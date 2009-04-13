set Path=%Path%;%ProgramFiles%\quincy\mingw\bin
windres.exe handy.rc handy.o 
gcc.exe -mwindows -mno-cygwin -o EthioCalendar.exe date.o date2.o CalendarCell.o CalendarTable.o CalendarMonth.o EthioCalendarUI.o handy.o win.o main.o -L"C:\Program Files\quincy\lib" -lfltk_images -lfltk_jpeg -lfltk -lole32 -luuid -lcomctl32 -lwsock32 -lstdc++ -lsupc++
PAUSE
