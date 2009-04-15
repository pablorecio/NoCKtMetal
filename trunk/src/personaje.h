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

/**
 * @brief La clase Personaje hace de intermediario entre 
 * la clase Sprite y la clase Animacion.
 * @see Sprite.h Animacion.h
 */
class Personaje {
 public:
  
  /**
   * @brief Constructor vacio.
   * Este constructor no hace nada, y además no da lugar a un personaje
   * utilizable posteriormente. Es necesaria para poder definir vectores
   * y otros elementos.
   */
  Personaje();
  /**
   * @brief Constructor de un objeto Personaje
   * Este constructor crea un personaje en una posicion determinada
   * (casilla en un mapa, nada de pixels)
   * @param i Identificador del personaje
   * @param s Sprite con el que esta relacionado el personaje
   * @param x Posicion horizontal
   * @param y Posicion vertical
   */
  Personaje(Uint32 i, Sprite s, Uint32 x, Uint32 y);
  /**
   * @brief Destructor de Personaje
   * Destruye un objeto Personaje
   */
  ~Personaje();
  /**
   * @brief Consultor de identificador de personaje
   * @return Valor del identificador del personaje
   */
  Uint32 getId() const;
  /**
   * @brief Consultor de la posicion horizontal del personaje
   * @return Indice x de la casilla en que se encuentra el personaje
   */
  Uint32 getX() const;
  /**
   * @brief Consultor de la posicion vertical del personaje
   * @return Indice y de la casilla en que se encuentra el personaje
   */
  Uint32 getY() const;
  /**
   * @brief Consultor del sprite del personaje
   * @return Referencia constante al sprite de este personaje
   */
  const Sprite& getSprite() const;
  /**
   * @brief Asociacion con Animacion
   * Se asocia el objeto Personaje actual con un objeto Animacion
   */
  void animadoPor(Animacion& a);
  /**
   * @brief Modificador de la posicion
   * @param x Posicion horizontal
   * @param y Posicion vertical
   */
  void setPosicion(Uint32 x, Uint32 y);
  /**
   * @brief Desplazamiento del personaje una posicion hacia arriba
   */
  void moverArriba();
  /**
   * @brief Desplazamiento del personaje una posicion hacia abajo
   */
  void moverAbajo();
  /**
   * @brief Desplazamiento del personaje una posicion hacia izquierda
   */
  void moverIzda();
  /**
   * @brief Desplazamiento del personaje una posicion hacia derecha
   */
  void moverDcha();
 protected:
  /**
   * Identificador del personaje
   */
  Uint32 id_;
  /**
   * Coordenadas de la casilla en que se encuentra el personaje
   * */
  Uint32 x_, y_;
  /* Rango de casillas en pantalla en las que se puede mover
   * el personaje: deben introducirse en animacion -> Movimiento restringido
  Uint32 rango_ai, rango_ad, rango_bi, rango_bd;
  */
  /**
   * Puntero a un objeto Animacion
   */
  Animacion* anim_;
  /**
   * Composicion de sprite
   */
  Sprite sprite_;
};


/* Funciones get inline: eficiencia */
inline Uint32 Personaje::getX() const { return id_; }
inline Uint32 Personaje::getX() const { return x_; }
inline Uint32 Personaje::getY() const { return y_; }
inline const Sprite& getSprite() const { return sprite_; }

#endif
