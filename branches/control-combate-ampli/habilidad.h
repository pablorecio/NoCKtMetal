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
 * Fichero = habilidad.h
 * Autor = Pablo Recio Quijano
 * Fecha = 15 de abril de 2009
 * --------------------------------------------------------
 */

#ifndef _HABILIDAD_H
#define	_HABILIDAD_H

#include <iostream>

#include <SDL/SDL.h>

#include <boost/serialization/access.hpp>

#include <boost/serialization/serialization.hpp>
#include <boost/serialization/nvp.hpp>
#include <boost/serialization/utility.hpp>
#include <boost/serialization/base_object.hpp>

#include "especial.h"

#include "es-xml.h"

/**
 *
 * Clase que modela el comportamiento de las habilidades especiales de los
 * distintos combatientes. Estas habilidades son una especialización de la clase
 * Especial, ya que el comportamiento es muy similar.
 *
 * @see Especial
 *
 * @author Pablo Recio Quijano 
 *
 * @date 15 de Abril de 2009
 */
class Habilidad: public Especial{
public:
  /**
   * Constructor vacio, no hace nada.
   */
  Habilidad() {}

  /**
   * Constructor de un objeto de la clase Habilidad. Este constructor recibe todos
   * los parámetros para crear dicho objeto, y aprovecha el constructor
   * de su clase padre "especial".
   *
   * @param nombre Cadena con el nombre identificativo del Objeto
   * @param id Identificador único del Objeto
   * @param tipo Tipo del Objeto
   * @param cotaInf Cota inferior de daño
   * @param cotaSup Cota superior de daño
   * @param gastoPE Cantidad de puntos especiales que consume este ataque.
   *
   */
  Habilidad(std::string nombre, Uint32 id, tipoEspecial tipo,
	    Uint32 cotaInf, Uint32 cotaSup, Uint32 gastoPE, string rXML);

  Habilidad(const char* ruta_XML){
    cargar_XML(*this,ruta_XML);
  }

  /**
   * Método <i>getter</i> que nos devuelve el número de puntos especiales
   * que consume esta hábilidad especial.
   *
   * @return Valor entero sin signo de 32 bits con el número de PE consumidos
   * por el atáque.
   */
  Uint32 getGastoPE() { return _PEgastados; }

  string getRutaXML() const {return _ruta_XML;}
  
  void actualizarXML(){
    guardar_XML(*this,_ruta_XML.c_str());
  }
  
private:
  //hay que añadir las funciones de serializacion, hay que ver como
  //son para clases heredadas
  string _ruta_XML;
  friend class boost::serialization::access;
  template<class Archive>
  void serialize(Archive & ar, const unsigned int version)
  {
    // serialize base class information
    //ar & BOOST_SERIALIZATION_NVP(boost::serialization::base_object<Especial>(*this));

    ar & BOOST_SERIALIZATION_NVP(_nombre);
    ar & BOOST_SERIALIZATION_NVP(_idEspecial);
    ar & BOOST_SERIALIZATION_NVP(_tipoEsp);
    ar & BOOST_SERIALIZATION_NVP(_rangoDamage);
    ar & BOOST_SERIALIZATION_NVP(_PEgastados);
    ar & BOOST_SERIALIZATION_NVP(_ruta_XML);
  }


  Uint32 _PEgastados;

};

#endif	/* _HABILIDAD_H */

