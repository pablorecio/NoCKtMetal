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

//#define DEBUG 1

using namespace std;

class ControlTurno;

/**
 * Clase controladora, la cual controla el flujo del desarrollo de un combate.
 *
 * El uso de esta clase es bastante simple:
 *
 * <code>ControlCombate C(G1,G2);</code>
 *
 * Creamos el objeto <code>ControlCombate</code> pasándole los dos grupos que
 * participan en dicho combate. Luego simplemente, usamos las funciones
 * <code>iniciarCombate()</code> y <code>postCombate()</code> para iniciar el
 * combate, e internamente realiza todo el proceso. En el postcombate se calcula
 * la experiencia obtenida, subidas de nivel, y almacenamiento de los objetos necesarios.
 *
 * <B>PRECUACIÓN: </B> Es necesario para el correcto funcionamiento de la clase, que
 * ambos grupos tengan correctamente inicializados sus inventarios, personajes, habilidades
 * y demás objetos necesarios para el funcionamiento.
 *
 * @author Pablo Recio Quijano
 * @todo ¿ControlTurno es interna de ControlCombate?
 */
class ControlCombate {
public:
    /**
     * Constructor vacio de un objeto de la clase <code>ControlCombate</code>
     */
    ControlCombate();

    /**
     * Constructor de un objeto de la clase <code>ControlCombate</code>,
     * generando un combate entre los grupos dados.
     *
     * @param g1 Grupo 1 participante del combate
     * @param g2 Grupo 2 participante del combate
     */
    ControlCombate(Grupo &g1, Grupo &g2);

    /**
     * Función que inicia el combate. Esta función, realiza un bucle,
     * de forma que mientras los dos grupos estén vivos, se van haciendo
     * turnos, que internamente usan la clase <code>ControlTurno</code>,
     * para ir iterando cada acción dentro de un turno.
     *
     * @return Devuelve 1 si combate se ha iniciado correctamente.
     */
    Uint32 iniciarCombate();

    /**
     * Función que realiza los cálculos de postcombate (experiencia, guardado...)
     *
     * @return
     * @todo Toda la función xD
     */
    Uint32 postCombate();
private:
    Grupo *_g1, *_g2;
    bool _huida;
    void mostrarCombate();

    friend class ControlTurno;
};

/**
 * Clase que controla la secuencia de cada turno. Cada turno se compone
 * de acciones, organizadas al comienzo del turno en función de la velocidad
 * de cada combatiente.
 *
 * De esta forma, la secuencia normal de un turno sería la siguiente:
 * <UL>
 * <LI> Se crea un objeto de la clase <code>ControlTurno</code>, pasándole el
 * combate al que pertenece dicho turno.
 * <LI> Mientras que no se acabe el turno:
 * <LI> Se itera en dicho turno, con <code>iteracionTurno()</code>
 * </UL>
 *
 * Internamente, cuando se crea el objeto, se crea una cola de acciones, en función
 * de la velocidad de cada personaje. Cada iteración del turno, consume una posición
 * de la cola, por tanto un turno no termina hasta que no se quede esa cola vacia.
 *
 * Hay que tener en cuenta, que esta clase está marcada como amiga de ControlCombate,
 * por lo que tenemos libertad a acceder a los atributos de esta clase.
 *
 * @author Pablo Recio Quijano
 */
class ControlTurno {
public:
    /**
     * Constructor vacio. No hace nada.
     */
    ControlTurno();

    /*
     * Construye un objeto de la clase <code>ControlTurno</code>. Este constructor
     * se encarga, aparte de asignar las variables, de construir la cola de acciones
     * que se van a realizar en el turno, para que se vayan consumiendo posteriormente
     * dichas acciones.
     *
     * @param comb Referencia al combate sobre el que esté este turno.
     */
    ControlTurno(ControlCombate &comb);

    /**
     * Función principal del desarrollo del combate. Este método consume una posición de
     * la cola de acciones, y pide al usuario que acción desea realizar, así como calcula
     * el daño producido, e informa al usuario de ello.
     *
     * @return
     */
    Uint32 iteracionTurno();

    /**
     * Método para comprobar si el turno ha terminado.
     *
     * @return Devuelve <code>true</code> si no quedan acciones en el turno, y <code>
     * false</code> en otro caso.
     */
    bool finTurno() const {
      #ifdef DEBUG
      cout << "ControlTurno::finTurno()" << endl;
      #endif
        return _turno.empty();
    }
protected:
    ControlCombate *_comb;
    queue<Combatiente*> _turno;

    void mostrarEstadoActual(const Combatiente &c);

    Uint32 seleccionarAccion();
    void mostrarAcciones();
    void mostrarObjetivos(const Combatiente& c);
    Combatiente* seleccionarObjetivo(const Combatiente& c) throw(Grupo::NoExisteCombatiente);
    void mostrarHabilidades(const Combatiente& c);
    Habilidad* seleccionarHabilidad(const Combatiente& c);
    void mostrarInventario(const Combatiente& c);
    Objeto* seleccionarObjeto(const Combatiente& c);

    void mostrarDamage(const Combatiente &c, const Combatiente &o, Uint32 d);
    void mostrarAtaqueFallado(const Combatiente &c);
    Uint32 intentarHuir(const Combatiente &c);
};

#endif	/* _CONTROLCOMBATE_H */
