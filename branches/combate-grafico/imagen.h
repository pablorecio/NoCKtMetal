
//-*-C++-*-
/*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.

 * Copyright (C) 2009, NoCKTMetal Team
 
 * --------------------------------------------------------
 * Fichero = tile.h
 * Autor = Rosa María Durante Lerate
 * Fecha = 20 / 04 / 2009
 */

#ifndef _IMAGEN_H_
#define _IMAGEN_H_

#include "tile.h"
#include <map>

#include "pantalla.h"


/** 
 * @brief Abstración del mapa del juego. En esta clase se obtendrán los tiles necesarios y
 * la organización de éstos para crear el mapa de juego y visualizarlo en la pantalla.
 * @author Rosa María Durante Lerate
 * @version 3.0
 * @note Parte del Proyecto NoCKt Metal
 */

class Imagen{
 public:

  /**
   * @brief Constructor vacío de la clase.
   */
  Imagen();

  /**
   * @brief Constructor para la clase imagen a partir del tamaño del mapa (alto y ancho)
   * de la pantalla en la que se mostrará y de las estructuras de organización del mapa.
   * @param ancho Tamaño en número de tiles del ancho del mapa.
   * @param alto Tamaño en número de tiles del alto del mapa.
   * @param p Puntero a un objeto tipo <code>Pantalla</code> el cual se utilizará para 
   * mostrar el mapa en la pantalla del juego.
   * @param matriz_tiles Matriz de tipo <code>Uint32</code> la cual está compuesta de los
   * identificadores de los tiles que se utilizarán para estructurar el mapa.
   * @param matriz_col Matriz de tipo <code>bool</code> informando que casilla del mapa
   * es colisionable con el personaje y cual no.
   * @param matriz_inter Matriz de tipo <code>bool</code> informando que casilla del mapa
   * es interactuable con el personaje y cual no.
   */
  Imagen(Uint32 ancho, Uint32 alto, Pantalla* p, Uint32** matriz_tiles = NULL,
	 bool** matriz_col = NULL, bool** matriz_inter = NULL);

  /**
   * @brief Constructor para la clase imagen a partir del tamaño del mapa (alto y ancho)
   * de la pantalla en la que se mostrará y de las estructuras de organización del mapa.
   * @param imagenes Estructura de tipo <code>map</code> que contiene los tiles que se 
   * utilizarán para construir el mapa del juego y su identificador en dicho mapa.
   * @param ancho Tamaño en número de tiles del ancho del mapa.
   * @param alto Tamaño en número de tiles del alto del mapa.
   * @param matriz_tiles Matriz de tipo <code>Uint32</code> la cual está compuesta de los
   * identificadores de los tiles que se utilizarán para estructurar el mapa.
   * @param matriz_col Matriz de tipo <code>bool</code> informando que casilla del mapa
   * es colisionable con el personaje y cual no.
   * @param matriz_inter Matriz de tipo <code>bool</code> informando que casilla del mapa
   * es interactuable con el personaje y cual no.
   */  
  Imagen(std::map<Uint32, Tile> imagenes, Uint32 ancho, Uint32 alto, 
	 Uint32** matriz_tiles = NULL, bool** matriz_col = NULL, 
	 bool** matriz_inter = NULL);

  /**
   * @brief Función que abstrae la composición formada entre las clases Tile e Imagen.
   * Esta función relaciona el tile pasado por parámetro con el mapa a partir de un 
   * identificador.
   * @param id Identificador del tile en el mapa.
   * @param t Tile utilizado para construir el mapa.
   */
  void relacionarTile(Uint32 id, Tile& t);

  /**
   * @brief Función que abstrae la asociación formada entre las clases Pantalla e Imagen.
   * Esta función relaciona la pantalla con el mapa para mostrarlo en la pantalla del juego.
   * @param p Referencia a un objeto de la clase pantalla con el que se realizará 
   * la asociación.
   */
  void relacionarPantalla(Pantalla &p);
  
  /**
   * @brief Función encargada de dibujar el mapa completo en memoria.
   * Construye a partir de la 'matriz de tiles' (matriz de identificadores de tiles)
   * y de todos los tiles almacenados el mapa completo de la fase.
   */
  void dibujarFondo();

  /**
   * @brief Función encargada de realizar el movimiento del mapa. (en cuatro tiempos).
   * A partir de la posición donde se encuentre la pantalla, el mapa se moverá un tile 
   * de distancia hacia la dirección indicada.
   * @param dir Caracter que indica la dirección a la que se debe de mover el mapa (u,d,l,r).
   * @param secuencia Número del paso en el que nos encontramos para realizar el movimiento.
   * @param veces Número total de pasos que se realizarán para trasladarnos un tile más hacia
   * la dirección indicada.
   */
  void dibujarSecuencia(char dir, Uint32 secuencia, Uint32 veces);
  
