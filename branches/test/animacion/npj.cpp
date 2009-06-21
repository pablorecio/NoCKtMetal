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

#include <iostream>

#include <SDL/SDL.h>
#include "imagen.h"
#include "sprite.h"

NPJ::NPJ() {} // para vectores;
NPJ::NPJ(Uint32 i, Uint32 x, Uint32 y, const char* sprite, Pantalla* p,
	 Uint32 xmapa, Uint32 ymapa, Uint32 amplMov, Uint32 f, Uint32 c): 
  id_(i), x_(x), y_(y), p_(p)
{
  sprite_ = Sprite(sprite, f,c);
  rango_.x = x_; // por tiles.
  rango_.y = y_;
  rango_.h = amplMov;
  rango_.w = amplMov;

  cx_ = xmapa*Tile::getTam();
  cy_ = ymapa*Tile::getTam();

  establecerPosicion();
  
  //cout << "(x,y): (" << x_ << "," << y_ << ")" << endl;
  //cout << "(cx,cy): (" << cx_ << "," << cy_ << ")" << endl;
  //cout << "(px,py): (" << px_ << "," << py_ << ")" << endl;
  //cout << "(ppx,ppy): (" << ppx_ << "," << ppy_ << ")" << endl;
  
  vel_=60;

  pers_dibujado = (ppx_ < p_->getAncho() && ppy_ < p_->getAlto());

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


void NPJ::establecerPosicion()
{
  px_ = x_*Tile::getTam();
  py_ = y_*Tile::getTam();

  tam_ = Tile::getTam();

  /* Colocación en pixels correcta de los sprites en las casillas */
  if (tam_ != sprite_.getAncho()) {
    if (tam_ < sprite_.getAncho()) {
      /* Si el ancho del sprite es distinto, hay que centrarlo
       * horizontalmente en la casilla */
      px_ -= (sprite_.getAncho() - tam_)/2;
    } else {
      /* Si el ancho del sprite es distinto, hay que centrarlo
       * horizontalmente en la casilla */
      px_ += (tam_ - sprite_.getAncho())/2;
    }
  }
  
  /* Colocación vertical */
  if (tam_ > sprite_.getAlto()) {
    /* Si el alto del sprite es mayor hay que centrarlo */
    py_ += tam_ - sprite_.getAlto()/2;
  } else {
    /* De forma general el sprite se colocará con su borde inferior alineado
     * con el borde inferior de la casilla */
    py_ += tam_ - sprite_.getAlto();
  }

  ppx_ = px_ - cx_;
  ppy_ = py_ - cy_;
  
}

void NPJ::dentroPantalla(Uint32 cx, Uint32 cy){ 

  this->cx_ = cx*Tile::getTam();
  this->cy_ = cy*Tile::getTam();

  establecerPosicion();

  pers_dibujado = (ppx_ < p_->getAncho() && ppy_ < p_->getAlto());
  
}

void NPJ::dentroPantalla(Uint32 cx, Uint32 cy, Uint32 sec, char dir){ 

   this->cx_ = cx*Tile::getTam();
   this->cy_ = cy*Tile::getTam();

   if(sec < desp_.size()){
     for(Uint32 i=0; i<sec; i++){
       switch(dir){
       case 'u': cy_ -= desp_.at(i); 
	 break;
       case 'd': cy_ += desp_.at(i);
	 break;
       case 'l': cx_ -= desp_.at(i);
	 break;
       case 'r': cx_ += desp_.at(i);
	 break;
       }  
     }
   }
  
   establecerPosicion();
   pers_dibujado = (ppx_ < p_->getAncho() && ppy_ < p_->getAlto());
  
 }
  

void NPJ::dibujarPosicion(Uint32 mx, Uint32 my, Uint32 px, Uint32 py)
{
  cout << "identificador: " << id_;
  if(mx == px && my < py) {// posición frente: pj abajo , npj arriba.
    cout << " -> posicion frente" << endl;
    dibujarPosicionFrente();
  } else if(mx == px && my > py){ // posición de espaldas.
    cout << " -> posicion de espaldas" << endl;
    dibujarPosicionEspaldas();
  } else if(my == py && mx < px){ // posicion lateral derecha
    cout << " -> posicion derecha" << endl;
    dibujarPosicionLatDcha();
  } else if(my == py && mx > px){
    cout << " -> posicion izquierda" << endl;
    dibujarPosicionLatIzda();
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
  ppy_ -= desp;
  mover(sprite_.getMovArriba(), mov);
}

void NPJ::moverAbajo(Uint32 mov, Uint32 desp ) 
{
  py_ += desp;
  ppy_ += desp;
  mover(sprite_.getMovAbajo(), mov); 
}

void NPJ::moverIzda(Uint32 mov, Uint32 desp ) 
{ 
  px_ -= desp;
  ppx_ -= desp;
  mover(sprite_.getMovIzda(), mov);
}

void NPJ::moverDcha(Uint32 mov, Uint32 desp  ) 
{ 
  px_ += desp;
  ppx_ += desp;
  mover(sprite_.getMovDcha(), mov);
}

void NPJ::mover(Uint32 movimiento, Uint32 secuencia) {
  /* Trastear cuánto tiempo es necesario para que no se vea raro:
   * que no vaya ya demasiado lento */
  SDL_Delay(150 - vel_);
  /* Dibujamos el personaje en la imagen de secuencia indicada en la
   * posición actualizada de pantalla */
  // cout << "(cx,cy): (" << cx_ << "," << cy_ << ")" << endl;
  // cout << "(x,y): (" << x_ << "," << y_ << ")" << endl;
  // cout << "(px,py): (" << px_ << "," << py_ << ")" << endl;
  // cout << "(ppx,ppy): (" << ppx_ << "," << ppy_ << ")" << endl;
  sprite_.dibujar(movimiento, secuencia, p_->getBuffer(), ppx_, ppy_);
  //p_->volcarPantalla(p_->getBuffer());
}


// bool operator <(const NPJ n1, const NPJ n2)
// {
//   return (n1.getId() < n2.getId());
// }
