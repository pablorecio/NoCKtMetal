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
 * Fichero = iacombate.h
 * Autor = Pablo Recio Quijano
 * Fecha = 30 de mayo de 2009
 * --------------------------------------------------------
 */

#ifndef _IACOMBATE_H
#define	_IACOMBATE_H

#include <SDL/SDL.h>

#include "combatiente.h"
#include "grupo.h"

class IACombate {
public:
    IACombate(){}

    IACombate(Combatiente &act, Grupo &g1, Grupo &g2);
    
    //Los 4 parámetros por referencia serán valores indicativos que se escribirán
    //que daño se ha realizado, que tipo de ataque, el indice de si es objeto 
    //o habilidad, y el objetivo.
    void atacar(Uint32 &danio, Uint32 &tipo, Uint32 &indice, Uint32 &objetivo);

private:
    Grupo *_g1; //Siempre tener en cuenta que _g1 es el grupo del jugador
    Grupo *_g2;
    Combatiente *_actual;

    Uint32 seleccionarTipoAtaque();
    Uint32 seleccionarHabilidad();
    Uint32 seleccionarObjeto();
    Combatiente* seleccionarObjetivo();
};

#endif	/* _IACOMBATE_H */

