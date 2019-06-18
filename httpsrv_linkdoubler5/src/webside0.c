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
  "<meta http-equiv=\"refresh\" content=\"5\">\r\n"
  "<title>Expert-3</title>\r\n"
  "</head>\r\n"
  "\r\n"
  "<body bgcolor=\"#3030A0\" text=\"#FFFF00\">\r\n"
  "<p><b><font color=\"#FFFFFF\" size=\"6\"><i>Data channels tester Expert-3 v05.12.15 </i></font></b></p>\r\n"
  "\r\n"
  "<p><b>LONIIR 2005</b> <b>NIO-4</b></p>\r\n"
  "<p><b>Testing results:</b></p>\r\n"
  "<ul>\r\n"
  "<li><b>BER     :AD1%</b></li>\r\n"
  "<li><b>Losts     :AD2%</b></li>\r\n"
  "<li><b>Errors    :AD3%</b></li>\r\n"
  "<li><b>Bits      :AD4%</b></li>\r\n"
  "<li><b>Data Rate :AD5%</b></li>\r\n"
  "</ul>\r\n"
  "\r\n"
  "<!"
  "<p><b>BER:</b></p>\r\n"
  "\r\n"
  "<table bgcolor=\"#ff0000\" border=\"5\" cellpadding=\"0\" cellspacing=\"0\" width=\"500\">\r\n"
  "<tr>\r\n"
  "<td>\r\n"
  "<table width=\"AD7%\" border=\"0\" cellpadding=\"0\" cellspacing=\"0\">\r\n"
  "<tr><td bgcolor=\"#0000ff\">&nbsp;</td></tr>\r\n"
  "</table>\r\n"
  "</td>\r\n"
  "</tr>\r\n"
  "</table>\r\n"
  "\r\n"
  "<table border=\"0\" width=\"500\">\r\n"
  "<tr>\r\n"
  "<td width=\"20%\">E-4</td>\r\n"
  "<td width=\"20%\">E-6</td>\r\n"
  "<td width=\"20%\">E-8</td>\r\n"
  "<td width=\"20%\">E-10</td>\r\n"
  "<td width=\"20%\">E-12</td>\r\n"
  "</tr>\r\n"
  "</table>\r\n"
  "\r\n"
  "<p><b>Bits:</b></p>\r\n"
  "\r\n"
  "<table bgcolor=\"#00ff00\" border=\"5\" cellpadding=\"0\" cellspacing=\"0\" width=\"500\">\r\n"
  "<tr>\r\n"
  "<td>\r\n"
  "<table width=\"ADA%\" border=\"0\" cellpadding=\"0\" cellspacing=\"0\">\r\n"
  "<tr><td bgcolor=\"#00ff00\">&nbsp;</td></tr> \r\n"
  "</table>\r\n"
  "</td>\r\n"
  "</tr>\r\n"
  "</table>\r\n"
  "\r\n"
  "<table border=\"0\" width=\"500\">\r\n"
  "<tr>\r\n"
  "<td width=\"20%\">E+4</td>\r\n"
  "<td width=\"20%\">E+6</td>\r\n"
  "<td width=\"20%\">E+8</td>\r\n"
  "<td width=\"20%\">E+12</td>\r\n"
  "<td width=\"20%\">E+14</td>\r\n"
  "</tr>\r\n"
  "</table>\r\n"
  ">"
  "</body>\r\n"
  "</html>\r\n"
  "\r\n"
};
