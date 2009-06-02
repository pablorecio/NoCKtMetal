/*
 * This program is free software: you can redistribute it
 * and/or modify it under the terms of the GNU General
 * Public License as published by the Free Software
 * Foundation, either version 3 of the License, or any
 * later version.

 * This program is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A
 * PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.

 * You should have received a copy of the GNU General
 * Public License along with this program.  If not, see
 * <http://www.gnu.org/licenses/>.

 * Copyright (C) 2009, NoCKTMetal Team
 *
 * Fichero: evento.h
 * Autor: Noelia Sales Montes
 * Fecha: 21 de abril de 2009
 * Proyecto: NoCKt Metal
 */

#ifndef _EVENTO_H
#define	_EVENTO_H

#include <SDL/SDL.h>
#include <map>

using namespace std;

/**
 * Tipo <i>accion</i>, que representa la acción que se ha sido activada,
 * mediante un evento determinado.
 */
enum accion {
    NULA = 0,
    SALIR,
    MENU,
	ACEPTAR,
    ATRAS,
    ARRIBA,
    ABAJO,
	IZQUIERDA,
	DERECHA
};

/**
 * @brief Clase de gestión de eventos.
 * Abstrae los eventos (generados por el usuario) que dan lugar a determinadas
 * acciones.
 * @author Noelia Sales Montes
 * @date 21 de abril de 2009
 * @note Parte del Proyecto NoCKt Metal
 */
class Evento {
public:
    /**
     * Constructor predeterminado de la clase <code>Evento</code>.
     * @param r Retraso entre recepción de eventos.
     */
    Evento(Uint32 r = 70);
    /**
     * Método actualizador del controlador de eventos.
     * Es utilizado en el metodo observador para poder leer los eventos del
     * instante actual sin detener el movimiento en caso de que se mantuviera
     * presionada una tecla.
     * @todo Intentar buscar la forma de expandir o retrasar el intervalo de
     * tiempo en que el bucle de espera se repite. (Demasiadas veces)
     * @todo Incluir definiciones de teclas alternativas en caso de querer
     * probar con la PSP.
     */
    void actualizar();
    /**
     * Método observador de la acción a realizar.
     * @return Identificador de la acción de tipo <code>accion</code>,
     * definido específicamente para esta clase.
     */
    accion getEvento();
    /**
     * Destructor de la clase <code>Evento</code>.
     */
    virtual ~Evento();
private:
    Uint32 _retraso;
    /**
     * Evento de la librería SDL que esta clase permite abstraer.
     */
    SDL_Event _evento;
    /**
     * Par <i>tecla-accion</i>, que asocia los eventos (teclas 
     * <code>SDLKey</code> que pulsa el usuario) a la acción que
     * activarán, de tipo <code>accion</code>.
     */
    map<SDLKey, accion> _accion;
    /**
     * Par <i>accion-valor lógico</i>, que asocia cada acción con un valor
     * lógico que se activa (<code>true</code>) en caso de que haya sido
     * efectuado el evento que provocará dicha acción.
     */
    map<accion, bool> _activa;
};

#endif	/* _EVENTO_H */
