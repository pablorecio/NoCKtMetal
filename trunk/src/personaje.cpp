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
 * --------------------------------------------------------
 * Fichero: personaje.cpp
 * Autor: Noelia Sales Montes
 * Fecha: 14 / 04 / 2009
 * --------------------------------------------------------
 */

#include <iostream>
#include <SDL/SDL.h>

#include "personaje.h"

Personaje::Personaje() {}

Personaje::Personaje(Uint32 i, Sprite s): id_(i), sprite_(s) {}

Personaje::Personaje(Uint32 i, Sprite s, Uint32 x, Uint32 y):
  id_(i), sprite_(s), x_(x), y_(y) {}

Personaje::~Personaje() {}


void Personaje::animadoPor(Animacion& a) {
  anim_ = &a;
}


void Personaje::setPosicion(Uint32 x, Uint32 y) {
  x_ = x;
  y_ = y;
}


void Personaje::moverArriba() {
  /* Si estamos en la fila superior del mapa, no podemos subir mas */
  if(y_ != 0) {
    y_--;
  }
}


void Personaje::moverAbajo() {
  /* Si estamos en la fila inferior del mapa, no podemos subir mas */
  if(y_ != anim_.tamMapaY()) {
    y_++;
  }
}
  

void Personaje::moverIzda() {
  /* Si estamos en la fila izquierda del mapa, no podemos avanzar mas */
  if(x_ != 0) {
    x_--;
  }
}


void Personaje::moverDcha() {
  /* Si estamos en la fila derecha del mapa, no podemos avanzar mas */
  if(x_ != anim_.tamMapaX()) {
    x_++;
  }
}
