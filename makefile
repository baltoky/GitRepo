#The Compiler:
CC = g++

#The Compiler Flags:
CFLAGS = -g -Wall

#The Title of The exe file:
TARG = ProjectOne.exe

#The Source Code:
SRC = src/main.cpp

#The Object files:
OBJ = main.o
 
all: $(OBJ)
	$(CC) $(CFLAGS) -o $(TARG) $(OBJ)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)

clean: 
	rm *.o
