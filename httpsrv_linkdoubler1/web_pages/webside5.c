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
"<html>"
"<head>"
"<meta http-equiv=\"Content-Type\" content=\"text/html; charset=windows-1251\">"
"<meta http-equiv=\"Content-Language\" content=\"ru\">"
"<meta name=\"GENERATOR\" content=\"Microsoft FrontPage 5.0\">"
"<meta name=\"ProgId\" content=\"FrontPage.Editor.Document\">"
"<title>Index Server Search Page</title></head>"
"<html>"
"<body bgcolor=#FFFFFF>"
"<h1 align=\"center\">Index Server Search Page</h1>"
//"<hr><p><form action=\"/search/search.idq\" method=\"POST\">"
"<table border=\"0\">"
"<tr><td>Search for</td><td>&nbsp;"
"<input type=\"text\" name=\"CiRestriction\" size=\"60\" maxlength=\"100\" value=\" \"></td></tr>"
"<tr><td colspan=\"2\">"
"<input type=\"submit\" value=\"Search\">"
"<input type=\"reset\" value=\"Clear\"></td>"
//"</tr></table></form></p>"
"<hr>"
"<p><FONT size=6><STRONG>?????????</STRONG></FONT></p>"
"<p><B>????????????? ????????? ???????:</B></p>"
"<ul>"
"</ul>"
"</body></html>"
 };
