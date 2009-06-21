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
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "evento.h"
#include "pantalla.h"

using namespace std;

/**
 * Clase que abstrae un elemento básico de un menú.
 * Se utilizará como clase base para el resto de componentes. Entre ellos,
 * botones y cursores.
 * @author Noelia Sales Montes
 * @date 28 05 2009
 * @note Parte del Proyecto NoCKt Metal
 */
class Elemento {
public:

	/**
	 * Constructor predeterminado.
	 */
    Elemento();

    /**
     * Constructor de la clase elemento.
     * @param url Ruta a la imagen que representa el elemento.
     * @param x Posición horizontal inicial del elemento.
     * @param y Posición vertical inicial del elemento.
     * @param p Puntero a la pantalla donde se dibujará el elemento.
     * Debe ser la misma que la del menú.
     */
    Elemento(const char* url, Uint32 x, Uint32 y, Pantalla* p);

    /**
     * Método observador de la posición horizontal del elemento.
     * @return Entero que se corresponde con la posición horizontal.
     */
    Uint32 getPosX() const;
    /**
     * Método observador de la posición vertical del elemento.
     * @return Entero que se corresponde con la posición vertical.
     */
    Uint32 getPosY() const;
    /**
     * Método observador del ancho del elemento.
     * @return Entero que se corresponde con la anchura de la imagen
     * que representa al elemento.
     */
    Uint32 getAncho() const;
    /**
     * Método observador del alto del elemento.
     * @return Entero que se corresponde con la altura de la imagen
     * que representa al elemento.
     */
    Uint32 getAlto() const;

    /**
     * Método que dibuja el elemento en la pantalla asociada.
     */
    void dibujar();
    /**
     * Método que dibuja el elemento en la pantalla dada.
     * @param p Superficie de la SDL en la cual se debe pintar el elemento.
     */
    void dibujar(SDL_Surface* p);

    /**
     * Destructor de la clase Elemento.
     */
    virtual ~Elemento();

protected:

    /**
     * Superficie de la librería SDL donde se almacena la imagen que
     * representa al elemento.
     */
    SDL_Surface* _imagen;

    /**
     * Posición horizontal del elemento.
     */
    Uint32 _posX;
    /**
     * Posición vertical del elemento.
     */
    Uint32 _posY;

    /**
     * Puntero a la pantalla donde se dibujará el elemento.
     */
    Pantalla* _pant;

    /**
     * Ancho de la imagen que representa el elemento.
     */
    Uint32 _ancho;
    /**
     * Alto de la imagen que representa el elemento.
     */
    Uint32 _alto;
};

/* Métodos inline de la clase Elemento */
inline Elemento::Elemento(): _imagen(0), _posX(0), _posY(0),
        _pant(0) {}
inline Uint32 Elemento::getPosX() const { return _posX; }
inline Uint32 Elemento::getPosY() const { return _posY; }
inline Uint32 Elemento::getAncho() const { return _ancho; }
inline Uint32 Elemento::getAlto() const { return _alto; }
inline Elemento::~Elemento() {}



/**
 * Clase que abstrae el comportamiento de un boton de un menú.
 * Hereda el comportamiento básico de un elemento de menú, pero añade
 * nuevas funcionalidades como contener un mensaje en el interior del
 * elemento visual que se le asigne.
 * @author Noelia Sales Montes
 * @date 28 05 2009
 * @note Parte del Proyecto NoCKt Metal
 */
class Boton: public Elemento {
public:

	/**
	 * Constructor predeterminado.
	 */
    Boton();

    /**
     * Constructor de la clase Boton.
     * @param url Ruta a la imagen que representa el botón.
     * @param mensaje Mensaje o cadena que se muestra en el interior del botón.
     * @param p Puntero a la pantalla donde se dibujará el botón.
     * @param x Posición horizontal inicial del elemento.
     * @param y Posición vertical inicial del elemento.
     * @param dX Desplazamiento o margen horizontal con respecto a elementos
     * exteriores.
     * @param dY Desplazamiento o margen vertical con respecto a elementos
     * exteriores.
     * @param rX Desplazamiento o margen horizontal con respecto a elementos
     * interiores, en este caso el mensaje a mostrar.
     * @param rY Desplazamiento o margen vertical con respecto a elementos
     * interiores, en este caso el mensaje a mostrar.
     */
    Boton(const char* url, const char* mensaje, Pantalla* p, Uint32 x, Uint32 y,
          Uint32 dX = 0, Uint32 dY = 0, Uint32 rX = 0, Uint32 rY = 0, 
	  const char* urlFont = "fuentes/FontMenu.ttf", Uint32 tamFont = 19);

