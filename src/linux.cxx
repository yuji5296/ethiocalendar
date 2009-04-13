/** \file linux.cxx
 * \brief Code for Linux
 * 
 * \author Yuji DOI<yuji5296@gmail.com>
 * \date 2008-2009
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "os.h"
#include <FL/fl_ask.H>

void show_browser(const char *URL){
	char str[256];
	int i,rtn;
	sprintf(str,"./openbrowser.sh %s",URL);
	rtn = system(str);
	if(rtn!=0){
		sprintf(str,"%s %s &",fl_input("Input your browser"),URL);
		system(str);
	}
}
/*
void show_website(){
	show_browser("http://yuji5296.web.fc2.com/project/calendar/");
}
void show_help(){
	show_browser("help.htm");
}
*/

#include <X11/xpm.h>
#include "handy5.xpm"

char *get_icon(){
	 //Set icon for window (MacOS uses app bundle for icon...)
	Pixmap p, mask;
//	  unsigned int w,h;
//	  int x,y;
	fl_open_display();	// needed if display has not been previously opened
//	p = XCreateBitmapFromData(fl_display, DefaultRootWindow(fl_display),(char *)handy3_bits, handy3_width, handy3_height));
	XpmCreatePixmapFromData(fl_display, DefaultRootWindow(fl_display), (char**)handy5_xpm, &p, &mask, NULL);

//	XReadBitmapFile(fl_display,DefaultRootWindow(fl_display),"handy5.xpm",&w,&h,&p,&x,&y);
//	printf("p=%s\n",p);
//	XpmReadFileToPixmap (fl_display,DefaultRootWindow(fl_display),"handy5.bmp",&p, &mask, NULL);
	return (char *)p;
}

