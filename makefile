all: app

app: main.o conway.o
	g++ -g -Wall -Werror main.o conway.o -o app -lncurses
main.o: main.cpp
	g++ -g -c -Wall -Werror main.cpp
conway.o: conway.cpp
	g++ -g -c -Wall -Werror conway.cpp

clean:
	rm *.o app


