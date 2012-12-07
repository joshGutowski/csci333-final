CPP = g++
CFLAGS = -Wall -Wextra -Werror

all: clean list wordList

list: list.cpp
	$(CPP) $(CFLAGS) -o list list.cpp

wordList: wordList.cpp
	$(CPP)  $(CFLAGS) -o wordList wordList.cpp

clean:
	rm -f *.o;
	rm -f *~;
	rm -f list;
	rm -f wordList;
	rm -f words;
	rm -f lexicalDiversity;