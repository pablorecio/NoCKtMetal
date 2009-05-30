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
//#include "iniciar-objetos.h"
#include "control-combate.h"

using namespace std;

int main(){
  //crearFicheros();

  /*#ifdef DEBUG
  cout << "Ficheros XML creados" << endl;
  #endif

  Objeto Birra("datos-xml/birra.xml");
  Objeto Grifa("datos-xml/grifa.xml");

  #ifdef DEBUG
  cout << "Objetos creados" << endl;
  #endif

  Inventario invAmpli("datos-xml/InventarioAmpli.xml");
  Inventario invKinkis("datos-xml/InventarioKinkis.xml");

  #ifdef DEBUG
  cout << "Inventarios creados" << endl;
  #endif

  Grupo AmpliBreakers("datos-xml/ampli.xml");
  Grupo Kinkis("datos-xml/kinkis.xml");

  #ifdef DEBUG
  cout << "Grupos creados" << endl;
  #endif

  Habilidad riffMuerte("datos-xml/riffMuerte.xml");
  Habilidad bomboCabeza("datos-xml/bomboCabeza.xml");
  Habilidad tonoCurativo("datos-xml/tonoCurativo.xml");
  Habilidad alaridoTremebundo("datos-xml/alaridoTremebundo.xml");

  #ifdef DEBUG
  cout << "Habilidades creadas" << endl;
  #endif

  Combatiente Dentacos("datos-xml/dentacos.xml");
  #ifdef DEBUG
  cout << "Dentacos creado" << endl;
  #endif
  Combatiente Baldos("datos-xml/baldos.xml");
  #ifdef DEBUG
  cout << "Baldos creado" << endl;
  #endif
  Combatiente Graimito("datos-xml/graimito.xml");
  #ifdef DEBUG
  cout << "Graimito creado" << endl;
  #endif
  Combatiente Manolo("datos-xml/manolo.xml");
  #ifdef DEBUG
  cout << "Manolo creado" << endl;
  cout << "Combatientes buenos creados" << endl;
  #endif

  Combatiente Kinki1("datos-xml/kinki1.xml");
  Combatiente Kinki2("datos-xml/kinki2.xml");
  Combatiente Kinki3("datos-xml/kinki3.xml");*/

  Grupo AmpliBreakers("datos-xml/ampli.xml");
  Grupo Kinkis("datos-xml/kinkis.xml");

  //#ifdef DEBUG
  //cout << "Enemigos creados" << endl;
  //cout << "Ficheros XML leidos" << endl;
  //#endif

    AmpliBreakers.mostrarGrupo();
    Kinkis.mostrarGrupo();

    ControlCombate combate(AmpliBreakers, Kinkis);

  #ifdef DEBUG
    cout << "Combate inicializado" << endl;
  #endif

    combate.iniciarCombate();
    combate.postCombate();
}

