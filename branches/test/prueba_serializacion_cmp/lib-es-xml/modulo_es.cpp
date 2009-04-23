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

#include <iostream>
#include <cmath>
#include <vector>

#include "modulo_es.h"

#include "../atributos_base.h"
//#include "../atributos.h"
//#include "../combatiente.h"
//#include "../grupo.h"
//#include "../especial.h"
//#include "../habilidad.h"
//#include "../objeto.h"

#include "../tinyxml/tinyxml.h"

#define DEBUG 1
#define PRIMER_ASCII 65

using namespace std;

static int string_a_int(string s);

void lecturaAtributoBase(AtributoBase& atr, const char* ficheroXML) {
//    vector<int> valoresDeCadena(10);
//
//    valoresDeCadena[0] = string_a_int("PV");
//    valoresDeCadena[1] = string_a_int("PE");
//    valoresDeCadena[2] = string_a_int("Velocidad");
//    valoresDeCadena[3] = string_a_int("Fuerza");
//    valoresDeCadena[4] = string_a_int("Destreza");
//    valoresDeCadena[5] = string_a_int("Suerte");
//    valoresDeCadena[6] = string_a_int("Resistencia");
//    valoresDeCadena[7] = string_a_int("Virtuosidad");
//    valoresDeCadena[8] = string_a_int("Constitucion");
//    valoresDeCadena[9] = string_a_int("Inteligencia");

    TiXmlDocument doc;

    #ifdef DEBUG
      std::cout << "TiXmlDocument doc;" << std::endl;
    #endif

    doc.LoadFile(ficheroXML); //Cargamos el fichero XML
    #ifdef DEBUG
      std::cout << "doc.LoadFile(ficheroXML);" << std::endl;
    #endif

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
}
////void escrituraAtributoBase(const AtributoBase& atrB, const char* ficheroXML);//necesario?
///*---------- Viendo esto, me planteo, ¿es necesaria una clase Atributos? ----------*/
//void lecturaAtributos(Atributos& atr, const char* ficheroXML);
//void escrituraAtributos(const Atributos& atr, const char* ficheroXML);
///*---------------------------------------------------------------------------------*/
//void lecturaCombatientes(Combatiente& comb, const char* ficheroXML);
//void escrituraCombatientes(const Combatiente& comb, const char* ficheroXML);
//
//void lecturaGrupo(Grupo& grupo, const char* ficheroXML);
////void escrituraGrupo(const Grupo& grupo, const char* ficheroXML); //necesario?
//// el grupo siempre tendrá los mismos atributos...
//
//void lecturaHabilidad(Habilidad& hab, const char* ficheroXML);
////void escrituraHabilidad(const Habilidad& hab, const char* ficheroXML);
////idem, ¿es necesario escribir una habilidad desde el sistema?
//
//void lecturaObjeto(Objeto& obj, const char* ficheroXML);
//void escrituraObjeto(const Objeto& obj, const char* ficheroXML);
//
//void lecturaInventario(Inventario& inv, const char* ficheroXML);
//void escrituraInventario(const Inventario& inv, const char* ficheroXML);

/**
 * Pequeña función para convertir de forma biyectiva una cadena a un entero,
 * para poder hacer uso de la sentencia switch
 */
int string_a_int(string s) {
    int res = 0;
    for (unsigned int i = 0; i < s.length(); i++) {
        res += pow(2, i)*(s[i] - PRIMER_ASCII);
    }
    return res;
}
