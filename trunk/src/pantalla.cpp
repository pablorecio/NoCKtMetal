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

#include <iostream>
#include <SDL/SDL_image.h>
#include "pantalla.h"

using namespace std;

Pantalla::Pantalla(Uint32 ancho, Uint32 alto, Uint32 prof):
_ancho(ancho), _alto(alto), _prof(prof) {
    atexit(SDL_Quit);
    
    /* Comprobamos que sea compatible el modo de video */
    if(SDL_VideoModeOK(_ancho, _alto, _prof,
                       SDL_HWSURFACE|SDL_DOUBLEBUF) == 0) {
        cerr << "Modo no soportado: " << SDL_GetError() << endl;
        exit(1);
    }
    /* Entrar en el modo gráfico: pantalla principal */
    _pantalla = SDL_SetVideoMode(_ancho, _alto, _prof,
                                 SDL_HWSURFACE|SDL_DOUBLEBUF);

    if(_pantalla == NULL) {
        cerr << "Error al entrar a modo grafico: " << SDL_GetError() << endl;
        exit(1);
    }

    /* Definimos las surfaces de trabajo como transparentes, despues de
     * llamar a SetVideoMode (en caso de hacerlo antes provocaremos
     * que glibc tenga que venir a ayudarnos...) */
    _buffer = SDL_CreateRGBSurface(SDL_HWSURFACE, _ancho, _alto,
                                  _prof, 0, 0, 0, 0);
    _fondo = SDL_CreateRGBSurface(SDL_HWSURFACE, _ancho, _alto,
                                  _prof, 0, 0, 0, 0);
    _movimiento = SDL_CreateRGBSurface(SDL_HWSURFACE, _ancho,
                                       _alto, _prof, 0, 0, 0, 0);
}

Pantalla::~Pantalla() {}

void Pantalla::setTitulo(const char *titulo, const char *icono) {
    /* Configuramos el titulo */
    SDL_WM_SetCaption(titulo, titulo);
    /* Y el icono que se asignara a nuestra ventana principal */
    SDL_Surface* imgIcono = IMG_Load(icono);
    SDL_WM_SetIcon(imgIcono, NULL);
}

void Pantalla::cargarImagen(SDL_Surface *p, const char *imagen) {
    /* Cargamos la imagen en una surface auxiliar y la volcamos en p */
    SDL_Surface* img = IMG_Load(imagen);
    volcarPantalla(img, p);
}

void Pantalla::rellenarPantalla(SDL_Surface *p, Uint32 colorR, Uint32 colorG,
                                Uint32 colorB, Uint32 colorA) {
    SDL_FillRect(p, NULL, SDL_MapRGBA(p->format, colorR, colorG, colorB,
                                      colorA));
}

void Pantalla::volcarPantalla(SDL_Surface *p1) {
    /* Copiar la surface completa p1 en la pantalla principal */
    SDL_BlitSurface(p1, NULL, _pantalla, NULL);
    SDL_Flip(_pantalla);
}

void Pantalla::volcarPantalla(SDL_Surface *p1, SDL_Rect *rectP2) {
    SDL_BlitSurface(p1, rectP2, _pantalla, rectP2);
    SDL_Flip(_pantalla);
}

void Pantalla::volcarPantalla(SDL_Surface *p1, SDL_Surface *p2) {
    SDL_BlitSurface(p1, NULL, p2, &(p1->clip_rect));
    SDL_Flip(p2);
}

void Pantalla::cerrarPantalla() {
    /* Liberamos la memoria de las pantallas creadas */
    SDL_FreeSurface(_buffer);
    SDL_FreeSurface(_fondo);
    SDL_FreeSurface(_movimiento);
    SDL_FreeSurface(_pantalla);
    /* Quitamos la SDL */
    SDL_Quit();
}
