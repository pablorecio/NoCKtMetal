
#ifndef _IMAGEN_H_
#define _IMAGEN_H_


#include "tile.h"
#include <map>

#include "pantalla.h"

// nota: en esta clase todos los tamaños se miden en tiles

class Imagen{
 public:
  Imagen();

  // creamos un objeto imagen a partir del tamaño de la matriz completa.

  Imagen(Uint32 ancho, Uint32 alto, Pantalla* p, Uint32** matriz_tiles = NULL,
	 Uint32** matriz_col = NULL, Uint32** matriz_inter = NULL);

  Imagen(std::map<Uint32, Tile> imagenes, Uint32 ancho, Uint32 alto, 
	 Uint32** matriz_tiles = NULL,Uint32** matriz_col = NULL, 
	 Uint32** matriz_inter = NULL);

  void relacionarTile(Uint32 id, Tile& t);
  void relacionarPantalla(Pantalla &p);
  // Conviete la matriz completa en el dibujo con tiles sobre una Surface.
  // Necesitamos saber desde que coordenada de la matriz completa comenzamos
  // a dibujar. El final/tamaño nos lo proporciona la Surface.

  void dibujarFondo(Sint32 cx, Sint32 cy, Uint32 Secuencia=1, Uint32 vez=1);
  
  // get!!
  Uint32 getAlto();
  Uint32 getAncho();
  Uint32** getMatrizImagenes();
  Uint32** getMatrizColision();
  Uint32** getMatrizInteractual();
  Sint32 getCX();
  Sint32 getCY();
  std::map<Uint32,Tile> getTiles();

  // modificadoras
  void setCX(Sint32 x);
  void setCY(Sint32 y);
  void setTiles(std::map<Uint32,Tile> conjTiles);
  void setMatriz(Uint32 ancho, Uint32 alto, Uint32** matriz, 
		 Uint32** colisionable=NULL, Uint32** interactuable=NULL);

 private:

  std::map<Uint32,Tile> _tiles;
  
  // matriz rellena de índices del vector de tiles.
  Uint32 **_matrizOriginal;
  Uint32 **_matrizColision;
  Uint32 **_matrizInteractual;
  Uint32 _alto,_ancho;
  Sint32 _cX, _cY; 
  // coordenadas tomadas de la matriz original 
  // desde donde se es visible la matriz secundaria en pantalla.  

  Pantalla *_p;
  
  
};

// funciones inline

inline Uint32 Imagen::getAlto() { return _alto; }
inline Uint32 Imagen::getAncho() { return _ancho; }
inline Uint32** Imagen::getMatrizImagenes() { return _matrizOriginal; }
inline Uint32** Imagen::getMatrizColision() { return _matrizColision; }
inline Uint32** Imagen::getMatrizInteractual() { return _matrizInteractual; } 

inline Sint32 Imagen::getCX() { return _cX; }
inline Sint32 Imagen::getCY() { return _cY; }

inline std::map<Uint32,Tile> Imagen::getTiles() { return _tiles; }

inline void Imagen::setCX(Sint32 x) { _cX=x; }
inline void Imagen::setCY(Sint32 y) { _cY=y; }

inline void Imagen::setTiles(std::map<Uint32,Tile> conj_tiles) { _tiles= conj_tiles; }


#endif
