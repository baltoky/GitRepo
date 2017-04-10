#The Compiler:
CC = g++

#The Compiler Flags:
CFLAGS = -std=c++0x -g -Wall

#The Title of The exe file:
TARG = ProjectOne.exe

#The Source Code:
SRC = src/main.cpp src/Window.cpp

#The path to the include files.
INCLUDES = -I./include

#The path to the libraries.
LFLAGS = -L./dep 

#The libraries.
LIBS = -lGL -lGLU -lGLEW -lglfw3 -lX11 -lXxf86vm -lXrandr -lpthread -lXi -ldl -lXinerama -lXcursor

#The Object files:
OBJ = $(SRC:.cpp=.o)

.PHONY: clean
 
all: $(TARG)
	@echo Compilation Successful.

$(TARG): $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(TARG) $(OBJ) $(LFLAGS) $(LIBS)
	@echo Linking successful.

.cpp.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo Compiling $(SRC).

clean: 
	cd src/ ; rm *.o ; cd ..
