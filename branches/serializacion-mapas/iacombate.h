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
 * Fichero = iacombate.h
 * Autor = Pablo Recio Quijano
 * Fecha = 30 de mayo de 2009
 * --------------------------------------------------------
 */

#ifndef _IACOMBATE_H
#define	_IACOMBATE_H

#include <SDL/SDL.h>

#include "combatiente.h"
#include "grupo.h"

/**
 * Clase que modela una inteligencia artifical básica. El funcionamiento externo
 * es sencillo: se crea un objeto de esta clase pasándole quien es el que atacará,
 * así como los dos grupos que participan en el combate. Se supone que el segundo
 * grupo es al que pertenece el combatiente.
 *
 * El procedimiento que sigue es el siguiente:
 * <UL>
 * <LI>Selecciona que tipo de ataque realiza (por ahora solo ataque simple)</LI>
 * <LI>Si fuera habilidad u objeto, selecciona cual</LI>
 * <LI>Selecciona el objetivo</LI>
 * <LI>Realiza el ataque</LI>
 * <LI>Lanza las excepciones que recibe para que se ocupe de ellas la clase que la llame</LI>
 * </UL>
 *
 * En principio, todas las selecciones deben ser funciones probabilísticas ponderadas,
 * sin embargo actualmente solo ataca indiscriminadamente eligiendo objetivo
 * al azar.
 * @todo Funciones de probabilidad para los ataques.
 * @todo Funciones de probabilidad para seleccionar objetivos. Quizás se podría hacer
 * teniendo en cuenta el porcentaje de la vida que le quede a los rivales.
 */
class IACombate {
public:
	/**
	 * Constructor predeterminado. No hace nada.
	 */
    IACombate(){}

    /**
     * Constructor de un objeto de la clase <code>IACombate</code>. El objeto
     * construido encapsula una acción de un combatiente determinado.
     *
     * @param act Referencia al combatiente que realiza la acción.
     * @param g1 Referencia al grupo contrario al combatiente.
     * @param g2 Referencia al grupo al que pertenece el combaitente
     */
    IACombate(Combatiente &act, Grupo &g1, Grupo &g2);

    /**
     * Método que realiza un ataque de la IA. Los parámetros que se le pasan se
     * borrarán, ya que insertaran valores para que el usuario de la función
     * sepa que ha hecho el combatiente y proceder en consecuencia si se quisiera.
     * @param danio Valor entero sin signo que indica el daño realizado en el ataque
     * @param tipo Valor entero sin signo que indica que tipo de ataque ha sido:
     * <UL>
     *   <LI>1: Ataque simple</LI>
     *   <LI>2: Ataque especial</LI>
     *   <LI>3: Objeto</LI>
     * </UL>
     * @param indice Valor identificativo de que habilidad u objeto se ha usado.
     * @param objetivo Clave del rival objetivo del ataque.
     */
    void atacar(Uint32 &danio, Uint32 &tipo, Uint32 &indice, Uint32 &objetivo);

private:
    Grupo *_g1; //Siempre tener en cuenta que _g1 es el grupo del jugador
    Grupo *_g2;
    Combatiente *_actual;

    Uint32 seleccionarTipoAtaque();
    Uint32 seleccionarHabilidad();
    Uint32 seleccionarObjeto();
    Combatiente* seleccionarObjetivo();
};

#endif	/* _IACOMBATE_H */

