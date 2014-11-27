CC = g++
CFLAGS = -Wall -g -std=c++0x
INCLUDES = -I./ -I./effects -I./spec -I./core -I./util
LFLAGS =
LIBRARIES = 
SOURCES = \
  Arduino.cpp \
  core/Cube.cpp \
  core/Point.cpp \
  effects/Effect.cpp \
  effects/Rain.cpp \
  effects/Blink.cpp \
  effects/UpDown.cpp \
  effects/GameOfLife.cpp \
  effects/TurnOnRandomly.cpp \
  effects/EffectSpec.cpp \
  spec.cpp \
  spec/Asserter.cpp \
  spec/PointSpec.cpp \
  spec/CubeSpec.cpp \
  util/Dumper.cpp \
  util/Util.cpp

OBJECTS = $(SOURCES:.cpp=.o)
MAIN = spec_bin

.PHONY: depend clean

all: $(MAIN)
	@echo  Arduino Cube

$(MAIN): $(OBJECTS) 
	$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJECTS) $(LFLAGS) $(LIBRARIES)

.cpp.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) *.o *~ effects/*.o effects/*~ util/*.o util/*~ core/*.o core/*~ spec/*.o spec/*~ $(MAIN)

depend: $(SRCS)
	makedepend $(INCLUDES) $^

# DO NOT DELETE THIS LINE -- make depend needs it
