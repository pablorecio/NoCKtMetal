/*
 * This program is free software: you can redistribute it
 * and/or modify it under the terms of the GNU General
 * Public License as published by the Free Software
 * Foundation, either version 3 of the License, or any
 * later version.

 * This program is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A
 * PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.

 * You should have received a copy of the GNU General
 * Public License along with this program.  If not, see
 * <http://www.gnu.org/licenses/>.

 * Copyright (C) 2009, NoCKTMetal Team
 *
 * Fichero: animacion.h
 * Autor: Noelia Sales Montes
 * Fecha: 19 de abril de 2009
 * Proyecto: NoCKt Metal
 */

#ifndef _ANIMACION_H
#define	_ANIMACION_H

#include "evento.h"
#include "pantalla.h"
#include "personaje.h"
#include "imagen.h"
#include "npj.h"

#include <vector>

/**
 * Tipo <i>Movimiento</i>, que representa la orientación del movimiento a
 * realizar.
 */
enum Movimiento {
    NULO = 0,
    SUBIR,
    BAJAR,
    IZDA,
    DCHA
};

/**
 * @brief Clase controladora de un nivel de juego.
 * Se encarga de inicializar los datos necesarios para un nivel del juego, así
 * como de controlar la gestión de eventos (con ayuda de la clase 
 * <code>Evento</code>) y el movimiento general de los elementos
 * dinámicos, en principio, el <i>fondo</i> y un <i>personaje principal</i>.
 * @author Noelia Sales Montes
 * @date 19 de abril de 2009
 * @note Parte del Proyecto NoCKt Metal
 * @see evento.h imagen.h personaje.h pantalla.h
 */
class Animacion {
public:
  /**
   * Constructor predeterminado de <code>Animacion</code>.
   */
  Animacion();
  /**
   * Constructor de un nivel del juego, cuyos elementos se representarán
   * en la pantalla dada.
   * @param p Puntero al objeto que representa la pantalla principal del 
   * juego.
   */
  Animacion(Pantalla* p, Evento* e);
  
  /**
   * Función que se encarga de inicializar el nivel actual.
   * @note Al encontrarnos aún en una versión <i>alpha</i> del proyecto,
   * esta función es un tanto burda.
   * No se comporta abstrayendo absolutamente nada, puesto que aún no 
   * se ha incluido en el motor de movimiento la sección correspondiente a
   * lectura/escritura en XML.
   */
  void inicializarAnimacion();
  /**
   * Método modificador de animacion, donde se reune el comportamiento
   * principal de esta clase.
   * Ejecuta y controla el movimiento en el mapa.
   * @note De momento tan solo se refiere al movimiento solicitado por el
   * usuario, pero en versiones posteriores se pretende añadir más elementos
   * bajo control ajeno a éste.
   * @return Valor lógico que controla la acción procesada. Si la acción 
   * elegida es salir del programa, se devuelve <code>true</code>; 
   * <code>false</code> en caso contrario.
   */
  bool procesarAccion();
  /**
   * Destructor de la clase Animacion.
   */

  void iniciarMotorCombate();
  virtual ~Animacion();
 private:
  
  NPJ& persAactuar(Uint32 mx, Uint32 my);

  /**
   * Método auxiliar que dibuja un movimiento estático <i>desde el punto
   * de vista del personaje</i>.
   * @param cx Coordenada horizontal que indica hacia que sentido se mueve el
   * personaje.
   * @param cy Coordenada vertical que indica hacia que sentido se mueve el
   * personaje.
   * @param dir Identificador de la direccion del movimiento necesario para
   * dibujar el fondo en movimiento.
   */
  void hacerMovimientoEstatico(Sint32 cx, Sint32 cy, char dir);
  /**
   * Método auxiliar que realiza un movimiento dinámico <i>desde el punto
   * de vista del personaje</i>.
   */
  void hacerMovimientoDinamico();
  /**
   * Método auxiliar que realiza un movimiento simple del personaje.
   * Sirve de ayuda a <code>hacerMovimientoEstatico</code> y
   * <code>hacerMovimientoDinamico</code> que realizan el movimiento
   * intercalándolo con el del mapa.
   * @param sec Secuencia actual del movimiento.
   * @param desp Desplazamiento. Por defecto 0.
   */
  void mover(Uint32 sec, Uint32 desp = 0);
  /**
   * Método auxiliar que se encarga de actualizar la posición del personaje,
   * en el mapa.
   */
  void actualizarMapa();
  /**
   * Método auxiliar que realiza el movimiento de "choque" del personaje
   * (cuando se topa con un tile colisionable).
   */
  void dibujarPosicionEstatica();
  void hacerMovDinNPJ();

  void dialogos(Uint32 i);
  /**
   * Puntero a la pantalla general del juego.
   */
  Pantalla* _pant;
  /**
   * Objeto de la clase evento que controlará las acciones solicitadas por el
   * usuario.
   */
  Evento* _evento;
  /**
   * Puntero al personaje principal del nivel.
   */
  Personaje* _principal;
  /**
   * Puntero al elemento que controla el fondo y las imágenes de este nivel.
   */
  Imagen* _imag;
  /**
   * Identificador que se corresponde con la orientación del movimiento a
   * ejecutar con el personaje.
   * Se corresponde con <code>subir</code>, <code>bajar</code>,
   * <code>izda</code> y <code>dcha</code>.
   */
  Movimiento _mov;

  /**
   * Personajes secundarios de la animación.
   */
  std::vector<NPJ> _persSecs;
};

#endif	/* _ANIMACION_H */
