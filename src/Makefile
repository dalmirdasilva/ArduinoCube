CC = g++
CFLAGS = -Wall -g
INCLUDES = -I./
LFLAGS = 
LIBRARIES = 
SOURCES = main.cpp Cube.cpp Drawer.cpp DrawerTest.cpp SpecHelper.cpp
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
