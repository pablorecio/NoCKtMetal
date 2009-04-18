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
 * Fichero = grupo.h
 * Autor = Pablo Recio Quijano
 * Fecha = 16 de abril de 2009
 * --------------------------------------------------------
 */

#ifndef _GRUPO_H
#define	_GRUPO_H

#include <iostream>
#include <vector>
#include <exception>

#include <SDL/SDL.h>

#include "combatiente.h"
#include "inventario.h"

using namespace std;

class Grupo {
public:
    class GrupoLleno: public exception{
    public:
        const char* what() const throw(){
            return "Grupo lleno";
        }
    };
    Grupo(){}
    Grupo(Inventario& invent, bool contr);

    const Inventario& getInventario() const { return *_inventario; }
    Inventario& getInventario() { return *_inventario; }

    const Combatiente& getCombatiente(Uint32 i) const {return *(_componentes.at(i));}
    Combatiente& getCombatiente(Uint32 i) {return *(_componentes.at(i));}

    Uint32 getNumeroCombatientes() const { return _numComp; }

    void addCombatiente(Combatiente& comb) throw(GrupoLleno);

    bool controlable() const { return _controlable; }

    bool vivo() const {
        for (unsigned int i = 0 ; i < _componentes.size() ; i++)
            if (_componentes.at(i)->getPV() != 0) return true;
        return false;
    }

private:
    bool _controlable;
    Inventario* _inventario;
    vector<Combatiente*> _componentes;
    Uint32 _numComp;
};
#endif	/* _GRUPO_H */

