// Listado: Musica.cpp
//
// Implementación de la clase Música

#include <iostream>

#include "musica.h"

using namespace std;

Musica::Musica(const char *ruta) {
    if(Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 1, 2048) < 0) {
      cerr << "Subsistema de Audio no disponible" << endl;
      exit(1);
    }
    // Cargamos la música

    bso = Mix_LoadMUS(ruta);

    if(bso == NULL) {

	cerr << "Música no disponible" << endl;
	exit(1);	

    }

    // Establecemos un volumen predeterminado

    Mix_VolumeMusic(60);

#ifdef DEBUG
    cout << "Música cargada" << endl;
#endif
    
}

void Musica::reproducir() {

   Mix_PlayMusic(bso, -1);

}


void Musica::pausar() {

    Mix_PauseMusic();

}

Musica::~Musica() {

    Mix_FreeMusic(bso);

}
