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

Sprite::Sprite(std::string ruta_imagen,
	       int num_f,// = 1, 
	       int num_c,// = 1, 
	       int num_s/* = 1*/): _filas(num_f), _cols(num_c), _num(num_s){
  
  _imagen = IMG_Load(ruta_imagen.c_str());

  if( _imagen == NULL ) {
    cerr << "Error: " << SDL_GetError() << endl;;
    exit(1); //TODO Excepciones en vez de exit(1)
  }

  //Vamos a convertirla a formato de pantalla

  SDL_Surface *tmp = _imagen;
  _imagen = SDL_DisplayFormat(tmp);
  SDL_FreeSurface(tmp);

  if(_imagen == NULL) {
    cerr << "Error: " << SDL_GetError() << endl;
    exit(1);
  }

  //Definimos el color transparente.
  //TODO Buscar transparencia en .png
  Uint32 colorkey = SDL_MapRGB(_imagen->format, 0, 255, 0);

  SDL_SetColorKey(_imagen, SDL_SRCCOLORKEY,colorkey);

  _ancho = _imagen->w / _cols;
  _alto = _imagen->h / _filas;
  
}

Sprite::Sprite(const Sprite& otro){
  SDL_Surface* _imagen = otro._imagen;

  int _ancho = otro._ancho;
  int _alto = otro._alto;

  int _filas = otro._filas;
  int _cols = otro._cols;

  int _num = otro._num;
}

Sprite::~Sprite(){
  SDL_FreeSurface(_imagen);
}

void Sprite::dibujar(int fila,
		     int columna, 
		     SDL_Surface *dest, 
		     int x, 
		     int y) const{
 
  //TODO Usar SDL_BlitSurface
  //El uso de SDL_BlitSurface:
  //int SDL_BlitSurface(SDL_Surface *src, 
                      //SDL_Rect *srcrect, 
                      //SDL_Surface *dst, 
                      //SDL_Rect *dstrect);

  //La idea es (creo) dibujar el rectangulo srcrect de src en el rectangulo
  //dstrect de dst

  //Los rectangulos (SDL_Rect) tenemos que iniciarlos y colocarlos en pantalla

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

void Sprite::dibujar(int i,
		     SDL_Surface *dest, 
		     int x, 
		     int y) const{
  if ( i < 0 || i >= _num){
    cerr << "Sprite::dibujar = No existe la imagen numero " 
	 << i << endl;
    exit(1);
  }
  
  int fila, columna;

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
