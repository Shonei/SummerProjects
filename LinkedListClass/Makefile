
# code details

EXE_DIR = .
EXE = $(EXE_DIR)/main

SRC= main.cpp 

# generic build details

CC=      gcc
COPT=    -O
CXXFLAGS=  -g -Wall -std=c++11 -fpermissive
LOADLIBES=  -lstdc++
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
main.o:	main.cpp Node.hpp
LinkedList.o: LinkedList.cpp LinkedList.hpp