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
 * Fichero: evento.cpp
 * Autor: Noelia Sales Montes
 * Fecha: 21 de abril de 2009
 * Proyecto: NoCKt Metal
 */

#include <SDL/SDL_keysym.h>
#include <SDL/SDL_events.h>

#include "evento.h"

Evento::Evento() {
    /* Evitar la autorepeticion de teclas */
    SDL_EnableKeyRepeat(0, 0);
    /* Configuracion de eventos con las teclas que los activan */
    _accion[SALIR] = SDLK_ESCAPE;
    _accion[MENU] = SDLK_SPACE;
    _accion[ACEPTAR] = SDLK_RETURN;
    _accion[ATRAS] = SDLK_BACKSPACE;
    _accion[ARRIBA] = SDLK_UP;
    _accion[ABAJO] = SDLK_DOWN;
    _accion[IZQUIERDA] = SDLK_LEFT;
    _accion[DERECHA] = SDLK_RIGHT;
    /** @todo Incluir definiciones de teclas alternativas en caso de querer
     * probar con la PSP. (IFDEF.... blablabla) */
}

Evento::~Evento() {}

accion Evento::getEvento() {
    /* Esperamos a que se produzca el evento */
    while (SDL_PollEvent(&_evento)) {
        /* Comprobamos que es uno de los eventos que esperamos:
         *  - Tecla presionada en este instante
         *  - Tecla presionada anteriormente
         */
        if (_evento.type == SDL_KEYDOWN || _evento.key.state == SDL_PRESSED) {
            /* Devolvemos el tipo de accion que se corresponde con el
             * evento leido */
            for (map<accion,SDLKey>::iterator i = _accion.begin();
            i != _accion.end(); ++i) {
                if (_evento.key.keysym.sym == i->second) {
                    return i->first;
                }
            }
        }
        if (_evento.type == SDL_QUIT) {
            return SALIR;
        }
    }
    return NULA;
}