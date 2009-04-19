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
 * Fichero: personaje.cpp
 * Autor: Noelia Sales Montes
 * Fecha: 14 04 2009
 * Proyecto: NoCKt Metal
 */

#include <iostream>
#include <SDL/SDL.h>

#include "personaje.h"
#include "pantalla.h"

Personaje::Personaje() { }

Personaje::Personaje(Uint32 i, Uint32 x, Uint32 y): _id(i),
_x(x), _y(y), _rango_pX(0), _rango_pY(0), _rango_dX(0),
_rango_dY(0), _anim(0), _sprite(0) { }

Personaje::Personaje(Uint32 i, const char* sprite, Uint32 x, Uint32 y): _id(i),
_x(x), _y(y), _rango_pX(0), _rango_pY(0), _rango_dX(0),
_rango_dY(0), _anim(0), _sprite(0) {
    Sprite s = Sprite(sprite, 4, 4, 16);
}

Personaje::~Personaje() { }

void Personaje::animadoPor(Animacion& a) {
    _anim = &a;
}

void Personaje::dibujadoPor(Sprite& s) {
    _sprite = &s;
}

void Personaje::setPosicion(Uint32 x, Uint32 y) {
    _x = x;
    _y = y;
}

void Personaje::setPosicion() {
    /* Si esta definido el rango, colocamos al personaje en el centro */
    if (existeRango()) {
        _x = (_rango_bX - _rango_aX) / 2;
        _y = (_rango_bY - _rango_aY) / 2;
    }
}

void Personaje::setRango(Uint32 margenIzdo, Uint32 margenArriba,
                         Uint32 rangoAncho, Uint32 rangoAlto) {
    _rango_pX = margenIzdo;
    _rango_pY = margenArriba;
    _rango_dX = rangoAncho;
    _rango_dY = rangoAlto;
    _existeRango = true;
}

void Personaje::moverArriba() {
    mover(_mov_arriba);
}

Uint32 Personaje::moverArriba(Uint32 mov, Uint32 desp) {
    /* Dibujamos el personaje en la imagen de secuencia indicada, un
     * poco mas avanzado */
    _sprite->dibujar(_mov_arriba, mov, _anim->getPantalla()->getMovimiento(),
                     _x, _y - desp);
    mov = (mov + 1) % _sprite->getColumnas();
}

void Personaje::moverAbajo() {
    mover(_mov_abajo);
}

Uint32 Personaje::moverAbajo(Uint32 mov, Uint32 desp) {
    /* Dibujamos el personaje en la imagen de secuencia indicada, un
     * poco mas avanzado */
    _sprite->dibujar(_mov_abajo, mov, _anim->getPantalla()->getMovimiento(),
                     _x, _y + desp);
    mov = (mov + 1) % _sprite->getColumnas();
}

void Personaje::moverIzda() {
    mover(_mov_izda);
}

Uint32 Personaje::moverIzda(Uint32 mov, Uint32 desp) {
    /* Dibujamos el personaje en la imagen de secuencia indicada, un
     * poco mas avanzado */
    _sprite->dibujar(_mov_izda, mov, _anim->getPantalla()->getMovimiento(),
                     _x - desp, _y);
    mov = (mov + 1) % _sprite->getColumnas();
}

void Personaje::moverDcha() {
    mover(_mov_dcha);
}

Uint32 Personaje::moverDcha(Uint32 mov, Uint32 desp) {
    /* Dibujamos el personaje en la imagen de secuencia indicada, un
     * poco mas avanzado */
    _sprite->dibujar(_mov_dcha, mov, _anim->getPantalla()->getMovimiento(),
                     _x + desp, _y);
    mov = (mov + 1) % _sprite->getColumnas();
}

void Personaje::mover(Uint32 movimiento) {
    /* Movimientos a realizar suponiendo que el sprite de movimiento
     * esté organizado tal que cada fila corresponda a la secuencia de
     * movimientos hacia una posicion determinada */
    Uint32 movs = _sprite->getColumnas() - 1;

    /* Dibujamos un desplazamiento estático */
    for (int i = 0; i < movs; i++) {
        _sprite->dibujar(movimiento, i,
                         _anim->getPantalla()->getMovimiento(), _x, _y);
    }
}
