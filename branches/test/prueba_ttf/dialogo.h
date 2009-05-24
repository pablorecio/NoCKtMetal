
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
 * Fichero: dialogo.cpp
 * Autor: Rosa María Durante Lerate
 * Fecha: 24 05 2009
 * Proyecto: NoCKt Metal
 */

#ifndef _DIALOGO_H_
#define _DIALOGO_H_

#include <SDL/SDL_ttf.h>
#include <map>
#include "pantalla.h"

// Es necesario inicializar el subsistema de fuentes:
// if(TTF_Init() == 0) {
//	atexit(TTF_Quit);
//        cout << "TTF inicializada" << endl;	
//    }

// Necesario XD
class Mensaje{
 public:
  Mensaje(Uint32 personaje_hablador, const char* msj);
  Uint32 Personaje() const;
  const char* mensaje() const;
 private:
  Uint32 pers_;
  const char* mens_;
};

class Dialogo {
 public:
  Dialogo(std::vector<Mensaje> // frases de los personajes.
	  Uint32 rP1, Uint32 gP1, Uint32 bP1, Uint32 rP2 = rP1, Uint32 gP2 = gP1, Uint32 bP2 = bP1);
  
  void IniciarDialogo
  // Se tomarán la localización de los diálogos predeterminado (SDL_Rect), es decir, el jugador principal
  // hablará siempre en la parte de arriba del mapa y el jugador secundario en la parte de abajo sin
  // obstruir menús ni nada por el estilo. Con lo cual hay que tener en cuenta que se deberia (o eso creo yo)
  // realizar siempre los mapas con un par de tiles de "pared" para que no se vaya a superponer nunca el
  // diálogo con los personajes u objetos del mapa. 

 private:
  // se necesita un "buffer" en la clase pantalla 
  // para los diálogos.

  Pantalla *p_;
 
  TTF_Font *tipoFuente_; // válido para los dos personajes que dialogen.
  SDL_Color c1,c2; // Por si necesitamos dos tipos de colores ya que puede que
  // las letras no se vean bien.
  
  SDL_Rect *localizacionP1, /*ARRIBA*/ *localizacionP2 /*ABAJO*/;
  
  std::vector<Mensaje> mensajes_;
  // Uint32 definirá qué personaje está ablando: tomaremos 0 el personaje principal 
  // y (por ahora) 1 el personaje secundario. Con lo cual sabemos 

};

#endif
