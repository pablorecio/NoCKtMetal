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
 * File:   control-combate.h
 * Author: Pablo Recio Quijano
 *
 * Created on 27 de abril de 2009, 1:12
 */

#ifndef _CONTROLCOMBATE_H
#define	_CONTROLCOMBATE_H

#include <iostream>
#include <queue>

#include <SDL/SDL.h>

#include "grupo.h"
#include "combatiente.h"

using namespace std;

class ControlTurno;

class ControlCombate {
public:
    ControlCombate();
    ControlCombate(Grupo &g1, Grupo &g2);

    Uint32 iniciarCombate();

    Uint32 postCombate();
private:
    Grupo *_g1, *_g2;

    friend class ControlTurno;
};

class ControlTurno {
public:
    ControlTurno();
    ControlTurno(ControlCombate &comb);

    Uint32 iteracionTurno();

    bool finTurno(){ return _turno.empty(); }
private:
    ControlCombate *_comb;
    queue<Combatiente*> _turno;

    Uint32 seleccionaAccion(const Combatiente& c);

    void mostrarMenu(const Combatiente& c);
    void mostrarHabilidades(const Combatiente& c);
    void mostrarInventario(const Combatiente& c);
    void mostrarObjetivos(const Combatiente& c);

    void seleccionarObjetivo(const Combatiente& c, Combatiente* objetivo)
        throw(Grupo::NoExisteCombatiente);
};

#endif	/* _CONTROLCOMBATE_H */