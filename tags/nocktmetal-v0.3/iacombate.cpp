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
     cout << "Objetivo: " << obj << endl;
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

    for (size_t i = 0; i < _g1->getNumeroCombatientes(); i++) {
      if (_g1->getCombatientes().at(i)->getPV() > 0){
            auxiliar.push_back(_g1->getCombatientes().at(i));
	    cout << "Posible objetivo: " << _g1->getCombatientes().at(i) 
		 << endl;
      }
    }

    //Aleatorio a;
    //int seleccionado = a.valorEntero(1,auxiliar.size()) - 1;
    //return auxiliar.at(seleccionado);
    sort(auxiliar.begin(),auxiliar.end());

    #ifdef DEBUG
    cout << "OBJETIVOS ORDENADOS:" << endl << "-----------------" << endl;
    for(vector<Combatiente*>::iterator i = auxiliar.begin();
	i != auxiliar.end() ; i++){
      cout << (*i)->getNombre() << " -> " << *i << endl;
    }
    #endif

    Aleatorio a;
    Sint32 n = _g1->getNumeroCombatientesVivos();
    vector<Sint32> valores;
    Sint32 val_aux = 0;
    for(Sint32 i = 0 ; i < n ; i++){
    	val_aux += i + 1;
    	valores.push_back(val_aux);
    }
    Sint32 valor_aleatorio = a.valorEntero(1,val_aux);

    Combatiente *objetivo;
    objetivo = *(auxiliar.begin());
    for(Sint32 i = n-1 ; i >= 0 ; i--){
    	if(i != 0 && valores.at(i) > valor_aleatorio && valores.at(i-1) < valor_aleatorio){
	  cout << "WOJOJO" << endl << "n: " << n << endl << "i: " << i << endl;
	  objetivo = auxiliar.at(n-i);
    	}
    }
    cout << "Objetivo seleccionado: " << objetivo << endl;
    return objetivo;
}
