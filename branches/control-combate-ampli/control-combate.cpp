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
 * ------------------------------------------------------
 * File:   control-combate.cpp
 * Author: Pablo Recio Quijano
 * 
 * Created on 27 de abril de 2009, 1:12
 */


#include <iostream>
#include <iterator>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

#include <SDL/SDL.h>

#include "grupo.h"
#include "atributos.h"
#include "combatiente.h"

#include "habilidad.h"
#include "objeto.h"
#include "inventario.h"

#include "control-combate.h"

using namespace std;

class ObjetoComparacion{ //Para la ordenación de los turnos
public:
    bool operator() (Combatiente* C1, Combatiente* C2){
        return (C1->tiradaVelocidad() > C2->tiradaVelocidad());
    }
};

ControlCombate::ControlCombate(){}

ControlCombate::ControlCombate(Grupo &g1, Grupo &g2){
    _g1 = &g1;
    _g2 = &g2;
}

Uint32 ControlCombate::iniciarCombate(){
    mostrarCombate();
    while(_g1->vivo() && _g2->vivo()){
        ControlTurno actual(*this);
        while(!actual.finTurno() && _g1->vivo() && _g2->vivo()){
            actual.iteracionTurno();
        }
    }
    if(_g1->vivo()) return 1;
    else return 2;
}

void ControlCombate::mostrarCombate(){
    //SDL: iniciar motor, fondo, sprites, etc ...
    cout << "---------------------------------------" << endl;
    cout << "--------------- Grupo 1 ---------------" << endl;
    cout << "---------------------------------------" << endl;
    _g1->mostrarGrupo();
    cout << "---------------------------------------" << endl;
    cout << "--------------- Grupo 2 ---------------" << endl;
    cout << "---------------------------------------" << endl;
    _g2->mostrarGrupo();
}

Uint32 ControlCombate::postCombate(){
    return 1;
}


ControlTurno::ControlTurno(){}

//Crea la cola de turnos. Hacer acto de fe, porque aun no entiendo como es capaz de funcionar xDDD
ControlTurno::ControlTurno(ControlCombate &comb){
    _comb = &comb;

    vector<Combatiente*> auxiliar;
    vector<int> num_acciones;

    //Insertamos todos los combatientes en un mismo vector para ordenarlos
    for(size_t i = 0 ; i < _comb->_g1->getNumeroCombatientes() ; i++){
        auxiliar.push_back(_comb->_g1->getCombatientes().at(i));
    }

    for(size_t i = 0 ; i < _comb->_g2->getNumeroCombatientes() ; i++){
        auxiliar.push_back(_comb->_g2->getCombatientes().at(i));
    }

    sort(auxiliar.begin(),auxiliar.end(),ObjetoComparacion());

    for(size_t i = 0 ; i < auxiliar.size() ; i++){
        //cout << auxiliar.at(i)->getNombre() << " - Velocidad: "
        //     << auxiliar.at(i)->getVelocidad() << endl;
        num_acciones.push_back((auxiliar.at(i)->getVelocidad() / 25)+1);
    }

    Uint32 num_ceros = 0;
    Uint32 i = 0;

    while(num_ceros != auxiliar.size()){
        if(i == auxiliar.size()){
            i = 0;
        }

        if(num_acciones.at(i) != 0){
            num_acciones.at(i)--;
            if(num_acciones.at(i) == 0){
                num_ceros++;
            }

            _turno.push(auxiliar.at(i));
            //cout << "Insertado " << auxiliar.at(i)->getNombre() << endl;
        }
        i++;
    }
}

Uint32 ControlTurno::iteracionTurno(){
    Combatiente *actual;
    Combatiente *objetivo;

    do{ //Seleccionamos a los que están vivos
        actual = _turno.front();
        _turno.pop();
    }while(actual->getPV() == 0);

    mostrarEstadoActual();

    if(actual->getGrupo().controlable()){ //El combatiente es controlable por el jugador
        mostrarAcciones();
        Uint32 accion = seleccionarAccion();

        Uint32 danio = 0;
        Habilidad *hab;
        Objeto *obj;
        switch(accion){
            case 1: //Ataque
                mostrarObjetivos(*actual);
                objetivo = seleccionarObjetivo(*actual);
                try{
                    danio = actual->ataqueSimple(*objetivo);
                    mostrarDamage(*actual,*objetivo,danio);
                }catch(Combatiente::AtaqueFallado){
                    mostrarAtaqueFallado(*actual);
                }
                break;
            case 2: //Ataque especial
                mostrarHabilidades(*actual);
                hab = seleccionarHabilidad(*actual);
                mostrarObjetivos(*actual);
                objetivo = seleccionarObjetivo(*actual);
                danio = actual->ataqueEspecial(hab->getIdentificador(),*objetivo);
                mostrarDamage(*actual,*objetivo,danio);
                break;
            case 3: //Objeto
                mostrarInventario(*actual);
                obj = seleccionarObjeto(*actual);
                mostrarObjetivos(*actual);
                objetivo = seleccionarObjetivo(*actual);
                danio = actual->usarObjeto(obj->getIdentificador(),*objetivo);
                mostrarDamage(*actual,*objetivo,danio);
                break;
            case 4: //Huir
                cerr << "No implementada aun" << endl;
                return 2;
                break;
            default:
                break;
        }
    }
    else{ //IA
        cout << "Eres un kinki de mierda y no puedes atacar, te jodes" << endl;
    }
    return 1;
}

