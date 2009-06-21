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
#include "menu.h"


ControlGrafico::ControlGrafico(Grupo &g1, Grupo &g2, Pantalla* p):
	ControlCombate(g1, g2), _pant(p) {

  /* Añadir parte gráfica */
  /* Forma fácil: con imágenes en lugar de tiles */

	_pant->rellenarPantalla(_base, 100, 100, 100, 0);

	/* Pintar los grupos en la base */


  _menuSup = new MenuVariable("./fondo/menu_sup.png",
		  "./fondo/cursor_menu_sup.png", _pant, 480, 100, 0,0);

	  /*_menuSup-> Añadir los botones
	  for(Uint32 c = 0; i < _g1->getNumeroCombatientes(); ++i) {
		  _menuSup->setBoton()
	  }
  */

  _menuInf = new MenuVariable("./fondo/menu_inf.png",
		  "./fondo/cursor_menu_inf.png", _pant, 480, 100, 0, 380);

  //_menuInf-> Añadir los botones

  /* Volcar la base en la pantalla */
  _pant->volcarPantalla(_base);
  /* Volcar los menus.
   * NOTA: Se debe hacer de forma independiente porque son elementos dinámicos.
   */
  _menuSup->dibujar();
  _menuInf->dibujar();
}


void ControlGrafico::mostrarCombate() {
	ControlCombate::mostrarCombate();
	_menuSup->dibujar();
	_menuInf->dibujar();
}
