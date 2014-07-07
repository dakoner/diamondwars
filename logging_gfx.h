#ifndef _LOGGING_GFX_H_
#define _LOGGING_GFX_H_

#include <iostream>
#include "constants.h"


class LoggingGFX: public GFX {
 public:
 LoggingGFX(): _width(256), _height(256) {
  }

  void stroke(char r, char g, char b) {
    std::cout << "stroke: " << r << " " << g << " " << b << std::endl;
  }
  void fill(char r, char g, char b) {
    std::cout << "fill: " << r << " " << g << " " << b << std::endl;
  }
  void point(int x, int y) {
    std::cout << "point: " << x << " " << y << std::endl;
  }
  void rect(int x1, int y1, int x2, int y2) {
    std::cout << "rect: " << x1 << " " << y1 << " " << x2 << " " << y2 << std::endl;
  }
  void line(int x1, int y1, int x2, int y2) {
    std::cout << "line: " << x1 << " " << y1 << " " << x2 << " " << y2 << std::endl;
  }

  int width() { return _width; }
  int height() { return _height; }

 private:
  int _width;
  int _height;

};


#endif
