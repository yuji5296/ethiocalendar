/** \file date.cxx
 * \brief Class for having a date class
 * 
 * \author Yuji DOI<yuji5296@gmail.com>
 * \date 2008-2009
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "date.h"
#include "yaecob.h"
/* Base point */
//const int BASE[2]={1600,1596};
const int BASE[3]={1600,1600,1020};
/* Table of Total Days each month */
int MONTH[6][14]={
                     {0,31,59,90,120,151,181,212,243,273,304,334,365,365},// Gregorian non-leap year
                     {0,31,60,91,121,152,182,213,244,274,305,335,366,366},// Gregorian leap year
                     {0,30,60,90,120,150,180,210,240,270,300,330,360,365},// Ethiopian non-leap year
                     {0,30,60,90,120,150,180,210,240,270,300,330,360,366},// Ethiopian leap year
                   {0,30,59,89,118,148,177,207,236,266,295,325,354,354},// Hijula non-leap year
                   {0,30,59,89,118,148,177,207,236,266,295,325,355,355},// Hijula leap year
//                     {0,29,59,89,118,147,177,206,236,265,295,324,354,354},// Isramic in Austria
//                     {0,30,60,90,119,148,178,207,237,266,296,325,355,355},// Isramic in Austria
                 };
/* Names of Month */
char MONTH_NAME[3][13][16]={
                               {GC_MONTH01,GC_MONTH02,GC_MONTH03,GC_MONTH04,GC_MONTH05,GC_MONTH06,GC_MONTH07,GC_MONTH08,GC_MONTH09,GC_MONTH10,GC_MONTH11,GC_MONTH12,""},
                               {EC_MONTH01,EC_MONTH02,EC_MONTH03,EC_MONTH04,EC_MONTH05,EC_MONTH06,EC_MONTH07,EC_MONTH08,EC_MONTH09,EC_MONTH10,EC_MONTH11,EC_MONTH12,EC_MONTH13},
                               {IC_MONTH01,IC_MONTH02,IC_MONTH03,IC_MONTH04,IC_MONTH05,IC_MONTH06,IC_MONTH07,IC_MONTH08,IC_MONTH09,IC_MONTH10,IC_MONTH11,IC_MONTH12,""},
                           };
/* Names of Day */
char WEEKDAY_NAME[3][7][16]={
                                {GC_WEEKDAY0,GC_WEEKDAY1,GC_WEEKDAY2,GC_WEEKDAY3,GC_WEEKDAY4,GC_WEEKDAY5,GC_WEEKDAY6},
                                {EC_WEEKDAY0,EC_WEEKDAY1,EC_WEEKDAY2,EC_WEEKDAY3,EC_WEEKDAY4,EC_WEEKDAY5,EC_WEEKDAY6},
                                {IC_WEEKDAY0,IC_WEEKDAY1,IC_WEEKDAY2,IC_WEEKDAY3,IC_WEEKDAY4,IC_WEEKDAY5,IC_WEEKDAY6},
                            };
static char gc_weekday[][16]={GC_WEEKDAY0_LABEL,GC_WEEKDAY1_LABEL,GC_WEEKDAY2_LABEL,GC_WEEKDAY3_LABEL,GC_WEEKDAY4_LABEL,GC_WEEKDAY5_LABEL,GC_WEEKDAY6_LABEL};

