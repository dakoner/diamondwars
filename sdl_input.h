#ifndef _SDL_INPUT_H_
#define _SDL_INPUT_H_

#include <iostream>
#include "SDL2/SDL.h"


class SDLJoystick: public Joystick {
  bool readButton(unsigned char channel) {
    SDL_PumpEvents();
    return !SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT);
  }
  int readJoystickX() {
    SDL_PumpEvents();
    int x;
    SDL_GetMouseState(&x, NULL);
    x= int((x-ui->width()/2) / float(ui->width()) * 25);
    return x;
  }

  int readJoystickY() {
    SDL_PumpEvents();
    int y;
    SDL_GetMouseState(NULL, &y);

    
    y =  int((y-ui->width()/2) / float(ui->height()) * 25);
    return y;
  }
};

#endif
