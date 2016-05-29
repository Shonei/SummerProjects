
# code details

EXE_DIR = .
EXE = $(EXE_DIR)/main

SRC= main.cpp Rectangle.cpp

# generic build details

CC=      g++
COPT=    -O
CFLAGS=  -g -Wall
#-Wpedantic - too much C++ comment style errors

# compile to  object code

OBJ= $(SRC:.cpp=.o)

.c.o:
	$(CC) $(CFLAGS) $(COPT) -c -o $@ $< 

# build executable

$(EXE): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXE) -lsfml-graphics -lsfml-window -lsfml-system

# clean up compilation

clean:
	rm -f $(OBJ) $(EXE)

# dependencies

#qtree:  main.o quadtree_functions.o 
main.o:	main.cpp Rectangle.o
Rectangle.o: Rectangle.cpp 