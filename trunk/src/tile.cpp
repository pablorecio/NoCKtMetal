
#include<iostream>
#include<SDL/SDL_image.h>
#include"tile.h"

using namespace std;

Tile::Tile(char *ruta, bool col, bool inter){

#ifdef DEBUG
  cout << "-> Cargando" <<  ruta << endl;
#endif
  
  _imagen = IMG_Load(ruta);
  
  if(_imagen == NULL) {  
    cerr << "Error: " << SDL_GetError() << endl;;
    exit(1);
  }

  SDL_Surface *tmp = _imagen; 
  _imagen = SDL_DisplayFormat(tmp);
  SDL_FreeSurface(tmp);

  if(_imagen == NULL) {
    cerr << "Error: " << SDL_GetError() << endl;
    exit(1);
  }
  
  _colorkey = SDL_MapRGB(_imagen->format, 0, 255, 0);
  SDL_SetColorKey(_imagen, SDL_SRCCOLORKEY, _colorkey);

  // para saber con que tipo de tile trabajamos. 
  _colisionable=col;
  _interactuable=inter;
}

Tile::~Tile() {

  SDL_FreeSurface(_imagen);
#ifdef DEBUG    
  cout << "<- Liberando imagen" << endl;
#endif
}

Uint32 Tile::getAnchura() {
  return _imagen->w;
}

Uint32 Tile::getAltura() {
  return _imagen->h;
}

SDL_Surface* Tile::getImagen() {
  return _imagen;
}

bool Tile::isColisionable() {
  return _colisionable;
}

bool Tile::isInteractuable() {
  return _interactuable;
}
