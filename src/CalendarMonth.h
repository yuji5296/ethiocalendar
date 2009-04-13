/** \file CalendarMonth.h
 * \brief Class for select month.
 * 
 * \author Yuji DOI<yuji5296@gmail.com>
 * \date 2008-2009
 */
#ifndef CalendarMonth_h
#define CalendarMonth_h
#include <Fl/Fl_Choice.h>
#include "date.h"
#include <FL/Fl_Menu_Item.H>
static Fl_Menu_Item menu_month_gr[] = {
 {GC_MONTH01, 0,  0, (void*)1, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {GC_MONTH02, 0,  0, (void*)2, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {GC_MONTH03, 0,  0, (void*)3, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {GC_MONTH04, 0,  0, (void*)4, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {GC_MONTH05, 0,  0, (void*)5, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {GC_MONTH06, 0,  0, (void*)6, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {GC_MONTH07, 0,  0, (void*)7, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {GC_MONTH08, 0,  0, (void*)8, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {GC_MONTH09, 0,  0, (void*)9, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {GC_MONTH10, 0,  0, (void*)10, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {GC_MONTH11, 0,  0, (void*)11, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {GC_MONTH12, 0,  0, (void*)12, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {0,0,0,0,0,0,0,0,0}
};
static Fl_Menu_Item menu_month_et[] = {
 {EC_MONTH01, 0,  0, (void*)1, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {EC_MONTH02, 0,  0, (void*)2, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {EC_MONTH03, 0,  0, (void*)3, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {EC_MONTH04, 0,  0, (void*)4, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {EC_MONTH05, 0,  0, (void*)5, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {EC_MONTH06, 0,  0, (void*)6, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {EC_MONTH07, 0,  0, (void*)7, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {EC_MONTH08, 0,  0, (void*)8, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {EC_MONTH09, 0,  0, (void*)9, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {EC_MONTH10, 0,  0, (void*)10, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {EC_MONTH11, 0,  0, (void*)11, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {EC_MONTH12, 0,  0, (void*)12, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {EC_MONTH13, 0,  0, (void*)13, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {0,0,0,0,0,0,0,0,0}
};
static Fl_Menu_Item menu_month_is[] = {
 {IC_MONTH01, 0,  0, (void*)1, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {IC_MONTH02, 0,  0, (void*)2, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {IC_MONTH03, 0,  0, (void*)3, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {IC_MONTH04, 0,  0, (void*)4, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {IC_MONTH05, 0,  0, (void*)5, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {IC_MONTH06, 0,  0, (void*)6, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {IC_MONTH07, 0,  0, (void*)7, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {IC_MONTH08, 0,  0, (void*)8, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {IC_MONTH09, 0,  0, (void*)9, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {IC_MONTH10, 0,  0, (void*)10, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {IC_MONTH11, 0,  0, (void*)11, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {IC_MONTH12, 0,  0, (void*)12, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {0,0,0,0,0,0,0,0,0}
};
/*! \class CalendarMonth CalendarMonth.h "CalendarMonth.h"
 *  \brief Class for select month.
 *
 * 
 */
class CalendarMonth : public Fl_Choice {
	CALENDAR t;
public:
	CalendarMonth(int x, int y, int w, int h);
	void redraw();
    void type(CALENDAR);
};
#endif

