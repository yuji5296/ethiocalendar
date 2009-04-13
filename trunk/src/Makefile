#PREFIX = /home/yuji/fltk-1.1.7
PREFIX =/usr/local
INCLUDE = -I$(PREFIX)/include -I/usr/include
LIB = -L$(PREFIX)/lib -lfltk_images -lfltk_png -lfltk_z -lfltk_jpeg -lfltk  -L/usr/lib -lm -lXext -lX11 -lXpm
TARGET = EthioCalendar
#OBJS = date.o date2.o calendar.o ethiocalendarui.o main.o ethiocalendar.o
#OBJS = $(wildcard *.o)
OBJS = $(SRCS:.cxx=.o)
#SRCS = $(OBJS:.o=.cxx)
SRCS = HolidayList.cxx CalendarHtml.cxx Fl_Clock_Ethiopia.cxx yaecob.cxx date.cxx date2.cxx EthioCalendarUI.cxx CalendarMonth.cxx CalendarCell.cxx CalendarTable.cxx linux.cxx main.cxx
CFLAGS = #-g
CC = g++
FLS = EthioCalendarUI.fl


$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(INCLUDE) $(LIB)
#	$(PREFIX)/bin/fltk-config --compile main.cxx	

yaecob: yaecob.o date.o
	$(CC) $(CFLAGS) yaecob.o date.o -o $@ $(INCLUDE) $(LIB)


.SUFFIXES: .c .cxx .o .fl .h
.fl.h .fl.cxx: $(FLS)
	/home/yuji/fltk-1.1.9/fluid/fluid -c $<
.cxx.o: $(SRCS)
	$(CC) $(CFALGS) -c $< $(INCLUDE) -o $@

zip:
	zip -u ethiocalendar-v1.5.1-linux.zip $(TARGET) openbrowser.sh index_e.htm index_j.htm handy.jpg screenshot.jpg jica.jpg 
	
install:
	mkdir -p /usr/share/ethiocalendar
	chmod 777 /usr/share/ethiocalendar
#	touch /usr/share/ethiocalendar/output.htm
#	chmod 666 /usr/share/ethiocalendar/output.htm
	cp openbrowser.sh /usr/share/ethiocalendar/.
	cp help.htm /usr/share/ethiocalendar/.
	cp handy.jpg /usr/share/ethiocalendar/.
	cp screenshot.jpg /usr/share/ethiocalendar/.
	cp jica.jpg /usr/share/ethiocalendar/.
	cp EthioCalendar /usr/share/ethiocalendar/.
	cp ethiocalendar.css /usr/share/ethiocalendar/.
	cp calendar1.css /usr/share/ethiocalendar/.
	cp calendar2.css /usr/share/ethiocalendar/.
	cp calendar6.css /usr/share/ethiocalendar/.
#	chmod 755 /usr/share/ethiocalendar/EthioCalendar
	cp ethiocalendar.sh /usr/bin/.
#	chmod 755 /usr/bin/ethiocalendar.sh
	cp ethiocalendar.desktop /usr/share/applications/.
	cp handy.png /usr/share/icons/.

uninstall:
	rm -rf /usr/share/ethiocalendar
	rm -f  /usr/bin/ethiocalendar.sh
	rm -f /usr/share/applications/ethiocalendar.desktop
	rm -f /usr/share/icons/handy.png

clean :
	rm -f *.o
	rm -f $(FLS:.fl=.cxx) $(FLS:.fl=.h)
	rm -f $(TARGET)
	rm -f output.htm
	
deb:
	cd  ../ethiocalendar-1.6.1 ;	dpkg-buildpackage

