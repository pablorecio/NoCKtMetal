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

#include "evento.h"

Evento::Evento() {
    /* Evitar la autorepeticion de teclas */
    SDL_EnableKeyRepeat(0,0);
    /* Configuracion de eventos con las teclas que los activan */
    accion[SALIR] = SDLK_ESCAPE;
    accion[MENU] = SDLK_UP;
    accion[ACEPTAR] = SDLK_RETURN;
    accion[ARRIBA] = SDLK_UP;
    accion[ABAJO] = SDLK_DOWN;
    accion[IZQUIERDA] = SDLK_LEFT;
    accion[DERECHA] = SDLK_RIGHT;
 }

Evento::~Evento() {
 }

tAccion Evento::getEvento() {
    
while (SDL_PollEvent(&evento))   //Poll our SDL key event for any keystrokes.
{
  switch(evento.type) {
    case SDL_KEYDOWN:
      switch(keyevent.key.keysym.sym){
        case SDLK_LEFT:
          charxvel = -1;
          break;
        case SDLK_RIGHT:
          charxvel = 1;
          break;
        case SDLK_UP:
          charyvel = -1;
          break;
        case SDLK_DOWN:
          charyvel = 1;
          break;
        default:
          break;
       }
    case SDL_KEYUP:
      switch(keyevent.key.keysym.sym){
        case SDLK_LEFT:
          charxvel = 0;
          break;
        case SDLK_RIGHT:
          charxvel = 0;
          break;
        case SDLK_UP:
          charyvel = 0;
          break;
        case SDLK_DOWN:
          charyvel = 0;
          break;
        default:
          break;
      }
  }
}
}