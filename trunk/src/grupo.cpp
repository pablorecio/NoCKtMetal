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
#include <vector>

#include <SDL/SDL.h>

#include "grupo.h"
#include "combatiente.h"
#include "inventario.h"


Grupo::Grupo(Inventario& invent, bool contr): _controlable(contr){
    _inventario = &invent;
    std::vector<Combatiente*> temp(4);
    _componentes = temp;
}

void Grupo::addCombatiente(Combatiente& comb) throw(GrupoLleno){
    if(_numComp == 4) throw(new GrupoLleno());
    _componentes.at(_numComp) = &comb;
    _numComp++;
}
