CXXFLAGS=-std=c++11 -g -I/usr/include/qt4
LOADLIBES=-lQtCore -lQtGui
SOURCES=qt_main.cpp enemy.cpp constants.cpp env.cpp vec2.cpp random.cpp ui.cpp collision.cpp world.cpp ship.cpp qt_joystick.cpp joystick.cpp qt_ui.cpp diamond.cpp star.cpp
OBJECTS = $(SOURCES:.cpp=.o)
all: diamondwars

include .depend

diamondwars: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LOADLIBES)

.depend: $(SOURCES)
	rm -f .depend
	$(CC) $(CPPFLAGS) -M -MM $(SOURCES) > .depend ; \

clean:
	rm -f *.o diamondwars *~