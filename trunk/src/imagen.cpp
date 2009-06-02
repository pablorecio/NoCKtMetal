
#include <iostream>
#include <iterator>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <cmath>
#include <map>
#include <vector>

#include "imagen.h"
#include "tile.h"
#include "pantalla.h"
#include "npj.h"

#include <vector>

using namespace std;

Imagen::Imagen() { }

Imagen::Imagen(Uint32 ancho, Uint32 alto, vector<NPJ> npj, Pantalla& p, vector<vector<Uint32> > matriz_tiles):
  _alto(alto), _ancho(ancho), _cX(0), _cY(0), _cXt(0), _cYt(0), _p(&p) {
  
  for(size_t i=0; i<npj.size(); i++)
    npjs_.push_back(npj.at(i));

  for(size_t i=0; i<npjs_.size(); i++){
    npjs_.at(i).setImagen(*this);
  }

  // if (matriz_tiles != NULL) {
  //   _matrizOriginal = (Uint32**) malloc(sizeof (Uint32) * ancho);
  //   for (Uint32 i = 0; i < ancho; i++)
  //     _matrizOriginal[i] = (Uint32*) malloc(sizeof (Uint32) * alto);
    
  //   for (Uint32 i = 0; i < ancho; i++)
  //     for (Uint32 j = 0; j < alto; j++)
  // 	_matrizOriginal[i][j] = matriz_tiles[i][j];
    
  // }

  vector<Uint32> auxiliar(_alto);
  vector<bool> auxiliarb(_alto);
  for(Uint32 i=0; i<_ancho; i++){
    _matrizOriginal.push_back(auxiliar); 
    _matrizColision.push_back(auxiliarb);
    _matrizInteractual.push_back(auxiliarb);
  }
      
  for(Uint32 i=0; i<_ancho; i++)
    for(Uint32 j=0; j<_alto; j++)
      _matrizOriginal[i][j] = matriz_tiles[i][j];

  for(Uint32 i=0; i<_ancho; i++)
    for(Uint32 j=0; j<_alto; j++){
      _matrizColision[i][j] = getTile(_matrizOriginal[i][j]).isColisionable();
      _matrizInteractual[i][j] = getTile(_matrizOriginal[i][j]).isInteractuable();
    }
  
}

Imagen::Imagen(Uint32 ancho, Uint32 alto, Uint32 x, Uint32 y, std::vector<NPJ> personajes, Pantalla& p,
               vector<vector<Uint32> > matriz_tiles):
_alto(alto), _ancho(ancho), _cX(0), _cY(0), _cXt(x), _cYt(y), _p(&p) {

  for(size_t i=0; i<personajes.size(); i++)
    npjs_.push_back(personajes.at(i));
  for(size_t i=0; i<npjs_.size(); i++){
    npjs_.at(i).setImagen(*this);
  }

  vector<Uint32> auxiliar(_alto);
  vector<bool> auxiliarb(_alto);
  for(Uint32 i=0; i<_ancho; i++){
    _matrizOriginal.push_back(auxiliar); 
    _matrizColision.push_back(auxiliarb);
    _matrizInteractual.push_back(auxiliarb);
  }
      
  for(Uint32 i=0; i<_ancho; i++)
    for(Uint32 j=0; j<_alto; j++)
      _matrizOriginal[i][j] = matriz_tiles[i][j];

  for(Uint32 i=0; i<_ancho; i++)
    for(Uint32 j=0; j<_alto; j++){
      _matrizColision[i][j] = getTile(_matrizOriginal[i][j]).isColisionable();
      _matrizInteractual[i][j] = getTile(_matrizOriginal[i][j]).isInteractuable();
    }
    
}

Imagen::Imagen(map<Uint32, Tile> imagenes, Uint32 ancho, Uint32 alto, Pantalla& p, std::vector<NPJ> pers,
               vector<vector<Uint32> > matriz_tiles) {

    _ancho = ancho;
    _alto = alto;

    _cX = 0;
    _cY = 0;

    _cXt = 0;
    _cYt = 0;

    _tiles = imagenes;

    for(size_t i=0; i<pers.size(); i++)
    npjs_.push_back(pers.at(i));
  for(size_t i=0; i<npjs_.size(); i++){
    npjs_.at(i).setImagen(*this);
  }

   vector<Uint32> auxiliar(_alto);
   vector<bool> auxiliarb(_alto);
  for(Uint32 i=0; i<_ancho; i++){
    _matrizOriginal.push_back(auxiliar); 
    _matrizColision.push_back(auxiliarb);
    _matrizInteractual.push_back(auxiliarb);
  }
      
  for(Uint32 i=0; i<_ancho; i++)
    for(Uint32 j=0; j<_alto; j++)
      _matrizOriginal[i][j] = matriz_tiles[i][j];

  for(Uint32 i=0; i<_ancho; i++)
    for(Uint32 j=0; j<_alto; j++){
      _matrizColision[i][j] = getTile(_matrizOriginal[i][j]).isColisionable();
      _matrizInteractual[i][j] = getTile(_matrizOriginal[i][j]).isInteractuable();
    }

}