void ControlTurno::mostrarEstadoActual(const Combatiente &c){
    cout << "---------------------------------------" << endl;
    cout << "---- Le toca a " << c.getNombre() << " ----" << endl;
    cout << "---------------------------------------" << endl;
    _comb->mostrarCombate();
}

void ControlTurno::mostrarAcciones(){
    cout << "Acciones disponibles:" << endl;
    cout << "[1] - Atacar" << endl;
    cout << "[2] - Habilidad" << endl;
    cout << "[3] - Objeto" << endl;
    cout << "[4] - Huir" << endl;
}

Uint32 ControlTurno::seleccionarAccion(){
    Uint32 sel;
    cout << "Seleccione la acción que desee: ";
    cin >> sel;
    return sel;
}

void ControlTurno::mostrarObjetivos(const Combatiente& c){
    vector<Combatiente*> combG1 = _comb->_g1->getCombatientes();
    vector<Combatiente*> combG2 = _comb->_g2->getCombatientes();

    for(size_t i = 0 ; i < _comb->_g1->getNumeroCombatientes() ; i++)
        if(combG1.at(i)->getPV() != 0)
            cout << "[" << combG1.at(i)->getIdentificador() << "] - "
                 << combG1.at(i)->getNombre() << endl;

    for(size_t i = 0 ; i < _comb->_g2->getNumeroCombatientes() ; i++)
        if(combG2.at(i)->getPV() != 0)
            cout << "[" << combG2.at(i)->getIdentificador() << "] - "
                 << combG2.at(i)->getNombre() << endl;
}

Combatiente* ControlTurno::seleccionarObjetivo(const Combatiente& c)
        throw(Grupo::NoExisteCombatiente){
    Combatiente* objetivo;
    vector<Combatiente*> auxiliar;

    for(size_t i = 0 ; i < _comb->_g1->getNumeroCombatientes() ; i++){
        auxiliar.push_back(_comb->_g1->getCombatientes().at(i));
    }

    for(size_t i = 0 ; i < _comb->_g2->getNumeroCombatientes() ; i++){
        auxiliar.push_back(_comb->_g2->getCombatientes().at(i));
    }

    cout << "Seleccione objetivo (por la clave): ";
    Uint32 clave;
    cin >> clave;

    for(size_t i = 0 ; i < auxiliar.size() ; i++){
        if(auxiliar.at(i)->getIdentificador() == clave){
            objetivo = (auxiliar.at(i));
            return objetivo;
        }
    }
    throw(Grupo::NoExisteCombatiente());
}

void ControlTurno::mostrarHabilidades(const Combatiente& c){
    map<Uint32,Habilidad*> auxiliar = c.getHabilidades();

    cout << "Habilidades disponibles para " << c.getNombre() << ":" << endl;
    for(map<Uint32,Habilidad*>::iterator i = auxiliar.begin() ;
        i != auxiliar.end() ; i++){
        cout << "[" << i->second->getIdentificador() << "] - " << i->second->getNombre()
             << " - PE: " << i->second->getGastoPE() << endl;
    }
}

Habilidad* ControlTurno::seleccionarHabilidad(const Combatiente& c){
    Uint32 sel;
    cout << "Seleccione la habilidad que desea usar (clave): ";
    cin >> sel;
    return c.getHabilidades().at(sel);
}

void ControlTurno::mostrarInventario(const Combatiente& c){
    map<Uint32,Objeto> auxiliar = c.getInventario().getInventarioCompleto();

    cout << "Objetos disponibles para " << c.getNombre() << ":" << endl;
    for(map<Uint32,Objeto>::iterator i = auxiliar.begin() ;
        i != auxiliar.end() ; i++){
        cout << "[" << i->second.getIdentificador() << "] - " << i->second.getNombre()
             << " - Cantidad: " << i->second.getCantidad() << endl;
    }
}

Objeto* ControlTurno::seleccionarObjeto(const Combatiente& c){
    Uint32 sel;
    cout << "Seleccione el objeto que desea usar (clave): ";
    cin >> sel;

    Inventario I = c.getInventario();
    return I.getPointerObjeto(sel);
}

void ControlTurno::mostrarDamage(const Combatiente &c, const Combatiente &o, Uint32 d){
    cout << c.getNombre() << " atacó a " << o.getNombre() << " y le inflingió "
         << d << " puntos de daño" << endl;
}

void ControlTurno::mostrarAtaqueFallado(const Combatiente &c){
    cout << c.getNombre() << " ha fallado el ataque" << endl;
}