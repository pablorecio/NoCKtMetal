#include <iostream>
#include <SDL/SDL.h>

#include "pantalla.h"
#include "animacion.h"


using namespace std;

int main() {

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cerr << "No se pudo iniciar SDL: " << SDL_GetError() << endl;
        exit(1);
    }

    Pantalla p = Pantalla();
    p.setTitulo("NoCKt Metal", "./logo.png");

    Animacion a = Animacion(&p);
    a.inicializarAnimacion();

    bool salir = false;

    while (!salir) {
        salir = a.procesarAccion();
    }

    cout << "Saliendo de la pantalla" << endl;
    p.cerrarPantalla();
}
