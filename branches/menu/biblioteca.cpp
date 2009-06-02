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
 * Fichero = biblioteca.cpp
 * Autor = Pablo Recio Quijano
 * Fecha = 31-may-2009
 * --------------------------------------------------------
 */

#include "biblioteca.h"
#include "combatiente.h"
#include "objeto.h"
#include "habilidad.h"
#include "grupo.h"
#include "es-xml.h"

Biblioteca::Biblioteca(const char* rutaXML){
	_rutaXML = string(rutaXML);
}

void Biblioteca::recargarXML(string rutaXML){
	cargar_XML(*this,rutaXML.c_str());
}

void Biblioteca::setGrupoPrincipal(const Grupo & g){
	_grupoPrincipal = g.getRutaXML();
}

void Biblioteca::addPJGrupoPrincipal(const Combatiente & c){
	_personajesPrincipales.insert(make_pair(c.getIdentificador(),c.getRutaXML()));
}

void Biblioteca::addObjeto(const Objeto & o){
	_objetos.insert(make_pair(o.getIdentificador(),o.getRutaXML()));
}

void Biblioteca::addHabilidad(const Habilidad & h){
	_habilidades.insert(make_pair(h.getIdentificador(),h.getRutaXML()));
}

void Biblioteca::addGrupoEnemigo(const Grupo & g){
	_gruposEnemigos.insert(make_pair(g.getIdentificador(),g.getRutaXML()));
}
