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
#include "pantalla.h"

using namespace std;

Personaje::Personaje() { }

Personaje::Personaje(Uint32 i, Uint32 x, Uint32 y, Uint32 tam): _id(i),
_x(x), _y(y), _tamCasilla(tam), _rango_pX(0), _rango_pY(0), _rango_dX(0),
_rango_dY(0), _p(0), _sprite(0) {
    cout << "ID: " << _id << endl;
    cout << "X: " << _x << endl;
    cout << "Y: " << _y << endl;
    cout << "RANGO PX: " << _rango_pX << endl;
    cout << "RANGO PY: " << _rango_pY << endl;
    cout << "RANGO DX: " << _rango_dX << endl;
    cout << "RANGO DY: " << _rango_dY << endl;
}

Personaje::Personaje(Uint32 i, const char* sprite, Uint32 x, Uint32 y,
                     Uint32 tam): _id(i),
_x(x), _y(y), _tamCasilla(tam), _rango_pX(0), _rango_pY(0), _rango_dX(0),
_rango_dY(0), _p(0) {
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
    cout << "ID: " << _id << endl;
    cout << "X: " << _x << endl;
    cout << "Y: " << _y << endl;
    cout << "RANGO PX: " << _rango_pX << endl;
    cout << "RANGO PY: " << _rango_pY << endl;
    cout << "RANGO DX: " << _rango_dX << endl;
    cout << "RANGO DY: " << _rango_dY << endl;
}

void Personaje::setPosicion() {
    /* Si esta definido el rango, colocamos al personaje en el centro */
    if (existeRango()) {
        _x = _rango_pX + _rango_dX / 2;
        _y = _rango_pY + _rango_dY / 2;
    }
}

void Personaje::setRango(Uint32 margenIzdo, Uint32 margenArriba,
                         Uint32 rangoAncho, Uint32 rangoAlto) {
    _rango_pX = margenIzdo;
    _rango_pY = margenArriba;
    _rango_dX = rangoAncho;
    _rango_dY = rangoAlto;
    _existeRango = true;
}

void Personaje::dibujarPosicionFrente() {
    cout << "dibujarPosFrente" << endl;
    moverAbajo(0, 0);
}

void Personaje::dibujarPosicionEspaldas()  {
    moverArriba(0, 0);
}

void Personaje::dibujarPosicionLatIzda() {
    moverIzda(0, 0);
}

void Personaje::dibujarPosicionLatDcha() {
    moverDcha(0, 0);
}

void Personaje::moverArriba() {
    mover(_sprite->getMovArriba());
}

Uint32 Personaje::moverArriba(Uint32 mov, Uint32 desp) {
    /* Dibujamos el personaje en la imagen de secuencia indicada, un
     * poco mas avanzado */
    _sprite->dibujar(_sprite->getMovArriba(), mov,
                     _p->getMovimiento(), _x * _tamCasilla,
                     _y * _tamCasilla - desp);
    _p->volcarPantalla(_p->getMovimiento());
    mov = (mov + 1) % _sprite->getColumnas();
    return mov;
}

void Personaje::moverAbajo() {
    mover(_sprite->getMovAbajo());
}

Uint32 Personaje::moverAbajo(Uint32 mov, Uint32 desp) {
    /* Dibujamos el personaje en la imagen de secuencia indicada, un
     * poco mas avanzado */
    _sprite->dibujar(_sprite->getMovAbajo(), mov,
                     _p->getMovimiento(), _x * _tamCasilla,
                     _y * _tamCasilla + desp);
    _p->volcarPantalla(_p->getMovimiento());
    mov = (mov + 1) % _sprite->getColumnas();
    return mov;
}

void Personaje::moverIzda() {
    mover(_sprite->getMovIzda());
}

Uint32 Personaje::moverIzda(Uint32 mov, Uint32 desp) {
    /* Dibujamos el personaje en la imagen de secuencia indicada, un
     * poco mas avanzado */
    _sprite->dibujar(_sprite->getMovIzda(), mov,
                     _p->getMovimiento(), _x * _tamCasilla - desp,
                     _y * _tamCasilla);
    _p->volcarPantalla(_p->getMovimiento());
    mov = (mov + 1) % _sprite->getColumnas();
    return mov;
}

void Personaje::moverDcha() {
    mover(_sprite->getMovDcha());
}

Uint32 Personaje::moverDcha(Uint32 mov, Uint32 desp) {
    /* Dibujamos el personaje en la imagen de secuencia indicada, un
     * poco mas avanzado */
    _sprite->dibujar(_sprite->getMovDcha(), mov,
                     _p->getMovimiento(), _x * _tamCasilla + desp,
                     _y * _tamCasilla);
    _p->volcarPantalla(_p->getMovimiento());
    mov = (mov + 1) % _sprite->getColumnas();
    return mov;
}

void Personaje::mover(Uint32 movimiento) {
    /* Movimientos a realizar suponiendo que el sprite de movimiento
     * esté organizado tal que cada fila corresponda a la secuencia de
     * movimientos hacia una posicion determinada */
    Uint32 movs = _sprite->getColumnas() - 1;

    /* Dibujamos un desplazamiento estático */
    for (Uint32 i = 0; i < movs; i++) {
        _sprite->dibujar(movimiento, i,
                         _p->getMovimiento(), _x * _tamCasilla,
                         _y * _tamCasilla);
        _p->volcarPantalla(_p->getMovimiento());
        SDL_Delay(200);
    }
}
