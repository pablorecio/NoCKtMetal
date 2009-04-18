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
 * --------------------------------------------------------
 * Fichero: pantalla.cpp
 * Autor: Noelia Sales Montes
 * Fecha: 15 / 04 / 2009
 * --------------------------------------------------------
 */

#include <SDL/SDL_image.h>
#include "pantalla.h"


Pantalla::~Pantalla() {
    SDL_FreeSurface(pantalla_);
    SDL_FreeSurface(buffer_);
    SDL_FreeSurface(fondo_);
}

Pantalla::Pantalla(Uint32 ancho, Uint32 alto, Uint32 prof) {
    /* Comprobamos que sea compatible el modo de video */
    if(SDL_VideoModeOK(ancho, alto, prof, SDL_HWSURFACE|SDL_DOUBLEBUF) == 0) {
        cerr << "Modo no soportado: " << SDL_GetError() << endl;
        exit(1);
    }
    pantalla_ = SDL_SetVideoMode(ancho, alto, prof, SDL_HWSURFACE|SDL_DOUBLEBUF);
}

Pantalla::setTitulo(const char *titulo, const char *icono) {
    SDL_WM_SetCaption(titulo, icono);
}

void Pantalla::cargarImagen(SDL_Surface *p, const char *imagen) {
    p = IMG_Load(imagen);
}

void Pantalla::volcarPantalla(SDL_Surface *p1, SDL_Surface *p2) {
    SDL_BlitSurface(p1, NULL, p2, &(p1->clip_rect));
    SDL_Flip(p2);
}

void Pantalla::cerrarPantalla() {
    this->~Pantalla();
}
