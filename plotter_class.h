#ifndef _PLOTTER_CLASS_H_
#define _PLOTTER_CLASS_H_

// byte
#include <Arduino.h>

#define BLACK RGB(0,0,0)
#define WHITE RGB(255,255,255)


class PlotterClass
{
public:
  void begin();
  void line(byte x0, byte y0, byte x1, byte y1);
  void show();
private:
  byte flip;
  byte plotting;
  void erase();
  void waitready();
};

extern PlotterClass Plotter;

#endif
