/*
 * This program is free software: you can redistribute it
 * and/or modify it under the terms of the GNU General
 * Public License as published by the Free Software
 * Foundation, either version 3 of the License, or any
 * later version.

 * This program is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A
 * PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.

 * You should have received a copy of the GNU General
 * Public License along with this program.  If not, see
 * <http://www.gnu.org/licenses/>.

 * Copyright (C) 2009, NoCKTMetal Team
 *
 * Fichero: control-grafico.cpp
 * Autor: Noelia Sales Montes
 * Fecha: 7 de junio de 2009
 * Proyecto: NoCKt Metal
 */

#include "control-grafico.h"
#include "control-combate.h"

ControlGrafico::ControlGrafico(Grupo &g1, Grupo &g2){
  _huida = false;
  _g1 = &g1;
  _g2 = &g2;

#ifdef DEBUG
  cout << "ControlCombate::ControlCombate(Grupo &g1, Grupo &g2)" << endl;
#endif
}

ControlGrafico::~ControlGrafico() {}
