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

    Personaje baldos(1, 1, 1, 30, &p, "./baldos.png");
    baldos.setRango(2,2);
    baldos.setPosicion();

    Personaje graimito(4,13, 4, 30, &p, "./graimito.png");
    graimito.setPosicion(13,4);

    /* Creamos un fondo liso */
    p.cargarImagen(p.getFondo(), "./fondo.png");
    p.volcarPantalla(p.getFondo(), p.getBuffer());

    baldos.dibujarPosicionFrente();
    p.volcarPantalla(p.getBuffer());
    SDL_Delay(50);

    Uint32 desp = 7;

    cout << baldos.getPantX() << " " << baldos.getPantY() << " posicion baldos" << endl;

    for (Uint32 i = 0; i < 3; i++) {
        for (Uint32 sec = 4; sec > 0; sec--) {
            /* Volcar fondo en buffer */
            p.volcarPantalla(p.getFondo(), p.getBuffer());
            /* Realizar movimiento del PJ (en buffer) */
            baldos.moverAbajo(sec - 1, baldos.getDesp(sec-1));
            cout << " sec = " << sec << "; desp(sec) = " << baldos.getDesp(sec-1) << endl; 
            graimito.moverAbajo(sec - 1, graimito.getDesp(sec-1));
            /* Volcar buffer en pantalla */
            p.volcarPantalla(p.getBuffer());
            SDL_Delay(50);
        }
        baldos.bajarEnPantalla();
        if(baldos.fueraRango(baldos.getPantX(),baldos.getPantY()))
            cout << baldos.getPantX() << " " << baldos.getPantY() << " FUERA DE RANGO" << endl;
        else
            cout << baldos.getPantX() << " " << baldos.getPantY() << " EN RANGO" << endl;
    }

    for (Uint32 i = 0; i < 3; i++) {
        desp = 7;
        for (Uint32 sec = 4; sec > 0; sec--) {
            if (sec < 3) desp = 8;
            /* Volcar fondo en buffer */
            p.volcarPantalla(p.getFondo(), p.getBuffer());
            /* Realizar movimiento del PJ (en buffer) */
            baldos.moverIzda(sec - 1, desp);
            graimito.moverIzda(sec - 1, desp);
            /* Volcar buffer en pantalla */
            p.volcarPantalla(p.getBuffer());
            SDL_Delay(50);
        }
        baldos.izdaEnPantalla();
        if(baldos.fueraRango(baldos.getPantX(),baldos.getPantY()))
            cout << baldos.getPantX() << " " << baldos.getPantY() << " FUERA DE RANGO" << endl;
        else
            cout << baldos.getPantX() << " " << baldos.getPantY() << " EN RANGO" << endl;
    }

    for (Uint32 i = 0; i < 4; i++) {
        desp = 7;
        for (Uint32 sec = 4; sec > 0; sec--) {
            if (sec < 3) desp = 8;
            /* Volcar fondo en buffer */
            p.volcarPantalla(p.getFondo(), p.getBuffer());
            /* Realizar movimiento del PJ (en buffer) */
            baldos.moverArriba(sec - 1, desp);
            graimito.moverArriba(sec - 1, desp);
            /* Volcar buffer en pantalla */
            p.volcarPantalla(p.getBuffer());
            SDL_Delay(50);
        }
        baldos.subirEnPantalla();
        if(baldos.fueraRango(baldos.getPantX(),baldos.getPantY()))
            cout << baldos.getPantX() << " " << baldos.getPantY() << " FUERA DE RANGO" << endl;
        else
            cout << baldos.getPantX() << " " << baldos.getPantY() << " EN RANGO" << endl;
    }

    for (Uint32 i = 0; i < 3; i++) {
        desp = 7;
        for (Uint32 sec = 4; sec > 0; sec--) {
            if (sec < 3) desp = 8;
            /* Volcar fondo en buffer */
            p.volcarPantalla(p.getFondo(), p.getBuffer());
            /* Realizar movimiento del PJ (en buffer) */
            baldos.moverDcha(sec - 1, desp);
            graimito.moverDcha(sec - 1, desp);
            /* Volcar buffer en pantalla */
            p.volcarPantalla(p.getBuffer());
            SDL_Delay(50);
        }
        baldos.dchaEnPantalla();
        if(baldos.fueraRango(baldos.getPantX(),baldos.getPantY()))
            cout << baldos.getPantX() << " " << baldos.getPantY() << " FUERA DE RANGO" << endl;
        else
            cout << baldos.getPantX() << " " << baldos.getPantY() << " EN RANGO" << endl;
    }

    /*
    for (Uint32 i = 0; i < 8; i++) {
        desp = 7;
        for (Uint32 sec = 4; sec > 0; sec--) {
            if (sec < 3) desp = 8;
            * Volcar fondo en buffer *
            p.volcarPantalla(p.getFondo(), p.getBuffer());
            * Realizar movimiento del PJ (en buffer) *
            baldos.moverAbajo(sec - 1, desp);
            * Volcar buffer en pantalla *
            p.volcarPantalla(p.getBuffer());
            SDL_Delay(50);
        }
    }
*/
    cout << "Saliendo de la pantalla" << endl;
    p.cerrarPantalla();
}
