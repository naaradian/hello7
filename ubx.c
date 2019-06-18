//#include <termios.h>

//#include "omgps.h"
#include "gps.h"
//#include "ubx4.h"
#include "ubx4.h"
#include "hello7.h"

#include "gps_utc.c"


//#include "util.h"
//#include "usart.h"


//all need init : 

static int gps_dev_fd;

ubx_msg_type_t type_nav_posllh;// = 	{UBX_CLASS_NAV, UBX_ID_NAV_POSLLH};
ubx_msg_type_t type_nav_status;// = 	{UBX_CLASS_NAV, UBX_ID_NAV_STATUS};
ubx_msg_type_t type_nav_velned;// = 	{UBX_CLASS_NAV, UBX_ID_NAV_VELNED};
ubx_msg_type_t type_nav_timeutc;// = 	{UBX_CLASS_NAV, UBX_ID_NAV_TIMEUTC};

ubx_msg_type_t type_nav_timegps;// = 	{UBX_CLASS_NAV, UBX_ID_NAV_TIMEGPS};


ubx_msg_type_t type_nav_svinfo;// = 	{UBX_CLASS_NAV, UBX_ID_NAV_SVINFO};

ubx_msg_type_t type_cfg_prt;// = 		{UBX_CLASS_CFG, UBX_ID_CFG_PRT};
ubx_msg_type_t type_cfg_msg;// = 		{UBX_CLASS_CFG, UBX_ID_CFG_MSG};
ubx_msg_type_t type_cfg_rate;// = 	{UBX_CLASS_CFG, UBX_ID_CFG_RATE};
ubx_msg_type_t type_cfg_sbas;// = 	{UBX_CLASS_CFG, UBX_ID_CFG_SBAS};
ubx_msg_type_t type_cfg_rst;// = 		{UBX_CLASS_CFG, UBX_ID_CFG_RST};
ubx_msg_type_t type_cfg_rxm;// = 		{UBX_CLASS_CFG, UBX_ID_CFG_RXM};

ubx_msg_type_t type_mon_ver;// = 		{UBX_CLASS_MON, UBX_ID_MON_VER};
ubx_msg_type_t type_cfg_nav2;// = 	{UBX_CLASS_CFG, UBX_ID_CFG_NAV2};
ubx_msg_type_t type_cfg_tp5;//  = 	{UBX_CLASS_CFG, UBX_ID_CFG_TP5};


#include <globals.c>


/**
 * <buf>: checksum must be set already.
 */
 
int write_gps(int addr, U1 *buf, int size)
{

int ret = size;
#ifdef Debug_Baco  
               printfp( "\n\rSend :");
#endif


 for (unsigned i  = 0l; i < size; i++)
         {
   //         fputc(*pTBuff0mf++, fusart0_ptr);
#ifdef Debug_Baco  
               printfpd( "_%02X",*buf);
#endif
   
#ifndef GPS_USART1  
        // printfpd( "%02X",*bu);
         ToPdcTu0(*buf++);
#else
         ToPdcTu1(*buf++);
#endif         
         }
         
#ifndef GPS_USART1          
        OperateBuffers_usart0t();
#else
         OperateBuffers_usart1t();
#endif        
        
        
#ifdef Debug_Baco  
            printfp( "\n\r");
#endif
return ret;  
}

int read_gps(int addr, U1 *buf, int size)
{
char tmp;
int ret = 0;
#ifdef Debug_Baco  
     //          printfp( " R: ");
#endif


//while(embRS232.UsedReceive())
//		{
  //			byte = embRS232.Receive();
  
#ifndef GPS_USART1   
  OperateBuffers_usart0(); //receive data from pdc
#else
  OperateBuffers_usart1(); 
#endif

 for (unsigned i  = 0l; i < size; i++)
         {
         
#ifndef GPS_USART1          
         if(haveusart0())
   //         fputc(*pTBuff0mf++, fusart0_ptr);
            { 
            tmp =   getbufferusart0();
#ifdef Debug_Baco  
               printfpd( "+%02 X",tmp);
#endif
            

             *buf++ = tmp;
             ret++;
            }
            else{  break;  } 
#else
                 if(haveusart1())
   //         fputc(*pTBuff0mf++, fusart0_ptr);
            { 
               tmp =   getbufferusart1();

#ifdef Debug_Baco  
               printfpd( "-%02X",tmp);
#endif
            
             *buf++ = tmp;
             ret++;
            }
            else{  break;  } 

#endif         
         
         
         
         }
         
         
return ret;  
}

 
 
 
 
gboolean ubx_send_request(U1 *buf, int size)
{
	int written = 0;
	while (TRUE) {
		if ((written = write_gps(gps_dev_fd, &buf[written], size)) <= 0)
			return FALSE;
		size -= written;
		if (size == 0)
			break;
		buf += written;
	}
//hier need send 	tcdrain(gps_dev_fd);

 //sleep_ms(200);
 delay_mcs(200 * 1000);

	return TRUE;
}

/**
 * NOTE: the packet must end with 2 chars of checksum at count size and size+1.
 */
void ubx_checksum(U1 *packet, int size)
{
	U4 a = 0x00;
	U4 b = 0x00;
	int i = 0;
 //   printfp("\n\r");
	while(i<size) {
//     printfpd("%x ",packet[i]);

   
		a += packet[i++];
		b += a;
	}
	packet[size] = a & 0xFF;
	packet[size+1] = b & 0xFF;
 //  printfpd("\n\r checksum : a :%x", a & 0xFF);
  //  printfpd("b :%x \n\r", b & 0xFF);

   
}

void ubx_checksum1(U1 *packet, int size)
{
	U4 a = 0x00l;
	U4 b = 0x00l;
	int i = 0;
 //   printfp("\n\r");
	while(i<size) {
  //   printfpd("%x ",packet[i]);

   
		a += packet[i++];
		b += a;
	}
	packet[size-2] = a & 0xFF;
	packet[size-1] = b & 0xFF;
//   printfpd("\n\r checksum : a :%x", a & 0xFF);
  //  printfpd(" b :%x \n\r", b & 0xFF);

   
}



gboolean read_fixed_len(U1 *buf, int expected_len)
{
	int len = 0, count;

//ok   return; //for test
  long wdc = 1000;
   
	while (TRUE) {
         wdc--;
         if(!wdc){ /* Body */ 
         printfp("\n\r WDC_ret");
         return FALSE;

      } /* Endbody */
   
		count = read_gps(gps_dev_fd, &buf[len], expected_len);
	
   	if (count == expected_len)
			return TRUE;

		if (count <= 0) {
	//		usart_flush_output();
			return FALSE;
		} else {
			len += count;
			expected_len -= count;
			if (expected_len == 0)
				return TRUE;
		}  //else
	}   //while
   
   
}


static gboolean ubx_read_header(U1 *buf, int next_len)
{
	U1 c;
	int status = 0;
	int ret;
   unsigned watch_cnt = 0xfff;
 //  unsigned watch_cnt = 1;
   unsigned  wi = 1;

	while (1)
//    for(wi = 1; wi> 0; wi--)
    {
      if(!watch_cnt--)
      { 
      printfp("\n\rread UBX binary header failed watch_cnt = 0");
   //   printfp("NEXT");
      return FALSE;
      }   
      
       
		if ((ret = read_gps(gps_dev_fd, &c, 1)) != 1) {
	 //		usart_flush_output();
     //      printfpd("\n\rread_gps != 1 :%d", ret);

			return FALSE;
		}

		if (c == 0xB5) {
			status = 1;
		} else if (status == 1) {
			if (c == 0x62)
				break;
			else {
	  			printfpd("=%x ", c);
				continue;
			}
		}
	}

	/* class, id, length: 1 + 1 + 2, or full message -- ack */
	if (! read_fixed_len(buf, next_len)) {
		printfp("read data after UBX binary header failed.");
		return FALSE;
	}

	return TRUE;
}

