#ifndef _LOGGING_UI_H_
#define _LOGGING_UI_H_

#include <iostream>
#include "constants.h"


class LoggingUI: public UI {
 public:
 LoggingUI(): UI(256, 256) {
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

};


#endif
