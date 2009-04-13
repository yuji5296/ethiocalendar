/** \file HolidayList.cxx
 * \brief Class for display list of holiday
 * 
 * \author Yuji DOI<yuji5296@gmail.com>
 * \date 2008-2009
 */
#include "HolidayList.h"
//#include "EthioCalendar.h"
#include <stdio.h>
//#include <string.h>
//#define append(str) append(str);append("\n")
HolidayList::HolidayList(DATE2 c,CALENDAR t,CALENDAR s)
		: Fl_Text_Buffer(0)
{
	Current = c;
	type = t;
	sub = s;
	char str[256];
//	  append("Hello");
	work = DATE2(c.Year(type),1,1,type);
	do {
		if(work.IsHoliday()) {
//	  	  	  sprintf(str,"%04d/%02d/%02d(%s): ",work.Year(type),work.Month(type),work.Day(type),work.Weekday(type));
			append(work.print_short(type));
			append(": ");
			append(work.holiday);
			append("\n");
		}
		work.Tomorrow();
	} while(work.Year(type)==Current.Year(type));
	
}

