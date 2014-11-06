CC = g++
CFLAGS = -Wall -g -std=c++0x
INCLUDES = -I./
LFLAGS = 
LIBRARIES = 
SOURCES = main.cpp Cube.cpp Drawer.cpp CubeTest.cpp Asserter.cpp
OBJECTS = $(SOURCES:.cpp=.o)
MAIN = main

.PHONY: depend clean

all: $(MAIN)
	@echo  Arduino Cube

$(MAIN): $(OBJECTS) 
	$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJECTS) $(LFLAGS) $(LIBRARIES)

.cpp.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) *.o *~ $(MAIN)

depend: $(SRCS)
	makedepend $(INCLUDES) $^

# DO NOT DELETE THIS LINE -- make depend needs it
