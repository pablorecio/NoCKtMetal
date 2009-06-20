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
 * Fichero: control-grafico.h
 * Autor: Noelia Sales Montes
 * Fecha: 7 de junio de 2009
 * Proyecto: NoCKt Metal
 */

#ifndef CONTROLGRAFICO_H_
#define CONTROLGRAFICO_H_

#include "control-combate.h"
#include "grupo.h"
#include "menu.h"


/**
 * Clase que especifica el control del combate en un modo gráfico.
 * @author Noelia Sales Montes
 * @date 7 junio 2009
 * @version 1.0
 */
class ControlGrafico: public ControlCombate {
public:
	ControlGrafico();
	/* Inicializar los mismos parámetros y además la parte gráfica */
	ControlGrafico(Grupo& g1, Grupo& g2, Pantalla* p);

	virtual ~ControlGrafico();
private:

	/* Redibujar el combate completo */
	Uint32 mostrarCombate();

	Pantalla* _pant;
	SDL_Surface* _base;
	MenuVariable* _menuSup;
	MenuVariable* _menuInf;
};

/* Métodos inline de la clase ControlGrafico */
inline ControlGrafico::ControlGrafico(): ControlCombate() {}
inline ControlGrafico::~ControlGrafico() {}


/**
 * Clase que especifica el control del turno en un modo gráfico.
 * @author Noelia Sales Montes
 * @date 7 junio 2009
 * @version 1.0
 */
class TurnoGrafico: public ControlTurno {
	TurnoGrafico();
};

/* Métodos inline de la clase ControlTurno */
inline TurnoGrafico::TurnoGrafico() {}


#endif /* CONTROLGRAFICO_H_ */
