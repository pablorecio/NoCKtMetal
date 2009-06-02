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
 * Fichero = aleatorio.h
 * Autor = Pablo Recio Quijano
 * Fecha = 30 de mayo de 2009
 * --------------------------------------------------------
 */

#ifndef _ALEATORIO_H
#define	_ALEATORIO_H

#include <cstdlib>
#include <ctime>

#include <SDL/SDL.h>

/**
 * Sencilla clase para encapsular el cálculo de valores aleatorios. Esta clase
 * simplemente tiene funciones para calcular valores en cierto rango
 * dado por el usuario.
 */
class Aleatorio {
public:
	/**
	 * Constructor predeterminado. No hace nada.
	 */
	Aleatorio() {}
	/**
	 * Calcula un número entero pseudo-aleatorio en el rango dado, ambos incluidos.
	 * @param a Extremo izquierdo del intervalo
	 * @param b Extremo derecho del intervalo
	 * @return Valor entero sin signo de 32 bits entre [a,b]
	 */
	Uint32 valorEntero(Uint32 a, Uint32 b) const;
};

#endif	/* _ALEATORIO_H */

