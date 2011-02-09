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

#include "objeto.h"
#include "especial.h"

Objeto::Objeto(std::string nombre, Uint32 id, tipoEspecial tipo,
	       Uint32 cotaInf, Uint32 cotaSup, Uint32 cantidad, string rXML):
  Especial(nombre,id,tipo,cotaInf,cotaSup),_cantidad(cantidad), _ruta_XML(rXML){}

Uint32 Objeto::usarObjeto() throw(CantidadItemInsuficiente){
    if(_cantidad == 0) throw(new CantidadItemInsuficiente());
    _cantidad--;
    return calculaDamage();
}

Objeto& Objeto::operator --() throw(CantidadItemInsuficiente){
    if(_cantidad == 0) throw(new CantidadItemInsuficiente());
    _cantidad--;
    return *this;
}
