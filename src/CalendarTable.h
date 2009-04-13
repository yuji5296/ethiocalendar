/** \file CalendarTable.h
 * \brief Class for display calendar matrix.
 * 
 * \author Yuji DOI<yuji5296@gmail.com>
 * \date 2008-2009
 */
#ifndef CalendarTable_h
#define CalendarTable_h
#include "CalendarCell.h"
#include <FL/Fl_Group.H>
#include <Fl/Fl_Box.h>
#include "date2.h"
/*! \class CalendarTable CalendarTable.h "CalendarTable.h"
 *  \brief Class for display calendar matrix.
 *
 * This class has some CalendarCell class.
 */
class CalendarTable : public Fl_Group {
	CalendarCell *d[42]; 
	Fl_Box *weekdaylabel[7];
	Fl_Callback* callback_;
	void cb_cell_click_i(CalendarCell* o, void* v) ;
	static void cb_cell_click(CalendarCell* o, void* v) ;
public:
	CalendarTable(int x, int y, int w, int h);
	void draw(DATE2 Current,CALENDAR type, CALENDAR sub);
	void callback(Fl_Callback *func);
};
#endif

