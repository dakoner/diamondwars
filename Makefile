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
# For each source, let the compiler run the preprocessor with the -M and -MM
# options, which causes it to output a dependency suitable for make.
	for source in $(SOURCES) ; do \
	  $(CC) $(CPPFLAGS) -M -MM $$source | tee -a .depend ; \
	done

clean:
	rm -f *.o main