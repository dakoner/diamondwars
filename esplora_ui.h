#ifndef _ARDUINO_UI_H_
#define _ARDUINO_UI_H_

#include <Esplora.h>
#include <TFT.h>
#include <SPI.h>

#include <iterator>
#include <string>
#include "ui.h"

class EsploraUI: public UI {
  public:
  EsploraUI();

  void clear();
  void draw();

  void text(int x, int y, std::string t);

  void stroke(int r, int g, int b);
  void fill(int r, int g, int b);

  void point(int x, int y);
  void rect(int x1, int y1, int x2, int y2);
  void line(int x1, int y1, int x2, int y2);

};
#endif
