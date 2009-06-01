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
  Elemento(char* url, Uint32 x, Uint32 y, Pantalla* p);
  string getImagen() const;
  void dibujar();
  virtual ~Elemento();

 private:
  string _urlImagen;
  Uint32 _posX;
  Uint32 _posY;
  Pantalla* _pant;

};

/* Métodos inline */
inline string Elemento::getImagen() const { return _urlImagen; }


class Boton: public Elemento {
 public:
  Boton(char* url, char* mensaje, Pantalla* p, Uint32 x, Uint32 y, Uint32 dX = 0, Uint32 dY = 0, bool activo = false);
  ~Boton();

 private:
  Uint32 _despX;
  Uint32 _despY;
  Uint32 _rangoMensajeX;
  Uint32 _rangoMensajeY;
  char* _mensaje;
  bool _activo;
};


/* Cursor que hereda de elemento */
class Cursor: public Elemento {
 public:
  Cursor();
  ~Cursor();
};


class Menu {
public:
    Menu(char* urlFondo);
    /* Devuelve el codigo (orden) del boton activado, o el valor siguiente al
     último en caso de error */
    Uint32 getPosicionCursor() const;
    Boton* getBoton(Uint32 i) const;
    void setBoton(char* mensaje, Uint32 posX, Uint32 poxY, char* url,
                       Uint32 espacioX, Uint32 espacioY);
    void setBoton(Boton* b);
    void dibujar();
    void actualizar();  
    /**
     * Mueve el cursor hasta el siguiente botón y devuelve su posición en el
     * orden de los botones
     */
    Uint32 avanzarCursor();
    virtual ~Menu();

private:

    void dibujarBotones();
    /**
     * Puntero a la pantalla general del juego.
     */
    Pantalla* _pant;
    /**
     * Objeto de la clase evento que controlará las acciones solicitadas por el
     * usuario.
     */
    Evento _evento;
    char* _urlFondo;
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
};

#endif	/* _MENU_H */
