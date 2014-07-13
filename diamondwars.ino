#include <Esplora.h>
#include <TFT.h>
#include <SPI.h>

#include <pnew.cpp>

#include "constants.h"
#include "env.h"
#include "arduino_gfx.h"
#include "arduino_input.h"

void setup() {
  constants = new Constants();
  gfx = new ArduinoGFX();
  env = new Env();
  joystick = new ArduinoJoystick();
}


void loop() {
  env->loop();
  delay(50);
}