void Imagen::relacionarTile(Uint32 id, Tile& t) {
    _tiles.insert(make_pair(id, t));
}

void Imagen::relacionarPantalla(Pantalla& p) {
    _p = &p;
}

// void Imagen::setMatriz(Uint32 ancho, Uint32 alto, Uint32** matriz,
//                        bool** colisionable, bool** interactuable) {
//     _ancho = ancho;
//     _alto = alto;

//     _matrizOriginal = (Uint32**) malloc(sizeof (Uint32) * ancho);
//     for (Uint32 i = 0; i < ancho; i++)
//         _matrizOriginal[i] = (Uint32*) malloc(sizeof (Uint32) * alto);

//     for (Uint32 i = 0; i < ancho; i++)
//         for (Uint32 j = 0; j < alto; j++)
//             _matrizOriginal[i][j] = matriz[i][j];

//     if (colisionable != NULL) {
//         _matrizColision = (bool**)malloc(sizeof (bool*) * ancho);
//         for (Uint32 i = 0; i < ancho; i++)
//             _matrizColision[i] = (bool*)malloc(sizeof (bool) * alto);

//         for (Uint32 i = 0; i < ancho; i++)
//             for (Uint32 j = 0; j < alto; j++)
//                 _matrizColision[i][j] = colisionable[i][j];
//     }

//     if (interactuable != NULL) {
//         _matrizInteractual = (bool**)malloc(sizeof (bool*) * ancho);
//         for (Uint32 i = 0; i < ancho; i++)
//             _matrizInteractual[i] = (bool*)malloc(sizeof (bool) * alto);

//         for (Uint32 i = 0; i < ancho; i++)
//             for (Uint32 j = 0; j < alto; j++)
//                 _matrizInteractual[i][j] = interactuable[i][j];
//     }
// }

// Convierte la matriz completa en el dibujo con tiles sobre una Surface.
// Necesitamos saber desde que coordenada de la matriz completa comenzamos
// a dibujar. El final/tamaño nos lo proporciona la Surface.

void Imagen::dibujarFondo() {
    SDL_Rect origen, destino;

    _imagenAux = SDL_CreateRGBSurface(SDL_HWSURFACE, _ancho * Tile::getTam(),
                                      _alto * Tile::getTam(), 24, 0, 0, 0, 0);
   
    origen.x = 0;
    origen.y = 0;
    origen.h = Tile::getTam();
    origen.w = Tile::getTam();
    
    destino.w = _ancho;
    destino.h = _alto;

    for (Uint32 i = 0; i < _ancho; i++) {
      for (Uint32 j = 0; j < _alto; j++) {
	
	destino.x = i * Tile::getTam();
	destino.y = j * Tile::getTam();
	
	Tile t = getTile(_matrizOriginal[i][j]);
	
	_p->volcarPantalla(t.getImagen(), &origen, _imagenAux, &destino);
      }
    }

    cout << "mapa pintado" << endl;
    
    for(size_t i=0; i<npjs_.size(); i++){
      NPJ aux = npjs_.at(i);
      cout << "Personaje: " << aux.getId() << endl;
      cout << "(" << aux.getX() << "," << aux.getY() << ")" << endl;
      _matrizColision[aux.getX()][aux.getY()] = true;
      cout << "colision true" << endl;
      _matrizInteractual[aux.getX()][npjs_.at(i).getY()] = true;
      cout << "interactual true" << endl; 
      cout << "dibuja personaje: " << aux.getId() << endl;
      aux.dibujarPosicionFrente();
    }

    _cX = _cXt * Tile::getTam();
    _cY = _cYt * Tile::getTam();

    destino.x = destino.y = 0;
    origen.h = destino.h = _p->getAlto();
    origen.w = destino.w = _p->getAncho();
    origen.x = _cX;
    origen.y = _cY;

    _p->volcarPantalla(_imagenAux, &origen, _p->getFondo(), &destino);
    _p->volcarPantalla(_p->getFondo(), _p->getBuffer());

    cout << "Pantalla volcada completa." << endl;

}

