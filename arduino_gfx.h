#ifndef _ARDUINO_GFX_H_
#define _ARDUINO_GFX_H_

#include <Esplora.h>
#include <TFT.h>
#include <SPI.h>

#include "constants.h"
#include "gfx.h"

class ArduinoGFX: public GFX {
  public:
 ArduinoGFX(): _width(EsploraTFT.width()), _height(EsploraTFT.height()) {
    EsploraTFT.begin();
    EsploraTFT.background(constants->backgroundColor.r(), constants->backgroundColor.g(), constants->backgroundColor.b());    
  }

  void stroke(char r, char g, char b) {
    EsploraTFT.stroke(r, g, b);
  }
  void fill(char r, char g, char b) {
    EsploraTFT.fill(r, g, b);
  }

  void point(int x, int y) {
    EsploraTFT.point(x, y);
  }
  void rect(int x1, int y1, int x2, int y2) {
    EsploraTFT.rect(x1, y1, x2, y2);
  }
  void line(int x1, int y1, int x2, int y2) {
    EsploraTFT.line(x1, y1, x2, y2);
  }

  int width() { return _width; }
  int height() { return _height; }

 private:
  int _width;
  int _height;

};
#endif
