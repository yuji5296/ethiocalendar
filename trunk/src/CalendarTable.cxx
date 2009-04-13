/** \file CalendarTable.cxx
 * \brief Class for display calendar matrix.
 * 
 * \author Yuji DOI<yuji5296@gmail.com>
 * \date 2008-2009
 */
#include "CalendarTable.h"
#include <FL/fl_ask.H>
#include <stdio.h>
#include "yaecob.h"
CalendarTable::CalendarTable(int x, int y, int w, int h)
		: Fl_Group(x,y,w,h)
{
	h=h-16;
	int width=w/7;
	int hight=h/6;
	for(int j=0;j<7;j++){
		weekdaylabel[j] = new Fl_Box(x+width*j, y, width-2, 16, "");
		weekdaylabel[j]->labelfont(FL_TIMES);
	}
	weekdaylabel[0]->labelcolor(FL_RED);
	y+=16;
	for(int i=0;i<6;i++){
		for(int j=0;j<7;j++){
			int k = 7*i+j;
			d[k] = new CalendarCell(x+width*j,y+hight*i,width,hight);
			d[k]->callback((Fl_Callback*)cb_cell_click,d[k]);
			if (k % 7 == 0) {
				d[k]->textcolor(FL_RED);
			}
		}
	}
	end();
}
void CalendarTable::draw(DATE2 Current,CALENDAR type, CALENDAR sub) {
	int i,x;
	char str[16],str2[16],str3[16];
	DATE2 work; //for display calendar
	if (type==ETHIOPIAN){
		weekdaylabel[0]->label(EC_WEEKDAY0);
		weekdaylabel[1]->label(EC_WEEKDAY1);
		weekdaylabel[2]->label(EC_WEEKDAY2);
		weekdaylabel[3]->label(EC_WEEKDAY3);
		weekdaylabel[4]->label(EC_WEEKDAY4);
		weekdaylabel[5]->label(EC_WEEKDAY5);
		weekdaylabel[6]->label(EC_WEEKDAY6);
	}else if (type==ISLAMIC){
	   	weekdaylabel[0]->label(IC_WEEKDAY0_LABEL);
		weekdaylabel[1]->label(IC_WEEKDAY1_LABEL);
		weekdaylabel[2]->label(IC_WEEKDAY2_LABEL);
		weekdaylabel[3]->label(IC_WEEKDAY3_LABEL);
		weekdaylabel[4]->label(IC_WEEKDAY4_LABEL);
		weekdaylabel[5]->label(IC_WEEKDAY5_LABEL);
		weekdaylabel[6]->label(IC_WEEKDAY6_LABEL);
	   }else{
	   	weekdaylabel[0]->label(GC_WEEKDAY0_LABEL);
		weekdaylabel[1]->label(GC_WEEKDAY1_LABEL);
		weekdaylabel[2]->label(GC_WEEKDAY2_LABEL);
		weekdaylabel[3]->label(GC_WEEKDAY3_LABEL);
		weekdaylabel[4]->label(GC_WEEKDAY4_LABEL);
		weekdaylabel[5]->label(GC_WEEKDAY5_LABEL);
		weekdaylabel[6]->label(GC_WEEKDAY6_LABEL);
	   }
	work = Current;
	work.FirstDay(type);
	str[0] = '\0';
	str2[0] = '\0';
	str3[0] = '\0';
	   for(i=0;i<work.Weekday();i++){
		d[i]->value("");
		d[i]->color(FL_BACKGROUND_COLOR);
		d[i]->hide();
		d[i]->redraw();
	}
	for(i=work.Weekday();Current.Month(type)==work.Month(type);i++){
		d[i]->show();
		sprintf(str,"%2d",work.Day(type));
		sprintf(str2,"%2d",work.Day(sub));
//	  	  sprintf(str3,"%2d",work.Day(ISLAMIC));
//  	   d[i]->value(str);
		d[i]->value(str,str2);
//	  	  d[i]->value(str,str2,str3);
	   	   // change background to yellow on current date
		if (work.CompDate(Current)==true)
			d[i]->color(FL_YELLOW);
		else
			d[i]->color(FL_WHITE);
		// if it holiday, change text color to red
		if (work.IsHoliday()) {
			d[i]->textcolor(FL_RED);
			d[i]->textfont(FL_HELVETICA_BOLD);
		}else  {
			d[i]->textcolor(FL_BLACK);
			d[i]->textfont(FL_HELVETICA);
		}
		// Sunday is holiday
		if (i % 7 == 0) d[i]->textcolor(FL_RED);
		d[i]->redraw();
		work.Tomorrow();
	}
	str[0] = '\0';
	for(;i<42;i++){
		d[i]->value("");
		d[i]->color(FL_BACKGROUND_COLOR);
		d[i]->hide();
		d[i]->redraw();
	}
}
void CalendarTable::callback(Fl_Callback *func)
{
	callback_ = func;
	for(int k=0;k<42;k++)
		d[k]->callback((Fl_Callback*)cb_cell_click,d[k]);
}
void CalendarTable::cb_cell_click_i(CalendarCell* o, void* v) {
	//fl_alert("CalendarTable::cb_cell_click_i");
	//	   cb_func(o->parent(),v);
	//fl_alert(((CalendarCell*)(o->parent()))->upper->value());
	//fl_alert(((CalendarCell*)v)->upper->value());
	//fl_alert("hello");
	callback_((CalendarTable*)(o->parent()),v);
}
void CalendarTable::cb_cell_click(CalendarCell* o, void* v) {
	//fl_alert("CalendarTable::cb_cell_click");
	((CalendarTable*)(o->parent()))->cb_cell_click_i(o,v);
}

