#include "gameduino_ui.h"
#include "plotter_class.h"
#include <SPI.h>


#define min(arg1,arg2) (arg1<arg2 ? arg1 : arg2)
 
#define max(arg1,arg2) (arg1>arg2 ? arg1 : arg2)

#include <GD.h>

GameduinoUI::GameduinoUI(): UI(400, 300) {
  GD.begin();
  GD.ascii();
  GD.putstr(0, 0, "This is a test");
  Plotter.begin();
}

void GameduinoUI::clear() {
}

void GameduinoUI::draw() {
  char str[100];
  snprintf(str, 100, "%uld", millis());
  GD.putstr(0, 0, str);
  Plotter.line(0, 0, 100, 50);
  Plotter.show();
}

void GameduinoUI::stroke(char r, char g, char b) {
  strokeR = r;
  strokeG = g;
  strokeB = b;
}
void GameduinoUI::fill(char r, char g, char b) {
  fillR = r;
  fillG = g;
  fillB = b;
}
void GameduinoUI::point(int x, int y) {
}
void GameduinoUI::rect(int x1, int y1, int x2, int y2) {
}
void GameduinoUI::line(int x1, int y1, int x2, int y2) {
  Plotter.line(x1, y1, x2, y2);
}
void GameduinoUI::text(int x, int y, std::string text) {
}
