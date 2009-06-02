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

    /* ----------------------- AMPLIS -----------------------------*/

    Arma Strato("Guitarra Strato",100,ARMA,15,23,false,18,
    		string("datos-xml/arma-strato"));
    Arma Baquetas("Baquetas",101,ARMA,25,35,false,19,
    		string("datos-xml/arma-baquetas"));
    Arma Cuerdita("Bajo cuerdita",102,ARMA,13,20,false,21,
    		string("datos-xml/arma-cuerdita"));
    Arma MicroInfernal("Micro Infernal",103,ARMA,18,25,false,18,
    		string("datos-xml/arma-micro"));

    Armadura ChupaCuero1("Chupa de cuero", 110, DEFENSIVO, 0, 0,false, 35,
    		string("datos-xml/armadura-chupa"));
    Armadura ChupaCuero2("Chupa de cuero", 120, DEFENSIVO, 0, 0,false, 35,
    		string("datos-xml/armadura-chupa"));
    Armadura ChupaCuero3("Chupa de cuero", 130, DEFENSIVO, 0, 0,false, 35,
    		string("datos-xml/armadura-chupa"));
    Armadura ChupaCuero4("Chupa de cuero", 140, DEFENSIVO, 0, 0,false, 35,
    		string("datos-xml/armadura-chupa"));

    Combatiente Dentacos("Dentacos Joe", 20, atrDentacosJoe, AmpliBreakers,
                         string("datos-xml/comb-dentacos.xml"),Strato,
                         ChupaCuero1,12000);
    Dentacos.addHabilidad(riffMuerte);

    Combatiente Baldos("Baldos", 21, atrBaldos, AmpliBreakers,
		       string("datos-xml/comb-baldos.xml"), Baquetas, ChupaCuero2,
		       15000);
    Baldos.addHabilidad(bomboCabeza);

    Combatiente Graimito("Graimito el Bajo", 22, atrGraimito, AmpliBreakers,
			string("datos-xml/comb-graimito.xml"),Cuerdita,ChupaCuero3,10000);
    Graimito.addHabilidad(tonoCurativo); Graimito.addHabilidad(venganzaBajista);

    Combatiente Manolo("Manolo la Punki", 23, atrManoloLaPunki, AmpliBreakers,
		       string("datos-xml/comb-manolo.xml"),MicroInfernal, ChupaCuero4, 13000);
    Manolo.addHabilidad(alaridoTremebundo);

    /* ------------------------------------------------------------*/
    /* ----------------------- KINKIS -----------------------------*/

    Arma Navajote1("Er navajote",104,ARMA,17,23,false,19,
    		string("datos-xml/arma-navajote"));
    Arma Navajote2("Er navajote",114,ARMA,17,23,false,19,
    		string("datos-xml/arma-navajote"));
    Arma Navajote3("Er navajote",124,ARMA,17,23,false,19,
    		string("datos-xml/arma-navajote"));

    Armadura Shanda1("Er shanda naik", 121, DEFENSIVO, 0, 0,false, 25,
    		string("datos-xml/armadura-shanda"));
    Armadura Shanda2("Er shanda naik", 131, DEFENSIVO, 0, 0,false, 25,
    		string("datos-xml/armadura-shanda"));
    Armadura Shanda3("Er shanda naik", 141, DEFENSIVO, 0, 0,false, 25,
    		string("datos-xml/armadura-shanda"));

    Combatiente shurmano("Shurmano",30,atrKinki1,Kinkis,
		       string("datos-xml/comb-shurmano.xml"),Navajote1,Shanda1,10000,900);

    Combatiente shuprimo("Shuprimo",31,atrKinki1,Kinkis,
		       string("datos-xml/comb-shuprimo.xml"),Navajote2,Shanda2,10000,900);

    Combatiente tioshungo("Er tio shungoshungo",32,atrKinki1,Kinkis,
		       string("datos-xml/comb-tioshungo.xml"),Navajote3,Shanda3,10000,900);

    /* ------------------------------------------------------------*/
    /* ------------------------ MARIS -----------------------------*/
    Arma BolsaMercadia1("Bolsa mercadia",105,ARMA,15,35,false,24,
    		string("datos-xml/arma-bolsa"));
    Arma BolsaMercadia2("Bolsa mercadia",115,ARMA,15,35,false,24,
    		string("datos-xml/arma-bolsa"));
    Arma BolsaMercadia3("Bolsa mercadia",125,ARMA,15,35,false,24,
    		string("datos-xml/arma-bolsa"));
    Arma BolsaMercadia4("Bolsa mercadia",135,ARMA,15,35,false,24,
    		string("datos-xml/arma-bolsa"));

    Armadura Bata1("La bata de guatiné", 112, DEFENSIVO, 0, 0,false, 30,
    		string("datos-xml/armadura-bata"));
    Armadura Bata2("La bata de guatiné", 122, DEFENSIVO, 0, 0,false, 30,
    		string("datos-xml/armadura-bata"));
    Armadura Bata3("La bata de guatiné", 132, DEFENSIVO, 0, 0,false, 30,
    		string("datos-xml/armadura-bata"));
    Armadura Bata4("La bata de guatiné", 142, DEFENSIVO, 0, 0,false, 30,
    		string("datos-xml/armadura-bata"));

	Combatiente paca("Paca", 35, atrMari1,Maris,
			   string("datos-xml/comb-paca.xml"),BolsaMercadia1,Bata1,12000,1500);

	Combatiente ortensia("Ortensia", 36, atrMari1,Maris,
			   string("datos-xml/comb-ortensia.xml"),BolsaMercadia2,Bata2,12000,1500);

	Combatiente juani("La juani", 37, atrMari1,Maris,
			   string("datos-xml/comb-juani.xml"),BolsaMercadia3,Bata3,12000,1500);

	Combatiente conchita("Conchita", 38, atrMari1,Maris,
			   string("datos-xml/comb-conchita.xml"),BolsaMercadia4,Bata4,12000,1500);

    /* ------------------------------------------------------------*/
    /* ------------------------- EMOS -----------------------------*/
    Arma CuchillaAfeitar1("Cuchilla de afetiar",106,ARMA,15,25,false,18,
    		string("datos-xml/arma-cuchilla"));
    Arma CuchillaAfeitar2("Cuchilla de afetiar",116,ARMA,15,25,false,18,
    		string("datos-xml/arma-cuchilla"));
    Arma CuchillaAfeitar3("Cuchilla de afetiar",126,ARMA,15,25,false,18,
    		string("datos-xml/arma-cuchilla"));

    Armadura Flequillo1("Flequillo visera", 113, DEFENSIVO, 0, 0, false,50,
    		string("datos-xml/armadura-flequillo"));
    Armadura Flequillo2("Flequillo visera", 123, DEFENSIVO, 0, 0, false,50,
    		string("datos-xml/armadura-flequillo"));
    Armadura Flequillo3("Flequillo visera", 133, DEFENSIVO, 0, 0, false,50,
    		string("datos-xml/armadura-flequillo"));

	Combatiente darknight("Dark Night", 40, atrEmo1,Emos,
			   string("datos-xml/comb-darknight.xml"),
			   CuchillaAfeitar1,Flequillo1,9000,800);

	Combatiente bloodtears("Blood Tears", 41, atrEmo1,Emos,
			   string("datos-xml/comb-bloodtears.xml"),
			   CuchillaAfeitar2,Flequillo2,9000,800);

	Combatiente death("I Wish Death", 42, atrEmo1,Emos,
			   string("datos-xml/comb-death.xml"),
			   CuchillaAfeitar3,Flequillo3,9000,800);

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
