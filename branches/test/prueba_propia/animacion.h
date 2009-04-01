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

/*
 * --------------------------------------------------------
 * Fichero = animacion.h
 * Autor = Pablo Recio Quijano
 * Fecha = 31 / 03 / 2009
 * 
 * - Definición de la clase Animacion.
 */

/*-------- Clase en pruebas --------*/

#ifndef _ANIMACION_SPRITE_
#define _ANIMACION_SPRITE_

#include <vector>

#include <SDL/SDL.h>

#include "sprite.h"

/**
 * @brief La clase Animacion se encargara, como su propio nombre indica, 
 * de animar nuestro sprite, usando una serie de marcos del sprite.
 * La idea de esta clase es ser capaz de realizar una animacion, en el sentido
 * de una secuencia determinada de sprites, pudiendo dibujar esa secuencia
 * paso a paso, o indefinidamente en el tiempo.
 *
 * Ejemplo de uso:
 * <code>
 * Sprite s("imagenes/dentacos.png",num_f,num_c);
 * std::vector v = {3,4,5,6,5,4,3}; //esto esta mal, pero sirve de ejemplo
 * Animacion a(s,v,80}; //por decir un valor de retardo
 * 
 * //completar ejemplo
 * </code>
 */
class Animacion{
 public:
  /**
   * @brief Constructor vacio.
   * Este constructor no hace nada, y además no se puede cargar
   * la imagen posteriormente. Aunque no la usemos hace falta para las
   * cargas de vectores y demás.
   */
  Animacion();

  /**
   * @brief Constructor de un objeto de tipo Animacion. Al no tomar
   * una secuencia de sprites en la tabla, toma la tabla entera.
   * @param s Sprite base de la animacion
   * @param r Valor para el retardo entre cada paso del sprite.
   */
  Animacion(Sprite s, Uint32 r);

  /**
   * @brief Constructor de un objeto de tipo animacion, tomando una serie
   * de posiciones determinadas de la tabla de sprites
   * @param s Sprite base de la animacion
   * @param m Cuadros de la tabla de sprites utilizados en la animacion,
   * en orden
   * @param r Valor para el retardo entre cada paso del sprite.
   */
  Animacion(Sprite s, std::vector<int> m, Uint32 r);

  /**
   * @brief Constructor de copia de un objeto Animacion.
   * @param otra Objeto Animacion que queremos copiar
   */
  Animacion(const Animacion& otra);

  /**
   * @brief Destructor del objeto
   */
  ~Animacion();

  /**
   * @brief Dibuja de forma indefinida, todos los pasos de la animacion.
   * @param destino 
   * @param x
   * @param y
   * @param flip
   */
  void animar_inf(SDL_Surface *destino, int x, int y, int flip = 1);

  /**
   * @brief Dibuja el siguiente paso en la animacion.
   * @param destino 
   * @param x
   * @param y
   * @param flip
   */
  void animar_paso(SDL_Surface *destino, int x, int y, int flip = 1);

  /**
   * @brief Funcion consultora para conocer el retardo de la animacion
   * @return Valor del retardo
   */
  Uint32 getRetardo();
 private:
  Sprite _sprite;
  std::vector<int> _marcos;
  Uint32 _retardo;
  //protected: depende de si queremos o no queremos heredar
};

#endif
