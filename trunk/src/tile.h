
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
 * 
 * @author Rosa María Durante Lerate 
 */

class Tile{
 public:


  /** 
   * @brief
   * @param ruta
   * @param col
   * @param inter
   */

  Tile(char *ruta, bool col=false, bool inter=false);


  /** 
   * @brief
   */

  ~Tile();


  /** 
   * @brief
   * @return
   */

  static Uint32 getAncho();
  Uint32 getAnchura();


  /** 
   * @brief
   * @return 
   */

  static Uint32 getAlto();
  Uint32 getAltura();


  /** 
   * @brief
   * @return
   */

  SDL_Surface* getImagen();
  

  /** 
   * @brief
   * @return
   */

  bool isColisionable();


  /** 
   * @brief
   * @return 
   */

  bool isInteractuable();

 private:
  SDL_Surface *_imagen;
  Uint32 _colorkey;
  bool _colisionable;
  bool _interactuable;

  static Uint32 _alto;
  static Uint32 _ancho;

};

#endif