/* Constructor */
DATE1::DATE1(){
	serial = 0;
	year = 0;
	month = 0;
	day = 0;
	weekday = 0;
	type = GREGORIAN;
}
/*DATE1::DATE1(long serial){
	serial = serial;
	calc_date(serial,GREGORIAN);
}*/
DATE1::DATE1(short y, char m, char d, CALENDAR t){
	type = t;
	year = y;
	month = m;
	day = d;
	calc_serial();
	calc_weekday();
}
/* Judge Leap year */
bool DATE1::isLeap(int x, CALENDAR calendar){
	if (calendar == GREGORIAN){
		if ((x % 400) == 0){
			return true;
		}else if ((x % 100) == 0){
			//	  	  	  if (x == 1900){
			/* Excel specific */
			//	  	  	  	  return 1;
			//	  	  	  }else{
			return false;
			//	  	  	  }
		}else if ((x % 4) == 0){
			return true;
		}else{
			return false;
		}
	}else if(calendar == ETHIOPIAN){
		if (((x + 1) % 4) == 0){
			return true;
		}else{
			return false;
		}
	}else if(calendar == ISLAMIC){
		switch ((x+1) % 30){
		case 2:
		case 5:
		case 7:
		case 10:
		case 13:
		case 15:
		case 18:
		case 20:
		case 24:
		case 26:
		case 29:
			return true;
		default:
			return false;
		}
	}else {
		return false;
	}
}
/* Calculate Days of year */
int DATE1::days1(int x, CALENDAR calendar){
	if (calendar == ISLAMIC) {
		return 354 + isLeap(x,calendar);
	}else {
		return YEAR1 + isLeap(x,calendar);
	}
}
/* Calculate Days of years from X to Y */
int DATE1::days2(int x, int y, CALENDAR calendar){
	int d;
	for(d=0;y>=x;x++){
		d += days1(x, calendar);
	}
	return d;
}
int DATE1::calc_serial(){
	int x;
	x = days2(BASE[type],year-1,type);
	x += MONTH[2 * type + isLeap(year, type)][month-1];
	x += day;
	//	  weekday = calc_weekday(x);
	if (type == ETHIOPIAN){
		x = x + OFFSET;
	}else if (type == ISLAMIC) {
		x = x + OFFSET_ISLAMIC;
	}
	serial = x;
	return serial;
}
/* Calculate Name of Day */
void DATE1::calc_weekday(){
	int a;
	a = abs(serial) % 7;
	if (a>=FIRSTWEEKDAY) a -= FIRSTWEEKDAY;
	else a += (7-FIRSTWEEKDAY);
	weekday = a;
}
int DATE1::number_of_days(){
	static int days_of_month[]={31,28,31,30,31,30,31,31,30,31,30,31};//Gregorian
//	  static int days_of_month_ic[]={29,30,30,29,29,30,29,30,29,30,29,30};// Islamic in Austria
	      if (type == GREGORIAN){
		if (month == 2){
			if (isLeap(year,type)) return 29;
			else return 28;
		}
		else return days_of_month[month-1];
	}else if (type == ETHIOPIAN){
		if (month == 13){
			if (isLeap(year,type)) return 6;
			else return 5;
		}else return 30;
	}else if (type == ISLAMIC){
#if 1// Hijula
		if (month == 12){
			if (isLeap(year,type)) return 30;
			else return 29;
		}else if (month % 2) return 30;
		else return 29;
#else // Islamic in Austria
		if (month == 1){
			if (isLeap(year,type)) return 30;
			else return 29;
		}
		else return days_of_month_ic[month-1];
#endif

	}
}
/* Calculate month and day from Serial number */
int DATE1::calc_month(int x, int leap, int *month, int *day, CALENDAR calendar){
	int m,d,len,sub;
	int top,mid,*months;
	len = 14;
	months = MONTH[2 * calendar + leap];
	top = 0;
	for (;len>1;){
		mid = top + len/2;
		sub = months[mid-1];
		//printf("len=%d, top=%d, mid=%d,sub=%d\n",len,top,mid,sub);
		if (x <= sub) {
			len = mid - top ;
		}else{
			len = len - (mid - top);
			top = mid ;
		}
	}
	*month = top;
	*day = x - months[top-1];
	//printf("x=%d, leap=%d, month = %d, day=%d\n",x,leap,*month,*day);
	return 0;
}
/* Calculate year from Serial number */
int DATE1::calc_year(int x, int *year, int *month, int *day, CALENDAR calendar){
	int Base;	/* Base year */
	int leap;	/* flag of leap year */
	int x1, x2, x3, x4, x5;	/* days */
	int y1, y2, y3, y4;
	int rtn;
	if (calendar == GREGORIAN) {
		if (x <= days1(BASE[calendar],calendar)){
			Base = BASE[calendar];
			x1 = x;
			x4 = x3 = x2 = x1;
			y4 = y3 = y2 = y1 = 0;
		}else{
			Base = 1601;
			x1 = x - days1(BASE[calendar],calendar) ;
			y1 = x1 / YEAR400 ;		   /* Number of 400 years */
			x2 = x1 - y1 * YEAR400;	/* Days from recently 400 years */
			y2 = x2 / YEAR100 ;		/* Number of 100 years */
			if ((x2 % YEAR100) == 0) y2--;
			if (y2 > 3) y2 = 3;
			x3 = x2 - y2 * YEAR100 ;	/* Days from recently 100 years */
			y3 = x3 / YEAR4 ;			/* Number of 4 years */
			if ((x3 % YEAR4) == 0) y3--;
			if (y3 > 24) y3 = 24;
			x4 = x3 - y3 * YEAR4;		/* Days from recently 4 years */
			y4 = x4 / YEAR1 ;			/* Number of year */
			if ((x4 % YEAR1) == 0) y4--;
			if (y4 > 3) y4 = 3;
		}
		*year = Base + (y1 * 400) + (y2 * 100) + (y3 * 4) + y4 ;
	}else if (calendar == ETHIOPIAN) {
		Base = BASE[calendar];
		x1 = x - OFFSET;
		y1 = 0 ;
		x2 = x1;
		y2 = 0 ;
		x3 = x2;
		y3 = x3 / YEAR4 ;			/* Number of 4 years */
		if ((x3 % YEAR4) == 0) y3--;
		x4 = x3 - y3 * YEAR4;		/* Days from recently 4 years */
		y4 = x4 / YEAR1 ;			/* Number of year */
		if ((x4 % YEAR1) == 0) y4--;
		if (y4 > 3) y4 = 3;
		*year = Base + (y1 * 400) + (y2 * 100) + (y3 * 4) + y4 ;
	}else if (calendar == ISLAMIC) {
		Base = BASE[calendar];
		x1 = x - OFFSET_ISLAMIC;
		x3 = x1;
		y3 = x3 / 10631 ;			/* Number of 30 years */
		if ((x3 % 10631) == 0) y3--;
		x4 = x3 - y3 * 10631;		/* Days from recently 4 years */
		for (y4=0;x4 > days1(Base+(y3*30)+y4,calendar);y4++){
			x4 -= days1(Base+(y3*30)+y4,calendar);
		}
		*year = Base + (y3 * 30) + y4 ;
	}
	leap = isLeap(*year,calendar);
	x5 = x1 - days2(Base,*year-1,calendar);
	//printf("x=%d, x1=%d, x2=%d, x3=%d, x4=%d, x5=%d, y1=%d, y2=%d, y3=%d, y4=%d, Base=%d, leap=%d:",x,x1,x2,x3,x4,x5,y1,y2,y3,y4,Base,leap);
	rtn = calc_month(x5, leap, month, day, calendar);
	return rtn;
}
/* Change Serial number to DATE1 type */
void DATE1::calc_date(int x, CALENDAR calendar){
	int rtn;
	int y,m,d;
	rtn = calc_year(x, &y, &m, &d, calendar);
	year = y;
	month = m;
	day = d;
	type = calendar;
	serial = x;
	calc_weekday();
}
/* Change DATE1 to Serial number */
void DATE1::exchange_date(struct tm *from){
	year = from->tm_year + 1900;
	month = from->tm_mon + 1;
	day = from->tm_mday;
	type = GREGORIAN;
	//	  to.weekday = from->tm_wday;
	calc_serial();
	calc_weekday();
}
/* DATE1 Utility */
char* DATE1::print_date(){
	static char str[256];
	sprintf(str,"%14s %15s(%2d) %2d, %4d",WEEKDAY_NAME[type][weekday],MONTH_NAME[type][month-1],month,day,year);
	return str;
}
char* DATE1::print_short(){
	static char str[16];
	sprintf(str,"%04d/%02d/%02d(%s)",year,month,day,gc_weekday[weekday]);
	return str;
}
/* Input date from keyboard */
int DATE1::scan_date(){
	printf("Gregorian=0, Ethiopian=1> ");
	scanf(" %d",&type);
	printf("\nInput date (yyyy mm dd):");
	scanf(" %d %d %d",&year, &month, &day);
	calc_serial();
	calc_weekday();
	if (year == 0) return 0;
	if (day > number_of_days()){
		printf("Input error!\n");
		return 0;
	}
	return 1;
}
int DATE1::scan(const char *str, CALENDAR type){
	sscanf(str,"%d/%d/%d",&year, &month, &day);
	calc_serial();
	calc_weekday();
	if (year == 0) return 0;
	if (day > number_of_days()){
		printf("Input error!\n");
		return 0;
	}
	return 1;
}
char *DATE1::name_of_month(){
	return MONTH_NAME[type][month-1];
}
void DATE1::FirstDay(){
	day = 1;
	calc_serial();
	calc_weekday();
}
void DATE1::Today(){
	//	  DATE1 date;
	time_t now;
	struct tm *d;
	// get today
	now = time(&now);
	printf("Today is %s",ctime(&now));
	d = localtime(&now);
	// set today
	exchange_date(d);
	type = GREGORIAN;
	//	  return *this;
}
void DATE1::Tomorrow(){
	int lastmonth = (type==ETHIOPIAN) ? 13 : 12;
	if (day < number_of_days()){
		day++;
	}else if (month == lastmonth){	      //New Year's Eve
		day = 1;
		month = 1;
		year++;
	}else {	//end of the month
		day = 1;
		month++;
	}
	if (weekday != 6) weekday++;
	else weekday=0;
	serial++;
}
void DATE1::Yesterday(){
	int lastmonth = (type==ETHIOPIAN) ? 13 : 12;
	if (day > 1){
		day--;
	}else if (month == 1){	      //New Year's day
		year--;
		month = lastmonth;
		day = number_of_days();
	}else {	//beging of the month
		month--;
		day = number_of_days();
	}
	if (weekday != 0) weekday--;
	else weekday=6;
	serial--;
}
void DATE1::NextMonth(){
	int lastmonth = (type==ETHIOPIAN) ? 13 : 12;
	if (month == lastmonth){	       //Last month
		month = 1;
		year++;
	}else {
		month++;
	}
	calc_serial();
	calc_weekday();
}
void DATE1::NextYear(){
	year++;
	calc_serial();
	calc_weekday();
}
void DATE1::PrevMonth(){
	int lastmonth = (type==ETHIOPIAN) ? 13 : 12;
	if (month == 1){	       //First month
		month = lastmonth;
		year--;
	}else {
		month--;
	}
	calc_serial();
	calc_weekday();
}
void DATE1::PrevYear(){
	year--;
	calc_serial();
	calc_weekday();
}
int DATE1::DiffDate(DATE1 d1, DATE1 d2){
	int i;
	i = d2.serial - d1.serial;
	//for(i=0;d1.year!=d2.year||d1.month!=d2.month||d1.day!=d2.day;i++){
	//	  d1.Tomorrow();
	//}
	return i;
}
bool DATE1::CompDate(DATE1 date){
	if ((year == date.year) && (month == date.month) && (day == date.day)) return true;
	else return false;
}
bool DATE1::CompDate(DATE1 *date){
	if ((year == date->year) && (month == date->month) && (day == date->day)) return true;
	else return false;
}
#if 0
int DATE1::days(){
	int sum= day;
	int lastmonth = (type==ETHIOPIAN) ? 13 : 12;
	for(month--;month>0;month--){
		sum+=number_of_days();
	}
	for(;year>0;year--){
		for(month=lastmonth;month>0;month--){
			sum+=number_of_days();
		}
	}
	return sum;
}
/* return days from dispatched */
char * DATE1::days_dispatched(){
	DATE1 *dd = new DATE1(2007,6,19,3,GREGORIAN);
	static char str[256];
	sprintf(str,"%dth day from dispatched",calc_serial() - dd->calc_serial());
	//printf("%dth day from dispatched\n",DiffDate(*dd,*this));
	return str;
}
/* return days from specified day */
int DATE1::get_days_from(DATE1 dd){
	return calc_serial() - dd.calc_serial();
}
/* return days until specified day */
int DATE1::get_days_until(DATE1 dd){
	return dd.calc_serial() - calc_serial();
}
void DATE1::disp_date(){
	int x, rtn;
	// display
	days_dispatched();
	print_date();
	x = calc_serial();
	printf(" => x=%d =>\n",x);
	calc_date(x, ETHIOPIAN);
	print_date();
	printf("\n");
}
void DATE1::disp_calendar(){
	int i,d=1,m=month,x;
	DATE1 date2;
	CALENDAR t;
	day = 1;
	x = calc_serial();
	weekday = calc_weekday(x);
	if (type == GREGORIAN ) t = ETHIOPIAN;
	else t = GREGORIAN;
	date2.calc_date(x, t);
	//	  date.weekday = calc_weekday(calc_serial(&date));
	printf("%s, %d\t/\t",MONTH_NAME[type][month-1],year);
	printf("%s, %d\n",MONTH_NAME[date2.type][date2.month-1],date2.year);
	printf(" Sun   Mon   Tue   Wed   Thu   Fri   Sat\n");
	for(i=0;i<weekday;i++) printf("      ");
	while(month == m){
		printf("%2d/%2d ",day,date2.day);
		Tomorrow();
		date2.Tomorrow();
		if (weekday == 0) {
			printf("\n");
		}
	}
	printf("\n");
}
#endif
bool DATE1::Validate(){
	if(type==GREGORIAN){
		if(year < 1604 || 9999 < year) return false;
	}else{
		if(year < 1604 || 9999 < year) return false;
	}
	if(month < 1 || MAXMONTH(type) < month) return false;
	if(day < number_of_days() || number_of_days() < day) return false;
	return true;
}
bool DATE1::IsHoliday(){
	if (type == GREGORIAN) {
		if (month==1 && day==7) {strcpy(holiday,"Ethiopian Christmas");return true;}//JICA Calendar
	   	   if (month==5 && day==1) {strcpy(holiday,"International Labour Day");return true;}
	   	   else {strcpy(holiday,"");return false;}
	}else if (type == ETHIOPIAN){
		if (month==1 && day==1)  {strcpy(holiday,"Ethiopian New Year");return true;}
		if (month==1 && day==17) {strcpy(holiday,"Finding of the True cross(Meskel)");return true;}
//	  	  if (month==4 && day==29) {strcpy(holiday,"Ethiopian Christmas");return true;}//Which is correct?
		if (month==5 && day==11) {strcpy(holiday,"Ethiopian Epiphany(Timqat)");return true;}
		if (month==6 && day==23) {strcpy(holiday,"Victory of Adwa Command Day");return true;}
		if (month==8 && day==27) {strcpy(holiday,"Ethiopian Patriots Command Day");return true;}
		if (month==9 && day==20) {strcpy(holiday,"Dawn Fall of the Dergue");return true;}
		if (IsGoodFriday()) {strcpy(holiday,"Good Friday");return true;}
		if (IsEaster()) {strcpy(holiday,"Ethiopian Easter");return true;}
		else {strcpy(holiday,"");return false;}
	}else if (type == ISLAMIC){
		//Muslim holiday
		if (month==3 && day==12)  {strcpy(holiday,"Birth Day of Prophet Mohammed(MAULID)");return true;}
	   	if (month==10 && day==1)  {strcpy(holiday,"Id Al Faster(Ramadan)");return true;}
		if (month==12 && day==10)  {strcpy(holiday,"Id Al Adha(Arefa)");return true;}
	      }
	else {strcpy(holiday,"");return false;}
}
bool DATE1::IsGoodFriday(){
	if (CompDate(Good_Friday(year))) return true;
	else return false;
}
bool DATE1::IsEaster(){
	if (CompDate(Easter(year))) return true;
	else return false;
}
bool DATE1::IsRamadan(){
	      if (year == 2000 && month==2 && day==1) return true;
	if (year == 2001 && month==1 && day==21) return true;
	else return false;
}
bool DATE1::IsArefa(){
	      if (year == 2000 && month==4 && day==9) return true;
	if (year == 2001 && month==3 && day==29) return true;
	else return false;
}
bool DATE1::IsMaulid(){
	   if (year == 2000 && month==7 && day==10) return true;
	if (year == 2001 && month==6 && day==29) return true;
	else return false;
}

