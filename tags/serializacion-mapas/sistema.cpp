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
 * Fichero: sistema.cpp
 * Autor: Noelia Sales Montes
 * Fecha: 29 de abril de 2009
 * Proyecto: NoCKt Metal
 */

#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

#include "sistema.h"

using namespace std;

bool iniciarSistema(bool video, bool audio, bool tiempo, bool cd,
                    bool joystick) {
    bool iniciado = false;

    /* Al iniciar el sistema SDL, definir que se desactive el sistema en
     * caso de salir mediante un exit */
    atexit(SDL_Quit);

    Uint32 flagVideo = 0, flagAudio = 0, flagTiempo = 0, flagCD = 0,
           flagJoy = 0;

    if (video) {
        flagVideo = SDL_INIT_VIDEO;
    }
    if (audio) {
        flagAudio = SDL_INIT_AUDIO;
    }
    if (tiempo) {
        flagTiempo = SDL_INIT_TIMER;
    }
    if (cd) {
        flagCD = SDL_INIT_CDROM;
    }
    if (joystick) {
        flagJoy = SDL_INIT_JOYSTICK;
    }

    /* Iniciar SDL: modo video */
    if (SDL_Init(flagVideo|flagAudio|flagTiempo|flagCD|flagJoy) < 0) {
        cerr << "No se pudo iniciar SDL: " << SDL_GetError() << endl;
        exit(1);
    } else {
        iniciado = true;
        cout << "INICIADO" << endl;
    }
    return iniciado;
}

void iniciarSubsistemaVideo() {
    /* Inicializamos el video */
    if (SDL_InitSubSystem(SDL_INIT_VIDEO) < 0) {
        cerr << "No se puede iniciar el video: %s\n" << SDL_GetError() << endl;
        exit(1);
    }
}

void iniciarSubsistemaAudio() {
    /* Inicializamos el audio */
    if (SDL_InitSubSystem(SDL_INIT_AUDIO) < 0) {
        cerr << "No se puede iniciar el audio: %s\n" << SDL_GetError() << endl;
        exit(1);
    }
}

void iniciarSubsistemaTiempo() {
    /* Inicializamos el TIMER */
    if (SDL_InitSubSystem(SDL_INIT_TIMER) < 0) {
        cerr << "No se puede iniciar el timer: %s\n" << SDL_GetError() << endl;
        exit(1);
    }
}

void iniciarSubsistemaCD() {
    /* Inicializamos el CD-ROM */
    if (SDL_InitSubSystem(SDL_INIT_CDROM) < 0) {
        cerr << "No se puede iniciar el cdrom: %s\n" << SDL_GetError() << endl;
        exit(1);
    }
}

void iniciarSubsistemaJoystick() {
    /* Inicializamos el joystick */
    if (SDL_InitSubSystem(SDL_INIT_JOYSTICK) < 0) {
        cerr << "No se puede iniciar el joystick: %s\n" << SDL_GetError()
                << endl;
        exit(1);
    }
}

void iniciarTTF() {
	/* Iniciamos el sistema TTF si no estaba activo ya */
    if(!TTF_WasInit() && TTF_Init()==-1) {
    	cout << "TTF_Init: %s\n" << TTF_GetError() << endl;
    	exit(2);
    }
}
