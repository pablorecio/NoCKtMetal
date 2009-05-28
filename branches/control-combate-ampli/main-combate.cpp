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

  cout << "Ficheros XML creados" << endl;

  Objeto Birra("datos-xml/birra.xml");
  Objeto Grifa("datos-xml/grifa.xml");

  cout << "Objetos creados" << endl;

  Inventario invAmpli("datos-xml/InventarioAmpli.xml");
  Inventario invKinkis("datos-xml/InventarioKinkis.xml");

  cout << "Inventarios creados" << endl;

  Grupo AmpliBreakers("datos-xml/ampli.xml");
  Grupo Kinkis("datos-xml/kinkis.xml");

  cout << "Grupos creados" << endl;

  Habilidad riffMuerte("datos-xml/riffMuerte.xml");
  Habilidad bomboCabeza("datos-xml/bomboCabeza.xml");
  Habilidad tonoCurativo("datos-xml/tonoCurativo.xml");
  Habilidad alaridoTremebundo("datos-xml/alaridoTremebundo.xml");

  cout << "Habilidades creadas" << endl;

  Combatiente Dentacos("datos-xml/dentacos.xml");
  cout << "Dentacos creado" << endl;
  Combatiente Baldos("datos-xml/baldos.xml");
  cout << "Baldos creado" << endl;
  Combatiente Graimito("datos-xml/graimito.xml");
  cout << "Graimito creado" << endl;
  Combatiente Manolo("datos-xml/manolo.xml");
  cout << "Manolo creado" << endl;

  cout << "Combatientes buenos creados" << endl;

  Combatiente Kinki1("datos-xml/kinki1.xml");
  Combatiente Kinki2("datos-xml/kinki2.xml");
  Combatiente Kinki3("datos-xml/kinki3.xml");

  cout << "Enemigos creados" << endl;

  cout << "Ficheros XML leidos" << endl;

    AmpliBreakers.mostrarGrupo();
    Kinkis.mostrarGrupo();

    ControlCombate combate(AmpliBreakers, Kinkis);

    cout << "Combate inicializado" << endl;

    combate.iniciarCombate();
    combate.postCombate();
}

