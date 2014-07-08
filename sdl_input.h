#ifndef _SDL_INPUT_H_
#define _SDL_INPUT_H_

#include <iostream>
#include "SDL2/SDL.h"
#include "input.h"

class SDLJoystick: public Joystick {
  bool readButton(unsigned char channel) {
    SDL_PumpEvents();
    return !SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT);
  }
  int readJoystickX() {
    SDL_PumpEvents();
    int x;
    SDL_GetMouseState(&x, NULL);
    x= int((x-gfx->width()/2) / float(gfx->width()) * 25);
    return x;
  }

  int readJoystickY() {
    SDL_PumpEvents();
    int y;
    SDL_GetMouseState(NULL, &y);

    
    y =  int((y-gfx->width()/2) / float(gfx->height()) * 25);
    return y;
  }
};

#endif
