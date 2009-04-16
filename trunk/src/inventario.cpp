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

#include <iostream>
#include <map>

#include "inventario.h"
#include "objeto.h"

void Inventario::addObjeto(const Objeto& obj) throw (ObjetoEnInventario){
    if(_inventario.find(_obj) == _inventario.end())
      _inventario.insert(new std::pair<Uint32,Objeto>(_obj.getCantidad(),_obj));
    else
        throw new ObjetoEnInventario();
}

const Objeto& Inventario::getObjeto(Uint32 i) throw (ObjetoNoEnInventario){
    if(_inventario.find() == _inventario.end()) throw new ObjetoNoEnInventario();

    return _inventario[i];
}

Objeto& Inventario::getObjeto(Uint32 i) throw (ObjetoNoEnInventario){
    if(_inventario.find() == _inventario.end()) throw new ObjetoNoEnInventario();

    return _inventario[i];
}

void Inventario::borrarObjeto(Uint32 i){
    if(_inventario.find() == _inventario.end()) throw new ObjetoNoEnInventario();

    _inventario.erase(i);
}