  /**
   * @brief Función con la que obtenemos la altura del mapa.
   */
  Uint32 getAlto();

  /**
   * @brief Función con la que obtenemos la anchura del mapa.
   */
  Uint32 getAncho();

  /**
   * @brief Función con la que obtenemos la organización de los tiles en el mapa (matriz
   * de identificadores de tiles).
   */
  Uint32** getMatrizImagenes();

  /**
   * @brief Función con la que obtenemos la matriz de tiles colisionables en el mapa.
   */
  bool** getMatrizColision();

  /**
   * @brief Función con la que obtenemos la matriz de tiles interactuables en el mapa.
   */
  bool** getMatrizInteractual();

  /**
   * @brief Coordenada X del mapa donde se situa (esquina superior izquierda) la pantalla
   * en el mapa. Medida en número de tiles.
   */
  Sint32 getCX();

  /**
   * @brief Coordenada Y del mapa donde se situa (esquina superior izquierda) la pantalla
   * en el mapa. Medida en número de tiles.
   */
  Sint32 getCY();

  /**
   * @brief Función con la que obtenemos los tiles correspondientes con el mapa y sus
   * identificadores.
   */
  std::map<Uint32,Tile> getTiles();

  /**
   * @brief Función con la que obtenemos el tile correspondiente al identificador dado.
   * Dicho identificador es usado para la organización de la matriz  de tiles.
   */
  Tile getTile(Uint32 identificador);

  /**
   * @brief Función con la que obtenemos si el tile que permanece en la posición dada
   * es colisionable (<code>true</code>) o no lo es (<code>false</code>).
   */
  bool isColisionable(Uint32 cX, Uint32 cY);

  /**
   * @brief Función con la que obtenemos si el tile que permanece en la posición dada
   * es interactuable (<code>true</code>) o no lo es (<code>false</code>).
   */
  bool isInteractuable(Uint32 cX, Uint32 cY);

  /**
   * @brief Función que modifica la coordenada X de la posición de la pantalla en el mapa.
   */
  void setCX(Sint32 x);

  /**
   * @brief Función que modifica la coordenada Y de la posición de la pantalla en el mapa.
   */
  void setCY(Sint32 y);

  /**
   * @brief Función que modifica los tiles relacionados con el objeto imagen y sus 
   * identificadores.
   */
  void setTiles(std::map<Uint32,Tile> conjTiles);

  /**
   * @brief Función que modifica las estructuras de organización del mapa, asi como
   * la información de qué posiciones son colisionables y de las que son interactuables
   * en el mapa.
   */
  void setMatriz(Uint32 ancho, Uint32 alto, Uint32** matriz, 
		 bool** colisionable=NULL, bool** interactuable=NULL);

 private:

  std::map<Uint32,Tile> _tiles;
 
  Uint32 **_matrizOriginal;
  bool **_matrizColision;
  bool **_matrizInteractual;
  Uint32 _alto,_ancho;
  Sint32 _cX, _cY;       // coordenadas en pixels.
  Sint32 _cXt, _cYt;     // coordenadas en tiles.

  Pantalla *_p;

  SDL_Surface* _imagenAux;
 
};

// funciones inline

inline Uint32 Imagen::getAlto() { return _alto; }
inline Uint32 Imagen::getAncho() { return _ancho; }
inline Uint32** Imagen::getMatrizImagenes() { return _matrizOriginal; }
inline bool** Imagen::getMatrizColision() { return _matrizColision; }
inline bool** Imagen::getMatrizInteractual() { return _matrizInteractual; } 

inline Sint32 Imagen::getCX() { return _cXt; }
inline Sint32 Imagen::getCY() { return _cYt; }

inline std::map<Uint32,Tile> Imagen::getTiles() { return _tiles; }

inline void Imagen::setCX(Sint32 x) { _cXt=x; }
inline void Imagen::setCY(Sint32 y) { _cYt=y; }

inline void Imagen::setTiles(std::map<Uint32,Tile> conj_tiles) { _tiles= conj_tiles; }

inline Tile Imagen::getTile(Uint32 identificador) { return _tiles.find(identificador)->second; }
inline bool Imagen::isColisionable(Uint32 cX, Uint32 cY) { return _matrizColision[cX][cY]; }
inline bool Imagen::isInteractuable(Uint32 cX, Uint32 cY) { return _matrizInteractua[cX][cY]; }


#endif
