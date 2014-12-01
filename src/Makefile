CC = g++
CFLAGS = -Wall -g -std=c++0x
INCLUDES = -I./ -I./effect -I./spec -I./core -I./util -I./lib
LFLAGS =
LIBRARIES = 
SOURCES = \
  Arduino.cpp \
  core/Cube.cpp \
  core/Point.cpp \
  core/BitmapFont.cpp \
  core/TextRender.cpp \
  effect/Effect.cpp \
  effect/Blink.cpp \
  effect/BoingBoing.cpp \
  effect/BoxShrinkGrow.cpp \
  effect/BoxWoopWoop.cpp \
  effect/FlowingBox.cpp \
  effect/GameOfLife.cpp \
  effect/MovingBoxShrinkGrow.cpp \
  effect/Rain.cpp \
  effect/RandomSparkle.cpp \
  effect/Ripples.cpp \
  effect/Stairs.cpp \
  effect/Suspend.cpp \
  effect/TurnOnRandomly.cpp \
  effect/UpDown.cpp \
  effect/WormSqueeze.cpp \
  spec.cpp \
  spec/Asserter.cpp \
  spec/PointSpec.cpp \
  spec/CubeSpec.cpp \
  spec/EffectSpec.cpp \
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
	$(RM) *.o *~ effect/*.o effect/*~ util/*.o util/*~ core/*.o core/*~ spec/*.o spec/*~ $(MAIN)

depend: $(SRCS)
	makedepend $(INCLUDES) $^

# DO NOT DELETE THIS LINE -- make depend needs it
