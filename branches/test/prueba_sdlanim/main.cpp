// Listado: main.cpp
//
// Programa de prueba de la clase Imagen

#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "Animacion.h"

#define TAM_X 480
#define TAM_Y 360

using namespace std;

int main() {
  
  // Iniciamos el subsistema de video
  if(SDL_Init(SDL_INIT_VIDEO) < 0) {
    
    cerr << "No se pudo iniciar SDL: " << SDL_GetError() << endl;
    exit(1);	
  }
  
  atexit(SDL_Quit);
  
  // Comprobamos que sea compatible el modo de video
  if(SDL_VideoModeOK(TAM_X, TAM_Y, 24, SDL_HWSURFACE|SDL_DOUBLEBUF) == 0) {
    cerr << "Modo no soportado: " << SDL_GetError() << endl;
    exit(1);
  }
  
  
  // Establecemos el modo de video
  SDL_Surface *pantalla;
  
  pantalla = SDL_SetVideoMode(TAM_X, TAM_Y, 24, SDL_HWSURFACE|SDL_DOUBLEBUF);
  
  if(pantalla == NULL) {
    cerr << "No se pudo establecer el modo de video: "
	 << SDL_GetError() << endl;
    exit(1);
  }
  
  // Suelo
  SDL_Surface *temp, *grass;
  
  temp  = SDL_LoadBMP("grass.bmp");
  grass = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);
  
  /* Repeticion del teclado */
  SDL_EnableKeyRepeat(70, 70);
  
  // Creamos animaciones para llenar la pantalla
  Animacion animacion("./dentacos.png", 4, 4,"4,5,6,7,6,5,4", 120);
  Animacion an_izda("./dentacos.png", 4, 4,"4,5,6,7,6,5,4", 120);  
  //Animacion an_("./dentacos.png", 4, 4,"0,4,8,12,8,4,0", 120);  
  //Animacion animacion2("./dentacos.png", 4, 4,"4,5,6,7,6,5,4", 120);  
  Animacion an_abajo("./dentacos.png", 4, 4,"0,1,2,3,2,1,0", 120);   
  Animacion an_dcha("./dentacos.png", 4, 4,"8,9,10,11,10,9,8", 120);   
  Animacion an_arriba("./dentacos.png", 4, 4,"12,13,14,15,14,13,12", 120); 
  
  // animacion.animar(pantalla, 100, 100);
  an_abajo.animar(pantalla, 150, 150);
  
  // Variables auxiliares
  SDL_Event evento;

  // Para controlar el tiempo
  Uint32 t0 = SDL_GetTicks();
  Uint32 t1;
  
  // Bucle "infinito"
  bool gameover = false;
  for(int x = 0, y = 0; !gameover; ) {
    
    // Si se sale de la pantalla volvemos a introducirlo
      
    if(x == TAM_X)
      x = 0;
    if(y == TAM_Y)
      y = 0;
      
    /* Pintar el cesped */
    for (int x = 0; x < TAM_X / 32; x++) {
      for (int y = 0; y < TAM_Y / 32; y++) {
	rcGrass.x = x * 32;
	rcGrass.y = y * 32;
	SDL_BlitSurface(grass, NULL, pantalla, &rcGrass);
      }
    }
    
    
    // Referencia de tiempo
    t1 = SDL_GetTicks();
    
    if((t1 - t0) > animacion.retardo()) {
      
      // Nueva referencia de tiempo
      t0 = SDL_GetTicks();
      
      // Movimiento del personaje
      x += 4;
      
      // Limpiamos la pantalla
      // Sería mejor limpiar el anterior
      SDL_FillRect(pantalla, NULL,				\
		   SDL_MapRGB(pantalla->format, 0, 0, 0));
      
      // Mostramos el siguiente paso de todas las animaciones
      /*
	if(x % 16 == 0)
	animacion.paso_a_paso(pantalla, x, y,-1);
	else{
	y += 4;
	animacion3.paso_a_paso(pantalla,x,y);
	}
      */
      //animacion1.paso_a_paso(pantalla, 200, 300);
      //animacion2.paso_a_paso(pantalla, 300, 300);
    }
    
    // Control de la entrada
    while(SDL_PollEvent(&evento)) {
      if(evento.type == SDL_KEYDOWN) {
	switch (evento.key.keysym.sym) {
	case SDLK_ESCAPE:
	  return 0;
	case SDLK_q:
	  gameover = true;
	  break;
	case SDLK_LEFT:
	  an_izda.paso_a_paso(pantalla, x, y);
	  break;
	case SDLK_RIGHT:
	  an_dcha.paso_a_paso(pantalla, x, y);
	  break;
	case SDLK_UP:
	  an_arriba.paso_a_paso(pantalla, x, y);
	  break;
	case SDLK_DOWN:
	  an_abajo.paso_a_paso(pantalla, x, y);
	  break;
	default:
	  break;
	}
      }
      if(evento.type == SDL_QUIT)
	return 0;	    
    }
  }
}
