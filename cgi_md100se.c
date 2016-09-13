
/**HEADER********************************************************************
* 
* Copyright (c) 2008 Freescale Semiconductor;
* All Rights Reserved
*
* Copyright (c) 1989-2008 ARC International;
* All Rights Reserved
*
*************************************************************************** 
*
* THIS SOFTWARE IS PROVIDED BY FREESCALE "AS IS" AND ANY EXPRESSED OR 
* IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES 
* OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  
* IN NO EVENT SHALL FREESCALE OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, 
* INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES 
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR 
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) 
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, 
* STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING 
* IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF 
* THE POSSIBILITY OF SUCH DAMAGE.
*
**************************************************************************
*
* $FileName: cgi.c$
* $Version : 3.6.13.0$
* $Date    : Jun-4-2010$
*
* Comments:
*
*   Example of shell using RTCS.
*
*END************************************************************************/

#include "httpd.h"
#include "cgi.h"
//#include "httpdsrv.h"
#include "PVG610_API.h"




volatile uint_8 led_status = 0;
//extern MQX_FILE_PTR output_port;

#if BSPCFG_ENABLE_ADC
extern MQX_FILE_PTR adc_fd[ADC_HW_CHANNELS];
#endif

   /*
extern "C" float GetFreqOffset();
extern "C" float GetChannelDelay();
extern "C" float GetIFBalance();
extern "C" signed GetSatLock();
extern "C" char* GetSatInput();
extern "C" char* GetSatSearch();
extern "C" unsigned GetSatACnt();
 */
 
extern "C" double GetMEbN0(void);
extern "C" double GetMBER(void);
extern "C" double GetMBERE(void);
extern "C" double GetMAGC(void);
extern "C" double GetMSweep(void);
extern "C" char* GetTModul();
extern "C" char* GetDFE();


extern "C" double GetTCode();
extern "C" double GetTSymb();
extern "C" char* GetRModul();
extern "C" double GetRCode();
extern "C" double GetRSymb();
extern "C" char* GetEthMode();

extern "C" double GetMEthSend(void);
extern "C" double GetMEthReceived(void);
extern "C" double GetMEthSendU(void);
extern "C" double GetMEthReceivedCRC(void);

extern "C" char*  GetLogStr0();
extern "C" char*  GetLogStr1();







 
int cgi_ethstat1(HTTPD_SESSION_STRUCT *session);
int cgi_log(HTTPD_SESSION_STRUCT *session);
int cgi_ethstat(HTTPD_SESSION_STRUCT *session);
int cgi_md100se(HTTPD_SESSION_STRUCT *session);
//int cgi_pumstat(HTTPD_SESSION_STRUCT *session);
int cgi_ipstat(HTTPD_SESSION_STRUCT *session);
int cgi_icmpstat(HTTPD_SESSION_STRUCT *session);
int cgi_udpstat(HTTPD_SESSION_STRUCT *session);
int cgi_tcpstat(HTTPD_SESSION_STRUCT *session);

int cgi_analog_data(HTTPD_SESSION_STRUCT *session);
int cgi_rtc_data(HTTPD_SESSION_STRUCT *session);

int cgi_toggle_led1(HTTPD_SESSION_STRUCT *session);
int cgi_toggle_led2(HTTPD_SESSION_STRUCT *session);
int cgi_toggle_led3(HTTPD_SESSION_STRUCT *session);
int cgi_toggle_led4(HTTPD_SESSION_STRUCT *session);

const HTTPD_CGI_LINK_STRUCT cgi_lnk_tbl[] = {
    { "ethstat1",      cgi_ethstat1},
    { "log",            cgi_log},
    { "ethstat",        cgi_ethstat},
    { "md100se",        cgi_md100se},
//    { "pumstat",        cgi_pumstat},
    { "ipstat",         cgi_ipstat},
    { "icmpstat",       cgi_icmpstat},
    { "udpstat",        cgi_udpstat},
    { "tcpstat",        cgi_tcpstat},
    { "analog",         cgi_analog_data},
    { "rtcdata",        cgi_rtc_data},
    { "toggleled1",     cgi_toggle_led1},
    { "toggleled2",     cgi_toggle_led2},
    { "toggleled3",     cgi_toggle_led3},
    { "toggleled4",     cgi_toggle_led4},
    { 0, 0 }    // DO NOT REMOVE - last item - end of table
};
  
