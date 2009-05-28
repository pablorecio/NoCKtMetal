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

#include "es-xml.h"

using namespace std;

Uint32 crearFicheros(){
  AtributoBase atrDentacosJoe(90,18,14,9,12,10,10,11,9,10,0.9,0.6,0.8,0.7,0.7,0.8,0.6,0.65,
			      string("datos-xml/atrBase-DentacosJoe.xml"));

    AtributoBase atrBaldos(120,8,7,12,9,10,14,8,12,6,0.7,0.85,0.6,0.9,0.5,0.6,0.9,0.5,
			      string("datos-xml/atrBase-Baldos.xml"));
    AtributoBase atrGraimito(50,40,10,8,12,9,8,14,7,14,0.8,0.55,0.7,0.5,0.6,0.9,0.6,0.9,
			      string("datos-xml/atrBase-Graimito.xml"));
    AtributoBase atrManoloLaPunki(80,20,10,11,12,7,8,10,11,13,0.7,0.65,0.8,0.6,0.9,0.8,0.7,0.7,
			      string("datos-xml/atrBase-ManoloLaPunki.xml"));

    AtributoBase atrKinki1(80,20,10,11,12,7,8,10,11,13,0.7,0.65,0.8,0.6,0.9,0.8,0.7,0.7,
			      string("datos-xml/atrBase-Kinki1.xml"));

    Objeto Birra("Birra", 2,CURATIVO,25,50,5,string("datos-xml/birra.xml"));
    Objeto Grifa("Grifa",8,CAMBIO_ESTADO,8,15,2,string("datos-xml/grifa.xml"));

    Inventario invAmpli(string("datos-xml/InventarioAmpli.xml")); 
    invAmpli.addObjeto(Birra); invAmpli.addObjeto(Grifa);
    Inventario invKinkis(string("datos-xml/InventarioKinkis.xml"));

    Habilidad riffMuerte("Riff de la muerte", 1,ATAQUE,20,38,6,string("datos-xml/riffMuerte.xml"));
    Habilidad bomboCabeza("Bombo a la cabeza", 3, ATAQUE, 25,40,6,string("datos-xml/bomboCabeza.xml"));
    Habilidad tonoCurativo("Tono curativo",4,CURATIVO,30,40,15,string("datos-xml/tonoCurativo.xml"));
    Habilidad alaridoTremebundo("Alarido tremebundo",5,ATAQUE,25,38,9,string("datos-xml/alaridoTremebundo.xml"));

    Grupo AmpliBreakers(invAmpli,true,string("datos-xml/ampli.xml"));
    Grupo Kinkis(invKinkis,false,string("datos-xml/kinkis.xml"));

    Combatiente Dentacos("Dentacos Joe", 20, atrDentacosJoe, AmpliBreakers,
                         make_pair(14,20),string("datos-xml/dentacos.xml"),12000,0,17,30);
    Dentacos.addHabilidad(riffMuerte);
    Combatiente Baldos("Baldos", 21, atrBaldos, AmpliBreakers, make_pair(23,32),
		       string("datos-xml/baldos.xml"),
		       15000,0, 20, 40);
    Baldos.addHabilidad(bomboCabeza);
    Combatiente Graimito("Graimito el Bajo", 22, atrGraimito, AmpliBreakers,
			make_pair(13,20), string("datos-xml/graimito.xml"),10000,0, 18, 20);
    Graimito.addHabilidad(tonoCurativo);
    Combatiente Manolo("Manolo la Punki", 23, atrManoloLaPunki, AmpliBreakers,
		       make_pair(18,25), string("datos-xml/manolo.xml"), 13000,0, 20, 30);
    Manolo.addHabilidad(alaridoTremebundo);

    Combatiente Kinki1("Kinki 1",30,atrKinki1,Kinkis,make_pair(17,23),
		       string("datos-xml/kinki1.xml"),10000,900,19,25);
    Combatiente Kinki2("Kinki 2",31,atrKinki1,Kinkis,make_pair(17,23),
		       string("datos-xml/kinki2.xml"),10000,1000,19,25);
    Combatiente Kinki3("Kinki 3",32,atrKinki1,Kinkis,make_pair(17,23),
		       string("datos-xml/kinki3.xml"),10000,1200,19,25);

    atrDentacosJoe.actualizarXML();
    atrBaldos.actualizarXML();
    atrGraimito.actualizarXML();
    atrManoloLaPunki.actualizarXML();

    Birra.actualizarXML();
    Grifa.actualizarXML();

    invAmpli.actualizarXML();
    invKinkis.actualizarXML();

    AmpliBreakers.actualizarXML();
    Kinkis.actualizarXML();

    riffMuerte.actualizarXML();
    bomboCabeza.actualizarXML();
    tonoCurativo.actualizarXML();
    alaridoTremebundo.actualizarXML();

    Dentacos.actualizarXML();
    Baldos.actualizarXML();
    Graimito.actualizarXML();
    Manolo.actualizarXML();

    Kinki1.actualizarXML();
    Kinki2.actualizarXML();
    Kinki3.actualizarXML();

    return 1;
}
