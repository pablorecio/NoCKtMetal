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
 * Fichero: animacion.h
 * Autor: Noelia Sales Montes
 * Fecha: 19 de abril de 2009
 * Proyecto: NoCKt Metal
 */

#ifndef _ANIMACION_H
#define	_ANIMACION_H

#include "evento.h"
#include "pantalla.h"
#include "personaje.h"
#include "imagen.h"

/**
 * @brief Clase que se encarga de inicializar los datos necesarios para
 * un nivel del juego asi como controlar la gestion de eventos (con ayuda
 * de la clase <code>Evento</code>) y el movimiento general de los elementos
 * dinamicos.
 * @author Noelia Sales Montes
 * @date 19 de abril de 2009
 */
class Animacion {
public:
    /**
     * Constructor predeterminado de <code>Animacion</code>.
     */
    Animacion();
    
    /**
     * Metodo observador de la pantalla en la que se muestra la animacion.
     * Sera la ventana del videojuego logicamente.
     * @return Puntero a <code>Pantalla</code>.
     */
    Pantalla* getPantalla();
    /**
     * Asociacion con la clase <code>Pantalla</code>.
     * @param p Referencia a la pantalla que se desea asociar.
     */
    void animandoEn(Pantalla& p);
    /**
     * Uno de los metodos principales de Animacion.
     * Ejecuta y controla el movimiento en el mapa.
     */
    void animandoMapa();
    /**
     * Destructor de la clase Animacion.
     */
    virtual ~Animacion();
private:

    /**
     * Metodo auxiliar que realiza un movimiento estatico desde el punto
     * de vista del personaje.
     * @param m Identificador de la direccion del movimiento.
     */
    void hacerMovimientoEstatico(Movimiento m);
    /**
     * Metodo auxiliar que realiza un movimiento dinamico desde el punto
     * de vista del personaje.
     * @param m Identificador de la direccion del movimiento.
     */
    void hacerMovimientoDinamico(Movimiento m);
    /**
     * Metodo auxiliar que realiza un movimiento simple del personaje.
     * Sirve de ayuda a <code>hacerMovimientoEstatico</code> y
     * <code>hacerMovimientoDinamico</code> que realizan el movimiento
     * incluyendo el mapa.
     * @param mov Identificador de la direccion del movimiento.
     * @param sec Secuencia actual del movimiento.
     * @param desp Desplazamiento. Por defecto 0.
     */
    void movimiento(Movimiento mov, Uint32 sec, Uint32 desp = 0);
    /**
     * Puntero a la pantalla general del juego.
     */
    Pantalla* _pant;
    /**
     * Puntero al personaje principal del juego.
     */
    Personaje* _principal;
    /**
     * Equivalencia de un tile en pixels: En verdad no hace falta, porque
     * se puede leer directamente de Imagen creo.
     */
    Uint32 _tamCasilla;
    /**
     * Desplazamiento igual a _numSecuencias/_tamCasilla
     */
    Uint32 _desp;
    /**
     * Ancho del mapa.
     */
    Uint32 _anchoMapa;
    /**
     * Alto del mapa.
     */
    Uint32 _altoMapa;
};

/* Metodos inline */
inline Pantalla* Animacion::getPantalla() { return _pantalla; }

#endif	/* _ANIMACION_H */
