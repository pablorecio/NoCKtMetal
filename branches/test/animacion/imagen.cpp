
#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include <cmath>
#include <map>

#include "tile.h"
#include "imagen.h"
#include "pantalla.h"

using namespace std;


Imagen::Imagen(){}

Imagen::Imagen(Uint32 ancho, Uint32 alto, Pantalla* p, Uint32** matriz_tiles,
	       Uint32** matriz_col, Uint32** matriz_inter ):
_alto(alto), _ancho(ancho), _cX(0), _cY(0), _p(p) {

  if(matriz_tiles != NULL){
    _matrizOriginal= (Uint32**)malloc(sizeof(Uint32)*ancho);
    for(Uint32 i=0; i<ancho; i++)
      _matrizOriginal[i]=(Uint32*)malloc(sizeof(Uint32)*alto);
    
    for(Uint32 i=0; i<ancho; i++)
      for(Uint32 j=0; j<alto; j++)
	_matrizOriginal[i][j] = matriz_tiles[i][j];
    
  }
  
  if(matriz_col != NULL){
    _matrizColision= (Uint32**)malloc(sizeof(Uint32)*ancho);
    for(Uint32 i=0; i<ancho; i++)
      _matrizColision[i]=(Uint32*)malloc(sizeof(Uint32)*alto);
    
    for(Uint32 i=0; i<ancho; i++)
      for(Uint32 j=0; j<alto; j++)
	_matrizColision[i][j] = matriz_col[i][j];
  }

  if(matriz_inter != NULL){
    _matrizInteractual= (Uint32**)malloc(sizeof(Uint32*)*ancho);
    for(Uint32 i=0; i<ancho; i++)
      _matrizInteractual[i]=(Uint32*)malloc(sizeof(Uint32)*alto);
    
    for(Uint32 i=0; i<ancho; i++)
      for(Uint32 j=0; j<alto; j++)
	_matrizInteractual[i][j] = matriz_inter[i][j];
  }

  

}

Imagen::Imagen(map<Uint32,Tile*> imagenes, Uint32 ancho, Uint32 alto, 
       Uint32** matriz_tiles, Uint32** matriz_col, 
       Uint32** matriz_inter){

  _ancho=ancho;
  _alto=alto;

  _cX=0;
  _cY=0;

  _tiles = imagenes;

  if(matriz_tiles != NULL){
    _matrizOriginal= (Uint32**)malloc(sizeof(Uint32)*ancho);
    for(Uint32 i=0; i<ancho; i++)
      _matrizOriginal[i]=(Uint32*)malloc(sizeof(Uint32)*alto);
    
    for(Uint32 i=0; i<ancho; i++)
      for(Uint32 j=0; j<alto; j++)
	_matrizOriginal[i][j] = matriz_tiles[i][j];
    
  }
  
  if(matriz_col != NULL){
    _matrizColision= (Uint32**)malloc(sizeof(Uint32)*ancho);
    for(Uint32 i=0; i<ancho; i++)
      _matrizColision[i]=(Uint32*)malloc(sizeof(Uint32)*alto);
    
    for(Uint32 i=0; i<ancho; i++)
      for(Uint32 j=0; j<alto; j++)
	_matrizColision[i][j] = matriz_col[i][j];
  }

  if(matriz_inter != NULL){
    _matrizInteractual= (Uint32**)malloc(sizeof(Uint32)*ancho);
    for(Uint32 i=0; i<ancho; i++)
      _matrizInteractual[i]=(Uint32*)malloc(sizeof(Uint32)*alto);
    
    for(Uint32 i=0; i<ancho; i++)
      for(Uint32 j=0; j<alto; j++)
	_matrizInteractual[i][j] = matriz_inter[i][j];
  }
}

void Imagen::relacionarTile(Uint32 id, Tile& t){
  _tiles.insert(make_pair(id,&t));
}

void Imagen::relacionarPantalla(Pantalla& p)
{
  _p = &p;
}

void Imagen::setMatriz(Uint32 ancho, Uint32 alto, Uint32** matriz, 
		       Uint32** colisionable, Uint32** interactuable){
  _ancho=ancho;
  _alto=alto;
  
  _matrizOriginal= (Uint32**)malloc(sizeof(Uint32)*ancho);
  for(Uint32 i=0; i<ancho; i++)
    _matrizOriginal[i]=(Uint32*)malloc(sizeof(Uint32)*alto);
  
  for(Uint32 i=0; i<ancho; i++)
    for(Uint32 j=0; j<alto; j++)
      _matrizOriginal[i][j] = matriz[i][j];
  
  if(colisionable != NULL){
    _matrizColision= (Uint32**)malloc(sizeof(Uint32)*ancho);
    for(Uint32 i=0; i<ancho; i++)
      _matrizColision[i]=(Uint32*)malloc(sizeof(Uint32)*alto);
    
    for(Uint32 i=0; i<ancho; i++)
      for(Uint32 j=0; j<alto; j++)
	_matrizColision[i][j] = colisionable[i][j];
  }

  if(interactuable != NULL){
    _matrizInteractual= (Uint32**)malloc(sizeof(Uint32)*ancho);
    for(Uint32 i=0; i<ancho; i++)
      _matrizInteractual[i]=(Uint32*)malloc(sizeof(Uint32)*alto);
    
    for(Uint32 i=0; i<ancho; i++)
      for(Uint32 j=0; j<alto; j++)
	_matrizInteractual[i][j] = interactuable[i][j];
  }
    
  
}

  // Conviete la matriz completa en el dibujo con tiles sobre una Surface.
  // Necesitamos saber desde que coordenada de la matriz completa comenzamos
  // a dibujar. El final/tamaño nos lo proporciona la Surface.


void Imagen::dibujarFondo(Sint32 cx, Sint32 cy, Uint32 Secuencia, 
			       Uint32 vez){

  SDL_Rect origen, destino;

  double trozo_dibujo = Secuencia/vez;

  origen.x=0;
  origen.y=0;

  origen.h=_Tam_Tile * trozo_dibujo;
  origen.w=_Tam_Tile * trozo_dibujo;

  _cX=cx * trozo_dibujo;
  _cY=cy * trozo_dibujo;

  Uint32 ancho_aux=_p->getAncho();
  Uint32 alto_aux=_p->getAlto();

  Uint32 aux_h = _cX+(_p->getFondo()->h/_Tam_Tile); 
  // número de tiles de la pantalla (alto) + coordY
  Uint32 aux_w = _cY+(_p->getFondo()->w/_Tam_Tile); 
  // número de tiles de la pantalla (ancho) + coordX

  for(Uint32 i=_cX; (i<aux_w && i<_ancho); i++)
    for(Uint32 j=_cY;(j<aux_h && j<_alto); j++){      
      destino.x=((i-_cX)*_Tam_Tile) * trozo_dibujo;
      destino.y=((j-_cY)*_Tam_Tile) * trozo_dibujo;
      
      SDL_BlitSurface((_tiles.at(_matrizOriginal[i][j]))->getImagen(), 
		      &origen, _p->getFondo(), &destino);
      
    }
  cout << "PREVOLCADO" << endl;
  _p->volcarPantalla(_p->getFondo(), _p->getBuffer());
  cout << "POSTVOLCADO" << endl;
}

  // TODO: hacer que los bordes (arriba y izquierda) también salgan en negro
  // cuando se necesite, es decir, por ejemplo, cuando el muñeco quiera acceder
  // hasta el límite superior del mapa
