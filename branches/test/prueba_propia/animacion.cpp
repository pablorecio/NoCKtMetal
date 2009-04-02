/*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.

 * Copyright (C) 2009, NoCKTMetal Team
 *
 */

/*
 * --------------------------------------------------------
 * Fichero = animacion.cpp
 * Autor = Pablo Recio Quijano
 * Fecha = 02 / 04 / 2009
 * 
 * - Implementacion de la clase Animacion.
 */

/*-------- Clase en pruebas --------*/

#include <iostream>
#include <vector>

#include <SDL/SDL.h>

#include "sprite.h"
#include "animacion.h"

Animacion::Animacion(){
}

Animacion::Animacion(Sprite s, Uint32 r){
  _sprite = s;
  _retardo = r;

  int n = s.getNumSprites();

  std::vector<int> v(n);
  for (int i = 0 ; i < n ; i++)
    v.at(i) = i;

  _marcos = v;
}

Animacion::Animacion(Sprite s, std::vector<int> m, Uint32 r){
  _sprite = s;
  _marcos = m;
  _retardo = r;
}

Animacion::Animacion(const Animacion& otra){
  _sprite = otra._sprite;
  _marcos = otra._marcos;
  _retardo = otra._retardo;
}

Animacion::~Animacion(){} //llama a todos los destructores

void Animacion::animar_inf(SDL_Surface *destino, int x, int y, int flip = 1);
void Animacion::animar_paso(SDL_Surface *destino, int x, int y, int flip = 1);
