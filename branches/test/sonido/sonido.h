// Listado: Sonido.h
//
// Clase para facilitar el trabajo con sonidos

#ifndef _SONIDO_H_
#define _SONIDO_H_

#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>

class Sonido {

 public:

    // Constructor

    Sonido(const char *ruta);

    void reproducir();

    
    // Destructor

    ~Sonido();

 private:

    Mix_Chunk *sonido;

};

#endif

    
