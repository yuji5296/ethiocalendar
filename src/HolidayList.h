/** \file HolidayList.h
 * \brief Class for display list of holiday
 * 
 * \author Yuji DOI<yuji5296@gmail.com>
 * \date 2008-2009
 */
#ifndef HolidayList_h
#define HolidayList_h
#include <FL/Fl_Text_Buffer.H>
#include "date2.h"
/*! \class HolidayList HolidayList.h "HolidayList.h"
 *  \brief Class for display list of holiday.
 *
 * This class is buffer for list of holiday.
 */
class HolidayList : public Fl_Text_Buffer {
private:
	DATE2 Current, work;
	CALENDAR type;
	CALENDAR sub;
public:
	HolidayList(DATE2 Current,CALENDAR type, CALENDAR sub);
};
#endif

