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
 * --------------------------------------------------------
 * Fichero: personaje.h
 * Autor: Noelia Sales Montes
 * Fecha: 14 / 04 / 2009
 * --------------------------------------------------------
 */

#ifndef _PERSONAJE_
#define _PERSONAJE_

#include "animacion.h"
#include "sprite.h"

/* 
 * @brief La clase Personaje hace de intermediario entre 
 * la clase Sprite y la clase Animacion.
 * @see Sprite.h Animacion.h
 */
class Personaje {
 public:
  Personaje();
  Personaje(Uint32 i, Sprite s);
  Personaje(Uint32 i, Sprite s, Uint32 x, Uint32 y);
  ~Personaje();
  Uint32 getId() const;
  Uint32 getX() const;
  Uint32 getY() const;
  const Sprite& getSprite() const;
  void animadoPor(Animacion& a);
  void setPosicion(Uint32 x, Uint32 y);
  /**
   * @param desp Numero de casillas a desplazar
   */
  void moverArriba();
  void moverAbajo();
  void moverIzda();
  void moverDcha();
 protected:
  Uint32 id_;
  /* Coordenadas de la casilla en que se encuentra el personaje */
  Uint32 x_, y_;
  /* Rango de casillas en pantalla en las que se puede mover
   * el personaje: deben introducirse en animacion -> Movimiento restringido
  Uint32 rango_ai, rango_ad, rango_bi, rango_bd;
  */
  Animacion* anim_;
  Sprite sprite_;
}

inline Uint32 getX() const { return id_; }
inline Uint32 getX() const { return x; }
inline Uint32 getY() const { return y; }
inline const Sprite& getSprite() const { return s; }

#endif
