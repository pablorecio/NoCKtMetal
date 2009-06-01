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
#include <SDL/SDL.h>

#include "sistema.h"
#include "pantalla.h"
#include "animacion.h"
#include "musica.h"


using namespace std;

int main() {
    if (iniciarSistema()) {
        Pantalla p = Pantalla();
        p.setTitulo("NoCKt Metal", "./logo.png");

        Musica m("musica/NIN-1m.ogg");
        m.reproducir();
        cout << "Music on" << endl;

        Animacion a = Animacion(&p);
        cout << "Animacion creada" << endl;
        a.inicializarAnimacion();
        cout << "Animacion iniciada" << endl;

        bool salir = false;

        while (!salir) {
            salir = a.procesarAccion();
        }

        cout << "Music off" << endl;
        m.pausar();

        cout << "Saliendo de la pantalla" << endl;
        p.cerrarPantalla();
    } else {
        cerr << "ERROR INICIAL" << endl;
    }
}