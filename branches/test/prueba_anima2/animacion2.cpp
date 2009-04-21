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
 * Fichero: Animacion_2.cpp
 * Autor: Rosa María Durante Lerate
 * Fecha: 18 04 2009
 * Proyecto: NoCKt Metal
 */

#include<SDL/SDL.h>
#include<iostream>
#include<fstream>

#include<cstring>

#include"imagen.h"
#include"tile.h"
#include"personaje.h"
#include"sprite.h"
#include"pantalla.h"
#include"animacion2.h"

Animacion::Animacion(){}

Animacion::Animacion(Pantalla s): _pant(s){}


void Animacion::iniciarAnimacion(char* fich_img, char* ruta_spr){

  std::cout << "IMAGEN "<< std::endl;
  iniciarImagen(fich_img);
  std::cout << "Personaje" << std::endl;
  iniciarPersonaje(ruta_spr);

  std::cout << "fondo" << std::endl;
  _imag.dibujarFondo(0,0,_pant.getFondo());
  _pant.volcarPantalla(_pant.getFondo());
  SDL_Delay(500);

}

void Animacion::realizarMovimiento(char direccion)
{
  switch(direccion){

  case 'u': 
    // para subir el muñeco debemos decrementar la altura.
    if(!(_pers.fueraRango(_pers.getX(), _pers.getY()-1))){
      _pers.moverArriba(0,1);
    }
    else{
      if(_imag.getCoorY() > 0){
	_imag.dibujarFondo(_imag.getCoorX(), _imag.getCoorY()-1, 
			    _pant.getFondo());
	_pant.volcarPantalla(_pant.getFondo());
      }
      _pers.dibujarPosicionEspaldas();
      
    }
    break;

  case 'd': //abajo;
    if(!(_pers.fueraRango(_pers.getX(), _pers.getY()+1))){
      _pers.moverAbajo(0,1);
    }
    else{
      if(_imag.getCoorY() < _pant.getAlto()/_Tam_Tile){
	_imag.dibujarFondo(_imag.getCoorX(), _imag.getCoorY()+1, 
			    _pant.getFondo());
	_pant.volcarPantalla(_pant.getFondo());
      }
      _pers.dibujarPosicionFrente();
    }
    break;

  case 'l': // izquierda;
    if(!(_pers.fueraRango(_pers.getX()-1, _pers.getY()))){
      _pers.moverIzda(0,1);
    }
    else{
      if(_imag.getCoorX() > 0){
	_imag.dibujarFondo(_imag.getCoorX()+1, _imag.getCoorY(), 
			    _pant.getFondo());
	_pant.volcarPantalla(_pant.getFondo());
      }
      _pers.dibujarPosicionLatIzda();
    }
    break;

  case 'r': //rerecha;
    if(!(_pers.fueraRango(_pers.getX()+1, _pers.getY()))){
      _pers.moverDcha(0,1);
    }
    else{
      if(_imag.getCoorX() < _pant.getAncho()/_Tam_Tile){
	_imag.dibujarFondo(_imag.getCoorX()+1, _imag.getCoorY(), 
			    _pant.getFondo());
	_pant.volcarPantalla(_pant.getFondo());
      }
      _pers.dibujarPosicionLatDcha();
    }
    break;
  }
  
}





void Animacion::iniciarImagen(char* fich_img){

  std::ifstream datos(fich_img);
  Uint32 tam1,tam2,aux;

  datos >> tam1;
  std::cout << "tamaño1: " << tam1 << std::endl;
  datos >> tam2;
  std::cout << "tamaño2: " << tam2 << std::endl;

  Uint32 **matriz = (Uint32**)malloc(sizeof(Uint32*)*tam1);
  for(int i=0; i<tam1; i++){
    matriz[i] = (Uint32*)malloc(sizeof(Uint32)*tam2);
  }

  std::cout << "Matriz creada." << std::endl;

  for(Uint32 i=0; i<tam1; i++)
    for(Uint32 j=0; j<tam2; j++){
      datos >> aux;
      matriz[i][j]=aux;
    }
  
  std::cout << "Matriz inicializada" << std::endl;

  Imagen i(matriz, tam1, tam2);
  _imag=i;

  // Inicialización de tile

  _imag.relacionarTile(&Tile("arena.png"));
  std::cout << "tile1" << std::endl;
  _imag.relacionarTile(&Tile("acero1.png"));
  std::cout << "tile2" << std::endl;
  _imag.relacionarTile(&Tile("suelo.png"));
  std::cout << "tile3" << std::endl;

  std::cout << "tiles inicializados " << std::endl;

  _imag.dibujarFondo(0,0,_pant.getFondo());
  _pant.volcarPantalla(_pant.getFondo());


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

void Animacion::iniciarPersonaje(char* ruta_spr)
{
  Sprite s(ruta_spr);
  Personaje p(0);
  p.animadoEn(_pant);
  p.dibujadoPor(s);
  _pers=p;

  setMovimientoPersonaje();

  _pers.dibujarPosicionFrente();
}

void Animacion::setMovimientoPersonaje(){
  
  // transformación de pixel a tiles. Tamaño de la pantalla.
  Uint32 numTilesAncho = _pant.getAncho()/_Tam_Tile;  
  Uint32 numTilesAlto = _pant.getAlto()/_Tam_Tile;  
  
  // número de tiles que podrá desplazarse el personaje dentro de la pantalla.
  Uint32 Desplazamiento = 4;

  // identificación de la coordenada arriba izquierda del mini cuadrao.
  Uint32 cX = (numTilesAncho/2)-(Desplazamiento/2);
  Uint32 cY = (numTilesAlto/2)-(Desplazamiento/2);

  _pers.setRango(cX,cY,Desplazamiento,Desplazamiento);
  // situamos el personaje en el centro del rectangulo.
  _pers.setPosicion(cX+ (Desplazamiento/2) ,cY+ (Desplazamiento/2));
}