/**
 * When messages from the Class CFG are sent to the receiver,
 * the receiver will send an Acknowledge (ACK-ACK (0x05 0x01)) or a Not Acknowledge
 * (ACK-NAK (0x05 0x00)) message back to the sender,
 * depending on whether or not the message was processed correctly.
 * There is no ACK/NAK mechanism for message poll_suspending requests outside Class CFG.
 */
gboolean ubx_read_ack(const ubx_msg_type_t *expected_type)
{
	static U1 ack_buf[8];

	if (! ubx_read_header(ack_buf, 8))
   {
         printfp("\n\r ACK FALSE");
   		return FALSE;
   }

	if (ack_buf[0] != UBX_CLASS_ACK || ack_buf[1] != UBX_ID_ACK_ACK ||
		ack_buf[2] != 0x02 || ack_buf[3] != 0x00 ||
		ack_buf[4] != expected_type->class_ || ack_buf[5] != expected_type->id) {
	 //	printfp("bad ack: %02X, %02X, %02X, %02X, %02X, %02X",
	 //		ack_buf[0], ack_buf[1], ack_buf[2], ack_buf[3], ack_buf[4], ack_buf[5]);
	 //	usart_flush_output();
    printfp("\n\r ACK FALSE_");
		return FALSE;
	}
    printfp("\n\r ACK TRUE");

	return TRUE;
}

gboolean ubx_read_next_msg(ubx_msg_t *msg, const ubx_msg_type_t *expected_type)
{
	static U1 buf[1024];

	if (! ubx_read_header(buf, 4)){ 
     //     printfp("\n\r read header false");
		return FALSE;
      }

	msg->class_ = buf[0];
	msg->id = buf[1];

	/* LITTLE ENDIAN ALWAYS */
	msg->payload_len = buf[2] | (buf[3] << 8);
 //   printfpd("payload_len : %d", msg->payload_len);

	/* payload length + checksum(2) */
	if (! read_fixed_len(buf, msg->payload_len + 2)) {
  		printfp("\n\rread payload failed.");
		return FALSE;
	}

	msg->payload_addr = buf;
	msg->checksum[0] = buf[msg->payload_len];
	msg->checksum[1] = buf[msg->payload_len + 1];

	/* Previous operations may leave garbage in the out buffer. */
	if (expected_type != NULL && (msg->class_ != expected_type->class_ || msg->id != expected_type->id)) {
		printfp("\n\rbad message type");
	//		expected_type->class_, expected_type->id, msg->class_, msg->id);
  //		usart_flush_output();
		return FALSE;
	}

	return TRUE;
}

/**
 * Send a command.
 * The response content is ignored
 */
gboolean ubx_issue_cmd(U1 *packet, int len)
{
 	ubx_checksum(&packet[2], len - 4);
 //  ubx_checksum(&packet[2], len - 2);  //150217
 //  ubx_checksum1(&packet[2], len - 2);  //150217

 	if (! ubx_send_request(packet, len)) {
 // 	if (! ubx_send_request(packet, len+2)) {
		printfp("\n\rwrite device failed");
		return FALSE;
	}
	return TRUE;
}

/**
 * Enable or disable all standard NMEA messages
 * send_reate: 0x00 means disabled.
 *
 * NOTE: on FR GTA02 v6, the I/O target numbers are 1. (0, 1, 2, 3)
 * Although u-blox firmware 5.00 doc says 6 ports, but ANTARIS 0635 has only 4.
 */
gboolean ubx_cfg_msg_nmea_std(U1 send_rate, gboolean all, gboolean readack)
{
	/* class=0xf0, id={0x00 - 0x0a} */
	U1 packet[8+66] = {
		0xB5, 0x62,
		type_cfg_msg.class_, type_cfg_msg.id,
		66, 0x00
	};

	int i, off;
	U1 val;
	U1 ids[] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a};
	gboolean enable[] = {TRUE, FALSE, FALSE, FALSE, FALSE, TRUE, FALSE, FALSE, FALSE, FALSE, FALSE};

	for (i=0; i<11; i++) {
		off = 6 + i * 6;
		val = all? send_rate : (enable[i]? send_rate : 0x00);
		packet[off] = 0xF0; /* NMEA msg class*/
		packet[off+1] = ids[i];
		packet[off+2] = 0;	/*target 0*/
		packet[off+3] = val;/*target 1*/
		packet[off+4] = 0;	/*target 2*/
		packet[off+5] = 0;	/*target 3*/
	}

	return ubx_issue_cmd(packet, sizeof(packet)) && (! readack || ubx_read_ack(&type_cfg_msg));
}

void ubx_mon_ver_poll(char *buf, int buf_len)
{
	U1 packet[] = {
		0xB5, 0x62,
		type_mon_ver.class_, type_mon_ver.id,
		0x00, 0x00,
		0x00, 0x00
	};

	ubx_msg_t msg;

	if (! (ubx_issue_cmd(packet, sizeof(packet)) &&
		ubx_read_next_msg(&msg, &type_mon_ver))) {
 		printfp("MON-VER: poll failed.\n");
		return;
	}

 //	sprintf(buf, buf_len, "software=%s; hardware=%s", msg.payload_addr, &msg.payload_addr[30]);
	sprintf(buf,  (const char *)&msg.payload_addr, "software=%s");
	/* no extension at all, ignore */
}

/**
 * NOTE: U-BLOX5 chip use CFG-NAV5 instead of CFG-NAV2.
 * model:
 * 1 Stationary
 * 2 Pedestrian
 * 3 Automotive
 * 4 Sea
 * 5 Airborne with <1g Acceleration
 * 6 Airborne with <2g Acceleration
 * 7 Airborne with <4g Acceleration
 * fix_mode:
 * 1: 2D only
 * 2: Auto 2D/3D
 * 3: 3D only
 *
 * min_ELE: Minimum Elevation for a GNSS satellite to be used in NAV, degree, default 5
 * maxsv: Maximum number of GNSS satellites for Navigation, default 16
 */
gboolean ubx_cfg_nav2(U1 model, gboolean readack)
{
	U1 maxsv = 0x10;
	U1 fix_mode = 0x02; /* auto */
	U1 min_ELE = 0x05;
	U1 allow_alma_nav = 0X0;

	U1 packet[8+40] = {
		0xB5, 0x62,
		type_cfg_nav2.class_, type_cfg_nav2.id,
		40, 0x00,
		model,
		0x00,
		0x00, 0x00,
		0x03,
		0x03,
		maxsv,
		fix_mode,
		0x50, 0xC3, 0x00, 0x00,
		0x0F,
		0x0A,
		min_ELE,
		0x3C,
		0x0F, /* default 0 */
		allow_alma_nav,
		0x00, 0x00,
		0xFA, 0x00,
		0xFA, 0x00,
		0x64, 0x00,
		0x2C, 0x01,
		0x00,
		0x00,
		0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00
	};

	return ubx_issue_cmd(packet, sizeof(packet)) && (! readack || ubx_read_ack(&type_cfg_nav2));
}

/**
 * @rate: the bigger the slower. 0 : disable
 */
gboolean ubx_cfg_msg_nmea_ubx(U1 send_rate, gboolean all, gboolean readack)
{
	/* class=0xf1, id={0x00, 0x01, 0x03, 0x04} */
	U1 packet[8+4*6] = {
		0xB5, 0x62,
		type_cfg_msg.class_, type_cfg_msg.id,
		24, 0x00
	};

	U1 ids[] = {0x00, 0x01, 0x03, 0x04};
	gboolean enable[] = {TRUE, FALSE, FALSE, FALSE};
	int i, off;

	U1 val;
	for (i=0; i<4; i++) {
		off = 6 + i * 6;
		val = all? send_rate : (enable[i]? send_rate : 0x00);
		packet[off] = 0xF1;
		packet[off+1] = ids[i];
		packet[off+2] = 0;	/*target 0*/
		packet[off+3] = val;/*target 1*/
		packet[off+4] = 0;	/*target 2*/
		packet[off+5] = 0;	/*target 3*/
	}

	return ubx_issue_cmd(packet, sizeof(packet)) && (! readack || ubx_read_ack(&type_cfg_msg));
}