    /**
     * Método observador del desplazamiento o margen horizontal con respecto
     * a elementos exteriores.
     */
    Uint32 getDespX() const;
    /**
     * Método observador del desplazamiento o margen vertical con respecto
     * a elementos exteriores.
     */
    Uint32 getDespY() const;

    /**
     * Destructor de la clase Boton.
     */
    ~Boton();

private:

    /**
     * Separación lateral con respecto al cursor.
     */
    Uint32 _despX;
    /**
     * Separación vertical con respecto al cursor.
     */
    Uint32 _despY;

    /**
     * Separación lateral con respecto al mensaje.
     */
    Uint32 _rangoMensajeX;
    /**
     * Separación vertical con respecto al mensaje.
     */
    Uint32 _rangoMensajeY;

    /**
     * Mensaje que contiene el botón.
     */
    const char* _mensaje;
    /**
     * Tipo de fuente asociada al mensaje del botón.
     */
    TTF_Font* _tipoFuente;
};

/* Métodos inline de la clase Boton */
inline Boton::Boton(): Elemento() {}
inline Uint32 Boton::getDespX() const { return _despX; }
inline Uint32 Boton::getDespY() const { return _despY; }
inline Boton::~Boton() {}


/**
 * Clase que abstrae el comportamiento de un cursor de un menú.
 * Hereda el comportamiento básico de un elemento de menú, pero añade
 * nuevas funcionalidades como el cambio de posicionamiento externo.
 * @author Noelia Sales Montes
 * @date 28 05 2009
 * @note Parte del Proyecto NoCKt Metal
 */
class Cursor: public Elemento {
public:

	/**
	 * Constructor predeterminado.
	 */
    Cursor();

    /**
     * Constructor de la clase Cursor.
     * @param url Ruta a la imagen que representa el cursor.
     * @param p Puntero a la pantalla donde se dibujará el cursor.
     */
    Cursor(const char* url, Pantalla* p);

    /*
     * Modificación de la posición.
     */
    void setPosicion(Uint32 x, Uint32 y);

    /**
     * Destructor de la clase Cursor.
     */
    ~Cursor();
};

/* Métodos inline de la clase Cursor */
inline Cursor::Cursor(): Elemento() {}
inline Cursor::Cursor(const char* url, Pantalla* p):
Elemento(url, 0, 0, p) {}
inline void Cursor::setPosicion(Uint32 x, Uint32 y) {
    _posX = x;
    _posY = y;
}
inline Cursor::~Cursor() {}


