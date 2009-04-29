#include <iostream>
#include <SDL/SDL.h>

#include "pantalla.h"
#include "animacion.h"
#include "musica.h"


using namespace std;

int main() {

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cerr << "No se pudo iniciar SDL: " << SDL_GetError() << endl;
        exit(1);
    }

    if(Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT,	1, 2048) < 0) { 
      //probar parametros
      cerr << "Subsistema de Audio no disponible" << endl;
      exit(1);
    }

    Pantalla p = Pantalla();
    p.setTitulo("NoCKt Metal", "./tiles/logo.png");

    Animacion a = Animacion(&p);
    Musica m("musica/NIN-1m.ogg");

    m.reproducir();
    a.inicializarAnimacion();

    bool salir = false;

    while (!salir) {
        salir = a.procesarAccion();
    }

    cout << "Saliendo de la pantalla" << endl;
    p.cerrarPantalla();
    m.pausar();
}
