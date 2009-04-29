
//-*-C++-*-
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
 
 * --------------------------------------------------------
 * Fichero = tile.cpp
 * Autor = Rosa María Durante Lerate
 * Fecha = 15 / 04 / 2009
 */

#include<iostream>
#include<cstring>

#include<SDL/SDL_image.h>

#include"tile.h"

using namespace std;

Uint32 Tile::_tam = 30;

Tile::Tile(){}

Tile::Tile(const char *ruta, bool col, bool inter) {
  
  _ruta = (char*)malloc(sizeof(char)*(strlen(ruta)+1));
  strcpy(_ruta,ruta);
  _ruta[strlen(ruta)]='\0';
  
  // para saber con que tipo de tile trabajamos. 
  _colisionable=col;
  _interactuable=inter;

}

Tile::Tile(const Tile& otro) {

  _ruta= (char*)malloc(sizeof(char)*(strlen(otro._ruta)+1));
  strcpy(_ruta, otro._ruta);
  _ruta[strlen(otro._ruta)]='\0';

  _colisionable=otro._colisionable;
  _interactuable = otro._interactuable;
  
}


Tile& Tile::operator =(const Tile& otro){
  
  if(this != &otro){
    free(_ruta);
    _ruta= (char*)malloc(sizeof(char)*(strlen(otro._ruta)+1));
    strcpy(_ruta, otro._ruta);
    _ruta[strlen(otro._ruta)]='\0';
    
    _colisionable=otro._colisionable;
    _interactuable = otro._interactuable;
  }

  return *this;
}


Tile::~Tile() {
  free(_ruta);
}


SDL_Surface* Tile::getImagen(){
  
  SDL_Surface *_imagen = IMG_Load(_ruta);

  if(_imagen == NULL) {  
    cerr << "Error: " << SDL_GetError() << endl;;
    exit(1);
  }

  SDL_Surface *tmp = _imagen; 
  _imagen = SDL_DisplayFormatAlpha(tmp);
  SDL_FreeSurface(tmp);

  if(_imagen == NULL) {
    cerr << "Error: " << SDL_GetError() << endl;
    exit(1);
  }

  return _imagen;
}

void Tile::setRuta(char* ruta) {
  
  free(_ruta);
  _ruta = (char*)malloc(sizeof(char)*(strlen(ruta)+1));
  strcpy(_ruta,ruta);
  _ruta[strlen(ruta)]='\0';
}

