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

#ifndef _NPJ_H_
#define _NPJ_H_

/* . Esta clase estará relacionada con la clase IMAGEN ¿Por qué? Pues porque un npj 
 no tiene que aparecer siempre en la pantalla, simplemente tiene que estar en el mapa
 o en un sitio fijo o en un rango pero permanece en el mapa y no en la pantalla. */

/* . Es similar a la clase Personaje pero no es igual, sobretodo por la cuestión anterior. */

/* . Hay que modificar la clase IMAGEN para poder tener varias funcionalidades más: */
/* . -> Incluir un npj en el mapa y poner que esa/s casilla/s (por si se mueve el personaje)
        son colisionables e interactuables. */
/* . -> Además tendremos que poder acceder a que personaje se está colisionando y que interacciones
        se pueden realizar con él. */

#include <SDL/SLD.h>

class Imagen;
class Sprite;

class NPJ {
 public:
 
  enum interaccion {DIALOGO, OBJETO, PELEA};
  
  NPJ(); // para vectores;
  NPJ(Uint32 i, Uint32 x, Uint32 y, const char* sprite, 
      Uint32 amplMov = 2; Uint32 f = 4, Uint32 c = 4);

  Uint32 getId() const;
  Uint32 getX() const;
  Uint32 getY() const;
  void addAccion(const interaccion& i);

  // Devuelve todas las acciones que se tienen que activar cuando 
  // colisiona con el personaje principal.
  std::vector<interaccion>& acciones() const;

  Uint32 getDesp(Uint32 i) const;
  bool fueraRango(Uint32 x, Uint32 y) const;
  Uint32 getSecuenciasMovimiento() const;
  Uint32 getVelocidad() const;
  
  void subir();
  void bajar();
  void izq();
  void drch();
  void dibujarPosicionFrente(SDL_Surface* i);
  void dibujarPosicionEspaldas(SDL_Surface* i);
  void dibujarPosicionLatIzda(SDL_Surface* i);
  void dibujarPosicionLatDcha(SDL_Surface* i);
  void moverArriba(Uint32 mov, SDL_Surface* i, Uint32 desp = 0);
  void moverAbajo(Uint32 mov, SDL_Surface* i, Uint32 desp = 0);
  void moverIzda(Uint32 mov, SDL_Surface* i, Uint32 desp = 0);
  void moverDcha(Uint32 mov, SDL_Surface* i, Uint32 desp = 0);
    
 private:
  void mover(Uint32 movimiento, Uint32 secuencia);

  Uint32 id_;
  Uint32 tam_;
  Uint32 vel_;
  std::vector<Uint32> desp_;
  SDL_Rect rango_;

  Uint32 x_; // TILES 
  Uint32 y_;
  Uint32 px_;
  Uint32 py_;

  std::vector<interaccion> acciones_;
};


inline Uint32 NPJ::getId() const { return id_; }
inline Uint32 NPJ::getX() const { return x_; }
inline Uint32 NPJ::getY() const { return y_; }
  
inline void NPJ::addAccion(const interaccion& i) { acciones_.push_back(i); }

inline std::vector<interaccion>& NPJ::acciones() const { return acciones_; }

inline Uint32 NPJ::getDesp(Uint32 i) const { return desp_.at(i); } 
inline bool NPJ::fueraRango(Uint32 x, Uint32 y) const 
{
  return ((x < (Uint32)rango_.x/tam_) ||
            (x >= ((Uint32)rango_.x/tam_ + rango_.w/tam_)) ||
            (y < (Uint32)rango_.y/tam_) ||
            (y >= ((Uint32)rango_.y/tam_ + rango_.h/tam_)));
}
inline Uint32 NPJ::getSecuenciasMovimiento() const { return sprite_.getColumnas(); }
inline Uint32 NPJ::getVelocidad() const { return vel_; } 


#endif
