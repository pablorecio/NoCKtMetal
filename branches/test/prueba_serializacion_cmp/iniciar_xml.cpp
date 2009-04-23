#include <iostream>

#include <SDL/SDL.h>

#include "atributos_base.h"
#include "atributos.h"
#include "combatiente.h"
#include "grupo.h"
#include "especial.h"
#include "habilidad.h"
#include "objeto.h"
#include "inventario.h"

#include "es-xml.h"

using namespace std;

int main(){
  Objeto o1("Espada",1,ATAQUE,4,9,1);
  Objeto o2("Pocion", 2,CURATIVO,10,22,5);
  Objeto o3("Pua del destino", 10,ATAQUE,8,15,2);
  Objeto o4("Grifa",8,CAMBIO_ESTADO,40,70,1);
  
  cout << "main()" << endl;
  guardar_XML(o1,"datos-xml/objeto1.xml");
  cout << "Objeto 1 escrito" << endl;
  guardar_XML(o2,"datos-xml/objeto2.xml");
  cout << "Objeto 2 escrito" << endl;
  guardar_XML(o3,"datos-xml/objeto3.xml");
  cout << "Objeto 3 escrito" << endl;
  guardar_XML(o4,"datos-xml/objeto4.xml");
  cout << "Objeto 4 escrito" << endl;
  
  Inventario I;

  I.addObjeto(o1);
  I.addObjeto(o2);
  I.addObjeto(o3);
  I.addObjeto(o4);
  
  guardar_XML(I,"datos-xml/inventario1.xml");
  cout << "Inventario escrito" << endl;

  AtributoBase base1(20,4,7,8,6,6,12,9,12,5,0.4,0.6,0.3,0.8,0.4,0.4,0.7,0.2);
  AtributoBase base2(12,9,12,9,10,8,8,12,7,15,0.5,0.3,0.7,0.3,0.5,0.6,0.4,0.9);
  AtributoBase base3(25,2,9,12,5,7,8,12,10,7,0.5,0.3,0.7,0.9,0.3,0.3,0.7,0.2);

  guardar_XML(base1,"datos-xml/atrBase1.xml");
  cout << "AtributoBase 1 escrito" << endl;
  guardar_XML(base2,"datos-xml/atrBase2.xml");
  cout << "AtributoBase 2 escrito" << endl;
  guardar_XML(base3,"datos-xml/atrBase3.xml");
  cout << "AtributoBase 3 escrito" << endl;


  Habilidad H1("Solo mortal",7,ATAQUE,6,12,3);
  Habilidad H2("Redoble veloz",11,ATAQUE,9,15,4);
  Habilidad H3("Arrastrada",4,ATAQUE,1,4,1);
  Habilidad H4("Dame20sentimos",5,ATAQUE,20,40,1);
  Habilidad H5("Bajista imbecil",6,CURATIVO,12,19,5);

  guardar_XML(H1,"datos-xml/habilidad1.xml");
  cout << "Habilidad 1 escrito" << endl;
  guardar_XML(H2,"datos-xml/habilidad2.xml");
  cout << "Habilidad 2 escrito" << endl;
  guardar_XML(H3,"datos-xml/habilidad3.xml");
  cout << "Habilidad 3 escrito" << endl;
  guardar_XML(H4,"datos-xml/habilidad4.xml");
  cout << "Habilidad 4 escrito" << endl;
  guardar_XML(H5,"datos-xml/habilidad5.xml");
  cout << "Habilidad 5 escrito" << endl;


  Grupo G(I,true);

  Combatiente Baldos("Baldos", 0, base3, G, 9000);
  Combatiente Graimito("Graimito",1, base2, G, 12000);

  Baldos.addHabilidad(H1);
  Baldos.addHabilidad(H2);

  Graimito.addHabilidad(H3);
  Graimito.addHabilidad(H5);

  guardar_XML(G,"datos-xml/grupo.xml");
  cout << "Grupo escrito" << endl;
  guardar_XML(Baldos,"datos-xml/baldos.xml");
  cout << "Baldos escrito" << endl;
  guardar_XML(Graimito,"datos-xml/graimito.xml");
  cout << "Graimito escrito" << endl;
}
