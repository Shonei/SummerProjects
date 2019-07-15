
# code details

EXE_DIR = .
EXE = $(EXE_DIR)/main

SRC= main.cpp Button.cpp RoundedRec.cpp

# generic build details

CC=      gcc
COPT=    -O
CXXFLAGS=  -g -Wall -std=c++11 
LOADLIBES=  -lsfml-graphics -lsfml-window -lsfml-system -lstdc++ -lm
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

run:
	./main

# dependencies
main.o:	main.cpp 
Button.o: Button.cpp Button.hpp
RoundedRec.o: RoundedRec.cpp RoundedRec.hpp
