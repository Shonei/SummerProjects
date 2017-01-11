
# code details

EXE_DIR = .
EXE = $(EXE_DIR)/main

SRC= Block.cpp main.cpp Grid.cpp Game.cpp OptionsMenu.cpp 

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

main.o: main.hpp main.cpp
Game.o: Game.cpp Game.hpp
Grid.o: Grid.cpp Grid.hpp
Block.o: Block.hpp Block.cpp
OptionsMenu.o: OptionsMenu.cpp OptionsMenu.hpp SingleOption.hpp



