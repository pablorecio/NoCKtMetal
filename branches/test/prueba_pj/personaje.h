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
 * Fichero: personaje.h
 * Autor: Noelia Sales Montes
 * Fecha: 14 04 2009
 * Proyecto: NoCKt Metal
 */

#ifndef _PERSONAJE_
#define _PERSONAJE_

#include "pantalla.h"
#include "sprite.h"

/**
 * @brief La clase Personaje hace de intermediario entre 
 * la clase Sprite y la clase Animacion.
 * @author Noelia Sales Montes
 * @date 14 04 2009
 * @see Sprite.h Animacion.h
 */
class Personaje {
public:

    /**
     * @brief Constructor vacio.
     * Este constructor no hace nada, y además no da lugar a un personaje
     * utilizable posteriormente. Es necesaria para poder definir vectores
     * y otros elementos.
     */
    Personaje();
    /**
     * @brief Constructor de un objeto Personaje
     * Este constructor crea un personaje en una posicion determinada
     * (casilla en un mapa, nada de pixels)
     * @param i Identificador del personaje
     * @param x Posicion horizontal
     * @param y Posicion vertical
     */
    Personaje(Uint32 i, Uint32 x = 0, Uint32 y = 0, Uint32 tam = 32);
    Personaje(Uint32 i, const char* sprite, Uint32 x, Uint32 y, Uint32 tam = 32);
    /**
     * @brief Destructor de Personaje
     * Destruye un objeto Personaje
     */
    ~Personaje();
    /**
     * @brief Consultor de identificador de personaje
     * @return Valor del identificador del personaje
     */
    Uint32 getId() const;
    /**
     * @brief Consultor de la posicion horizontal del personaje
     * @return Indice x de la casilla en que se encuentra el personaje
     */
    Uint32 getX() const;
    /**
     * @brief Consultor de la posicion vertical del personaje
     * @return Indice y de la casilla en que se encuentra el personaje
     */
    Uint32 getY() const;
    /**
     * @brief Consultor de si la posicion dada se sale del rango de movimiento
     * @param x Posición horizontal
     * @param y Posición vertical
     * @return <code>True</code> en caso de que la posición esté fuera de rango,
     * y <code>false</code> en caso contrario.
     * En caso de que el rango no este definido se entiende que no es esta fuera
     * del rango.
     */
    bool fueraRango(Uint32 x, Uint32 y) const;
    /**
     * @brief Asociacion con Animacion
     * Se asocia el objeto Personaje actual con un objeto Animacion
     */
    void animadoEn(Pantalla& p);
    void dibujadoPor(Sprite& s);
    /**
     * @brief Modificador de la posicion
     * @param x Posicion horizontal
     * @param y Posicion vertical
     */
    void setPosicion(Uint32 x, Uint32 y);
    /**
     * @brief Colocar el personaje en la posicion central dentro de su rango
     * de movimiento
     */
    void setPosicion();
    void setRango(Uint32 margenIzdo, Uint32 margenArriba, Uint32 rangoAncho,
                  Uint32 rangoAlto);
    void dibujarPosicionFrente();
    void dibujarPosicionEspaldas();
    void dibujarPosicionLatIzda();
    void dibujarPosicionLatDcha();
    /**
     * @brief Desplazamiento del personaje una posicion hacia arriba
     */
    void moverArriba();
    /**
     * Sobrecarga de moverArriba que movera el personaje a pequeños pasos
     * @param mov Movimiento a realizar
     * @param desp Desplazamiento
     * @return Entero que indica el movimiento que "toca" hacer a continuación
     * (en funcion del lugar de dicho movimiento en la secuencia total)
     */
    Uint32 moverArriba(Uint32 mov, Uint32 desp);
    /**
     * @brief Desplazamiento del personaje una posicion hacia abajo
     */
    void moverAbajo();
    Uint32 moverAbajo(Uint32 mov, Uint32 desp);
    /**
     * @brief Desplazamiento del personaje una posicion hacia izquierda
     */
    void moverIzda();
    Uint32 moverIzda(Uint32 mov, Uint32 desp);
    /**
     * @brief Desplazamiento del personaje una posicion hacia derecha
     */
    void moverDcha();
    Uint32 moverDcha(Uint32 mov, Uint32 desp);
protected:
    void mover(Uint32 movimiento);
    bool existeRango() const;
    /**
     * Identificador del personaje
     */
    Uint32 _id;
    /**
     * Coordenadas de la casilla en que se encuentra el personaje
     * */
    Uint32 _x, _y;
    Uint32 _tamCasilla;
    /** Rango de casillas en pantalla en las que se puede mover
     * el personaje: Movimiento restringido
     */
    Uint32 _rango_pX, _rango_pY, _rango_dX, _rango_dY;
    bool _existeRango;
    /**
     * Puntero a un objeto Pantalla
     */
    Pantalla* _p;
    /**
     * Composicion de sprite
     */
    Sprite* _sprite;
};

/* Funciones get inline: eficiencia */
inline Uint32 Personaje::getId() const { return _id; }
inline Uint32 Personaje::getX() const { return _x; }
inline Uint32 Personaje::getY() const { return _y; }
inline bool Personaje::fueraRango(Uint32 x, Uint32 y) const {
    return (existeRango() && (x < _rango_pX || x > _rango_pX + _rango_dX ||
                              y < _rango_pY || y > _rango_pY + _rango_dY));
}
inline bool Personaje::existeRango() const { return _existeRango; }

#endif
