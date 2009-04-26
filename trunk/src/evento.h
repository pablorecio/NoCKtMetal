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

#ifndef _EVENTO_H
#define	_EVENTO_H

#include <SDL/SDL.h>
#include <map>

using namespace std;

enum accion {
    NULA = 0,
    SALIR,
    MENU,
	ACEPTAR,
    ATRAS,
    ARRIBA,
    ABAJO,
	IZQUIERDA,
	DERECHA
};

/**
 * @brief Clase de gestion de eventos.
 * Abstrae los eventos (generados por el usuario) que dan lugar a determinadas
 * acciones.
 * @author Noelia Sales Montes
 * @date 21 de abril de 2009
 * @note Parte del Proyecto NoCKt Metal
 */
class Evento {
public:
    /**
     * Constructor de la clase de gestion de eventos.
     */
    Evento();
    /**
     * Metodo observador de la accion a realizar.
     * @return Identificador de la accion a realizar de tipo <code>accion</code>
     * definido especificamente para esta clase.
     */
    accion getEvento();
    /**
     * Destructor del evento generado.
     */
    virtual ~Evento();
private:
    /**
     * Evento de la libreria SDL abstraido.
     */
    SDL_Event _evento;
    /**
     * Asocia las teclas que necesitamos a la constate SDL que la representa.
     */
    map<accion, SDLKey> _accion;
};

#endif	/* _EVENTO_H */