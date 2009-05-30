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
 * File:   aleatorio.h
 * Author: Pablo Recio Quijano
 *
 * Created on 30 de mayo de 2009, 12:43
 */

#ifndef _ALEATORIO_H
#define	_ALEATORIO_H

#include <cstdlib>
#include <ctime>

#include <SDL/SDL.h>

Uint32 aleatorioRango(Uint32 a, Uint32 b){
  return (rand()%(b-a+1)+a);
}

#endif	/* _ALEATORIO_H */

