/*
 * This program is free software: you can redistribute it
 * and/or modify it under the terms of the GNU General
 * Public License as published by the Free Software
 * Foundation, either version 3 of the License, or any
 * later version.

 * This program is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A
 * PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.

 * You should have received a copy of the GNU General
 * Public License along with this program.  If not, see
 * <http://www.gnu.org/licenses/>.

 * Copyright (C) 2009, NoCKTMetal Team
 *
 * Fichero: animacion.cpp
 * Autor: Noelia Sales Montes
 * Fecha: 19 de abril de 2009
 * Proyecto: NoCKt Metal
 */

#include <SDL/SDL.h>
#include <iostream>
#include "animacion.h"

using namespace std;

Animacion::Animacion() {
    evento = Evento();
}

Animacion::Animacion(Pantalla *p): _pant(p) {}

Animacion::~Animacion() { }

void Animacion::inicializarAnimacion() {
    /* Inicializamos el mapa */
    Uint32** matriz = (Uint32**) malloc(sizeof (Uint32*) * 48);
    for (Uint32 i = 0; i < 48; i++) {
        matriz[i] = (Uint32*) malloc(sizeof (Uint32)*36);
    }

    for (Uint32 i = 0; i < 48; i++) {
        for (Uint32 j = 0; j < 36; j++) {
            if ((i % 6 < 2) && (j % 6 > 2)) {
                matriz[i][j] = 0;
            } else {
                matriz[i][j] = 1;
            }
        }
    }

    cout << "matriz creada." << endl;

    _imag = new Imagen(48, 36, _pant, matriz);
    Tile arena("arena.png");
    Tile acero("acero.png");

    cout << "imagen y tiles creado" << endl;

    _imag->relacionarTile(0, arena);
    _imag->relacionarTile(1, acero);
    cout << "relación de los tiles" << endl;

    _imag->dibujarFondo(0, 0);
    cout << " imagen dibujada (en buffer)" << endl;

    /* Personaje */
    _principal = new Personaje(1, 1, 1, 30, _pant, "./baldos.png");
    _principal->setRango(8,8);
    _principal->setPosicion();
    cout << "Personaje nuevo" << endl;

    /* Dibujamos la pantalla inicial */
    _pant->volcarPantalla(_pant->getFondo(), _pant->getBuffer());
    _principal->dibujarPosicionFrente();
    _pant->volcarPantalla(_pant->getBuffer());
}

bool Animacion::procesarAccion() {
    /* Cargamos las posiciones iniciales del personaje y del fondo */
    Uint32 x = _principal->getPantX();
    Uint32 y = _principal->getPantY();
    Sint32 cx = _imag->getCX();
    Sint32 cy = _imag->getCY();
    /* Movimiento actual tomado como NULO */ 
    _mov = NULO;

    /* Lectura del nuevo evento */
    switch (evento.getEvento()) {
    case SALIR:
        cout << "Saliendo de la ejecucion del programa" << endl;
        return true;
    case MENU:
        cout << "Desea ver el menu... va a tener que esperar un poco..." << endl;
        break;
    case ACEPTAR:
        cout << "Ha aceptado algo... Pero aqui no sirve de nada... "
                << " eso solo vale en los menus..." << endl;
        break;
    case ATRAS:
        cout << "Ha rechazado algo... eso solo sirve en un menu... "
                << endl;
        break;
    case ARRIBA:
        y--;
        cy--;
        _mov = SUBIR;
        break;
    case ABAJO:
        y++;
        cy++;
        _mov = BAJAR;
        break;
    case IZQUIERDA:
        x--;
        cx--;
        _mov = IZDA;
        break;
    case DERECHA:
        x++;
        cx++;
        _mov = DCHA;
        break;
    default: break;
    }

    /* Si la opción elegida es realizar un movimiento... */
    if (_mov != NULO) {
        /* Si el movimiento queda fuera del rango de pantalla del personaje,
         * se moverá de forma estática, desplazándose el fondo por debajo */
        if (_principal->fueraRango(x, y)) {
            hacerMovimientoEstatico(cx, cy);
        } else {            
            /* En caso de que se desplace el personaje, el fondo quedará tal y
             * como estaba (por lo que no tendremos que pintarlo de nuevo,
             * tan sólo hemos de volcarlo repetidas veces desde el buffer). */
            hacerMovimientoDinamico();
        }
    }
    return false;
}

void Animacion::hacerMovimientoEstatico(Uint32 x, Uint32 y) {
    /* Mientras necesitemos mover al personaje */
    for (Sint32 sec = _principal->getSecuenciasMovimiento() - 1; sec >= 0;
         --sec) {
        /* Desplazamos el mapa */
        _imag->dibujarFondo(x, y, _principal->getSecuenciasMovimiento() - sec,
                            _principal->getSecuenciasMovimiento());
        /* Volcar fondo en buffer */
        _pant->volcarPantalla(_pant->getFondo(), _pant->getBuffer());
        /* Mover el personaje (autovolcado en buffer) */
        mover(sec, 0);
        /* Volcar buffer en pantalla */
        _pant->volcarPantalla(_pant->getBuffer());
    }
}

void Animacion::hacerMovimientoDinamico() {
    /* Mientras necesitemos mover al personaje */
    for (Sint32 sec = _principal->getSecuenciasMovimiento() - 1; sec >= 0;
         --sec) {
        /* Volcar fondo en buffer */
        _pant->volcarPantalla(_pant->getFondo(), _pant->getBuffer());
        /* Volcar seccion de movimiento del PJ en buffer */
        mover(sec, _principal->getDesp(sec));
        /* Volcar buffer en pantalla */
        _pant->volcarPantalla(_pant->getBuffer());
    }
    
    /* En función de la orientación del movimiento, indicamos que se ha
     * producido una variación en la posición de pantalla medida en casillas */
    switch (_mov) {
    case SUBIR:
        _principal->subirEnPantalla();
        break;
    case BAJAR:
        _principal->bajarEnPantalla();
        break;
    case IZDA:
        _principal->izdaEnPantalla();
        break;
    case DCHA:
        _principal->dchaEnPantalla();
        break;
    default:
        break;
    }
}

void Animacion::mover(Uint32 sec, Uint32 desp) {
    switch (_mov) {
    case SUBIR:
        _principal->subirEnPantalla();
        _principal->moverArriba(sec, desp);
        break;
    case BAJAR:
        _principal->bajarEnPantalla();
        _principal->moverAbajo(sec, desp);
        break;
    case IZDA:
        _principal->izdaEnPantalla();
        _principal->moverIzda(sec, desp);
        break;
    case DCHA:
        _principal->dchaEnPantalla();
        _principal->moverDcha(sec, desp);
        break;
    default:
        break;
    }
}
