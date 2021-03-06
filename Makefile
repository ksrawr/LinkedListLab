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
	$(CC) $(CFLAGS) - g dbconnect.cpp

main.o: main.cpp
	$(CC) $(CFLAGS) -g main.cpp
wine.o: wine.cpp
	$(CC) $(CFLAGS) -g wine.cpp


clean:
	rm *.o main

run:
	./main "select * from wineInfo where price > 100"
