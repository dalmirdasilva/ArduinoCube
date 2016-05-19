CC = g++
CFLAGS = -Wall  -g -std=c++0x 
INCLUDES = -I./ \
  -I./.. \
  -I./../effect \
  -I./../core \
  -I./../util \
  -I./../lib/InputStream \
  -I./../lib/ByteArrayInputStream \
  -I./../lib/ByteArraySeekableInputStream \
  -I./../lib/SeekableInputStream \
  -I./../lib/Seekable \
  -I./../lib/Closeable
LFLAGS =
LIBRARIES = -lGL -lglut -lGLU -lpthread 
SOURCES = \
  ./main.cpp \
  ./simulator.c \
  ../Arduino.cpp \
  ../core/Cube.cpp \
  ../core/Point.cpp \
  ../util/Dumper.cpp \
  ../util/Util.cpp

OBJECTS = $(SOURCES:.cpp=.o)
MAIN = simulator

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
