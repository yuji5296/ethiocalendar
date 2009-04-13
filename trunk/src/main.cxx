/*! \mainpage
 *
 * \image html handy.png
 * \author Yuji DOI<yuji5296@gmail.com>
 * \date 2009/03/10
*/
/** \file main.cxx
 * \brief main function
 * 
 * \author Yuji DOI<yuji5296@gmail.com>
 * \date 2008-2009
 */
#include "EthioCalendarUI.h"

/*! \fn main(int argc, char **argv)
 *  \brief Main function.
 *  \param argc a number of command line argument.
 *  \param argv an array of command line argument.
 *  \return a status code of Fl::run().
 */int main(int argc, char **argv){
	EthioCalendarUI cal;
	cal.show(argc,argv);
	return Fl::run();
}

