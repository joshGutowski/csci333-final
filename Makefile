CPP = g++
CFLAGS = -Wall -Wextra -Werror

all: clean list

list: list.cpp
	$(CPP) $(CFLAGS) -o list list.cpp

clean:
	rm -f *.o;
	rm -f *~;
	rm -f list
