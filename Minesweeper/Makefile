
# code details

EXE_DIR = .
EXE = $(EXE_DIR)/main

SRC= Block.cpp main.cpp Game.cpp

# generic build details

CXX=      g++
COPT=    -O
CXXFLAGS=  -g -Wall -std=c++11
LOADLIBES=  -lsfml-graphics -lsfml-window -lsfml-system -lstdc++
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

#main: main.o Block.o Game.o
main.o:  Game.o Game.hpp
#Game.o: Block.o Game.cpp Graphics.hpp
Block.o: Block.hpp Block.cpp

