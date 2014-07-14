#include <Arduino.h>
#include <stdlib.h>
#include <pnew.cpp>

#include <SPI.h>
#include <GD.h>

#include "constants.h"
#include "env.h"
#include "gameduino_ui.h"
#include "dummy_joystick.h"

void setup() {
  constants = new Constants();
  ui = new GameduinoUI();
  joystick = new DummyJoystick();
  env = new Env();
}


void loop() {
  env->loop();
  // delay(100);
}
