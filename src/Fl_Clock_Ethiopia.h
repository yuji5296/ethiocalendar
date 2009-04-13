/** \file Fl_Clock_Ethiopia.h
 * \brief Class for Ethiopian clock
 * 
 * \author Yuji DOI<yuji5296@gmail.com>
 * \date 2008-2009
 */
#ifndef Fl_Clock_Ethiopia_H
#define Fl_Clock_Ethiopia_H
#include <FL/Fl_Clock.H>

#ifndef Fl_Widget_H
#include <Fl/Fl_Widget.H>
#endif

#define TIMEMODE_STANDARD	0
#define TIMEMODE_ETHIOPIA	  1

/*! \class Fl_Clock_Ethiopia Fl_Clock_Ethiopia.h "Fl_Clock_Ethiopia.h"
 *  \brief Class for Ethiopian clock.
 *
 * This class show Ethiopian clock.
 */
class FL_EXPORT Fl_Clock_Ethiopia : public Fl_Clock_Output {
public:
	int mode;
	int handle(int);
	void update();
	Fl_Clock_Ethiopia(int x,int y,int w,int h, const char *l = 0);
//	Fl_Clock_Ethiopia(uchar t,int x,int y,int w,int h, const char *l);
	~Fl_Clock_Ethiopia();
	char *str();
};

#endif

//
// End of "$Id: Fl_Clock.H 4288 2005-04-16 00:13:17Z mike $".
//

