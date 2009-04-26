

#ifndef _IMAGEN_H_
#define _IMAGEN_H_


#include "tile.h"
#include <vector>

// nota: en esta clase todos los tamaños se miden en tiles

class Imagen{
 public:
  Imagen(){};

  // creamos un objeto imagen a partir del tamaño de la matriz completa.
  Imagen(Uint32 ancho, Uint32 alto);

  // creamos un objeto imagen a partir de la matriz completa
  Imagen(Uint32 **matriz_completa, Uint32 ancho, Uint32 alto);
  
  // creamos un objeto imagen a partir de los tamaños y los tiles.
  Imagen(Uint32 ancho, Uint32 alto, std::vector<Tile*> imagenes);

  // se introducirá en el final del vector.
  // hay que tener en cuenta los índices para luego poder 
  // realizar la imagen correctamente.
  void relacionarTile(Tile *t);

  // Para cambiar o inicializar la matriz
  void inicializarMatrizCompleta(Uint32 **matriz, Uint32 ancho, Uint32 alto);

  // Conviete la matriz completa en el dibujo con tiles sobre una Surface.
  // Necesitamos saber desde que coordenada de la matriz completa comenzamos
  // a dibujar. El final/tamaño nos lo proporciona la Surface.
  void dibujarFondo(Sint32 cx, Sint32 cy, SDL_Surface *pantalla);
  
  Uint32 getAlto();
  Uint32 getAncho();

  Uint32 getCoorX();
  Uint32 getCoorY();

  std::vector<Tile*> getTiles();
 
 private:

  std::vector<Tile*> _tiles;
  
  // matriz rellena de índices del vector de tiles.
  Uint32 **_matrizOriginal;
  Uint32 _alto,_ancho;
  Uint32 _cX, _cY; 
  // coordenadas tomadas de la matriz original 
  // desde donde se es visible la matriz secundaria en pantalla.


  //Uint32 **_matrizVisible; Creo k no sirve de muxo, solo controlamos 
  // la coordenada desde la que dibujamos en la surface ¿no?
  
  

};

#endif
