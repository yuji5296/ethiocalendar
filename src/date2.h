/** \file date2.h
 * \brief Class for having multiple date class
 * 
 * \author Yuji DOI<yuji5296@gmail.com>
 * \date 2008-2009
 */
#ifndef date2_h
#define date2_h
#include "date.h"

/*! \class DATE2 date2.h "date2.h"
 *  \brief Class for having multiple date class.
 *
 * This class has some DATE1 class.
 */
class DATE2 {
	int serial;
	void calc_date2();
public:
	DATE1 gr;	//Gregorian calendar
	DATE1 et;	//Ethiopian calendar
	DATE1 is;	//Islamic calendar
	DATE2();
	DATE2(short y, char m, char d, CALENDAR calendar);
//	   DATE2(long serial);
	void Today();
	void Tomorrow();
	void Yesterday();
	void NextYear(CALENDAR calendar);
	void NextMonth(CALENDAR calendar);
	void PrevYear(CALENDAR calendar);
	void PrevMonth(CALENDAR calendar);
	void FirstDay(CALENDAR calendar);
	int Year(CALENDAR calendar);
	void Year(CALENDAR calendar, int year);
	int Month(CALENDAR calendar);
	void Month(CALENDAR calendar, int month);
	int Day(CALENDAR calendar);
	int Weekday();
	char* name_of_month(CALENDAR calendar);
//	  int calc_serial2();
//	  int scan_date2();
	void scan(const char *str,CALENDAR calendar);
//	  void disp_date2();
//	  void disp_calendar2();
	char* print_date();
	char* print_date(CALENDAR calendar);
	char* print_short();
	   char* print_short(CALENDAR calendar);
//	    int number_of_days(CALENDAR calendar);
	int DiffDate(DATE2 d1, DATE2 d2);
	bool CompDate(DATE2 date);
	bool IsHoliday();
	char holiday[64];
};
#endif

