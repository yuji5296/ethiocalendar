/** \file CalendarMonth.cxx
 * \brief Class for select month.
 * 
 * \author Yuji DOI<yuji5296@gmail.com>
 * \date 2008-2009
 */
#include "CalendarMonth.h"

CalendarMonth::CalendarMonth(int x, int y, int w, int h)
: Fl_Choice( x,  y,  w,  h)
{
	if (t==GREGORIAN) {
	      menu(menu_month_gr);
	}else if (t==ETHIOPIAN){
	      menu(menu_month_et);
	}else if (t==ISLAMIC){
		menu(menu_month_is);
	}
}
void CalendarMonth::redraw(){
	if (t==GREGORIAN) {
	      menu(menu_month_gr);
	}else if (t==ETHIOPIAN){
	      menu(menu_month_et);
	}else if (t==ISLAMIC){
		menu(menu_month_is);
	}
	   Fl_Choice::redraw();   
}
void CalendarMonth::type(CALENDAR type){
	t = type;
	if (t==GREGORIAN) {
	      menu(menu_month_gr);
	}else if (t==ETHIOPIAN){
	      menu(menu_month_et);
	}else if (t==ISLAMIC){
		menu(menu_month_is);
	}
	   Fl_Choice::redraw();   
}

