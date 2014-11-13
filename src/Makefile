CC = g++
CFLAGS = -Wall -g -std=c++0x
INCLUDES = -I./ -I./effects
LFLAGS = -v
LIBRARIES = 
SOURCES = spec.cpp effects/Rain.cpp effects/Effect.cpp Cube.cpp Asserter.cpp effects/EffectTest.cpp CubeTest.cpp
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
	$(RM) *.o *~ $(MAIN)

depend: $(SRCS)
	makedepend $(INCLUDES) $^

# DO NOT DELETE THIS LINE -- make depend needs it
