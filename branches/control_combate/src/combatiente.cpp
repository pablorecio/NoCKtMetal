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

#include "atributos.h"


#include <iostream>
#include <map>

#include <SDL/SDL.h>

#include "combatiente.h" //TODO: Implementar las funciones
#include "grupo.h"
#include "inventario.h"
#include "objeto.h"

Combatiente::Combatiente(std::string nombre, Uint32 id, AtributoBase atr,
                         Grupo &grupo, std::pair<Uint32,Uint32> rangoArma,
                         Uint32 exp, Uint32 aciertoArma, Uint32 armadura):
            Atributos(atr, exp), _nombre(nombre), _idCombatiente(id), _rangoArma(rangoArma),
            _aciertoArma(aciertoArma), _armadura(armadura){
    _grupo = &grupo;
    _inventario = &(_grupo->getInventario());
    _grupo->addCombatiente(*this); //Añadimos el combatiente a su grupo
    _pasarTurno = false;
}

void Combatiente::addHabilidad(Habilidad& h) {
    _habilidades.insert(std::make_pair(h.getIdentificador(), &h));
}

Uint32 Combatiente::ataqueSimple(Combatiente& objetivo) throw(AtaqueFallado){
    //Primero vemos si le damos
    if(getAciertoArma() + tiradaDestreza() - (objetivo.tiradaDestreza() / 2)
            > aleatorioRango(1,100)) throw(AtaqueFallado());
    else{
        Uint32 damage = tiradaArma() + tiradaFuerza() - (objetivo.tiradaResistencia() / 2);
        objetivo.decrementarPV(damage);
        return damage;
    }
}

Uint32 Combatiente::usarObjeto(Uint32 i, Combatiente& objetivo)
        throw (Inventario::ObjetoNoEnInventario, Objeto::CantidadItemInsuficiente){
    Objeto o = _inventario->getObjeto(i);
    
    Uint32 res;
    if (o.getTipoAtaque() == CURATIVO){
        res = o.calculaDamage();
        objetivo.aumentarPV(res);
    }
    else if (o.getTipoAtaque() == ATAQUE){
        res = o.calculaDamage();
        objetivo.decrementarPV(res);
    }
    --o;
    return res;
}
Uint32 Combatiente::ataqueEspecial(Uint32 i, Combatiente& objetivo){
    Habilidad h = *_habilidades.at(i);

    Uint32 res;
    if(h.getTipoAtaque() == CURATIVO){
        res = h.calculaDamage();
        objetivo.aumentarPV(res);
    }
    else if (h.getTipoAtaque() == ATAQUE){
        res = h.calculaDamage();
        objetivo.decrementarPV(res);
    }
    decrementarPE(h.getGastoPE());
    return res;
}

Uint32 Combatiente::defenderse(){
    _pasarTurno = true;
    //TODO: buscar forma de aumentar el parámetro para restaurarlo en el turno siguiente
    return _res /*+ ¿? */;
}

bool Combatiente::huir(){
    cout << "Función no implementada aun. Pierdes el turno xP" << endl;
    return true;
}
