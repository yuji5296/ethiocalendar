/** \file CalendarHtml.h
 * \brief Class for print calendar.
 * \details This class output calendar as HTML file for print out.
 * \author Yuji DOI<yuji5296@gmail.com>
 * \date 2008-2009
 */
#ifndef CalendarHtml_h
#define CalendarHtml_h
#include <FL/Fl_Text_Buffer.H>
#include "date2.h"
#include "os.h"
char *name_of_weekday(CALENDAR t, int m, LANGUAGE l);
char *name_of_month(CALENDAR t, int m, LANGUAGE l);

/*! \class CalendarHtml CalendarHtml.h "CalendarHtml.h"
 *  \brief Class for print calendar.
 *
 * \details This class output calendar as HTML file for print out.
 */
class CalendarHtml : public Fl_Text_Buffer {
private:
	DATE2 Current, work;
	CALENDAR type;
	CALENDAR sub;
	LANGUAGE lang;
	char fontsize_main[8],fontsize_sub[8],fontsize_label[8];
//	  void make_attribute(const char *name, const char *value);
//	  void make_font(const char *str, const char *color, const char *size);
//	  void make_cell_index(const char *str, const char *color);
//	  void make_cell_index_string(const char *str1, const char *str2, const char *color);
	void make_cell();
	void make_row_label();
	void make_row();
	void make_table();
	void make_calendar();
	void make_header(int);
	void make_footer();
	void setLanguage();
public:
	CalendarHtml(DATE2 Current,CALENDAR type, CALENDAR sub);
	void draw1();
	void draw2();
	void draw6();
	void draw1w();
	void draw12();
	char holiday[512];
	void add_holiday();
	void make_holidays();
};
#endif

