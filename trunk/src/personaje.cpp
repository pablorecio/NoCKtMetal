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


void Personaje::animadoPor(Animacion& a);


void Personaje::setPosicion(Uint32 x, Uint32 y);


void Personaje::moverArriba();


void Personaje::moverAbajo();


void Personaje::moverIzda();


void Personaje::moverDcha();
