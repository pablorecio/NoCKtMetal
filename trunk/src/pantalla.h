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
 * Fichero: pantalla.h
 * Autor: Noelia Sales Montes
 * Fecha: 18 04 2009
 * Proyecto: NoCKt Metal
 */

#ifndef _PANTALLA_
#define _PANTALLA_

#include "SDL/SDL.h"

/**
 * @brief Pantalla
 * @author Noelia Sales Montes
 * @date 18 04 2009
 */
class Pantalla {
 public:
    /**
     * Constructor de la clase Pantalla
     * @param ancho Ancho de la pantalla
     * @param alto Alto de la pantalla
     * @param prof Profundidad de la pantalla
     */
    Pantalla(Uint32 ancho = 480, Uint32 alto = 360, Uint32 prof = 24);

    /**
     * Metodo observador del buffer de nuestra pantalla
     * @return Puntero a <code>SDL_Surface*</code> que representa el buffer
     */
    SDL_Surface* getBuffer() const;
    /**
     * Metodo observador de la pantalla donde se gestiona el fondo
     * @return Puntero a <code>SDL_Surface*</code> que representa el fondo
     */
    SDL_Surface* getFondo() const;
    /**
     * Metodo observador de la pantalla donde se gestiona el movimiento
     * @return Puntero a <code>SDL_Surface*</code> que representa el movimiento
     * de personajes
     */
    SDL_Surface* getMovimiento() const;
    /**
     * Metodo observador del ancho
     * @return Entero coincidente con el ancho de la pantalla principal
     */
    Uint32 getAncho() const;
    /**
     * Metodo observador del alto
     * @return Entero coincidente con el alto de la pantalla principal
     */
    Uint32 getAlto() const;
    /**
     * Metodo observador de la profundidad
     * @return Entero coincidente con la profundidad de la pantalla principal
     */
    Uint32 getProf() const;

    /**
     * Metodo modificador que configura el titulo de nuestra ventana, asi como
     * el icono que la representara.
     * @param titulo Cadena de caracteres de bajo nivel que se corresponde con
     * el titulo.
     * @param icono Cadena de caracteres de bajo nivel que se corresponde con
     * la ruta (relativa preferiblemente) donde se encuentra el icono que se
     * desea asociar a la ventana.
     */
    void setTitulo(const char *titulo, const char *icono);
    /**
     * Metodo modificador que carga una imagen en una pantalla determinada.
     * @param p Puntero a la pantalla (<code>SDL_Surface</code>) que se desea
     * modificar.
     * @param imagen Cadena de caracteres de bajo nivel que se corresponde
     * la ruta (relativa preferiblemente) donde se encuentra la imagen que se
     * desea cargar en <code>p</code>.
     */
    void cargarImagen(SDL_Surface *p, const char *imagen);
    /**
     * Metodo modificador que rellena una pantalla completa de un color
     * determinado.
     * @param p Puntero a la pantalla (<code>SDL_Surface</code>) que se desea
     * modificar.
     * @param colorR Entero que representa la mascara de color Rojo.
     * @param colorG Entero que representa la mascara de color Verde.
     * @param colorB Entero que representa la mascara de color Azul.
     * @param colorA Entero que representa la mascara de transparencia.
     */
    void rellenarPantalla(SDL_Surface *p, Uint32 colorR = 255,
                          Uint32 colorG = 255, Uint32 colorB = 255,
                          Uint32 colorA = 0);

    /**
     * Metodo modificador que copia el contenido de una pantalla en nuestra
     * pantalla principal.
     * @param p1 Puntero a la pantalla (<code>SDL_Surface</code>) que se desea
     * volcar.
     */
    void volcarPantalla(SDL_Surface *p1);
    /**
     * Metodo modificador que copia un trozo del contenido de una pantalla en
     * nuestra pantalla principal.
     * @param p1 Puntero a la pantalla (<code>SDL_Surface</code>) que se desea
     * volcar.
     * @param p2 Trozo de pantalla (<code>SDL_Rect</code>) que se copiara.
     */
    void volcarPantalla(SDL_Surface *p1, SDL_Rect *rectP2);
    /**
     * Metodo modificador que el contenido de una pantalla
     * (<code>SDL_Surface</code>) en otra.
     * @param p1 Puntero a la pantalla (<code>SDL_Surface</code>) que se desea
     * volcar.
     * @param p2 Trozo de pantalla (<code>SDL_Rect</code>) que se copiara.
     */
    void volcarPantalla(SDL_Surface *p1, SDL_Surface *p2);

    /**
     * Metodo que se encarga de finalizar de forma segura el funcionamiento
     * de nuestra pantalla, asi como de salir del sistema de SDL.
     */
    void cerrarPantalla();
    /**
     * Destructor de la clase Pantalla.
     * <b>No se recomienda su uso a menos que sea estrictamente necesario.
     * SI NO ENTIENDES LO QUE ESTAS HACIENDO, POR FAVOR, UTILIZA LA FUNCION
     * <i>cerrarPantalla()</i></b>
     * @see cerrarPantalla()
     */
    ~Pantalla();
 private:

    /**
     * Ventana de visualización.
     * Puntero a una <code>SDL_Surface</code> especial, que se muestra
     * permanentemente por pantalla.
     */
    SDL_Surface* _pantalla;
    /**
     * Puntero a la pantalla de buffer donde dibujaremos antes de volcar a
     * <code>_pantalla</code>.
     */
    SDL_Surface* _buffer;
    /**
     * Puntero a la pantalla de fondo donde se dibujan el escenario (suelo
     * en nuestro caso, formado por imagenes denominadas <i>tiles</i>).
     */
    SDL_Surface* _fondo;
    /**
     * Puntero a la pantalla de movimiento, donde se dibuja el comportamiento
     * dinamico de los personajes (dado en funcion de imagenes denominadas
     * <i>sprites</i>).
     */
    SDL_Surface* _movimiento;
    /**
     * Entero que representa el ancho de la pantalla principal.
     */
    Uint32 _ancho;
    /**
     * Entero que representa el anto de la pantalla principal.
     */
    Uint32 _alto;
    /**
     * Entero que representa la profundidado de la pantalla principal.
     */
    Uint32 _prof;
};

/* Metodos inline */
inline SDL_Surface* Pantalla::getBuffer() const { return _buffer; }
inline SDL_Surface* Pantalla::getFondo() const { return _fondo; }
inline SDL_Surface* Pantalla::getMovimiento() const { return _movimiento; }
inline Uint32 Pantalla::getAncho() const { return _ancho; }
inline Uint32 Pantalla::getAlto() const { return _alto; }
inline Uint32 Pantalla::getProf() const { return _prof; }

#endif
