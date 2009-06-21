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
 * Fichero = armadura.h
 * Autor = Pablo Recio Quijano
 * Fecha = 02-jun-2009
 * --------------------------------------------------------
 */

#ifndef ARMADURA_H_
#define ARMADURA_H_

#include <iostream>

#include <boost/serialization/string.hpp>
#include <boost/serialization/access.hpp>
#include <boost/serialization/serialization.hpp>
#include <boost/serialization/nvp.hpp>

#include <SDL/SDL.h>

#include "item_equipable.h"

/**
 * Armadura
 */
class Armadura: public ItemEquipable {
public:
	Armadura() {}
	Armadura(std::string nombre, Uint32 id, tipoEspecial tipo, Uint32 cotaInf,
			Uint32 cotaSup, bool equipado, Uint32 inc_armadura, std::string rXML):
				ItemEquipable(nombre,id,tipo,cotaInf,cotaSup,equipado),
				_inc_armadura(inc_armadura), _ruta_XML(rXML)
	{}

	Armadura(const char* ruta_XML){
		cargar_XML(*this, ruta_XML);
	}

	Uint32 getIncrementoArmadura() const;
	/**
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
	Uint32 _inc_armadura;
	std::string _ruta_XML;
	friend class boost::serialization::access;
	/// Serialization function
	template<class Archive>
	void serialize(Archive& ar, const unsigned int version) {
		ar & BOOST_SERIALIZATION_NVP(_nombre);
		ar & BOOST_SERIALIZATION_NVP(_idEspecial);
		ar & BOOST_SERIALIZATION_NVP(_tipoEsp);
		ar & BOOST_SERIALIZATION_NVP(_rangoDamage);
		ar & BOOST_SERIALIZATION_NVP(_equipado);
		ar & BOOST_SERIALIZATION_NVP(_id);
		ar & BOOST_SERIALIZATION_NVP(_inc_armadura);
		ar & BOOST_SERIALIZATION_NVP(_ruta_XML);
	}
};

inline Uint32 Armadura::getIncrementoArmadura() const{
	return _inc_armadura;
}

#endif /* ARMADURA_H_ */
