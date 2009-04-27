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
    _numComp = 0;
}

void Grupo::addCombatiente(Combatiente& comb) throw(GrupoLleno){
    if(_numComp == 4) throw(new GrupoLleno());
    _componentes.at(_numComp) = &comb;
    _numComp++;
}

const Combatiente& Grupo::getCombatiente(Uint32 i) const throw(NoExisteCombatiente){
    for(size_t j = 0 ; j < _componentes.size() ; j++){
        if(_componentes.at(j)->getIdentificador() == i)
            return *(_componentes.at(j));
    }
    throw(new NoExisteCombatiente());
}

Combatiente& Grupo::getCombatiente(Uint32 i) throw(NoExisteCombatiente){
    for(size_t j = 0 ; j < _componentes.size() ; j++){
        if(_componentes.at(j)->getIdentificador() == i)
            return *(_componentes.at(j));
    }
    throw(new NoExisteCombatiente());
}

bool Grupo::vivo() const {
    for (unsigned int i = 0 ; i < _componentes.size() ; i++)
        if (_componentes.at(i)->getPV() != 0) return true;
    return false;
}

void Grupo::mostrarGrupo() const {
    cout << "void Grupo::mostrarGrupo() const" << endl;
    cout << "_numComp = " << _numComp << endl;
    for(size_t i = 0; i < _numComp ; i++)
    cout << _componentes.at(i)->getIdentificador() << " - " << _componentes.at(i)->getNombre()
            << " -- PV: " << _componentes.at(i)->getPV() << "/" << _componentes.at(i)->getPVMax()
            << " -- PE: " << _componentes.at(i)->getPE() << "/" << _componentes.at(i)->getPEMax() << endl;
}
