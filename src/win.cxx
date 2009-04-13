/** \file win.cxx
 * \brief Code for Windows
 * 
 * \author Yuji DOI<yuji5296@gmail.com>
 * \date 2008-2009
 */
#include <FL/fl_ask.H>
#include "os.h"
#include <windows.h>
#include <shellapi.h>
void show_browser(const char *URL){
	ShellExecute(0, "open", URL,"","", 0);
}
/*
void show_website(){
	show_browser("http://yuji5296.web.fc2.com/project/calendar/");
}
void show_help(){
	show_browser("help.htm");
}
*/

#include "handy.h"
char *get_icon(){
	 //Set icon for window (MacOS uses app bundle for icon...)
	   return (char *)LoadIcon(fl_display, MAKEINTRESOURCE(HANDY1));
}

