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

#include<SDL/SDL.h>
#include<iostream>

#include"animacion.h"
#include"imagen.h"
#include"tile.h"
#include"personaje.h"
#include"sprite.h"
#include"pantalla.h"


Animacion::Animacion(){}

Animacion::Animacion(Imagen *i, Personaje *p, Pantalla *s){

  imag_=i;
  pant_=s;
  pers_=p;

  setMovimientoPersonaje(s,p);
}


void Animacion::iniciarAnimacion(char* fich_img, char* ruta_spr){

  iniciarImagen(fich_img);
  iniciarPersonaje(ruta_spr);
}

void Animacion::realizarMovimiento(char direccion)
{
  switch(dirección){
  case 'u': //arriba;
    break;
  case 'd': //abajo;
    break;
  case 'l': // izquierda;
    break;
  case 'r': //rerecha;
    break;

}




void Animacion::iniciarImagen(char* fich_img){

  // abrir fichero imagen.
  // comprobar que esté abierto.
  // leer 1º tamaños de la matriz (primera linea dos números)
  // crear la matriz dinámica
  // realizar un bucle para rellenar la matriz
  // La última línea del fichero de la matriz contiene la ruta del
  // fichero correspondiente de sus tiles y en orden de índice.
  // cerrar fichero.
  // Crear la imagen con la matriz y los tamaños.
  // 
  // abrir fichero tiles.
  // cmprobar que está abierto.
  // cada línea contiene la ruta del tile que hay que cargar.
  // realizamos un bucle para relacionarlos todos con la imagen
  // *el orden establecido en el fichero es el que relaciona con los
  //  índices de la matriz de imagen* 
}

void Animacion::iniciarPersonaje(char* ruta_spr);

void Animacion::setMovimientoPersonaje(Pantalla *s, Personaje *p){
  
  // transformación de pixel a tiles. Tamaño de la pantalla.
  Uint32 numTilesAncho = s->getAncho()/Tile.getAncho();  
  Uint32 numTilesAlto = s->getAlto()/Tile.getAlto();  
  
  // número de tiles que podrá desplazarse el personaje dentro de la pantalla.
  Uint32 Desplazamiento = 4;

  // identificación de la coordenada arriba izquierda del mini cuadrao.
  Uint32 cX = (numTilesAncho/2)-(Desplazamiento/2);
  Uint32 cY = (numTilesAlto/2)-(Desplazamiento/2);

  p->setRango(cX,cY,Desplazamiento,Desplazamiento);
}