gboolean ubx_cfg_msg(const ubx_msg_type_t *msg_type, gboolean enabled, gboolean readack)
{
	U1 packet[11] = {
		0xB5, 0x62,
		type_cfg_msg.class_, type_cfg_msg.id,
		0x03, 0x00 /* length */
	};

	packet[6] = msg_type->class_;
	packet[7] = msg_type->id;
	packet[8] = enabled? 0x01 : 0x00;

	return ubx_issue_cmd(packet, sizeof(packet)) && (! readack || ubx_read_ack(&type_cfg_msg));
}

/**
 * meas: ms, multiple of 250 ms.
 */
gboolean ubx_cfg_rate(U2 meas, gboolean readack)
{
	U1 packet[8+6] = {
		0xB5, 0x62,
		type_cfg_rate.class_, type_cfg_rate.id,     //06 00
		0x06, 0x00, /* len */
		0x00, 0x00, /* meas */
		0x01, 0x00, /* nav */
		0x00, 0x00, /* time: aligned to GPS time */
		0x00, 0x00  /* checksum */
	};

	packet[6] = (U1)(meas & 0xFF);
	packet[7] = (U1)((meas >> 8) & 0xFF);
  //ok   	return ubx_issue_cmd(packet, sizeof(packet));  //t
	return ubx_issue_cmd(packet, sizeof(packet)) && (!readack || ubx_read_ack(&type_cfg_rate));
}

/**
 * By default SBAS is enabled with three prioritized SBAS channels and it will use
 * any received SBAS satellites (except for those in test mode) for navigation,
 * ionosphere parameters and corrections.
 *
 * SBAS Usage (Bitmask):
 * Bit 0: Use SBAS GEOs as a ranging source (for navigation)
 * Bit 1: Use SBAS Differential Corrections
 * Bit 2: Use SBAS Integrity Information
 */
gboolean ubx_cfg_sbas(gboolean enable, gboolean readack)
{
	/* FIXME: make these configurable? */
	U1 usage = 0x07;
	U1 max_channels_searched = 0x03;

	U1 packet[8+8] = {
		0xB5, 0x62,
		type_cfg_sbas.class_, type_cfg_sbas.id,
		0x08, 0x00, /* length */
		enable? 0x01:0x00, /* mode */
		usage, /* usage */
		max_channels_searched, /* maxsbas: 0-3 */
		0x00, /* reserved */
		0x00, 0x00, 0x00, 0x00, /* scanmode: all zeros->auto */
		0X00, 0X00 /* checksum */
	};

	return ubx_issue_cmd(packet, sizeof(packet)) && (! readack || ubx_read_ack(&type_cfg_sbas));
}

/**
 * GPS Sensitivity Mode:
 * 0: Normal
 * 1: Fast Acquisition
 * 2: High Sensitivity
 * 3: Auto
 *
 * Low Power Mode:
 * 0: Continuous Tracking Mode
 * 1: Fix Now
 */
gboolean ubx_cfg_rxm(U1 gps_mode, U1 lp_mode, gboolean readack)
{
	U1 packet[] = {
		0xB5, 0x62,
		type_cfg_rxm.class_, type_cfg_rxm.id,
		0x02, 0x00,
		gps_mode, lp_mode,
		0x00, 0x00
	};

	return ubx_issue_cmd(packet, sizeof(packet)) && (! readack || ubx_read_ack(&type_cfg_rxm));
}
   /*
   U4  interval;                 //!< time interval for time pulse
	U4  length;                   //!< length of time pulse
	I1  status;                   //!< time pulse config setting
	U1  timeRef;                  //!< alignment to reference time:
	U1  flags;                    //!< bitmask
	U1  res;                      //!< reserved
	I2  antennaCableDelay;        //!< Antenna Cable Delay
	I2  rfGroupDelay;             //!< Receiver RF Group Delay
	I4  userDelay;                //!< User Time Function Delay (positive delay results in earlier pulse)

   */
/*   


active if set enable time pulse; if pin assigned to another function, other function takes precedence

lockGpsFreq if set synchronize time pulse to GPS as soon as GPS time is valid, otherwise use local clock

lockedOtherSet
if set use 'freqPeriodLock' and 'pulseLenRatioLock' as soon as GPS time is valid and 'freqPeriod' and
'pulseLenRatio' if GPS time is invalid,
if flag is cleared 'freqPeriod' and 'pulseLenRatio' used regardless of GPS time

isFreq if set 'freqPeriodLock' and 'freqPeriod' interpreted as frequency, otherwise interpreted as period



isLength if set 'pulseLenRatioLock' and 'pulseLenRatio' interpreted as pulse length, otherwise interpreted as duty cycle

alignToTow align pulse to top of second (period time must be integer fraction of 1s)

polarity pulse polarity:
0 = falling edge at top of second
1 = rising edge at top of second

gridUtcGps timegrid to use:
0 = UTC
1 = GPS

*/   
   
  /* 10 MHz 
0000  B5 62 06 31 20 00 00 00 00 00 00 00 00  µb1 
000D  00 80 96 98 00 01 00 00 00 00 00 00 80  €–˜€
001A  99 99 99 19 00 00 00 00 6F 00 00 00 D9  ™™™oÙ
0027  3F                                      ?   
  */

gboolean ubx_cfg_tp5( gboolean readack)
{
	U1 packet[] = {
		0xB5, 0x62,
		type_cfg_tp5.class_, type_cfg_tp5.id,
      0x20,  00,   //length
      0, //tp1 or tp2
      0, //ver
      0, 0,  //rezerved
      0, 0,  //cable delay
      0, 0,  //rf group delay
      0, 9, 0x3d, 0, //freq or period, depending "isfreq" 
      0, 9, 0x3d,  0, //freq or period, depending "isfreq" 
//      0, 0, 0, 0x80,          // Pulse length or duty cycle, depending on  'isLength'
      0xff, 0xff, 0xff, 0x4f,          // Pulse length or duty cycle, depending on  'isLength'
      0xff, 0xff, 0xff, 0x4f,          //Pulse length or duty cycle when locked to GPS  time, only used if 'lockedOtherSet' is set
      0, 0, 0, 0,         //User configurable time pulse delay
      0x6F, 0, 0, 0,         //Configuration flags
      0,  0              //checksum - added when send need keep hier zeros                         
	};

	return ubx_issue_cmd(packet, sizeof(packet)) && (! readack || ubx_read_ack(&type_cfg_tp5));
}
// for timepulse2
gboolean ubx_cfg_tp5_2( gboolean readack)
{
	U1 packet[] = {
		0xB5, 0x62,
		type_cfg_tp5.class_, type_cfg_tp5.id,
      0x20,  00,   //length
      1, //tp1 = 0 or tp2 = 1
      0, //ver
      0, 0,  //rezerved
      0, 0,  //cable delay
      0, 0,  //rf group delay
   //   0x80, 0x96, 0x98, 0, //freq or period, depending "isfreq" 
      0xA, 0, 0, 0, //freq or period, depending "isfreq"  10 Hz
      0xA, 0, 0, 0,    //  freq or period when locked to gps time if used "lockedotherset"  
      0x99, 0x99, 0x99, 0x19,          // Pulse length or duty cycle, depending on  'isLength'
      0x99, 0x99, 0x99, 0x19,          //Pulse length or duty cycle when locked to GPS  time, only used if 'lockedOtherSet' is set
      0, 0, 0, 0,         //User configurable time pulse delay
      0x6F, 0, 0, 0,         //Configuration flags
      0,  0              //checksum - added when send need keep hier zeros                         
	};

	return ubx_issue_cmd(packet, sizeof(packet)) && (! readack || ubx_read_ack(&type_cfg_tp5));
}



