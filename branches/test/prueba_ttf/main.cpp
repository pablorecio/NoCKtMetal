
// Listado: main.cpp
//
// Programa de prueba de la clase Imagen

#include <iostream>
#include <SDL/SDL.h>

#include <SDL/SDL_ttf.h>

#include <vector>

#include "dialogo.h"
#include "pantalla.h"

using namespace std;

int main () {

// Iniciamos el subsistema de video

    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
	
	cerr << "No se pudo iniciar SDL: " << SDL_GetError() << endl;
	 exit(1);
    }

    atexit(SDL_Quit);

    // Comprobamos que sea compatible el modo de video
    
    if(SDL_VideoModeOK(480, 360, 24, SDL_HWSURFACE|SDL_DOUBLEBUF) == 0) {
	
        cerr << "Modo no soportado: " << SDL_GetError() << endl;
        exit(1);
	
    }

    // Inicializamos la librería TTF

    if(TTF_Init() == 0) {

	atexit(TTF_Quit);
        cout << "TTF inicializada" << endl;
	
    }
  
    Pantalla p;

    std::vector<Dialogo::Mensaje> men(10);
    men.at(0) = Dialogo::Mensaje(0,"Wola rubio");
    men.at(1) = Dialogo::Mensaje(1,"Wojojola ijorl");
    men.at(2) = Dialogo::Mensaje(0,"cm tas tu?");
    men.at(3) = Dialogo::Mensaje(1,"poz aki, tudiando.. y tu?");
    men.at(4) = Dialogo::Mensaje(0,"programando XD");
    men.at(5) = Dialogo::Mensaje(1,"ta bien eso :P");
    men.at(6) = Dialogo::Mensaje(0,"sip, bueno, voy a seguir k m keda tela XD");
    men.at(7) = Dialogo::Mensaje(1,"claro! a mi tb m keda XDD");
    men.at(8) = Dialogo::Mensaje(0,"poz venga rubio!! ta luegooo");
    men.at(9) = Dialogo::Mensaje(1,"xaitooo!! ^^");
    

    Dialogo d(men, p);

    // Cargamos la fuente que vamos a utilizar de tamaño 40
    
    /*TTF_Font *diag1;
    TTF_Font *diag2;
    diag1 = TTF_OpenFont("fuentes/FreeMono.ttf", 15);
    diag2 = TTF_OpenFont("fuentes/FreeMono.ttf", 15);
    // Mostramos información acerca de la fuente cargada

    cout << "El tamaño de la fuente es " <<  TTF_FontHeight(diag1) << endl;
    cout << "El ascendente de la fuente es " << TTF_FontAscent(diag1) << endl;
    cout << "El descendente de la fuente es " << TTF_FontDescent(diag1) << endl;
    cout << "La separación entre líneas es " << TTF_FontLineSkip(diag1) << endl;
    
    int w1, w2, h1, h2;
    
    TTF_SizeUTF8(diag1, "Hola Mundo", &w1, &h1);
    TTF_SizeUTF8(diag2, "Que tal! como estás?", &w2, &h2); 

    cout << "El mensaje Hola Mundo ocupará " << w1 << " píxeles de ancho"
	 << " y " << h1 << " de alto." << endl;

    // Vamos a escribir HolaMundo

    SDL_Surface *texto1, *texto2;
    SDL_Color color;
    
    // Establecemos el color para la fuente

    color.r = 255;
    color.g = 255;
    color.b = 255;

    // Renderizamos

    //const Uint16 text = "que tal! cómo estás??";

    texto1 = TTF_RenderText_Blended(diag1, "Hola Mundo", color);
    texto2 = TTF_RenderText_Blended(diag2, "wojojolaa jeje XD", color);
    // Establecemos la posición

    SDL_Rect dest1, dest2;

    dest1.x = 10;
    dest1.y = 10;
    dest1.h = texto1->h;
    dest1.w = texto1->w;

    dest2.x = 10;
    dest2.y = 340;
    dest2.h = texto2->h;
    dest2.w = texto2->w;

    // Mostramos el texto por pantalla

    SDL_BlitSurface(texto1, NULL, pantalla, &dest1);  
    SDL_Flip(pantalla);

    // Mostramos el resultado durante 5 seg

    SDL_Delay(2000);

    SDL_BlitSurface(texto2, NULL, pantalla, &dest2);  
    SDL_Flip(pantalla);

    // Mostramos el resultado durante 5 seg

    SDL_Delay(2000);
    */

    return 0;


}
