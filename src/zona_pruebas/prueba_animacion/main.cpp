// Listado: main.cpp
//
// Programa de prueba de la clase Imagen

#include <iostream>
#include <SDL/SDL.h>

#include "Animacion.h"

using namespace std;

int main() {


    // Iniciamos el subsistema de video

    if(SDL_Init(SDL_INIT_VIDEO) < 0) {

	cerr << "No se pudo iniciar SDL: " << SDL_GetError() << endl;
	exit(1);
	
    }


    atexit(SDL_Quit);

    // Comprobamos que sea compatible el modo de video
    
    if(SDL_VideoModeOK(640, 480, 24, SDL_HWSURFACE|SDL_DOUBLEBUF) == 0) {
	
        cerr << "Modo no soportado: " << SDL_GetError() << endl;
        exit(1);
	
    }


      // Establecemos el modo de video

    SDL_Surface *pantalla;

    pantalla = SDL_SetVideoMode(640, 480, 24, SDL_HWSURFACE|SDL_DOUBLEBUF);

    if(pantalla == NULL) {

        cerr << "No se pudo establecer el modo de video: "
             << SDL_GetError() << endl;

        exit(1);
    }

    // Creamos animaciones para llenar la pantalla

    Animacion animacion("./dentacos.png", 4, 4,"4,5,6,7,6,5,4", 120);  
    Animacion animacion1("./dentacos.png", 4, 4,"0,4,8,12,8,4,0", 120);  
    Animacion animacion2("./dentacos.png", 4, 4,"4,5,6,7,6,5,4", 120);  
    
    // animacion.animar(pantalla, 100, 100);


    // Variables auxiliares

    SDL_Event evento;

    // Para controlar el tiempo

    Uint32 t0 = SDL_GetTicks();
    Uint32 t1;

    // Bucle "infinito"

    for(int x = 0, y = 0 ; ; ) {

	// Si se sale de la pantalla volvemos a introducirlo

	if(x == 640)
	    x = 0;

	// Referencia de tiempo

	t1 = SDL_GetTicks();
	
	if((t1 - t0) > animacion.retardo()) {
	    
	    // Nueva referencia de tiempo
	    
	    t0 = SDL_GetTicks();

	    // Movimiento del personaje
	    
	    x += 4;

	    // Limpiamos la pantalla
	    // Sería mejor limpiar el anterior

	    SDL_FillRect(pantalla, NULL,\
			 SDL_MapRGB(pantalla->format, 0, 0, 0));

	    // Mostramos el siguiente paso de todas las animaciones

	    animacion.paso_a_paso(pantalla, x, y,-1);
	    animacion1.paso_a_paso(pantalla, 200, 300);
	    animacion2.paso_a_paso(pantalla, 300, 300);
	}

	
	// Control de la entrada

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
