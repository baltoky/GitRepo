#The Compiler:
CC = g++

#The Compiler Flags:
CFLAGS = -std=c++11 -g -Wall

#The Title of The exe file:
TARG = ProjectOne.exe

#The Source Code:
SRC = src/main.cpp src/graphics/Window.cpp src/graphics/shader/shader.cpp src/graphics/shader/shaderProgram.cpp src/graphics/image2D/Texture.cpp src/graphics/image2D/GraphicsData.cpp

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
	@echo Compiling $<.

clean: 
	cd src/ ; rm *.o ; cd ..
	cd src/graphics/ ; rm *.o ; cd ../..
	cd src/graphics/image2D ; rm *.o ; cd ../../..
	cd src/shader/ ; rm *.o ; cd ../..
