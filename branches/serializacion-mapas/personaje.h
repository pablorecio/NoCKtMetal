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

#include <SDL/SDL.h>
#include <vector>
#include "pantalla.h"
#include "sprite.h"

using namespace std;

/**
 * @brief La clase <code>Personaje</code> hace de intermediario entre la
 * clase <code>Sprite</code> y las demás clases por encima a nivel de
 * abstracción (como la clase <code>Animacion</code>).
 * Su comportamiento principal y más importante es el control del
 * movimiento restringido del personaje en el mapa.
 * @author Noelia Sales Montes
 * @date 14 04 2009
 * @note Parte del Proyecto NoCKt Metal
 * @see sprite.h animacion.h
 */
class Personaje {
public:

    /**
     * Constructor vacío de la clase <code>Personaje</code>.
     * @note Este constructor no hace nada: no crea un personaje utilizable
     * posteriormente. Es necesaria para poder definir vectores y otros 
     * elementos similares.
     */
    Personaje();
    /**
     * Constructor de un objeto <i>Personaje</i>.
     * Este constructor crea un personaje en una posición determinada
     * (casilla en la pantalla, nada de pixels) junto con su <i>sprite</i>
     * asociado.
     * @note Este constructor no va a ser utilizado de momento, puesto que
     * no podemos asegurar que el ancho del sprite sea igual al de un tile.
     * @param i Identificador del personaje.
     * @param x Posición horizontal.
     * @param y Posición vertical.
     * @param p Puntero a la pantalla en que se dibujará el personaje.
     * @param sprite Cadena de bajo nivel que representa la ruta donde se
     * encuentra la imagen del sprite a crear dentro del personaje.
     * @param f Número de filas del sprite, cuyo valor por defecto es 4.
     * @param c Número de columnas del sprite, cuyo valor por defecto es 4.
     */
    Personaje(Uint32 i, Uint32 x, Uint32 y, Pantalla* p, const char* sprite,
                     Uint32 f = 4, Uint32 c = 4);
    /**
     * Constructor de un objeto <i>Personaje</i>.
     * Este constructor crea un personaje en una posición determinada
     * (casilla en la pantalla, nada de pixels) junto con su <i>sprite</i> asociado.
     * @param i Identificador del personaje.
     * @param x Posición horizontal.
     * @param y Posición vertical.
     * @param tam Tamaño de las casillas en las que "viaja" nuestro personaje.
     * @param p Puntero a la pantalla en que se dibujará el personaje.
     * @param sprite Cadena de bajo nivel que representa la ruta donde se
     * encuentra la imagen del sprite a crear dentro del personaje.
     * @param f Número de filas del sprite, cuyo valor por defecto es 4.
     * @param c Número de columnas del sprite, cuyo valor por defecto es 4.
     */                     
    Personaje(Uint32 i, Uint32 x, Uint32 y, Uint32 tam, Pantalla* p,
              const char* sprite, Uint32 f = 4, Uint32 c = 4);
    /**
     * Constructor de un objeto <i>Personaje</i>.
     * Este constructor crea un personaje en una posición determinada
     * (casilla en un mapa, nada de pixels) junto con su <i>sprite</i> asociado.
     * @param i Identificador del personaje.
     * @param x Posición horizontal en la pantalla.
     * @param y Posición vertical en la pantalla.
     * @param mapax Posición horizontal en el mapa.
     * @param mapay Posición vertical en el mapa.
     * @param tam Tamaño de las casillas en las que "viaja" nuestro personaje.
     * @param p Puntero a la pantalla en que se dibujará el personaje.
     * @param sprite Cadena de bajo nivel que representa la ruta donde se
     * encuentra la imagen del sprite a crear dentro del personaje.
     * @param f Número de filas del sprite, cuyo valor por defecto es 4.
     * @param c Número de columnas del sprite, cuyo valor por defecto es 4.
     */                     
    Personaje(Uint32 i, Uint32 x, Uint32 y, Uint32 mapax, Uint32 mapay,
              Uint32 tam, Pantalla* p, const char* sprite, Uint32 f = 4,
              Uint32 c = 4);

    /**
     * Destructor de la clase Personaje.
     */
    ~Personaje();

