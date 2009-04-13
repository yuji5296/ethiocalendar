/** \file CalendarCell.cxx
 * \brief Class for display cell
 * \details Each cell has two day.
 * \author Yuji DOI<yuji5296@gmail.com>
 * \date 2008-2009
 */
#include "CalendarCell.h"
#include <FL/fl_ask.H>
#include <string.h>
#define MIN(a,b)	a < b ? a : b
#define MAX(a,b)	a > b ? a : b
CalendarCell::CalendarCell(int x, int y, int w, int h)
		: Fl_Group(x,y,w,h)
{
	box(FL_BORDER_BOX);
	upper = new Fl_Output(x,y,w,h);
	upper->box(FL_NO_BOX);
	upper->textfont(FL_TIMES);
	lower = new Fl_Output(x,y,w,h);
	lower->box(FL_NO_BOX);
	lower->textfont(FL_TIMES);
	leftlower = new Fl_Output(x,y,0,0);
//	  leftlower->box(FL_NO_BOX);
//	  leftlower->textfont(FL_TIMES);
	   cover = new Fl_Button(x,y,w,h);
	cover->box(FL_NO_BOX);
	cover->down_box(FL_NO_BOX);
	//	  cover->callback((Fl_Callback*)cb_cover);
	end();
	resize(x,y,w,h);
};
void CalendarCell::cb_cell_click_i(Fl_Button* o, void *v) {
	//fl_alert("CalendarCell::cb_cell_click_i");
	//fl_alert(((CalendarCell*)(o->parent()))->upper->value());
	//fl_alert(((CalendarCell*)(*v))->upper->value());
	//fl_alert(upper->value());
	if(strcmp(((CalendarCell*)(o->parent()))->upper->value(),""))
		callback_((CalendarCell*)(o->parent()),v);
}
void CalendarCell::cb_cell_click(Fl_Button* o, void *v) {
	//fl_alert("CalendarCell::cb_cell_click");
	((CalendarCell*)(o->parent()))->cb_cell_click_i(o,v);
}
void CalendarCell::callback(Fl_Callback *func,void*v)
{
	callback_ = func;
	cover->callback((Fl_Callback*)cb_cell_click,v);
}
void CalendarCell::resize(int x, int y, int w, int h)
{
	Fl_Group::resize(x,y,w,h);
	int border = 1;
	int w_upper = w * 3 / 5;
	int h_upper = h * 3 / 5;
	int t_upper = (int)(MIN(w_upper,h_upper));
	int w_lower = w - w_upper;
	int h_lower = h - h_upper;
	int t_lower = (int)(MIN(w_lower,h_lower));
	int x_lower = x + w_upper;
	int y_lower = y + h_upper;
	w_lower = MAX(w_lower,t_lower);
	h_lower = MAX(h_lower,t_lower);
	upper->resize(x,y,w,h_upper);
	upper->textsize(t_upper);
	lower->resize(x_lower,y_lower,w_lower,h_lower);
	lower->textsize(t_lower);
//	  leftlower->resize(x,y_lower,w_lower,h_lower);
//	  leftlower->textsize(t_lower);
	   //	   cover->resize(x,y,w,h);
	//	  textsize(h_upper);
}
int CalendarCell::value(const char *a)
{
	//	  Fl_Output::value(a);
	upper->value(a);
	lower->value("");
	leftlower->value("");
}
int CalendarCell::value(const char *a, const char *b)
{
	//	  Fl_Output::value(a);
	upper->value(a);
	lower->value(b);
	leftlower->value("");
}
int CalendarCell::value(const char *a, const char *b, const char *c)
{
	//	  Fl_Output::value(a);
	upper->value(a);
	lower->value(b);
	leftlower->value(c);
}
/*
void CalendarCell::redraw()
{
	upper->textsize(upper->h());
	upper->redraw();
	lower->textsize(lower->h());
	lower->redraw();
}
void CalendarCell::color(Fl_Color color)
{
//	  upper->color(color);
//	  lower->color(color);
}
uchar CalendarCell::type(int )
{
}
void CalendarCell::labeltype(Fl_Labeltype)
{
}
void CalendarCell::align(Fl_Align)
{
}
void CalendarCell::labelcolor(Fl_Color)
{
}
*/
void CalendarCell::textcolor(Fl_Color color)
{
	//	  Fl_Output::textcolor(color);
	upper->textcolor(color);
	lower->textcolor(color);
	leftlower->textcolor(color);
}
void CalendarCell::textfont(int font)
{
	upper->textfont(font);
	lower->textfont(font);
	leftlower->textfont(font);
}

