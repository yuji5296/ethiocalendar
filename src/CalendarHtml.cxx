/** \file CalendarHtml.cxx
 * \brief Class for print calendar
 * \details This class output calendar as HTML file for print out.
 * \author Yuji DOI<yuji5296@gmail.com>
 * \date 2008-2009
 */
#include "CalendarHtml.h"
#include "EthioCalendar.h"
#include <stdio.h>
#include <string.h>
#define FL_YELLOW "yellow"
#define FL_WHITE "white"
#define FL_BACKGROUND_COLOR "white"
#define append(str) append(str);append("\n")
char *name_of_weekday(CALENDAR t, int m, LANGUAGE l){
	static char gc_weekday[][16]={GC_WEEKDAY0_LABEL,GC_WEEKDAY1_LABEL,GC_WEEKDAY2_LABEL,GC_WEEKDAY3_LABEL,GC_WEEKDAY4_LABEL,GC_WEEKDAY5_LABEL,GC_WEEKDAY6_LABEL};
	static char ec_weekday[][16]={EC_WEEKDAY0,EC_WEEKDAY1,EC_WEEKDAY2,EC_WEEKDAY3,EC_WEEKDAY4,EC_WEEKDAY5,EC_WEEKDAY6};
	static char ec_weekday_am[][16]={EC_WEEKDAY0_AM,EC_WEEKDAY1_AM,EC_WEEKDAY2_AM,EC_WEEKDAY3_AM,EC_WEEKDAY4_AM,EC_WEEKDAY5_AM,EC_WEEKDAY6_AM};
	static char ic_weekday[][16]={IC_WEEKDAY0_LABEL,IC_WEEKDAY1_LABEL,IC_WEEKDAY2_LABEL,IC_WEEKDAY3_LABEL,IC_WEEKDAY4_LABEL,IC_WEEKDAY5_LABEL,IC_WEEKDAY6_LABEL};
	if (t == GREGORIAN) return gc_weekday[m];
	else if (t == ETHIOPIAN) {
		if (l == ENGLISH) return ec_weekday[m];
		else  return ec_weekday_am[m];
	}else if (t == ISLAMIC) return ic_weekday[m];
}
char *name_of_month(CALENDAR t, int m, LANGUAGE l){
	static char gc_month[][16]={GC_MONTH01,GC_MONTH02,GC_MONTH03,GC_MONTH04,GC_MONTH05,GC_MONTH06,GC_MONTH07,GC_MONTH08,GC_MONTH09,GC_MONTH10,GC_MONTH11,GC_MONTH12,""};
	static char ec_month[][16]={EC_MONTH01,EC_MONTH02,EC_MONTH03,EC_MONTH04,EC_MONTH05,EC_MONTH06,EC_MONTH07,EC_MONTH08,EC_MONTH09,EC_MONTH10,EC_MONTH11,EC_MONTH12,EC_MONTH13};
	static char ec_month_am[][16]={EC_MONTH01_AM,EC_MONTH02_AM,EC_MONTH03_AM,EC_MONTH04_AM,EC_MONTH05_AM,EC_MONTH06_AM,EC_MONTH07_AM,EC_MONTH08_AM,EC_MONTH09_AM,EC_MONTH10_AM,EC_MONTH11_AM,EC_MONTH12_AM,EC_MONTH13_AM};
	static char ic_month[][16]={IC_MONTH01,IC_MONTH02,IC_MONTH03,IC_MONTH04,IC_MONTH05,IC_MONTH06,IC_MONTH07,IC_MONTH08,IC_MONTH09,IC_MONTH10,IC_MONTH11,IC_MONTH12,""};
	if (t == GREGORIAN) return gc_month[m-1];
	else if (t == ETHIOPIAN) {
		if (l == ENGLISH) return ec_month[m-1];
		else  return ec_month_am[m-1];
	}else if (t == ISLAMIC) return ic_month[m-1];
}
CalendarHtml::CalendarHtml(DATE2 c,CALENDAR t,CALENDAR s)
		: Fl_Text_Buffer(0)
{
	Current = c;
	type = t;
	sub = s;
	setLanguage();
	//	     lang = AMHARIC;
}
/*
void CalendarHtml::make_attribute(const char *name, const char *value){
	append(name);
	append("='");
	append(value);
	append("' ");
}
void CalendarHtml::make_font(const char *str, const char *color, const char *size){
	char str2[256];
	append("<font ");
	make_attribute("size",size);
	make_attribute("color",color);
	append(">");
	append(str);
	append("</font>");
}
void CalendarHtml::make_cell_index(const char *str, const char *color){
	append("<th width='14%'>");
	make_font(str, color, fontsize_label);
	append("</th>");
}
void CalendarHtml::make_cell_index_string(const char *str1, const char *str2, const char *color){
	char str[32];
	sprintf(str,"%s<br>%s",str1,str2);
	make_cell_index(str,color);
}
*/
void CalendarHtml::make_row_label(){
	char str[128];
	append("<tr>");
	append("<th>");
	/*
	make_cell_index_string(GC_WEEKDAY0_LABEL,EC_WEEKDAY0_AM,"red");
	make_cell_index_string(GC_WEEKDAY1_LABEL,EC_WEEKDAY1_AM,"black");
	make_cell_index_string(GC_WEEKDAY2_LABEL,EC_WEEKDAY2_AM,"black");
	make_cell_index_string(GC_WEEKDAY3_LABEL,EC_WEEKDAY3_AM,"black");
	make_cell_index_string(GC_WEEKDAY4_LABEL,EC_WEEKDAY4_AM,"black");
	make_cell_index_string(GC_WEEKDAY5_LABEL,EC_WEEKDAY5_AM,"black");
	make_cell_index_string(GC_WEEKDAY6_LABEL,EC_WEEKDAY6_AM,"black");
	*/
	sprintf(str,"<font class='sunday'>%s<br>%s</font>",name_of_weekday(type,0,lang),name_of_weekday(sub,0,lang));
	append(str);
	for(int i=1;i<7;i++){
		append("</th><th>");
		sprintf(str,"<font class='weekday'>%s<br>%s</font>",name_of_weekday(type,i,lang),name_of_weekday(sub,i,lang));
		append(str);
	}
	append("</th>");
	append("</tr>");
}
void CalendarHtml::make_cell(){
	char str[256];
	append("<td>");
	append("<div class='main'>");
	sprintf(str,"%d",work.Day(type));
	if (work.IsHoliday()) {
		append("<font class='holiday'>");
		add_holiday();
	} else if (work.Weekday() == 0) {
		append("<font class='sunday'>");
	} else {
		append("<font class='weekday'>");
	}
	append(str);
	append("</font>");
	append("</div>");
	append("<div class='sub'>");
	sprintf(str,"%d",work.Day(sub));
	if (work.IsHoliday()) {
		append("<font class='holiday'>");
	} else if (work.Weekday() == 0){
		append("<font class='sunday'>");
	} else {
		append("<font class='weekday'>");
	}
	append(str);
	append("</font>");
	append("</div>");
	append("</td>");
}
void CalendarHtml::make_row(){
	int i;
	append("<tr>");
	for(i=0;i<work.Weekday();i++){
		append("<td>&nbsp;</td>");
	}
	for(i=work.Weekday();Current.Month(type)==work.Month(type);i++){
		make_cell();
		if (work.Weekday() % 7 == 6) append("</tr><tr>");
		work.Tomorrow();
	}
	for(;i<42;i++){
		if (i % 7 == 0) break;//append("</tr><tr>");
		append("<td>&nbsp;</td>");
	}
	append("</tr>");
}
void CalendarHtml::make_table(){
	append("<table id='calendar_table'>");
	make_row_label();
	make_row();
	append("</table>");
}
void CalendarHtml::make_calendar(){
	char str[256];
	append("<table id='calendar'><tr>");
	//	  sprintf(str,"<td style='text-align: left; vertical-align: bottom;'><font size='%s'>",fontsize_main);
	append("<td class='main'>");
	sprintf(str,"%s, %d",name_of_month(type,work.Month(type),lang),work.Year(type));
	append(str);
	append("</td>");
	//	  sprintf(str,"<td style='text-align: right; vertical-align: bottom;'><font size='%s'>",fontsize_sub);
	append("<td class='sub'>");
	sprintf(str,"%s, %d",name_of_month(sub,work.Month(sub),lang),work.Year(sub));
	append(str);
	append("</td>");
	append("</tr></table>");
	make_table();
	//	  sprintf(str,"<div align='right'><font size='%s'>",fontsize_sub);
	append("<div align='right'><font class='sub'>");
	sprintf(str,"%s, %d",name_of_month(sub,work.Month(sub),lang),work.Year(sub));
	append(str);
	append("</font></div>");
}
void CalendarHtml::make_header(int mode){
	char str[256];
	char css[32];
	append("<html lang='am'>");
	append("<head>");
	append("<meta content='text/html; charset=UTF-8' http-equiv='content-type'>");
	append("<title>Ethiopian Calendar</title>");
	switch (mode){
	case 1:
		strcpy(css,"calendar1.css");
		break;
	case 2:
		strcpy(css,"calendar2.css");
		break;
	case 6:
		strcpy(css,"calendar6.css");
		break;
	case 12:
		strcpy(css,"calendar12.css");
		break;
	default:
		strcpy(css,"");
	}
	sprintf(str,"<link href='%s' rel='stylesheet' type='text/css'>",css);
	append(str);
	append("</head>");
	append("<body>");
	append("<table id='header'><tbody><tr>");
	append("<td id='logo'>");
	append("<img style='width: 64px; height: 64px;' alt='' src='handy.jpg' align='middle'></td>");
	append("<td id='title'>");
	append(ETHIOCALENDAR_TITLE);
	append("</td>");
	append("<td id='org'><img src='jica.jpg' align='right'></td>");
	append("</tr></tbody></table>");
}
void CalendarHtml::make_footer(){
	char str[256];
	append("<hr>");
	sprintf(str,"<div id='footer'>&copy;2008-2009 Yuji DOI. &lt;<a href=%s>%s</a>&gt;</div>",ETHIOCALENDAR_URI,ETHIOCALENDAR_URI);
	append(str);
	append("</body>");
	append("</html>");
}
void CalendarHtml::draw1() {
	//	  DATE2 work; //for display calendar
	const char filename[256] = "output.htm";
	//	  strcpy(fontsize_main,"+3");
	//	  strcpy(fontsize_sub,"+0");
	//	  strcpy(fontsize_label,"+0");
	work = Current;
	work.FirstDay(type);
	//	  append("<hr>");
	make_header(1);
	strcpy(holiday,"");
	make_calendar();
	make_holidays();
	make_footer();
	outputfile(filename, 0, length());
	show_browser(filename);
}
void CalendarHtml::draw2() {
	//	  DATE2 work; //for display calendar
	const char filename[256] = "output.htm";
	//	  strcpy(fontsize_main,"+2");
	//	  strcpy(fontsize_sub,"-1");
	//	  strcpy(fontsize_label,"+0");
	work = Current;
	work.FirstDay(type);
	//	  append("<hr>");
	make_header(2);
	strcpy(holiday,"");
	make_calendar();
	make_holidays();
	Current.NextMonth(type);
	append("<hr>");
	strcpy(holiday,"");
	make_calendar();
	make_holidays();
	make_footer();
	outputfile(filename, 0, length());
	show_browser(filename);
}
void CalendarHtml::draw1w() {
	//	  DATE2 work; //for display calendar
	const char filename[256] = "output.htm";
	CALENDAR tmp;
	//	  strcpy(fontsize_main,"+2");
	//	  strcpy(fontsize_sub,"-1");
	//	  strcpy(fontsize_label,"+0");
	work = Current;
	work.FirstDay(type);
	//	  append("<hr>");
	make_header(2);
	strcpy(holiday,"");
	make_calendar();
	make_holidays();
	tmp = type;
	type = sub;
	sub = tmp;
	work = Current;
	work.FirstDay(type);
	append("<hr>");
	strcpy(holiday,"");
	make_calendar();
	make_holidays();
	make_footer();
	outputfile(filename, 0, length());
	show_browser(filename);
}
void CalendarHtml::draw6() {
	int i,j;
	//	  DATE2 work; //for display calendar
	const char filename[256] = "output.htm";
	//	  strcpy(fontsize_main,"+1");
	//	  strcpy(fontsize_sub,"-2");
	//	  strcpy(fontsize_label,"-2");
	make_header(6);
	append("<table width='100%'>");
	for(i=0;i<3;i++){
		append("<tr>");
		for(j=0;j<2;j++){
			append("<td style='vertical-align: top;'>");
			work = Current;
			work.FirstDay(type);
			make_calendar();
			Current.NextMonth(type);
			append("</td>");
		}
		append("</tr>");
	}
	append("</table>");
	make_footer();
	outputfile(filename, 0, length());
	show_browser(filename);
}
void CalendarHtml::draw12() {
	int i,j;
	//	  DATE2 work; //for display calendar
	const char filename[256] = "output.htm";
	//	  strcpy(fontsize_main,"-2");
	//	  strcpy(fontsize_sub,"-3");
	//	  strcpy(fontsize_label,"-3");
	make_header(12);
	append("<table width='100%'>");
	for(i=0;i<4;i++){
		append("<tr>");
		for(j=0;j<3;j++){
			append("<td style='vertical-align: top;'>");
			work = Current;
			work.FirstDay(type);
			make_calendar();
			Current.NextMonth(type);
			append("</td>");
		}
		append("</tr>");
	}
	append("</table>");
	make_footer();
	outputfile(filename, 0, length());
	show_browser(filename);
}
void CalendarHtml::add_holiday(){
	char tmp[64];
	DATE1 d;
	if (type==GREGORIAN) d = work.gr;
	else if (type==ETHIOPIAN) d = work.et;
	else if (type==ISLAMIC) d = work.is;
	sprintf(tmp, "%2d: %s<br>", d.day, work.holiday);
	strcat(holiday,tmp);
}
void CalendarHtml::make_holidays() {
	if (strcmp(holiday,"")){
		append("<table id='holidays'><tr><td>");
		append(holiday);
		append("</td></tr></table>");
	}
}
#include <FL/fl_ask.H>
void CalendarHtml::setLanguage(){
	if (fl_ask("Do you have Amharic font?")) lang = AMHARIC;
	else lang = ENGLISH;
}

