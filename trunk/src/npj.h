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
 * Fichero: npj.h
 * Autor: Rosa María Durante Lerate
 * Fecha: 06 05 2009
 * Proyecto: NoCKt Metal
 */

#ifndef _NPJ_H_
#define _NPJ_H_

/* . Esta clase estará relacionada con la clase IMAGEN ¿Por qué? Pues porque un npj 
 no tiene que aparecer siempre en la pantalla, simplemente tiene que estar en el mapa
 o en un sitio fijo o en un rango pero permanece en el mapa y no en la pantalla. */

/* . Es similar a la clase Personaje pero no es igual, sobretodo por la cuestión anterior. */

/* . Hay que modificar la clase IMAGEN para poder tener varias funcionalidades más: */
/* . -> Incluir un npj en el mapa y poner que esa/s casilla/s (por si se mueve el personaje)
        son colisionables e interactuables. */
/* . -> Además tendremos que poder acceder a que personaje se está colisionando y que interacciones
        se pueden realizar con él. */

class NPJ {
 public:
  NPJ(); // para vectores;
  NPJ(Uint32 i, Uint32 x, Uint32 y, const char* sprite, Uint32 f = 4, Uint32 c = 4);
 private:

};




#endif
