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

#ifndef _SPRITE_GENERICO_
#define _SPRITE_GENERICO_

#include <SDL/SDL.h>

/**
 * @brief Clase que abstrae el manejo de los sprites.
 * Con ella conseguiremos abstraer un poco las funciones de la SDL para
 * cargar las páginas de sprites y acceder a cada sprite individual de una
 * forma mas intuitiva.
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
     * Este constructor toma el numero de filas del sprite
     * @param ruta_imagen Cadena con la direccion de la tabla de sprites a cargar
     * @param numFil Numero de filas de la matriz de sprites.
     * @param numCol Numero de columnas de la matriz de sprites.
     * @param numEl Numero de elementos del sprite.
     */
    Sprite(const char *ruta_imagen, Uint32 numFil = 1, Uint32 numCol = 1,
               Uint32 numEl = 1);
    /**
     * @brief Destructor de una instancia de Sprite.
     */
    ~Sprite();

    /**
     * Metodo observador del ancho de un elemento del sprite.
     */
    Uint32 getAncho() const;
    /**
     * Metodo observador del alto de un elemento del sprite.
     */
    Uint32 getAlto() const;
    /**
     * Metodo observador del numero de filas de la matriz del sprite.
     */
    Uint32 getFilas() const;
    /**
     * Metodo observador del numero de columnas de la matriz del sprite.
     */
    Uint32 getColumnas() const;
    /**
     * Metodo observador del numero de elementos del sprite.
     */
    Uint32 getNumSprites() const;

    /**
     * Metodo observador del codigo asociado al movimiento hacia arriba.
     */
    Uint32 getMovArriba() const;
    /**
     * Metodo observador del codigo asociado al movimiento hacia la izquierda.
     */
    Uint32 getMovIzda() const;
    /**
     * Metodo observador del codigo asociado al movimiento hacia la derecha.
     */
    Uint32 getMovDcha() const;
    /**
     * Metodo observador del codigo asociado al movimiento hacia abajo.
     */
    Uint32 getMovAbajo() const;

    /**
     * @brief Función que nos dibuja un sprite determinado de una superficie
     * de la SDL.
     * @param fila Fila donde esta situado el sprite
     * @param columna Columna donde esta situado el sprite
     * @param dest Superficie de destino donde vamos a dibujar el sprite
     * @param x Desplazamiento horizontal en la superficie
     * @param y Desplazamiento vertical en la superficie
     */
    void dibujar(Uint32 fila, Uint32 columna,
                 SDL_Surface* p, Uint32 x, Uint32 y) const;
    /**
     * @brief Función que nos dibuja un sprite determinado de una superficie
     * de la SDL.
     * @param n Numero de sprite de 0 a n-1.
     * @param dest Superficie de destino donde vamos a dibujar el sprite
     * @param x Desplazamiento horizontal en la superficie
     * @param y Desplazamiento vertical en la superficie
     */
    void dibujar(Uint32 i, SDL_Surface* p, Uint32 x, Uint32 y) const;
protected:

    /**
     * Pantalla de la libreria SDL donde se almacena la matriz de sprites.
     */
    SDL_Surface* _imagen;
    /**
     * Ancho de un elemento individual del sprite.
     */
    Uint32 _ancho;
    /**
     * Alto de un elemento individual del sprite.
     */
    Uint32 _alto;
    /**
     * Numero de filas de la matriz del sprite.
     */
    Uint32 _filas;
    /**
     * Numero de columnas de la matriz del sprite.
     */
    Uint32 _columnas;
    /**
     * Numero de sprites en la matriz de movimiento.
     * @note Generalmente suele ser igual a la multiplicacion de filas por
     * columnas, pero se almacena puesto que hay casos en que existen filas
     * incompletas, etc.
     */
    Uint32 _num;    
    /**
     * Correspondencia con el orden de los movimientos (fila que le
     * corresponde a cada secuencia).
     * @note Se supone que para cada movimiento se tienen tantos movimientos
     * en dicha direccion como columnas haya en la matriz.
     */
    Uint32 _mov_abajo, _mov_izda, _mov_dcha, _mov_arriba;
};

/* Metodos inline */
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
