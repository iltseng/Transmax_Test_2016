
CC              = g++

CFLAGS          = -O2 -std=c++0x -Wall
#CFLAGS          = -g

OBJ		= First_Names.o main.o Names.o Scores.o

all: grade-scores

grade-scores: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

First_Names.o: First_Names.cpp First_Names.hpp
	$(CC) $(CFLAGS) -c First_Names.cpp

main.o: main.cpp main.hpp Scores.hpp
	$(CC) $(CFLAGS) -c main.cpp

Names.o: Names.cpp Names.hpp First_Names.hpp
	$(CC) $(CFLAGS) -c Names.cpp

Scores.o: Scores.cpp Scores.hpp Names.hpp
	$(CC) $(CFLAGS) -c Scores.cpp

clean:
	rm -f grade-scores $(OBJ)
