//------------------------------------------------------------------------------
// Name: webside.c
// Func: example HTML-code for easyweb.c
// Ver.: 1.1
// Date: January 2004
// Auth: Andreas Dannenberg
//       MSP430 Applications
//       Texas Instruments Inc.
// Rem.: -
//------------------------------------------------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("MenuFile") 
#else
#pragma DATA_SECTION(WebSide,"MenuFile");
#endif
const unsigned char WebSide[] =
{
  "<html>\r\n"
  "<head>\r\n"
  "<meta http-equiv=\"refresh\" content=\"20\">\r\n"
  "<title>Expert-3</title>\r\n"
  "</head>\r\n"
  "\r\n"
  "<body bgcolor=\"#3030A0\" text=\"#FFFF00\">\r\n"
  "<p><b><font color=\"#FFFFFF\" size=\"6\"><i>BER tester Expert-3 v05.12.21 </i></font></b></p>\r\n"
  "\r\n"
  "<p><b>LONIIR 2005</b> <b>NIO-4</b></p>\r\n"
  "<p><b>Testing results:</b></p>\r\n"
  "<ul>\r\n"
  "<li><b>BER:....01234589ABC</b></li>\r\n"
  "<li><b>Losts:......012345678</b></li>\r\n"
  "<li><b>Errors:.....012345678</b></li>\r\n"
  "<li><b>Bits:........01234567</b></li>\r\n"
  "<li><b>Data Rate:...01234567 Bps</b></li>\r\n"
  "</ul>\r\n"
    "<hr><p><form action=\"/SET/DRate/\" method=\"POST\">"
	"<table border=\"0\">"
	"<tr><td>Data Rate</td><td>&nbsp;"
	"<input type= \"text\" name=\"DRate\" size=\"10\" maxlength=\"10\" value= \" \"></td></tr>"
	"<tr><td colspan=\"2\">"
	"<input type=\"submit\" value=\"Set\">"
	"</td>"
	"</tr></table></form></p>"
	"</hr>"
  "</body>\r\n"
  "</html>\r\n"
 };
