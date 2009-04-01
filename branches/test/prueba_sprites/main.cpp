// Listado: main.cpp
//
// Programa de prueba de la clase Imagen

#include <iostream>
#include <SDL/SDL.h>

#include "Imagen.h"

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


    // Creamos un elemento de la clase Imagen

    Imagen personaje("./dentacos.png", 4, 4);


    // Mostramos por consola información de la imagen
    
    cout << "La imagen tiene: " << endl;
    cout << "- anchura: " << personaje.anchura() << " px"<< endl;
    cout << "- altura : " << personaje.altura() << " px" << endl;
    cout << "- cuadros: " << personaje.cuadros() << endl;

    // Mostramos varios "frames"

    // El primero normal y rotado

    personaje.dibujar(pantalla, 0, 0, 0);
    personaje.dibujar(pantalla, 1, 50, 0);
    personaje.dibujar(pantalla, 2, 100, 0);
    personaje.dibujar(pantalla, 3, 150, 0);



    personaje.dibujar(pantalla, 4, 0, 100);
    personaje.dibujar(pantalla, 5, 50, 100);
    personaje.dibujar(pantalla, 6, 100, 100);
    personaje.dibujar(pantalla, 7, 150, 100);



    personaje.dibujar(pantalla, 8, 0, 200);
    personaje.dibujar(pantalla, 9, 50, 200);
    personaje.dibujar(pantalla, 10, 100, 200);
    personaje.dibujar(pantalla, 11, 150, 200);



    personaje.dibujar(pantalla, 12, 0, 300);
    personaje.dibujar(pantalla, 13, 50, 300);
    personaje.dibujar(pantalla, 14, 100, 300);
    personaje.dibujar(pantalla, 15, 150, 300);

    // Actualizamos la superficie principal

    SDL_Flip(pantalla);



    // Variables auxiliares

    SDL_Event evento;

    // Bucle "infinito"

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
