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

#include <SDL/SDL.h>
#include "imagen.h"
#include "sprite.h"

NPJ::NPJ() {} // para vectores;
NPJ::NPJ(Uint32 i, Uint32 x, Uint32 y, const char* sprite,  Uint32 amplMov, Uint32 f, Uint32 c): 
  id_(i), x_(x), y_(y), px_(x*Tile::getTam()), py_(y*Tile::getTam())
{
  sprite_ = Sprite(sprite, f,c);
  rango_.x = x_; // por tiles.
  rango_.y = y_;
  rango_.h = amplMov;
  rango_.w = amplMov;

  vel_=60;

  tam_ = sprite_.getAncho();

  desp_ = vector<Uint32>(getSecuenciasMovimiento());
    for (Uint32 i = 0; i < getSecuenciasMovimiento(); i++) {
        desp_.at(i) = tam_/getSecuenciasMovimiento();
        /* Si la división en pixels no es exacta hay que rellenar pixels
         * de forma equitativa */
        if (i < tam_ % getSecuenciasMovimiento()) {
            desp_.at(i)++;
        }
    }
}

void NPJ::subir() { y_ -= 1; }
void NPJ::bajar() { y_ += 1; }
void NPJ::izq() { x_ -= 1; }
void NPJ::drch() { x_ += 1; }
void NPJ::dibujarPosicionFrente() { moverAbajo(0,0); }
void NPJ::dibujarPosicionEspaldas() { moverArriba(0,0); }
void NPJ::dibujarPosicionLatIzda() { moverIzda(0,0); }
void NPJ::dibujarPosicionLatDcha() { moverDcha(0,0); }

void NPJ::moverArriba(Uint32 mov, Uint32 desp ) 
{
  py_ -= desp;
  mover(sprite_.getMovArriba(), mov);
}

void NPJ::moverAbajo(Uint32 mov, Uint32 desp ) 
{
  py_ += desp;
  mover(sprite_.getMovAbajo(), mov); 
}

void NPJ::moverIzda(Uint32 mov, Uint32 desp ) 
{ 
  px_ -= desp;
  mover(sprite_.getMovIzda(), mov);
}

void NPJ::moverDcha(Uint32 mov, Uint32 desp  ) 
{ 
  px_ += desp;
  mover(sprite_.getMovDcha(), mov);
}

void NPJ::mover(Uint32 movimiento, Uint32 secuencia) {
  SDL_Delay(150 - vel_);
  
  //imagen_ = SDL_CreateRGBSurface(SDL_HWSURFACE, sprite_.getAncho(),
  //  sprite_.getAlto(), 24, 0,0,0,0);
  
  sprite_.dibujar(movimiento, secuencia, imagen_->SurfaceNpj(), px_ ,py_);
}
