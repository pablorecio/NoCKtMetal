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
 * Fichero: menu.cpp
 * Autor: Noelia Sales Montes
 * Fecha: 28 de mayo de 2009
 * Proyecto: NoCKt Metal
 */

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <iostream>

#include "menu.h"
#include "pantalla.h"
#include "sistema.h"

using namespace std;


/**********************************************************************
 * Elemento
 **********************************************************************/

Elemento::Elemento(const char* url, Uint32 x, Uint32 y, Pantalla* p):
_posX(x), _posY(y), _pant(p) {

    /* Cargamos la imagen en la pantalla */
    _imagen = IMG_Load(url);


    if (_imagen == NULL) {
        cerr << "Error: " << SDL_GetError() << endl;
        exit(1);
    }

    /* Convertir a formato de pantalla */
    SDL_Surface *aux = IMG_Load(url);
    _imagen = SDL_DisplayFormatAlpha(aux);
    SDL_FreeSurface(aux);

    if (_imagen == NULL) {
        cerr << "Error: " << SDL_GetError() << endl;
        exit(1);
    }

    /* Guardamos el ancho y el alto del elemento */
    _ancho = aux->w;
    _alto = aux->h;
}

void Elemento::dibujar() {

    SDL_Rect r;
    r.x = _posX;
    r.y = _posY;

    /* Volcamos el elemento en la pantalla */
    _pant->volcarPantalla(_imagen, NULL, _pant->getBuffer(), &r);

    /* Volcamos el buffer en la pantalla principal */
    _pant->volcarPantalla(_pant->getBuffer());
}

void Elemento::dibujar(SDL_Surface *p) {

    SDL_Rect r;
    r.x = _posX;
    r.y = _posY;

    /* Volcamos el elemento en la pantalla dada */
    _pant->volcarPantalla(_imagen, NULL, p, &r);
}


/**********************************************************************
 * Botón
 **********************************************************************/

inline Boton::Boton(const char* url, const char* mensaje, Pantalla* p,
                    Uint32 x, Uint32 y, Uint32 dX, Uint32 dY, Uint32 rX,
                    Uint32 rY):
                    Elemento(url, x, y, p), _despX(dX), _despY(dY),
        _rangoMensajeX(rX), _rangoMensajeY(rY), _mensaje(mensaje) {

	iniciarTTF();

    /* Definición del tipo de fuente del menu */
    _tipoFuente = TTF_OpenFontRW(SDL_RWFromFile("fuentes/FontMenu.ttf", "r"), 1, 19);

    /* Color de la fuente */
    SDL_Color c;
    c.r = 150;
    c.g = 0;
    c.b = 0;


    SDL_Rect r;
    r.x = _rangoMensajeX;
    r.y = _rangoMensajeY;

    /* Cargamos el mensaje */
    cout << "El mensaje es: " << _mensaje << endl;
    SDL_Surface* texto = TTF_RenderText_Blended(_tipoFuente, _mensaje, c);
    p->volcarPantalla(texto, NULL, _imagen, &r);
    SDL_FreeSurface(texto);
}


/**********************************************************************
 * Menú
 **********************************************************************/

Menu::Menu(const char* urlFondo, const char* urlCursor, Pantalla* p):
	_pant(p), _botonActivo(0), _numBotones(0), _estadoSalida(false),
	_estadoAceptado(false) {

    _evento = Evento(80);

    /* Cargamos la imagen en la pantalla */
    _fondo = IMG_Load(urlFondo);

    if (_fondo == NULL) {
        cerr << "Error: " << SDL_GetError() << endl;
        exit(1);
    }

    /* Convertir a formato de pantalla */
    SDL_Surface *aux = IMG_Load(urlFondo);
    _fondo = SDL_DisplayFormatAlpha(aux);
    SDL_FreeSurface(aux);

    if (_fondo == NULL) {
        cerr << "Error: " << SDL_GetError() << endl;
        exit(1);
    }

    /* Definición del color transparente */
    Uint32 colorkey = SDL_MapRGB(_fondo->format, 0, 255, 0);
    SDL_SetColorKey(_fondo, SDL_SRCCOLORKEY, colorkey);

    _cursor = new Cursor(urlCursor, _pant);
}


void Menu::setBoton(const char* mensaje, Uint32 posx, Uint32 posy,
                    const char* url, Uint32 espacioX, Uint32 espacioY) {

	/* Si es el primer botón, se toma por defecto como activado */
    if(_numBotones == 0) {
        _botonActivo = 0;
    }

    Boton *b = new Boton(url, mensaje, _pant, posx, posy, 0,0,10,10);
    _botones.insert(make_pair(_numBotones, b));

    /* Dibujamos el botón en el fondo, puesto que no es necesario redibujarlo
     * cada vez que se mueva el cursor: siempre va a estar en la misma posición
     */
    b->dibujar(_fondo);

    /* Volvemos a comprobar si es el primer botón introducido en el
     * mapa, para calcular la posición inicial del cursor en base a éste */
    if(_numBotones == 0) {
        Uint32 x = b->getPosX() - b->getDespX() - _cursor->getAncho();
        Uint32 y = b->getPosY() + b->getDespY();
        _cursor->setPosicion(x,y);
    }

    _numBotones++;
}

