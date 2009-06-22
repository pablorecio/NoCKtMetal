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
#include "iacombate.h"

#include "control-combate.h"

//#define DEBUG 1

using namespace std;

class ObjetoComparacion { //Para la ordenación de los turnos
public:

  bool operator()(Combatiente* C1, Combatiente* C2) {
    return (C1->getVelocidad() > C2->getVelocidad());
  }
};

ControlCombate::ControlCombate() {
}

ControlCombate::ControlCombate(Grupo &g1, Grupo &g2){
  _huida = false;
  _g1 = &g1;
  _g2 = &g2;

#ifdef DEBUG
  cout << "ControlCombate::ControlCombate(Grupo &g1, Grupo &g2)" << endl;
#endif
}

Uint32 ControlCombate::iniciarCombate() {
	mostrarCombate();
	int cont1 = 0;
	while (_g1->vivo() && _g2->vivo() && !_huida) {
		cout << "Turno " << ++cont1 << endl;
		ControlTurno actual(*this);
		while (!actual.finTurno() && !_huida && _g1->vivo() && _g2->vivo()) {
			//cout << "Accion " << cont1 << "." << cont2++ << endl;
			actual.iteracionTurno();
		}
	}
	if (_g1->vivo())
		return 1;
	else if (_huida)
		return 3;
	else
		return 2;
}

void ControlCombate::mostrarCombate() {
  //SDL: iniciar motor, fondo, sprites, etc ...
  cout << "---------------------------------------" << endl;
  cout << "--------------- Grupo 1 ---------------" << endl;
  cout << "---------------------------------------" << endl;
  _g1->mostrarGrupo();
  cout << "---------------------------------------" << endl;
  cout << "--------------- Grupo 2 ---------------" << endl;
  cout << "---------------------------------------" << endl;
  _g2->mostrarGrupo();
#ifdef DEBUG
  cout << "ControlCombate::mostrarCombate()" << endl;
#endif
}

Uint32 ControlCombate::postCombate() {
  if (_g1->vivo() && !_g2->vivo()) {
    Uint32 exp_ganada = 0;
    for (size_t i = 0; i < _g2->getNumeroCombatientes(); i++) {
      exp_ganada += _g2->getCombatientes().at(i)->getExperienciaGanable();
    }
    Uint32 cada_uno = exp_ganada / 4;
    cout << "Habeis ganado " << exp_ganada << " puntos de experiencia"
	 << endl;
    for (size_t i = 0; i < _g1->getNumeroCombatientes(); i++) {
      if (_g1->getCombatientes().at(i)->getExperiencia() + cada_uno
	  >= _g1->getCombatientes().at(i)->getExperienciaSiguienteNivel())
	cout << _g1->getCombatientes().at(i)->getNombre()
	     << " ha subido al nivel " << _g1->getCombatientes().at(
								    i)->getNivel() + 1 << endl;
      _g1->getCombatientes().at(i)->addExperiencia(cada_uno);
    }
  }
  _g1->actualizarXML(); //LO ACTUALIZA TODO LO NECESARIO, YA QUE SOLO QUEREMOS GUARDAR EL GRUPO.
  return 1;
}

ControlTurno::ControlTurno() {
}


