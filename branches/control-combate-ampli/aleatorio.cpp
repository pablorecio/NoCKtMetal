//-*-C++-*-
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
 * Fichero = aleatorio.cpp
 * Autor = Pablo Recio Quijano
 * Fecha = 30 de mayo de 2009
 * --------------------------------------------------------
 */

#include <cstdlib>
#include <ctime>

#include <SDL/SDL.h>

#include "aleatorio.h"

Uint32 Aleatorio::valorEntero(Uint32 a, Uint32 b) const{
  return (rand()%(b-a+1)+a);
}

