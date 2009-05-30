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
 * Fichero: npj.h
 * Autor: Rosa María Durante Lerate
 * Fecha: 06 05 2009
 * Proyecto: NoCKt Metal
 */

#include <SDL/SLD.h>
#include "imagen.h"
#include "sprite.h"

NPJ::NPJ() {} // para vectores;
NPJ::NPJ(Uint32 i, Uint32 x, Uint32 y, Uint32 amplMov, const char* sprite, Uint32 f = 4, Uint32 c = 4): 
  id_(i), x_(x), y_(y),  px_(x*Tile::getTam()), py_(y*Tile::getTam()), velocidad_(60)
{
  sprite_ = Sprite(sprite, f,c);
  rango_.x = x_; // por tiles.
  rango_.y = y_;
  rango_.h = amplMov;
  rango_.w = amplMov;

  _tam = _sprite.getAncho();

  _desp = vector<Uint32>(getSecuenciasMovimiento());
    for (Uint32 i = 0; i < getSecuenciasMovimiento(); i++) {
        _desp.at(i) = _tam/getSecuenciasMovimiento();
        /* Si la división en pixels no es exacta hay que rellenar pixels
         * de forma equitativa */
        if (i < _tam % getSecuenciasMovimiento()) {
            _desp.at(i)++;
        }
    }
}

void NPJ::subir() { y_ -= 1; }
void NPJ::bajar() { y_ += 1; }
void NPJ::izq() { x_ -= 1; }
void NPJ::drch() { x_ += 1; }
void NPJ::dibujarPosicionFrente(SDL_Surface* i) { moverAbajo(0,i,0); }
void NPJ::dibujarPosicionEspaldas(SDL_Surface* i) { moverArriba(0,i,0); }
void NPJ::dibujarPosicionLatIzda(SDL_Surface* i) { moverIzda(0,i,0); }
void NPJ::dibujarPosicionLatDcha(SDL_Surface* i) { moverDcha(0,i,0); }

void NPJ::moverArriba(Uint32 mov, SDL_Surface* i, Uint32 desp ) 
{
  py_ -= desp;
  mover(sprite_.getMovArriba(), mov, i); 
}

void NPJ::moverAbajo(Uint32 mov, SDL_Surface* i, Uint32 desp ) 
{
  py_ += desp;
  mover(sprite_.getMovAbajo(), mov, i); 
}

void NPJ::moverIzda(Uint32 mov, SDL_Surface* i, Uint32 desp ) 
{ 
  px_ -= desp;
  mover(sprite_.getMovIzda(), mov, i); 
}

void NPJ::moverDcha(Uint32 mov, SDL_Surface* i, Uint32 desp  ) 
{ 
  px_ += desp;
  mover(sprite_.getMovDcha(), mov, i); 
}

void NPJ::mover(Uint32 movimiento, Uint32 secuencia, SDL_Surface* i) {
   SDL_Delay(150 - _velocidad);
   sprite_.dibujar(movimiento, secuencia, i, px_ ,py_);
}
