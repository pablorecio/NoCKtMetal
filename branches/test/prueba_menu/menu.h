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
 * Fichero: menu.h
 * Autor: Noelia Sales Montes
 * Fecha: 28 de mayo de 2009
 * Proyecto: NoCKt Metal
 */

#ifndef _MENU_H
#define	_MENU_H

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "evento.h"
#include "pantalla.h"

using namespace std;

class Menu {
public:
    Menu(char* urlFondo);
    /* Devuelve el codigo (orden) del boton activado, o el valor siguiente al
     último en caso de error */
    Uint32 getPosicionCursor() const;
    void setNuevoBoton(char* mensaje, Uint32 posX, Uint32 poxY, char* url,
                       Uint32 espacioX, Uint32 espacioY);
    void setCursor(char* url, Uint32 posicion, Uint32 espacio);
    void dibujarMapa();
    void actualizarMapa();
    virtual ~Menu();
private:

    void dibujarBotones();
    void moverCursor();
    /**
     * Puntero a la pantalla general del juego.
     */
    Pantalla* _pant;
    /**
     * Objeto de la clase evento que controlará las acciones solicitadas por el
     * usuario.
     */
    Evento evento;
    /**
     * Botón actual que está activado.
     */
    Uint32 _botonActivo;

};

#endif	/* _MENU_H */