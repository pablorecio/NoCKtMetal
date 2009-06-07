/*
 * motor-combate.h
 *
 *  Created on: 06-jun-2009
 *      Author: nessa
 */

#ifndef MOTORCOMBATE_H_
#define MOTORCOMBATE_H_

#include "atributos.h"
#include "atributos_base.h"
#include "combatiente.h"
#include "grupo.h"
#include "habilidad.h"
#include "objeto.h"
#include "inventario.h"
#include "aleatorio.h"
#include "biblioteca.h"
#include "es-xml.h"
#include "control-combate.h"

class MotorCombate {
 public:
  MotorCombate();
  void ejecutar();

  private:
    Biblioteca _bib;
    Grupo _jugador;
    map<Uint32, string> _nombreEnemigos;
    map<Uint32, string>::iterator _iterador;
    Grupo _enemigosActuales;
    ControlCombate _combate;
};

#endif /* MOTORCOMBATE_H_ */
