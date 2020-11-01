all: conway

conway: main.o conway.o
	g++ -g -Wall -Werror main.o conway.o -o conway -lncurses
main.o: main.cpp
	g++ -g -c -Wall -Werror main.cpp
conway.o: conway.cpp
	g++ -g -c -Wall -Werror conway.cpp
.PHONY: clean
clean:
	-rm *.o  conway