ControlTurno::ControlTurno(ControlCombate &comb) {
  _comb = &comb;

  vector<Combatiente*> auxiliar;
  vector<int> num_acciones;

#ifdef DEBUG
  cout << "ControlTurno::ControlTurno(): Vectores creados" << endl;
#endif

  //Insertamos todos los combatientes en un mismo vector para ordenarlos
  for (size_t i = 0; i < _comb->_g1->getNumeroCombatientes(); i++) {
    if (_comb->_g1->getCombatientes().at(i)->getPV() > 0)
      auxiliar.push_back(_comb->_g1->getCombatientes().at(i));
  }

#ifdef DEBUG
  cout << "ControlTurno::ControlTurno(): Combatientes 1 insertados en auxiliar" << endl;
#endif

  for (size_t i = 0; i < _comb->_g2->getNumeroCombatientes(); i++) {
    if (_comb->_g2->getCombatientes().at(i)->getPV() > 0)
      auxiliar.push_back(_comb->_g2->getCombatientes().at(i));
  }

#ifdef DEBUG
  cout << "ControlTurno::ControlTurno(): Combatientes 2 insertados en auxiliar" << endl;
  cout << "ControlTurno::ControlTurno(): auxiliar.size() = " << auxiliar.size() << endl;
  for (size_t i = 0; i < auxiliar.size(); i++) {
    cout << "ControlTurno::ControlTurno(): " << auxiliar.at(i)->getNombre()
	 << " = " << auxiliar.at(i) << endl;
  }
  cout << "--------------------------------------------" << endl;

  for (vector<Combatiente*>::iterator i = auxiliar.begin();
       i != auxiliar.end(); i++) {
    cout << "ControlTurno::ControlTurno(): " << (*i)->getNombre()
	 << " = " << *i << endl;
  }
#endif

	stable_sort(auxiliar.begin(),auxiliar.end(),ObjetoComparacion());


#ifdef DEBUG
  cout << "ControlTurno::ControlTurno(): Combatientes ordenados" << endl;
#endif

  for (size_t i = 0; i < auxiliar.size(); i++) {
    //cout << auxiliar.at(i)->getNombre() << " - Velocidad: "
    //     << auxiliar.at(i)->getVelocidad() << endl;
    num_acciones.push_back((auxiliar.at(i)->getVelocidad() / 25) + 1);
  }

#ifdef DEBUG
  cout << "ControlTurno::ControlTurno(): Inicializado vector numero de acciones" << endl;
#endif

  Uint32 num_ceros = 0;
  Uint32 i = 0;

  while (num_ceros != auxiliar.size()) {
    if (i == auxiliar.size()) {
      i = 0;
    }

    if (num_acciones.at(i) != 0) {
      num_acciones.at(i)--;
      if (num_acciones.at(i) == 0) {
	num_ceros++;
      }

      _turno.push(auxiliar.at(i));
      //cout << "Insertado " << auxiliar.at(i)->getNombre() << endl;
    }
    i++;
  }

#ifdef DEBUG
  cout << "ControlTurno::ControlTurno(): Fin" << endl;
#endif
}

Uint32 ControlTurno::iteracionTurno() {
  Combatiente *actual;
  Combatiente *objetivo;

  do { //Seleccionamos a los que están vivos
    actual = _turno.front();
    _turno.pop();
  } while (actual->getPV() == 0);

  mostrarEstadoActual(*actual);

  Uint32 accion = 0;

  Uint32 danio = 0;

  if (actual->getGrupo().controlable()) { //El combatiente es controlable por el jugador
    mostrarAcciones();
    accion = seleccionarAccion();
    Habilidad *hab;
    Objeto *obj;
    bool band = false;
    switch (accion) {
    case 1: //Ataque
      mostrarObjetivos(*actual);
      objetivo = seleccionarObjetivo(*actual);
      try {
	danio = actual->ataqueSimple(*objetivo);
	mostrarDamage(*actual, *objetivo, danio);
      } catch (Combatiente::AtaqueFallado) {
	mostrarAtaqueFallado(*actual);
      }
      break;
    case 2: //Ataque especial
    	while(!band){
    		mostrarHabilidades(*actual);
    		hab = seleccionarHabilidad(*actual);
    		mostrarObjetivos(*actual);
    		objetivo = seleccionarObjetivo(*actual);
    		try{
    			danio = actual->ataqueEspecial(hab->getIdentificador(), *objetivo);
        		band = true;
        		mostrarDamage(*actual, *objetivo, danio);
    		}
    		catch(Combatiente::NoHaySuficientePE){
    			cerr << "No tienes suficiente PE para usar ese ataque" << endl;
    		}
    	}
      break;
    case 3: //Objeto
      mostrarInventario(*actual);
      obj = seleccionarObjeto(*actual);
      mostrarObjetivos(*actual);
      objetivo = seleccionarObjetivo(*actual);
      danio = actual->usarObjeto(obj->getIdentificador(), *objetivo);
      mostrarDamage(*actual, *objetivo, danio);
      break;
    case 4: //Huir
      if (intentarHuir(*actual) == 1){
	cout << "Has huido, cobarde" << endl;
	_comb->_huida = true;
      }
      else{
	cout << "No has logrado huir" << endl;
      }
      break;
    default:
      break;
    }
  } else { //IA
    IACombate ia(*actual, *(_comb->_g1), *(_comb->_g2));
    Uint32 tipo = 0, indice = 0, ind_obj = 0;
    try {
      ia.atacar(danio, tipo, indice, ind_obj);
      for (size_t i = 0; i < _comb->_g1->getNumeroCombatientes(); i++) {
	if (_comb->_g1->getCombatientes().at(i)->getIdentificador()
	    == ind_obj) {
	  objetivo = _comb->_g1->getCombatientes().at(i);
	}
      }
      mostrarDamage(*actual, *objetivo, danio);
    } catch (Combatiente::AtaqueFallado) {
      mostrarAtaqueFallado(*actual);
    }

  }
#ifdef DEBUG
  cout << "ControlTurno::iteracionTurno()" << endl;
#endif
  return 1;
}

