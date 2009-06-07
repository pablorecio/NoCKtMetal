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
 * Fichero = grupo.h
 * Autor = Pablo Recio Quijano
 * Fecha = 16 de abril de 2009
 * --------------------------------------------------------
 */

#ifndef _GRUPO_H
#define	_GRUPO_H

#include <iostream>
#include <vector>
#include <exception>

#include <SDL/SDL.h>

#include "inventario.h"
#include "combatiente.h"

#include <boost/serialization/access.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/serialization.hpp>
#include <boost/serialization/nvp.hpp>

#include "es-xml.h"

using namespace std;

/**
 *
 * Declaración adelantada de la clase <code>Combatiente</code>, necesaria para la
 * relación entre ambas clases.
 * @see combatiente.h
 */
class Combatiente;

/**
 * Clase para modelar la unión de varios combatientes en una sola unidad conjunta.
 * Estos grupos son los que se enfrentan en un combate. De esta forma, un grupo
 * tiene un inventario común, así como un conjunto de componentes, los cuales
 * son controlables desde el grupo.
 *
 * @author Pablo Recio Quijano
 *
 * @date 16 de Abril de 2009
 */
class Grupo {
public:
	/**
	 * Clase de excepción que modela el caso que el grupo esté lleno (4 componentes)
	 *
	 * @author Pablo Recio Quijano
	 *
	 * @date 16 de Abril de 2009
	 */
	class GrupoLleno: public exception {
	public:
		const char* what() const throw() {
			return "Grupo lleno";
		}
	};

	class NoExisteCombatiente: public exception {
	public:
		const char* what() const throw() {
			return "No existe combatiente con esa clave";
		}
	};
	/**
	 * Constructor vacio, no hace nada.
	 */
	Grupo() {
	}

	/**
	 * Constructor de un objeto de la clase <code>Grupo</code>, determinando el
	 * inventario del que dispone, y si es controlable o no.
	 *
	 * @param invent Inventario sobre el cual trabaja todos los miembros
	 * del grupo.
	 * @param contr Determina si el grupo es controlable o no.
	 * @param rXML Ruta donde se almacenará el fichero serializado de este objeto.
	 */
	Grupo(Inventario& invent, bool contr, Uint32 i, string rXML);

	/**
	 * Construye un objeto de la clase <code>Grupo</code> a partir de
	 * un fichero XML.
	 *
	 * @param ruta_XML Ruta al fichero que contiene el objeto que queremos
	 * deserializar.
	 */
	Grupo(const char* ruta_XML) {
	  cargar_XML(*this, ruta_XML);
	}

  Grupo(const Grupo& otro){
    
    _controlable = otro._controlable;
    _inventario = otro._inventario;
    _componentes = otro._componentes;
    _numComp = otro._numComp;
    _id = otro._id;
    
    _ruta_XML = otro._ruta_XML;
  }

  Grupo& operator =(const Grupo& otro){
    if(&otro != this){
      _controlable = otro._controlable;
      _inventario = otro._inventario;
      _componentes = otro._componentes;
      _numComp = otro._numComp;
      _id = otro._id;
      
      _ruta_XML = otro._ruta_XML;      
    }
    return *this;
  }

	/**
	 * Método <i>getter</i> para obtener acceso al inventario del grupo
	 *
	 * @return Referencia constante al inventario.
	 */
	const Inventario& getInventario() const {
		return *_inventario;
	}

	/**
	 * Método <i>getter</i> para obtener acceso al inventario del grupo
	 *
	 * @return Referencia al inventario.
	 */
	Inventario& getInventario() {
		return *_inventario;
	}

	const std::vector<Combatiente*>& getCombatientes() const {
		return _componentes;
	}

	std::vector<Combatiente*>& getCombatientes() {
		return _componentes;
	}

	/**
	 * Método <i>getter</i> para obtener acceso al componente con la clave dada.
	 *
	 * @return Referencia constante al combatiente con la clave <code>i</code>
	 */
	const Combatiente& getCombatiente(Uint32 i) const
			throw(NoExisteCombatiente);

	/**
	 * Método <i>getter</i> para obtener acceso al componente con la clave dada.
	 *
	 * @return Referencia al combatiente con la clave <code>i</code>
	 */
	Combatiente& getCombatiente(Uint32 i) throw(NoExisteCombatiente);

	/**
	 *
	 * Método <i>getter</i> para obtener el número de combatientes del grupo.
	 *
	 * @return Entero sin signo de 32 bits con el número de combatientes que
	 * pertenecen al grupo.
	 */
	Uint32 getNumeroCombatientes() const {
		return _numComp;
	}

	/**
	 * Método que sirve para añadir un combatiente al grupo
	 *
	 * @param comb Referencia al combatiente a añadir en el grupo.
	 * @exception GrupoLleno Si el número de combatientes es 4, lanza la
	 * excepción
	 */
	void addCombatiente(Combatiente& comb) throw(GrupoLleno);

	Uint32 getIdentificador() const {
		return _id;
	}

	/**
	 *
	 * Método <i>getter</i> para obtener si un grupo es controlable o no
	 *
	 * @return <code>true</code> si el grupo es controlabe y <code>false</code>
	 * en otro caso.
	 */
	bool controlable() const {
		return _controlable;
	}

	/**
	 *
	 * Método que indica si queda algún miembro vivo del grupo.
	 *
	 * @return <code>true</code> si hay algún combatiente con PV > 0 <code>false</code>
	 * en otro caso.
	 */
	bool vivo() const;

	void mostrarGrupo() const;

	/**
	 *
	 * Método <i>getter</i> para la ruta del fichero XML con el contenido
	 * serializado del objeto.
	 *
	 * @return Cadena que contiene la ruta al fichero XML.
	 */
	string getRutaXML() const {
		return _ruta_XML;
	}

	/**
	 * Método que serializa el objeto en la ruta XML del mismo, borrando
	 * lo que hubiera antes.
	 */
	void actualizarXML() {
		guardar_XML(*this, _ruta_XML.c_str());
	}

private:
	bool _controlable;
	Inventario* _inventario;
	vector<Combatiente*> _componentes;
	Uint32 _numComp;
	Uint32 _id;

	string _ruta_XML;

	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version) {
		ar & BOOST_SERIALIZATION_NVP(_controlable);
		ar & BOOST_SERIALIZATION_NVP(_inventario);
		ar & BOOST_SERIALIZATION_NVP(_componentes);
		ar & BOOST_SERIALIZATION_NVP(_numComp);
		ar & BOOST_SERIALIZATION_NVP(_ruta_XML);
		ar & BOOST_SERIALIZATION_NVP(_id);
	}
};
#endif	/* _GRUPO_H */

