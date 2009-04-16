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
 * Fichero = combatiente.h
 * Autor = Pablo Recio Quijano
 * Fecha = 15 de abril de 2009
 * --------------------------------------------------------
 */

#ifndef _COMBATIENTE_H
#define	_COMBATIENTE_H

#include <iostream>
#include <map>

#include <SDL/SDL.h>

#include "atributos.h"
#include "atributos_base.h"
#include "habilidad.h"
#include "objeto.h"

class Combatiente: public Atributos{
public:
    Combatiente(){}
    Combatiente(std::string nombre, Uint32 id, AtributoBase atr, Uint32 exp = 0,
                std::map<Uint32,Objeto*>& inventario); //TODO: grupo?


    std::string getNombre() const { return _nombre; }
    Uint32 getIdentificador() const { return _idCombatiente; }
    const Habilidad& getHabilidad(Uint32 i) const { return _habilidades[i]; }

    void addHabilidad(Habilidad& h);

    Uint32 ataqueSimple(Combatiente& objetivo);
    Uint32 usarObjeto(Uint32 i, Combatiente& objetivo)
            throw(Objeto::CantidadItemInsuficiente);
    Uint32 ataqueEspecial(Uint32 i, Combatiente& objetivo);
    Uint32 defenderse();
    boolean huir();
private:
    std::string _nombre;
    Uint32 _idCombatiente;
    std::map<Uint32,Habilidad*> _habilidades;
    std::map<Uint32,Objeto*>* _inventario;
};

#endif	/* _COMBATIENTE_H */

