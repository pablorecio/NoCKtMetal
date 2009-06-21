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
 * @brief Clase que abstrae el comportamiento de la ventana principal del 
 * videojuego.
 * Se compone de una ventana principal, así como de múltiples superficies
 * empleadas como <i>buffers</i>.
 * @author Noelia Sales Montes
 * @date 18 de abril de 2009
 * @note Parte del Proyecto NoCKt Metal
 */
class Pantalla {
 public:
    /**
     * Constructor de la clase Pantalla.
     * @param ancho Ancho de la pantalla.
     * @param alto Alto de la pantalla.
     * @param prof Profundidad de la pantalla.
     */
    Pantalla(Uint32 ancho = 480, Uint32 alto = 360, Uint32 prof = 24);

    /**
     * Método observador del <i>buffer</i> principal de nuestra pantalla.
     * Todo lo que se desee mostrar por pantalla debe ser dibujado primero
     * en este buffer y posteriormente volcado a la pantalla principal.
     * @return Puntero a <code>SDL_Surface</code> que representa el buffer.
     */
    SDL_Surface* getBuffer() const;
    /**
     * Método observador de la pantalla donde se gestiona el fondo.
     * @return Puntero a la <code>SDL_Surface</code> que representa el
     * fondo.
     */
    SDL_Surface* getFondo() const;
    /**
     * Método observador de la pantalla donde se gestiona el movimiento.
     * @return Puntero a la<code>SDL_Surface</code> que representa el 
     * movimiento de elementos.
     */
    SDL_Surface* getMovimiento() const;
    /**
     * Método observador del ancho de la ventana principal.
     * @return Entero coincidente con el ancho de la ventana principal.
     */
    Uint32 getAncho() const;
    /**
     * Método observador del alto de la ventana principal.
     * @return Entero coincidente con el alto de la ventana principal.
     */
    Uint32 getAlto() const;
    /**
     * Método observador de la profundidad de la ventana principal.
     * @return Entero coincidente con la profundidad de la ventana principal.
     */
    Uint32 getProf() const;

    /**
     * Método modificador que configura el título de nuestra ventana, así como
     * el icono que la representará.
     * @param titulo Cadena de caracteres de bajo nivel que se corresponde
     * con el título.
     * @param icono Cadena de caracteres de bajo nivel que se corresponde
     * con la ruta (relativa preferiblemente), donde se encuentra el icono que se
     * desea asociar a la ventana.
     */
    void setTitulo(const char *titulo, const char *icono);
    /**
     * Método modificador que carga una imagen en una pantalla determinada.
     * @param p Puntero a la pantalla (<code>SDL_Surface</code>) que se
     * desea modificar.
     * @param imagen Cadena de caracteres de bajo nivel que se corresponde
     * con la ruta (relativa preferiblemente) donde se encuentra la imagen que
     * se desea cargar en <code>p</code>.
     */
    void cargarImagen(SDL_Surface *p, const char *imagen);

    /**
     * Método modificador que rellena una pantalla completa de un color
     * determinado.
     * @param p Puntero a la pantalla (<code>SDL_Surface</code>) que se desea
     * modificar.
     * @param colorR Entero que representa la máscara de color Rojo.
     * @param colorG Entero que representa la máscara de color Verde.
     * @param colorB Entero que representa la máscara de color Azul.
     * @param colorA Entero que representa la máscara de transparencia.
     */
    void rellenarPantalla(SDL_Surface *p, Uint32 colorR = 255,
                          Uint32 colorG = 255, Uint32 colorB = 255,
                          Uint32 colorA = 0);

    
    /**
     * Tomaremos una SDL_Surface vacía y la volcaremos en el
     * 'Buffer' que nos pasen por parámetro.
     * @param buffer Es un tipo SDL_Surface que queremos limpiar.
     */
    void limpiarBuffer(SDL_Surface* buffer);

    /**
     * Método modificador que copia el contenido de una pantalla en nuestra
     * pantalla principal.
     * @param p1 Puntero a la pantalla (<code>SDL_Surface</code>) que se 
     * desea volcar.
     */
    void volcarPantalla(SDL_Surface *p1);
    /**
     * Método modificador que copia un trozo del contenido de una pantalla en
     * nuestra pantalla principal.
     * @param p1 Puntero a la pantalla (<code>SDL_Surface</code>) que se
     * desea volcar.
     * @param rectP2 Trozo de pantalla (<code>SDL_Rect</code>) que se
     * copiará.
     */
    void volcarPantalla(SDL_Surface *p1, SDL_Rect *rectP2);
    /**
     * Método modificador que copia el contenido de una pantalla
     * (<code>SDL_Surface</code>) en otra.
     * @param p1 Puntero a la pantalla (<code>SDL_Surface</code>) que se
     * desea volcar.
     * @param p2 Puntero a la pantalla (<code>SDL_Surface</code>) que se 
     * va a ver modificada.
     */
    void volcarPantalla(SDL_Surface *p1, SDL_Surface *p2);
    void volcarPantalla(SDL_Surface *p1, SDL_Rect *rectP1, SDL_Surface *p2,
                        SDL_Rect *rectP2);

    /**
     * Método que se encarga de finalizar de forma segura el funcionamiento
     * de nuestra pantalla, así como de salir del sistema de SDL.
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
     * Puntero a la pantalla de <i>buffer</i> principal, que modificaremos
     * antes de volcar a <code>_pantalla</code>.
     */
    SDL_Surface* _buffer;
    /**
     * Puntero a la pantalla de fondo donde se dibuja el escenario (suelo
     * en nuestro caso, formado por imágenes denominadas <i>tiles</i>).
     */
    SDL_Surface* _fondo;
    /**
     * Puntero a la pantalla de movimiento, donde se dibuja el comportamiento
     * dinámico de determinados elementos.
     * @note En principio se creía oportuno mantener esta superficie para 
     * dedicarla al movimiento de los <i>sprites</i>; sin embargo, esto no 
     * resulta conveniente, por lo que se dedicará al movimiento de menús si 
     * fuera posible.     
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

/* Métodos inline */
inline SDL_Surface* Pantalla::getBuffer() const { return _buffer; }
inline SDL_Surface* Pantalla::getFondo() const { return _fondo; }
inline SDL_Surface* Pantalla::getMovimiento() const { return _movimiento; }
inline Uint32 Pantalla::getAncho() const { return _ancho; }
inline Uint32 Pantalla::getAlto() const { return _alto; }
inline Uint32 Pantalla::getProf() const { return _prof; }

#endif