void ControlTurno::mostrarEstadoActual(const Combatiente & c) {
  cout << "---------------------------------------" << endl;
  cout << "---- Le toca a " << c.getNombre() << " ----" << endl;
  cout << "---------------------------------------" << endl;
  _comb->mostrarCombate();
#ifdef DEBUG
  cout << "ControlTurno::mostrarEstadoActual()" << endl;
#endif
}

void ControlTurno::mostrarAcciones() {
  cout << "Acciones disponibles:" << endl;
  cout << "[1] - Atacar" << endl;
  cout << "[2] - Habilidad" << endl;
  cout << "[3] - Objeto" << endl;
  cout << "[4] - Huir" << endl;
#ifdef DEBUG
  cout << "ControlTurno::MostrarAcciones()" << endl;
#endif
}

Uint32 ControlTurno::seleccionarAccion() {
  Uint32 sel;
  cout << "Seleccione la acción que desee: ";
  cin >> sel;
#ifdef DEBUG
  cout << "ControlTurno::seleccionarAccion()" << endl;
#endif
  return sel;
}

void ControlTurno::mostrarObjetivos(const Combatiente & c) {
  vector<Combatiente*> combG1 = _comb->_g1->getCombatientes();
  vector<Combatiente*> combG2 = _comb->_g2->getCombatientes();

  for (size_t i = 0; i < _comb->_g1->getNumeroCombatientes(); i++)
    if (combG1.at(i)->getPV() != 0)
      cout << "[" << combG1.at(i)->getIdentificador() << "] - "
	   << combG1.at(i)->getNombre() << endl;

  for (size_t i = 0; i < _comb->_g2->getNumeroCombatientes(); i++)
    if (combG2.at(i)->getPV() != 0)
      cout << "[" << combG2.at(i)->getIdentificador() << "] - "
	   << combG2.at(i)->getNombre() << endl;
#ifdef DEBUG
  cout << "ControlTurno::mostrarObjetivos()" << endl;
#endif
}

Combatiente * ControlTurno::seleccionarObjetivo(const Combatiente & c)
  throw (Grupo::NoExisteCombatiente) {
  Combatiente* objetivo;
  vector<Combatiente*> auxiliar;

  for (size_t i = 0; i < _comb->_g1->getNumeroCombatientes(); i++) {
    auxiliar.push_back(_comb->_g1->getCombatientes().at(i));
  }

  for (size_t i = 0; i < _comb->_g2->getNumeroCombatientes(); i++) {
    auxiliar.push_back(_comb->_g2->getCombatientes().at(i));
  }

  cout << "Seleccione objetivo (por la clave): ";
  Uint32 clave;
  cin >> clave;

  for (size_t i = 0; i < auxiliar.size(); i++) {
    if (auxiliar.at(i)->getIdentificador() == clave) {
      objetivo = (auxiliar.at(i));
#ifdef DEBUG
      cout << "ControlTurno::seleccionarObjetivo()" << endl;
#endif
      return objetivo;
    }
  }
#ifdef DEBUG
  cout << "ControlTurno::seleccionarObjetivo()" << endl;
#endif
  throw(Grupo::NoExisteCombatiente());
}

