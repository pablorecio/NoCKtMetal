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
 * @brief La clase <code>Personaje</code> hace de intermediario entre la clase
 * <code>Sprite</code> y la clase <code>Animacion</code>. Ademas controla el
 * movimiento restringido del personaje en el mapa.
 * @author Noelia Sales Montes
 * @date 14 04 2009
 * @see sprite.h animacion.h
 */
class Personaje {
public:

    /**
     * Constructor vacio.
     * Este constructor no hace nada, y además no da lugar a un personaje
     * utilizable posteriormente. Es necesaria para poder definir vectores
     * y otros elementos.
     */
    Personaje();
    /**
     * Constructor de un objeto <i>Personaje</i>.
     * Este constructor crea un personaje en una posicion determinada
     * (casilla en un mapa, nada de pixels)
     * @param i Identificador del personaje.
     * @param x Posicion horizontal.
     * @param y Posicion vertical.
     */
    Personaje(Uint32 i, Uint32 x = 0, Uint32 y = 0);
    /**
     * Constructor de un objeto <i>Personaje</i>.
     * Este constructor crea un personaje en una posicion determinada
     * (casilla en un mapa, nada de pixels) y asociado a un sprite.
     * @param i Identificador del personaje.
     * @param sprite Cadena de bajo nivel que representa la ruta donde se
     * encuentra la imagen del sprite a crear y relacionar con el Personaje.
     * @param x Posicion horizontal.
     * @param y Posicion vertical.
     */
    Personaje(Uint32 i, const char* sprite, Uint32 x, Uint32 y);

    /**
     * Destructor de Personaje
     * Destruye un objeto Personaje
     */
    ~Personaje();

    /**
     * Metodo observador de identificador de personaje.
     * @return Valor del identificador del personaje.
     */
    Uint32 getId() const;
    /**
     * Metodo observador de la posicion horizontal del personaje en la pantalla.
     * @return Posicion horizontal en que se encuentra el personaje en la
     * pantalla.
     */
    Uint32 getX() const;
    /**
     * Metodo observador de la posicion vertical del personaje en la pantalla.
     * @return Posicion vertical en que se encuentra el personaje en la
     * pantalla.
     */
    Uint32 getY() const;
    /**
     * Metodo observador de la posicion horizontal del personaje en la pantalla.
     * @return Indice x de la casilla del mapa en que se encuentra el personaje.
     */
    Uint32 getMapaX() const;
    /**
     * Metodo observador de la posicion vertical del personaje en la pantalla.
     * @return Indice y de la casilla del mapa en que se encuentra el personaje.
     */
    Uint32 getMapaY() const;
    /**
     * Metodo observador que consulta si la posicion dada se sale del rango
     * de movimiento.
     * @param x Posición horizontal en pixels.
     * @param y Posición vertical en pixels.
     * @return <code>True</code> en caso de que la posición esté fuera de rango,
     * y <code>false</code> en caso contrario.
     * @note En caso de que el rango no este definido se entiende que no es
     * esta fuera del rango.
     */
    bool fueraRango(Uint32 x, Uint32 y) const;
    /**
     * Metodo observador del numero de movimientos que tiene cada secuencia
     * para el sprite relacionado con el personaje.
     * @return Entero que se corresponde con el numero de movimientos.
     */
    Uint32 getSecuenciasMovimiento() const;
    /**
     * Metodo observador del rango de movimiento del personaje en la pantalla.
     * @return Puntero a <code>SDL_Rect</code>.
     */
    SDL_Rect* getRango() const;

    /**
     * Asociacion con la clase <code>Pantalla</code>.
     * Se asocia el personaje actual con la pantalla principal de nuestro
     * juego. Dentro de ella, nuestro personaje se dibujara sobre la
     * pantalla secundaria dedicada al movimiento.
     * @param p Referencia a la pantalla.
     * @see Pantalla
     */
    void animadoEn(Pantalla& p);
    /**
     * Asociacion con la clase <code>Sprite</code>.
     * Se asocia el personaje actual con el sprite que lo representa
     * graficamente.
     * @param s Referencia al sprite.
     * @see Sprite
     */
    void dibujadoPor(Sprite& s);

    /**
     * Metodo modificador de la posicion en pantalla (en <i>pixels</i>).
     * @param x Posicion horizontal.
     * @param y Posicion vertical.
     */
    void setPosicion(Uint32 x, Uint32 y);
    /**
     * Metodo modificador de la posicion en pantalla (en <i>pixels</i>) que
     * coloca el personaje en la posicion central dentro de su rango de
     * movimiento.
     */
    void setPosicion();
    /**
     * Metodo modificador del rango de movimiento del personaje.
     * @param margenIzdo Margen izquierdo del rango.
     * @param margenArriba Margen superior del rango.
     * @param rangoAncho Ancho del rango.
     * @param rangoAlto Alto del rango.
     */
    void setRango(Uint16 margenIzdo, Uint16 margenArriba, Uint16 rangoAncho,
                  Uint16 rangoAlto);
    /**
     * Metodo modificador de la posicion en el mapa.
     * @param mapaX Posicion horizontal de la casilla en el mapa.
     * @param mapaY Posicion vertical de la casilla en el mapa.
     */
    void actualizarMapa(Uint32 mapaX, Uint32 mapaY);

