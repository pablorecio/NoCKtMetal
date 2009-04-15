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
 * Fichero = especial.h
 * Autor = Pablo Recio Quijano
 * Fecha = 15 de abril de 2009
 * --------------------------------------------------------
 */

#ifndef _ESPECIAL_H
#define	_ESPECIAL_H

#include <SDL/SDL.h>
#include <iostream>

/** 
 * Enumerado para indicar que tipos de especiales hay.
 * 
 */
enum tipoEspecial {
    ATAQUE = 0, CURATIVO, CAMBIO_ESTADO
};

/** 
 * Clase que modela el comportamiento de una entidad especial de un combate. Una entidad
 * especial se refiere a un objeto usable en combate (poción, bomba ...), una habilidad 
 * o algo similar. 
 * Aunque de forma lógica una habilidad y un objeto son entidades muy distintas, funcionalmente
 * son casi idénticas, por lo que esta clase pretende generalizar ambas clases, para que ambas
 * hereden el comportamiento de ella.
 *
 * Una entidad especial está compuesta de:
 *
 * <UL>
 * <LI><B>Nombre</B> - Indica el nombre que tiene el elemento especial.</LI> 
 * <LI><B>Identificador</B> - Identificador único del elemento especial, para diferenciarlo
 * inequivocamente del resto. </LI>
 * <LI><B>Tipo</B> - Un especial puede ser de diversos tipos: ofensivo, curativo, (ampliable)
 * <LI><B>Rango de daño</B> - Rango de daño base del especial. Un especial realizará un 
 * daño base, que es un valor aleatorio dentro de ese rango.</LI>
 * <UL>
 *
 * @author Pablo Recio Quijano 
 */
class Especial {
public:

  /** 
   * Constructor predeterminado de un objeto de la clase <code>Especial</code>. 
   * No hace nada, pero es necesario para posibles inicializaciones en vectores.
   */
  Especial() {}

  /** 
   * Constructor de un objeto de la clase <code>Especial</code>. Lo crea con
   * todos los valores inicializados, no es posible de otra forma.
   * 
   * @param nombre Cadena con el nombre del especial
   * @param id Entero sin signo de 32 bits con el valor identifativo único del especial.
   * @param tipo Enumerado que indica que tipo de especial que es el objeto (ofensivo o curativo)
   * @param cotaInf Cota inferior de daño
   * @param cotaSup Cota superior de daño
   */
  Especial(std::string nombre, Uint32 id, tipoEspecial tipo,
	   Uint32 cotaInf, Uint32 cotaSup);
  
  /** 
   * 
   * Método <i>getter</i> del nombre del especial. 
   * 
   * @return Cadena con el nombre del especial
   */
  std::string getNombre() const { return _nombre; }
  Uint32 getIdentificador() const { return _idEspecial; }
  tipoEspecial getTipoAtaque() const { return _tipoEsp; }
  std::pair<Uint32, Uint32> getRangoAtaque() const { return _rangoDamage; }
  
  Uint32 calculaDamage() const;
  
protected:
  std::string _nombre;
  Uint32 _idEspecial;
  tipoEspecial _tipoEsp;
  
  std::pair<Uint32, Uint32> _rangoDamage; //first cota inferior - second cota superior
  
private:
  Uint32 aleatorioRango(Uint32 a, Uint32 b) const;
};

#endif	/* _ESPECIAL_H */

