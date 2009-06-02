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
 * Fichero: main.cpp
 * Autor: Noelia Sales Montes
 * Fecha: 29 de abril de 2009
 * Proyecto: NoCKt Metal
 */

#include "menu.h"


#include <iostream>
#include <SDL/SDL.h>

#include "sistema.h"
#include "pantalla.h"

using namespace std;

int main() {
    if (iniciarSistema()) {
        Pantalla p = Pantalla();
        p.setTitulo("NoCKt Metal", "imagenes/logo.png");

        Menu menu = Menu("imagenes/menu.png", "imagenes/cursor.png", &p);

        menu.setBoton("Menu de movimiento", 270, 20, "imagenes/boton_movimiento.png", 0, 0);
        menu.setBoton("Menu de combate", 290, 70, "imagenes/boton_combate.png", 0, 0);
        menu.setBoton("Salir", 310, 120, "imagenes/boton_salir.png", 0, 0);

        bool salir = false;

        while (!salir) {
            menu.dibujar();
            while (!menu.actualizar()) {
                ;
            }

            if (menu.getEstadoAceptado()) {
                cout << "Estado aceptado" << endl;
                /* Procesar el boton activado */
                switch (menu.getPosicionCursor()) {
                case 0: /* Motor de movimiento */
                    cout << "Motor de movimiento" << endl;
                    /* Lanzar motor de movimiento */
                    
                    
                    break;
                case 1: /* Motor de combate */
                    cout << "Motor de combate" << endl;
                    /* Lanzar motor de combate */
                    break;
                case 2:
                    cout << "Saliendo del juego" << endl;
                    salir = true;
                    break;
                default:
                    break;
                }
            }
            if (menu.getEstadoSalida()) {
                cout << "Saliendo del juego" << endl;
                salir = true;
            }
        }
        
        p.cerrarPantalla();
    } else {
        cerr << "ERROR INICIAL" << endl;
    }
}
