// Listado: Sonido.cpp
//
// Implementación de la clase Música

#include <iostream>

#include "sonido.h"

using namespace std;

Sonido::Sonido(const char *ruta) {

  // Cargamos el sonido
  
  sonido = Mix_LoadWAV(ruta);
  
  if(sonido == NULL) {
    
  cerr << "Sonido " << ruta <<  " no disponible" << endl;
   exit(1);	
    
  }
  
  Mix_AllocateChannels(1);
  
#ifdef DEBUG
  cout << "Sonido cargado" << endl;
#endif

}


void Sonido::reproducir() {
  
  Mix_PlayChannel(-1, sonido, 0);

}


Sonido::~Sonido() {
    
  Mix_FreeChunk(sonido);
    
}
