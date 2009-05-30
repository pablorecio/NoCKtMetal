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
 * Fichero = iacombate.cpp
 * Autor = Pablo Recio Quijano
 * Fecha = 30 de mayo de 2009
 * --------------------------------------------------------
 */

#include <vector>

#include "iacombate.h"

#include "grupo.h"
#include "combatiente.h"
#include "objeto.h"
#include "habilidad.h"
#include "inventario.h"
#include "aleatorio.h"

using namespace std;

class ComparacionVida{
public:
    bool operator()(Combatiente *C1, Combatiente *C2){
        return ((C1->getPV() / C1->getPVMax()) > (C2->getPV() / C2->getPVMax()));
    }
};

 IACombate::IACombate(Combatiente &act, Grupo &g1, Grupo &g2){
     _actual = &act;
     _g1 = &g1;
     _g2 = &g2;
 }

    //Los 4 parámetros por referencia serán valores indicativos que se escribirán
    //que daño se ha realizado, que tipo de ataque, el indice de si es objeto
    //o habilidad, y el objetivo.
 void IACombate::atacar(Uint32 &danio, Uint32 &tipo, Uint32 &indice, Uint32 &objetivo){
   tipo = seleccionarTipoAtaque();
     
   switch(tipo){
   case 1: //Ataque simple
     Combatiente *obj;
     obj = seleccionarObjetivo();
     objetivo = obj->getIdentificador();
     danio = _actual->ataqueSimple(*obj);
     break;
   case 2: //Habilidad
     break;
   case 3: //Objeto
     break;
   case 4: //Huir
     break;
   }
   cout << "Y salgo de la IA" << endl; 
 }

Uint32 IACombate::seleccionarTipoAtaque(){
    return 1;
}

Uint32 IACombate::seleccionarHabilidad(){
    return 1;
}
Uint32 IACombate::seleccionarObjeto(){
    return 1;
}

Combatiente* IACombate::seleccionarObjetivo(){
    vector<Combatiente*> auxiliar;

    cout << "Hola rubio. Esto es antes" << endl;
    for (size_t i = 0; i < _g1->getNumeroCombatientes(); i++) {
        if (_g1->getCombatientes().at(i)->getPV() > 0)
            auxiliar.push_back(_g1->getCombatientes().at(i));
    }

    cout << "Y esto es despues" << endl;
    Aleatorio a;
    int seleccionado = a.valorEntero(1,auxiliar.size()) - 1;
    cout << "salgo de la funcion seleccionarObjetivo()" << endl;
    return auxiliar.at(seleccionado);
    /*make_heap(auxiliar.begin(),auxiliar.end(),ComparacionVida());
    sort_heap(auxiliar.begin(),auxiliar.end());

    vector<int> porc_vida;
    int total = 0;
    for(size_t i = 0 ; i < auxiliar.size() ; i++){
        porc_vida.push_back((auxiliar.at(i)->getPV() / auxiliar.at(i)->getPVMax())*100);
        total += porc_vida.at(i);
    }

    vector<int> probabilidades;
    for(size_t i = 0 ; i < porc_vida.size() ; i++){
    }*/
}
