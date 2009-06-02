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
 * Fichero = biblioteca.h
 * Autor = Pablo Recio Quijano
 * Fecha = 31-may-2009
 * --------------------------------------------------------
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

#include <iostream>
#include <map>
#include <exception>

#include <boost/serialization/access.hpp>
#include <boost/serialization/map.hpp>
#include <boost/serialization/serialization.hpp>
#include <boost/serialization/nvp.hpp>

#include "combatiente.h"
#include "objeto.h"
#include "habilidad.h"
#include "grupo.h"

#include "es-xml.h"

using namespace std;

/**
 * Clase que modela una biblioteca de ficheros. Estos ficheros son los encargados
 * de manejar una partida, con los datos de la misma, de forma que la biblioteca
 * almacena las rutas a estos ficheros para que se puedan cargar, actualizar y
 * trabajar con ellos facilmente.
 *
 * Todos los ficheros son serializados de los objetos, convertidos a XML.
 * Posteriormente estudiaremos la posibilidad de encriptar los ficheros. Hay
 * que tener en cuenta que solo debe haber un objeto <code>Biblioteca</code> por
 * partida.
 */
class Biblioteca {
public:
	/**
	 * Constructor predeterminado, no hace nada.
	 */
	Biblioteca() {
	}
	/**
	 * Crea un objeto de la clase <code>Biblioteca</code> vacio. Este objeto
	 * debe ir completándose posteriormente con los distintos objetos que se
	 * inserten en la biblioteca.
	 * @param rutaXML Ruta donde se creará el XML de este objeto.
	 */
	Biblioteca(const char* rutaXML);

	/**
	 * Sobreescribe el fichero XML de la biblioteca, así como todos los
	 * contenidos. Es la función que hay que usar para restaurar una biblioteca.
	 * @param rutaXML Ruta donde está situado el fichero XML que se cargará en
	 * este objeto concreto.
	 */
	void recargarXML(string rutaXML);

	/**
	 * Modifica la dirección del fichero XML que contiene al grupo principal.
	 * @param g Objeto de la clase <code>Grupo</code> que contiene al grupo
	 * principal del juego.
	 */
	void setGrupoPrincipal(const Grupo & g);

	/**
	 * Añade un PJ a la lista. Con este método añadimos un nuevo PJ para poder
	 * trabajar con el.
	 * @param c Objeto de la clase <code>Combatiente</code> con el PJ a insertar.
	 */
	void addPJGrupoPrincipal(const Combatiente & c);

	/**
	 * Añade un objeto a la lista de objetos. Con este método añadimos un nuevo
	 * objeto para trabajar con el.
	 * @param o Objeto de la clase <code>Objeto</code> con el objeto a insertar
	 * en la lista de objetos.
	 */
	void addObjeto(const Objeto & o);

	/**
	 * Añade una habilidad a la lista de habilidades. Con este método añadimos
	 * una nueva habiidad para trabajar con ella.
	 * @param h Objeto de la clase <code>Habilidad</code> con la habilidad a insertar
	 * en la lista de habilidades.
	 */
	void addHabilidad(const Habilidad & h);

	/**
	 * Añade un grupo a la lista de grupos enemigos. Con este método añadimos un nuevo
	 * grupo para trabajar con el.
	 * @param g Objeto de la clase <code>Grupo</code> con el grupo a insertar
	 * en la lista de grupos.
	 */
	void addGrupoEnemigo(const Grupo & g);

	/**
	 * Método <i>getter</i> para obtener cuantos PJs tenemos en la biblioteca.
	 *
	 * @return Valor entero sin signo de 32 bits con el número de XML de PJs
	 * almacenados en la biblioteca.
	 */
	Uint32 getNumeroPersonajesPrincipales() const;

	/**
	 * Método <i>getter</i> para obtener cuantos objetos tenemos en la biblioteca.
	 *
	 * @return Valor entero sin signo de 32 bits con el número de XML de objetos
	 * almacenados en la biblioteca.
	 */
	Uint32 getNumeroObjetos() const;

