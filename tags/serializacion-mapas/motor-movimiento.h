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
 * Fichero: motor-movimiento.h
 * Autor: Noelia Sales Montes
 * Fecha: 6 de junio de 2009
 * Proyecto: NoCKt Metal
 */
#ifndef MOTORMOVIMIENTO_H_
#define MOTORMOVIMIENTO_H_

#include "pantalla.h"
#include "animacion.h"
#include "evento.h"

class MotorMovimiento {
public:
	MotorMovimiento();
	MotorMovimiento(Pantalla* p, Evento* e);
	void ejecutar();
	virtual ~MotorMovimiento();

private:
	Pantalla* _pant;
	Animacion* _anim;
	Evento* _evento;
};

inline MotorMovimiento::MotorMovimiento() {}
inline MotorMovimiento::~MotorMovimiento() {}

#endif /* MOTORMOVIMIENTO_H_ */
