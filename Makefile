#The Compiler:
CC = g++

#The Compiler Flags:
CFLAGS = -g -Wall

#The Title of The exe file:
TARG = ProjectOne.exe

#The Source Code:
SRC = src/main.cpp

#The path to the include files.
INCLUDES = -I./include

#The path to the libraries.
LFLAGS = -L./dep 

#The libraries.
LIBS = -lGL -lGLU -lGLEW -lglfw3 -lX11 -lXxf86vm -lXrandr -lpthread -lXi -ldl -lXinerama -lXcursor

#The Object files:
OBJ = main.o

.PHONY: clean
 
all: $(TARG)
	@echo Starting compilation.

$(TARG): $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(TARG) $(OBJ) $(LFLAGS) $(LIBS)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC) 

clean: 
	rm *.o