	/**
	 * Método <i>getter</i> para obtener cuantas habilidades tenemos en
	 * la biblioteca.
	 *
	 * @return Valor entero sin signo de 32 bits con el número de XML de
	 * habilidades almacenados en la biblioteca
	 */
	Uint32 getNumeroHabilidades() const;

	/**
	 * Método <i>getter</i> para obtener cuantos grupos enemigos
	 * tenemos en la biblioteca.
	 *
	 * @return Valor entero sin signo de 32 bits con el número de XML de
	 * grupos enemigos almacenados en la biblioteca
	 */
	Uint32 getNumeroGruposEnemigos() const;

	/**
	 * Método <i>getter</i> para obtener la ruta al fichero XML que contiene
	 * los datos del grupo principal.
	 *
	 * @return Cadena de tipo <code>string</code> con la ruta al fichero.
	 */
	string getGrupoPrincipal() const;

	/**
	 * Método <i>getter</i> para obtener la ruta al fichero XML que contiene
	 * los datos de un PJ.
	 *
	 * @param id Identificador para obtener el fichero deseado
	 * @return Cadena de tipo <code>string</code> con la ruta al fichero.
	 */
	string getPersonajePrincipal(Uint32 id) const;

	/**
	 * Método <i>getter</i> para obtener la ruta al fichero XML que contiene
	 * los datos de un objeto.
	 *
	 * @param id Identificador para obtener el fichero deseado
	 * @return Cadena de tipo <code>string</code> con la ruta al fichero.
	 */
	string getObjeto(Uint32 id) const;

	/**
	 * Método <i>getter</i> para obtener la ruta al fichero XML que contiene
	 * los datos de una habilidad.
	 *
	 * @param id Identificador para obtener el fichero deseado
	 * @return Cadena de tipo <code>string</code> con la ruta al fichero.
	 */
	string getHabilidad(Uint32 id) const;

	/**
	 * Método <i>getter</i> para obtener la ruta al fichero XML que contiene
	 * los datos de un grupo enemigo.
	 *
	 * @param id Identificador para obtener el fichero deseado
	 * @return Cadena de tipo <code>string</code> con la ruta al fichero.
	 */
	string getGrupoEnemigo(Uint32 id) const;

	/*
	 * Método <i>getter</i> para la ruta del fichero XML con el contenido
	 * serializado del objeto.
	 *
	 * @return Cadena que contiene la ruta al fichero XML.
	 */
	string getRutaXML() const;

	/*
	 * Método <i>getter</i> para obtener el <code>map</code> completo
	 * con los PJs.
	 *
	 * @return Referencia al <code>map</code> que contiene las rutas a
	 * los ficheros.
	 */
	map<Uint32, string>& getPersonajesPrincipales();

	/*
	 * Método <i>getter</i> para obtener el <code>map</code> completo
	 * con los objetos.
	 *
	 * @return Referencia al <code>map</code> que contiene las rutas a
	 * los ficheros.
	 */
	map<Uint32, string>& getObjetos();

	/*
	 * Método <i>getter</i> para obtener el <code>map</code> completo
	 * con las habilidades.
	 *
	 * @return Referencia al <code>map</code> que contiene las rutas a
	 * los ficheros.
	 */
	map<Uint32, string>& getHabilidades();

	/*
	 * Método <i>getter</i> para obtener el <code>map</code> completo
	 * con los grupos enemigos.
	 *
	 * @return Referencia al <code>map</code> que contiene las rutas a
	 * los ficheros.
	 */
	map<Uint32, string>& getGruposEnemigos();

	/*
	 * Método <i>getter</i> para obtener el <code>map</code> completo
	 * con los PJs.
	 *
	 * @return Referencia consante al <code>map</code> que contiene las rutas a
	 * los ficheros.
	 */
	const map<Uint32, string>& getPersonajesPrincipales() const;

