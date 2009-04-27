/* 
 * File:   main-combate.cpp
 * Author: riku
 *
 * Created on 27 de abril de 2009, 14:58
 */

#include <iostream>

#include "atributos.h"
#include "atributos_base.h"
#include "combatiente.h"
#include "grupo.h"
#include "habilidad.h"
#include "objeto.h"
#include "inventario.h"

#include "es-xml.h"
#include "iniciar-objetos.h"
#include "control-combate.h"

using namespace std;

int main(){
    crearFicheros();

    Objeto Birra; cargar_XML(Birra,"datos-xml/birra.xml");
    Objeto Grifa; cargar_XML(Grifa,"datos-xml/grifa.xml");

    Inventario invAmpli; cargar_XML(invAmpli,"datos-xml/inventarioAmpli.xml");
    Inventario invKinkis; cargar_XML(invKinkis,"datos-xml/inventarioKinkis.xml");

    Grupo AmpliBreakers; cargar_XML(AmpliBreakers,"datos-xml/ampli.xml");
    Grupo Kinkis; cargar_XML(Kinkis,"datos-xml/kinkis.xml");

    Habilidad riffMuerte ; cargar_XML(riffMuerte,"datos-xml/riffMuerte.xml");
    Habilidad bomboCabeza ; cargar_XML(bomboCabeza,"datos-xml/bomboCabeza.xml");
    Habilidad tonoCurativo ; cargar_XML(tonoCurativo,"datos-xml/tonoCurativo.xml");
    Habilidad alaridoTremebundo ; cargar_XML(alaridoTremebundo,"datos-xml/alaridoTremebundo.xml");

    Combatiente Dentacos; cargar_XML(Dentacos,"datos-xml/dentacos.xml");
    Combatiente Baldos; cargar_XML(Baldos,"datos-xml/baldos.xml");
    Combatiente Graimito; cargar_XML(Graimito,"datos-xml/graimito.xml");
    Combatiente Manolo; cargar_XML(Manolo,"datos-xml/manolo.xml");

    Combatiente Kinki1; cargar_XML(Kinki1,"datos-xml/kinki1.xml");
    Combatiente Kinki2; cargar_XML(Kinki2,"datos-xml/kinki2.xml");
    Combatiente Kinki3; cargar_XML(Kinki3,"datos-xml/kinki3.xml");

    cout << "Ficheros XML leidos" << endl;

    AmpliBreakers.mostrarGrupo();
    Kinkis.mostrarGrupo();

    ControlCombate combate(AmpliBreakers, Kinkis);

    cout << "Combate inicializado" << endl;

    combate.iniciarCombate();
}

