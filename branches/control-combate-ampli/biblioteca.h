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
 * Biblioteca
 */
class Biblioteca {
public:
	Biblioteca() {
	}
	Biblioteca(const char* rutaXML);

	void recargarXML(string rutaXML);

	void setGrupoPrincipal(const Grupo & g);
	void addPJGrupoPrincipal(const Combatiente & c);
	void addObjeto(const Objeto & o);
	void addHabilidad(const Habilidad & h);
	void addGrupoEnemigo(const Grupo & g);

	string getGrupoPrincipal() const;
	Uint32 getNumeroPersonajesPrincipales() const;
	Uint32 getNumeroObjetos() const;
	Uint32 getNumeroHabilidades() const;
	Uint32 getNumeroGruposEnemigos() const;

	string getPersonajePrincipal(Uint32 id);
	string getObjeto(Uint32 id) const;
	string getHabilidad(Uint32 id) const;
	string getGrupoEnemigo(Uint32 id) const;
	string getRutaXML() const;

	map<Uint32, string>& getPersonajesPrincipales();
	map<Uint32, string>& getObjetos();
	map<Uint32, string>& getHabilidades();
	map<Uint32, string>& getGruposEnemigos();

	const map<Uint32, string>& getPersonajesPrincipales() const;
	const map<Uint32, string>& getObjetos() const;
	const map<Uint32, string>& getHabilidades() const;
	const map<Uint32, string>& getGruposEnemigos() const;

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

inline string Biblioteca::getPersonajePrincipal(Uint32 id) {
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

inline map<Uint32, string>& Biblioteca::getPersonajesPrincipales(){
	return _personajesPrincipales;
}

inline map<Uint32, string>& Biblioteca::getObjetos(){
	return _objetos;
}

inline map<Uint32, string>& Biblioteca::getHabilidades(){
	return _habilidades;
}

inline map<Uint32, string>& Biblioteca::getGruposEnemigos(){
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
