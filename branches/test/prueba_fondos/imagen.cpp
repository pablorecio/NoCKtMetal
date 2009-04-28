
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

Imagen::Imagen(map<Uint32,Tile> imagenes, Uint32 ancho, Uint32 alto, 
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


void Imagen::dibujarFondo(Sint32 cx, Sint32 cy, Uint32 Secuencia, 
			       Uint32 vez){

  SDL_Rect origen, destino;

  vector<Uint32> movimiento(vez);

  cout << "(mov,vez): ("<< Secuencia << "," << vez << ")." << endl;
  
  for(Uint32 i=0; i<vez; i++){
    movimiento.at(i)= Tile::getTam()*Secuencia/vez;
    if(i < Tile::getTam()%vez)
      movimiento.at(i)++;
  }

  char _mov=' ';
  if(_cX == (cx*Tile::getTam())-Tile::getTam())
    _mov='r';
  if(_cX == (cx*Tile::getTam())+Tile::getTam())
    _mov='l';
  if(_cY == (cy*Tile::getTam())-Tile::getTam())
    _mov='d';
  if(_cY == (cy*Tile::getTam())+Tile::getTam())
    _mov='u';

  
  if(Secuencia-1 == 0){
    origen.x=0; origen.y=0;
    origen.h= Tile::getTam();
    origen.w= Tile::getTam();
    
    Uint32 aux_ancho = _cX/Tile::getTam() + (_p->getAncho()/Tile::getTam()) +1;
    Uint32 aux_alto = _cY/Tile::getTam() + (_p->getAlto()/Tile::getTam()) +1;
    
    if(_cX < Tile::getTam())
      aux_ancho++;
    else
      _cX -= Tile::getTam();
    if(_cY < Tile::getTam())
      aux_alto++;
    else
      _cY -= Tile::getTam();
    
    cout << "(_cX,_cY): (" << _cX << "," << _cY << ")" << endl;
    
    destino.w= _p->getAncho()/Tile::getTam() +2;
    destino.h= _p->getAlto()/Tile::getTam() +2;
    
    for(Uint32 i=_cX/Tile::getTam(); (i<aux_ancho && i< _ancho); i++)
      for(Uint32 j=_cY/Tile::getTam(); (j<aux_alto && i<_alto); j++){
	destino.x=(i-_cX) * Tile::getTam();
	destino.y=(j-_cY) * Tile::getTam();
	
	cout << "(i,j): (" << i << "," << j << ")" << endl;
	cout << "matriz: " << _matrizOriginal[i][j] << endl;
	
	Tile t = _tiles.find(_matrizOriginal[i][j])->second;
	cout << "tile tomado;" << endl;
	
      SDL_BlitSurface(t.getImagen(),
      		      &origen, _p->getFondo(), &destino);
      
      }
  }

    
  origen.x=destino.x;
  origen.y=destino.y;
  origen.h=destino.h;
  origen.w=destino.w;
  
  switch(_mov){
  case 'u': 
    _cY -= movimiento.at(Secuencia-1);
    destino.y = origen.y - movimiento.at(Secuencia-1);
    break;
  case 'd':
    _cY += movimiento.at(Secuencia-1);
    destino.y = origen.y + movimiento.at(Secuencia-1);
      break;
  case 'l':
    _cX -= movimiento.at(Secuencia-1);
    destino.x = origen.x - movimiento.at(Secuencia-1);
    break;
  case 'r':
    _cX += movimiento.at(Secuencia-1);
    destino.x = origen.x + movimiento.at(Secuencia-1);
    break;
  default: break;
  }
  
  cout << "(_cX,_cY): (" << _cX << "," << _cY << ")" << endl;
  
  SDL_BlitSurface(_p->getFondo(),&origen, _p->getFondo(), &destino);
  
  _p->volcarPantalla(_p->getFondo(), _p->getBuffer());
  
  
}

  /*
  cout << "(secuencia,vez): (" << Secuencia << "," << vez << ")" << endl;

  double trozo_dibujo = (double)Secuencia/vez;
  cout << "trozo_dib: " << trozo_dibujo << endl;

  origen.x=0;
  origen.y=0;
  
  origen.h = Tile::getTam() * trozo_dibujo;
  origen.w = Tile::getTam() * trozo_dibujo;

  cout << "_cX : " << cx* (double)Tile::getTam()*trozo_dibujo << endl;
  cout << "_cY : " << cy* (double)Tile::getTam()*trozo_dibujo << endl;
  cout << "tamaño tile: " << Tile::getTam() << endl; 

  _cX=(double)cx * (double)Tile::getTam() * trozo_dibujo;
  _cY=(double)cy * (double)Tile::getTam() * trozo_dibujo;

  cout << "cX: " << _cX << endl;
  cout << "cY: " << _cY << endl;

  Uint32 ancho_aux=_p->getAncho();
  Uint32 alto_aux=_p->getAlto();

  Uint32 aux_h = _cX+(_p->getFondo()->h/Tile::getTam());
  // número de tiles de la pantalla (alto) + coordY
  Uint32 aux_w = _cY+(_p->getFondo()->w/Tile::getTam());
  // número de tiles de la pantalla (ancho) + coordX

  cout << "ancho: " << aux_h << endl;
  cout << "alto: " << aux_w << endl;

  for(Uint32 i=(Uint32)_cX; (i < aux_w && i < _ancho); i++){
    cout << "i: " << i << endl;
    for(Uint32 j=(Uint32)_cY;(j < aux_h && j < _alto); j++){
      cout << "(i,j): (" << i << "," << j << ")" << endl;
      destino.x=(double)(i-_cX)*(double)Tile::getTam() * trozo_dibujo;
      destino.y=(double)(j-_cY)*(double)Tile::getTam() * trozo_dibujo;

      cout << "destino x e y: " << destino.x << " " << destino.y << endl;
      cout << "(i,j) matriz: (" << i/Tile::getTam() << "," 
	   << j/Tile::getTam() << ")" << endl;

      map<Uint32, Tile*>::iterator aux = 
	_tiles.find(_matrizOriginal[i][j]);

      cout << "tile encontrado iterador" << endl;

      Tile* t ;
      t= aux->second;
      cout << "RUTA: " << t->getRuta() << endl;

      cout << "MATRIZ ORIGINAL: " << _matrizOriginal[i][j] << endl;
      
      Tile* aux2 = _tiles.at(_matrizOriginal[i][j]);
      //cout << "RUTA: " << aux2->getRuta() << endl;
      cout << "Colisionable?: " << aux2->isColisionable() << endl;

      SDL_BlitSurface(t->getImagen(),
		      &origen, _p->getFondo(), &destino);      
    }
    cout << endl;
  }


  
  cout << "PREVOLCADO" << endl;
  _p->volcarPantalla(_p->getFondo(), _p->getBuffer());
  cout << "POSTVOLCADO" << endl;

  
}
  */

  // TODO: hacer que los bordes (arriba y izquierda) también salgan en negro
  // cuando se necesite, es decir, por ejemplo, cuando el muñeco quiera acceder
  // hasta el límite superior del mapa
