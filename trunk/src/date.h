/** \file date.h
 * \brief Class for having a date
 * 
 * \author Yuji DOI<yuji5296@gmail.com>
 * \date 2008-2009
 */
#ifndef date_h
#define date_h
#include <ctime>
#include "resource.h"

/*! Calendar types */
typedef enum  {GREGORIAN, ETHIOPIAN, ISLAMIC} CALENDAR;
/*! Language types */
typedef enum  {ENGLISH, AMHARIC, JAPANESE, ARABIC} LANGUAGE;

/*! Days of no-leap year */
#define YEAR1 365	  	
/*! Days of 4 years include leap year */
#define YEAR4 1461		
/*! Days of 100 years ,last year is not leap year*/
#define YEAR100 36524	
/*! Days of 400 years */
#define YEAR400 146097	
/*!
 Offset days between Europian and Ethiopian.
 Days between GC1600/1/1 and GC1607/9/9(EC1600/1/1).
*/
#define OFFSET	 2808
/* GC1603/9/9, EC1596/1/1 */
//#define OFFSET	347

/*! Days between GC1600/1/1 and GC1611/3/15(IC1020/1/1) */
#define OFFSET_ISLAMIC	 4091
/*! Weekday of firstday */
#define FIRSTWEEKDAY 2
/*! The number of month */
#define MAXMONTH(type)	(type == GREGORIAN) ? 12 : 13

/*! \class DATE1 date.h "date.h"
 *  \brief Class for having a date.
 *
 * This class has a date.
 */
class DATE1 {
public:
	int serial;
	short year;
	char month;
	char day;
	char weekday;
	CALENDAR type;	 //GREGORIAN or ETHIOPIAN
	DATE1();
//	  DATE1(long serial);
	DATE1(short y, char m, char d, CALENDAR calendar);
//	  DATE1(short y, char m, char d, char w, CALENDAR calendar);
	void calc_date(int x, CALENDAR calendar);
	char* print_date();
	char* print_short();
	int scan_date();
	int scan(const char *str, CALENDAR calendar);
	void Today();
	void Tomorrow();
	void Yesterday();
	void FirstDay();
	void NextYear();
	void NextMonth();
	void PrevYear();
	void PrevMonth();
//	   char *days_dispatched();
//	  int get_days_from(DATE1 dd);
//	  int get_days_until(DATE1 dd);
//	  void disp_date();
//	  void disp_calendar();
	int DiffDate(DATE1 d1, DATE1 d2);
	char *name_of_month();
	int number_of_days();
	bool CompDate(DATE1 date);
	bool CompDate(DATE1 *date);
	   int calc_serial();
	void calc_weekday();
//	    int days();	   get days from 0/1/1
	bool Validate();
	   bool IsHoliday();
	   char holiday[64];

private:
	bool isLeap(int x, CALENDAR calendar);
	int days1(int x, CALENDAR calendar);
	int days2(int x, int y, CALENDAR calendar);
	int calc_month(int x, int leap, int *month, int *day, CALENDAR calendar);
	int calc_year(int x, int *year, int *month, int *day, CALENDAR calendar);
	void exchange_date(struct tm *from);
bool IsGoodFriday();
bool IsEaster();
bool IsRamadan();
bool IsArefa();
bool IsMaulid();
};
#endif

