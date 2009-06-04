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
#include "sistema.h"
#include "pantalla.h"
#include "menu-principal.h"
#include "animacion.h"
#include "musica.h"

using namespace std;

int main() {

	/* Construcción e inicialización de elementos del motor de combate */
    Biblioteca bib;
    bib.recargarXML("datos-xml/biblioteca.xml");
    cout << "Biblioteca cargada" << endl;

    Grupo AmpliBreakers(bib.getGrupoPrincipal().c_str());

    srand(time(0));
    cout << "Mira que de gente nos quiere pegar: " << bib.getNumeroGruposEnemigos()
            << endl;
    Aleatorio a;
    Uint32 num_rep =
            a.valorEntero(0, bib.getNumeroGruposEnemigos() - 1);
    map<Uint32, string> aux = bib.getGruposEnemigos();

    cout << "Número elegido..." << num_rep << endl;

    map<Uint32, string>::iterator I = aux.begin();
    for (size_t i = 0; i < num_rep; i++) {
        I++;
    }

    Grupo Enemigos(bib.getGrupoEnemigo(I->first).c_str());

    ControlCombate combate(AmpliBreakers, Enemigos);

    if (iniciarSistema()) {

    	/* Construcción e inicialización de elementos del motor de movimiento */
        Pantalla p = Pantalla();
        p.setTitulo("NoCKt Metal", "imagenes/logo.png");

        Animacion anim = Animacion(&p);
        cout << "Animacion creada" << endl;

        Musica m("musica/NIN-1m.ogg");
        m.reproducir();
        cout << "Music on" << endl;

        vector<const char*> botonesMenu;
        botonesMenu.push_back("Motor de movimiento");
        botonesMenu.push_back("Motor de combate");
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
        bool salirAnimacion;

        while (!salir) {
            salirAnimacion = false;

            menu.dibujar();
            while (!menu.actualizar()) {
                ;
            }

            if (menu.getEstadoAceptado()) {
                /* Procesar el boton activado */
                switch (menu.getPosicionCursor()) {
                case 0: /* Motor de movimiento */
                    cout << endl << "--------------------------------------"
                            << "------------------------------------" << endl
                            << " Entrando en el motor de movimiento " << endl
                            << "--------------------------------------"
                            << "------------------------------------" << endl
                            << endl;

                    /* Lanzar motor de movimiento */
                    anim.inicializarAnimacion();
                    cout << "Animacion iniciada" << endl;


                    while (!salirAnimacion) {
                        salirAnimacion = anim.procesarAccion();
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

                    break;
                case 1: /* Motor de combate */
                    cout << endl << "--------------------------------------"
                            << "------------------------------------" << endl
                            << " Entrando en el motor de movimiento " << endl
                            << "--------------------------------------"
                            << "------------------------------------" << endl
                            << endl;

                    /* Lanzar motor de combate */

                    cout << "Seleccionado " << I->first;
                    cout << " " << bib.getGrupoEnemigo(I->first) << endl;

                    AmpliBreakers.mostrarGrupo();
                    Enemigos.mostrarGrupo();

#ifdef DEBUG
                    cout << "Combate inicializado" << endl;
#endif

                    combate.iniciarCombate();
                    combate.postCombate();

                    cout << endl << "--------------------------------------"
                            << "------------------------------------" << endl
                            << " Saliendo del motor de combate " << endl
                            << "--------------------------------------"
                            << "------------------------------------" << endl
                            << endl;
                    break;
                case 2:
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
