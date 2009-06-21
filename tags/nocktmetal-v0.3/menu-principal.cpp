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
 * Fichero: menu-principal.cpp
 * Autor: Noelia Sales Montes
 * Fecha: 4 de junio de 2009
 * Proyecto: NoCKt Metal
 */

#include "menu-principal.h"


MenuPrincipal::MenuPrincipal(const char* urlFondo, const char* urlCursor,
		const char* urlBoton, Pantalla* p, vector<const char*> mBotones,
		Uint32 posX, Uint32 posY, Sint32 despX, Sint32 despY):
		Menu(urlFondo, urlCursor, p) {

	for (unsigned int i = 0; i < mBotones.size(); ++i) {
		setBoton(mBotones.at(i), posX + i*despX, posY + i*despY, urlBoton, 0,0);
	}
}
