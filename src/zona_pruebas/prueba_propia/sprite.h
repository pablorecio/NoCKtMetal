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
 *
 */

/*
 * --------------------------------------------------------
 * Fichero = sprite.h
 * Autor = Pablo Recio
 * Fecha = 26 / 03 / 2009
 * 
 * - Definición de la clase Sprite.
 *
 * La clase Sprite se encargara de cargar una imagen conteniendo
 * una serie de sprites y gestionar el acceso a cada sprite individual, 
 * así como el dibujarlo sobre una SDL_Surface y demás.
 */

/*-------- Clase en pruebas --------*/

#ifndef _SPRITE_GENERICO_
#define _SPRITE_GENERICO_

#include <SDL/SDL.h>

#include <string>


/**
 * @brief Clase que modela un tratamiento generico de los sprites.
 *
 * Con ella conseguiremos abstraer un poco las funciones de la SDL para
 * cargar las páginas de sprites y acceder a cada sprite individual de una
 * forma mas intuitiva.
 *
 * La idea sera hacer un uso similar al siguiente:
 * <code>sprite s1("./imagenes/baldomero.png",4,4);</code>
 * Por ejemplo, consideramos que la matriz de sprites tiene 4 filas 
 * y 4 columnas.
 *
 */
class sprite{
 public:
  //----- Constructores --------

  /**
   * @brief Constructor vacio.
   * Este constructor no hace nada, y además no se puede cargar
   * la imagen posteriormente. Aunque no la usemos hace falta para las
   * cargas de vectores y demás.
   */
  sprite();

  /**
   * @brief Constructor de un objeto tipo sprite.
   * Este constructor toma el numero de filas del sprite 
   */
  sprite(std::string ruta_imagen, int num_f = 1, int num_c = 1, int num_s = 1);

  /**
   * @brief Constructor de copia.
   * @param otro Objeto sprite que queremos copiar
   */
  sprite(const sprite& otro);

  /**
   * @brief Destructor del objeto.
   */
  ~sprite();

  //------- Consultoras --------- //INLINE?

  int getAncho() const;
  int getAlto() const;

  int getFilas() const;
  int getColumnas() const;

  int getNumSprites() const;

  /**
   * @brief Función que nos dibuja un sprite determinado de una superficie
   * de la SDL.
   * @param fila Fila donde esta situado el sprite
   * @param columna Columna donde esta situado el sprite
   * @param dest Superficie de destino donde vamos a dibujar el sprite
   * @param x Desplazamiento horizontal en la superficie
   * @param y Desplazamiento vertical en la superficie
   */
  void dibujar(int fila, int columna, SDL_Surface* dest, int x, int y) const;
  
  /**
   * @brief Función que nos dibuja un sprite determinado de una superficie
   * de la SDL.
   * @param n Numero de sprite de 0 a n-1.
   * @param dest Superficie de destino donde vamos a dibujar el sprite
   * @param x Desplazamiento horizontal en la superficie
   * @param y Desplazamiento vertical en la superficie
   */
  void dibujar(int i, SDL_Surface* dest, int x, int y) const;

  //TODO Buscar mas funciones que definir e implementar. Cortar? 

 private:
 //protected: Si sprite hereda, cambiaremos private por protected

  //Superficie SDL donde almacenamos la matriz de sprites
  SDL_Surface* _imagen;

	
  // Ancho y alto imagen individual.
  int _ancho;
  int _alto;

  // Filas y columnas
  int _filas;
  int _cols;

  // Numero de sprites en la matriz.
  int _num;
};

#endif
