

#include <iostream>
#include <SDL/SDL_image.h>

#include <cmath>

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

  // creamos un objeto imagen a partir de la matriz completa
Imagen::Imagen(Uint32 **matriz_completa, Uint32 ancho, Uint32 alto){
  _matrizOriginal=matriz_completa;
  
  _alto=alto; 
  _ancho=ancho;
  
  _cX=0; 
  _cY=0;
}
  
  // creamos un objeto imagen a partir de los tamaños y los tiles.
Imagen::Imagen(Uint32 ancho, Uint32 alto, std::vector<Tile*> imagenes){
  _tiles=imagenes;
  
  _alto=alto; 
  _ancho=ancho;
  
  _cX=0; 
  _cY=0;
}

  // se introducirá en el final del vector.
  // hay que tener en cuenta los índices para luego poder 
  // realizar la imagen correctamente.
void Imagen::relacionarTile(Tile *t){
  _tiles.push_back(t);
}

  // Para cambiar o inicializar la matriz
void Imagen::inicializarMatrizCompleta(Uint32 **matriz, 
				       Uint32 ancho, Uint32 alto){
  _matrizOriginal=matriz;
  _alto=alto; 
  _ancho=ancho;
}

  // Conviete la matriz completa en el dibujo con tiles sobre una Surface.
  // Necesitamos saber desde que coordenada de la matriz completa comenzamos
  // a dibujar. El final/tamaño nos lo proporciona la Surface.
void Imagen::dibujarFondo(Sint32 cx, Sint32 cy, SDL_Surface *pantalla){

  SDL_Rect origen,destino;

  _cX=cx;
  _cY=cy;

  cout << "coordenadas: (" << _alto << "," << _ancho << "). ";
  cout << "coordenadas: (" << _cX << "," << _cY << ")." << endl;

  origen.x=0;
  origen.y=0;
  
  // suponemos que todos los tiles tienen el mismo tamaño.
  // TODO: poner en la clase tile una función estática que nos diga los 
  // pixeles o el tamaño de dicho tile, y lógicamente, ya que la función
  // es estática es pork todos los tiles son iguales en tamaño.
  Uint32 aux_h = _cY+(pantalla->h/_tiles[0]->altura());
  Uint32 aux_w = _cX+(pantalla->w/_tiles[0]->anchura());
  
  cout << "aux_w && aux_h: " << aux_w << " && " << aux_h << endl;
  
  for(Uint32 i=_cX; i<aux_w && i<_ancho; i++){
    for(Uint32 j=_cY; j<aux_h && j<_alto; j++){
	
	cout << "(i,j): ("<< i << "," << j <<")." << endl;
	
        origen.h = _tiles[_matrizOriginal[i][j]]->altura();
	origen.w = _tiles[_matrizOriginal[i][j]]->anchura();
	
	destino.x=(i-_cX)*(_tiles[_matrizOriginal[i][j]]->anchura());
	destino.y=(j-_cY)*(_tiles[_matrizOriginal[i][j]]->altura());
	
	SDL_BlitSurface(_tiles[_matrizOriginal[i][j]]->imagen(), 
			&origen, pantalla, &destino);

      }
  }
    
}

  // TODO: hacer que los bordes (arriba y izquierda) también salgan en negro
  // cuando se necesite, es decir, por ejemplo, cuando el muñeco quiera acceder
  // hasta el límite superior del mapa

  
Uint32 Imagen::getAlto(){ return _alto;}
Uint32 Imagen::getAncho(){ return _ancho;}
Uint32 Imagen::getCoorX(){ return _cX;}
Uint32 Imagen::getCoorY(){ return _cY;}
std::vector<Tile*> Imagen::getTiles(){ return _tiles;}
 
