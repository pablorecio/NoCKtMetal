
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

#include "pantalla.h"
#include "tile.h"
#include "npj.h"
#include <map>
#include <vector>

using namespace std;

/** 
 * @brief Abstración del mapa del juego. En esta clase se obtendrán los tiles necesarios y
 * la organización de éstos para crear el mapa de juego y visualizarlo en la pantalla.
 * @author Rosa María Durante Lerate
 * @version 3.0
 * @note Parte del Proyecto NoCKt Metal
 */
class NPJ;

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
  Imagen(Uint32 ancho, Uint32 alto, std::vector<NPJ>& npj, Pantalla& p, 
	 std::vector<std::vector<Uint32> >& matriz_tiles, std::map<Uint32, Tile>& imagenes);
  /**
   * Constructor alternativo.
   * @param ancho Número de tiles del ancho del mapa.
   * @param alto Número de tiles de la altura del mapa.
   * @param x Coordenada horizontal que se corresponde con la casilla a partir
   * de la cual se desea visualizar el mapa.
   * @param y Coordenada vertical que se corresponde con la casilla a partir
   * de la cual se desea visualizar el mapa.
   * @param p Pantalla en la que se visualizará el mapa.
   * @param matriz_tiles Matriz de correspondencia <i>casilla-tile</i>.
   * @param matriz_col Matriz de valores lógicos que identifica cada
   * <code>tile</code> como colisionable o no colisionable.
   * Debe ser del mismo tamaño que <code>matriz_tiles</code>.
   * @param matriz_inter Matriz de valores lógicos que identifica cada
   * <code>tile</code> como interactuable o no interactuable.
   * Debe ser del mismo tamaño que <code>matriz_tiles</code>.
   */

  Imagen(Uint32 ancho, Uint32 alto, Uint32 x, Uint32 y, std::vector<NPJ>& personajes, Pantalla& p,
	 std::vector<std::vector<Uint32> >& matriz_tiles, std::map<Uint32,Tile>& imagenes);

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
  Imagen(std::map<Uint32, Tile>& imagenes, Uint32 ancho, Uint32 alto, Pantalla& p, std::vector<NPJ>& pers,
	 std::vector<std::vector<Uint32> >& matriz_tiles);

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
  std::vector<std::vector<Uint32> > getMatrizImagenes();

  /**
   * @brief Función con la que obtenemos la matriz de tiles colisionables en el mapa.
   */
  std::vector<std::vector<bool> > getMatrizColision();

  /**
   * @brief Función con la que obtenemos la matriz de tiles interactuables en el mapa.
   */
  std::vector<std::vector<bool> > getMatrizInteractual();

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
  map<Uint32,Tile> getTiles();

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
  void setTiles(map<Uint32,Tile> conjTiles);

  SDL_Surface* SurfaceNpj() const;

  /**
   * Cuando el muñeco principal accione la interacción que tenga el muñeco
   * secundario éste se volverá a dibujar de cara al personaje principal.
   * @param tx Posición x del personaje secundario.
   * @param ty Posición y del personaje secundario.
   * @param px Posición x del perosnaje principal.
   * @param py Posición y del personaje principal.
   * Éstos últimos se utilizan para saber qué orientación debe tener el personaje
   * secundario.
   * @return Devuelve la interacción que se realiza con este personaje (Dialogo, Combate
   * u objeto).
   */
  const std::vector<NPJ::interaccion>& dibujar(Uint32 tx, Uint32 ty, Uint32 px, Uint32 py);

 private:

  std::map<Uint32,Tile> _tiles;
 
  std::vector<std::vector<Uint32> > _matrizOriginal;
  std::vector<std::vector<bool> > _matrizColision;
  std::vector<std::vector<bool> > _matrizInteractual;
  Uint32 _alto,_ancho;
  Sint32 _cX, _cY;       // coordenadas en pixels.
  Sint32 _cXt, _cYt;     // coordenadas en tiles.

  Pantalla *_p;

  SDL_Surface* _imagenAux;
  //SDL_Surface* _imagenNpj; Futura modificación para el movimiento
  // en el mapa de un npj.
  
  std::vector<NPJ> npjs_;
};

// funciones inline

inline Uint32 Imagen::getAlto() { return _alto; }
inline Uint32 Imagen::getAncho() { return _ancho; }
inline std::vector<std::vector<Uint32> > Imagen::getMatrizImagenes() { return _matrizOriginal; }
inline std::vector<std::vector<bool> > Imagen::getMatrizColision() { return _matrizColision; }
inline std::vector<std::vector<bool> > Imagen::getMatrizInteractual() { return _matrizInteractual; } 

inline Sint32 Imagen::getCX() { return _cXt; }
inline Sint32 Imagen::getCY() { return _cYt; }

inline std::map<Uint32,Tile> Imagen::getTiles() { return _tiles; }

inline void Imagen::setCX(Sint32 x) { _cXt=x; }
inline void Imagen::setCY(Sint32 y) { _cYt=y; }

inline void Imagen::setTiles(std::map<Uint32,Tile> conj_tiles) { _tiles= conj_tiles; }

inline Tile Imagen::getTile(Uint32 identificador) { return _tiles.find(identificador)->second; }
inline bool Imagen::isColisionable(Uint32 cX, Uint32 cY) { return _matrizColision[cX][cY]; }
inline bool Imagen::isInteractuable(Uint32 cX, Uint32 cY) { return _matrizInteractual[cX][cY]; }

inline SDL_Surface* Imagen::SurfaceNpj() const { return _imagenAux; } 

#endif
