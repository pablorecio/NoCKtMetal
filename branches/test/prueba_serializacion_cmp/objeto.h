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
 * Fichero = objeto.h
 * Autor = Pablo Recio Quijano
 * Fecha = 15 de abril de 2009
 * --------------------------------------------------------
 */

#ifndef _OBJETO_H
#define	_OBJETO_H

#include <SDL/SDL.h>
#include <exception>

#include <boost/serialization/export.hpp>
#include <boost/serialization/access.hpp>

#include <boost/serialization/serialization.hpp>
#include <boost/serialization/nvp.hpp>

#include <boost/serialization/base_object.hpp>

#include "especial.h"

/** 
 * 
 * Clase que modela el comportamiento de un Item. Consideramos un Item como una entidad la 
 * cual es utilizable por un combatiente en un combate, es decir, pociones, bombas, antídotos,
 * étcetera. Estos Item son una especialización de la clase Especial, aprovechando así 
 * la definición e implementación de sus funciones, añadiendo ademas un controlador de la cantidad
 * de la que disponemos del Item en cuestión.
 *
 * @see Especial
 *
 * @author Pablo Recio Quijano 
 *
 * @date 15 de Abril de 2009
 */
class Objeto: public Especial {
public:
  /**
   *
   * Clase de excepción que nos servirá para indicar cuando no tenemos la cantidad suficiente
   * de un objeto determinado que queremos utilizar.
   *
   *
   * @author Pablo Recio Quijano 
   *
   * @date 15 de Abril de 2009
   */
  class CantidadItemInsuficiente: public std::exception{ //TODO: añadir referencia al objeto
  public:
    /** 
     * 
     * Método observador que nos indica el mensaje de porque ha sido lanzada la excepción
     * 
     * @return Cádena constante con el mensaje indicativo.
     */
    const char* what() const throw(){
      return "No hay suficiente cantidad del objeto ";
    }
  private:
  };
  
  /** 
   * 
   * Constructor predeterminado, no hace nada.
   * 
   */
  Objeto() {}

  /** 
   * Constructor de un objeto de la clase Objeto. Este constructor recibe todos
   * los parámetros para crear dicho objeto, y aprovecha el constructor
   * de su clase padre "especial". 
   * 
   * @param nombre Cadena con el nombre identificativo del Objeto
   * @param id Identificador único del Objeto
   * @param tipo Tipo del Objeto
   * @param cotaInf Cota inferior de daño
   * @param cotaSup Cota superior de daño
   * @param cantidad Número de objetos
   * 
   */
  Objeto(std::string nombre, Uint32 id, tipoEspecial tipo,
         Uint32 cotaInf, Uint32 cotaSup, Uint32 cantidad);
  
  /** 
   * 
   * Método <i>getter</i> para la cantidad del objeto
   * 
   * @return Valor entero sin signo de 32 bits con la cantidad disponible
   * del objeto en cuestión
   */
  Uint32 getCantidad() const { return _cantidad; }

  /** 
   * 
   * Método usado para usar un Objeto en cuestión, de forma que obtenemos
   * el daño que realiza el objeto, y decrementamos en uno su valor
   * 
   * @return Valor entero sin signo de 32 bits con el daño realizado
   * por el objeto tras su uso.
   *
   * @exception CantidadItemInsuficiente Es lanzada cuando la cantidad
   * necesaria para usar el objeto es menor que la cantidad disponible.
   */
  Uint32 usarObjeto() throw(CantidadItemInsuficiente);

  /** 
   * Método que aumenta en <code>c</code> el número de Objetos del que 
   * disponemos
   * 
   * @param c Valor entero sin signo de 32 bits que indica la cantidad a 
   * aumentar
   */
  void addCantidad(Uint32 c) { _cantidad += c; }
  
  /** 
   * Método que decrementa en uno la cantidad disponible del objeto.
   * 
   * 
   * @return Referencia al objeto decrementado.
   *
   * @exception CantidadItemInsuficiente Es lanzada cuando la cantidad
   * necesaria para usar el objeto es menor que la cantidad disponible.
   */
  Objeto& operator --() throw(CantidadItemInsuficiente);
private:
  Uint32 _cantidad;

  friend class boost::serialization::access;
  template<class Archive>
  void serialize(Archive & ar, const unsigned int version)
  {
    //std::cout << "Objeto::serialize(Archive &ar, const unsigned int version)" 
    //	      << std::endl;
    ar & BOOST_SERIALIZATION_NVP(boost::serialization::base_object<Especial>(*this));
    //std::cout << "ar & BOOST_SERIALIZATION_NVP(boost::serialization::base_object<Especial>(*this));" 
    //	      << std::endl;
    ar & BOOST_SERIALIZATION_NVP(_cantidad);
    //std::cout << "ar & BOOST_SERIALIZATION_NVP(_cantidad);" 
    //	      << std::endl;
  }
};

#endif	/* _OBJETO_H */

