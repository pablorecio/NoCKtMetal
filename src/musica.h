// Listado: Musica.h
//
// Clase para facilitar el trabajo con la musica

#ifndef _MUSICA_H_
#define _MUSICA_H_

#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>

class Musica {

 public:

    // Constructor

    Musica(const char *ruta);

    void reproducir();
    void pausar();

    ~Musica();

 private:

    Mix_Music *bso;

};

#endif
