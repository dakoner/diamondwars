CXXFLAGS=-std=c++11 -g
main: main.cpp enemy.cpp constants.cpp env.cpp vec2.cpp random.cpp gfx.cpp input.cpp collision.cpp

clean:
	rm -f *.o main