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
 }

Animacion::~Animacion() {
 }


void Animacion::animandoEn(Pantalla& p) {
    _pant = &p;
}

void Animacion::animandoMapa() {
    Uint32 x, y;

    x = _principal->getX() / _tamCasilla;
    y = _principal->getY() / _tamCasilla;

    switch (mov) {
    case ARRIBA: y--;
        break;
    case ABAJO: y++;
        break;
    case IZDA: x--;
        break;
    case DCHA: x++;
        break;
    default: break;
    }

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

void Animacion::hacerMovimientoEstatico(Movimiento m) {
    /* Mientras necesitemos mover al PJ */
    for (Uint32 i = 0; i < _numSecuencias; i++) {
        /* Desplazar el mapa en _desp pixels y volcarlo en fondo*/
        /* Mover el PJ (autovolcado en movimiento) */
        movimiento(m, i, 0);
        /* Volcar fondo en buffer */
        _pant->volcarPantalla(_pant->getFondo(), _pant->getBuffer());
        /* Volcar seccion de movimiento del PJ en buffer */
        _pant->volcarPantalla(_pant->getFondo(), _pant->getBuffer(),
                              &_rangoPJ);
        /* Volcar buffer en pantalla */
        _pant->volcarPantalla(_pant->getBuffer());
    }
}

void Animacion::hacerMovimientoDinamico(Movimiento m) {
    /* Pintar el fondo en fondo (valga la redundancia) */
    /* Mientras necesitemos mover al PJ */
    for (Uint32 i = 0; i < _numSecuencias; i++) {
        movimiento(m, i);
        /* Volcar fondo en buffer */
        _pant->volcarPantalla(_pant->getFondo(), _pant->getBuffer());
        /* Volcar seccion de movimiento del PJ en buffer */
        _pant->volcarPantalla(_pant->getFondo(), _pant->getBuffer(),
                              &_rangoPJ);
        /* Volcar buffer en pantalla */
        _pant->volcarPantalla(_pant->getBuffer());
    }
}

void Animacion::movimiento(Movimiento mov, Uint32 sec, Uint32 desp) {
    switch (mov) {
    case ARRIBA: _principal->moverArriba(mov, sec, desp);
        break;
    case ABAJO: _principal->moverAbajo(mov, sec, desp);
        break;
    case IZDA: _principal->moverIzda(mov, sec, desp);
        break;
    case DCHA: _principal->moverDcha(mov, sec, desp);
        break;
    default: break;
    }
}
