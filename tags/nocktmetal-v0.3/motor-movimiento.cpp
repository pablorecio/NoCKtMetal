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
 * Fichero: motor-movimiento.cpp
 * Autor: Noelia Sales Montes
 * Fecha: 6 de junio de 2009
 * Proyecto: NoCKt Metal
 */

#include <iostream>
#include "motor-movimiento.h"
#include "pantalla.h"
#include "animacion.h"
#include "evento.h"

using namespace std;

MotorMovimiento::MotorMovimiento(Pantalla* p, Evento* e): _pant(p), _evento(e) {
	/* Construcción e inicialización de elementos del motor de movimiento */
    _anim = new Animacion(_pant, _evento);
    cout << "Animacion creada" << endl;
}

void MotorMovimiento::ejecutar() {
    cout << endl << "--------------------------------------"
            << "------------------------------------" << endl
            << " Entrando en el motor de movimiento " << endl
            << "--------------------------------------"
            << "------------------------------------" << endl
            << endl;

    /* Lanzar motor de movimiento */
    _anim->inicializarAnimacion();
    cout << "Animacion iniciada" << endl;

    bool salir = false;

    while (!salir) {
        salir = _anim->procesarAccion();
    /*
        if (anim.getEstadoInventario()) {
             * Procesar el guardado de posiciones para
             * no perder el estado actual del pj *
        }
    */
    }

    cout << endl << "--------------------------------------"
            << "------------------------------------" << endl
            << " Saliendo del motor de movimiento " << endl
            << "--------------------------------------"
            << "------------------------------------" << endl
            << endl;

}
