/*
 * File:   main-combate.cpp
 * Author: riku
 *
 * Created on 27 de abril de 2009, 14:58
 */

#include <iostream>
#include <map>
#include <iterator>
#include <ctime>
#include <cstdlib>

#include "atributos.h"
#include "atributos_base.h"
#include "combatiente.h"
#include "grupo.h"
#include "habilidad.h"
#include "objeto.h"
#include "inventario.h"
#include "aleatorio.h"
#include "biblioteca.h"
#include "es-xml.h"
#include "control-combate.h"

using namespace std;

int main(){
  Biblioteca bib;
  bib.recargarXML("datos-xml/biblioteca.xml");
  cout << "Biblioteca cargada" << endl;

  Grupo AmpliBreakers(bib.getGrupoPrincipal().c_str());

  srand(time(0));
  cout << "WOLA RUBIOOOO " << bib.getNumeroGruposEnemigos() << endl;
  Aleatorio a;
  Uint32 num_rep = a.valorEntero(0,bib.getNumeroGruposEnemigos() - 1);
  map<Uint32,string> aux = bib.getGruposEnemigos();

  cout << "NUMERO ELEGIDO ES.............." << num_rep << endl;
  cout << "Antes del for :(" << endl;
  map<Uint32,string>::iterator I = aux.begin();
  for(size_t i = 0 ; i < num_rep ; i++){
	  I++;
  }
  cout << "Despues del for :)" << endl;
  cout << "Seleccionado " << I->first;
  cout << " " << bib.getGrupoEnemigo(I->first) << endl;

  Grupo Enemigos(bib.getGrupoEnemigo(I->first).c_str());

    AmpliBreakers.mostrarGrupo();
    Enemigos.mostrarGrupo();

    ControlCombate combate(AmpliBreakers, Enemigos);

  #ifdef DEBUG
    cout << "Combate inicializado" << endl;
  #endif

    combate.iniciarCombate();
    combate.postCombate();
}

