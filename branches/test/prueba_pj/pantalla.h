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
     * @brief Constructor de la clase Pantalla
     * @param ancho Ancho de la pantalla
     * @param alto Alto de la pantalla
     * @param prof Profundidad de la pantalla
     */
    Pantalla(Uint32 ancho = 480, Uint32 alto = 360, Uint32 prof = 24);
    /**
     *
     */
    SDL_Surface* getBuffer() const;
    SDL_Surface* getFondo() const;
    SDL_Surface* getMovimiento() const;
    Uint32 getAncho() const;
    Uint32 getAlto() const;
    Uint32 getProf() const;
    void setTitulo(const char *titulo, const char *icono);
    void cargarImagen(SDL_Surface *p, const char *imagen);
    void rellenarPantalla(SDL_Surface *p, Uint32 colorR = 255,
                          Uint32 colorG = 255, Uint32 colorB = 255,
                          Uint32 colorA = 0);
    void volcarPantalla(SDL_Surface *p1);
    void volcarPantalla(SDL_Surface *p1, SDL_Rect *rectP2);
    void volcarPantalla(SDL_Surface *p1, SDL_Surface *p2);
    void cerrarPantalla();
    ~Pantalla();
 private:
    /**
     * Ventana de visualización: será una SDL_Surface especial, donde lo que
     * dibujemos se mostrará por pantalla.
     */
    SDL_Surface* _pantalla;
    /**
     * Buffer donde dibujaremos antes de volcar a <code>pantalla_</code>
     */
    SDL_Surface* _buffer;
    /**
     * Fondo donde se dibujan los tiles
     */
    SDL_Surface* _fondo;
    SDL_Surface* _movimiento;
    Uint32 _ancho;
    Uint32 _alto;
    Uint32 _prof;
};

inline SDL_Surface* Pantalla::getBuffer() const { return _buffer; }
inline SDL_Surface* Pantalla::getFondo() const { return _fondo; }
inline SDL_Surface* Pantalla::getMovimiento() const { return _movimiento; }
inline Uint32 Pantalla::getAncho() const { return _ancho; }
inline Uint32 Pantalla::getAlto() const { return _alto; }
inline Uint32 Pantalla::getProf() const { return _prof; }

#endif
