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
 * Fichero: personaje.cpp
 * Autor: Noelia Sales Montes
 * Fecha: 14 04 2009
 * Proyecto: NoCKt Metal
 */

#include <iostream>
#include <SDL/SDL.h>

#include "personaje.h"

using namespace std;

Personaje::Personaje() { }

Personaje::Personaje(Uint32 i, Uint32 x, Uint32 y, Pantalla* p,
                     const char* sprite, Uint32 f, Uint32 c):
                     _id(i), _x(0), _y(0), _pantX(x), _pantY(y), _p(p) {
    _sprite = Sprite(sprite, f, c);
    _rango.x = 0;
    _rango.y = 0;
    _rango.w = _p->getAncho();
    _rango.h = _p->getAlto();
}

Personaje::Personaje(Uint32 i, Uint32 x, Uint32 y, Uint32 mapax, Uint32 mapay,
                     Uint32 tam, Pantalla* p, const char* sprite, Uint32 f,
                     Uint32 c):
                     _id(i), _mapaX(mapax), _mapaY(mapay), _x(x*tam), _y(y*tam),
                     _pantX(x), _pantY(y), _tam(tam), _p(p) {
    _sprite = Sprite(sprite, f, c);
    _rango.x = 0;
    _rango.y = 0;
    _rango.w = _p->getAncho();
    _rango.h = _p->getAlto();
}

Personaje::~Personaje() { }

/*
void Personaje::animadoEn(Pantalla& p) {
    _p = &p;
}*/

void Personaje::setPosicion(Uint32 x, Uint32 y) {
    _mapaX = x;
    _mapaY = y;
}

void Personaje::setPosicion() {
    /* Colocamos al personaje en el centro del rango*/
    _x = _rango.x + _rango.w / 2;
    _y = _rango.y + _rango.h / 2;
}

void Personaje::setRango(Uint16 margenIzdo, Uint16 margenArriba,
                         Uint16 rangoAncho, Uint16 rangoAlto) {
    _rango.x = margenIzdo;
    _rango.y = margenArriba;
    _rango.w = rangoAncho;
    _rango.h = rangoAlto;
}

void Personaje::setRango(Uint16 rangoAncho, Uint16 rangoAlto) {
    if (rangoAncho == 0 || rangoAlto == 0) {
        /* Se toma el rango de un cuadrado de 2 x 2 casillas */
        rangoAncho = rangoAlto = 2;
    }
    _rango.w = rangoAncho * _tam;
    _rango.h = rangoAlto * _tam;
    _rango.x = (_p->getAncho() - _rango.w)/2;
    _rango.y = (_p->getAlto() - _rango.h)/2;
}

void Personaje::setTam(Uint32 tam) {
    _tam = tam;
}

void Personaje::subirEnMapa() {
    _mapaY--;
}

void Personaje::bajarEnMapa() {
    _mapaY++;
}

void Personaje::izdaEnMapa() {
    _mapaX--;
}

void Personaje::dchaEnMapa() {
    _mapaX++;
}

void Personaje::dibujarPosicionFrente() {
    moverAbajo(0, 0);
}

void Personaje::dibujarPosicionEspaldas() {
    moverArriba(0, 0);
}

void Personaje::dibujarPosicionLatIzda() {
    moverIzda(0, 0);
}

void Personaje::dibujarPosicionLatDcha() {
    moverDcha(0, 0);
}

void Personaje::moverArriba(Uint32 mov, Uint32 desp) {
    /* Posicion en la pantalla actualizada */
    _y = _y - desp;
    /* Modificamos la posicion actual en la pantalla */
    mover(_sprite.getMovArriba(), mov);
}

void Personaje::moverAbajo(Uint32 mov, Uint32 desp) {
    /* Posicion en la pantalla actualizada */
    _y = _y + desp;
    /* Modificamos la posicion actual en la pantalla */
    mover(_sprite.getMovAbajo(), mov);
}

void Personaje::moverIzda(Uint32 mov, Uint32 desp) {
    /* Posicion en la pantalla actualizada */
    _x = _x - desp;
    /* Modificamos la posicion actual en la pantalla */
    mover(_sprite.getMovIzda(), mov);
}

void Personaje::moverDcha(Uint32 mov, Uint32 desp) {
    /* Posicion en la pantalla actualizada */
    _x = _x + desp;
    /* Modificamos la posicion actual en la pantalla */
    mover(_sprite.getMovDcha(), mov);
}

void Personaje::mover(Uint32 movimiento, Uint32 secuencia) {
    /* Dibujamos el personaje en la imagen de secuencia indicada en la
     * posicion actualizada de pantalla */
    _sprite.dibujar(movimiento, secuencia, _p->getBuffer(), _x, _y);
    _p->volcarPantalla(_p->getBuffer(), &_rango);
    /* Trastear cuanto tiempo es necesario para que no se vea raro, en
     * de que no vaya ya demasiado lento */
     /*SDL_Delay(10);*/
}