static int cgi_analog_data(HTTPD_SESSION_STRUCT *session) {

#ifdef HTTP_PRINTM
printfp("cgi_analog_data");
#endif

    static int aval = 0;
    int i = 0;
     /*
#if BSPCFG_ENABLE_ADC
    ADC_RESULT_STRUCT data;
    
    for (i = 0; (i < 8) && (i < ADC_HW_CHANNELS); i++) {
        if (adc_fd[i] == NULL)
            break;
        
        if (read(adc_fd[i], &data, sizeof(ADC_RESULT_STRUCT))) {
            CGI_SEND_NUM((uint_32)data.result);
        }
        else {
            CGI_SEND_NUM(0);
        }
    }
#endif
     */
    // generate values for unused chanels   
    for (; i < 8; i++) {
        CGI_SEND_NUM(aval += 50);
    }

    if (aval > 3500)
        aval = 0;

    return session->request.content_len;
}
     
static int cgi_rtc_data(HTTPD_SESSION_STRUCT *session) {
    TIME_STRUCT time;
    int min, hour;
    
#ifdef HTTP_PRINTM
printfp("cgi_rtc_data");
#endif
    
    
    _time_get(&time);
    
    min = time.SECONDS / 60;
    hour = min / 60;
    min %= 60;
    
    CGI_SEND_NUM(hour);
    CGI_SEND_NUM(min);
    CGI_SEND_NUM(time.SECONDS % 60);

#ifdef HTTP_PRINTM
printfpd("\n\r  %d", time.SECONDS);
#endif

    return session->request.content_len;
}
 /*
int cgi_pumstat(HTTPD_SESSION_STRUCT *session) {

#ifdef HTTP_PRINTM
printfp("cgi_pumstat");
#endif



    TIME_STRUCT time;
    int min, hour;
    
    
    _time_get(&time);
    
    min = time.SECONDS / 60;
    hour = min / 60;
    min %= 60;

//#if RTCSCFG_ENABLE_IP_STATS
//    {
  //  IP_STATS_PTR ip = IP_stats();
    
    CGI_SEND_NUM(time.SECONDS % 60);    //temporary
    CGI_SEND_NUM(min );  //temporary
    CGI_SEND_NUM(hour);
    CGI_SEND_FLOAT6(GetFreqOffset());
    CGI_SEND_FLOAT7(GetChannelDelay());
    if(GetSatLock())
    { 
    CGI_SEND_NUM(GetIFBalance());
    }
    else
    { 
    CGI_SEND_STR("N/A");
    } 
    CGI_SEND_STR(GetSatInput());
    CGI_SEND_STR(GetSatSearch());
    CGI_SEND_NUM(GetSatACnt());
//    }
//#else
//    int i;
    
//    for (i = 0; i < 18; i++) {
//        httpd_sendstr(session->sock, "unk\n");
//    }
//#endif

    return session->request.content_len;
}

*/

