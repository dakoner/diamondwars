#ifndef _SDL_GFX_H_
#define _SDL_GFX_H_
#include <iostream>

#include "SDL2/SDL.h"
#include "SDL2/SDL_video.h"

#include "constants.h"
#include "gfx.h"

class SDLGFX: public GFX {
  public:
  SDLGFX(): GFX(160, 128) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0){
      std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
      exit(1);
    }
    win = SDL_CreateWindow("Hello World!", 100, 100, width(), height(),
                            SDL_WINDOW_SHOWN);
    if (win == NULL) {
      std::cerr << "SDL_CreateWndow Error: " << SDL_GetError() << std::endl;
      exit(1);

    }
    ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_SOFTWARE);
    if (ren == NULL) {
      std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
      exit(1);
    }
    SDL_Surface *screenSurface = SDL_GetWindowSurface( win );
    if (screenSurface == NULL) {
      std::cerr << "SDL_GetWindowSurface Error: " << SDL_GetError() << std::endl;
      exit(1);
    }

    //Fill the surface white
    SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );

    //Update the surface
    SDL_UpdateWindowSurface( win );

    //Wait two seconds
    SDL_Delay( 2000 );
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
  }
  void rect(int x1, int y1, int x2, int y2) {
  }
  void line(int x1, int y1, int x2, int y2) {
  }

 private:
  SDL_Window *win;
  SDL_Renderer *ren;
  char strokeR;
  char strokeG;
  char strokeB;
  char fillR;
  char fillG;
  char fillB;
};
#endif
