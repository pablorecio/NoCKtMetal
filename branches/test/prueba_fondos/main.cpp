

// Listado: main.cpp
//
// Programa de prueba de la clase Imagen

#include <iostream>
#include <SDL/SDL.h>

#include "imagen.h"

using namespace std;

int main () {

  if(SDL_Init(SDL_INIT_VIDEO) < 0) {
    cerr << "No se pudo iniciar SDL: " << SDL_GetError() << endl;
    exit(1);
  }


  atexit(SDL_Quit);
  if(SDL_VideoModeOK(480, 360, 24, SDL_HWSURFACE|SDL_DOUBLEBUF) == 0) {
    cerr << "Modo no soportado: " << SDL_GetError() << endl;
    exit(1);
  }

  SDL_Surface *pantalla;
  pantalla = SDL_SetVideoMode(640, 480, 24, SDL_HWSURFACE|SDL_DOUBLEBUF);
  if(pantalla == NULL) {
    cerr << "No se pudo establecer el modo de video: "
	 << SDL_GetError() << endl;
    exit(1);
  }

  Imagen i;
  i.inicializar(pantalla);
  i.dibujarFondo1();

  SDL_Flip(pantalla);

  SDL_Event evento;
  
  for( ; ; ) {
    while(SDL_PollEvent(&evento)) {  
      if(evento.type == SDL_KEYDOWN) {
	if(evento.key.keysym.sym == SDLK_ESCAPE)
	  return 0;
      }
      if(evento.type == SDL_QUIT)
	return 0;
    }
  }

}