int cgi_md100se(HTTPD_SESSION_STRUCT *session) {

#ifdef HTTP_PRINTM
printfp("cgi_md100se");
#endif



    TIME_STRUCT time;
    int min, hour;
 unsigned long tmp;   
    
    _time_get(&time);
    
    min = time.SECONDS / 60;
    hour = min / 60;
    min %= 60;

//#if RTCSCFG_ENABLE_IP_STATS
//    {
  //  IP_STATS_PTR ip = IP_stats();
    
  //  CGI_SEND_NUM(time.SECONDS % 60);    //temporary
    
         if(LOCK)
    { 
   // CGI_SEND_STR(" LOCK ");
    CGI_SEND_STR("LOCK  ");
   //   printfp("\n\r send lock");

    }
    else
    { /* Body */
    CGI_SEND_STR("UNLOCK");
     //     printfp("\n\r send unlock");

    } /* Endbody */

    
    
 //   CGI_SEND_NUM(min );  //temporary
    
       CGI_SEND_STR(GetDFE());
       
    CGI_SEND_NUM(hour);
    CGI_SEND_FLOAT6(GetMEbN0());
    CGI_SEND_FLOAT6(GetMBER());
    CGI_SEND_NUM((signed long)GetMBERE());
 //   printfpd("\n\rMBERE %d",(signed long)GetMBERE() );

    
  tmp = (unsigned long)GetMAGC();  
    
    if(tmp == (unsigned long)MAGIC_VAL1)
	{
	 CGI_SEND_STR(" <-45");
  //  printfp("\n\ragc <-45");
	}
	else
	{
    CGI_SEND_FLOAT6(GetMAGC());
    // printfpdv("\n\ragc %f",GetMAGC() );
     //   printfpd("\n\ragc %x",(unsigned long)GetMAGC() );


   }
    
    
    
    CGI_SEND_FLOAT6(GetMSweep());
    CGI_SEND_STR(GetTModul());
    CGI_SEND_FLOAT8(GetTCode());
    CGI_SEND_FLOAT9(GetTSymb());
    CGI_SEND_STR(GetRModul());
  //    CGI_SEND_STR("test> ");

    
    
    CGI_SEND_FLOAT8(GetRCode());
   // printfpdv("\n\rrcode %f",GetRCode() );

    CGI_SEND_FLOAT9(GetRSymb());
    
  
    
    CGI_SEND_NUM(GetMBERE());
    
    //   CGI_SEND_STR(GetDFE());

    
          /*
      if(LOCK)
    { 
   // CGI_SEND_STR(" LOCK ");
    CGI_SEND_STR("LOCK   ");
   //   printfp("\n\r send lock");

    }
    else
    {     CGI_SEND_STR("UNLOCK");
     //     printfp("\n\r send unlock");

    } 
        */


 //   CGI_SEND_FLOAT7(GetChannelDelay());
 //   if(GetSatLock())
 //   { 
 //   CGI_SEND_NUM(GetIFBalance());
 //   }
 //   else
 //   { /* Body */
 //   CGI_SEND_STR("N/A");
 //   } /* Endbody */
 //   CGI_SEND_STR(GetSatInput());
 //   CGI_SEND_STR(GetSatSearch());
 //   CGI_SEND_NUM(GetSatACnt());
//    }
//#else
//    int i;
    
//    for (i = 0; i < 18; i++) {
//        httpd_sendstr(session->sock, "unk\n");
//    }
//#endif

    return session->request.content_len;
}



int cgi_ethstat(HTTPD_SESSION_STRUCT *session) {

#ifdef HTTP_PRINTM
printfp("cgi_ethstat");
#endif



    TIME_STRUCT time;
    int min, hour;
 unsigned long tmp;   
    
    _time_get(&time);
    
    min = time.SECONDS / 60;
    hour = min / 60;
    min %= 60;
    
    CGI_SEND_NUM(time.SECONDS % 60);    //temporary
    CGI_SEND_NUM(min );  //temporary
    CGI_SEND_NUM(hour);
    CGI_SEND_STR(GetEthMode());
    CGI_SEND_NUM(GetMEthSend());
    CGI_SEND_NUM(GetMEthSendU());
    CGI_SEND_NUM(GetMEthReceived());
    CGI_SEND_NUM(GetMEthReceivedCRC());
     return session->request.content_len;
}

extern PVG610_NET_ETH_PM_STRUCT Pma;