void ControlTurno::mostrarHabilidades(const Combatiente & c) {
  map<Uint32, Habilidad*> auxiliar = c.getHabilidades();

  cout << "Habilidades disponibles para " << c.getNombre() << ":" << endl;
  for (map<Uint32, Habilidad*>::iterator i = auxiliar.begin(); i
	 != auxiliar.end(); i++) {
    cout << "[" << i->second->getIdentificador() << "] - "
	 << i->second->getNombre() << " - PE: "
	 << i->second->getGastoPE() << endl;
  }
#ifdef DEBUG
  cout << "ControlTurno::mostrarHabilidades()" << endl;
#endif
}

Habilidad * ControlTurno::seleccionarHabilidad(const Combatiente & c) {
  Uint32 sel;
  cout << "Seleccione la habilidad que desea usar (clave): ";
  cin >> sel;
#ifdef DEBUG
  cout << "ControlTurno::seleccionarHabilidad()" << endl;
#endif
  return c.getHabilidades().at(sel);
}

void ControlTurno::mostrarInventario(const Combatiente & c) {
  map<Uint32, Objeto> auxiliar = c.getInventario().getInventarioCompleto();

  cout << "Objetos disponibles para " << c.getNombre() << ":" << endl;
  for (map<Uint32, Objeto>::iterator i = auxiliar.begin(); i
	 != auxiliar.end(); i++) {
    cout << "[" << i->second.getIdentificador() << "] - "
	 << i->second.getNombre() << " - Cantidad: "
	 << i->second.getCantidad() << endl;
  }
#ifdef DEBUG
  cout << "ControlTurno::mostrarInventario()" << endl;
#endif
}

Objeto * ControlTurno::seleccionarObjeto(const Combatiente & c) {
  Uint32 sel;
  cout << "Seleccione el objeto que desea usar (clave): ";
  cin >> sel;

  Inventario I = c.getInventario();
#ifdef DEBUG
  cout << "ControlTurno::seleccionarObjeto()" << endl;
#endif
  return I.getPointerObjeto(sel);
}

void ControlTurno::mostrarDamage(const Combatiente &c, const Combatiente &o,
				 Uint32 d) {
  cout << c.getNombre() << " atacó a " << o.getNombre() << " y le inflingió "
       << d << " puntos de daño" << endl;
#ifdef DEBUG
  cout << "ControlTurno::mostrarDamage()" << endl;
#endif
}

void ControlTurno::mostrarAtaqueFallado(const Combatiente & c) {
  cout << c.getNombre() << " ha fallado el ataque" << endl;
#ifdef DEBUG
  cout << "ControlTurno::mostrarAtaqueFallado()" << endl;
#endif
}

Uint32 ControlTurno::intentarHuir(const Combatiente &c) {
  //la idea es sumar tiradas de suerte de todos los miembros del grupo
  //y si ganan, pueden huir.

  Uint32 tiradaG1 = 0, tiradaG2 = 0;

  for (size_t i = 0; i < _comb->_g1->getNumeroCombatientes(); i++) {
    tiradaG1 += _comb->_g1->getCombatientes().at(i)->tiradaSuerte();
  }

  for (size_t i = 0; i < _comb->_g2->getNumeroCombatientes(); i++) {
    tiradaG2 += _comb->_g2->getCombatientes().at(i)->tiradaSuerte();
  }

  if(c.getGrupo().getIdentificador() == _comb->_g1->getIdentificador()){
    if (tiradaG1 > tiradaG2) return 1;
    else return 2;
  }

  if(c.getGrupo().getIdentificador() == _comb->_g2->getIdentificador()){
    if (tiradaG2 > tiradaG1) return 1;
    else return 2;
  }
  return 0;
}
