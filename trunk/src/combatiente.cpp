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

#include <map>


#include <SDL/SDL.h>

#include "combatiente.h" //TODO: Implementar las funciones
#include "grupo.h"

Combatiente::Combatiente(std::string nombre, Uint32 id, AtributoBase atr,
	      /*Grupo& g, */Uint32 exp): Atributos(atr,exp){
    _nombre = nombre;
    _idCombatiente = id;
    //_grupo = *g;

    //_inventario = new (std::map<Uint32,Objeto*>*);
    //_inventario = _grupo->getInventario();
}

void Combatiente::addHabilidad(Habilidad& h){
    //_inventario.insert(h);
}


