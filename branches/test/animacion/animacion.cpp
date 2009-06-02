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
 * Fichero: animacion.cpp
 * Autor: Noelia Sales Montes
 * Fecha: 19 de abril de 2009
 * Proyecto: NoCKt Metal
 */

#include <iostream>

#include <vector>

#include "personaje.h"
#include "animacion.h"
#include "imagen.h"
#include "npj.h"

using namespace std;

Animacion::Animacion() {
    evento = Evento();
}

Animacion::Animacion(Pantalla *p): _pant(p) { }

Animacion::~Animacion() { }

void Animacion::inicializarAnimacion() {
    /* Inicializamos el mapa */
 
  cout << "inicializarAnimacion" << endl;
  
  vector<vector<Uint32> > matriz;
  vector<Uint32> auxiliar(36);

  for(Uint32 i=0; i<48; i++)
    matriz.push_back(auxiliar);

  for (Uint32 j = 0; j < 48; j++) {
    for(Uint32 i = 0; i < 36; i++) {
      cout << "(" << i << "," << j << ")" << endl;
      matriz[j][i] = 6;
      if(j <= 6 || j >= 40 || i <= 4 || i >= 31) {
	matriz[j][i] = 1;
      }
      if(i == 5 && j > 6 && j < 40) {
                matriz[j][i] = 5;
      }
      if(i == 6 && j > 6 && j < 40) {
	matriz[j][i] = 4;
      }
      if(i == 17 && j > 10 && j < 30) {
	matriz[j][i] = 5;
      }
    }
  }
  
  cout << "matriz de tiles echo" << endl;

  Uint32 fondoX = 10, fondoY = 10;
    
  cout << "NPJS" << endl;
  std::vector<NPJ> personajes;
  personajes.push_back(NPJ(0,30,30,"baldos.png"));
  personajes.push_back(NPJ(1,7,7,"lapunki.png"));
  
  cout << "imagen!" << endl;
  _imag = new Imagen(48, 36, fondoX, fondoY, personajes, *_pant, matriz);

    Tile arena("./tiles/arena.png");
    Tile piedra("./tiles/piedra.png", true);
    Tile madera("./tiles/madera.png");
    Tile metal("./tiles/metal.png");
    Tile ladrillo("./tiles/ladrillos.png", true);
    Tile ladTope("./tiles/ladrillosTope.png", true);

    _imag->relacionarTile(1, piedra);
    _imag->relacionarTile(2, arena);
    _imag->relacionarTile(3, madera);
    _imag->relacionarTile(4, ladrillo);
    _imag->relacionarTile(5, ladTope);
    _imag->relacionarTile(6, metal);

    cout << "dibujar fondoo!" << endl;
    _imag->dibujarFondo();

    cout << "personaje" << endl;
    /* Personaje */
    _principal = new Personaje(1,1,1,30,_pant, "./lapunki.png");
    _principal->setRango(2, 2);
    _principal->setPosicion();
    _principal->setMapa(fondoX + _principal->getPantX(),
                        fondoY + _principal->getPantY());
    _principal->setVelocidad(80);
    _principal->dibujarPosicionFrente();
    /* Dibujamos la pantalla inicial */
    _pant->volcarPantalla(_pant->getBuffer());
}