/**
 * BBR Sections to clear:
 *
 * 0x0000 Hotstart
 * 0x0001 Warmstart
 * 0xFFFF Coldstart
 *
 * Reset Type:
 * 0x00 - Hardware Reset (Watchdog)
 * 0x01 - Controlled Software reset
      terminates all running processes in an orderly manner and, once the system is
 *    idle, restarts operation, reloads its configuration and starts to acquire and track GPS satellites
 * 0x02 - Controlled Software reset (GPS only)
 *    only restarts the GPS tasks, without reinitializing the full system or
 *    reloading any stored configuration.
 * 0x08 - Controlled GPS stop
 * 0x09 - Controlled GPS start
 */
gboolean ubx_cfg_rst(U2 bbr, U1 reset_type)
{
	U1 packet[] = {
		0xB5, 0x62,
		type_cfg_rst.class_, type_cfg_rst.id,
		0x04, 0x00, /* len */
		bbr & 0xFF, (bbr >> 8) & 0xFF, /* bbr */
		reset_type & 0xFF, /* reset type */
		0x00, /* reserved */
		0x00, 0x00
	};

	/* no output available, so skip reading ACK */
	return ubx_issue_cmd(packet, sizeof(packet));
}

gboolean ubx_reset_gps(char *type)
{
	U2 bbr;
	if (strcmp(type, "hot") == 0)
		bbr = 0x0000;
	else if (strcmp(type, "warm") == 0)
		bbr = 0x0001;
	else if (strcmp(type, "cold") == 0)
		bbr = 0xFFFF;
	else
		return FALSE; // should not happen

	return ubx_cfg_rst(bbr, 0x02);
}

/**
 * CFG-PRT (0x06 0x00)
 * 0x0001: UBX Protocol
 * 0x0002: NMEA Protocol
 */
gboolean ubx_cfg_prt(U1 port_id, U1 in_protocol, U1 out_protocol, U4 baud, gboolean readack)
{
	U1 packet[] = {
		0xB5, 0x62,
		type_cfg_prt.class_, type_cfg_prt.id,
		20, 0, /* length */
		port_id, /* port ID */
		0x00,    /* reserved */
      0x00, 0x00, /* tx ready */       //not enabled
	 //	0xd0, 0x08, 0x08, 0x00, /* mode */
   //	0xc0, 0x08, 0x08, 0x00, /* mode */    //8 bits no parity 2 stop bits
      0xc0, 0x08, 0x00, 0x00, /* mode */    //8 bits no parity 1 stop bits
		0x80, 0x25, 0x00, 0x00, /* baud rate */   //9600
		0x07, 0x00, /* in protocol */     //all
		0x03, 0x00, /* out protocol */     //no rtsm
		0x00, 0x00, /* flags */     //no extended timeout
		0x00, 0x00, /* reserved*/
		0x00, 0x00 /* checksum */
	};

	/* Disable this port totally */
	if (in_protocol == 0x00 && out_protocol == 0x00 && baud == 0x00) {
		packet[10] = packet[11] = packet[12] = packet[13] = 0x00;
	}

     
	packet[6+8] = baud & 0xFF;
	packet[6+9] = (baud >> 8) & 0xFF;
	packet[6+10] = (baud >> 16) & 0xFF;
	packet[6+11] = (baud >> 24) & 0xFF;
	packet[6+12] = in_protocol;
	packet[6+14] = out_protocol;
     
   

	return ubx_issue_cmd(packet, sizeof(packet)) && (! readack|| ubx_read_ack(&type_cfg_prt));
}

static gboolean ubx_parse_nav_svinfo(ubx_msg_t *msg)
{
	U1 *buf = msg->payload_addr;

	g_gpsdata.sv_channel_count = (U1)READ_U1(buf+4);
	if (g_gpsdata.sv_channel_count > SV_MAX_CHANNELS)
		g_gpsdata.sv_channel_count = SV_MAX_CHANNELS;

	if (msg->payload_len != 8 + g_gpsdata.sv_channel_count * 12) {
		printfp("svinfo: bad length\n");
		g_gpsdata.svinfo_valid = FALSE;
		return FALSE;
	}

	int i, j = 0;
	U1 flags, sv_id, *p;
	svinfo_channel_t *sv;

	g_gpsdata.sv_in_use = 0;
	g_gpsdata.sv_get_signal = 0;

	/* default elevation is -9, default azimuth is 0 */

	for (i=0; i < g_gpsdata.sv_channel_count; i++) {
		p = (U1 *)(buf + 8 + i * 12);

		/* CHN: 255 -- SVs not assigned to a channel */
		if (READ_U1(p) == 0xFF)
			continue;

		/* Valid SV ID: 1..32, or DGPS IDS (>100) */
		sv_id = READ_U1(p+1);
		if (sv_id == 0x0)
			continue;

		flags = READ_U1(p+2);
		/* unhealthy */
		if (flags & 0x10)
			continue;

		sv = &g_gpsdata.sv_channels[j];
		sv->sv_id = sv_id;
		sv->flags = flags;
		sv->cno = READ_U1(p+4);
		sv->elevation = READ_S1(p+5);
		sv->azimuth = READ_S2(p+6);
		if (sv->elevation < 0 || sv->azimuth < 0)
			sv->elevation = sv->azimuth = -9;

		if ((flags & 0x01) == 0x01)
			++g_gpsdata.sv_in_use;

		if (sv->cno > (U1)0)
			++g_gpsdata.sv_get_signal;

		j++;
	}

	g_gpsdata.sv_channel_count = j;
	g_gpsdata.svinfo_valid = TRUE;
	return TRUE;
}

/**
 * For dump AID-EPH, AID-HUI, AID-ALM.
 * Make sure the <raw> char array can holds max length of data ot <type>
 *
 * From http://www.u-blox.cn/customersupport/gps.g5/ublox5_Fw5.00_Release_Notes(GPS.G5-SW-08019).pdf:
 *
 * UBX-AID-EPH and UBX-AID-ALM Messages for Satellite without valid Orbits
 * When polling UBX-AID-EPH or UBX-AID-ALM messages, satellites without valid ephemeris or almanac data will
 * return a complete UBX-AID-EPH or UBX-AID-ALM message with all data words set to zero. This doesnâ€™t comply
 * with the protocol specification. Furthermore, u-blox 5 receivers with firmware V5.00 and
 * earlier can run into a floating-point exception when fed with such â€œemptyâ€ ephemeris.
 */
int ubx_read_next_aid_message(U1 raw[], int len, const ubx_msg_type_t *type, int valid_payload_len)
{
	ubx_msg_t msg;
	if (! ubx_read_next_msg(&msg, type)) {
		printfpd("read response failed:  id=%02x",  type->id);
		return -1;
	}

	if (len < msg.payload_len + 8)
		return -2;

	if (msg.payload_len != valid_payload_len)
		return 0;

	gboolean hit_bug = TRUE;
	int i;

	for (i=4; i<msg.payload_len; i++) { /* skip SV ID */
		if (msg.payload_addr[i] != 0x00) {
			hit_bug = FALSE;
			break;
		}
	}
	if (hit_bug)
		return 0;

	raw[0] = 0xB5;
	raw[1] = 0x62;
	raw[2] = type->class_;
	raw[3] = type->id;
	raw[4] = msg.payload_len & 0xFF;
	raw[5] = (msg.payload_len >> 8) & 0xFF;

	memcpy(&raw[6], msg.payload_addr, msg.payload_len);

	raw[6 + msg.payload_len] = msg.checksum[0];
	raw[7 + msg.payload_len] = msg.checksum[1];

	return 8 + msg.payload_len;
}

#define POLLED_MSG   (5)
#define TYPES_SIZE   (14)

//static int enabled_type_count = 8; 
int enabled_type_count;      //use 5 types of requests
//tstatic U1 poll_packet[8 * 8];
static U1 poll_packet[TYPES_SIZE * 8];
//ubx_msg_type_t g_types[13];
ubx_msg_type_t g_types[TYPES_SIZE];

