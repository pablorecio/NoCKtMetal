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
 * Fichero: sprite.h
 * Autor: Noelia Sales Montes
 * Fecha: 19 de abril de 2009
 * Proyecto: NoCKt Metal
 */

#ifndef _SPRITE_H
#define _SPRITE_H

#include <SDL/SDL.h>

/**
 * @brief Clase que abstrae el manejo de los <i>sprites</i>.
 * Abstrae la carga y el manejo de estas imágenes, debido a que se comportan
 * de forma un tanto más compleja que una imagen simple.
 * @author Noelia Sales Montes
 * @date 26 de Marzo de 2009
 * @note Parte del Proyecto NoCKt Metal
 */
class Sprite {
public:

    /**
     * @brief Constructor vacio.
     */
    Sprite();
    /**
     * @brief Constructor de un objeto tipo sprite.
     * @param ruta_imagen Cadena con la dirección de la tabla de sprites a
     * cargar.
     * @param numFil Número de filas de la matriz de sprites.
     * @param numCol Número de columnas de la matriz de sprites.
     * @param numEl Número de elementos del sprite.
     */
    Sprite(const char *ruta_imagen, Uint32 numFil = 1, Uint32 numCol = 1,
               Uint32 numEl = 1);
    /**
     * @brief Destructor de una instancia de Sprite.
     */
    ~Sprite();

    /**
     * Método observador del ancho de <b>un</b> elemento del sprite.
     */
    Uint32 getAncho() const;
    /**
     * Método observador de la altura de <b>un</b> elemento del sprite.
     */
    Uint32 getAlto() const;
    /**
     * Método observador del número de filas de la matriz del sprite.
     */
    Uint32 getFilas() const;
    /**
     * Método observador del número de columnas de la matriz del sprite.
     */
    Uint32 getColumnas() const;
    /**
     * Método observador del número de elementos del sprite.
     */
    Uint32 getNumSprites() const;

    /**
     * Método observador del código asociado al movimiento hacia arriba.
     */
    Uint32 getMovArriba() const;
    /**
     * Método observador del código asociado al movimiento hacia la izquierda.
     */
    Uint32 getMovIzda() const;
    /**
     * Método observador del código asociado al movimiento hacia la derecha.
     */
    Uint32 getMovDcha() const;
    /**
     * Método observador del código asociado al movimiento hacia abajo.
     */
    Uint32 getMovAbajo() const;

    /**
     * @brief Función que dibuja un sprite determinado de una superficie de
     * la SDL.
     * @param fila Fila donde esta situado el sprite.
     * @param columna Columna donde esta situado el sprite.
     * @param dest Superficie donde se dibujará el sprite.
     * @param x Desplazamiento horizontal en la superficie.
     * @param y Desplazamiento vertical en la superficie.
     */
    void dibujar(Uint32 fila, Uint32 columna,
                 SDL_Surface* p, Uint32 x, Uint32 y) const;
    /**
     * @brief Función que dibuja un sprite determinado de una superficie
     * de la SDL.
     * @param n Número de sprite de 0 a n-1.
     * @param dest Superficie donde se dibujará el sprite.
     * @param x Desplazamiento horizontal en la superficie.
     * @param y Desplazamiento vertical en la superficie.
     * @note Es completamente análoga a la anterior, salvo en la identificación
     * del sprite a dibujar.
     */
    void dibujar(Uint32 i, SDL_Surface* p, Uint32 x, Uint32 y) const;
protected:

    /**
     * Superficie de la librería SDL donde se almacena la matriz de sprites.
     */
    SDL_Surface* _imagen;
    /**
     * Ancho de un elemento individual del sprite.
     */
    Uint32 _ancho;
    /**
     * Altura de un elemento individual del sprite.
     */
    Uint32 _alto;
    /**
     * Número de filas de la matriz del sprite.
     */
    Uint32 _filas;
    /**
     * Número de columnas de la matriz del sprite.
     */
    Uint32 _columnas;
    /**
     * Número de sprites en la matriz de movimiento.
     * @note Generalmente suele ser igual a la multiplicación de filas por
     * columnas, pero se almacena puesto que hay casos en que existen filas
     * incompletas, etc.
     */
    Uint32 _num;    
    /**
     * Correspondencia con el orden del movimiento hacia abajo (índice de la 
     * fila que se corresponde con la secuncia de éste movimiento).
     * @note Se supone que para cada movimiento se tienen tantos
     * movimientos en dicha dirección como columnas haya en la matriz.
     */
    Uint32 _mov_abajo;    
    /**
     * Correspondencia con el orden del movimiento hacia la izquierda (índice
     * de la fila que se corresponde con la secuncia de éste movimiento).
     * @note Se supone que para cada movimiento se tienen tantos
     * movimientos en dicha dirección como columnas haya en la matriz.
     */
    Uint32 _mov_izda;    
    /**
     * Correspondencia con el orden del movimiento hacia la derecha (índice
     * de la fila que se corresponde con la secuncia de éste movimiento).
     * @note Se supone que para cada movimiento se tienen tantos
     * movimientos en dicha dirección como columnas haya en la matriz.
     */
    Uint32 _mov_dcha;    
    /**
     * Correspondencia con el orden del movimiento hacia arriba (índice de la
     * fila que se corresponde con la secuncia de éste movimiento).
     * @note Se supone que para cada movimiento se tienen tantos
     * movimientos en dicha dirección como columnas haya en la matriz.
     */
    Uint32 _mov_arriba;
};

/* Métodos inline */
inline Uint32 Sprite::getAncho() const { return _ancho; }
inline Uint32 Sprite::getAlto() const { return _alto; }
inline Uint32 Sprite::getFilas() const { return _filas; }
inline Uint32 Sprite::getColumnas() const { return _columnas; }
inline Uint32 Sprite::getNumSprites() const { return _num; }
inline Uint32 Sprite::getMovAbajo() const { return _mov_abajo; }
inline Uint32 Sprite::getMovIzda() const { return _mov_izda; }
inline Uint32 Sprite::getMovDcha() const { return _mov_dcha; }
inline Uint32 Sprite::getMovArriba() const { return _mov_arriba; }

#endif
