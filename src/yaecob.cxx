/** \file yaecob.cxx
 * \brief Functions for calculating Easter
 * \details This source file implement method for calculating Good Friday and Easter. This algorithm was taught by Yaecob.
 * \author Yuji DOI<yuji5296@gmail.com>
 * \date 2008-2009
 */
#include <stdio.h>
#include "yaecob.h"
#define OFFSET_YEAR	5500
#define TINTE_ABEKETEA	11	//7*23 % 30
#define TINTE_METKEA	19	//7*7 % 30
void year_name(int year){
	int i = ( OFFSET_YEAR + year ) % 4;
	printf("The %d year is ",year);
	switch (i) {
	case 0: printf("Zemene Yohannes (John),");break;
	case 1: printf("Zemene Mathewos (Mathew),");break;
	case 2: printf("Zemene Markos   (Mark),");break;
	case 3: printf("Zemene Lukas    (Luke),");break;
	}
}
int weekday_of_newyear(int year){
	static char weekday[][16]={"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
	int y = OFFSET_YEAR + year;
	int x = y / 4;
	int w = ( y + x ) % 7;
//	printf("%d:%s,",w,weekday[w]);
	return w;
}
int Weneber(int year){
	int w = ((OFFSET_YEAR + year ) % 19) - 1;
//	printf("%2d,",w);
	return w;
}
int Metkea(int year){
	int m, w = Weneber(year);
	if (w == 0){
		m = 30;
	}else if (w == -1){
		//previous metkea + 19
		m = Metkea(year-1) + TINTE_METKEA;
	}else {
		m = (TINTE_METKEA * w) % 30;
	}
//	printf("%2d,",m);
	return m;
}
int Metkea2(int metkea){
	///Calculate Metkea from the previous years Metkea
	return (metkea + TINTE_METKEA ) % 30;
}
int Abektea(int year){
	int a, w = Weneber(year);
	if (w == 0){
		a = 0;
	}else if (w == -1){
	  a = Abektea(year-1) + TINTE_ABEKETEA;
	}else{
		a = (TINTE_ABEKETEA * w) % 30;
	}
//	printf("%2d,",a);
	return a;
}
DATE1 * Mebaja_hammer(int year){
	int GivenNumber[]={7,6,5,4,3,2,8};//start from Sunday
	int metkea = Metkea(year);
	int m;	//Month of Metkea
	if (metkea == 14 ) printf("Error!\n");
	else if (metkea > 14) {
		m=1;	//Meskaram
	}else{
		m=2; 	//Tkmt
	}
	DATE1 *mh = new DATE1(year,m,metkea,ETHIOPIAN);
	mh->calc_weekday();
	int w = mh->weekday;
	int g = GivenNumber[w];
	int	 d = metkea + g;
	if (d > 30 ) {
		d -= 30 ;
		m=2; 	//Tkmt
	}
	mh = new DATE1(year,m,d,ETHIOPIAN);
//	printf("%s,",mh->print_date());
	return mh ;
}
DATE1 * Good_Friday(int year){
	DATE1 *mh = Mebaja_hammer(year);
	///add 5 months and 69 days from Mebaja Hammer
	for(int i=0;i<4;i++) mh->NextMonth();
	///add 69 days
	mh->calc_date(mh->calc_serial()+67,ETHIOPIAN);
//	  for(int i=0;i<67;i++) mh->Tomorrow();
//	printf("%s,",mh->print_date());
	return mh;
}
DATE1 * Easter(int year){
	///add 2 days from good friday
	DATE1 *gf = Good_Friday(year);
	gf->Tomorrow();
	gf->Tomorrow();
//	printf("%s",gf->print_date());
	return gf;
}

#if 0
int DayMoon(DATE1 *d){
	int rtn;
	int m = (d->month + 1) / 2 ;
	if (m > 6 ) m = 6;	//Pagume = 6
	rtn = (Abektea(d->year) + m + d->day + 4 ) % 30 ;
	return rtn;
}
int test1(int year){
	year_name(year);
	weekday_of_newyear(year);
	printf("Weneber = %d\n",Weneber(year));
	printf("Metkea = %d\n", Metkea(year));
	printf("Abektea = %d\n", Abektea(year));
	Mebaja_hammer(year);
}
int test2(){
	int year ;
	for(year = 1;year<2001;year++)
		printf("Metkea = %d\n", Metkea(year));
}
int test3(){
	DATE1 *d = new DATE1(2001,2,18,ETHIOPIAN);
	printf("DayMoon=%d\n",DayMoon(d));
}

int main(){
	int year ;
	printf("Year,Weneber,Metkea,Mebaja_hammer,Good_Friday,Easter\n");
	for(year = 1970;year<2030;year++){
		printf("%d,",year);
//		year_name(year);
//		weekday_of_newyear(year);
		Easter(year);
		printf("\n");
	}
}
#endif

