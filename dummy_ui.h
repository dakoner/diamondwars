#ifndef _LOGGING_UI_H_
#define _LOGGING_UI_H_

#include "constants.h"


class DummyUI: public UI {
 public:
 DummyUI(): UI(256, 256) {
  }

  void stroke(int r, int g, int b) {
  }
  void fill(int r, int g, int b) {
  }
  void point(int x, int y) {
  }
  void rect(int x1, int y1, int x2, int y2) {
  }
  void line(int x1, int y1, int x2, int y2) {
  }

};


#endif
