#ifndef ARDUINO
#include "qt_ui.h"

QtUI::QtUI(): UI(160, 128) {
  int argc = 1;
  char *argv[1];
  argv[0] = "qtapp";
  a = new QApplication( argc, argv );
  scene = new QGraphicsScene();
  view = new QGraphicsView(scene);
  view->setBackgroundBrush(QBrush(Qt::black));
  view->resize(width(), height());
  view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  view->show();
}

QGraphicsView* QtUI::getGraphicsView() {
  return view;
}

void QtUI::clear() {
}

void QtUI::draw() {
  a->processEvents();
  /* usleep(500); */
  scene->clear();
}

void QtUI::stroke(char r, char g, char b) {
  strokeR = r;
  strokeG = g;
  strokeB = b;
}
void QtUI::fill(char r, char g, char b) {
  fillR = r;
  fillG = g;
  fillB = b;
}
void QtUI::point(int x, int y) {
  QGraphicsRectItem *r = scene->addRect( x, y, 1, 1);
  r->setPen( QPen(Qt::white ));
  r->setBrush( Qt::red );
  r->show();
}
void QtUI::rect(int x1, int y1, int x2, int y2) {
  QGraphicsRectItem *r = scene->addRect(x1, y1, x2, y2);
  r->setPen( QPen(Qt::white ));
  r->setBrush( Qt::red );
  r->show();
}
void QtUI::line(int x1, int y1, int x2, int y2) {
  QGraphicsLineItem *l =  scene->addLine(x1, y1, x2, y2);
  l->setPen( QPen(Qt::white ));
  l->show();
}
void QtUI::text(int x, int y, std::string text) {
  QGraphicsTextItem *t =  scene->addText(text.c_str());
  t->setPos(x, y);
  // t->setTextFlags( Qt::AlignHCenter );
  t->setDefaultTextColor( Qt::red );
  t->show();
}
#endif