/**
 * SVINFO must be last!
 */
void ubx_set_poll_msg_types(ubx_msg_type_t types[], int count)
{
 //	enabled_type_count = POLLED_MSG;
 	enabled_type_count = TYPES_SIZE;

	int i, offset;

	for (i = 0; i<count; i++) {
		offset = i * 8;
		poll_packet[offset+0] = 0xB5;
		poll_packet[offset+1] = 0x62;
		poll_packet[offset+2] = types[i].class_;
		poll_packet[offset+3] = types[i].id;
		poll_packet[offset+4] = 0x00;       //len
		poll_packet[offset+5] = 0x00;       //len
     	poll_packet[offset+6] = 0x00;    //checksum
		poll_packet[offset+7] = 0x00;    //checksum


	  	ubx_checksum(&poll_packet[offset+2], 4);
    //	ubx_checksum1(&poll_packet[offset+2], 6);
	}
}

/*
 * _gpsdata is set as non-NULL on first call ubx_init();
 */
void ubx_init(int dev_fd)
{
	gps_dev_fd = dev_fd;
   enabled_type_count =POLLED_MSG;

   
 type_nav_posllh.class_ = UBX_CLASS_NAV;
 type_nav_posllh.id     = UBX_ID_NAV_POSLLH;
 
 type_nav_status.class_ = UBX_CLASS_NAV;
 type_nav_status.id     = UBX_ID_NAV_STATUS;
 
 type_nav_velned.class_ = UBX_CLASS_NAV;
 type_nav_velned.id     = UBX_ID_NAV_VELNED;
 
 type_nav_timeutc.class_= UBX_CLASS_NAV;
 type_nav_timeutc.id    = UBX_ID_NAV_TIMEUTC;
 
 type_nav_timegps.class_= UBX_CLASS_NAV;
 type_nav_timegps.id    = UBX_ID_NAV_TIMEGPS;
 
 type_nav_svinfo.class_ = UBX_CLASS_NAV;
 type_nav_svinfo.id     = UBX_ID_NAV_SVINFO;

 type_cfg_prt.class_    = UBX_CLASS_CFG;
 type_cfg_prt.id        = UBX_ID_CFG_PRT;
 
 type_cfg_msg.class_    = UBX_CLASS_CFG;
 type_cfg_msg.id        = UBX_ID_CFG_MSG;
 
 type_cfg_rate.class_   = UBX_CLASS_CFG;
 type_cfg_rate.id       = UBX_ID_CFG_RATE;
 
 type_cfg_sbas.class_   = UBX_CLASS_CFG;
 type_cfg_sbas.id       = UBX_ID_CFG_SBAS;
 
 type_cfg_rst.class_    = UBX_CLASS_CFG;
 type_cfg_rst.id        = UBX_ID_CFG_RST;
 
 type_cfg_rxm.class_    = UBX_CLASS_CFG;
 type_cfg_rxm.id        = UBX_ID_CFG_RXM;

 type_mon_ver.class_    = UBX_CLASS_MON;
 type_mon_ver.id        = UBX_ID_MON_VER;
 
 type_cfg_nav2.class_   = UBX_CLASS_CFG;
 type_cfg_nav2.id       = UBX_ID_CFG_NAV2;
 
 type_cfg_tp5.class_    = UBX_CLASS_CFG;
 type_cfg_tp5.id        = UBX_ID_CFG_TP5;
 
//g_types[0] = type_nav_posllh;
g_types[3] = type_nav_posllh;
g_types[12] = type_nav_status;
g_types[2] = type_nav_velned;
//g_types[3] = type_nav_timeutc;
g_types[0] = type_nav_timeutc;
g_types[13] = type_nav_timegps;


g_types[4] = type_nav_svinfo;
g_types[5] = type_cfg_prt;
g_types[6] = type_cfg_msg;
g_types[7] = type_cfg_rate;
g_types[8] = type_cfg_rst;
g_types[9] = type_cfg_rxm;
g_types[10] = type_mon_ver;
g_types[11] = type_cfg_nav2;
g_types[1] = type_cfg_tp5;




 init_gpsdata(&g_gpsdata);
 
 ubx_set_poll_msg_types(&g_types[0], TYPES_SIZE);
 
}

static gboolean ubx_parse_nav_status(ubx_msg_t *msg)
{
	U1 *buf = msg->payload_addr;

	if (msg->payload_len != 16) {
		printfp("nav status: bad length");
		return FALSE;
	}

	g_gpsdata.nav_status_itow = (U4)READ_U4(buf);
	g_gpsdata.nav_status_fixtype = (U1)READ_U1(buf+4);
	//g_gpsdata.nav_status_flags = ((U1)READ_U1(buf+5)) & 0xF;
	//g_gpsdata.nav_status_diffs = ((U1)READ_U1(buf+6)) & 0x4;
	//g_gpsdata.nav_status_ttff = (U4)READ_U4(buf+8);
	//g_gpsdata.nav_status_msss = (U4)READ_U4(buf+12);

	return TRUE;
}

static gboolean ubx_parse_nav_posllh(ubx_msg_t *msg)
{
	/* 1e7 */
	#define POS_SCALE	10000000
	/* mm -> m */
	#define ACC_SCALE	1000
	/* mm: hack! */
	#define VALID_HACC	1000000

	U1 *buf = msg->payload_addr;

	if (msg->payload_len != 28) {
		printfp("nav posllh: bad length");
		return FALSE;
	}

	U4 hacc = (U4)READ_U4(buf+20);
	if (hacc > VALID_HACC) {
		g_gpsdata.latlon_valid = FALSE;
		g_gpsdata.height_valid = FALSE;
		return TRUE;
	}

	g_gpsdata.llh_itow = (U4)READ_U4(buf);
	g_gpsdata.hacc = (float)hacc / ACC_SCALE;
	g_gpsdata.vacc = (float)(U4)READ_U4(buf+24) / ACC_SCALE;
	g_gpsdata.lon = (double)READ_S4(buf+4) / POS_SCALE;
	g_gpsdata.lat = (double)READ_S4(buf+8) / POS_SCALE;
	g_gpsdata.height = (float)READ_S4(buf+12) / ACC_SCALE;

	g_gpsdata.latlon_valid = TRUE;
	g_gpsdata.height_valid = TRUE;

	return TRUE;
}

static gboolean ubx_parse_nav_velned(ubx_msg_t *msg)
{
	/* 1e5 */
	#define HEADING_SCALE	100000
	/* cm -> m */
	#define VEL_SCALE		100
	/* cm/s, hack! */
	#define VALID_SPEED_ACC	500

	U1 *buf = msg->payload_addr;

	if (msg->payload_len != 36) {
		printfp("nav velned: bad length");
		return FALSE;
	}

	U4 acc = (U4)READ_U4(buf+28);
	if (acc > VALID_SPEED_ACC) {
		g_gpsdata.vel_valid = FALSE;
		return TRUE;
	}

	g_gpsdata.speed_2d = (float)READ_U4(buf+20) / VEL_SCALE;
	g_gpsdata.vel_down = (float)READ_S4(buf+12) / VEL_SCALE;
	g_gpsdata.heading_2d = (float)READ_S4(buf+24) / HEADING_SCALE;

	g_gpsdata.vel_valid = TRUE;

	return TRUE;
}

#define TRY_VAL (3)

