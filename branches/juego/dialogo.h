
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
#include <vector>
#include "pantalla.h"


// Es necesario inicializar el subsistema de fuentes:
// if(TTF_Init() == 0) {
//	atexit(TTF_Quit);
//        cout << "TTF inicializada" << endl;	
//    }

/**
 * Clase que muestra en la pantalla un diálogo entre dos personajes (siempre uno debe
 * ser el principal). Esta clase será utilizada en las interactuaciones que puede darse
 * cuando nuestro personaje principal se encuentre con un personaje no jugable. 
 *
 * También se puede utilizar esta clase para realizar introducciones a las fases del juego
 * o al comienzo y final del juego. Simplemente utilizamos los mensajes con identificador 1
 * para que los mensajes que queramos que se muestre se muestren en la parte inferior de la pantalla.
 *
 * @todo Queda pendiente la posición exacta del hablador en la parte inferior ya que puede
 * aparecer algún tipo de menú de interacción y se solapen.
 */
class Dialogo {
 public:

  /**
   * Agrupa los mensajes que dirán los presonajes con un identificador
   * específico: 0 para el personaje pincipal (hablará en la parte superior de la pantalla)
   * y 1 para el personaje no jugable (que hablará en la parte inferior de la pantalla).
   */
  class Mensaje{
  public:
    /**
     * Constructor vacio. Sobrecarga para crear vectores.
     */
    Mensaje() {} 
    /**
     * Constructor principal el cual recibe una cadena con el mensaje y el identificador de 
     * qué personaje está hablando.
     */
    Mensaje(Uint32 personaje_hablador, const char* msj);
    /**
     * Método que devuelve el identificador del personaje que habla.
     */
    Uint32 Personaje() const;
    /**
     * Método que devuelve el mensaje del personaje.
     */
    const char* mensaje() const;
  private:
    /**
     * Idenfificador de personaje.
     */
    Uint32 pers_;
    /**
     * Mensaje del personaje.
     */
    const char* mens_;
  };
  
  /**
   * Un diálogo se compone por un conjunto de mensajes ya ordenados junto con el personaje que 
   * dirá cada uno (el identificador del personaje) además del tipo de letra (predefinido) y el 
   * color en cada situación del mapa (puede no establecerse el mismo color para ambos hablantes
   * ya que como cada uno hablará en una posición distinta del mapa puede que el color en  un sitio
   * no esté tan legible que en otro).
   */
  Dialogo(std::vector<Mensaje> m , Pantalla& p, 
	  Uint32 rP1 = 255, Uint32 gP1 = 255, Uint32 bP1 = 255, 
	  Uint32 rP2 = 255, Uint32 gP2 = 255, Uint32 bP2 = 255);

  // Se tomarán la localización de los diálogos predeterminado (SDL_Rect), es decir, el jugador principal
  // hablará siempre en la parte de arriba del mapa y el jugador secundario en la parte de abajo sin
  // obstruir menús ni nada por el estilo. Con lo cual hay que tener en cuenta que se deberia (o eso creo yo)
  // realizar siempre los mapas con un par de tiles de "pared" para que no se vaya a superponer nunca el
  // diálogo con los personajes u objetos del mapa. 

 private:
  /**
   * Utilizamos el SDL_Surface Buffer que nos suministra la clase pantalla.
   */
  Pantalla *p_;
 
  /**
   * Tipo de la fuente que tomaremos para los diálogos.
   */
  TTF_Font *tipoFuente_; // válido para los dos personajes que dialogen.
  /**
   * Y diferenciamos los colores por si acaso.
   */
  SDL_Color c1,c2; // Por si necesitamos dos tipos de colores ya que puede que
  // las letras no se vean bien.
  
  /**
   * Vector de mensajes ordenados según qué mensaje se muestre antes.
   */
  std::vector<Mensaje> mensajes_;
  // Uint32 definirá qué personaje está ablando: tomaremos 0 el personaje principal 
  // y (por ahora) 1 el personaje secundario.

};


inline Uint32 Dialogo::Mensaje::Personaje() const { return pers_; }
inline const char* Dialogo::Mensaje::mensaje() const { return mens_; }

#endif
