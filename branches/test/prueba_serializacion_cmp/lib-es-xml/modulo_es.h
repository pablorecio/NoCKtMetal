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
 * --------------------------------------------------------
 * Fichero = modulo_es.h
 * Autor = Pablo Recio Quijano
 * Fecha = 21 de abril de 2009
 * --------------------------------------------------------
 */

#ifndef _MODULO_ES_H
#define	_MODULO_ES_H

#include "../atributos_base.h"
#include "../atributos.h"
//#include "../combatiente.h"
//#include "../grupo.h"
//#include "../especial.h"
//#include "../habilidad.h"
//#include "../objeto.h"


//Declaracion adelantada de las clases usadas
class AtributoBase;

void lecturaAtributoBase(AtributoBase& atrB, const char* ficheroXML);
//void escrituraAtributoBase(const AtributoBase& atrB, const char* ficheroXML);//necesario?
/*---------- Viendo esto, me planteo, ¿es necesaria una clase Atributos? ----------*/
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

#endif	/* _MODULO_ES_H */