void TuneTimeKeeper(void)
{
// printfp("\n\r  TuneTimeKeeper");


unsigned char tmp_sec;
unsigned char tmp_min;
unsigned char tmp_hour;
unsigned char tmp_mday;
unsigned char tmp_month;
unsigned char tmp_year;

  tmp_sec =  ClockReadSec();

  if( tmp_sec != g_gpsdata.time.tm_sec)
  {
   if(trysec > TRY_VAL)
   {
     printfpd("\n\r Tyne sec to : %d",g_gpsdata.time.tm_sec );
     printfpd("have sec : %d",  tmp_sec); 
 
    trysec = 0;
    ClockWriteSec(g_gpsdata.time.tm_sec);
   }
   else
   {
    trysec++;
   } 
  }
  else
  { 
    trysec = 0;
  } 
  
   tmp_min = ClockReadMin();

  
   if(tmp_min != g_gpsdata.time.tm_min)
  {
   if(trymin > TRY_VAL)
   {
     printfpd("\n\r Tyne min to : %d",g_gpsdata.time.tm_min );
     printfpd("have min : %d", tmp_min ); 

   
    trymin = 0;
    ClockWriteMin(g_gpsdata.time.tm_min);
   }
   else
   {
    trymin++;
   } 
  }
  else
  { 
    trymin = 0;
  } 
  
  
  
    tmp_hour =  ClockReadHours();
   if( tmp_hour  != (unsigned char)(g_gpsdata.time.tm_hour))
  {
   if(tryhour > TRY_VAL)
   {
     printfpd("\n\r Tyne hour to : %d", g_gpsdata.time.tm_hour );
     printfpd("have hour : %d",  tmp_hour); 
    tryhour = 0;
    ClockWriteHours(g_gpsdata.time.tm_hour);
   }
   else
   {
    tryhour++;
   } 
  }
  else
  { 
    tryhour = 0;
  } 
  
   tmp_mday =  ClockReadDate(); 
  
  
   if( tmp_mday != g_gpsdata.time.tm_mday)
  {
   if(tryday > TRY_VAL)
   {
     printfpd("\n\r Tyne day to : %d", g_gpsdata.time.tm_mday );
     printfpd("have day : %d",  tmp_mday); 


    tryday = 0;
    ClockWriteDate(g_gpsdata.time.tm_mday);
   }
   else
   {
    tryday++;
   } 
  }
  else
  { 
    tryday = 0;
  } 
  
  tmp_month = ClockReadMonth();
  
     if( tmp_month != g_gpsdata.time.tm_mon)
  {
   if(trymon > TRY_VAL)
   {
     printfpd("\n\r Tyne month to : %d", g_gpsdata.time.tm_mon);
     printfpd("have month : %d", tmp_month); 


    trymon = 0;
    ClockWriteMonth(g_gpsdata.time.tm_mon);
   }
   else
   {
    trymon++;
   } 
  }
  else
  { 
    trymon = 0;
  } 
  
  tmp_year = ClockReadYear();

  
  if( tmp_year != g_gpsdata.time.tm_year - 2000)
  {
   if(tryyear > TRY_VAL)
   {
    printfpd("\n\r Tyne year to : %d", g_gpsdata.time.tm_year - 2000);
     printfpd("have year : %d",tmp_year); 


    tryyear = 0;
    ClockWriteYear(g_gpsdata.time.tm_year - 2000);
   }
   else
   {
    tryyear++;
   } 
  }
  else
  { 
    tryyear = 0;
  } 

}

static gboolean ubx_parse_cfg_tp5(ubx_msg_t *msg)
{
U1 *buf = msg->payload_addr;

U1  tpIdx = (U1)READ_U1(buf);// Time pulse selection (0 = TIMEPULSE, 1 =  TIMEPULSE2)
U1  version = (U1)READ_U1(buf+1); // Version, 1 for this message
//U1  reserved1[2];//  - Reserved
 signed short  antCableDelay = (I2)READ_U2(buf+4);//4 ns Antenna cable delay
 signed short  rfGroupDelay = (I2)READ_U2(buf+6);//6 ns RF group delay
U4  freqPeriod = (U4)READ_U4(buf+8); //8 Hz_or_us Frequency or period time, depending on setting of bit 'isFreq'
U4  freqPeriodLoc = (U4)READ_U4(buf+12); //12 Hz_or_us Frequency or period time when locked to GNSS time, only used if 'lockedOtherSet' is set
U4  pulseLenRatio  = (U4)READ_U4(buf+16);//16 us_or_2  ^-32 Pulse length or duty cycle, depending on 'isLength'
U4  pulseLenRatioLock  = (U4)READ_U4(buf+20); //20  us_or_2  ^-32 Pulse length or duty cycle when locked to GNSS time, only used if 'lockedOtherSet' is set
 signed long  userConfigDel = (I4)READ_U4(buf+24); //24  ay ns User configurable time pulse delay
 unsigned long  flags = (X4)READ_U4(buf+28);//28 - Configuration flags (see graphic below)  Bitfield flags This Graphic explains the bits of flags

//Name Description
//-active         If set enable time pulse; if pin assigned to another function, other function takes precedence.
//                 Must be set for FTS variant.
//-lockGnssFreq If set synchronize time pulse to GNSS as soon as GNSS time is valid. If not set, or before GNSS time is valid use
//             local clock.
//                This flag is ignored by the FTS product variant; in this case the receiver always locks to the best available
//-time/frequency  reference (which is not necessarily GNSS).
//-lockedOtherSet
//If set the receiver switches between the timepulse settings given by 'freqPeriodLocked' & 'pulseLenLocked' and
//those given by 'freqPeriod' & 'pulseLen'. The 'Locked' settings are used where the receiver has an accurate sense
//of time. For non-FTS products, this occurs when GNSS solution with a reliable time is available, but for FTS
//products the setting syncMode field governs behavior. In all cases, the receiver only uses 'freqPeriod' & 'pulseLen'
//when the flag is unset.
//-isFreq If set 'freqPeriodLock' and 'freqPeriod' are interpreted as frequency, otherwise interpreted as period.
//-isLength If set 'pulseLenRatioLock' and 'pulseLenRatio' interpreted as pulse length, otherwise interpreted as duty cycle.
//-alignToTow Align pulse to top of second (period time must be integer fraction of 1s).
//Also set 'lockGnssFreq' to use this feature.
//This flag is ignored by the FTS product variant; it is assumed to be always set (as is lockGnssFreq). Set maxSlewRate
//and maxPhaseCorrRate fields of CFG-SMGR to 0 to disable alignment.


    printfpd("\n\rGGG TP5: %d", tpIdx);
    printfpd(" v: %d", version);
    printfpd(" aD: %d", antCableDelay);
    printfpd(" rGD: %d", rfGroupDelay);
    printfpd(" fP: %d", freqPeriod);
    printfpd(" fPL: %d", freqPeriodLoc);
    printfpd("\n\r pL: 0x%x", pulseLenRatio);
    printfpd(" pLL: 0x%x", pulseLenRatioLock);
    printfpd(" uCD: 0x%x", userConfigDel);
    printfpd(" flags 0x%x\n\r", flags);



}

#define TUNE_PERIOD (5)

