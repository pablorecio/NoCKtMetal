
#ifndef _IMAGEN_H_
#define _IMAGEN_H_


#include "tile.h"
#include <map>

// nota: en esta clase todos los tamaños se miden en tiles

class Imagen{
 public:
  Imagen(){};

  // creamos un objeto imagen a partir del tamaño de la matriz completa.
  Imagen(Uint32 ancho, Uint32 alto);

  // creamos un objeto imagen a partir de la matriz completa
  Imagen(Uint32 ancho, Uint32 alto, Uint32** matriz_completa);
  
  // creamos un objeto imagen a partir de los tamaños y los tiles.
  Imagen(Uint32 ancho, Uint32 alto, Uint32** matriz_completa, std::map<Uint32, Tile> imagenes);

  // se introducirá en el final del vector.
  // hay que tener en cuenta los índices para luego poder 
  // realizar la imagen correctamente.
  void relacionarTile(Uint32 id, Tile t);

  // Conviete la matriz completa en el dibujo con tiles sobre una Surface.
  // Necesitamos saber desde que coordenada de la matriz completa comenzamos
  // a dibujar. El final/tamaño nos lo proporciona la Surface.
  void dibujarFondo(Sint32 cx, Sint32 cy, SDL_Surface *pantalla);
  
  // Observadoras
  Uint32 getAlto();
  Uint32 getAncho();
  Uint32** getMatriz();
  Sint32 getCoorX(Uint32 x);
  Sint32 getCoorY(Uint32 y);
  std::map<Uint32,Tile> getTiles();

  // modificadoras
  void setCoorX(Sint32 x);
  void setCoorY(Sint32 y);
  void setTiles(std::map<Uint32,Tile> conj_tiles);
  void setMatriz(Uint32 ancho, Uint32 alto, Uint32** matriz);

 private:

  std::map<Uint32,Tile> _tiles;
  
  // matriz rellena de índices del vector de tiles.
  Uint32 **_matrizOriginal;
  Uint32 _alto,_ancho;
  Sint32 _cX, _cY; 
  // coordenadas tomadas de la matriz original 
  // desde donde se es visible la matriz secundaria en pantalla.  

};

// funciones inline

inline Uint32 Imagen::getAlto() { return _alto; }
inline Uint32 Imagen::getAncho() { return _ancho; }
inline Uint32** Imagen::getMatriz() { return _matrizOriginal; }

inline Sint32 Imagen::getCoorX() { return _cX; }
inline Sint32 Imagen::getCoorY() { return _cY; }

inline std::map<Uint32,Tile> Imagen::getTiles() { return _tiles; }

inline void Imagen::setCoorX(Sint32 x) { _cX=x; }
inline void Imagen:setCoorY(Sint32 y) { _cY=y; }

inline void Imagen::setTiles(std::map<Uint32,Tile*> conj_tiles) { _tiles= conj_tiles; }


#endif
