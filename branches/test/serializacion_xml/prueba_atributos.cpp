#include <iostream>
#include <fstream>

#include "atributos_base.h"
#include "atributos.h"

#include <boost/archive/tmpdir.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>

#include <boost/serialization/serialization.hpp>
#include <boost/serialization/nvp.hpp>

using namespace std;

void guardar_atributosBase(const AtributoBase &a, const char *fichero);
//void cargar_atributosBase(AtributoBase &a, const char *fichero);
void guardar_atributos(const Atributos &a, const char *fichero);

void mostrarAtributos(Atributos atr);
void mostrarAtributosBase(AtributoBase atr);

int main(){
  AtributoBase base(20,4,7,8,6,6,12,9,12,5,0.4,0.6,0.3,0.8,0.4,0.4,0.7,0.2);
  //AtributoBase base;
  guardar_atributosBase(base,"AtrB1.xml");
  cout << "Base iniciado" << endl;
  //lecturaAtributoBase(base,"base1.xml");
  cout << "XML leido" << endl;

  mostrarAtributosBase(base);

  Atributos atr(base,4000);
  guardar_atributos(atr,"Atr1.xml");

  mostrarAtributos(atr);
  cout << "1001 puntos de experiencia" << endl << endl;
  atr.addExperiencia(1001);

  mostrarAtributos(atr);
  cout << "1000000 puntos de experiencia" << endl << endl;
  atr.addExperiencia(500000);

  mostrarAtributos(atr);

  for(int i = 0 ; i < 10 ; i++){
    cout << "Tirada " << i << " de suerte: " 
	 <<  atr.tiradaSuerte() << endl;
  }

  for(int i = 0 ; i < 10 ; i++){
    cout << "Tirada " << i << " de velocidad: " 
	 <<  atr.tiradaVelocidad() << endl;
  }

  for(int i = 0 ; i < 10 ; i++){
    cout << "Tirada " << i << " de fuerza: " 
	 <<  atr.tiradaFuerza() << endl;
  }

  for(int i = 0 ; i < 10 ; i++){
    cout << "Tirada " << i << " de destreza: " 
	 <<  atr.tiradaDestreza() << endl;
  }

  for(int i = 0 ; i < 10 ; i++){
    cout << "Tirada " << i << " de resistencia: " 
	 <<  atr.tiradaResistencia() << endl;
  }

  for(int i = 0 ; i < 10 ; i++){
    cout << "Tirada " << i << " de virtuosidad: " 
	 <<  atr.tiradaVirtuosidad() << endl;
  }

  for(int i = 0 ; i < 10 ; i++){
    cout << "Tirada " << i << " de constitucion: " 
	 <<  atr.tiradaConstitucion() << endl;
  }

  for(int i = 0 ; i < 10 ; i++){
    cout << "Tirada " << i << " de inteligencia: " 
	 <<  atr.tiradaInteligencia() << endl;
  }
}

void mostrarAtributos(Atributos atr){
  cout << "Nivel: " << atr.getNivel() << endl;
  cout << "Experiencia: " << atr.getExperiencia() << endl;
  cout << "Experiencia para el siguiente nivel: " << atr.getExperienciaSiguienteNivel() << endl;
  cout << "PV: " << atr.getPV() << endl;
  cout << "PE: " << atr.getPE() << endl;
  cout << "Velocidad: " << atr.getVelocidad() << endl;
  cout << "Fuerza: " << atr.getFuerza() << endl;
  cout << "Destreza: " << atr.getDestreza() << endl;
  cout << "Suerte: " << atr.getSuerte() << endl;
  cout << "Resistencia: " << atr.getResistencia() << endl;
  cout << "Virtuosidad: " << atr.getVirtuosidad() << endl;
  cout << "Constitucion: " << atr.getConstitucion() << endl;
  cout << "Inteligencia: " << atr.getInteligencia() << endl;
}

void mostrarAtributosBase(AtributoBase atr){
  cout << "PV: " << atr.getPV() << endl;
  cout << "PE: " << atr.getPE() << endl;
  cout << "Velocidad: " << atr.getVelocidad() << endl;
  cout << "Fuerza: " << atr.getFuerza() << endl;
  cout << "Destreza: " << atr.getDestreza() << endl;
  cout << "Suerte: " << atr.getSuerte() << endl;
  cout << "Resistencia: " << atr.getResistencia() << endl;
  cout << "Virtuosidad: " << atr.getVirtuosidad() << endl;
  cout << "Constitucion: " << atr.getConstitucion() << endl;
  cout << "Inteligencia: " << atr.getInteligencia() << endl;
}

void guardar_atributosBase(const AtributoBase &a, const char *fichero){
  std::ofstream sal(fichero);
  assert(sal.good());
  boost::archive::xml_oarchive xml_sal(sal);
  xml_sal << BOOST_SERIALIZATION_NVP(a);
}

void guardar_atributos(const Atributos &a, const char *fichero){
  std::ofstream sal(fichero);
  assert(sal.good());
  boost::archive::xml_oarchive xml_sal(sal);
  xml_sal << BOOST_SERIALIZATION_NVP(a);
}


