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
//const need linc to code section - flash! 
//#ifdef __cplusplus 
//#pragma DATA_SECTION("MenuFileD") 
//#else
//#pragma DATA_SECTION(WebSide,"MenuFileD");
//#endif
const unsigned char WebSide[] =
{
"\r\n"
  "<html>"
  "\r\n"
  "<head>"
  "\r\n"
  "<meta http-equiv=\"refresh\" content=\" 4\">"
  "<title>Expert-3</title>"
  "</head>"
  "<html>"
//  "<body bgcolor=\"#3F3FFF\" text=\"#FFFF00\">\r\n"
  "<body bgcolor=\"#3F00FF\" text=\"#FFFF00\">\r\n"
  "<center>"
  "<p><b><font size=\"4\"><i>BER tester Expert-3 v06.01.18 </i></font></b></p>\r\n"
  "\r\n"
  "<p><b><font  size=\"1\" color=green>LONIIR 2006</b> <b>NIO-4</b></p>\r\n"
  "</center>"
  "<hr>"
  "<p><b><font  size=\"4\" color=yellow>Testing results:</b></p>\r\n"
  "<ul>\r\n"
  "<font  size=\"4\">"
  "<li><b>BER:....01234589ABC</b></li>\r\n"
  "<li><b>Losts:......01234567</b></li>\r\n"
  "<li><b>Errors:.....01234567</b></li>\r\n"
  "<li><b>Bits:........0123456</b></li>\r\n"
//  "<li><b>Data Rate:...01234567 Bps</b></li>\r\n"
	"</font>"
  "</ul>\r\n"
  // "</center>"
    "<hr><p>"
    "<p><b>Operate:</b></p>\r\n"
    "<form action=\"/operate\" method=\"POST\">"
	"<table border=\"1\" align = \"\center\">"
	"<tr><td>Page Refresh Rate</td><td>&nbsp;"
	"<input type= \"text\" name=\"000\" size=\"3\" maxlength=\"3\" value= \" 4\"></td>"
	"<td>\ sec.\ </td>"
	"<tr><td>Data Rate</td><td>&nbsp;"
	"<input type= \"text\"  size=\"8\" maxlength=\"8\"  name=\"001\" value=\"10000000\"></td>"
	"<td>\ Bps\ </td>"
	"<tr><td>Clear</td><td colspan=\"2\" align=\"center\"><input type= checkbox name = \"002\"></td></tr>"
	"<tr><td colspan=\"3\" align=\"center\"><input type=\"submit\" value=\"\ \ Set\ \ \">"
	"</td>"
	"</tr></table>"
	"</form>"
	"</p><hr>"
  "</body>\r\n"
  "</html>\r\n"
 };
