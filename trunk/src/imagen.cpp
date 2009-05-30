
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

using namespace std;

Imagen::Imagen() { }

Imagen::Imagen(Uint32 ancho, Uint32 alto, set<NPJ> npj, Pantalla* p, Uint32** matriz_tiles,
               bool** matriz_col, bool** matriz_inter):
_alto(alto), _ancho(ancho), _cX(0), _cY(0), _cXt(0), _cYt(0), _p(p) {
  
  npj_ = npj;

  if (matriz_tiles != NULL) {
    _matrizOriginal = (Uint32**) malloc(sizeof (Uint32) * ancho);
    for (Uint32 i = 0; i < ancho; i++)
      _matrizOriginal[i] = (Uint32*) malloc(sizeof (Uint32) * alto);
    
    for (Uint32 i = 0; i < ancho; i++)
      for (Uint32 j = 0; j < alto; j++)
	_matrizOriginal[i][j] = matriz_tiles[i][j];
    
  }
  
  if (matriz_col != NULL) {
    _matrizColision = (bool**)malloc(sizeof (bool*) * ancho);
    for (Uint32 i = 0; i < ancho; i++)
      _matrizColision[i] = (bool*)malloc(sizeof (bool) * alto);
    
    for (Uint32 i = 0; i < ancho; i++)
      for (Uint32 j = 0; j < alto; j++)
	_matrizColision[i][j] = matriz_col[i][j];
  }
  
  if (matriz_inter != NULL) {
    _matrizInteractual = (bool**)malloc(sizeof (bool*) * ancho);
    for (Uint32 i = 0; i < ancho; i++)
      _matrizInteractual[i] = (bool*)malloc(sizeof (bool) * alto);
    
    for (Uint32 i = 0; i < ancho; i++)
      for (Uint32 j = 0; j < alto; j++)
	_matrizInteractual[i][j] = matriz_inter[i][j];
  }
}

Imagen::Imagen(Uint32 ancho, Uint32 alto, Uint32 x, Uint32 y, Pantalla* p,
               Uint32** matriz_tiles, bool** matriz_col, bool** matriz_inter):
_alto(alto), _ancho(ancho), _cX(0), _cY(0), _cXt(x), _cYt(y), _p(p) {

    if (matriz_tiles != NULL) {
        _matrizOriginal = (Uint32**) malloc(sizeof (Uint32) * ancho);
        for (Uint32 i = 0; i < ancho; i++)
            _matrizOriginal[i] = (Uint32*) malloc(sizeof (Uint32) * alto);

        for (Uint32 i = 0; i < ancho; i++)
            for (Uint32 j = 0; j < alto; j++)
                _matrizOriginal[i][j] = matriz_tiles[i][j];

    }

    if (matriz_col != NULL) {
        _matrizColision = (bool**)malloc(sizeof (bool*) * ancho);
        for (Uint32 i = 0; i < ancho; i++)
            _matrizColision[i] = (bool*)malloc(sizeof (bool) * alto);

        for (Uint32 i = 0; i < ancho; i++)
            for (Uint32 j = 0; j < alto; j++)
                _matrizColision[i][j] = matriz_col[i][j];
    }

    if (matriz_inter != NULL) {
        _matrizInteractual = (bool**)malloc(sizeof (bool*) * ancho);
        for (Uint32 i = 0; i < ancho; i++)
            _matrizInteractual[i] = (bool*)malloc(sizeof (bool) * alto);

        for (Uint32 i = 0; i < ancho; i++)
            for (Uint32 j = 0; j < alto; j++)
                _matrizInteractual[i][j] = matriz_inter[i][j];
    }
}

Imagen::Imagen(map<Uint32, Tile> imagenes, Uint32 ancho, Uint32 alto,
               Uint32** matriz_tiles, bool** matriz_col,
               bool** matriz_inter) {

    _ancho = ancho;
    _alto = alto;

    _cX = 0;
    _cY = 0;

    _cXt = 0;
    _cYt = 0;

    _tiles = imagenes;

    if (matriz_tiles != NULL) {
        _matrizOriginal = (Uint32**) malloc(sizeof (Uint32) * ancho);
        for (Uint32 i = 0; i < ancho; i++)
            _matrizOriginal[i] = (Uint32*) malloc(sizeof (Uint32) * alto);

        for (Uint32 i = 0; i < ancho; i++)
            for (Uint32 j = 0; j < alto; j++)
                _matrizOriginal[i][j] = matriz_tiles[i][j];

    }

    if (matriz_col != NULL) {
        _matrizColision = (bool**)malloc(sizeof (bool*) * ancho);
        for (Uint32 i = 0; i < ancho; i++)
            _matrizColision[i] = (bool*)malloc(sizeof (bool) * alto);

        for (Uint32 i = 0; i < ancho; i++)
            for (Uint32 j = 0; j < alto; j++)
                _matrizColision[i][j] = matriz_col[i][j];
    }

    if (matriz_inter != NULL) {
        _matrizInteractual = (bool**)malloc(sizeof (bool*) * ancho);
        for (Uint32 i = 0; i < ancho; i++)
            _matrizInteractual[i] = (bool*)malloc(sizeof (bool) * alto);

        for (Uint32 i = 0; i < ancho; i++)
            for (Uint32 j = 0; j < alto; j++)
                _matrizInteractual[i][j] = matriz_inter[i][j];
    }
}

