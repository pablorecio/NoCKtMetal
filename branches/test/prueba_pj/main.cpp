#include <iostream>
#include <SDL/SDL.h>

#include "sprite.h"
#include "personaje.h"
#include "pantalla.h"


using namespace std;

int main() {

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cerr << "No se pudo iniciar SDL: " << SDL_GetError() << endl;
        exit(1);
    }

    Pantalla p = Pantalla();
    p.setTitulo("NoCKt Metal", "./logo.png");

    cout << "pantalla iniciada" << endl;

    Personaje baldos(1, 0, 0, &p, "./baldos.png");

    baldos.setRango();
    baldos.setPosicion();

    /* Creamos un fondo liso */
    p.rellenarPantalla(p.getFondo(), 50, 50, 0, 0);
    p.volcarPantalla(p.getFondo(), p.getBuffer());

    baldos.dibujarPosicionFrente();
    p.volcarPantalla(p.getBuffer());
    SDL_Delay(50);

    Uint32 desp = 7;

    for (Uint32 i = 0; i < 3; i++) {
        desp = 7;
        for (Uint32 sec = 4; sec > 0; sec--) {
            cout << "SEC " << sec << endl;
            if (sec < 3) desp = 8;
            /* Volcar fondo en buffer */
            p.volcarPantalla(p.getFondo(), p.getBuffer());
            /* Realizar movimiento del PJ (en buffer) */
            baldos.moverAbajo(sec-1, desp);
            /* Volcar buffer en pantalla */
            p.volcarPantalla(p.getBuffer());
            SDL_Delay(50);
        }
    }

    for (Uint32 i = 0; i < 3; i++) {
        desp = 7;
        for (Uint32 sec = 4; sec > 0; sec--) {
            if (sec < 3) desp = 8;

            /* Volcar fondo en buffer */
            p.volcarPantalla(p.getFondo(), p.getBuffer());
            /* Realizar movimiento del PJ (en buffer) */
            baldos.moverIzda(sec-1, desp);
            /* Volcar buffer en pantalla */
            p.volcarPantalla(p.getBuffer());
            SDL_Delay(50);
        }
    }

    for (Uint32 i = 0; i < 3; i++) {
        desp = 7;
        for (Uint32 sec = 4; sec > 0; sec--) {
            if (sec < 3) desp = 8;

            /* Volcar fondo en buffer */
            p.volcarPantalla(p.getFondo(), p.getBuffer());
            /* Realizar movimiento del PJ (en buffer) */
            baldos.moverArriba(sec-1, desp);
            /* Volcar buffer en pantalla */
            p.volcarPantalla(p.getBuffer());
            SDL_Delay(50);
        }
    }
   
    for (Uint32 i = 0; i < 3; i++) {
        desp = 7;
        for (Uint32 sec = 4; sec > 0; sec--) {
            if (sec < 3) desp = 8;

            /* Volcar fondo en buffer */
            p.volcarPantalla(p.getFondo(), p.getBuffer());
            /* Realizar movimiento del PJ (en buffer) */
            baldos.moverDcha(sec-1, desp);
            /* Volcar buffer en pantalla */
            p.volcarPantalla(p.getBuffer());
            SDL_Delay(50);
        }
    }

    for (Uint32 i = 0; i < 8; i++) {
        desp = 7;
        for (Uint32 sec = 4; sec > 0; sec--) {
            cout << "SEC " << sec << endl;
            if (sec < 3) desp = 8;
            /* Volcar fondo en buffer */
            p.volcarPantalla(p.getFondo(), p.getBuffer());
            /* Realizar movimiento del PJ (en buffer) */
            baldos.moverAbajo(sec-1, desp);
            /* Volcar buffer en pantalla */
            p.volcarPantalla(p.getBuffer());
            SDL_Delay(50);
        }
    }



    cout << "Saliendo de la pantalla" << endl;
    p.cerrarPantalla();
}
