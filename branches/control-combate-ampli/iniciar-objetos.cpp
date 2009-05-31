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
 * File:   iniciar-objetos.cpp
 * Author: Pablo Recio Quijano
 *
 * Created el 26 de abril de 2009, 23:22
 */

#include <iostream>
#include <SDL/SDL.h>

#include "iniciar-objetos.h"
#include "atributos.h"
#include "atributos_base.h"
#include "combatiente.h"
#include "grupo.h"
#include "habilidad.h"
#include "objeto.h"
#include "inventario.h"
#include "biblioteca.h"

#include "es-xml.h"

using namespace std;

Uint32 crearFicheros(){
	AtributoBase atrDentacosJoe(90,18,14,9,12,10,10,11,9,10,0.9,0.6,0.8,0.7,0.7,0.8,0.6,0.65,
			      string("datos-xml/atrBase-dentacosJoe.xml"));
    AtributoBase atrBaldos(120,8,7,12,9,10,14,8,12,6,0.7,0.85,0.6,0.9,0.5,0.6,0.9,0.5,
			      string("datos-xml/atrBase-baldos.xml"));
    AtributoBase atrGraimito(50,40,10,8,12,9,8,14,7,14,0.8,0.55,0.7,0.5,0.6,0.9,0.6,0.9,
			      string("datos-xml/atrBase-graimito.xml"));
    AtributoBase atrManoloLaPunki(80,20,10,11,12,7,8,10,11,13,0.7,0.65,0.8,0.6,0.9,0.8,0.7,0.7,
			      string("datos-xml/atrBase-manoloLaPunki.xml"));

    AtributoBase atrKinki1(80,20,10,11,12,7,8,10,11,13,0.7,0.65,0.8,0.6,0.9,0.8,0.7,0.7,
			      string("datos-xml/atrBase-kinki1.xml"));
    AtributoBase atrMari1(100,10,8,14,10,12,13,7,12,8,0.7,0.85,0.6,0.9,0.5,0.6,0.9,0.5,
				  string("datos-xml/atrBase-mari1"));
    AtributoBase atrEmo1(40,50,9,9,15,10,9,14,8,11,0.8,0.55,0.7,0.5,0.6,0.9,0.6,0.9,
				  string("datos-xml/atrBase-emo1"));

    Objeto Birra("Birra", 2,CURATIVO,25,50,5,string("datos-xml/obj-birra.xml"));
    Objeto Pitiflai("Pitiflai", 3, CURATIVO, 15,25,5,string("datos-xml/obj-pitiflai"));
    Objeto Grifa("Grifa",8,CAMBIO_ESTADO,8,15,2,string("datos-xml/obj-grifa.xml"));

    Inventario invAmpli(string("datos-xml/inv-ampli.xml"));
    invAmpli.addObjeto(Birra); invAmpli.addObjeto(Grifa); invAmpli.addObjeto(Pitiflai);
    Inventario invKinkis(string("datos-xml/inv-kinkis.xml"));
    Inventario invMaris(string("datos-xml/inv-maris.xml"));
    Inventario invEmos(string("datos-xml/inv-emos.xml"));

    Habilidad riffMuerte("Riff de la muerte", 1,ATAQUE,20,38,6,
    		string("datos-xml/hab-riffMuerte.xml"));
    Habilidad bomboCabeza("Bombo a la cabeza", 3, ATAQUE, 25,40,6,
    		string("datos-xml/hab-bomboCabeza.xml"));
    Habilidad tonoCurativo("Tono curativo",4,CURATIVO,30,40,15,
    		string("datos-xml/hab-tonoCurativo.xml"));
    Habilidad alaridoTremebundo("Alarido tremebundo",5,ATAQUE,25,38,9,
    		string("datos-xml/hab-alaridoTremebundo.xml"));
    Habilidad venganzaBajista("La venganza del Bajista",6,ATAQUE,70,120,70,
    		string("datos-xml/hab-venganzaBajista.xml"));

    Grupo AmpliBreakers(invAmpli,true,50,string("datos-xml/grp-ampli.xml"));
    Grupo Kinkis(invKinkis,false,70,string("datos-xml/grp-kinkis.xml"));
    Grupo Maris(invMaris,false,80,string("datos-xml/grp-maris.xml"));
    Grupo Emos(invEmos,false,90,string("datos-xml/grp-emos.xml"));

    Combatiente Dentacos("Dentacos Joe", 20, atrDentacosJoe, AmpliBreakers,
                         make_pair(14,20),string("datos-xml/comb-dentacos.xml"),12000,0,17,30);
    Dentacos.addHabilidad(riffMuerte);
    Combatiente Baldos("Baldos", 21, atrBaldos, AmpliBreakers, make_pair(23,32),
		       string("datos-xml/comb-baldos.xml"),
		       15000,0, 20, 40);
    Baldos.addHabilidad(bomboCabeza);
    Combatiente Graimito("Graimito el Bajo", 22, atrGraimito, AmpliBreakers,
			make_pair(13,20), string("datos-xml/comb-graimito.xml"),10000,0, 18, 20);
    Graimito.addHabilidad(tonoCurativo); Graimito.addHabilidad(venganzaBajista);
    Combatiente Manolo("Manolo la Punki", 23, atrManoloLaPunki, AmpliBreakers,
		       make_pair(18,25), string("datos-xml/comb-manolo.xml"), 13000,0, 20, 30);
    Manolo.addHabilidad(alaridoTremebundo);

    Combatiente shurmano("Shurmano",30,atrKinki1,Kinkis,make_pair(17,23),
		       string("datos-xml/comb-shurmano.xml"),10000,900,19,25);
    Combatiente shuprimo("Shuprimo",31,atrKinki1,Kinkis,make_pair(17,23),
		       string("datos-xml/comb-shuprimo.xml"),10000,1000,19,25);
    Combatiente tioshungo("Er tio shungoshungo",32,atrKinki1,Kinkis,make_pair(17,23),
		       string("datos-xml/comb-tioshungo.xml"),10000,1200,19,25);

	Combatiente paca("Paca", 35, atrMari1,Maris,make_pair(15,35),
			   string("datos-xml/comb-paca.xml"),12000,1500,24,30);
	Combatiente ortensia("Ortensia", 36, atrMari1,Maris,make_pair(15,35),
			   string("datos-xml/comb-ortensia.xml"),12000,1500,24,30);
	Combatiente juani("La juani", 37, atrMari1,Maris,make_pair(15,35),
			   string("datos-xml/comb-juani.xml"),12000,1500,24,30);
	Combatiente conchita("Conchita", 38, atrMari1,Maris,make_pair(15,35),
			   string("datos-xml/comb-conchita.xml"),12000,1500,24,30);

	Combatiente darknight("Dark Night", 40, atrEmo1,Emos,make_pair(15,35),
			   string("datos-xml/comb-darknight.xml"),9000,800,18,50);
	Combatiente bloodtears("Blood Tears", 41, atrEmo1,Emos,make_pair(15,35),
			   string("datos-xml/comb-bloodtears.xml"),9000,800,18,50);
	Combatiente death("I Wish Death", 42, atrEmo1,Emos,make_pair(15,35),
			   string("datos-xml/comb-death.xml"),9000,800,18,50);

	Biblioteca bib("datos-xml/biblioteca.xml");

    atrDentacosJoe.actualizarXML();
    atrBaldos.actualizarXML();
    atrGraimito.actualizarXML();
    atrManoloLaPunki.actualizarXML();

    Birra.actualizarXML();
    Pitiflai.actualizarXML();
    Grifa.actualizarXML();

    AmpliBreakers.actualizarXML();
    Kinkis.actualizarXML();
    Maris.actualizarXML();
    Emos.actualizarXML();

    riffMuerte.actualizarXML();
    bomboCabeza.actualizarXML();
    tonoCurativo.actualizarXML();
    alaridoTremebundo.actualizarXML();
    venganzaBajista.actualizarXML();

    Dentacos.actualizarXML();
    Baldos.actualizarXML();
    Graimito.actualizarXML();
    Manolo.actualizarXML();

    bib.setGrupoPrincipal(AmpliBreakers);
    bib.addPJGrupoPrincipal(Dentacos);
    bib.addPJGrupoPrincipal(Baldos);
    bib.addPJGrupoPrincipal(Graimito);
    bib.addPJGrupoPrincipal(Manolo);

    bib.addObjeto(Birra);
    bib.addObjeto(Pitiflai);
    bib.addObjeto(Grifa);

    bib.addHabilidad(riffMuerte);
    bib.addHabilidad(bomboCabeza);
    bib.addHabilidad(tonoCurativo);
    bib.addHabilidad(alaridoTremebundo);
    bib.addHabilidad(venganzaBajista);

    bib.addGrupoEnemigo(Kinkis);
    bib.addGrupoEnemigo(Maris);
    bib.addGrupoEnemigo(Emos);

    bib.actualizarXML();

	return 1;
}
