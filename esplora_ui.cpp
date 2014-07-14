#ifdef ESPLORA
#include "esplora_ui.h"
EsploraUI::EsploraUI(): UI(EsploraTFT.width(), EsploraTFT.height()) {
  EsploraTFT.begin();
  EsploraTFT.background(constants->backgroundColor.r(), constants->backgroundColor.g(), constants->backgroundColor.b());    
}

void EsploraUI::clear() { 
}
void EsploraUI::draw() {
}

void EsploraUI::text(int x, int y, std::string t) {
  EsploraTFT.text(t.c_str(), x, y);
}

void EsploraUI::stroke(char r, char g, char b) {
  EsploraTFT.stroke(r, g, b);
}
void EsploraUI::fill(char r, char g, char b) {
  EsploraTFT.fill(r, g, b);
}

void EsploraUI::point(int x, int y) {
  EsploraTFT.point(x, y);
}
void EsploraUI::rect(int x1, int y1, int x2, int y2) {
  EsploraTFT.rect(x1, y1, x2, y2);
}
void EsploraUI::line(int x1, int y1, int x2, int y2) {
  EsploraTFT.line(x1, y1, x2, y2);
}
#endif
