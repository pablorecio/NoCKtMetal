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
 * Fichero = generar-xml.cpp
 * Autor = Pablo Recio Quijano
 * Fecha = 01-jun-2009
 * --------------------------------------------------------
 */

#include <iostream>
#include <iterator>
#include <map>

#include <SDL/SDL.h>

#include "iniciar-objetos.h"
#include "biblioteca.h"

using namespace std;

ostream& operator << (ostream &o, map<Uint32,string> &m);

int main(){
	if (crearFicheros() != 1){
		cerr << "Se ha producido algún error al generar los ficheros XML" << endl;
	} else{
		cout << "Ficheros XML generados con éxito" << endl;
		Biblioteca bib;
		bib.recargarXML("datos-xml/biblioteca.xml");
		cout << "Generados los ficheros: " << endl;
		cout << bib.getGrupoPrincipal() << endl;
		cout << bib.getPersonajesPrincipales() << endl;
		cout << bib.getGruposEnemigos() << endl;
		cout << bib.getHabilidades() << endl;
		cout << bib.getObjetos() << endl;
	}
}

ostream& operator << (ostream &o, map<Uint32,string> &m){
	for(map<Uint32,string>::iterator i = m.begin() ; i != m.end() ; i++){
		o << i->second << "\n";
	}
	return o;
}
