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
 * Fichero = objeto.h
 * Autor = Pablo Recio Quijano
 * Fecha = 15 de abril de 2009
 * --------------------------------------------------------
 */

#ifndef _OBJETO_H
#define	_OBJETO_H

#include <SDL/SDL.h>
#include <exception>

#include "especial.h"

class Objeto: public Especial {
public:
  class CantidadItemInsuficiente: public std::exception{
  public:
      const char* what() const throw(){
          return "No hay suficiente cantidad del objeto ";
      }
  private:
  };
  
  Objeto() {}
  Objeto(std::string nombre, Uint32 id, tipoEspecial tipo,
         Uint32 cotaInf, Uint32 cotaSup, Uint32 cantidad);

  Uint32 getCantidad() const { return _cantidad; }
  Uint32 usarObjeto() throw(CantidadItemInsuficiente);

  Objeto& operator --() throw(CantidadItemInsuficiente);
private:
  Uint32 _cantidad;
};

#endif	/* _OBJETO_H */

