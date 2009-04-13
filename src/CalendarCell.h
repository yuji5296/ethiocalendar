/** \file CalendarCell.h
 * \brief Class for display cell.
 * \details Each cell has two day.
 * \author Yuji DOI<yuji5296@gmail.com>
 * \date 2008-2009
 */
#ifndef CalendarCell_h
#define CalendarCell_h
#include <FL/Fl_Group.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Output.H>
/*! \class CalendarCell CalendarCell.h "CalendarCell.h"
 *  \brief Class for display cell.
 *
 * This class has two text boxes and clickable.
 */
class CalendarCell : public Fl_Group{
	Fl_Callback* callback_;
	void cb_cell_click_i(Fl_Button* o, void *v) ;
	static void cb_cell_click(Fl_Button* o, void *v) ;
	Fl_Output *lower;
	Fl_Output *leftlower;
	Fl_Button *cover;
	void resize(int x, int y, int w, int h);
public:
	CalendarCell(int x, int y, int w, int h);
	Fl_Output *upper;
	int value(const char *a);
	int value(const char *a, const char *b);
	int value(const char *a, const char *b, const char *c);
	void textcolor(Fl_Color );
	void textfont(int );
	void callback(Fl_Callback *func,void*v);
//	  void cb_cover_i(Fl_Button* o, void*);
//	    static void cb_cover(Fl_Button* o, void* v);
};
#endif