	/*
	 * Método <i>getter</i> para obtener el <code>map</code> completo
	 * con los objetos.
	 *
	 * @return Referencia consante al <code>map</code> que contiene las rutas a
	 * los ficheros.
	 */
	const map<Uint32, string>& getObjetos() const;

	/*
	 * Método <i>getter</i> para obtener el <code>map</code> completo
	 * con las habilidades.
	 *
	 * @return Referencia consante al <code>map</code> que contiene las rutas a
	 * los ficheros.
	 */
	const map<Uint32, string>& getHabilidades() const;

	/*
	 * Método <i>getter</i> para obtener el <code>map</code> completo
	 * con los grupos enemigos.
	 *
	 * @return Referencia consante al <code>map</code> que contiene las rutas a
	 * los ficheros.
	 */
	const map<Uint32, string>& getGruposEnemigos() const;

	/**
	 * Método que serializa el objeto en la ruta XML del mismo, borrando
	 * lo que hubiera antes.
	 */
	void actualizarXML();

private:
	string _rutaXML;

	string _grupoPrincipal;
	map<Uint32, string> _personajesPrincipales;
	map<Uint32, string> _objetos;
	map<Uint32, string> _habilidades;
	map<Uint32, string> _gruposEnemigos;

	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version) {
		ar & BOOST_SERIALIZATION_NVP(_rutaXML);
		ar & BOOST_SERIALIZATION_NVP(_grupoPrincipal);
		ar & BOOST_SERIALIZATION_NVP(_personajesPrincipales);
		ar & BOOST_SERIALIZATION_NVP(_objetos);
		ar & BOOST_SERIALIZATION_NVP(_habilidades);
		ar & BOOST_SERIALIZATION_NVP(_gruposEnemigos);
	}
};

inline string Biblioteca::getGrupoPrincipal() const {
	return _grupoPrincipal;
}

inline Uint32 Biblioteca::getNumeroPersonajesPrincipales() const {
	return _personajesPrincipales.size();
}

inline Uint32 Biblioteca::getNumeroObjetos() const {
	return _objetos.size();
}

inline Uint32 Biblioteca::getNumeroHabilidades() const {
	return _habilidades.size();
}

inline Uint32 Biblioteca::getNumeroGruposEnemigos() const {
	return _gruposEnemigos.size();
}

inline string Biblioteca::getPersonajePrincipal(Uint32 id) const {
	return _personajesPrincipales.at(id);
}

inline string Biblioteca::getObjeto(Uint32 id) const {
	return _objetos.at(id);
}

inline string Biblioteca::getHabilidad(Uint32 id) const {
	return _habilidades.at(id);
}

inline string Biblioteca::getGrupoEnemigo(Uint32 id) const {
	return _gruposEnemigos.at(id);
}

inline string Biblioteca::getRutaXML() const {
	return _rutaXML;
}

inline map<Uint32, string>& Biblioteca::getPersonajesPrincipales() {
	return _personajesPrincipales;
}

inline map<Uint32, string>& Biblioteca::getObjetos() {
	return _objetos;
}

inline map<Uint32, string>& Biblioteca::getHabilidades() {
	return _habilidades;
}

inline map<Uint32, string>& Biblioteca::getGruposEnemigos() {
	return _gruposEnemigos;
}

inline const map<Uint32, string>& Biblioteca::getPersonajesPrincipales() const {
	return _personajesPrincipales;
}

inline const map<Uint32, string>& Biblioteca::getObjetos() const {
	return _objetos;
}

inline const map<Uint32, string>& Biblioteca::getHabilidades() const {
	return _habilidades;
}

inline const map<Uint32, string>& Biblioteca::getGruposEnemigos() const {
	return _gruposEnemigos;
}

inline void Biblioteca::actualizarXML() {
	guardar_XML(*this, _rutaXML.c_str());
}

#endif /* BIBLIOTECA_H_ */