int cgi_ethstat1(HTTPD_SESSION_STRUCT *session) {

#ifdef HTTP_PRINTM
printfp("cgi_ethstat1");
#endif



    TIME_STRUCT time;
    int min, hour;
 unsigned long tmp;   
    
    _time_get(&time);
    
    min = time.SECONDS / 60;
    hour = min / 60;
    min %= 60;
    
    CGI_SEND_NUM(time.SECONDS % 60);    //temporary
    CGI_SEND_NUM(min );  //temporary
    CGI_SEND_NUM(hour);
    CGI_SEND_STR(GetEthMode());
    
    
    CGI_SEND_NUM(Pma.rx.truncatedFrames);  //4
    CGI_SEND_NUM(Pma.rx.longEvents);
    CGI_SEND_NUM(Pma.rx.vlanTagsDetected);
    CGI_SEND_NUM(Pma.rx.unsopprtedOpcodes);
    CGI_SEND_NUM(Pma.rx.pauseFrames);
    CGI_SEND_NUM(Pma.rx.controlFrames);
    CGI_SEND_NUM(Pma.rx.dribbleNibbles);  //10
    CGI_SEND_NUM(Pma.rx.broadcasts);
    CGI_SEND_NUM(Pma.rx.multicasts);
    CGI_SEND_NUM(Pma.rx.dones);
    CGI_SEND_NUM(Pma.rx.outOfRangeErrors);
    CGI_SEND_NUM(Pma.rx.lengthCheckErrors);
    CGI_SEND_NUM(Pma.rx.crcErrors);
    CGI_SEND_NUM(Pma.rx.codeErrors);
    CGI_SEND_NUM(Pma.rx.falseCarrierErrors);
    CGI_SEND_NUM(Pma.rx.rxDvEvent);
    CGI_SEND_NUM(Pma.rx.previosPacketDropped);  //20
    CGI_SEND_NUM(Pma.rx.byteCounterLow);
    CGI_SEND_NUM(Pma.rx.byteCounterHigh);
			   
    CGI_SEND_NUM(Pma.tx.vlanTags);
    CGI_SEND_NUM(Pma.tx.backpressuresEvents);
    CGI_SEND_NUM(Pma.tx.pauseFrames);
    CGI_SEND_NUM(Pma.tx.controlFrames);
    CGI_SEND_NUM(Pma.tx.wireByteCounterLow);
    CGI_SEND_NUM(Pma.tx.wireByteCounterHigh);
    CGI_SEND_NUM(Pma.tx.underruns);
    CGI_SEND_NUM(Pma.tx.giants);          //30
    CGI_SEND_NUM(Pma.tx.lateCollisions);
    CGI_SEND_NUM(Pma.tx.maxCollisions);
    CGI_SEND_NUM(Pma.tx.excessiveDefers);
    CGI_SEND_NUM(Pma.tx.nonExcessiveDefers);
    CGI_SEND_NUM(Pma.tx.broadcasts);
    CGI_SEND_NUM(Pma.tx.multicasts);
    CGI_SEND_NUM(Pma.tx.dones);
    CGI_SEND_NUM(Pma.tx.reserved);
    CGI_SEND_NUM(Pma.tx.lengthCheckErrors);
    CGI_SEND_NUM(Pma.tx.crcErrors);           //40
    CGI_SEND_NUM(Pma.tx.collisions);
    CGI_SEND_NUM(Pma.tx.byteCounterLow);
    CGI_SEND_NUM(Pma.tx.byteCounterHigh);      //43
    
    CGI_SEND_NUM(Pma.gfp.fcsErrors); 
    CGI_SEND_NUM(Pma.gfp.checErrors); 
    CGI_SEND_NUM(Pma.gfp.droppedFrames); 
    CGI_SEND_NUM(Pma.gfp.frameDelineationLosses); 

    CGI_SEND_NUM(Pma.qos.rxQ1Frames); 
    CGI_SEND_NUM(Pma.qos.rxQ1DroppedFrames); 
    CGI_SEND_NUM(Pma.qos.rxQ2Frames); 
    CGI_SEND_NUM(Pma.qos.rxQ2DroppedFrams); 
    CGI_SEND_NUM(Pma.qos.txFrames);
    CGI_SEND_NUM(Pma.qos.txDroppedFrames);
    
    
  
    
     return session->request.content_len;
}



int cgi_log(HTTPD_SESSION_STRUCT *session) {

#ifdef HTTP_PRINTM
printfp("cgi_log");
#endif



    TIME_STRUCT time;
    int min, hour;
 unsigned long tmp;   
    
    _time_get(&time);
    
    min = time.SECONDS / 60;
    hour = min / 60;
    min %= 60;
    
    CGI_SEND_NUM(time.SECONDS % 60);    //temporary
    CGI_SEND_NUM(min );  //temporary
    CGI_SEND_NUM(hour);
    
//_______________________________________________________________________________
unsigned long ev_addr;	 

 ev_addr = GetEventAddr();

 unsigned short ev_id = GetEvId(ev_addr);
 //2 evevts  for(unsigned j = start_event; j < start_event+2; j++)
// for(unsigned j = start_event; j < start_event+10; j++)
 for(unsigned j = start_event; j < start_event+20; j++)
 {
  view_counter = j;
  if(EventToMenu())
  {
 // printfpd("\n\r ok :%d", j);
 // printfp(LogStr0.Value);
//  printfp(LogStr1.Value);

  //	   sprintf(NewKey, "%s", "                        ");
  //	    sprintf(NewKey, "++%4d", j);
  //  memcpy((Key+25), NewKey, 24);  

  //     sprintf(NewKey, "%s", LogStr0.Value);  //
       CGI_SEND_STR(GetLogStr0());
	//   sprintf(NewKey, "%s", ":23456789012345678901234");  //
    //        memcpy((Key), NewKey, 24);  
  //t1	    memcpy((Key), NewKey, 6);

    //   sprintf(NewKey, "%s", "                        ");
	 //    memcpy((Key+25), NewKey, 24);  

    //   sprintf(NewKey, "%s", LogStr1.Value);  //
         CGI_SEND_STR(GetLogStr1());

	//   sprintf(NewKey, "%s", "_123456789_");
	   	//  memcpy((Key+25), NewKey, 24);  

  }	 //if
   else
 {
  // 	  printfpd("\n\r ________wrong : %d", j);

    //  break;
 }

//  Key += 72;
 } //for
   view_counter = 1;
//_______________________________________________________________________________    
    
     return session->request.content_len;
}











