
# code details

EXE_DIR = .
EXE = $(EXE_DIR)/main

SRC= main.cpp Node.cpp LinkedList.cpp

# generic build details

CXX=      g++
COPT=    -O
CXXFLAGS=  -g -Wall -std=c++11
LOADLIBES=  -lstdc++
#-Wpedantic - too much C++ comment style errors

# compile to  object code

OBJ= $(SRC:.cpp=.o)

.c.o:
	$(CXX) $(COPT) -c $< $(CFLAGS) 

# build executable

$(EXE): $(OBJ)
	$(CXX) $(CFLAGS) $(OBJ) -o $(EXE) $(LOADLIBES)

# clean up compilation

clean:
	rm -f $(OBJ) $(EXE)

# dependencies

#qtree:  main.o quadtree_functions.o 
main.o: main.cpp Node.o
Node.o: Node.cpp Node.hpp
LinkedList.o: LinkedList.cpp LinkedList.hpp
