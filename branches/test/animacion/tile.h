
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
 * Fichero = tile.h
 * Autor = Rosa María Durante Lerate
 * Fecha = 15 / 04 / 2009
 */

#ifndef _TILE_H_
#define _TILE_H_

#include <SDL/SDL.h>


/** 
 * Clase que abstrae el concepto de tile como mínima imagen que utilizaremos en este videojuego.
 * @author Rosa María Durante Lerate 
 */

class Tile{
 public:

  Tile();
  // constructores, operador de asignación y destructor.
  Tile(const char *ruta, bool col=false, bool inter=false);
  Tile(const Tile& otro);
  Tile& operator =(const Tile& otro);
  ~Tile();

  // construcción de un SDL_Surface que se utilizará en la clase imagen.
  SDL_Surface* getImagen();

  // observadoras
  char* getRuta();
  static Uint32 getTam();
  bool isColisionable();
  bool isInteractuable();

  // modificadoras
  void setRuta(char* ruta);
  void setColisionable(bool var);
  void setInteractuable(bool var);
  static void setTam(Uint32 tam);

protected:
  char * _ruta;
  bool _colisionable;
  bool _interactuable;
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
