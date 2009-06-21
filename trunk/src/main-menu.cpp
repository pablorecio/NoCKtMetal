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

#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#include <ctime>
#include <cstdlib>

#include "sistema.h"
#include "menu-principal.h"
#include "menu.h"
#include "motor-movimiento.h"
#include "motor-combate.h"
#include "musica.h"
#include "evento.h"

using namespace std;

void MostrarCreditos(Pantalla* p, Evento* e);

int main() {

    if (iniciarSistema()) {

        Pantalla p = Pantalla();
        p.setTitulo("NoCKt Metal", "imagenes/logo.png");

        Evento e = Evento(100);

        Musica m("musica/NIN-1m.ogg");
        m.reproducir();
        cout << "Music on" << endl;

        /* Construcción e inicialización de elementos del motor de movimiento */
        MotorMovimiento mov(&p, &e);
    	/* MotorCombate com = MotorCombate(); */

        vector<const char*> botonesMenu;
        botonesMenu.push_back("Nueva Partida");
        botonesMenu.push_back("Cargar Partida");
        botonesMenu.push_back("Creditos");
        botonesMenu.push_back("Salir");

        /* Construcción e inicialización del menú principal */
        MenuPrincipal menu = MenuPrincipal("imagenes/menu.png",
        		"imagenes/cursor.png", "imagenes/boton.png", &p, botonesMenu,
        		270, 30, 20, 60);
        /*
        menu.setBoton("Menu de movimiento", 270, 30, "imagenes/boton.png", 0, 0);
        menu.setBoton("Menu de combate", 290, 90, "imagenes/boton.png", 0, 0);
        menu.setBoton("Salir", 310, 150, "imagenes/boton.png", 0, 0);
        */

        bool salir = false;

        while (!salir) {

            menu.dibujar();
            while (!menu.actualizar()) {
                ;
            }

            if (menu.getEstadoAceptado()) {
                /* Procesar el boton activado */
                switch (menu.getPosicionCursor()) {
                case 0: /* Nueva partida */
                	mov.ejecutar();
                	break;
		case 1: /* Cargar partida */
		  cout << "Aún no se puede cargar partida..." << endl;
		  break;
                case 2: /* Créditos */
                	MostrarCreditos(&p, &e);
                	break;
                case 3: /* Salir */
                    cout << endl << "--------------------------------------"
                            << "------------------------------------" << endl
                            << " Saliendo del juego " << endl
                            << "--------------------------------------"
                            << "------------------------------------" << endl
                            << endl;
                    salir = true;
                    break;
                default:
                    break;
                }
            }
            if (menu.getEstadoSalida()) {
                cout << endl << "--------------------------------------"
                        << "------------------------------------" << endl
                        << " Saliendo del juego " << endl
                        << "--------------------------------------"
                        << "------------------------------------" << endl
                        << endl;
                salir = true;
            }
        }

        m.pausar();
        p.cerrarPantalla();
    } else {
        cerr << "ERROR INICIAL" << endl;
    }
}

void MostrarCreditos(Pantalla* p, Evento* e) {
    bool volver = false;

    vector<const char*> credLinea;
    credLinea.push_back("          CRÉDITOS");
    credLinea.push_back(" Juego desarrollado por:");
    credLinea.push_back("      - Rosa María Durante Lerate (rosUnix)");
    credLinea.push_back("      - Pablo Recio Quijano (riku)");
    credLinea.push_back("      - Noelia Sales Montes (nessa)");
    credLinea.push_back("   -> ELEMENTOS VISUALES:");
    credLinea.push_back("  + Extraídos de Battle for Wesnoth (GPL)");
    credLinea.push_back("  + Desarrollado por Noelia Sales Montes (GPL)");
    credLinea.push_back("   -> ELEMENTOS MULTIMEDIA (AUDIO):");
    credLinea.push_back("  + Música Creative Commons (especificada en");
    credLinea.push_back("    la documentación)");
    credLinea.push_back(" Bajo licencia GPLv3");

    credLinea.push_back("  Presione ESC o ENTER para volver al menú...");

    /* Construcción e inicialización del menú principal */
    Menu cred("imagenes/creditos_fondo.png", "imagenes/nulo.png", p);

    for(size_t i = 0; i < credLinea.size(); ++i) {
      cred.setBoton(credLinea.at(i), 50, 50 + 12 * i, "imagenes/nulo.png", 5,5);
    }

    cred.dibujar();

    while (!volver) {
		switch (e->getEvento()) {
		case SALIR: case ACEPTAR: case ATRAS:
			volver = true;
			break;
		default:
			break;
		}
    }
}


