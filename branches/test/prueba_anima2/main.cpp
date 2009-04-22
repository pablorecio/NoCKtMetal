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
  pantalla = SDL_SetVideoMode(480, 360, 24, SDL_HWSURFACE|SDL_DOUBLEBUF);
  if(pantalla == NULL) {
    cerr << "No se pudo establecer el modo de video: "
	 << SDL_GetError() << endl;
    exit(1);
  }

  cout << "pantalla iniciada" << endl;

  Uint32 **matriz_para_dibujar;
  matriz_para_dibujar= (Uint32**)malloc(sizeof(Uint32*)*48);
  for(Uint32 i=0; i<48; i++){
    matriz_para_dibujar[i] = (Uint32*)malloc(sizeof(Uint32)*36);
  }
  
  cout << "matriz creada" << endl;

  for(Uint32 i=0; i<48; i++){
    for(Uint32 j=0; j<36; j++){
      if(i < 24){
	if(j < 18)
	  matriz_para_dibujar[i][j]=0;
	else
	  matriz_para_dibujar[i][j]=1;
      }
      else{
	if(j < 18)
	  matriz_para_dibujar[i][j] = 2;
	else
	  matriz_para_dibujar[i][j] = 3;
      }
	 
    }
  }

  cout << "matriz inicializada" << endl;
  /*for(Uint32 i=0; i<5; i++){
    for(Uint32 j=0; j<5; j++)
      cout << matriz_para_dibujar[i][j] << endl;
      }*/

  Tile t1("../prueba_tiles/suelo.png");
  Tile t2("../prueba_tiles/piedra3.png");
  Tile t3("../prueba_tiles/tierra.png");
  Tile t4("../prueba_tiles/oscuro.png");

  cout << "tiles creados" << endl;
  
  Imagen i((Uint32)48, (Uint32)36, matriz_para_dibujar);
  
  cout << "imagen creada" << endl;

  i.relacionarTile(0,t1);
  i.relacionarTile(1,t2);
  i.relacionarTile(2,t3);
  i.relacionarTile(3,t4);

  cout << "tiles relacionados" << endl;

  i.dibujarFondo(5,0,pantalla);

  cout << "dibujado en pantalla" << endl;

  SDL_Flip(pantalla);

  cout << "sdl_flip" << endl;

  SDL_Event evento;
  Uint32 time0 = SDL_GetTicks();
  Uint32 time1;
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
  
  int x=0, y=0;

  for( ; ; ) {
    while(SDL_PollEvent(&evento)) {  
      if(evento.type == SDL_KEYDOWN) {
	SDL_FillRect(pantalla, NULL,SDL_MapRGB(pantalla->format, 0, 0, 0));
	switch(evento.key.keysym.sym){
	case SDLK_DOWN: 
	  y++; // title abajo
	  i.dibujarFondo(x,y,pantalla); break;
	case SDLK_UP: 
	  y--; // title arriba 
	  i.dibujarFondo(x,y,pantalla); break;
	case SDLK_RIGHT: 
	  x++; // title derecha
	  i.dibujarFondo(x,y,pantalla); break;
	case SDLK_LEFT: 
	  x--; // title izquierda
	  i.dibujarFondo(x,y,pantalla); break;
	default: break;
	}
	SDL_Flip(pantalla);
	
	if(evento.key.keysym.sym == SDLK_ESCAPE)
	  return 0;
      }
      if(evento.type == SDL_QUIT)
	return 0;
    }
  }


}
