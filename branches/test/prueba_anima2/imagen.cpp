
#include <iostream>
#include <SDL/SDL_image.h>

#include <cmath>
#include <map>

#include "tile.h"
#include "imagen.h"

using namespace std;

Imagen::Imagen(Uint32 ancho, Uint32 alto){
  _alto=alto; 
  _ancho=ancho;
  
  _cX=0; 
  _cY=0;
  
  _matrizOriginal=NULL;
}


Imagen::Imagen(Uint32 ancho, Uint32 alto, Uint32 **matriz_completa){
  _matrizOriginal= (Uint32**)malloc(sizeof(Uint32)*ancho);
  for(Uint32 i=0; i<ancho; i++)
    _matrizOriginal[i]=(Uint32*)malloc(sizeof(Uint32)*alto);

  for(int i=0; i<ancho; i++)
    for(int j=0; j<alto; j++)
      _matrizOriginal[i][j] = matriz_completa[i][j];
  
  _alto=alto; 
  _ancho=ancho;
  
  _cX=0; 
  _cY=0;
}
  
  // creamos un objeto imagen a partir de los tamaños y los tiles.
Imagen::Imagen(Uint32 ancho, Uint32 alto, Uint32** matriz_completa, 
	       std::map<Uint32,Tile> imagenes){
  _tiles=imagenes;
  
  _alto=alto; 
  _ancho=ancho;
  
  _cX=0; 
  _cY=0;

  _matrizOriginal= (Uint32**)malloc(sizeof(Uint32)*ancho);
  for(Uint32 i=0; i<ancho; i++)
    _matrizOriginal[i]=(Uint32*)malloc(sizeof(Uint32)*alto);

  for(int i=0; i<ancho; i++)
    for(int j=0; j<alto; j++)
      _matrizOriginal[i][j] = matriz_completa[i][j];

}

  // se introducirá en el final del vector.
  // hay que tener en cuenta los índices para luego poder 
  // realizar la imagen correctamente.


void Imagen::relacionarTile(Uint32 id, Tile t){
  _tiles.insert(make_pair(id,t));
}

void Imagen::setMatriz(Uint32 ancho, Uint32 alto, Uint32** matriz){
  _ancho=ancho;
  _alto=alto;

   _matrizOriginal= (Uint32**)malloc(sizeof(Uint32)*ancho);
  for(Uint32 i=0; i<ancho; i++)
    _matrizOriginal[i]=(Uint32*)malloc(sizeof(Uint32)*alto);

  for(int i=0; i<ancho; i++)
    for(int j=0; j<alto; j++)
      _matrizOriginal[i][j] = matriz[i][j];
  
  
}

  // Conviete la matriz completa en el dibujo con tiles sobre una Surface.
  // Necesitamos saber desde que coordenada de la matriz completa comenzamos
  // a dibujar. El final/tamaño nos lo proporciona la Surface.


void Imagen::dibujarFondo(Sint32 cx, Sint32 cy, SDL_Surface *pantalla){

  SDL_Rect origen,destino;

  _cX=cx;
  _cY=cy;

  origen.x=0;
  origen.y=0;

  origen.h=_Tam_Tile;
  origen.w=_Tam_Tile;

  Uint32 aux_h = _cY+(pantalla->h/_Tam_Tile); // número de tiles de la pantalla (alto) + coordY
  Uint32 aux_w = _cX+(pantalla->w/_Tam_Tile); // número de tiles de la pantalla (ancho) + coordX
  
  for(Uint32 i=_cX; i<aux_w && i<_ancho; i++)
    for(Uint32 j=_cY; j<aux_h && j<_alto; j++){
      
      destino.x=(i-_cX)*_Tam_Tile;
      destino.y=(j-_cY)*_Tam_Tile;
      
      SDL_BlitSurface((_tiles.at(_matrizOriginal[i][j])).getImagen(), 
		      &origen, pantalla, &destino);
      
    }  
}

  // TODO: hacer que los bordes (arriba y izquierda) también salgan en negro
  // cuando se necesite, es decir, por ejemplo, cuando el muñeco quiera acceder
  // hasta el límite superior del mapa
