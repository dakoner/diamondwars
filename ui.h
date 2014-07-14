#ifndef _UI_H_
#define _UI_H_
#include <iterator>
#include <string>

#include "constants.h"


class UI {
  public:
 UI(int width, int height): _width(width), _height(height) {
  }
  virtual void clear() = 0;
  virtual void draw() = 0;

  virtual void stroke(char r, char g, char b) = 0;
  virtual void fill(char r, char g, char b) = 0;
  virtual void point(int x, int y) = 0;
  virtual void rect(int x1, int y1, int x2, int y2) = 0;
  virtual void line(int x1, int y1, int x2, int y2) = 0;
  virtual void text(int x, int y, std::string t) = 0;

  virtual int width() { return _width; }
  virtual int height() { return _height; }

 private:
  int _width;
  int _height;

};

extern UI *ui;
#endif
