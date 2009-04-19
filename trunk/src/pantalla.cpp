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
 * Fichero: pantalla.cpp
 * Autor: Noelia Sales Montes
 * Fecha: 18 04 2009
 * Proyecto: NoCKt Metal
 */

#include <SDL/SDL_image.h>
#include "pantalla.h"


Pantalla::~Pantalla() {
    SDL_FreeSurface(pantalla_);
    SDL_FreeSurface(buffer_);
    SDL_FreeSurface(fondo_);
}

Pantalla::Pantalla(Uint32 ancho, Uint32 alto, Uint32 prof):
ancho_(ancho), alto_(alto), prof_(prof) {

    /* Comprobamos que sea compatible el modo de video */
    if(SDL_VideoModeOK(ancho_, alto_, prof_,
                       SDL_HWSURFACE|SDL_DOUBLEBUF) == 0) {
        cerr << "Modo no soportado: " << SDL_GetError() << endl;
        exit(1);
    }

    /* Entrar en el modo gráfico */
    pantalla_ = SDL_SetVideoMode(ancho_, alto_, prof_,
                                 SDL_HWSURFACE|SDL_DOUBLEBUF);

    if(screen == NULL) {
        printf( "Error al entrar a modo grafico: %s\n", SDL_GetError() );
        SDL_Quit();
        return -1;
    }

    /* Definimos las surfaces de trabajo como transparentes, después de
     * llamar a SetVideoMode */
    buffer_ = SDL_CreateRGBSurface(SDL_HWSURFACE|SDL_SRCALPHA, ancho_, alto_,
                                  prof_, 0, 0, 0, 255);
    fondo_ = SDL_CreateRGBSurface(SDL_HWSURFACE|SDL_SRCALPHA, ancho_, alto_,
                                  prof_, 0, 0, 0, 255);
    movimiento_ = SDL_CreateRGBSurface(SDL_HWSURFACE|SDL_SRCALPHA, ancho_,
                                       alto_, prof_, 0, 0, 0, 255);
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