    /**
     * Método observador del identificador de personaje.
     * @return Valor del identificador del personaje.
     */
    Uint32 getId() const;
    /**
     * Método observador de la posición horizontal del personaje en la pantalla
     * medida en pixels.
     * @return Posición horizontal del personaje en la pantalla.
     */
    Uint32 getX() const;
    /**
     * Método observador de la posición vertical del personaje en la pantalla.
     * @return Posición vertical del personaje en la pantalla.
     */
    Uint32 getY() const;
    /**
     * Método observador de la posición horizontal del personaje en el mapa.
     * @return Índice x de la casilla del mapa en que se encuentra el personaje.
     */
    Uint32 getMapaX() const;
    /**
     * Método observador de la posición vertical del personaje en el mapa.
     * @return Índice y de la casilla del mapa en que se encuentra el personaje.
     */
    Uint32 getMapaY() const;
    /**
     * Método observador de la posición horizontal del personaje en la pantalla.
     * @return Índice x de la casilla de la pantalla en que se encuentra el 
     * personaje.
     */
    Uint32 getPantX() const;
    /**
     * Método observador de la posición vertical del personaje en la pantalla.
     * @return Índice y de la casilla de la pantalla en que se encuentra el 
     * personaje.
     */
    Uint32 getPantY() const;
    /**
     * Método observador del desplazamiento a realizar en la secuencia <i>i</i>
     * de un movimiento cualquiera.
     * @param i Entero que representa la secuencia de la cual se desea averiguar
     * el desplazamiento.
     * @return Entero que se corresponde con el desplazamiento en pixels.
     */
    Uint32 getDesp(Uint32 i) const;
    /**
     * Método observador que consulta si la posición dada se sale del rango
     * de movimiento.
     * @param x Posición horizontal en casillas.
     * @param y Posición vertical en casillas.
     * @return <code>True</code> en caso de que la posición esté fuera de 
     * rango, y <code>false</code> en caso contrario.
     */
    bool fueraRango(Uint32 x, Uint32 y) const;
    /**
     * Método observador del número de movimientos dentro de la secuencia
     * que tiene cada secuencia de desplazamiento para el sprite relacionado
     * con el personaje.
     * @return Entero que se corresponde con el numero de movimientos.
     */
    Uint32 getSecuenciasMovimiento() const;
    /**
     * Método observador del rango de movimiento del personaje en la pantalla.
     * @return Referencia constante a <code>SDL_Rect</code>.
     */
    const SDL_Rect& getRango() const;
    /**
     * Método observador de la velocidad del personaje en la pantalla.
     * @return Entero que se corresponde con la velocidad en un rango de 0 a
     * 150.
     */
    Uint32 getVelocidad() const;

    /**
     * Método modificador de la posición en pantalla (en <i>casillas</i>).
     * @param x Posición horizontal.
     * @param y Posición vertical.
     */
    void setPosicion(Uint32 x, Uint32 y);
    /**
     * Método modificador de la posición en pantalla que coloca el personaje
     * en la posición central dentro de su rango de movimiento.
     */
    void setPosicion();
    /**
     * Método modificador del rango de movimiento del personaje.
     * @param margenIzdo Margen izquierdo del rango
     * @param margenArriba Margen superior del rango.
     * @param rangoAncho Ancho del rango.
     * @param rangoAlto Alto del rango.
     * @note Todos los rangos será medidos en casillas.
     */
    void setRango(Uint16 margenIzdo, Uint16 margenArriba, Uint16 rangoAncho,
                  Uint16 rangoAlto);
    /**
     * Método modificador del rango de movimiento del personaje, que 
     * generará un nuevo rango central del tamaño dado.
     * @param margenIzdo Ancho del rango en casillas.
     * @param margenArriba Alto del rango en casillas.
     */
    void setRango(Uint16 rangoAncho = 0, Uint16 rangoAlto = 0);
    /**
     * Método modificador de la posición del personaje en el mapa.
     * @note En principio, no es útil. Deben emplearse los métodos
     * <code>subirEnMapa()</code>, <code>bajarEnMapa()</code>,
     * <code>izdaEnMapa()</code>, <code>dchaEnMapa()</code>,
     * @param x Coordenada horizontal de la casilla del mapa
     * @param y Coordenada vertical de la casilla del mapa.
     */
    void setMapa(Uint16 x, Uint16 y);
    /**
     * Método modificador de la velocidad del personaje en la pantalla.
     * @param v Entero que se corresponde con la velocidad en un rango de 0 a
     * 150.
     */
    void setVelocidad(Uint16 v);

    /**
     * Método modificador de la posición en el mapa.
     * Se desplaza una casilla hacia arriba.
     */
    void subirEnMapa();
    /**
     * Método modificador de la posición en el mapa.
     * Se desplaza una casilla hacia abajo.
     */
    void bajarEnMapa();
    /**
     * Método modificador de la posición en el mapa.
     * Se desplaza una casilla hacia la izquierda.
     */
    void izdaEnMapa();
    /**
     * Método modificador de la posición en el mapa.
     * Se desplaza una casilla hacia la derecha.
     */
    void dchaEnMapa();

    /**
     * Método modificador de la posición en la pantalla.
     * Se desplaza una casilla hacia arriba.
     */
    void subirEnPantalla();
    /**
     * Método modificador de la posición en la pantalla.
     * Se desplaza una casilla hacia abajo.
     */
    void bajarEnPantalla();
    /**
     * Método modificador de la posición en la pantalla.
     * Se desplaza una casilla hacia la izquierda.
     */
    void izdaEnPantalla();
    /**
     * Método modificador de la posición en la pantalla.
     * Se desplaza una casilla hacia la derecha.
     */
    void dchaEnPantalla();

