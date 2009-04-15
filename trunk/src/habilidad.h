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
 * Fichero = habilidad.h
 * Autor = Pablo Recio Quijano
 * Fecha = 15 de abril de 2009
 * --------------------------------------------------------
 */

#ifndef _HABILIDAD_H
#define	_HABILIDAD_H

#include <SDL/SDL.h>

#include "especial.h"

class Habilidad: public Especial{
public:
  Habilidad() {}
  Habilidad(std::string nombre, Uint32 id, tipoEspecial tipo,
	    Uint32 cotaInf, Uint32 cotaSup, Uint32 gastoPE);
  
  Uint32 getGastoPE() { return _PEgastados; }
  
private:
  Uint32 _PEgastados;
};

#endif	/* _HABILIDAD_H */