void Menu::dibujar() {
    _pant->volcarPantalla(_fondo, _pant->getBuffer());
    _cursor->dibujar();
}

bool Menu::actualizar() {
    /* Cargamos las posiciones iniciales de los elementos y del fondo */

    /* Reiniciamos las banderas */
    _estadoSalida = false;
    _estadoAceptado = false;

    /* Lectura del nuevo evento */
    switch (_evento.getEvento()) {
    case SALIR:
        cout << "Saliendo de la ejecucion del programa" << endl;
        _estadoSalida = true;
        return true;
    case ACEPTAR:
        cout << "Ha elegido la opción " << _botonActivo << endl;
        _estadoAceptado = true;
        return true;
    case ATRAS:
        cout << "Reiniciar el menú" << endl;
        break;
    case ARRIBA: case IZQUIERDA:
        retrocederCursor();
        dibujar();
        break;
    case ABAJO: case DERECHA:
        avanzarCursor();
        dibujar();
        break;
    default:
        break;
    }

    return false;
}

Uint32 Menu::retrocederCursor() {
    if (_numBotones != 0) {
        if (_botonActivo == 0) {
            /* Hemos llegado al último botón por lo que volvemos al primero */
        	_botonActivo = _numBotones-1;
        } else {
        	/* Retrocedemos el cursor */
        	_botonActivo--;
        }
    }
    /* Incluir un else y lanzar un error en caso de que no haya botones */

    /* Recalcular posiciones del cursor en función del botón activo:
     * el cursor aparece en este caso a la izquierda del botón, pero
     * esto puede modificarse fácilmente */
    Boton* aux = _botones.at(_botonActivo);
    Uint32 x = aux->getPosX() - aux->getDespX() - _cursor->getAncho();
    Uint32 y = aux->getPosY() + aux->getDespY();
    _cursor->setPosicion(x,y);

    return _botonActivo;
}


Uint32 Menu::avanzarCursor() {
    if (_numBotones != 0) {
        /* Avanzamos el cursor */
        _botonActivo++;
        if (_botonActivo >= _numBotones) {
            /* Hemos llegado al último botón por lo que volvemos al primero */
            _botonActivo = 0;
        }
    }
    /* Incluir un else y lanzar un error en caso de que no haya botones */

    /* Recalcular posiciones del cursor en función del botón activo:
     * el cursor aparece en este caso a la izquierda del botón, pero
     * esto puede modificarse fácilmente */
    Boton* aux = _botones.at(_botonActivo);
    Uint32 x = aux->getPosX() - aux->getDespX() - _cursor->getAncho();
    Uint32 y = aux->getPosY() + aux->getDespY();
    _cursor->setPosicion(x,y);

    return _botonActivo;
}

/**********************************************************************
 * MenúVariable
 **********************************************************************/

MenuVariable::MenuVariable(const char* urlFondo, const char* urlCursor,
		Pantalla* p, Uint32 tamX, Uint32 tamY, Uint32 posX, Uint32 posY):
			_pant(p), _botonActivo(0), _numBotones(0), estadoSalida(false),
			_estadoAceptado(false), _ancho(tamX), _alto(tamY), _posX(posX),
			_posY(posY) {

    _evento = Evento(80);

    /* Cargamos la imagen en la pantalla */
    SDL_Surface* aux = IMG_Load(urlFondo);

    if (_fondo == NULL) {
        cerr << "Error: " << SDL_GetError() << endl;
        exit(1);
    }

    /* Convertir a formato de pantalla */
    SDL_Surface *aux2 = IMG_Load(urlFondo);
    aux = SDL_DisplayFormatAlpha(aux);
    SDL_FreeSurface(aux2);

    if (aux == NULL) {
        cerr << "Error: " << SDL_GetError() << endl;
        exit(1);
    }

    /* Definición del color transparente */
    Uint32 colorkey = SDL_MapRGB(_fondo->format, 0, 255, 0);
    SDL_SetColorKey(_fondo, SDL_SRCCOLORKEY, colorkey);

    /* Pegamos la imagen en la zona correspondiente del mapa */
    SDL_Rect r;
    r.x = _posX;
    r.y = _posY;
    r.w = _ancho;
    r.h = _alto;

    _pant->volcarPantalla(aux, _fondo, &r);

    _cursor = new Cursor(urlCursor, _pant);
}
