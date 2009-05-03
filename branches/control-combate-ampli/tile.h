
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
 * Fichero = tile.h
 * Autor = Rosa María Durante Lerate
 * Fecha = 15 / 04 / 2009
 */

#ifndef _TILE_H_
#define _TILE_H_

#include <SDL/SDL.h>


/** 
 * @brief Clase que abstrae el concepto de tile como mínima imagen que se utilizará.
 * Abstrae la carga de dicha imagen a memoria, así como sus propiedades y características.
 * @author Rosa María Durante Lerate
 * @version 2.0
 * @note Parte del Proyecto NoCKt Metal
 */

class Tile{
 public:

  /**
   * @brief Constructor vacío de la clase.
   */
  Tile();

  /**
   * @brief Constructor a partir de la ruta (relativa) del tile necesitado.
   * También podemos indicar si este tipo de imagen va a ser colisionable (el personaje
   * no va a poder atraversarlo) y/o interactuable (el personaje podrá ejercer una acción
   * con la imagen).
   * @param ruta Cadena de caracteres que contiene la ruta del fichero de la imagen.
   * @param col Parámetro booleano que informa si la imagen es colisionable o no (por defecto
   * es <code>false</code>.
   * @param inter Parámetro booleano que informa si la imagen es interactuable o no (por
   * defecto es <code>false</code>.
   */
  Tile(const char *ruta, bool col=false, bool inter=false);

  /**
   * @brief Constructor por copia de otro tile.
   * @param otro Tile con el que queremos crear una copia.
   */
  Tile(const Tile& otro);

  /**
   * @brief Operador de asignación para la clase Tile.
   * @param otro Tile con el que queremos asignar a otro objeto Tile.
   */
  Tile& operator =(const Tile& otro);

  /**
   * @Brief Destructor de la clase.
   */
  ~Tile();

  /**
   * @brief Función que crea y devuelve un tipo <code>SDL_Surface</code> en el
   * cual está cargada la imagen del tile. La función crea la variable, carga la imagen
   * definida en su ruta en dicha <code>SDL_Surface</code> y la devuelve.
   * @return Devuelve un tipo <code>SDL_Surface</code> que contiene la imagen.
   */
  SDL_Surface* getImagen();

  /**
   * @brief Función observadora que devuelve la ruta de la imagen.
   * @return Devuelve una cadena de caracteres conteniendo la ruta de la imagen.
   */
  char* getRuta();

  /**
   * @brief Función estática de la clase que devuelve el tamaño en pixels de la imagen.
   * Como es de esperar, hemos considerado a este tipo de imágenes de forma cuadrada.
   * @return Devuelve un tipo entero <code>Uint32</code> conteniendo el número de pixels
   * que tiene la imagen tanto de alto como de ancho.
   */
  static Uint32 getTam();

  /**
   * @brief Función que informa si la imagen es colisionable o no.
   * @return Devuelve un tipo <code>bool</code> tomando valor <code>true</code> si 
   * es colisionable y el personaje no podría atravesarlo y toma valor <code>false</code>
   * cuando no es colisionable y el personaje podría atravesar la imagen.
   */
  bool isColisionable();

  /**
   * @brief Función que informa si la imagen es interactuable o no.
   * @return Devuelve un tipo <code>bool</code> tomando valor <code>true</code> si 
   * es interactuable y el personaje podría ejercer una acción sobre la imagen y toma
   * valor <code>false</code> cuando no es interactuable y el personaje no podría ejercer
   * ninguna acción sobre la imagen.
   */
  bool isInteractuable();

  /**
   * @brief Función modificadora para la ruta de la imagen.
   * @param ruta Cadena de caracteres que contiene la ruta relativa de la imagen del tile.
   */
  void setRuta(char* ruta);

  /**
   * @brief Función que modifica el estado 'Colisionable' del objeto tile.
   * @param var Variable de tipo <code>bool</code> conteniendo el valor que se modificará
   * para la característica 'colisionable'.
   */
  void setColisionable(bool var);

  /**
   * @brief Función que modifica el estado de 'Interactuable' del objeto tile.
   * @param var Variable de tipo <code>bool</code> conteniendo el valor que se modificará
   * para la característica 'interactuable'.
   */
  void setInteractuable(bool var);

  /**
   * @brief Función estática que modifica el tamaño de la imagen.
   * @param tam Variable de tipo <code>Uint32</code> conteniendo el valor del nuevo
   * tamaño para la imagen de los tiles.
   */
  static void setTam(Uint32 tam);

protected:

  /**
   * @brief Cadena de caracteres que contiene la ruta relativa donde se encuentra la imagen.
   */
  char * _ruta;
  /**
   * @brief Variable booleana que guarda la información de si el tile es colisionable.
   */
  bool _colisionable;
  /**
   * @brief Variable booleana que guarda la información de si el tile es interactuable. 
   */
  bool _interactuable;
  /**
   * @brief Entero que almacena el tamaño del tile.
   */
  static Uint32 _tam;
};

inline char* Tile::getRuta() { return _ruta; }
inline Uint32 Tile::getTam() { return _tam; }
inline void Tile::setTam(Uint32 tam) { _tam = tam; }

inline bool Tile::isColisionable() { return _colisionable; }
inline bool Tile::isInteractuable() { return _interactuable; }

inline void Tile::setColisionable(bool var) { _colisionable=var; }
inline void Tile::setInteractuable(bool var) { _interactuable=var; }


#endif