int cgi_ipstat(HTTPD_SESSION_STRUCT *session) {
#ifdef HTTP_PRINTM
printfp("cgi_ipstat");
#endif

//#if RTCSCFG_ENABLE_IP_STATS
//    {
    IP_STATS_PTR ip = IP_stats();
    
    CGI_SEND_NUM(ip->ST_RX_TOTAL);
    CGI_SEND_NUM(ip->ST_RX_DELIVERED);
    CGI_SEND_NUM(ip->ST_RX_FORWARDED);
    CGI_SEND_NUM(ip->ST_RX_MISSED);
    CGI_SEND_NUM(ip->ST_RX_ERRORS);
    CGI_SEND_NUM(ip->ST_RX_DISCARDED);
    CGI_SEND_NUM(ip->ST_RX_HDR_ERRORS);
    CGI_SEND_NUM(ip->ST_RX_ADDR_ERRORS);
    CGI_SEND_NUM(ip->ST_RX_NO_PROTO);
    CGI_SEND_NUM(ip->ST_RX_FRAG_RECVD);
    CGI_SEND_NUM(ip->ST_RX_FRAG_REASMD);
    CGI_SEND_NUM(ip->ST_RX_FRAG_DISCARDED);

    CGI_SEND_NUM(ip->ST_TX_TOTAL);
    CGI_SEND_NUM(ip->ST_TX_MISSED);
    CGI_SEND_NUM(ip->ST_TX_ERRORS);
    CGI_SEND_NUM(ip->ST_TX_DISCARDED);
    CGI_SEND_NUM(ip->ST_TX_FRAG_FRAGD);
    CGI_SEND_NUM(ip->ST_TX_FRAG_SENT);
    CGI_SEND_NUM(ip->ST_TX_FRAG_DISCARDED);
//    }
//#else
//    int i;
    
//    for (i = 0; i < 18; i++) {
//        httpd_sendstr(session->sock, "unk\n");
//    }
//#endif

    return session->request.content_len;
}
   