    /**
     * Metodo modificador que dibuja en la pantalla de movimiento el personaje
     * en la posicion actual de frente.
     */
    void dibujarPosicionFrente();
    /**
     * Metodo modificador que dibuja en la pantalla de movimiento el personaje
     * en la posicion actual de espaldas.
     */
    void dibujarPosicionEspaldas();
    /**
     * Metodo modificador que dibuja en la pantalla de movimiento el personaje
     * en la posicion actual mirando hacia la izquierda.
     */
    void dibujarPosicionLatIzda();
    /**
     * Metodo modificador que dibuja en la pantalla de movimiento el personaje
     * en la posicion actual mirando hacia la derecha.
     */
    void dibujarPosicionLatDcha();
    
    /**
     * Metodo modificador que dibuja en la pantalla de movimiento un movimiento
     * simple dentro de la secuencia hacia arriba.
     * @param mov Identificado del movimiento a realizar dentro de la secuencia.
     * @param desp Desplazamiento, por defecto 0.
     */
    void moverArriba(Uint32 mov, Uint32 desp = 0);
    /**
     * Metodo modificador que dibuja en la pantalla de movimiento un movimiento
     * simple dentro de la secuencia hacia abajo.
     * @param mov Identificado del movimiento a realizar dentro de la secuencia.
     * @param desp Desplazamiento, por defecto 0.
     */
    void moverAbajo(Uint32 mov, Uint32 desp = 0);
    /**
     * Metodo modificador que dibuja en la pantalla de movimiento un movimiento
     * simple dentro de la secuencia hacia izquierda.
     * @param mov Identificado del movimiento a realizar dentro de la secuencia.
     * @param desp Desplazamiento, por defecto 0.
     */
    void moverIzda(Uint32 mov, Uint32 desp = 0);
    /**
     * Metodo modificador que dibuja en la pantalla de movimiento un movimiento
     * simple dentro de la secuencia hacia derecha.
     * @param mov Identificado del movimiento a realizar dentro de la secuencia.
     * @param desp Desplazamiento, por defecto 0.
     */
    void moverDcha(Uint32 mov, Uint32 desp = 0);
protected:

    /**
     * Metodo auxiliar que dibuja en la pantalla de movimiento especifico
     * que se reciba.
     * @param movimiento ARRIBA, ABAJO, IZQUIERDA o DERECHA en funcion
     * de los valores del sprite.
     * @param secuencia Movimiento de la secuencia.
     */
    void mover(Uint32 movimiento, Uint32 secuencia);
    /**
     * Metodo auxiliar que consulta si se ha definido un rango para este
     * personaje.
     * @return <code>True</code> si esta definido el rango, <code>false</code>
     * en caso contrario.
     */
    bool existeRango() const;
    /**
     * Identificador del personaje.
     */
    Uint32 _id;
    /**
     * Indice horizontal de la casilla en que se encuentra el personaje en
     * el mapa.
     */
    Uint32 _mapaX;
    /**
     * Indice vertical de la casilla en que se encuentra el personaje en
     * el mapa.
     */
    Uint32 _mapaY;
    /**
     * Coordenada horizontal en pixels en la pantalla.
     */
    Uint32 _x;
    /**
     * Coordenada vertical en pixels en la pantalla.
     */
    Uint32 _y;
    /**
     * Rango rectangular en pantalla en el que se puede mover el personaje.
     */
    SDL_Rect _rango;
    /**
     * Booleano que indica la definicion del rango restrictivo de movimiento.
     */
    bool _existeRango;
    /**
     * Puntero a un objeto <code>Pantalla</code>.
     */
    Pantalla* _p;
    /**
     * Puntero a un objet <code>Sprite</code>.
     */
    Sprite* _sprite;
};

/* Metodos inline */
inline Uint32 Personaje::getId() const { return _id; }
inline Uint32 Personaje::getX() const { return _x; }
inline Uint32 Personaje::getY() const { return _y; }
inline Uint32 Personaje::getMapaX() const { return _x; }
inline Uint32 Personaje::getMapaY() const { return _y; }
inline SDL_Rect* getRango() const { return _rango; }
inline bool Personaje::fueraRango(Uint32 x, Uint32 y) const {
    return (existeRango() && (x < _rango.x || x > _rango.x + _rango.w ||
            y < _rango.y || y > _rango.y + _rango.h));
}
inline bool Personaje::existeRango() const { return _existeRango; }
inline bool Personaje::getSecuenciasMovimiento() const {
    return _sprite->getColumnas();
}

#endif
