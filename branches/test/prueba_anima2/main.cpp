
#include<iostream>
#include"animacion2.h"

using namespace std;

int main (){

  if(SDL_Init(SDL_INIT_VIDEO) < 0) {
    cerr << "No se pudo iniciar SDL: " << SDL_GetError() << endl;
    exit(1);
  }
  
  if(SDL_VideoModeOK(480, 360, 24, SDL_HWSURFACE|SDL_DOUBLEBUF) == 0) {
    cerr << "Modo no soportado: " << SDL_GetError() << endl;
    exit(1);
  }

  Pantalla p;
  p.setTitulo("prueba_motor", "logo.png");
  
  Animacion a(p);
  a.iniciarAnimacion("fich_fondo.dat","baldos.png");
  
  
  SDL_Event evento;
  int repeat = SDL_EnableKeyRepeat(10,100);
  if(repeat < 0) {
    cerr << "No se pudo establecer el modo repetición "
	 << SDL_GetError() << endl;
    exit(1);
  }
  else {
    cout << "Modo repetición activado:\n "
	 << " Retardo: " << SDL_DEFAULT_REPEAT_DELAY
	 << "\nIntervalo: " <<SDL_DEFAULT_REPEAT_INTERVAL << endl;
  }

  for( ; ; ) {
    while(SDL_PollEvent(&evento)) {  
      if(evento.type == SDL_KEYDOWN) {
	switch(evento.key.keysym.sym){
	case SDLK_DOWN: 
	  a.realizarMovimiento('d'); break;
	case SDLK_UP: 
	  a.realizarMovimiento('u'); break;
	case SDLK_RIGHT: 
	  a.realizarMovimiento('d'); break;
	case SDLK_LEFT: 
	  a.realizarMovimiento('l'); break;
	default: break;
	}
	
	if(evento.key.keysym.sym == SDLK_ESCAPE)
	  return 0;
      }
      if(evento.type == SDL_QUIT)
	return 0;
    }
  }
  
}
