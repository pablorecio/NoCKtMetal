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
 * Fichero: pantalla.h
 * Autor: Noelia Sales Montes
 * Fecha: 15 / 04 / 2009
 * --------------------------------------------------------
 */

#ifndef _PANTALLA_
#define _PANTALLA_

#include "SDL/SDL.h"

/**
 * @brief Abstraccion de la clase pantalla de la SDL
 */
class Pantalla {
 public:
  /**
   * @brief Constructor de la clase Pantalla
   * @param ancho Ancho de la pantalla
   * @param alto Alto de la pantalla
   * @param prof Profundidad de la pantalla
   */
  Pantalla(Uint32 ancho = 480, Uint32 alto = 360, Uint32 prof = 24);
 private:
  /**
   * Pantalla de la SDL
   */
  SDL_Surface *pantalla_;
}