int cgi_icmpstat(HTTPD_SESSION_STRUCT *session) {

#ifdef HTTP_PRINTM
printfp("cgi_icmppstat");
#endif

//#if RTCSCFG_ENABLE_ICMP_STATS
//    {
    ICMP_STATS_PTR icmp = ICMP_stats();

    CGI_SEND_NUM(icmp->ST_RX_TOTAL);
    CGI_SEND_NUM(icmp->ST_RX_MISSED);
    CGI_SEND_NUM(icmp->ST_RX_ERRORS);
    CGI_SEND_NUM(icmp->ST_RX_DISCARDED);
    CGI_SEND_NUM(icmp->ST_RX_BAD_CHECKSUM + icmp->ST_RX_SMALL_DGRAM);
    CGI_SEND_NUM(icmp->ST_RX_BAD_CODE);
    CGI_SEND_NUM(icmp->ST_RX_RD_NOTGATE);
    
    CGI_SEND_NUM(icmp->ST_TX_TOTAL);
    CGI_SEND_NUM(icmp->ST_TX_MISSED);
    CGI_SEND_NUM(icmp->ST_TX_ERRORS);
    CGI_SEND_NUM(icmp->ST_TX_DISCARDED);
    
    CGI_SEND_NUM(icmp->ST_RX_DESTUNREACH);
    CGI_SEND_NUM(icmp->ST_RX_TIMEEXCEED);
    CGI_SEND_NUM(icmp->ST_RX_PARMPROB);
    CGI_SEND_NUM(icmp->ST_RX_SRCQUENCH);
    CGI_SEND_NUM(icmp->ST_RX_REDIRECT);
    CGI_SEND_NUM(icmp->ST_RX_ECHO_REQ);
    CGI_SEND_NUM(icmp->ST_RX_ECHO_REPLY);
    CGI_SEND_NUM(icmp->ST_RX_TIME_REQ);
    CGI_SEND_NUM(icmp->ST_RX_TIME_REPLY);
    CGI_SEND_NUM(icmp->ST_RX_INFO_REQ);
    CGI_SEND_NUM(icmp->ST_RX_INFO_REPLY);
    CGI_SEND_NUM(icmp->ST_RX_OTHER);
    
    CGI_SEND_NUM(icmp->ST_TX_DESTUNREACH);
    CGI_SEND_NUM(icmp->ST_TX_TIMEEXCEED);
    CGI_SEND_NUM(icmp->ST_TX_PARMPROB);
    CGI_SEND_NUM(icmp->ST_TX_SRCQUENCH);
    CGI_SEND_NUM(icmp->ST_TX_REDIRECT);
    CGI_SEND_NUM(icmp->ST_TX_ECHO_REQ);
    CGI_SEND_NUM(icmp->ST_TX_ECHO_REPLY);
    CGI_SEND_NUM(icmp->ST_TX_TIME_REQ);
    CGI_SEND_NUM(icmp->ST_TX_TIME_REPLY);
    CGI_SEND_NUM(icmp->ST_TX_INFO_REQ);
    CGI_SEND_NUM(icmp->ST_TX_INFO_REPLY);
    CGI_SEND_NUM(icmp->ST_TX_OTHER);
//    }
//#else
//    int i;
    
//    for (i = 0; i < 34; i++) {
//        httpd_sendstr(session->sock, "unk\n");
//    }
//#endif

    return session->request.content_len;
}
   
int cgi_udpstat(HTTPD_SESSION_STRUCT *session) {

#ifdef HTTP_PRINTM
printfp("cgi_udpstat");
#endif

//#if RTCSCFG_ENABLE_UDP_STATS
//    {
    UDP_STATS_PTR udp = UDP_stats();

    CGI_SEND_NUM(udp->ST_RX_TOTAL);
    CGI_SEND_NUM(udp->ST_RX_MISSED);
    CGI_SEND_NUM(udp->ST_RX_ERRORS);
    CGI_SEND_NUM(udp->ST_RX_DISCARDED);
    CGI_SEND_NUM(udp->ST_RX_BAD_PORT + udp->ST_RX_BAD_CHECKSUM + udp->ST_RX_SMALL_DGRAM + udp->ST_RX_SMALL_PKT);                             
    CGI_SEND_NUM(udp->ST_RX_NO_PORT);
    
    CGI_SEND_NUM(udp->ST_TX_TOTAL);
    CGI_SEND_NUM(udp->ST_TX_MISSED);
    CGI_SEND_NUM(udp->ST_TX_ERRORS);
    CGI_SEND_NUM(udp->ST_TX_DISCARDED);
//    }
//#else
//    int i;
    
//    for (i = 0; i < 9; i++) {
//        httpd_sendstr(session->sock, "unk\n");
//    }
//#endif

    return session->request.content_len;
}
   
