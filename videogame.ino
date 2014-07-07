#include <Esplora.h>
#include <TFT.h>
#include <SPI.h>
#include <pnew.cpp>

#include "constants.h"
#include "env.h"

void setup() {
  constants = new Constants(EsploraTFT.width(), EsploraTFT.height());
  env = new Env();
  // initialize the display
  EsploraTFT.begin();
  EsploraTFT.background(constants->backgroundColor.r(), constants->backgroundColor.g(), constants->backgroundColor.b());
}


void loop() {
  env->loop();
  delay(50);
}
