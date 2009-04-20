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
 * Fichero = sprite.h
 * Autor = Pablo Recio Quijano
 * Fecha = 26 / 03 / 2009
 * 
 * - Definición de la clase Sprite.
 *
 * La clase Sprite se encargara de cargar una imagen conteniendo
 * una serie de sprites y gestionar el acceso a cada sprite individual, 
 * así como el dibujarlo sobre una SDL_Surface y demás.
 */

#ifndef _SPRITE_GENERICO_
#define _SPRITE_GENERICO_

#include <SDL/SDL.h>

/**
 * @brief Clase que modela un tratamiento generico de los sprites.
 *
 * Con ella conseguiremos abstraer un poco las funciones de la SDL para
 * cargar las páginas de sprites y acceder a cada sprite individual de una
 * forma mas intuitiva.
 *
 * La idea sera hacer un uso similar al siguiente:
 * <code>sprite s1("./imagenes/baldomero.png",4,4);</code>
 * Por ejemplo, consideramos que la matriz de sprites tiene 4 filas 
 * y 4 columnas.
 *
 * @author Pablo Recio Quijano
 *
 * @date 26 de Marzo de 2009
 */
class Sprite {
public:

    /**
     * @brief Constructor vacio.
     * Este constructor no hace nada, y además no se puede cargar
     * la imagen posteriormente. Aunque no la usemos hace falta para las
     * cargas de vectores y demás.
     */
    Sprite();

    /**
     * @brief Constructor de un objeto tipo sprite.
     * Este constructor toma el numero de filas del sprite
     * @param ruta_imagen Cadena con la direccion de la tabla de sprites a cargar
     * @param num_f Numero de filas de la tabla de sprites. Por defecto a 1
     * @param num_c Numero de columnas de la tabla de sprites. Por defecto a 1
     * @param num_s Numero fijo de sprites. Por defecto a 1
     */
    Sprite(const char *ruta_imagen, Uint32 num_f = 1, Uint32 num_c = 1,
           Uint32 num_s = 1, Uint32 abajo = 0, Uint32 izda = 1,
           Uint32 dcha = 2, Uint32 arriba = 3);

    /**
     * @brief Constructor de copia.
     * @param otro Objeto sprite que queremos copiar
     */
    Sprite(const Sprite& otro);

    /**
     * @brief Destructor del objeto.
     */
    ~Sprite();

    //------- Consultoras ---------

    Uint32 getAncho() const;
    Uint32 getAlto() const;

    Uint32 getFilas() const;
    Uint32 getColumnas() const;

    Uint32 getNumSprites() const;

    Uint32 getMovArriba() const;
    Uint32 getMovIzda() const;
    Uint32 getMovDcha() const;
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
                 SDL_Surface* dest, Uint32 x, Uint32 y) const;

    /**
     * @brief Función que nos dibuja un sprite determinado de una superficie
     * de la SDL.
     * @param n Numero de sprite de 0 a n-1.
     * @param dest Superficie de destino donde vamos a dibujar el sprite
     * @param x Desplazamiento horizontal en la superficie
     * @param y Desplazamiento vertical en la superficie
     */
    void dibujar(Uint32 i, SDL_Surface* dest, Uint32 x, Uint32 y) const;

protected:

    /**
     * Superficie SDL donde almacenamos la matriz de sprites
     */
    SDL_Surface* _imagen;

    /**
     * Ancho imagen individual.
     */
    Uint32 _ancho;
    /**
     * Alto imagen individual.
     */
    Uint32 _alto;

    /**
     * Filas de la matriz de movimiento del sprite
     */
    Uint32 _filas;
    /**
     * Columnas de la matriz de movimiento del sprite
     */
    Uint32 _cols;

    /**
     * Numero de sprites en la matriz de movimiento.
     * Generalmente suele ser igual a la multiplicacion de filas por
     * columnas, pero se almacena puesto que hay casos en que existen filas
     * incompletas, etc.
     */
    Uint32 _num;
    
    /**
     * Correspondencia con el orden de los movimientos (fila que le
     * corresponde a cada secuencia).
     * Se supone que para cada movimiento se tienen tantos movimientos
     * en dicha direccion como columnas haya en la matriz.
     */
    Uint32 _mov_abajo, _mov_izda, _mov_dcha, _mov_arriba;
};

inline Uint32 Sprite::getAncho() const { return _ancho; }
inline Uint32 Sprite::getAlto() const { return _alto; }
inline Uint32 Sprite::getFilas() const { return _filas; }
inline Uint32 Sprite::getColumnas() const { return _cols; }
inline Uint32 Sprite::getNumSprites() const { return _num; }
inline Uint32 Sprite::getMovAbajo() const { return _mov_abajo; }
inline Uint32 Sprite::getMovIzda() const { return _mov_izda; }
inline Uint32 Sprite::getMovDcha() const { return _mov_dcha; }
inline Uint32 Sprite::getMovArriba() const { return _mov_arriba; }

#endif
