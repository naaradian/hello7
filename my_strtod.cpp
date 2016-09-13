#include <math.h>
#include <ctype.h>
#include "mqx_inc.h"
#include "fio.h"
#include "fio_prv.h"
#include "io.h"
#include "io_prv.h"
#include "fpio_prv.h"




/*FUNCTION*---------------------------------------------------------------------
*
* Function Name    : my_strtod
* Returned Value   : double the number obtained from the string
* Comments         :
*   this function converts a string to a double.
*
*END*-------------------------------------------------------------------------*/

static const double _io_strtod_powers_of_ten[] = {
    1.0, 1.0e1, 1.0e2, 1.0e3, 1.0e4, 1.0e5, 1.0e6, 1.0e7, 1.0e8, 1.0e9
};
static const double _io_strtod_inverse_powers_of_ten[] = {
    1.0, 1.0e-1, 1.0e-2, 1.0e-3, 1.0e-4, 1.0e-5, 1.0e-6, 1.0e-7, 1.0e-8, 1.0e-9
};

extern "C" double my_strtod
   (
      /* [IN] the string containing the number */
      register char _PTR_ nptr, 
      
      /* [IN/OUT] the string address after the number */
      char _PTR_ _PTR_ endptr
   )
{
//printfp("\n\rmy_strtod");
   register int_32 x;       /* Partial result */
   register int_32 exp;     /* Power of 10 for the result */
   register double result;
   register _mqx_int ne;     /* Number of digits seen so far */
   register _mqx_int nx;     /* Number of didits used so far */
   register int_32 eminus, minus;
   register char _PTR_ p;

   /* skip leading white space */
   p = (char _PTR_)nptr;
 //  while (isspace(*p)) {
   while ((*p) == ' ') {
      ++p;
   } /* Endwhile */

   /* consume the leading '+' or '-' */
   minus = 0;
   if (*p == '+') {
//140905      ++p;
 while ((*p) == '+') {
      ++p;
   } 
    
   } else if (*p == '-') {
      ++p;
      minus = 1;
   } /* Endif */

   if ((*p != '.') && (!isdigit(*p))) {
      /* no conversion possible: return initial nptr value */
      if (endptr) {
         *endptr = (char _PTR_)nptr;
      } /* Endif */
      return (0.0);
   } /* Endif */

   /* skip leading zeros */
   while (*p == '0') {
      ++p;
   } /* Endwhile */

   result = 0;
   nx = 0;
   ne = 0;
   exp = 0;

   /* read the integer part */
   for (x = 0; isdigit(*p); ++p) {
      if (ne < MAX_PRECISION) {					//17
         if (nx == 9) {
            if (ne == 9) {
               result = (double)x; /* d was still zero */
            } else {
               result = result * _io_strtod_powers_of_ten[9] + (double)x;
			 //  printfpd(";%d;", result);

            } /* Endif */
            x = nx = 0;
         } /* Endif */
         x = 10 * x + (*p - '0');
	  //	 printfpd(";%d;",x);

         ++ne;
         ++nx;
      } else { /* ignore digits after max precision */
         ++exp;
      } /* Endif */
   } /* Endfor */

   /* read the fractional part */
   if (*p == '.') {
      for (++p; isdigit(*p); ++p) {
         if (ne == 0 && *p == '0') {
            --exp; /* skip leading zeros if no digits yet */
         } else if (ne < MAX_PRECISION) {
            --exp;
            if (nx == 9) {
               if (ne == 9) {
                  result = (double)x; /* d was still zero */
               } else {
                  result = result * _io_strtod_powers_of_ten[9] + (double)x;
               } /* Endif */
               x = 0, nx = 0;
            } /* Endif */
            x = 10 * x + (*p - '0'); 
            ++ne;
            ++nx;
         } /* Endif */
      } /* Endif */
   } /* Endfor */

   /* pick up the pending product in x */
   if (nx != 0) {
      if (x == 0) {
         exp += nx;
      } else {
         if (ne == 9) {
            result = (double)x; /* d was still zero */
         } else {
            result = result * _io_strtod_powers_of_ten[nx] + (double)x;
         } /* Endif */
      } /* Endif */
   } /* Endfor */

   /* read the exponent */
   if (*p == 'e' || *p == 'E') {
      ++p;
      eminus = 0;
      if (*p == '+') {
         ++p;
      } else if (*p == '-') {
         ++p;
         eminus = 1;
      } /* Endif */

      for (x = 0; isdigit(*p); ++p) {
         x = 10 * x + (*p - '0');
         /* watch for overflow and underflow */
         if (eminus) {
            /* check for underflow */
            if ((exp - x) < -324) {
               exp = 0;
               x = 999;
            } /* Endif */
         } else {
            /* check for overflow */
            if ((exp + x) > DBL_MAX_10_EXP) {
               exp = 0;
               x = 999;
            } /* Endif */
         } /* Endif */
      } /* Endfor */
      if (eminus) {
         if (x == 999) { /* underflow */
            _task_errno = MQX_ERANGE;
            if (endptr) {
               *endptr = p;
            } /* Endif */
            return (0.0);
         } /* Endif */
         exp -= x;
      } else {
         if (x == 999) { /* overflow */
            _task_errno = MQX_ERANGE;
            if (endptr) {
               *endptr = p;
            } /* Endif */
            return (minus ? -HUGE_VAL : HUGE_VAL);
         } /* Endif */
         exp += x;
      } /* Endif */
   } /* Endif */

   /* multiply in the exponent */
   if (exp != 0) {
      while (9 <= exp) {
         result *= _io_strtod_powers_of_ten[9];
         exp -= 9;
      } /* Endwhile */
      while (exp <= -9) {
         result *= _io_strtod_inverse_powers_of_ten[9];
         exp += 9;
      } /* Endwhile */
      /* now exp is between -8 and +8 */
      if (0 < exp) {
         result *= _io_strtod_powers_of_ten[exp];
      } else if (exp < 0) {
         result *= _io_strtod_inverse_powers_of_ten[-exp];
      } /* Endif */
   } /* Endif */

   if (endptr) {
      *endptr = (char *)p;
   } /* Endif */

  //  printfpd("r:%d",result);

   return (minus ? -result : result);

} /* Endbody */