    /**
     * Método modificador que dibuja en la pantalla de buffer el personaje en
     * la posición actual de frente.
     */
    void dibujarPosicionFrente();
    /**
     * Método modificador que dibuja en la pantalla de buffer el personaje en
     * la posición actual de espaldas.
     */
    void dibujarPosicionEspaldas();
    /**
     * Método modificador que dibuja en la pantalla de buffer el personaje en
     * la posición actual mirando hacia la izquierda.
     */
    void dibujarPosicionLatIzda();
    /**
     * Método modificador que dibuja en la pantalla de buffer el personaje en
     * la posición actual mirando hacia la derecha.
     */
    void dibujarPosicionLatDcha();
    
    /**
     * Método modificador que dibuja en la pantalla de buffer un movimiento
     * simple dentro de la secuencia hacia arriba.
     * @param mov Identificador del movimiento a realizar dentro de la
     * secuencia.
     * @param desp Desplazamiento, por defecto 0.
     */
    void moverArriba(Uint32 mov, Uint32 desp = 0);
    /**
     * Método modificador que dibuja en la pantalla de buffer un movimiento
     * simple dentro de la secuencia hacia abajo.
     * @param mov Identificador del movimiento a realizar dentro de la
     * secuencia.
     * @param desp Desplazamiento, por defecto 0.
     */
    void moverAbajo(Uint32 mov, Uint32 desp = 0);
    /**
     * Método modificador que dibuja en la pantalla de buffer un movimiento
     * simple dentro de la secuencia hacia la izquierda.
     * @param mov Identificador del movimiento a realizar dentro de la
     * secuencia.
     * @param desp Desplazamiento, por defecto 0.
     */
    void moverIzda(Uint32 mov, Uint32 desp = 0);
    /**
     * Método modificador que dibuja en la pantalla de buffer un movimiento
     * simple dentro de la secuencia hacia la derecha.
     * @param mov Identificador del movimiento a realizar dentro de la
     * secuencia.
     * @param desp Desplazamiento, por defecto 0.
     */
    void moverDcha(Uint32 mov, Uint32 desp = 0);
protected:

    /**
     * Método auxiliar que dibuja en la pantalla de movimiento específico
     * que se reciba.
     * @param movimiento ARRIBA, ABAJO, IZQUIERDA o DERECHA en
     * función de los valores del sprite.
     * @param secuencia Movimiento de la secuencia.
     */
    void mover(Uint32 movimiento, Uint32 secuencia);
    /**
     * Identificador del personaje.
     */
    Uint32 _id;
    /**
     * Índice horizontal de la casilla en que se encuentra el personaje en
     * el mapa.
     */
    Uint32 _mapaX;
    /**
     * Índice vertical de la casilla en que se encuentra el personaje en
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
     * Índice horizontal de la casilla en que se encuentra el personaje en
     * la pantalla.
     */
    Uint32 _pantX;
    /**
     * Índice vertical de la casilla en que se encuentra el personaje en
     * la pantalla.
     */
    Uint32 _pantY;
    /** 
     * Correspondencia pixels-casilla
     */
    Uint32 _tam;
    /**
     * Velocidad del personaje al desplazarse.
     */
    Uint32 _velocidad;
    /**
     * Vector auxiliar empleado para calcular el desplazamiento a realizar
     * por el personaje en cada secuencia de un movimiento completo.
     */
    vector<Uint32> _desp;
    /**
     * Rango rectangular en pantalla en el que se puede mover el personaje.
     */
    SDL_Rect _rango;
    /**
     * Puntero a la ventana principal del videojuego.
     */
    Pantalla* _p;
    /**
     * Objeto <code>Sprite</code> contenido en nuestro Personaje.
     * No tiene sentido su existencia individual en nuestro motor.
     */
    Sprite _sprite;
};

/* Métodos inline */
inline Uint32 Personaje::getId() const { return _id; }
inline Uint32 Personaje::getX() const { return _x; }
inline Uint32 Personaje::getY() const { return _y; }
inline Uint32 Personaje::getMapaX() const { return _mapaX; }
inline Uint32 Personaje::getMapaY() const { return _mapaY; }
inline Uint32 Personaje::getPantX() const { return _pantX; }
inline Uint32 Personaje::getPantY() const { return _pantY; }
inline Uint32 Personaje::getDesp(Uint32 i) const { return _desp.at(i); }
inline const SDL_Rect& Personaje::getRango() const { return _rango; }
inline bool Personaje::fueraRango(Uint32 x, Uint32 y) const {
    return ((x < (Uint32)_rango.x/_tam) ||
            (x >= ((Uint32)_rango.x/_tam + _rango.w/_tam)) ||
            (y < (Uint32)_rango.y/_tam) ||
            (y >= ((Uint32)_rango.y/_tam + _rango.h/_tam)));
}
inline Uint32 Personaje::getSecuenciasMovimiento() const {
    return _sprite.getColumnas();
}
inline Uint32 Personaje::getVelocidad() const { return _velocidad; }
inline void Personaje::setVelocidad(Uint16 v) { if (v <= 150) _velocidad = v; }

#endif
