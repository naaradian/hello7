unsigned char *  Formula8fsb(unsigned short f_in, unsigned char a_filtrPCh)
{
	unsigned char u0=256;
	unsigned char u1=4;

	unsigned long f_tm;
	static unsigned char b[17];

		unsigned char ucFiltrNCh = 0x3f;
		unsigned char ucFiltrVCh = 0xf;


/*		if((f_in>=20)&&(f_in<=260)) ucFiltrNCh=0x38;	    // A1-B1-C1-A2-B2-C2
		if((f_in>260)&&(f_in<=340)) ucFiltrNCh=0x31;    		
		if((f_in>340)&&(f_in<=480)) ucFiltrNCh=0x2A;    
		if((f_in>480)&&(f_in<=700)) ucFiltrNCh=0x23;    
		if((f_in>700)&&(f_in<=1050)) ucFiltrNCh=0x1C;   	
		if((f_in>1050)&&(f_in<=1550)) ucFiltrNCh=0x0E;  		 
		if((f_in>1550)&&(f_in<=2450)) ucFiltrNCh=0x15;	
		if((f_in>2450)&&(f_in<=3400)) ucFiltrNCh=0x07;	*/

		if((f_in>=20)&&(f_in<260)) ucFiltrNCh=0x1C;//0x38;	    // 1// A1-B1-C1-A2-B2-C2
		if((f_in>=260)&&(f_in<340)) ucFiltrNCh=0x2A;//0x31;    	// 2	
		if((f_in>=340)&&(f_in<480)) ucFiltrNCh=0x23;//0x2A;			// 3
		if((f_in>=480)&&(f_in<700)) ucFiltrNCh=0x15; //0x0E;//0x23;			// 4
		if((f_in>=700)&&(f_in<1050)) ucFiltrNCh=0x0E;//0x15;//0x1C;   	// 5
		if((f_in>=1050)&&(f_in<1550)) ucFiltrNCh=0x07;//0x0E;  	// 6	 
		if((f_in>=1550)&&(f_in<2450)) ucFiltrNCh=0x38;//0x15;		// 7
		if((f_in>=2450)&&(f_in<3400)) ucFiltrNCh=0x31;//0x07;		// 8

// b0:0	 c2  pa24
// b0:1	 b2	 pa25
// b0:2	 a2	 pa26
// b0:3	 c1	 pa27
// b0:4	 b1	 pa28
// b0:5	 a1	 pa29
// b0:6	 b7	 pa11
// b0:7	 a7	 pa10

//#ifdef HAVE_CORRECTIONS
 
#ifndef SERIAL_N_2

#include <ch_h_1.txt>
#else
#include <ch_h_2.txt>
#endif

//#endif   	 
	


// b1:0	 b4  pa21
// b1:1	 a4	 pa20
// b1:2	 b3	 pa19
// b1:3	 a3	 pa16


// b1:4	 b6	 pa12
// b1:5	 a6	 pa13
// b1:6	 b5	 pa14
// b1:7	 a5	 pa15

/*		if((f_in>3400)&&(f_in<=4250)) ucFiltrVCh=0x03;	// A3-B3-A4-B4
		if((f_in>4250)&&(f_in<=5050)) ucFiltrVCh=0x0C;		
		if((f_in>5050)&&(f_in<=5950)) ucFiltrVCh=0x06;
		if((f_in>5950)&&(f_in<=7000)) ucFiltrVCh=0x09;*/

		if((f_in>3399)&&(f_in<4250)) ucFiltrVCh=0x03;//0x03;//0x03;//0x03;	// 9// A3-B3-A4-B4
		if((f_in>=4250)&&(f_in<5050)) ucFiltrVCh=0x06;//0x0C;//0x09;//0x0C;	// 10	
		if((f_in>=5050)&&(f_in<5950)) ucFiltrVCh=0x09;//0x06;//0x0C;//0x06;	// 11
		if((f_in>=5950)&&(f_in<7000)) ucFiltrVCh=0x0C;//0x09;//0x06;//0x09;	// 12

		// b[0] = ucKeyVCh + ucFiltrVCh;  
		b[0] = ucFiltrNCh;  // мл. A1-B1-C1-A2-B2-C2 ст.
		b[1] = ucFiltrVCh;  // мл. A3-B3-A4-B4 ст.

  /*		
		switch(a_filtrPCh) // A5-B5-A6-B6
		{
			case 0x00: b[2] = 0x0B; break; // 140/70 MHz
			case 0x01: b[2] = 0x0C; break; // 150/2 MHz
			case 0x02: b[2] = 0x06; break; // 150/8 MHz
			case 0x03: b[2] = 0x06; break; // 150/80 MHz
		}
   */		  
//           my
//________________________________________________my - b2-> b1
switch(a_filtrPCh) // A5-B5-A6-B6
		{
			case 0x00: b[1] |= 0x10; break; // 140/70 MHz
			case 0x01: b[1] |= 0xc0; break; // 150/2 MHz 140 22
			case 0x02: b[1] |= 0x60; break; // 150/8 MHz  140 20
			case 0x03: b[1] |= 0x50; break; // 150/80 MHz
		}
//______________________________________________  
// b2:0	 b6  pa12
// b2:1	 a6	 pa13
// b2:2	 b5	 pa14
// b2:3	 a5	 pa15

   //	 b[2] = 0x80; //t
   //	 printf("\n\r %d", f_in);
////////////// DDS /////////////////
  //		double Fdds0 =     188000000.0;//188000000.0;
 //111031		double Fdds0 =     170000000.0;//188000000.0;
		double Fdds0 =     158000000.0;//188000000.0;
	 

		double Fbase_dds = 700000000.0;
		double df;
		double Fsint;
		double Fint, Fdelta, Fstep_dds, Fdds;
   //		double Fdds_fl;
   //		unsigned char M;
		unsigned char A;
////////////////////////////////////
	if((f_in>=20)&&(f_in<=7000))
	{
	 //	if((f_in>=20)&&(f_in<3450))  
		if((f_in>=20)&&(f_in<=3400))  
		{
		  //	b[1] = b[1] + 0x80;  // 0x80 = A7(0)-B7(1)    0x40 = A7(1)-B7(0)
			b[0] = b[0] + 0x80;  // 0x80 = A7(0)-B7(1)    0x40 = A7(1)-B7(0)
			f_tm = f_in + 4260; //4060;  // новомар 01/03/11 1850 
														
			double Ftemp = f_tm * 1000000.0;
			Fsint = (f_tm * 1000000.0);
			A = Fsint/Fdds0/2; 
			Fint = A*Fdds0*2;			
			Fdelta = Fsint - Fint;
			Fstep_dds = Fdelta/(A*2);
			Fdds = Fdds0 + Fstep_dds;
			Ftemp = A*Fdds*2;
 //110926			b[2] = A-1; // Байт управления синтезатором HMC440QS16G A0...A4
//110927		   if(A < 12) A = 12;							   //110926
		   b[2] =  (((A>>2) - 1) << 2) + (A % 4);	   //110926

			/// DDS
			df = Fdds/Fbase_dds;
			__int64 u64base =  (__int64)(2814749l);
			u64base *= (__int64)(100000000l);
			u64base += (__int64) (76710656l);

			__int64 u64result = u64base*df;
			unsigned long low = u64result&0xFFFFFFFF;
			unsigned long high = (u64result>>32)&0xFFFFFFFF;
			b[3] = (high>>8)&0xFF; // Байты установки частоты в DDS
			b[4] = high&0xFF;
			b[5] = (low>>24)&0xFF;
			b[6] = (low>>16)&0xFF;
			b[7] = (low>>8)&0xFF;
			b[8] = low&0xFF;
	
		}
		else
		{
			f_tm = f_in + 960; //910; // новомар 01/03/11 550
	   //		b[1] = b[1] + 0x40;  // 0x80 = A7(0)-B7(1)    0x40 = A7(1)-B7(0)
			b[0] = b[0] + 0x40;  // 0x80 = A7(0)-B7(1)    0x40 = A7(1)-B7(0)
														
			double Ftemp = f_tm * 1000000.0;
			Fsint = (f_tm * 1000000.0);
			A = Fsint/Fdds0/2; 
			Fint = A*Fdds0*2;			
			Fdelta = Fsint - Fint;
			Fstep_dds = Fdelta/(A*2);
			Fdds = Fdds0 + Fstep_dds;
			Ftemp = A*Fdds*2;
 //			b[2] = A-1; // Байт управления синтезатором HMC440QS16G A0...A4
//110927           if(A < 12) A = 12;							   //110926
		    b[2] =  (((A>>2) - 1) << 2) + (A % 4);		   //110926
			/// DDS
			df = Fdds/Fbase_dds;
			__int64 u64base =  (__int64)(2814749l);
			u64base *= (__int64)(100000000l);
			u64base += (__int64) (76710656l);

			__int64 u64result = u64base*df;
			unsigned long low = u64result&0xFFFFFFFF;
			unsigned long high = (u64result>>32)&0xFFFFFFFF;
			b[3] = (high>>8)&0xFF; // Байты установки частоты в DDS
			b[4] = high&0xFF;
			b[5] = (low>>24)&0xFF;
			b[6] = (low>>16)&0xFF;
			b[7] = (low>>8)&0xFF;
			b[8] = low&0xFF;
		}
	}
	return b;
}

