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

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "sprite.h"

using namespace std;

Sprite::Sprite(){}

Sprite::Sprite(const char *ruta_imagen, Uint32 num_f, Uint32 num_c,
               Uint32 num_s, Uint32 abajo, Uint32 izda, Uint32 dcha,
               Uint32 arriba):
               _filas(num_f), _cols(num_c), _num(num_s), _mov_abajo(abajo),
               _mov_izda(izda), _mov_dcha(dcha), _mov_arriba(arriba) {
    /* Constructor incompleto mal utilizado: Sprite ("cad", 4,4) */
    if (_filas != 1 && _cols != 1 && _num == 1) {
         _num = _filas * _cols;
    }
  
  /*
  _imagen = IMG_Load(ruta_imagen);

  if( _imagen == NULL ) {
    cerr << "Error: " << SDL_GetError() << endl;
    SDL_Quit();
    exit(1); //TODO Excepciones en vez de exit(1)
  }
*/

  // Convertir a formato de pantalla
  SDL_Surface *tmp = IMG_Load(ruta_imagen);
  _imagen = SDL_DisplayFormatAlpha(tmp);
  SDL_FreeSurface(tmp);

  if(_imagen == NULL) {
    cerr << "Error: " << SDL_GetError() << endl;
    exit(1);
  }
/*
  //Definimos el color transparente.
  //TODO Buscar transparencia en .png
  Uint32 colorkey = SDL_MapRGB(_imagen->format, 0, 255, 0);

  SDL_SetColorKey(_imagen, SDL_SRCCOLORKEY,colorkey);
*/

  _ancho = _imagen->w / _cols;
  _alto = _imagen->h / _filas;
  
}

Sprite::Sprite(const Sprite& otro) {
  _imagen = otro._imagen;

  _ancho = otro._ancho;
  _alto = otro._alto;

  _filas = otro._filas;
  _cols = otro._cols;

  _num = otro._num;
}

Sprite::~Sprite(){
  SDL_FreeSurface(_imagen);
}

void Sprite::dibujar(Uint32 fila, Uint32 columna, SDL_Surface *dest, Uint32 x,
                     Uint32 y) const {

  if (fila < 0 || fila >= _filas || columna <0 || columna >= _cols){
      cerr << "sprite::dibujar = No existe la imagen en ("
	   << fila << "," << columna << ")" << endl;
      exit(1);
    }
    
    SDL_Rect src_rect; //rectangulo de origen, en la página de sprites
    
    src_rect.x = columna * _ancho;
    src_rect.y = fila * _alto;
    
    src_rect.w = _ancho - 1; //damos un margen a la rejilla
    src_rect.h = _alto - 1;
    
    SDL_Rect dst_rect;
    
    dst_rect.x = x;
    dst_rect.y = y;
    
    dst_rect.w = 0; //no aplica en el destino
    dst_rect.h = 0;
    
    SDL_BlitSurface(_imagen, &src_rect, dest, &dst_rect);
}

void Sprite::dibujar(Uint32 i, SDL_Surface *dest, Uint32 x, Uint32 y) const {

  if ( i < 0 || i >= _num){
    cerr << "Sprite::dibujar = No existe la imagen numero " 
	 << i << endl;
    exit(1);
  }
  
  Uint32 fila, columna;

  fila = i / _cols;
  columna = i % _cols;
    
  SDL_Rect src_rect; //rectangulo de origen, en la página de sprites
  
  src_rect.x = columna * _ancho;
  src_rect.y = fila * _alto;
  
  src_rect.w = _ancho - 1; //damos un margen a la rejilla
  src_rect.h = _alto - 1;
  
  SDL_Rect dst_rect;
  
  dst_rect.x = x;
  dst_rect.y = y;
  
  dst_rect.w = 0; //no aplica en el destino
  dst_rect.h = 0;
  
  SDL_BlitSurface(_imagen, &src_rect, dest, &dst_rect);
}
