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
    _accion[SDLK_ESCAPE] = SALIR;
    _accion[SDLK_SPACE] = MENU;
    _accion[SDLK_RETURN] = ACEPTAR;
    _accion[SDLK_BACKSPACE] = ATRAS;
    _accion[SDLK_UP] = ARRIBA;
    _accion[SDLK_DOWN] = ABAJO;
    _accion[SDLK_LEFT] = IZQUIERDA;
    _accion[SDLK_RIGHT] = DERECHA;
    /* Todas las teclas desactivadas en un principio */
    _activa[SALIR] = false;
    _activa[MENU] = false;
    _activa[ACEPTAR] = false;
    _activa[ATRAS] = false;
    _activa[ARRIBA] = false;
    _activa[ABAJO] = false;
    _activa[IZQUIERDA] = false;
    _activa[DERECHA] = false;

    /** @todo Incluir definiciones de teclas alternativas en caso de querer
     * probar con la PSP. (IFDEF.... blablabla) */
}

Evento::~Evento() { }

void Evento::actualizar() {
    /* Esperamos a que se produzca el evento */
    while (SDL_PollEvent(&_evento)) {
        /* Comprobamos que es uno de los eventos que esperamos:
         *  - Tecla presionada en este instante
         *  - Tecla presionada anteriormente
         */
        if (_evento.type == SDL_KEYDOWN) {
            map<SDLKey, accion>::iterator aux = _accion.find(_evento.key.keysym.sym);
            _activa[aux->second] = true;
        }
        if (_evento.type == SDL_KEYUP) {
            map<SDLKey, accion>::iterator aux = _accion.find(_evento.key.keysym.sym);
            _activa[aux->second] = false;
        }
        if (_evento.type == SDL_QUIT) {
            _activa[SALIR] = true;
        }
    }
}

accion Evento::getEvento() {
    actualizar();
    for (map < accion, bool>::iterator i = _activa.begin();
         i != _activa.end(); ++i) {
        if (i->second == true) {
            return i->first;
        }
    }
    return NULA;
}