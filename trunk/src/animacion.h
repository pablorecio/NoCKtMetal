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
 * Fichero: animacion.h
 * Autor: Noelia Sales Montes
 * Fecha: 19 de abril de 2009
 * Proyecto: NoCKt Metal
 */

#ifndef _ANIMACION_H
#define	_ANIMACION_H

/*#include "evento.h"*/
#include "pantalla.h"
#include "personaje.h"
#include "imagen.h"


/**
 * @brief
 * @author Noelia Sales Montes
 * @date 19 de abril de 2009
 */
class Animacion {
public:
    Animacion();
    Animacion(const Animacion& orig);
    Pantalla* getPantalla();
    Uint32 getTamCasilla() const;
    void animandoMapa();
    virtual ~Animacion();
private:
    /* Puntero a la pantalla general del juego */
    Pantalla* _pantalla;
    /* Equivalencia de un tile en pixels */
    Uint32 _tamCasilla;
};

inline Pantalla* Animacion::getPantalla() {
    return _pantalla;
}

inline Uint32 Animacion::getTamCasilla() const {
    return _tamCasilla;
}

#endif	/* _ANIMACION_H */

