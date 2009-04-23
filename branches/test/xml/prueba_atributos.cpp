#include <iostream>
#include <cmath>

#include <SDL/SDL.h>

#include "atributos_base.h"
#include "atributos.h"

#include "tinyxml.h"

#define DEBUG 1
#define PRIMER_ASCII 65

using namespace std;

double prueba[19];
int i = 0;

void mostrarAtributos(Atributos atr);
void mostrarAtributosBase(AtributoBase atr);
void lecturaAtributoBase(AtributoBase& atr, const char* ficheroXML);
int leer_atributo(TiXmlElement* pElement);
int string_a_int(string s) {
    int res = 0;
    for (unsigned int i = 0; i < s.length(); i++) {
        res += pow(2, i)*(s[i] - PRIMER_ASCII);
    }
    return res;
}

int main(){
  //AtributoBase base(20,4,7,8,6,6,12,9,12,5,0.4,0.6,0.3,0.8,0.4,0.4,0.7,0.2);
  AtributoBase base;
  cout << "Base iniciado" << endl;
  lecturaAtributoBase(base,"base1.xml");
  cout << "XML leido" << endl;

  mostrarAtributosBase(base);

  Atributos atr(base,4000);

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


void lecturaAtributoBase(AtributoBase& atr, const char* ficheroXML){
  std::cout << "Funcion iniciada" << std::endl;
  TiXmlDocument doc;
  std::cout << "Lectura fichero "<< ficheroXML << std::endl;

  doc.LoadFile(ficheroXML);
  std::cout << "Fichero cargado" << std::endl;

  int valorI = 0; //valores para las consultas
  double valorD = 0;
  
  TiXmlNode *pPadre = &doc;
#ifdef DEBUG
  std::cout << "TiXmlNode *pPadre = &doc;" << std::endl;
  std::cout << pPadre->Value() << std::endl;
#endif
  TiXmlNode *pHijo = pPadre->FirstChild(); //Apunta a la cabecera del documento
#ifdef DEBUG
  std::cout << "TiXmlNode *pHijo = pPadre->FirstChild();" << std::endl;
  std::cout << pHijo->Value() << std::endl;
#endif
  pHijo = pHijo->NextSibling(); //Apunta a la raiz del documento
#ifdef DEBUG
  std::cout << "pHijo = pHijo->NextSibling();" << std::endl;
  std::cout << pHijo->Value() << std::endl;
#endif
  
  pHijo = pHijo->FirstChild(); //Ahora, apunta al primer elemento del documento.
#ifdef DEBUG
  std::cout << "pHijo = pHijo->FirstChild();" << std::endl;
  std::cout << pHijo->Value() << std::endl;
#endif
  
  while (pHijo != NULL) {
    int leida = string_a_int(pHijo->Value());
    if (leida == string_a_int("PV")) {
      pHijo->ToElement()->FirstAttribute()->QueryIntValue(&valorI);
      atr._PV = valorI;
    } else if (leida == string_a_int("PE")) {
      pHijo->ToElement()->FirstAttribute()->QueryIntValue(&valorI);
      atr._PE = valorI;
    } else if (leida == string_a_int("Velocidad")) {
      pHijo->ToElement()->FirstAttribute()->QueryIntValue(&valorI);
      atr._vel = valorI;
      pHijo->ToElement()->LastAttribute()->QueryDoubleValue(&valorD);
      atr._incVel = valorD;
    } else if (leida == string_a_int("Fuerza")) {
      pHijo->ToElement()->FirstAttribute()->QueryIntValue(&valorI);
      atr._fue = valorI;
      pHijo->ToElement()->LastAttribute()->QueryDoubleValue(&valorD);
      atr._incFue = valorD;
    } else if (leida == string_a_int("Destreza")) {
      pHijo->ToElement()->FirstAttribute()->QueryIntValue(&valorI);
      atr._des = valorI;
      pHijo->ToElement()->LastAttribute()->QueryDoubleValue(&valorD);
      atr._incDes = valorD;
    } else if (leida == string_a_int("Suerte")) {
      pHijo->ToElement()->FirstAttribute()->QueryIntValue(&valorI);
      atr._sue = valorI;
      pHijo->ToElement()->LastAttribute()->QueryDoubleValue(&valorD);
      atr._incSue = valorD;
    } else if (leida == string_a_int("Resistencia")) {
      pHijo->ToElement()->FirstAttribute()->QueryIntValue(&valorI);
      atr._res = valorI;
      pHijo->ToElement()->LastAttribute()->QueryDoubleValue(&valorD);
      atr._incRes = valorD;
    } else if (leida == string_a_int("Virtuosidad")) {
      pHijo->ToElement()->FirstAttribute()->QueryIntValue(&valorI);
      atr._vir = valorI;
      pHijo->ToElement()->LastAttribute()->QueryDoubleValue(&valorD);
      atr._incVir = valorD;
    } else if (leida == string_a_int("Constitucion")) {
      pHijo->ToElement()->FirstAttribute()->QueryIntValue(&valorI);
      atr._con = valorI;
      pHijo->ToElement()->LastAttribute()->QueryDoubleValue(&valorD);
      atr._incCon = valorD;
    } else if (leida == string_a_int("Inteligencia")) {
      pHijo->ToElement()->FirstAttribute()->QueryIntValue(&valorI);
      atr._int = valorI;
      pHijo->ToElement()->LastAttribute()->QueryDoubleValue(&valorD);
      atr._incInt = valorD;
    } else {
#ifdef DEBUG
      std::cout << "No se ha leido nada en este paso" << std::endl;
#endif
    }
    pHijo = pHijo->NextSibling();
  }
  








  // //pJonnathan->ToElement()->FirstAttribute()
  // pJonnathan->ToElement()->FirstAttribute()->QueryIntValue(&auxI);
  // //atributo->QueryIntValue(&auxI);
  // atr._PV = auxI;
  // pJonnathan = pJonnathan->NextSibling();

  // pJonnathan->ToElement()->FirstAttribute()->QueryIntValue(&auxI);
  // atr._PE = auxI;
  // pJonnathan = pJonnathan->NextSibling();

  // pJonnathan->ToElement()->FirstAttribute()->QueryIntValue(&auxI);
  // atr._vel = auxI;
  // pJonnathan = pJonnathan->NextSibling();

  // pJonnathan->ToElement()->FirstAttribute()->QueryIntValue(&auxI);
  // atr._fue = auxI;
  // pJonnathan = pJonnathan->NextSibling();

  // pJonnathan->ToElement()->FirstAttribute()->QueryIntValue(&auxI);
  // atr._des = auxI;
  // pJonnathan = pJonnathan->NextSibling();

  // pJonnathan->ToElement()->FirstAttribute()->QueryIntValue(&auxI);
  // atr._sue = auxI;
  // pJonnathan = pJonnathan->NextSibling();

  // pJonnathan->ToElement()->FirstAttribute()->QueryIntValue(&auxI);
  // atr._res = auxI;
  // pJonnathan = pJonnathan->NextSibling();

  // pJonnathan->ToElement()->FirstAttribute()->QueryIntValue(&auxI);
  // atr._vir = auxI;
  // pJonnathan = pJonnathan->NextSibling();

  // pJonnathan->ToElement()->FirstAttribute()->QueryIntValue(&auxI);
  // atr._con = auxI;
  // pJonnathan = pJonnathan->NextSibling();

  // pJonnathan->ToElement()->FirstAttribute()->QueryIntValue(&auxI);
  // atr._int = auxI;
  // pJonnathan = pJonnathan->NextSibling();

  // pJonnathan->ToElement()->FirstAttribute()->QueryDoubleValue(&auxD);
  // atr._incVel = auxD;
  // pJonnathan = pJonnathan->NextSibling();

  // pJonnathan->ToElement()->FirstAttribute()->QueryDoubleValue(&auxD);
  // atr._incFue = auxD;
  // pJonnathan = pJonnathan->NextSibling();

  // pJonnathan->ToElement()->FirstAttribute()->QueryDoubleValue(&auxD);
  // atr._incDes = auxD;
  // pJonnathan = pJonnathan->NextSibling();

  // pJonnathan->ToElement()->FirstAttribute()->QueryDoubleValue(&auxD);
  // atr._incSue = auxD;
  // pJonnathan = pJonnathan->NextSibling();

  // pJonnathan->ToElement()->FirstAttribute()->QueryDoubleValue(&auxD);
  // atr._incRes = auxD;
  // pJonnathan = pJonnathan->NextSibling();

  // pJonnathan->ToElement()->FirstAttribute()->QueryDoubleValue(&auxD);
  // atr._incVir = auxD;
  // pJonnathan = pJonnathan->NextSibling();

  // pJonnathan->ToElement()->FirstAttribute()->QueryDoubleValue(&auxD);
  // atr._incCon = auxD;
  // pJonnathan = pJonnathan->NextSibling();

  // pJonnathan->ToElement()->FirstAttribute()->QueryDoubleValue(&auxD);
  // atr._incInt = auxD;
}
