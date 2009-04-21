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
 * Fichero: pantalla.h
 * Autor: Noelia Sales Montes
 * Fecha: 18 04 2009
 * Proyecto: NoCKt Metal
 */

#ifndef _ANIMACION_H_
#define _ANIMACION_H_

#include"pantalla.h"
#include"imagen.h"
#include"personaje.h"

class Animacion {
 public:
  Animacion();
  Animacion(Pantalla s);

  // Función para inicializar el fondo y el personaje.
  // La pantalla ya está inicializada.
  // Tomaremos los ficheros necesarios para cargar la animación.
  void iniciarAnimacion(char* fich_img, char* ruta_spr);
  void realizarMovimiento(char direccion);

 protected:
  
  Pantalla _pant;
  Imagen _imag;
  Personaje _pers;

  // Teclado *t;

  void iniciarImagen(char* fich_img);
  void iniciarPersonaje(char* ruta_spr);

  void setMovimientoPersonaje();

  void moverPersonaje(char direccion);

};

#endif
