
# code details

EXE_DIR = .
EXE = $(EXE_DIR)/main

SRC= Rectangle.cpp main.cpp Game.cpp

# generic build details

CC=      gcc
COPT=    -O
CXXFLAGS=  -g -Wall -std=c++11
LOADLIBES=  -lsfml-graphics -lsfml-window -lsfml-system -lstdc++
#-Wpedantic - too much C++ comment style errors

# compile to  object code

OBJ= $(SRC:.cpp=.o)

.c.o:
	$(CC) $(COPT) -c -o $@ $< $(CFLAGS) 

# build executable

$(EXE): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXE) $(LOADLIBES)

# clean up compilation

clean:
	rm -f $(OBJ) $(EXE)

# dependencies

#qtree:  main.o quadtree_functions.o 
main.o:	main.cpp 
Rectangle.o: Rectangle.cpp Rectangle.hpp
Game.o: Game.cpp Game.hpp