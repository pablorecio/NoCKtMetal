

#ifndef _TILE_H_
#define _TILE_H_

#include <SDL/SDL.h>

class Tile{
 public:
  Tile(char* ruta, bool col=false, bool inter=false);
  ~Tile();
  int anchura();
  int altura();
  SDL_Surface* imagen();
  
  bool es_colisionable();
  bool es_interactuable();

 private:
  SDL_Surface *imagen_;
  Uint32 colorkey;
  bool colisionable;
  bool interactuable;
};

#endif
