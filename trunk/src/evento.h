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
 * Fichero: evento.h
 * Autor: Noelia Sales Montes
 * Fecha: 21 de abril de 2009
 * Proyecto: NoCKt Metal
 */

#ifndef _EVENTO_Hq
#define	_EVENTO_H

enum tAccion {
	SALIR,
    MENU,
	ACEPTAR,
    ARRIBA,
    ABAJO,
	IZQUIERDA,
	DERECHA
};

/**
 * @brief
 * @author Noelia Sales Montes
 * @date 21 de abril de 2009
 * @note Parte del Proyecto NoCKt Metal
 */
class Evento {
public:
    Evento();
    virtual ~Evento();
private:
    Uint8* estado;
    SDL_Event evento;
    /** Asocia las teclas que necesitamos a la constate SDL que la representa */
    map<tAccion, SDLKey> accion;
};

#endif	/* _EVENTO_H */evewenv

