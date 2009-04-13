

#include<iostream>
#include<SDL/SDL_image.h>
#include"tile.h"

using namespace std;

Tile::Tile(char* ruta, bool col, bool inter)
{

#ifdef DEBUG
  cout << "-> Cargando" <<  ruta << endl;
#endif
  
  imagen_ = IMG_Load(ruta);
  
  if(imagen_ == NULL) {  
    cerr << "Error: " << SDL_GetError() << endl;;
    exit(1);
  }

  SDL_Surface *tmp = imagen_; 
  imagen_ = SDL_DisplayFormat(tmp);
  SDL_FreeSurface(tmp);
  if(imagen_ == NULL) {
    cerr << "Error: " << SDL_GetError() << endl;
    exit(1);
  }
  
  colorkey = SDL_MapRGB(imagen_->format, 0, 255, 0);
  SDL_SetColorKey(imagen_, SDL_SRCCOLORKEY, colorkey);

  // para saber con que tipo de tile trabajamos. 
  colisionable=col;
  interactuable=inter;
}

Tile::~Tile() 
{
  SDL_FreeSurface(imagen_);
#ifdef DEBUG    
  cout << "<- Liberando imagen" << endl;
#endif
}

int Tile::anchura()
{
  return imagen_->w;
}

int Tile::altura()
{
  return imagen_->h;
}

SDL_Surface* Tile::imagen()
{
  return imagen_;
}

bool Tile::es_colisionable()
{
  return colisionable;
}

bool Tile::es_interactuable()
{
  return interactuable;
}
