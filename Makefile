#
#
CC=g++
#
CFLAGS = -c -Wall -I/usr/include/mysql 
LFLAGS = -L/usr/lib/mysql -lmysqlclient



all: main

main: main.o dbconnect.o wine.o
	$(CC) main.o wine.o dbconnect.o -o main $(LFLAGS)

dbconnect.o: dbconnect.cpp
	$(CC) $(CFLAGS) dbconnect.cpp

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp
wine.o: wine.cpp
	$(CC) $(CFLAGS) wine.cpp


clean:
	rm *.o main

run:
	./main "select * from wineInfo where price > 100"
