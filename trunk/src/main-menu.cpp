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
#include <iostream>
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
#include "menu.h"

using namespace std;

int main() {

    Biblioteca bib;
    bib.recargarXML("datos-xml/biblioteca.xml");
    cout << "Biblioteca cargada" << endl;

    Grupo AmpliBreakers(bib.getGrupoPrincipal().c_str());

    srand(time(0));
    cout << "WOLA RUBIOOOO " << bib.getNumeroGruposEnemigos()
            << endl;
    Aleatorio a;
    Uint32 num_rep =
            a.valorEntero(0, bib.getNumeroGruposEnemigos() - 1);
    map<Uint32, string> aux = bib.getGruposEnemigos();

    cout << "NUMERO ELEGIDO ES.............." << num_rep
            << endl;

    map<Uint32, string>::iterator I = aux.begin();
    for (size_t i = 0; i < num_rep; i++) {
        I++;
    }

    Grupo Enemigos(bib.getGrupoEnemigo(I->first).c_str());

    ControlCombate combate(AmpliBreakers, Enemigos);

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

                    cout << "Seleccionado " << I->first;
                    cout << " " << bib.getGrupoEnemigo(I->first) << endl;

                    AmpliBreakers.mostrarGrupo();
                    Enemigos.mostrarGrupo();

#                    ifdef DEBUG
                    cout << "Combate inicializado" << endl;
#                    endif

                    combate.iniciarCombate();
                    combate.postCombate();

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