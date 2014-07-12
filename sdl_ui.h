#ifndef _SDL_UI_H_
#define _SDL_UI_H_
#include <iostream>

#include "SDL2/SDL.h"
#include "SDL2/SDL_video.h"

#include "constants.h"
#include "ui.h"

class SDLUI: public UI {
  public:
  SDLUI(): UI(160, 128) {
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
    /* ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_SOFTWARE); */
    ren = SDL_CreateRenderer(win, -1, 0);
    if (ren == NULL) {
      std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
      exit(1);
    }
  }

  void clear() {
    SDL_Surface *screenSurface = SDL_GetWindowSurface( win );
    if (screenSurface == NULL) {
      std::cerr << "SDL_GetWindowSurface Error: " << SDL_GetError() << std::endl;
      exit(1);
    }

    //Fill the surface white
    SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format,
						   constants->backgroundColor.r(), 
						   constants->backgroundColor.g(), 
						   constants->backgroundColor.b())) ;

    //Update the surface
    SDL_UpdateWindowSurface( win );
  }

  void draw() {
    SDL_RenderPresent( ren );
    SDL_Delay(25);
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
    SDL_SetRenderDrawColor(ren, strokeR, strokeG, strokeB, 255);
    SDL_RenderDrawPoint(ren, x, y);
  }
  void rect(int x1, int y1, int x2, int y2) {
    SDL_SetRenderDrawColor(ren, strokeR, strokeG, strokeB, 255);
    SDL_Rect r;
    r.x = x1;
    r.y = y1;
    r.w = x2;
    r.h = y2;
    SDL_RenderDrawRect(ren, &r);
  }
  void line(int x1, int y1, int x2, int y2) {
    SDL_SetRenderDrawColor(ren, strokeR, strokeG, strokeB, 255);
    SDL_RenderDrawLine(ren, x1, y1, x2, y2);
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
