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
 * Fichero: menu.h
 * Autor: Noelia Sales Montes
 * Fecha: 28 de mayo de 2009
 * Proyecto: NoCKt Metal
 */

#ifndef _MENU_H
#define	_MENU_H

#include <iostream>
#include <cstring>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "evento.h"
#include "pantalla.h"

using namespace std;

class Elemento {
public:
    Elemento();
    Elemento(string url, Uint32 x, Uint32 y, Pantalla* p);
    string getImagen() const;
    Uint32 getPosX() const;
    Uint32 getPosY() const;
    Uint32 getAncho() const;
    Uint32 getAlto() const;
    void dibujar();
    virtual ~Elemento();

private:

    /**
     * Superficie de la librería SDL donde se almacena la imagen.
     */
    SDL_Surface* _imagen;

    string _urlImagen;
    Uint32 _posX;
    Uint32 _posY;
    Pantalla* _pant;

    /* Ancho de la imagen que representa el botón */
    Uint32 _ancho;
    /* Alto de la imagen que representa el botón */
    Uint32 _alto;
};

/* Métodos inline */
inline Elemento::Elemento(): _imagen(0), _urlImagen(0), _posX(0), _posY(0),
        _pant(0) {}
inline string Elemento::getImagen() const { return _urlImagen; }
inline Uint32 Elemento::getPosX() const { return _posX; }
inline Uint32 Elemento::getPosY() const { return _posY; }
inline Uint32 Elemento::getAncho() const { return _ancho; }
inline Uint32 Elemento::getAlto() const { return _alto; }
inline Elemento::~Elemento() {}


class Boton: public Elemento {
public:
    Boton();
    Boton(string url, string mensaje, Pantalla* p, Uint32 x, Uint32 y,
          Uint32 dX = 0, Uint32 dY = 0, Uint32 rX = 0, Uint32 rY = 0,
          bool activo = false);
    Uint32 getDespX() const;
    Uint32 getDespY() const;
    ~Boton();

private:
    /* Separación lateral con respecto al cursor */
    Uint32 _despX;
    /* Separación vertical con respecto al cursor */
    Uint32 _despY;

    /* Separación lateral con respecto al mensaje */
    Uint32 _rangoMensajeX;
    /* Separación vertical con respecto al mensaje */
    Uint32 _rangoMensajeY;
    string _mensaje;
    bool _activo;
};

/* Métodos inline */
inline Boton::Boton(): Elemento() {}
inline Boton::Boton(string url, string mensaje, Pantalla* p, Uint32 x, Uint32 y,
                    Uint32 dX = 0, Uint32 dY = 0, Uint32 rX = 0, Uint32 rY = 0,
                    bool activo = false): Elemento(url, x, y, p), _despX(dX),
        _despY(dY), _rangoMensajeX(rX), _rangoMensajeY(rY), _mensaje(mensaje),
        _activo(activo) {}
inline Uint32 Boton::getDespX() const;
inline Uint32 Boton::getDespY() const;
inline Boton::~Boton() {}


/* Cursor que hereda de elemento */
class Cursor: public Elemento {
public:
    Cursor();
    Cursor(char* url, Uint32 x, Uint32 y, Pantalla* p);
    /*
     * Modificación de la posición.
     */
    void setPosicion(Uint32 x, Uint32 y);
    ~Cursor();
};

/* Métodos inline */
inline Cursor::Cursor(): Elemento() {}
inline Cursor::Cursor(char* url, Uint32 x, Uint32 y, Pantalla* p):
Elemento(url, x, y, p) {}
inline void Cursor::setPosicion(Uint32 x, Uint32 y) { _posX = x; _posY = y; }
inline Cursor::~Cursor() {}


/**
 * Clase que abstrae el comportamiento y la visualización del menú principal
 * @author Noelia Sales Montes
 */
class Menu {
public:
    /**
     * Constructor predeterminado.
     */
    Menu();
    /**
     * Constructor de una instancia utilizable como menú.
     * @param urlFondo Ruta a la imagen de fondo del menú.
     */
    Menu(string urlFondo);
    /* Devuelve el codigo (orden) del boton activado, o el valor siguiente al
     último en caso de error */
    Uint32 getPosicionCursor() const;
    Boton* getBoton(Uint32 i) const;
    Uint32 getNumBotones() const;
    bool getEstadoSalida() const;
    bool getEstadoAceptado() const;
    void setBoton(string mensaje, Uint32 posX, Uint32 poxY, string url,
                  Uint32 espacioX, Uint32 espacioY);
    void setBoton(Boton* b);
    void setCursor(char* url, Uint32 x, Uint32 y);
    void setCursor(Cursor* c);
    void dibujar();
    bool actualizar();
    /**
     * Mueve el cursor hasta el botón anterior y devuelve su posición en el
     * orden de los botones.
     */
    Uint32 retrocederCursor();
    /**
     * Mueve el cursor hasta el siguiente botón y devuelve su posición en el
     * orden de los botones.
     */
    Uint32 avanzarCursor();
    virtual ~Menu();

private:

    /**
     * Puntero a la pantalla general del juego.
     */
    Pantalla* _pant;
    /**
     * Objeto de la clase evento que controlará las acciones solicitadas por el
     * usuario.
     */
    Evento _evento;
    string _urlFondo;
    /**
     * Botón actual que está activado.
     */
    Uint32 _botonActivo;
    /**
     * Número total de botones.
     * Debe coincidir con el tamaño de <code>_botones</code>.
     */
    Uint32 _numBotones;
    map<Uint32, Boton*> _botones;
    Cursor* _cursor;
    bool _estadoSalida;
    bool _estadoAceptado;
};

inline Menu::Menu() {}
inline Menu::Menu(string urlFondo): _urlFondo(urlFondo) {
    _evento = new Evento();
}
/* Devuelve el codigo (orden) del boton activado, o el valor siguiente al
 * último en caso de error */
inline Uint32 Menu::getPosicionCursor() const { return _botonActivo; }
inline Boton* Menu::getBoton(Uint32 i) const { return _botones[i]; }
inline Uint32 Menu::getNumBotones() const { return _numBotones; }
inline bool Menu::getEstadoSalida() const { return _estadoSalida; }
inline bool Menu::getEstadoAceptado() const { return _estadoAceptado; }
inline void Menu::setCursor(Cursor* c) { _cursor = c; }
inline Menu::~Menu() {}

#endif	/* _MENU_H */