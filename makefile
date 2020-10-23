CC = g++
CCFLAGS = -g -Wall -Werror


APP = conway

all: $(APP)

$(APP): $(APP).cpp
	$(CC) $(CCFLAGS)  -o $(APP) $(APP).cpp -lncurses

clean:
	$(RM) $(APP)	
