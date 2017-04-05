#The Compiler:
CC = g++

#The Compiler Flags:
CFLAGS = -g -Wall

#The Title of The exe file:
TARG = ProjectOne.exe

#The Source Code:
SRC = src/main.cpp

#The lib dependencies:
LIB = glfw3

#The Object files:
OBJ = main.o
 
all: $(OBJ)
	$(CC) $(CFLAGS) -o $(TARG) $(OBJ) -L. -l$(LIB)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)

clean: 
	rm *.o
