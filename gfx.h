#ifndef _GFX_H_
#define _GFX_H_

#include "constants.h"


class GFX {
  public:
 GFX(int width, int height): _width(width), _height(height) {
  }

  virtual void stroke(char r, char g, char b) = 0;
  virtual void fill(char r, char g, char b) = 0;
  virtual void point(int x, int y) = 0;
  virtual void rect(int x1, int y1, int x2, int y2) = 0;
  virtual void line(int x1, int y1, int x2, int y2) = 0;

  virtual int width() { return _width; }
  virtual int height() { return _height; }

 private:
  int _width;
  int _height;

};

extern GFX *gfx;
#endif
