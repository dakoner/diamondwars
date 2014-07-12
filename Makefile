CXXFLAGS=-std=c++11 -g -I/usr/include/qt4
LOADLIBES=-lSDL2 -lQt3Support -lQtCore -lQtGui
SOURCES=main.cpp enemy.cpp constants.cpp env.cpp vec2.cpp random.cpp ui.cpp collision.cpp world.cpp ship.cpp qt_joystick.cpp joystick.cpp
OBJECTS = $(SOURCES:.cpp=.o)
all: main

include .depend

main: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LOADLIBES)

.depend: $(SOURCES)
	rm -f .depend
	$(CC) $(CPPFLAGS) -M -MM $(SOURCES) > .depend ; \

clean:
	rm -f *.o main *~