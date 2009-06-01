/*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.

 * Copyright (C) 2009, NoCKTMetal Team
 *
 * Fichero: menu.cpp
 * Autor: Noelia Sales Montes
 * Fecha: 28 de mayo de 2009
 * Proyecto: NoCKt Metal
 */

#include <iostream>
#include "menu.h"

using namespace std;


/**********************************************************************
 * Elemento
 **********************************************************************/

Elemento::Elemento() {}

Elemento::Elemento(char* url, Uint32 x, Uint32 y, Pantalla* p):
  _urlImagen(url), _posX(x), _posY(y), _pant(p) {

}

void Elemento::dibujar() {



  _pant->volcarPantalla(texto1, NULL, p_->getBuffer(), &r1);
}


/**********************************************************************
 * Botón
 **********************************************************************/






/**********************************************************************
 * Cursor
 **********************************************************************/





/**********************************************************************
 * Menú
 **********************************************************************/
