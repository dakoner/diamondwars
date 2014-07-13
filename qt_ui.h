#ifndef _QT_UI_H_
#define _QT_UI_H_
#include "ui.h"

#include <QtGui/QApplication>
#include <QtGui/QGraphicsView>
#include <QtGui/QGraphicsRectItem>
#include <QtGui/QGraphicsLineItem>
#include <QtGui/QBrush>


#include "constants.h"

#include <unistd.h>

class QtUI: public UI {
public:
  QtUI();

  QGraphicsView* getGraphicsView();

  void clear();

  void draw();

  void stroke(char r, char g, char b);
  void fill(char r, char g, char b);
  void point(int x, int y);
  void rect(int x1, int y1, int x2, int y2);
  void line(int x1, int y1, int x2, int y2);
  void text(int x, int y, std::string text);

private:
  QApplication *a;
  QGraphicsView *view;
  QGraphicsScene *scene;
  char strokeR;
  char strokeG;
  char strokeB;
  char fillR;
  char fillG;
  char fillB;
};


#endif
