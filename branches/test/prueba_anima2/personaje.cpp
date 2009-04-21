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
#include "tile.h"

using namespace std;

Personaje::Personaje() { }

Personaje::Personaje(Uint32 i, Uint32 x, Uint32 y): _id(i), _x(x), _y(y),
_rango(), _existeRango(false), _p(0), _sprite(0) { }

Personaje::Personaje(Uint32 i, const char* sprite, Uint32 x, Uint32 y): _id(i),
_x(x), _y(y), _rango(), _existeRango(false), _p(0) {
    Sprite s(sprite, 4, 4, 16);
    _sprite = &s;
}

Personaje::~Personaje() { }

void Personaje::animadoEn(Pantalla& p) {
    _p = &p;
}

void Personaje::dibujadoPor(Sprite& s) {
    _sprite = &s;
}

void Personaje::setPosicion(Uint32 x, Uint32 y) {
    _x = x;
    _y = y;
}

void Personaje::setPosicion() {
    /* Si esta definido el rango, colocamos al personaje en el centro */
    if (existeRango()) {
        _x = _rango.x + _rango.w / 2;
        _y = _rango.y + _rango.h / 2;
    }
}

void Personaje::setRango(Uint16 margenIzdo, Uint16 margenArriba,
                         Uint16 rangoAncho, Uint16 rangoAlto) {
    _rango.x = margenIzdo;
    _rango.y = margenArriba;
    _rango.w = rangoAncho;
    _rango.h = rangoAlto;
    _existeRango = true;
}

void Personaje::actualizarMapa(Uint32 mapaX, Uint32 mapaY) {
    _mapaX = mapaX;
    _mapaY = mapaY;
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
  _y = _y - desp;     // ahora son TILES
  /* Modificamos la posicion actual en la pantalla */
  mover(_sprite->getMovAbajo(), mov);
}

void Personaje::moverAbajo(Uint32 mov, Uint32 desp) {
    /* Posicion en la pantalla actualizada */
  _y = _y + desp;    //TILES
    /* Modificamos la posicion actual en la pantalla */
    mover(_sprite->getMovAbajo(), mov);
}

void Personaje::moverIzda(Uint32 mov, Uint32 desp) {
    /* Posicion en la pantalla actualizada */
  _x = _x - desp;   //TILES
    /* Modificamos la posicion actual en la pantalla */
    mover(_sprite->getMovIzda(), mov);
}

void Personaje::moverDcha(Uint32 mov, Uint32 desp) {
    /* Posicion en la pantalla actualizada */
  _x = _x + desp;  //TILES
    /* Modificamos la posicion actual en la pantalla */
    mover(_sprite->getMovDcha(), mov);
}

void Personaje::mover(Uint32 movimiento, Uint32 secuencia) {
    /* Dibujamos el personaje en la imagen de secuencia indicada en la
     * posicion actualizada de pantalla */
    _sprite->dibujar(movimiento, secuencia, _p->getMovimiento(), _x*_Tam_Tile,
		     _y*_Tam_Tile);  // EL movimiento en tiles.
    _p->volcarPantalla(_p->getMovimiento());
    /* Trastear cuanto tiempo es necesario para que no se vea raro, en
     * de que no vaya ya demasiado lento */
     SDL_Delay(10);
}
