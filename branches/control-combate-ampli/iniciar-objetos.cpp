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
    AtributoBase atrDentacosJoe(90,18,14,9,12,10,10,11,9,10,0.9,0.6,0.8,0.7,0.7,0.8,0.6,0.65);
    AtributoBase atrBaldos(120,8,7,12,9,10,14,8,12,6,0.7,0.85,0.6,0.9,0.5,0.6,0.9,0.5);
    AtributoBase atrGraimito(50,40,10,8,12,9,8,14,7,14,0.8,0.55,0.7,0.5,0.6,0.9,0.6,0.9);
    AtributoBase atrManoloLaPunki(80,20,10,11,12,7,8,10,11,13,0.7,0.65,0.8,0.6,0.9,0.8,0.7,0.7);

    AtributoBase atrKinki1(80,20,10,11,12,7,8,10,11,13,0.7,0.65,0.8,0.6,0.9,0.8,0.7,0.7);

    Objeto Birra("Birra", 2,CURATIVO,25,50,5);
    Objeto Grifa("Grifa",8,CAMBIO_ESTADO,8,15,2);

    Inventario invAmpli; invAmpli.addObjeto(Birra); invAmpli.addObjeto(Grifa);
    Inventario invKinkis;

    Habilidad riffMuerte("Riff de la muerte", 1,ATAQUE,20,38,6);
    Habilidad bomboCabeza("Bombo a la cabeza", 3, ATAQUE, 25,40,6);
    Habilidad tonoCurativo("Tono curativo",4,CURATIVO,30,40,15);
    Habilidad alaridoTremebundo("Alarido tremebundo",5,ATAQUE,25,38,9);

    Grupo AmpliBreakers(invAmpli,true);
    Grupo Kinkis(invKinkis,false);

    Combatiente Dentacos("Dentacos Joe", 20, atrDentacosJoe, AmpliBreakers,
                         make_pair(14,20), 12000,17,30);
    Dentacos.addHabilidad(riffMuerte);
    Combatiente Baldos("Baldos", 21, atrBaldos, AmpliBreakers, make_pair(23,32),
                        15000, 20, 40);
    Baldos.addHabilidad(bomboCabeza);
    Combatiente Graimito("Graimito el Bajo", 22, atrGraimito, AmpliBreakers,
                         make_pair(13,20), 10000, 18, 20);
    Graimito.addHabilidad(tonoCurativo);
    Combatiente Manolo("Manolo la Punki", 23, atrManoloLaPunki, AmpliBreakers,
                       make_pair(18,25), 13000, 20, 30);
    Manolo.addHabilidad(alaridoTremebundo);

    Combatiente Kinki1("Kinki 1",30,atrKinki1,Kinkis,make_pair(17,23),10000,19,25);
    Combatiente Kinki2("Kinki 2",31,atrKinki1,Kinkis,make_pair(17,23),10000,19,25);
    Combatiente Kinki3("Kinki 3",32,atrKinki1,Kinkis,make_pair(17,23),10000,19,25);

    guardar_XML(Birra,"datos-xml/birra.xml");
    guardar_XML(Grifa,"datos-xml/grifa.xml");

    guardar_XML(invAmpli,"datos-xml/inventarioAmpli.xml");
    guardar_XML(invKinkis,"datos-xml/inventarioKinkis.xml");

    guardar_XML(AmpliBreakers,"datos-xml/ampli.xml");
    guardar_XML(Kinkis,"datos-xml/kinkis.xml");

    guardar_XML(riffMuerte,"datos-xml/riffMuerte.xml");
    guardar_XML(bomboCabeza,"datos-xml/bomboCabeza.xml");
    guardar_XML(tonoCurativo,"datos-xml/tonoCurativo.xml");
    guardar_XML(alaridoTremebundo,"datos-xml/alaridoTremebundo.xml");

    guardar_XML(Dentacos,"datos-xml/dentacos.xml");
    guardar_XML(Baldos,"datos-xml/baldos.xml");
    guardar_XML(Graimito,"datos-xml/graimito.xml");
    guardar_XML(Manolo,"datos-xml/manolo.xml");

    guardar_XML(Kinki1,"datos-xml/kinki1.xml");
    guardar_XML(Kinki2,"datos-xml/kinki2.xml");
    guardar_XML(Kinki3,"datos-xml/kinki3.xml");

    return 1;
}
