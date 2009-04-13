/** \file Fl_Clock_Ethiopia.cxx
 * \brief Class for Ethiopian clock
 * 
 * \author Yuji DOI<yuji5296@gmail.com>
 * \date 2008-2009
 */
#include <FL/Fl.H>
#include "Fl_Clock_Ethiopia.h"
#include <FL/fl_draw.H>
//#include <math.h>
#include <time.h>
#include <stdio.h>
#ifndef WIN32
#  include <sys/time.h>
#endif /* !WIN32 */

Fl_Clock_Ethiopia::Fl_Clock_Ethiopia(int X, int Y, int W, int H, const char *l)
  : Fl_Clock_Output(X, Y, W, H, l) {}

/*
Fl_Clock_Ethiopia::Fl_Clock_Ethiopia(uchar t, int X, int Y, int W, int H, const char *l)
  : Fl_Clock_Output(X, Y, W, H, l) {
  type(t);
  box(t==FL_ROUND_CLOCK ? FL_NO_BOX : FL_UP_BOX);
}
*/

static void tick(void *v) {
	((Fl_Clock_Ethiopia*)v)->value(time(0));
	if (((Fl_Clock_Ethiopia*)v)->mode==TIMEMODE_ETHIOPIA) {
		((Fl_Clock_Ethiopia*)v)->value((((Fl_Clock_Ethiopia*)v)->hour()+6)%12,((Fl_Clock_Ethiopia*)v)->minute(),((Fl_Clock_Ethiopia*)v)->second());
		((Fl_Clock_Ethiopia*)v)->type(FL_SQUARE_CLOCK);
	}else{
		((Fl_Clock_Ethiopia*)v)->type(FL_ROUND_CLOCK);
	}  
	Fl::add_timeout(1.0, tick, v);
}

int Fl_Clock_Ethiopia::handle(int event) {
  switch (event) {
  case FL_SHOW:
    tick(this);
    break;
  case FL_HIDE:
    Fl::remove_timeout(tick, this);
    break;
  }
  return Fl_Clock_Output::handle(event);
}
  
Fl_Clock_Ethiopia::~Fl_Clock_Ethiopia() {
  Fl::remove_timeout(tick, this);
}

char *Fl_Clock_Ethiopia::str() {
	static char str[16];
	sprintf(str,"%02d:%02d:%02d",hour(),minute(),second());
	return str;
}

//
// End of "$Id: Fl_Clock.cxx 5472 2006-09-20 03:03:14Z mike $".
//