static gboolean ubx_parse_nav_timeutc(ubx_msg_t *msg)
{
  // printfp("\n\r ubx_parse_nav_timeutc");

  unsigned char tmp;
 int nano;
//  unsigned long itow;

 unsigned int accur;

	U1 *buf = msg->payload_addr;
   
	/**
	 * 0x01 = Valid Time of Week
	 * 0x02 = Valid Week Number
	 * 0x04 = Valid UTC (Leap Seconds already known?)
	 */
	U1 valid = (U1)READ_U1(buf+19);
   
 //   printfpd("\n\r UTC time VALID ? 0x%x \n\r", valid);
    
    tmp = valid & MASK_BIT_2;

       
 //	if (valid != 0x07)
   if(!tmp)
    {
     //   printfp("\n\r UTC time NO VALID");
       printfpd("\n\r UTC time VALID ? 0x%x \n\r", valid);

     
		g_gpsdata.time_valid = FALSE;
       time_valid = 0;
		return TRUE;
	}
   else{ /* Body */
     //    printfp("\n\r UTC time VALID");

   
} /* Endbody */
   
//	g_gpsdata.time.tm_year = (U2)READ_U2(buf+12) - 1900;
	g_gpsdata.time.tm_year = (U2)READ_U2(buf+12);
//	g_gpsdata.time.tm_mon = (U1)READ_U1(buf+14) - 1;
	g_gpsdata.time.tm_mon = (U1)READ_U1(buf+14);
	g_gpsdata.time.tm_mday = (U1)READ_U1(buf+15);
	g_gpsdata.time.tm_hour = (U1)READ_U1(buf+16);
	g_gpsdata.time.tm_min = (U1)READ_U1(buf+17);
	g_gpsdata.time.tm_sec = (U1)READ_U1(buf+18);
   nano = (signed int)READ_U4(buf+8);
   accur =  READ_U4(buf+4);
 //  itow =    READ_U4(buf);
 //  glob_cnt = itow / 1000000; //time in ms

 //150212	g_gpsdata.time.tm_zone = "UTC";
 
   
    printfpd("\n\r UTC time : %d", g_gpsdata.time.tm_year);
    printfpd(" : %d", g_gpsdata.time.tm_mon);
    printfpd(" : %d", g_gpsdata.time.tm_mday);
    printfpd(" : %d", g_gpsdata.time.tm_hour);
    printfpd(" : %d", g_gpsdata.time.tm_min);
    printfpd(" : %d", g_gpsdata.time.tm_sec);
 //   printfpd(" : %d", itow);
    printfpd(" : %d", nano);
    printfpd(" acc %ld ", accur);
    printfpd(" my:%d ", glob_cnt);

    
 //    glob_cnt = itow / 1000000; //time in ms
 if (nano < 0) nano = 0;
   glob_cnt = nano / 1000000; //use nano for msec
 

	g_gpsdata.time_valid = TRUE;
   time_valid = 0x80;
   
   
   
 //t  if(!g_gpsdata.time.tm_sec)
 if(!(g_gpsdata.time.tm_sec) % TUNE_PERIOD)
//   if(1)
   { 
     TuneTimeKeeper();
   } 

//150212	   if (! g_context.time_synced)
//150212		sync_gpstime_to_system(&g_gpsdata.time);

	return TRUE;
}




static gboolean ubx_parse_nav_timegps(ubx_msg_t *msg)
{
  // printfp("\n\r ubx_parse_nav_timeutc");

  struct tm Tm;
  
  unsigned char tmp;
  
  signed int nano;
  unsigned long itow;
  signed short week;
  signed char leapS;
  

 unsigned int accur;

	U1 *buf = msg->payload_addr;
   
	/**
	 * 0x01 = Valid Time of Week
	 * 0x02 = Valid Week Number
	 * 0x04 = Valid UTC (Leap Seconds already known?)
	 */
	U1 valid = (U1)READ_U1(buf+11);
   
 //   printfpd("\n\r GPS time VALID ? 0x%x \n\r", valid);
    
 //   tmp = valid & MASK_BIT_2;
    tmp = valid & 7;

       
 //	if (valid != 0x07)
   if(tmp != 7)
    {
     //   printfp("\n\r UTC time NO VALID");
          printfpd("\n\r GPS time VALID ? 0x%x \n\r", valid);
		g_gpsdata.time_valid = FALSE;
       time_valid = 0;
		return TRUE;
	}
   else{ /* Body */
     //    printfp("\n\r UTC time VALID");

   
} /* Endbody */
    /*
//	g_gpsdata.time.tm_year = (U2)READ_U2(buf+12) - 1900;
	g_gpsdata.time.tm_year = (U2)READ_U2(buf+12);
//	g_gpsdata.time.tm_mon = (U1)READ_U1(buf+14) - 1;
	g_gpsdata.time.tm_mon = (U1)READ_U1(buf+14);
	g_gpsdata.time.tm_mday = (U1)READ_U1(buf+15);
	g_gpsdata.time.tm_hour = (U1)READ_U1(buf+16);
	g_gpsdata.time.tm_min = (U1)READ_U1(buf+17);
	g_gpsdata.time.tm_sec = (U1)READ_U1(buf+18);
   
   */
   
   nano = (signed int)READ_U4(buf+4);
   accur =  READ_U4(buf+12);
   itow =    READ_S4(buf);
 //  ftow =    READ_U4(buf+4);
   week =   READ_S2(buf+8);
   leapS   =   READ_S1(buf+10);


 //  glob_cnt = itow / 1000000; //time in ms

 //150212	g_gpsdata.time.tm_zone = "UTC";
 
  SecondsSinceEpochToDateTime((struct tm* )&Tm, itow/1000);

   
 
 
   
    printfpd("\n\r GPS itow : %d", itow);
    printfpd(" nano : %d", nano);
    printfpd(" week : %d",week);
    printfpd(" leapS : %d", leapS);
    printfpd(" acc : %ld ", accur);
    
   /* 
 pTm->tm_sec = sec;          // [0,59]
  pTm->tm_min = min;          // [0,59]
  pTm->tm_hour = hour;        // [0,23]
  pTm->tm_mday = mday;        // [1,31]  (day of month)
  pTm->tm_mon = month - 1;    // [0,11]  (month)
  pTm->tm_year = year - 1900; // 70+     (year since 1900)
  pTm->tm_wday = wday;        // [0,6]   (day since Sunday AKA day of week)
  pTm->tm_yday = yday;        // [0,365] (day since January 1st AKA day of year)
  pTm->tm_isdst = -1;         // daylight saving time flag
  
 */ 
    printfpd("\n\r GPS time : %d", Tm.tm_year + 1900);
    printfpd(" : %d",Tm.tm_mon + 1);
    printfpd(" : %d", Tm.tm_mday);
    printfpd(" : %d", Tm.tm_hour);
    printfpd(" : %d",Tm.tm_min);
    printfpd(" : %d", Tm.tm_sec);
 //   printfpd(" : %d", itow);
    printfpd(" : %d", nano);
    printfpd(" acc %ld ", accur);
 //   printfpd("my:%d ", glob_cnt);

    

    
    
    
   // printfpd("my:%d ", glob_cnt);

    
 //    glob_cnt = itow / 1000000; //time in ms
// if (nano < 0) nano = 0;
   glob_cnt = itow; //use nano for msec
 

	g_gpsdata.time_valid = TRUE;
   time_valid = 0x80;
   
   
   
 //t  if(!g_gpsdata.time.tm_sec)
 if(!(itow))
//   if(1)
   { 
     TuneTimeKeeper();
   } 

//150212	   if (! g_context.time_synced)
//150212		sync_gpstime_to_system(&g_gpsdata.time);

	return TRUE;
}


static gboolean ubx_read_and_parse_response(ubx_msg_t *msg, ubx_msg_type_t *type)
{
 // printfp("start_p");
           //    OperateBuffers_usart0t();



	if (! ubx_read_next_msg(msg, type)) {
		if (type != NULL)
      { 
        //	 		printfpd("\n\rread response failed:  id=%02x",  type->id);
         //      printfpd("  class=%02x", type->class_);
          //     OperateBuffers_usart0t();

		}
      else
      {
        	 	//	printfp("\n\rread response failed");
        //        OperateBuffers_usart0t();

      }
		return FALSE;
	}
   
     //  printfpd("\n\rread response ok class: % x", msg->class_);
    //     printfpd("id %x", msg->id);
     //      OperateBuffers_usart0t();


	if (msg->class_ == UBX_CLASS_NAV) {      //1
		if (msg->id == UBX_ID_NAV_STATUS)    //3
			return ubx_parse_nav_status(msg);
		else if (msg->id == UBX_ID_NAV_POSLLH)   //2
			return ubx_parse_nav_posllh(msg);
		else if (msg->id == UBX_ID_NAV_VELNED)    //12
			return ubx_parse_nav_velned(msg);
		else if (msg->id == UBX_ID_NAV_TIMEUTC)   //21
			return ubx_parse_nav_timeutc(msg);
      else if (msg->id == UBX_ID_NAV_TIMEGPS)   //21
			return ubx_parse_nav_timegps(msg);
		else if (msg->id == UBX_ID_NAV_SVINFO)     //30
			return ubx_parse_nav_svinfo(msg);
	}
   
   if (msg->class_ == UBX_CLASS_CFG) {      //1
		if (msg->id == UBX_ID_CFG_TP5)    //3
			return ubx_parse_cfg_tp5(msg);
    }
   
   
   

	return FALSE;
}