int cgi_tcpstat(HTTPD_SESSION_STRUCT *session) {

#ifdef HTTP_PRINTM
printfp("cgi_tcpstat");
#endif

//#if RTCSCFG_ENABLE_TCP_STATS
//    {
    TCP_STATS_PTR        tcp  = TCP_stats();
    
    CGI_SEND_NUM(tcp->ST_RX_TOTAL);
    CGI_SEND_NUM(tcp->ST_RX_MISSED);
    CGI_SEND_NUM(tcp->ST_RX_ERRORS);
    CGI_SEND_NUM(tcp->ST_RX_DISCARDED);
    CGI_SEND_NUM(tcp->ST_RX_BAD_PORT + tcp->ST_RX_BAD_CHECKSUM + tcp->ST_RX_SMALL_HDR + tcp->ST_RX_SMALL_DGRAM + tcp->ST_RX_SMALL_PKT);
    CGI_SEND_NUM(tcp->ST_RX_BAD_ACK);
    CGI_SEND_NUM(tcp->ST_RX_BAD_DATA);
    CGI_SEND_NUM(tcp->ST_RX_LATE_DATA);
    CGI_SEND_NUM(tcp->ST_RX_DATA);
    CGI_SEND_NUM(tcp->ST_RX_DATA_DUP);
    CGI_SEND_NUM(tcp->ST_RX_ACK);
    CGI_SEND_NUM(tcp->ST_RX_ACK_DUP);
    CGI_SEND_NUM(tcp->ST_RX_RESET);
    CGI_SEND_NUM(tcp->ST_RX_PROBE);
    CGI_SEND_NUM(tcp->ST_RX_WINDOW);
    
    CGI_SEND_NUM(tcp->ST_TX_TOTAL);
    CGI_SEND_NUM(tcp->ST_TX_MISSED);
    CGI_SEND_NUM(tcp->ST_TX_ERRORS);
    CGI_SEND_NUM(tcp->ST_TX_DISCARDED);
    CGI_SEND_NUM(tcp->ST_TX_DATA);
    CGI_SEND_NUM(tcp->ST_TX_DATA_DUP);
    CGI_SEND_NUM(tcp->ST_TX_ACK);
    CGI_SEND_NUM(tcp->ST_TX_ACK_DELAYED);
    CGI_SEND_NUM(tcp->ST_TX_RESET);
    CGI_SEND_NUM(tcp->ST_TX_PROBE);
    CGI_SEND_NUM(tcp->ST_TX_WINDOW);
    
    CGI_SEND_NUM(tcp->ST_CONN_ACTIVE);
    CGI_SEND_NUM(tcp->ST_CONN_PASSIVE);
    CGI_SEND_NUM(tcp->ST_CONN_OPEN);
    CGI_SEND_NUM(tcp->ST_CONN_CLOSED);
    CGI_SEND_NUM(tcp->ST_CONN_RESET);
    CGI_SEND_NUM(tcp->ST_CONN_FAILED);
//    }
//#else
//    int i;
    
//    for (i = 0; i < 23; i++) {
//        httpd_sendstr(session->sock, "unk\n");
//    }
//#endif
    
    return session->request.content_len;
}

int cgi_toggle_led1(HTTPD_SESSION_STRUCT *session) {

#ifdef HTTP_PRINTM
printfp("cgi_toggle_led1");
#endif
 /*
#if BSPCFG_ENABLE_GPIODEV
    static const uint_32 led[] = {
        LED_1,
        GPIO_LIST_END
    };

    if (output_port == NULL)
        return session->request.content_len;
    led_status ^= 0x01;

    ioctl(output_port, (led_status & 0x01) ? GPIO_IOCTL_WRITE_LOG1 : GPIO_IOCTL_WRITE_LOG0, (pointer) &led);

#endif    

*/  
    return session->request.content_len;
}

int cgi_toggle_led2(HTTPD_SESSION_STRUCT *session) {
 /*
#if BSPCFG_ENABLE_GPIODEV
    static const uint_32 led[] = {
        LED_2,
        GPIO_LIST_END
    };

    if (output_port == NULL)
        return session->request.content_len;
    led_status ^= 0x02;

    ioctl(output_port, (led_status & 0x02) ? GPIO_IOCTL_WRITE_LOG1 : GPIO_IOCTL_WRITE_LOG0, (pointer) &led);
#endif  
*/        
    return session->request.content_len;
}

int cgi_toggle_led3(HTTPD_SESSION_STRUCT *session) {
/*
#if BSPCFG_ENABLE_GPIODEV
    static const uint_32 led[] = {
        LED_3,
        GPIO_LIST_END
    };

    if (output_port == NULL)
        return session->request.content_len;
    led_status ^= 0x04;

    ioctl(output_port, (led_status & 0x04) ? GPIO_IOCTL_WRITE_LOG1 : GPIO_IOCTL_WRITE_LOG0, (pointer) &led);
#endif    
*/      
    return session->request.content_len;
}

int cgi_toggle_led4(HTTPD_SESSION_STRUCT *session) {
   /*
#if BSPCFG_ENABLE_GPIODEV
    static const uint_32 led[] = {
        LED_4,
        GPIO_LIST_END
    };

    if (output_port == NULL)
        return session->request.content_len;
    led_status ^= 0x08;

    ioctl(output_port, (led_status & 0x08) ? GPIO_IOCTL_WRITE_LOG1 : GPIO_IOCTL_WRITE_LOG0, (pointer) &led);
#endif    
*/      
    return session->request.content_len;
}
