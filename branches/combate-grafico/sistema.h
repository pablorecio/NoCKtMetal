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
 * Fichero: sistema.h
 * Autor: Noelia Sales Montes
 * Fecha: 29 de abril de 2009
 * Proyecto: NoCKt Metal
 */

#ifndef _SISTEMA_H
#define	_SISTEMA_H

/**
 * Inicia el sistema SDL mínimo (audio y video) si no se pasan parámetros.
 * En caso de incluir parámetros, cada uno de ellos es un valor lógico que
 * identifica la activación (<code>true</code>) o no (<code>false</code>) de
 * cada subsistema de la SDL.
 * @param video Valor lógico que indica la activación del subsistema de video.
 * Por defecto, su valor es <code>true</code>.
 * @param video Valor lógico que indica la activación del subsistema de audio.
 * Por defecto, su valor es <code>true</code>.
 * @param video Valor lógico que indica la activación del subsistema de tiempo.
 * Por defecto, su valor es <code>false</code>.
 * @param video Valor lógico que indica la activación del subsistema de cd.
 * Por defecto, su valor es <code>false</code>.
 * @param video Valor lógico que indica la activación del subsistema de joystick.
 * Por defecto, su valor es <code>false</code>.
 * @note El porqué de los subsistemas que se activan o no por defecto es
 * simplemente por la usabilidad en nuestros motores: no utilizamos los
 * subsistemas de tiempo, cd o joystick.
 */
bool iniciarSistema(bool video = true, bool audio = true, bool tiempo = false,
                    bool cd = false, bool joystick = false);

/**
 * Inicia el subsistema de Video de la SDL.
 * @note Se presupone activado el sistema SDL anteriormente.
 */
void iniciarSubsistemaVideo();

/**
 * Inicia el subsistema de audio de la SDL.
 * @note Se presupone activado el sistema SDL anteriormente.
 */
void iniciarSubsistemaAudio();

/**
 * Inicia el subsistema de tiempo de la SDL.
 * @note Se presupone activado el sistema SDL anteriormente.
 */
void iniciarSubsistemaTiempo();

/**
 * Inicia el subsistema de CD de la SDL.
 * @note Se presupone activado el sistema SDL anteriormente.
 */
void iniciarSubsistemaCD();

/**
 * Inicia el subsistema de joystick de la SDL.
 * @note Se presupone activado el sistema SDL anteriormente.
 */
void iniciarSubsistemaJoystick();

/**
 * Inicia el sistema TTF para escritura de fuentes en pantalla, si no estaba
 *  activo ya.
 */
void iniciarTTF();

#endif	/* _SISTEMA_H */

