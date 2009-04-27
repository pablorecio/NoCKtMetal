
#include <iostream>
#include <iterator>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include <cmath>
#include <map>
#include <vector>

#include "tile.h"
#include "imagen.h"
#include "pantalla.h"

using namespace std;


Imagen::Imagen(){}

Imagen::Imagen(Uint32 ancho, Uint32 alto, Pantalla* p, Uint32** matriz_tiles,
	       Uint32** matriz_col, Uint32** matriz_inter ):
  _alto(alto), _ancho(ancho), _cX(0), _cY(0),_cXt(0), _cYt(0), _p(p) {

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

Imagen::Imagen(map<Uint32,Tile> imagenes, Uint32 ancho, Uint32 alto, 
       Uint32** matriz_tiles, Uint32** matriz_col, 
       Uint32** matriz_inter){

  _ancho=ancho;
  _alto=alto;

  _cX=0;
  _cY=0;

  _cXt=0;
  _cYt=0;

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
  _tiles.insert(make_pair(id,t));
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


void Imagen::dibujarFondo(){

  SDL_Rect origen, destino;

  _imagenAux = SDL_CreateRGBSurface(SDL_HWSURFACE, _ancho*Tile::getTam(),
				    _alto*Tile::getTam(), 24, 0, 0, 0, 0);
  origen.x=0; origen.y=0;
  origen.h=Tile::getTam();
  origen.w=Tile::getTam();

  destino.w= _ancho*Tile::getTam();
  destino.h= _alto*Tile::getTam();

  for(Uint32 i=0; i<destino.w; i=i+Tile::getTam())
    for(Uint32 j=0; j<destino.h; j=j+Tile::getTam()){

      destino.x=i;
      destino.y=j;
      
      cout << "(i,j): (" << i << "," << j << ")" << endl;

      Tile t = _tiles.find(_matrizOriginal[i/Tile::getTam()]
			   [j/Tile::getTam()])->second;

      SDL_BlitSurface(t.getImagen(),
      		      &origen, _imagenAux, &destino);

      cout << "dibujado" << endl;
    }

  _p->volcarPantalla(_imagenAux, _p->getFondo());

  cout << "(_cXt,_cYt): (" << _cXt << "," << _cYt << ")" << endl;
  
  _cX=_cXt*Tile::getTam();
  _cY=_cYt*Tile::getTam();

  _p->volcarPantalla(_p->getFondo(), _p->getBuffer());

}

  // TODO: hacer que los bordes (arriba y izquierda) también salgan en negro
  // cuando se necesite, es decir, por ejemplo, cuando el muñeco quiera acceder
  // hasta el límite superior del mapa

void Imagen::dibujarSecuencia(char dir, Uint32 secuencia, Uint32 veces){

  vector<Uint32> _pixels(veces);
  for(Uint32 i=0; i<veces; i++){
    _pixels.at(i)= Tile::getTam()/veces;
    if(i < Tile::getTam()%veces)
      _pixels.at(i)++;
  }

  SDL_Rect origen, destino;
  destino.x = destino.y = 0;
  origen.h = destino.h = _p->getAlto();
  origen.w = destino.w = _p->getAncho();

  switch(dir){
  case 'u': // muñeco arriba, mapa abajo.
    origen.x = _cX = _cX;
    origen.y = _cY = _cY+_pixels.at(secuencia-1);
    break;
  case 'd': // muñeco abajo, mapa arriba.
    origen.x = _cX = _cX;
    origen.y = _cY = _cY-_pixels.at(secuencia-1);
    break;
  case 'l': // muñeco a la izquierda, mapa hacia la derecha.
    origen.x = _cX = _cX - _pixels.at(secuencia-1);
    origen.y = _cY = _cY;
    break;
  case 'r': // muñeco a la derecha, mapa hacia la izquierda.
    origen.x = _cX = _cX + _pixels.at(secuencia-1);
    origen.y = _cY = _cY;
    break;
  default: break;
  }

  SDL_BlitSurface(_imagenAux, &origen, _p->getFondo(), &destino);

  _p->volcarPantalla(_p->getFondo(), _p->getBuffer());

  if(secuencia == veces){
    cout << "antes! " << _cXt << " " << _cYt << endl;

    _cXt = _cX/Tile::getTam();
    _cYt = _cY/Tile::getTam();
  
    cout << "despues! " << _cXt << " " << _cYt << endl;

    //dibujarFondo(_cXt, _cYt);
  }

}
