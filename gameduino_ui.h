#ifndef _GAMEDUINO_UI_H_
#define _GAMEDUINO_UI_H_
#include "ui.h"

#include "constants.h"

#include <unistd.h>

class GameduinoUI: public UI {
public:
  GameduinoUI();

  void clear();

  void draw();

  void stroke(int r, int g, int b);
  void fill(int r, int g, int b);
  void point(int x, int y);
  void rect(int x1, int y1, int x2, int y2);
  void line(int x1, int y1, int x2, int y2);
  void text(int x, int y, std::string text);

private:
  int strokeR;
  int strokeG;
  int strokeB;
  int fillR;
  int fillG;
  int fillB;
};


#endif
