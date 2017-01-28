CC = g++
CFLAGS = -Wall -g -std=c++0x
INCLUDES = -I./ \
  -I./emulate \
  -I./effect \
  -I./spec \
  -I./core \
  -I./util \
  -I./lib/InputStream \
  -I./lib/ByteArrayInputStream \
  -I./lib/ByteArraySeekableInputStream \
  -I./lib/SeekableInputStream \
  -I./lib/Seekable \
  -I./lib/Closeable
LFLAGS =
LIBRARIES = 
SOURCES = \
  emulate/Arduino.cpp \
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
  effect/ShiftingText.cpp \
  emulate/spec.cpp \
  spec/Asserter.cpp \
  spec/PointSpec.cpp \
  spec/CubeSpec.cpp \
  spec/EffectSpec.cpp \
  spec/BitmapFontSpec.cpp \
  util/Dumper.cpp \
  util/Util.cpp \
  lib/InputStream/InputStream.cpp \
  lib/ByteArrayInputStream/ByteArrayInputStream.cpp \
  lib/ByteArraySeekableInputStream/ByteArraySeekableInputStream.cpp

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
	find . -type f -name "*.o" -exec $(RM) {} \;
	$(RM) $(MAIN)

depend: $(SRCS)
	makedepend $(INCLUDES) $^

# DO NOT DELETE THIS LINE -- make depend needs it
