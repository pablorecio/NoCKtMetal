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
 * Fichero: menu-principal.h
 * Autor: Noelia Sales Montes
 * Fecha: 4 de junio de 2009
 * Proyecto: NoCKt Metal
 */

#ifndef MENUPRINCIPAL_H_
#define MENUPRINCIPAL_H_

#include <vector>
#include "menu.h"

using namespace std;

/**
 * Clase que abstrae el comportamiento y la visualización del menú principal.
 * @author Noelia Sales Montes
 * @date 4 06 2009
 * @note Parte del Proyecto NoCKt Metal
 * @see menu.h
 */
class MenuPrincipal: public Menu {
public:
	/**
	 * Constructor predeterminado.
	 */
	MenuPrincipal();

	MenuPrincipal(const char* urlFondo, const char* urlCursor,
			const char* urlBoton, Pantalla* p, vector<const char*> mBotones,
			Uint32 posX, Uint32 posY, Sint32 despX = 0, Sint32 despY = 0);

	/**
	 * Destructor de la clase MenuPrincipal.
	 */
	virtual ~MenuPrincipal();

};

/* Métodos inline de la clase MenuPrincipal */
inline MenuPrincipal::MenuPrincipal() {}
inline MenuPrincipal::~MenuPrincipal() {}

#endif /* MENUPRINCIPAL_H_ */