bool Animacion::procesarAccion() {
    /* Cargamos las posiciones iniciales del personaje y del fondo */
    Uint32 x = _principal->getPantX();
    Uint32 y = _principal->getPantY();
    Uint32 mx = _principal->getMapaX();
    Uint32 my = _principal->getMapaY();
    Sint32 cx = _imag->getCX();
    Sint32 cy = _imag->getCY();
    /* Movimiento actual tomado como NULO */
    _mov = NULO;

    char dir = ' ';

    /* Lectura del nuevo evento */
    switch (evento.getEvento()) {
    case SALIR:
        cout << "Saliendo de la ejecucion del programa" << endl;
        return true;
    case MENU:
        cout << "Desea ver el menu... va a tener que esperar un poco..." << endl;
        break;
    case ACEPTAR:
        cout << "Ha aceptado algo... Pero aqui no sirve de nada... "
                << " eso solo vale en los menus..." << endl;
        break;
    case ATRAS:
        cout << "Ha rechazado algo... eso solo sirve en un menu... "
                << endl;
        break;
    case ARRIBA:
        dir = 'u';
        y = _principal->getPantY() - 1;
        my = _principal->getMapaY() - 1;
        cy = _imag->getCY() - 1;
        _mov = SUBIR;
        break;
    case ABAJO:
        dir = 'd';
        y = _principal->getPantY() + 1;
        my = _principal->getMapaY() + 1;
        cy = _imag->getCY() + 1;
        _mov = BAJAR;
        break;
    case IZQUIERDA:
        dir = 'l';
        x = _principal->getPantX() - 1;
        mx = _principal->getMapaX() - 1;
        cx = _imag->getCX() - 1;
        _mov = IZDA;
        break;
    case DERECHA:
        dir = 'r';
        x = _principal->getPantX() + 1;
        mx = _principal->getMapaX() + 1;
        cx = _imag->getCX() + 1;
        _mov = DCHA;
        break;
    default:
        break;
    }

    /* Si la opción elegida es realizar un movimiento... */
    if (_mov != NULO) {
        /* Si se puede mover a la siguiente posicion (no colisionable) */
        if (!_imag->isColisionable(mx, my)) {
            actualizarMapa();
            /* Si el movimiento queda fuera del rango de pantalla del personaje,
             * se moverá de forma estática, desplazándose el fondo por debajo */
            if (_principal->fueraRango(x, y)) {
                hacerMovimientoEstatico(cx, cy, dir);
            } else {
                /* En caso de que se desplace el personaje, el fondo quedará tal y
                 * como estaba (por lo que no tendremos que pintarlo de nuevo,
                 * tan sólo hemos de volcarlo repetidas veces desde el buffer). */
                hacerMovimientoDinamico();
            }
        } else {
	  cout << "Personaje en: (" << _principal->getMapaX() << "," << _principal->getMapaY() << ")" << endl;
            cout << "COLISION EN (" << mx << ", " << my << ")" << endl;
	    if(_imag->isInteractuable(mx,my)){
	      _imag->dibujar(mx,my,_principal->getMapaX(), _principal->getMapaY());
	    }
	    _pant->volcarPantalla(_pant->getBuffer());
            dibujarPosicionEstatica();
	    
        }
    }
    return false;
}

void Animacion::hacerMovimientoEstatico(Sint32 x, Sint32 y, char dir) {
    /* Mientras necesitemos mover al personaje */
    for (Sint32 sec = _principal->getSecuenciasMovimiento() - 1; sec >= 0;
         --sec) {
        /* Desplazamos el mapa */
        _imag->dibujarSecuencia(dir, _principal->getSecuenciasMovimiento() - sec,
                                _principal->getSecuenciasMovimiento());
        /* Mover el personaje (autovolcado en buffer) */
        mover(sec, 0);
        /* Pantalla visible */
        _pant->volcarPantalla(_pant->getBuffer());
    }
}

void Animacion::hacerMovimientoDinamico() {
    /* Mientras necesitemos mover al personaje */
    for (Sint32 sec = _principal->getSecuenciasMovimiento() - 1; sec >= 0;
         --sec) {
        /* Volcar fondo en buffer */
        _pant->volcarPantalla(_pant->getFondo(), _pant->getBuffer());
        /* Volcar seccion de movimiento del PJ en buffer */
        mover(sec, _principal->getDesp(sec));
        /* Pantalla visible */
        _pant->volcarPantalla(_pant->getBuffer());
    }

    /* En función de la orientación del movimiento, indicamos que se ha
     * producido una variación en la posición de pantalla medida en casillas */
    switch (_mov) {
    case SUBIR:
        _principal->subirEnPantalla();
        break;
    case BAJAR:
        _principal->bajarEnPantalla();
        break;
    case IZDA:
        _principal->izdaEnPantalla();
        break;
    case DCHA:
        _principal->dchaEnPantalla();
        break;
    default:
        break;
    }
}

void Animacion::mover(Uint32 sec, Uint32 desp) {
    switch (_mov) {
    case SUBIR:
        _principal->moverArriba(sec, desp);
        break;
    case BAJAR:
        _principal->moverAbajo(sec, desp);
        break;
    case IZDA:
        _principal->moverIzda(sec, desp);
        break;
    case DCHA:
        _principal->moverDcha(sec, desp);
        break;
    default:
        break;
    }
}

void Animacion::actualizarMapa() {
    switch (_mov) {
    case SUBIR:
        _principal->subirEnMapa();
        break;
    case BAJAR:
        _principal->bajarEnMapa();
        break;
    case IZDA:
        _principal->izdaEnMapa();
        break;
    case DCHA:
        _principal->dchaEnMapa();
        break;
    default:
        break;
    }
}

void Animacion::dibujarPosicionEstatica() {
    /* Mientras necesitemos mover al personaje */
    for (Sint32 sec = _principal->getSecuenciasMovimiento() - 1; sec >= 0;
         --sec) {
        /* Volcar fondo en buffer */
        _pant->volcarPantalla(_pant->getFondo(), _pant->getBuffer());
        /* Mover el personaje (autovolcado en buffer) */
        mover(sec, 0);
        /* Pantalla visible */
        _pant->volcarPantalla(_pant->getBuffer());
    }
}