/**                                         
 * Poll a group of messages.
 * Save result to msg. The class and id of a msg must be initialized.
 * Return:
 * 		TRUE: ALL ok, may be invalid
 * 		FALSE: part or all failed: I/O error
 */
 
//#define POLLED_MSG   (5)
 
gboolean ubx_poll_group(gboolean pollsv)
{
 //  printfp(".");

    /*
    static unsigned long counter;
    counter++;
    if (counter < 1000) return 1;
    counter = 0;
    */
    
      //    printfpd("\n\r pollsv :%d \n\r", pollsv);


	ubx_msg_t msg;
	int iz;
	int count = (pollsv)? enabled_type_count : enabled_type_count - 1;
//	int count = (pollsv) ? enabled_type_count - 1 : POLLED_MSG;
 //	int size = count << 3;
  //	int size = 64;   //t   
  	int size = 8;   //t 
 // 	int written = 0;
  	int written = 8 * pollsv;
   
   //   printfpd("\n\r count :%d \n\r", count);
     //   enabled_type_count--;
   
 //ok return; 

  //	for (; size > 0; size-= written)
 // 	for (; size > 0; size-= 8)
   // {
     //   printfpd("\n\rwritten: %d count:", written);
  //      OperateBuffers_usart0t();

 // 		if ((written = write_gps(gps_dev_fd, &poll_packet[written], size)) <= 0)
  		written += write_gps(gps_dev_fd, &poll_packet[written], 8);
      
      //    printfp(" count:");
     //   OperateBuffers_usart0t();

      
      
 //      {
		//	printfp("UBX poll: write device failed");
	  //		return FALSE;
  //	  	}
  //    size -= written;  //my
  //    printfpd("\n\r size :%d", size);
   //	}
  //hier need send	tcdrain(gps_dev_fd);
//    ubx_cfg_tp5(TRUE); 
  //ubx_cfg_prt(0x01, 0x01, 0x01, 38400, TRUE); //test

 //	sleep_ms(SEND_RATE);
 //    delay_mcs(SEND_RATE * 1000);
  delay_mcs(1000);

     
 // return 1; //t   
     
      //  printfpd(" %d ", count);
      //    OperateBuffers_usart0t();
          
      //  printfp("\n\r ");

	gboolean has_failure = FALSE;
   
 //	for (iz=0; iz <=count; iz++) 
 	for (iz=0; iz <=2; iz++)      //30 -quickly
   {
     //   printfp(".");
 //  #ifdef Debug_Baco  
 //           printfp( "\n\rDebugBaco1\n\r");
 //  #endif
  
#ifndef GPS_USART1
     
        OperateBuffers_usart0t();
#else
         OperateBuffers_usart1t();


#endif  


// #ifdef Debug_Baco  
 //           printfp( "\n\rDebugBaco2\n\r");
 //  #endif
      

      
		if (! ubx_read_and_parse_response(&msg, NULL)) {
	  		has_failure = TRUE;   
      //  printfp(" ...break");

     //	 		break;
		}
            
//  #ifdef Debug_Baco  
//            printfp( "\n\rDebugBaco3\n\r");
//   #endif
     
      
      
 	}
     //    printfp(">");
      //    OperateBuffers_usart0t();

	return ! has_failure;
}



gboolean ubx_device_init()
{
   unsigned cnt;
#ifndef GPS_USART1

	printfpd("UBX_USART0 init:  baud rate=%d...", BAUD_RATE);
   SetUsart0BaudRate(BAUD_RATE);
   
#else
   printfpd("UBX_USART1 init:  baud rate=%d...", BAUD_RATE);
   SetUsart1BaudRate(BAUD_RATE);


#endif   
   
   
	printfp("\n\rInitializing GPS...");

 //ok  return 1;
  
	ubx_init(gps_dev_fd);
//________________________________________________my   
 printfp("\n\rcold start ubx_cfg_rst:");
   
  // ubx_cfg_rst(0xffff, 0); //hardware reset
   ubx_cfg_rst(0xffff, 4); //hardware reset    with shutdown
   
   delay_mcs(1000000l);
//________________________________________________my
   
  //ok   return 1;
   printfp("\n\rubx_cfg_rate:");


 	if (! ubx_cfg_rate((U2)SEND_RATE, TRUE))    //b5 62 06 08
// if (! ubx_cfg_rate((U2)100, TRUE))    //b5 62 06 08

	 //t	return FALSE;
       {  
         //try second time
         ubx_cfg_rate((U2)SEND_RATE, TRUE);
       
       } 
           // return 1;
 
      printfp("\n\rubx_cfg_prt:");
      
      cnt = 10;
 
      while(cnt--)
     {
 

 	if ( ubx_cfg_prt(0x01, 0x01, 0x01, BAUD_RATE, TRUE)) break;    //b5 62 06 00
 //	if (! ubx_cfg_prt(0x01, 0x01, 0x01, 38400, TRUE))     //b5 62 06 00
       }
	//	return FALSE;
      //     { 
           
        //     ubx_cfg_prt(0x01, 0x01, 0x01, BAUD_RATE, TRUE);
           
           
        //    } 
           
           
           
           
           
       printfp("\n\rubx_cfg_msg_nmea_ubx:");

  /* Disable NMEA to avoid flushing UBX binary output */
 	if (! ubx_cfg_msg_nmea_ubx(0x0, TRUE, TRUE))    //b5 62 06 01 18
	 //	return FALSE;
       {  } 

          printfp("\n\rubx_cfg_msg_nmea_std:");
  	if (! ubx_cfg_msg_nmea_std(0x0, TRUE, TRUE))      //b5 62 06 01 42
   	  //	return FALSE;
       {  } 
    
      cnt = 10;
     printfp("\n\rubx_cfg_tp5:");
     while(cnt--)
     {
         if (ubx_cfg_tp5(TRUE)) break;          //b5 62 06  31
     } /* Endbody */
       
     cnt = 10;  
     printfp("\n\rubx_cfg_tp5_2:");
     while(cnt--)
     {
         if (ubx_cfg_tp5_2(TRUE)) break;          //b5 62 06  31
     } /* Endbody */

       
       
 //	if (! ubx_cfg_sbas(TRUE, TRUE))
	//	return FALSE;
  //   {  } 


  //	if (! ubx_cfg_rxm(0x3, 0x0, TRUE))
	//	return FALSE;
   //  {  } 


	/* dynamic platform model */
 //	if (! ubx_cfg_nav2(0x2, TRUE))
	//	return FALSE;
  //  {  } 


 //	show_status("Set initial AID data...");

	/* no matter success or failure */
 //	set_initial_aid_data();

 //	usart_flush_output();

	printfp("\n\rGPS was initialized.");  
   
 //      printfp("\n\rubx_mon_ver_poll:");
 /*   
	ubx_mon_ver_poll(g_ubx_receiver_versions, sizeof(g_ubx_receiver_versions));    //   B5 62 0a 04 00
   printfp("\n\rg_ubx_receiver_versions:");
 	printfp(g_ubx_receiver_versions);
    
*/
	return TRUE;
}


gboolean ubx_device_mon()
{
static unsigned long cnt;
cnt++;

//ubx_poll_group(0);    //one type request
//ubx_poll_group(1); // 1 - tp5
if(cnt == 1000)
{

//printfp("\n\r > 2");
//cnt = 0;
ubx_poll_group(0);   // 0 - utc time
}
else  if(cnt >= 2000)

{
//printfp("\n\r 0");


cnt = 0;
ubx_poll_group(0);   // 13 - gpc time
}
//printbufferusart0();   
 if(GetTestMode() == 0x50)
 {
 printbufferusart1();   
 }
 
 
 
}
