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
#include "inventario.h"
//#include "grupo.h" //TODO: ¿Porqué da fallo en grupo.h añadir esta cabecera?

class Combatiente: public Atributos{
public:
  Combatiente(){}
  Combatiente(std::string nombre, Uint32 id, AtributoBase atr, 
	      Inventario &inv, Uint32 exp = 0); //TODO: grupo?


    std::string getNombre() const { return _nombre; }
    Uint32 getIdentificador() const { return _idCombatiente; }
    const Habilidad& getHabilidad(Uint32 i) const { return *_habilidades.at(i); }

    //const Grupo& getGrupo() const { return _grupo; }
    //Grupo& getGrupo() { return _grupo; }

    const Inventario& getInventario() const { return *_inventario; }
    Inventario& getInventario() { return *_inventario; }

    void addHabilidad(Habilidad& h);

    Uint32 ataqueSimple(Combatiente& objetivo);
    Uint32 usarObjeto(Uint32 i, Combatiente& objetivo)
            throw(Objeto::CantidadItemInsuficiente);
    Uint32 ataqueEspecial(Uint32 i, Combatiente& objetivo);
    Uint32 defenderse();
    bool huir();
private:
    std::string _nombre;
    Uint32 _idCombatiente;
    std::map<Uint32,Habilidad*> _habilidades;
    Inventario *_inventario;
    //Grupo* _grupo;
};

#endif	/* _COMBATIENTE_H */

