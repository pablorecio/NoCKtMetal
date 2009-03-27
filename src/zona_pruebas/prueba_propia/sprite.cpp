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

sprite::sprite(){}

sprite::sprite(std::string ruta_imagen, 
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

sprite::sprite(const sprite& otro){
  SDL_Surface* _imagen = otro._imagen;

  int _ancho = otro._ancho;
  int _alto = otro._alto;

  int _filas = otro._filas;
  int _cols = otro._cols;

  int _num = otro._num;
}

sprite::~sprite(){
  SDL_FreeSurface(_imagen);
}

int sprite::getAncho() const{
  return _ancho;
}

int sprite::getAlto() const{
  return _alto;
}

int sprite::getFilas() const{
  return _filas;
}

int sprite::getColumnas() const{
  return _cols;
}

int sprite::getNumSprites() const{
  return _num;
}

void sprite::dibujar(int fila, 
		     int columna, 
		     SDL_Surface* dest, 
		     int x, 
		     int y) const{
 
  //TODO Usar SDL_BlitSurface
    
}

void sprite::dibujar(int i, 
		     SDL_Surface* dest, 
		     int x, 
		     int y) const{
 
  //TODO Usar SDL_BlitSurface

}
