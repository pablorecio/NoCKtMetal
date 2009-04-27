
#include "atributos.h"

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
#include "combatiente.h"

#include "habilidad.h"
#include "objeto.h"
#include "inventario.h"

#include "control-combate.h"

using namespace std;

class ObjetoComparacion{
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
    while(_g1->vivo() && _g2->vivo()){
        ControlTurno actual(*this);
        while(!actual.finTurno()){
            actual.iteracionTurno();
        }
    }
    if(_g1->vivo()) return 1;
    else return 2;
}

Uint32 ControlCombate::postCombate(){
    return 1;
}


ControlTurno::ControlTurno(){}
ControlTurno::ControlTurno(ControlCombate &comb){
    _comb = &comb;

    vector<Combatiente*> auxiliar;
    vector<int> num_acciones;

    for(size_t i = 0 ; i < _comb->_g1->getNumeroCombatientes() ; i++){
        auxiliar.push_back(_comb->_g1->getCombatientes().at(i));
    }

    for(size_t i = 0 ; i < _comb->_g2->getNumeroCombatientes() ; i++){
        auxiliar.push_back(_comb->_g2->getCombatientes().at(i));
    }

    sort(auxiliar.begin(),auxiliar.end(),ObjetoComparacion());

    for(size_t i = 0 ; i < auxiliar.size() ; i++){
        cout << auxiliar.at(i)->getNombre() << " - Velocidad: "
             << auxiliar.at(i)->getVelocidad() << endl;
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
    Uint32 sel = 0;
    Combatiente *actual;
    Combatiente *objetivo;

    do{
        actual = _turno.front();
        _turno.pop();
    }while(actual->getPV() == 0);

    if(actual->getGrupo().controlable()){ //CONTROLABLE
        switch(seleccionaAccion(*actual)){
            case 1:
                cout << "Objetivos:" << endl;
                objetivo = seleccionarObjetivo(*actual);
                try{
                    cout << actual->getNombre() << " ataca a " << objetivo->getNombre()
                         << " infligiendole " << actual->ataqueSimple(*objetivo) << endl;
                }
                catch(...){
                    cout << actual->getNombre() << " falló el ataque!" << endl;
                }
                break;
            case 2:
                cout << "Habilidades: " << endl;
                mostrarHabilidades(*actual);
                cout << "Seleccione una habilidad (clave): ";
                cin >> sel;
                cout << "Objetivos:" << endl;
                objetivo = seleccionarObjetivo(*actual);

                cout << actual->getNombre() << " ataca a " ;
                cout << objetivo->getNombre() << " con ";
                cout << actual->getHabilidad(sel).getNombre() << " infligiendole ";
                cout << actual->ataqueEspecial(sel,*objetivo) << endl;
                break;
            case 3:
                cout << "Objetos: " << endl;
                mostrarInventario(*actual);
                cout << "Seleccione un objeto (clave): ";
                cin >> sel;
                cout << "Objetivos:" << endl;
                objetivo = seleccionarObjetivo(*actual);
                cout << actual->getNombre() << " ataca a " << objetivo->getNombre()
                     << " con " << actual->getInventario().getObjeto(sel).getNombre()
                     << " infligiendole " << actual->usarObjeto(sel,*objetivo) << endl;
                break;
            case 4:
                actual->huir();
                break;
            default:
                break;
        }
    }
    else{ //IA
        cout << "Los kinkis aun no pueden atacar" << endl;
    }
    return 1;
}

Uint32 ControlTurno::seleccionaAccion(const Combatiente& c){
    cout << "----- Ampli Breakers -----" << endl;
    _comb->_g1->mostrarGrupo();
    cout << "-------- Enemigos --------" << endl;
    _comb->_g2->mostrarGrupo();
    cout << "--------------------------" << endl;
    cout << "Le toca a " << c.getNombre()  << endl;
    cout << "-------- Acciones --------" << endl;

    mostrarMenu(c);

    cout << "Selecciones acción: ";
    Uint32 opc;

    cin >> opc;
    return opc;
}

void ControlTurno::mostrarMenu(const Combatiente& c){
    cout << "1 - Ataque" << endl;
    cout << "2 - Ataque especial" << endl;
    cout << "3 - Objeto" << endl;
    cout << "4 - Escapar" << endl;
}

void ControlTurno::mostrarHabilidades(const Combatiente& c){
    map<Uint32,Habilidad*> auxiliar = c.getHabilidades();

    for(map<Uint32,Habilidad*>::iterator i = auxiliar.begin() ;
        i != auxiliar.end() ; i++){
        cout << i->second->getIdentificador() << " - " << i->second->getNombre()
             << " - PE: " << i->second->getGastoPE() << endl;
    }
}

void ControlTurno::mostrarInventario(const Combatiente& c){
    map<Uint32,Objeto> auxiliar = c.getInventario().getInventarioCompleto();

    for(map<Uint32,Objeto>::iterator i = auxiliar.begin() ;
        i != auxiliar.end() ; i++){
        cout << i->second.getIdentificador() << " - " << i->second.getNombre()
             << " - Cantidad: " << i->second.getCantidad() << endl;
    }
}

void ControlTurno::mostrarObjetivos(const Combatiente& c){
    vector<Combatiente*> combG1 = _comb->_g1->getCombatientes();
    vector<Combatiente*> combG2 = _comb->_g2->getCombatientes();

    for(size_t i = 0 ; i < _comb->_g1->getNumeroCombatientes() ; i++)
        if(combG1.at(i)->getPV() != 0)
            cout << combG1.at(i)->getIdentificador() << " - "
                 << combG1.at(i)->getNombre() << endl;

    for(size_t i = 0 ; i < _comb->_g2->getNumeroCombatientes() ; i++)
        if(combG2.at(i)->getPV() != 0)
            cout << combG2.at(i)->getIdentificador() << " - "
                 << combG2.at(i)->getNombre() << endl;
}

Combatiente* ControlTurno::seleccionarObjetivo(const Combatiente& c)
        throw(Grupo::NoExisteCombatiente){ //falla ¬¬

    Combatiente* objetivo;
    vector<Combatiente*> auxiliar;

    for(size_t i = 0 ; i < _comb->_g1->getNumeroCombatientes() ; i++){
        auxiliar.push_back(_comb->_g1->getCombatientes().at(i));
    }

    for(size_t i = 0 ; i < _comb->_g2->getNumeroCombatientes() ; i++){
        auxiliar.push_back(_comb->_g2->getCombatientes().at(i));
    }

    mostrarObjetivos(c);
    cout << "Seleccione objetivo (por la clave): ";
    Uint32 clave;
    cin >> clave;

    //bool encontrado = false;

    for(size_t i = 0 ; i < auxiliar.size() ; i++){
        if(auxiliar.at(i)->getIdentificador() == clave){
            objetivo = (auxiliar.at(i));
            return objetivo;
        }
    }
    //if(!encontrado)
    throw(Grupo::NoExisteCombatiente());
}
