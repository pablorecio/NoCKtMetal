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

bool iniciarSistema(bool video = true, bool audio = true, bool tiempo = false,
                    bool cd = false, bool joystick = false, bool ttf = true);
void iniciarSubsistemaVideo();
void iniciarSubsistemaAudio();
void iniciarSubsistemaTiempo();
void iniciarSubsistemaCD();
void iniciarSubsistemaJoystick();
void iniciarSubsistemaTTF();
#endif	/* _SISTEMA_H */