/**
 * Clase que abstrae el comportamiento y la visualización de un menú básico.
 * @author Noelia Sales Montes
 * @date 28 05 2009
 * @note Parte del Proyecto NoCKt Metal
 * @see evento.h pantalla.h
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
    Menu(const char* urlFondo, const char* urlCursor, Pantalla* p);

    /**
     * Método observador de la posición actual del cursor en el menú.
     * @return Entero que se corresponde con la posición del botón activado,
     * o el valor siguiente al último en caso de error.
     */
    Uint32 getPosicionCursor() const;

    /**
     * Método observador de los botones del menú.
     * @param i Entero que se corresponde con la posición del botón en el menú.
     * @return Puntero al botón que se encuentre en la posición <code>i</code>
     * del menú.
     */
    Boton* getBoton(Uint32 i) const;

    /**
     * Método observador del número de botones del menú.
     * @return Entero que se corresponde con el número total de botones que
     * se han inicializado en el menú.
     */
    Uint32 getNumBotones() const;

    /**
     * Método observador del estado de salida del menú.
     * @return Valor lógico que es igual a <code>true</code> si el estado
     * de salida está activado; <code>false</code> en caso contrario.
     */
    bool getEstadoSalida() const;
    /**
     * Método observador del estado de aceptación del menú.
     * @return Valor lógico que es igual a <code>true</code> si el estado
     * de aceptación está activado; <code>false</code> en caso contrario.
     */
    bool getEstadoAceptado() const;

    /**
     * Método modificador que inicializa un nuevo menú.
     * @param mensaje Mensaje asociado al botón.
     * @param posx Posición horizontal del botón en la pantalla.
     * @param posy Posición vertical del botón en la pantalla.
     * @param url Ruta a la imagen que representa al botón.
     * @param espacioX Margen horizontal interior del botón.
     * @param espacioY Margen vertical interior del botón.
     */
    void setBoton(const char* mensaje, Uint32 posx, Uint32 posy,
		  const char* url, Uint32 espacioX, Uint32 espacioY, 
		  const char* urlFont = "fuentes/FontMenu.ttf", 
		  Uint32 tamFont = 19);
    /**
     * Método que dibuja el estado actual del menú en la pantalla.
     */
    void dibujar();
    /**
     * Método que espera hasta la captura de un evento para realizar
     * la operación que corresponda (mover el cursor, etc).
     * @return Valor lógico que es <code>true</code> en caso de que
     * se haya elegido aceptar una opción o salir del menú.
     * @note Para averiguar cuál de las dos se ha elegido se debe
     * comprobar el estado de salida y el estado de aceptación.
     */
    bool actualizar();

    /**
     * Destructor de la clase Menu.
     */
    virtual ~Menu();

protected:

    /**
     * Método auxiliar que modifica la posición del cursor, retrocediendo
     * su posición hasta el botón anterior.
     * @note En caso de encontrarse el cursor en el primer botón se trasladaría
     * hasta el último botón (movimiento circular).
     * @return Entero que se corresponde con la nueva posición del cursor para
     * realizar las comprobaciones necesarias.
     */
    Uint32 retrocederCursor();

    /**
     * Método auxiliar que modifica la posición del cursor, avanzando
     * su posición hasta el botón siguiente.
     * @note En caso de encontrarse el cursor en el último botón se trasladaría
     * hasta el primer botón (movimiento circular).
     * @return Entero que se corresponde con la nueva posición del cursor para
     * realizar las comprobaciones necesarias.
     */
    Uint32 avanzarCursor();

    /**
     * Superficie de la librería SDL donde se almacena la imagen de fondo del
     * menú.
     */
    SDL_Surface* _fondo;

    /**
     * Puntero a la pantalla general del juego.
     */
    Pantalla* _pant;
    /**
     * Objeto de la clase evento que controlará las acciones solicitadas por el
     * usuario.
     */
    Evento _evento;
    /**
     * Botón actual que está activado.
     */
    Uint32 _botonActivo;
    /**
     * Número total de botones.
     * Debe coincidir con el tamaño de <code>_botones</code>.
     */
    Uint32 _numBotones;

    /**
     * Diccionario que asocia cada botón con un código de orden a partir
     * del cual se puede llegar a él.
     */
    map<Uint32, Boton*> _botones;

    /**
     * Puntero al cursor del menú.
     */
    Cursor* _cursor;

    /**
     * Valor lógico que se encuentra a <code>true</code> si se ha activado
     * la salida del menú; <code>false</code> en caso contrario.
     */
    bool _estadoSalida;
    /**
     * Valor lógico que se encuentra a <code>true</code> si se ha activado
     * la selección de la opcioń actual; <code>false</code> en caso contrario.
     */
    bool _estadoAceptado;
};

/* Métodos inline de la clase Menu */
inline Menu::Menu() {}
inline Uint32 Menu::getPosicionCursor() const { return _botonActivo; }
inline Boton* Menu::getBoton(Uint32 i) const { return _botones.at(i); }
inline Uint32 Menu::getNumBotones() const { return _numBotones; }
inline bool Menu::getEstadoSalida() const { return _estadoSalida; }
inline bool Menu::getEstadoAceptado() const { return _estadoAceptado; }
inline Menu::~Menu() {}

#endif	/* _MENU_H */
