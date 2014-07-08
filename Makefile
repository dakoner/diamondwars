CXXFLAGS=-std=c++11 -g
LOADLIBES=-lSDL2
SOURCES=main.cpp enemy.cpp constants.cpp env.cpp vec2.cpp random.cpp gfx.cpp input.cpp collision.cpp
OBJECTS = $(SOURCES:.cpp=.o)
all: main

include .depend

main: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LOADLIBES)

.depend: $(SOURCES)
	rm -f .depend
	$(CC) $(CPPFLAGS) -M -MM $(SOURCES) > .depend ; \

clean:
	rm -f *.o main