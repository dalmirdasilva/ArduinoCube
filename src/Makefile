CC = g++
CFLAGS = -Wall -g -std=c++0x
INCLUDES = -I./ -I./effects
LFLAGS =
LIBRARIES = 
SOURCES = \
  Arduino.cpp \
  spec.cpp \
  effects/Rain.cpp \
  effects/Blink.cpp \
  effects/UpDown.cpp \
  effects/GameOfLife.cpp \
  effects/Effect.cpp \
  Cube.cpp \
  Asserter.cpp \
  effects/EffectTest.cpp \
  CubeTest.cpp \
  Util.cpp

OBJECTS = $(SOURCES:.cpp=.o)
MAIN = spec

.PHONY: depend clean

all: $(MAIN)
	@echo  Arduino Cube

$(MAIN): $(OBJECTS) 
	$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJECTS) $(LFLAGS) $(LIBRARIES)

.cpp.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) *.o *~ effects/*.o effects/*~ $(MAIN)

depend: $(SRCS)
	makedepend $(INCLUDES) $^

# DO NOT DELETE THIS LINE -- make depend needs it
