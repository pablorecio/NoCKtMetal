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
 * Fichero = inventario.h
 * Autor = Pablo Recio Quijano
 * Fecha = 16 de abril de 2009
 * --------------------------------------------------------
 */

#ifndef _INVENTARIO_H
#define	_INVENTARIO_H

#include <iostream>
#include <map>
#include <exception>

#include <SDL/SDL.h>

#include "objeto.h"

class Inventario {
public:
    class ObjetoEnInventario: public exception{
        const char* what() const throw(){
            return "El objeto ya se encuentra en el inventario";
        }
    };

    class ObjetoNoEnInventario: public exception{
        const char* what() const throw(){
            return "El objeto no se encuentra en el inventario";
        }
    };

    Inventario(){}

    void addObjeto(const Objeto& obj) throw (ObjetoEnInventario);
    Uint32 getObjeto(Uint32 i) throw (Objeto::CantidadItemInsuficiente);

    void borrarObjeto(Uint32 i);
private:
    std::map<Uint32,Objeto> _inventario;

};

#endif	/* _INVENTARIO_H */

