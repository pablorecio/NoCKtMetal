/*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.

 * Copyright (C) 2009, NoCKTMetal Team
 *
 */

#include <iostream>

#include "sprite.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

using namespace std;

Sprite::Sprite() {}

Sprite::Sprite(const char *ruta_imagen, Uint32 numFil, Uint32 numCol,
               Uint32 numEl): _filas(numFil), _columnas(numCol), _num(numEl),
        _mov_abajo(0), _mov_izda(1), _mov_dcha(2), _mov_arriba(3) {
    /* Constructor incompleto mal utilizado: actualizar numero de sprites */
    if (_filas != 1 && _columnas != 1 && _num == 1) {
        _num = _filas * _columnas;
    }

    /* Cargamos la imagen en la pantalla */
    _imagen = IMG_Load(ruta_imagen);

    if (_imagen == NULL) {
        cerr << "Error: " << SDL_GetError() << endl;
        exit(1);
    }

    /* Convertir a formato de pantalla */
    SDL_Surface *tmp = _imagen;
    _imagen = SDL_DisplayFormat(tmp);
    SDL_FreeSurface(tmp);

    if (_imagen == NULL) {
        cerr << "Error: " << SDL_GetError() << endl;
        exit(1);
    }
 
    /* Definicion del color transparente */
    Uint32 colorkey = SDL_MapRGB(_imagen->format, 0, 255, 0);
    SDL_SetColorKey(_imagen, SDL_SRCCOLORKEY, colorkey);

    /* Inicializamos el ancho y alto de un elemento del sprite */
    _ancho = _imagen->w / _columnas;
    _alto = _imagen->h / _filas;
}

Sprite::~Sprite() {}

void Sprite::dibujar(Uint32 fila, Uint32 columna, SDL_Surface *p, Uint32 x,
                     Uint32 y) const {
    /* Sprite inexistente */
    if (fila < 0 || fila >= _filas || columna < 0 || columna >= _columnas) {
        cerr << "sprite::dibujar = No existe la imagen en ("
                << fila << "," << columna << ")" << endl;
        exit(1);
    }

    /* Zona del elemento del sprite a dibujar en la pantalla */
    SDL_Rect rectSprite = {columna * _ancho, fila * _alto, _ancho-1, _alto-1};

    /* Zona de destino de la pantalla */
    SDL_Rect rectPant = {x,y,0,0};

    /* Vocamos la imagen seleccionada en la pantalla de destino */
    SDL_BlitSurface(_imagen, &rectSprite, p, &rectPant);
}

void Sprite::dibujar(Uint32 i, SDL_Surface *p, Uint32 x, Uint32 y) const {
    /* Calculamos la fila y la columna correspondientes al sprite numero i */
    Uint32 fila, columna;
    fila = i / _columnas;
    columna = i % _columnas;

    /* Utilizamos la funcion anterior como auxiliar puesto que la ejecucion
     * es la misma */
    dibujar(fila, columna, p, x, y);
}