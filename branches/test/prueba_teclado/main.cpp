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

    // Creamos animaciones para llenar la pantalla

    Animacion animacion("./dentacos.png", 4, 4,"4,5,6,7", 120);  
    Animacion animacion1("./dentacos.png", 4, 4,"12,13,14,15", 120);  
    Animacion animacion2("./dentacos.png", 4, 4,"8,9,10,11", 120);  
    Animacion animacion3("./dentacos.png", 4, 4,"0,1,2,3", 120); 
    
    // animacion.animar(pantalla, 100, 100);


    // Variables auxiliares

    SDL_Event evento;

    // Para controlar el tiempo

    Uint32 t0 = SDL_GetTicks();
    Uint32 t1;

    // número de pasos e intervalo de reposo para el movimiento del muñeco
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

    
    // Bucle "infinito"
    
    int x = 4, y = 4;

    for( ; ; ) {

	// El muñeco COMPLETO no se sale de la pantalla.

	if(x > 452)
	  x = 452;
	else if(x < 0)
	  x = 0;
	if(y > 308)
	  y = 308;
	else if(y < 0)
	  y = 0;

	// Referencia de tiempo

	t1 = SDL_GetTicks();
	
	if((t1 - t0) > animacion.retardo()) {
	  t0 = SDL_GetTicks();
	}

	
	// Control de la entrada

	while(SDL_PollEvent(&evento)) {
	  cout << "coordenadas: (" << x << "," << y << ")." << endl;
	    
	    if(evento.type == SDL_KEYDOWN) {
	      SDL_FillRect(pantalla, NULL,			\
			   SDL_MapRGB(pantalla->format, 0, 0, 0));
	      switch(evento.key.keysym.sym){
	      case SDLK_DOWN: 
		y+=4; // title abajo
		animacion3.paso_a_paso(pantalla, x,y); break;
	      case SDLK_UP: 
		y-=4; // title arriba 
		animacion1.paso_a_paso(pantalla, x,y); break;
	      case SDLK_RIGHT: 
		x+=4; // title derecha
		animacion2.paso_a_paso(pantalla,x,y); break;
	      case SDLK_LEFT: 
		x-=4; // title izquierda
		animacion.paso_a_paso(pantalla,x,y); break;
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
