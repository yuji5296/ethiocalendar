/** \file date2.cxx
 * \brief Class for having multiple date class
 * 
 * \author Yuji DOI<yuji5296@gmail.com>
 * \date 2008-2009
 */
#include "date2.h"
#include <stdio.h>
#include <string.h>
DATE2::DATE2(){
}
DATE2::DATE2(short y, char m, char d, CALENDAR calendar){
	if (calendar==GREGORIAN) {
		gr = DATE1(y,m,d,calendar);
		serial = gr.calc_serial();
	}else if (calendar==ETHIOPIAN){
		et = DATE1(y,m,d,calendar);
		serial = et.calc_serial();
	}else if (calendar==ISLAMIC){
		is = DATE1(y,m,d,calendar);
		serial = is.calc_serial();
	}
	calc_date2();
}
/*DATE2::DATE2(long serial){
	gr.calc_date(serial,GREGORIAN);
	et.calc_date(serial,ETHIOPIAN);
}*/
char* DATE2::print_date(){
	static char str[256];
	strcpy(str,gr.print_date());
	strcat(str,"\n");
	strcat(str,et.print_date());
	strcat(str,"\n");
	strcat(str,is.print_date());
	return str;
}
char* DATE2::print_date(CALENDAR calendar){
	static char str[256];
	switch (calendar){
	case GREGORIAN:
		strcpy(str,gr.print_date());
		break;
	case ETHIOPIAN:
		strcpy(str,et.print_date());
		break;
	case ISLAMIC:
		strcpy(str,is.print_date());
		break;
	}
	return str;
}
char* DATE2::print_short(){
	static char str[256];
	strcpy(str,gr.print_short());
	strcat(str,": ");
	strcat(str,et.print_short());
	strcat(str,": ");
	strcat(str,is.print_short());
	return str;
}
char* DATE2::print_short(CALENDAR calendar){
	static char str[256];
	switch (calendar){
	case GREGORIAN:
		strcpy(str,gr.print_short());
		break;
	case ETHIOPIAN:
		strcpy(str,et.print_short());
		break;
	case ISLAMIC:
		strcpy(str,is.print_short());
		break;
	}
	return str;
}
void DATE2::scan(const char *str,CALENDAR calendar){
	if (calendar==GREGORIAN) {
		gr.scan(str,calendar);
		serial = gr.calc_serial();
	}else if (calendar==ETHIOPIAN){
		et.scan(str,calendar);
		serial = et.calc_serial();
	}else if (calendar==ISLAMIC){
		is.scan(str,calendar);
		serial = is.calc_serial();
	}
	calc_date2();
}
int DATE2::Year(CALENDAR calendar){
	if (calendar==GREGORIAN) return gr.year;
	else if (calendar==ETHIOPIAN) return et.year;
	else if (calendar==ISLAMIC) return is.year;
}
void DATE2::Year(CALENDAR calendar, int year){
	if (calendar==GREGORIAN) {
		gr.year = year;
		serial = gr.calc_serial();
		gr.calc_weekday();
	}else if(calendar==ETHIOPIAN){
		et.year = year;
		serial = et.calc_serial();
		et.calc_weekday();
	}else if(calendar==ETHIOPIAN){
		is.year = year;
		serial = is.calc_serial();
		is.calc_weekday();
	}
	calc_date2();
}
int DATE2::Month(CALENDAR calendar){
	if (calendar==GREGORIAN) return gr.month;
	else if (calendar==ETHIOPIAN) return et.month;
	else if (calendar==ISLAMIC) return is.month;
}
void DATE2::Month(CALENDAR calendar, int month){
	if (calendar==GREGORIAN) {
		gr.month = month;
		serial = gr.calc_serial();
		gr.calc_weekday();
	}else if (calendar==ETHIOPIAN){
		et.month = month;
		serial = et.calc_serial();
		et.calc_weekday();
	}else if (calendar==ISLAMIC){
		is.month = month;
		serial = is.calc_serial();
		is.calc_weekday();
	}
	calc_date2();
}
int DATE2::Day(CALENDAR calendar){
	if (calendar==ISLAMIC) return is.day;
	else if (calendar==ETHIOPIAN) return et.day;
	else return gr.day;
}
int DATE2::Weekday(){
	return gr.weekday;
}
char* DATE2::name_of_month(CALENDAR calendar){
	if (calendar==GREGORIAN) return gr.name_of_month();
	else if (calendar==ETHIOPIAN) return et.name_of_month();
	else if (calendar==ISLAMIC) return is.name_of_month();
}
void DATE2::Today(){
	gr.Today();
	et.calc_date(gr.serial, ETHIOPIAN);
	is.calc_date(gr.serial,ISLAMIC);
}
void DATE2::Tomorrow(){
	gr.Tomorrow();
	et.Tomorrow();
	is.Tomorrow();
}
void DATE2::Yesterday(){
	gr.Yesterday();
	et.Yesterday();
	is.Yesterday();
}
void DATE2::FirstDay(CALENDAR calendar){
	if (calendar == GREGORIAN){
		gr.FirstDay();
		serial = gr.calc_serial();
	}else if (calendar==ETHIOPIAN){
		et.FirstDay();
		serial = et.calc_serial();
	}else if (calendar==ISLAMIC){
		is.FirstDay();
		serial = is.calc_serial();
	}
	calc_date2();
}void DATE2::NextYear(CALENDAR calendar){
	if (calendar == GREGORIAN){
		gr.NextYear();
		serial = gr.calc_serial();
	}else if (calendar==ETHIOPIAN){
		et.NextYear();
		serial = et.calc_serial();
	}else if (calendar==ISLAMIC){
		is.NextYear();
		serial = is.calc_serial();
	}
	calc_date2();
}
void DATE2::NextMonth(CALENDAR calendar){
	if (calendar == GREGORIAN){
		gr.NextMonth();
		serial = gr.calc_serial();
	}else if (calendar==ETHIOPIAN){
		et.NextMonth();
		serial = et.calc_serial();
	}else if (calendar==ISLAMIC){
		is.NextMonth();
		serial = is.calc_serial();
	}
	calc_date2();
}
void DATE2::PrevYear(CALENDAR calendar){
	if (calendar == GREGORIAN){
		gr.PrevYear();
		serial = gr.calc_serial();
	}else if (calendar==ETHIOPIAN){
		et.PrevYear();
		serial = et.calc_serial();
	}else if (calendar==ISLAMIC){
		is.PrevYear();
		serial = is.calc_serial();
	}
	calc_date2();
}
void DATE2::PrevMonth(CALENDAR calendar){
	if (calendar == GREGORIAN){
		gr.PrevMonth();
		serial = gr.calc_serial();
	}else if (calendar==ETHIOPIAN){
		et.PrevMonth();
		serial = et.calc_serial();
	}else if (calendar==ISLAMIC){
		is.PrevMonth();
		serial = is.calc_serial();
	}
	calc_date2();
}
int DATE2::DiffDate(DATE2 d1, DATE2 d2){
	return d1.gr.DiffDate(d1.gr,d2.gr);
}
bool DATE2::CompDate(DATE2 date){
	if (gr.CompDate(date.gr) && et.CompDate(date.et)) return true;
	else return false;
}
bool DATE2::IsHoliday(){
	if (gr.IsHoliday()){
		strcpy(holiday,gr.holiday);
		return true;
	}else if (et.IsHoliday()) {
		strcpy(holiday,et.holiday);
		return true;
	}else if (is.IsHoliday()) {
		strcpy(holiday,is.holiday);
		return true;
	}else {
		strcpy(holiday,"");
		return false;
	}
}
void DATE2::calc_date2(){
	gr.calc_date(serial,GREGORIAN);
	et.calc_date(serial,ETHIOPIAN);
	is.calc_date(serial,ISLAMIC);
}
#if 0
void DATE2::disp_date2(){
	print_date2();
}
void DATE2::disp_calendar2(){
	gr.disp_calendar();
	et.disp_calendar();
}
int DATE2::calc_serial2(){
	if (gr.year != 0) return gr.serial;
	else return et.serial;
}
int DATE2::scan_date2(){
	DATE1 d;
	int x;
	d.scan_date();
	x = d.serial;
	if (d.type == GREGORIAN) {
		gr = d;
		et.calc_date(x, ETHIOPIAN);
	} else {
		et = d;
		gr.calc_date(x, GREGORIAN);
	}
	return 1;
}
int DATE2::number_of_days(CALENDAR calendar){
	if (calendar==GREGORIAN) return gr.number_of_days();
	else return et.number_of_days();
}
#endif