// TODO: hacer que los bordes (arriba y izquierda) también salgan en negro
// cuando se necesite, es decir, por ejemplo, cuando el muñeco quiera acceder
// hasta el límite superior del mapa

void Imagen::dibujarSecuencia(char dir, Uint32 secuencia, Uint32 veces) {
    vector<Uint32> _pixels(veces);
    for (Uint32 i = 0; i < veces; i++) {
        _pixels.at(i) = Tile::getTam() / veces;
        if (i < Tile::getTam() % veces)
            _pixels.at(i)++;
    }

    SDL_Rect origen, destino;
    destino.x = destino.y = 0;
    origen.h = destino.h = _p->getAlto();
    origen.w = destino.w = _p->getAncho();

    switch (dir) {
    case 'u': // muñeco arriba, mapa abajo.
        origen.x = _cX = _cX;
        origen.y = _cY = _cY - _pixels.at(secuencia - 1);
        break;
    case 'd': // muñeco abajo, mapa arriba.
        origen.x = _cX = _cX;
        origen.y = _cY = _cY + _pixels.at(secuencia - 1);
        break;
    case 'l': // muñeco a la izquierda, mapa hacia la derecha.
        origen.x = _cX = _cX - _pixels.at(secuencia - 1);
        origen.y = _cY = _cY;
        break;
    case 'r': // muñeco a la derecha, mapa hacia la izquierda.
        origen.x = _cX = _cX + _pixels.at(secuencia - 1);
        origen.y = _cY = _cY;
        break;
    default: break;
    }

    _p->volcarPantalla(_imagenAux, &origen, _p->getFondo(), &destino);
    _p->volcarPantalla(_p->getFondo(), _p->getBuffer());
    //_p->volcarPantalla(_imagenNpj, &origen, _p->getMovimientoSecundario(), &destino);
    //_p->volcarPantalla(_p->getMovimientoSecundario(), _p->getBuffer());

    if (secuencia == veces) {
        _cXt = _cX / Tile::getTam();
        _cYt = _cY / Tile::getTam();
    }
}

const std::vector<NPJ::interaccion>& Imagen::dibujar(Uint32 tx, Uint32 ty, Uint32 px, Uint32 py)
{
  char dir;
  if(tx == px && ty < py)
    dir = 'd';
  if(tx == px && ty > py)
    dir = 'u';
  if(py == ty && tx < px)
    dir = 'r';
  if(py == ty && tx > px)
    dir = 'l';

  Uint32 posx = tx-1;
  Uint32 posy = ty-1;

  SDL_Rect origen, destino;
  
  origen.x = 0;
  origen.y = 0;
  origen.h = Tile::getTam();
  origen.w = Tile::getTam();
  
  destino.w = _ancho;
  destino.h = _alto;
  
  for(int i=0; i<3; i++)
    for(int j=0; j<3; j++){
      Tile t = getTile(_matrizOriginal[posx+i][posy+j]);
      
      destino.x = (posx+i) * Tile::getTam();
      destino.y = (posy+j) * Tile::getTam();

      _p->volcarPantalla(t.getImagen(), &origen, _imagenAux, &destino);
    }


  bool descubierto=false;
  size_t npj =0;
  while(npj < npjs_.size() && !descubierto){
    if(npjs_.at(npj).getX() == tx && npjs_.at(npj).getY() == ty){
      switch(dir){
      case 'd': npjs_.at(npj).dibujarPosicionFrente(); break;
      case 'u': npjs_.at(npj).dibujarPosicionEspaldas(); break;
      case 'r': npjs_.at(npj).dibujarPosicionLatDcha(); break;
      case 'l': npjs_.at(npj).dibujarPosicionLatIzda(); break;
      default: break;
      }
      descubierto=true;
    }
    else
      npj++;
  }
 
  destino.x = destino.y = 0;
  origen.h = destino.h = _p->getAlto();
  origen.w = destino.w = _p->getAncho();
  origen.x = _cX;
  origen.y = _cY;
  
  _p->volcarPantalla(_imagenAux, &origen, _p->getFondo(), &destino);
  _p->volcarPantalla(_p->getFondo(), _p->getBuffer());
  
  cout << "Pantalla volcada completa." << endl;
  
  return npjs_.at(npj).acciones();

}
