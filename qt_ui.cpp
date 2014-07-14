#include <iostream>
#ifndef ARDUINO
#include "qt_ui.h"
#include <QtGui/QMainWindow>
QtUI::QtUI(): UI(640, 480) {
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
  view->showFullScreen();
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

void QtUI::stroke(int r, int g, int b) {
  _stroke = QPen(QColor(r, g, b, 255));
}
void QtUI::fill(int r, int g, int b) {
  _fill = QBrush(QColor(r, g, b, 255));
}
void QtUI::point(int x, int y) {
  QGraphicsRectItem *r = scene->addRect( x, y, 1, 1);
  r->setPen(_stroke);
  r->setBrush( _fill );
  r->show();
}
void QtUI::rect(int x1, int y1, int x2, int y2) {
  QGraphicsRectItem *r = scene->addRect(x1, y1, x2, y2);
  r->setPen(_stroke);
  r->setBrush( _fill );
  r->show();
}
void QtUI::line(int x1, int y1, int x2, int y2) {
  QGraphicsLineItem *l =  scene->addLine(x1, y1, x2, y2);
  l->setPen(_stroke);
  l->show();
}
void QtUI::text(int x, int y, std::string text) {
  QGraphicsTextItem *t =  scene->addText(text.c_str());
  t->setPos(x, y);
  // t->setDefaultTextColor( _fill.color() );
  t->show();
}
#endif