void Imagen::relacionarTile(Uint32 id, Tile& t) {
    _tiles.insert(make_pair(id, t));
}

void Imagen::relacionarPantalla(Pantalla& p) {
    _p = &p;
}

void Imagen::setMatriz(Uint32 ancho, Uint32 alto, Uint32** matriz,
                       bool** colisionable, bool** interactuable) {
    _ancho = ancho;
    _alto = alto;

    _matrizOriginal = (Uint32**) malloc(sizeof (Uint32) * ancho);
    for (Uint32 i = 0; i < ancho; i++)
        _matrizOriginal[i] = (Uint32*) malloc(sizeof (Uint32) * alto);

    for (Uint32 i = 0; i < ancho; i++)
        for (Uint32 j = 0; j < alto; j++)
            _matrizOriginal[i][j] = matriz[i][j];

    if (colisionable != NULL) {
        _matrizColision = (bool**)malloc(sizeof (bool*) * ancho);
        for (Uint32 i = 0; i < ancho; i++)
            _matrizColision[i] = (bool*)malloc(sizeof (bool) * alto);

        for (Uint32 i = 0; i < ancho; i++)
            for (Uint32 j = 0; j < alto; j++)
                _matrizColision[i][j] = colisionable[i][j];
    }

    if (interactuable != NULL) {
        _matrizInteractual = (bool**)malloc(sizeof (bool*) * ancho);
        for (Uint32 i = 0; i < ancho; i++)
            _matrizInteractual[i] = (bool*)malloc(sizeof (bool) * alto);

        for (Uint32 i = 0; i < ancho; i++)
            for (Uint32 j = 0; j < alto; j++)
                _matrizInteractual[i][j] = interactuable[i][j];
    }
}

// Convierte la matriz completa en el dibujo con tiles sobre una Surface.
// Necesitamos saber desde que coordenada de la matriz completa comenzamos
// a dibujar. El final/tamaño nos lo proporciona la Surface.

void Imagen::dibujarFondo() {
    SDL_Rect origen, destino;
    bool matrizColCreada = false;
    bool matrizInterCreada = false;

    _imagenAux = SDL_CreateRGBSurface(SDL_HWSURFACE, _ancho * Tile::getTam(),
                                      _alto * Tile::getTam(), 24, 0, 0, 0, 0);
    origen.x = 0;
    origen.y = 0;
    origen.h = Tile::getTam();
    origen.w = Tile::getTam();

    destino.w = _ancho;
    destino.h = _alto;

    if (_matrizColision == NULL) {
        _matrizColision = (bool**)malloc(sizeof (bool*) * _ancho);
        for (Uint32 i = 0; i < _ancho; i++)
            _matrizColision[i] = (bool*)malloc(sizeof (bool) * _alto);
        matrizColCreada = true;
    }

    if (_matrizInteractual == NULL) {
        _matrizInteractual = (bool**)malloc(sizeof (bool*) * _ancho);
        for (Uint32 i = 0; i < _ancho; i++)
            _matrizInteractual[i] = (bool*)malloc(sizeof (bool) * _alto);
        matrizInterCreada = true;
    }

    for (Uint32 i = 0; i < _ancho; i++) {
      for (Uint32 j = 0; j < _alto; j++) {
	
	destino.x = i * Tile::getTam();
	destino.y = j * Tile::getTam();
	
	Tile t = getTile(_matrizOriginal[i][j]);
	if (matrizColCreada)
	  _matrizColision[i][j] = t.isColisionable();
	if (matrizInterCreada)
	  _matrizInteractual[i][j] = t.isInteractuable();
	
	_p->volcarPantalla(t.getImagen(), &origen, _imagenAux, &destino);

	
      }
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

    if (secuencia == veces) {
        _cXt = _cX / Tile::getTam();
        _cYt = _cY / Tile::getTam();
    }
}
