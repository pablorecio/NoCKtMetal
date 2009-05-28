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
 * Fichero = es-xml.h
 * Autor = Pablo Recio Quijano
 * Fecha = 25 de abril de 2009
 * --------------------------------------------------------
 */

#ifndef _ES_XML_
#define _ES_XML_

#include <iostream>
#include <fstream>

#include <boost/archive/tmpdir.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>

#include <boost/serialization/serialization.hpp>
#include <boost/serialization/nvp.hpp>

using namespace std;

/**
 * Función genérica, la cual nos permite almacenar un objeto en un
 * fichero XML. Hay que notar que es necesario el método <code>serialize()</code>
 * esté implementado en la clase de plantilla usada, de acuerdo a como se indica
 * en la documentación de la libreria <i>serialization<i> de la librera boost
 *
 * @param a Objeto que queremos almacenar en el fichero.
 * @param fichero Ruta al fichero.
 */
template <typename T>
void guardar_XML(const T &a, const char *fichero){
  std::ofstream sal(fichero);
  assert(sal.good());
  boost::archive::xml_oarchive xml_sal(sal);
  xml_sal << BOOST_SERIALIZATION_NVP(a);
}

/**
 * Función genérica, la cual nos permite cargar un objeto desde un
 * fichero XML. Hay que notar que es necesario el método <code>serialize()</code>
 * esté implementado en la clase de plantilla usada, de acuerdo a como se indica
 * en la documentación de la libreria <i>serialization<i> de la librera boost
 *
 * @param a Objeto que queremos cargar desde el fichero.
 * @param fichero Ruta al fichero.
 */
template <typename T>
void cargar_XML(T &a, const char *fichero){
  std::ifstream ent(fichero);
  assert(ent.good());
  boost::archive::xml_iarchive xml_ent(ent);
  xml_ent >> BOOST_SERIALIZATION_NVP(a);
}

// Página principal de la documentación.
/** @mainpage NoCKt Metal
 *
 *
 *  @section Introduccion
 *
 * En la siguiente documentación se hace una introducción a las distintas clases
 * usadas en el proyecto <B>NoCKtMetal</B>, haciendo las veces de API para los
 * desarrolladores, o como soporte para quien quiera que le pueda ser util dicho
 * proyecto
 *
 * @section Licencia
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see http://www.gnu.org/licenses/

 * Copyright (C) 2009, NoCKTMetal Team
 *
 * @section Dependencias
 *
 * Para una correcta compilación son necesarias las siguientes librerias:
 *
 * <UL>
 * <LI>libsdl1.2-dev</LI>
 * <LI>libsdl-image1.2-dev</LI>
 * <LI>libboost1.35-dev</LI>
 * </UL>
 *
 * Por ahora, no funciona con versiones posteriores de libboost (estamos
 * trabajando en ello)
 */

#endif

