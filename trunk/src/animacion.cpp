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

#include "animacion.h"
#include "personaje.h"
#include "imagen.h"

Animacion::Animacion() {
    evento = Evento();
}

Animacion::~Animacion() {
}


void Animacion::animandoEn(Pantalla& p) {
    _pant = &p;
}

bool Animacion::procesarAccion() {
    accion a = evento.getEvento();
    Uint32 x, y;
    x = _principal->getPantX();
    y = _principal->getPantY();
    bool mover = false;

    switch (a) {
    case SALIR: cout << "Saliendo de la ejecucion del programa" << endl;
    return true;
    case MENU: cout << "Desea ver el menu... va a tener que esperar un poco..." << endl;
    break;
    case ACEPTAR: cout << "Ha aceptado algo... Pero aqui no sirve de nada... eso solo vale en los menus..." << endl;
    break;
    case ATRAS : cout << "Ha rechazado algo... eso solo sirve en un menu... " << endl;
    break;
    case ARRIBA: y--;
        mover = true;
        break;
    case ABAJO: y++;
        mover = true;
        break;
    case IZDA: x--;
        mover = true;
        break;
    case DCHA: x++;
        mover = true;
        break;
    default: break;
        }

    /* Si la opcion elegida es realizar un movimiento... */
    if(mover) {
    /* Si el movimiento queda fuera del rango de pantalla del PJ,
     * se movera de forma estatica, desplazandose el fondo por debajo */
    if (_principal->fueraRango(x, y)) {
        hacerMovimientoEstatico(mov);
    } else {
        /* En caso de que se desplace el PJ, el fondo quedara tal y como estaba
         * por lo que solo tendremos que pintarlo una vez y volcarlo las veces
         * que haga falta */
        hacerMovimientoDinamico(mov);
    }
}
    return false;
}

void Animacion::hacerMovimientoEstatico(Movimiento m) {
    /* Mientras necesitemos mover al PJ */
    for (Sint32 sec = _principal->getSecuenciasMovimiento() - 1; sec >= 0; --sec) {
        /* Desplazar el mapa en _desp pixels y volcarlo en fondo*/
        /* Volcar fondo en buffer */
        _pant->volcarPantalla(_pant->getFondo(), _pant->getBuffer());
        /* Mover el PJ (autovolcado en buffer) */
        movimiento(m, sec, 0);
        /* Volcar buffer en pantalla */
        _pant->volcarPantalla(_pant->getBuffer());
    }
}

void Animacion::hacerMovimientoDinamico(Movimiento m) {
    /* Pintar el fondo en fondo (valga la redundancia) */
    /* Mientras necesitemos mover al PJ */
    for (Sint32 sec = _principal->getSecuenciasMovimiento() - 1; sec >= 0; --sec) {
        /* Volcar fondo en buffer */
        _pant->volcarPantalla(_pant->getFondo(), _pant->getBuffer());
        /* Volcar seccion de movimiento del PJ en buffer */
        movimiento(m, sec, _principal->getDesp(sec));
        /* Volcar buffer en pantalla */
        _pant->volcarPantalla(_pant->getBuffer());
    }
    switch (mov) {
    case ARRIBA: _principal->subirEnPantalla();
        break;
    case ABAJO: _principal->bajarEnPantalla();
        break;
    case IZDA: _principal->izdaEnPantalla();
        break;
    case DCHA: _principal->dchaEnPantalla();
        break;
    default: break;
    }
}

void Animacion::movimiento(Movimiento mov, Uint32 sec, Uint32 desp) {
    switch (mov) {
    case ARRIBA: _principal->moverArriba(sec, desp);
        break;
    case ABAJO: _principal->moverAbajo(sec, desp);
        break;
    case IZDA: _principal->moverIzda(sec, desp);
        break;
    case DCHA: _principal->moverDcha(sec, desp);
        break;
    default: break;
    }
}
