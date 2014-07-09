#ifndef _QT_GFX_H_
#define _QT_GFX_H_

#include <Qt/qapplication.h>
#include <Qt/q3canvas.h>
#include <Qt3Support/Q3CanvasItem>

#include "constants.h"

#include <unistd.h>

class QtGFX: public GFX {
 public:
 QtGFX(): GFX(160, 128) {
    int argc = 1;
    char *argv[1];
    argv[0] = "qtapp";
    a = new QApplication( argc, argv );
    c = new Q3Canvas( width(), height() );
    c->setBackgroundColor(Qt::black);
    cv = new Q3CanvasView( c );
    cv->show();
  }

  void clear() {
  }

  void draw() {
    std::cout << "draw" << std::endl;
    c->update();
    a->processEvents();
    usleep(25000);
    Q3CanvasItemList items = c->allItems();
    for (QLinkedList<Q3CanvasItem*>::iterator item = items.begin(); item != items.end(); ++item) {
      delete *item;
    }
  }

  void stroke(char r, char g, char b) {
    strokeR = r;
    strokeG = g;
    strokeB = b;
  }
  void fill(char r, char g, char b) {
    fillR = r;
    fillG = g;
    fillB = b;
  }
  void point(int x, int y) {
    Q3CanvasRectangle *r = new Q3CanvasRectangle( x, y, 1, 1, c );
    r->setPen( QPen(Qt::white ));
    r->setBrush( Qt::red );
    r->show();
  }
  void rect(int x1, int y1, int x2, int y2) {
    Q3CanvasRectangle *r = new Q3CanvasRectangle( x1, y1, x2, y2, c );
    r->setPen( QPen(Qt::white ));
    r->setBrush( Qt::red );
    r->show();
  }
  void line(int x1, int y1, int x2, int y2) {
    Q3CanvasLine *l =  new Q3CanvasLine(c);
    l->setPoints(x1, y1, x2, y2);
    l->setPen( QPen(Qt::white ));
    l->setBrush( Qt::red );
    l->show();
  }

 private:
  QApplication *a;
  Q3Canvas *c;
  Q3CanvasView *cv;
  char strokeR;
  char strokeG;
  char strokeB;
  char fillR;
  char fillG;
  char fillB;
};


#endif
