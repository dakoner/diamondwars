#include <Esplora.h>
#include <TFT.h>
#include <SPI.h>

#include <pnew.cpp>

#include "constants.h"
#include "env.h"
#include "esplora_ui.h"
#include "esplora_joystick.h"

void setup() {
  constants = new Constants();
  ui = new EsploraUI();
  env = new Env();
  joystick = new EsploraJoystick();
}


void loop() {
  env->loop();
  delay(50);
}
