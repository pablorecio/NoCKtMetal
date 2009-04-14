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
 *
 */

/*
 * --------------------------------------------------------
 * Fichero = atributo_base.h
 * Autor = Pablo Recio Quijano
 * Fecha = 14 / 04 / 2009
 */

#ifndef _ATRIBUTOS_BASE_
#define _ATRIBUTOS_BASE_

#include <SDL/SDL.h>


/**
 * Clase AtributoBase. Esta clase nos sirve para modelar los valores
 * base y de incremenento para un determinado personaje. Realmente es
 * una simple encapsulación de varios datos en un mismo objeto, con sus 
 * distintos métodos observadores.
 *
 * Los atributos que se usarán son los siguientes:
 * <UL>
 * <LI><B>PV</B> - Puntos de vida. Indica los puntos que tiene un personaje,
 *                 de forma que si en algún momento llega a 0, el personaje
 *                 queda KO</LI>
 * <LI><B>PE</B> - Puntos especiales. Los ataques especiales consumen estos
 *                 puntos, de forma que puede ser que no podamos lanzar un 
 *                 ataque por carencia de ellos.</LI>
 * <LI><B>Velocidad</B> - Rapidez con la que se mueve un personaje. Define
 *                        cuantas veces puede atacar en un turno.</LI>
 * <LI><B>Fuerza</B> - Potencia del personaje. Influye en el daño que hacen
 *                     los ataques.</LI>
 * <LI><B>Destreza</B> - Capacidad del personaje para acertar un ataque,
 *                       o poder esquivar uno.</LI>
 * <LI><B>Suerte</B> - Valor abstracto con la probabilidad que una tirada
 *                     sea crítica o no.</LI>
 * <LI><B>Resistencia</B> - Capacidad para amortiguar los golpes físicos 
 *                          de los enemigos.</LI>
 * <LI><B>Virtuosidad</B> - Poder de los ataques especiales. También es la 
 *                          capacidad de resistir dichos ataques.</LI>
 * <LI><B>Constitución</B> - Parámetro sobre el cual se modifica la
 *                           vitalidad del personaje.</LI>
 * <LI><B>Inteligencia</B> - Parámetro sobre el cual se modifica los 
 *                           puntos especiales del personaje.</LI>
 * </UL>
 * También están los atributos de incremento, que definen el aumento de un atributo en
 * función del nivel, ya que no todos los personajes incrementarán los atributos de 
 * la misma manera.
 */
class AtributoBase{
 public:
  /**
   * Constructor vacio de un objeto de la clase AtributoBase
   */
  AtributoBase(): _PV(0), _PE(0), _vel(0), _fue(0), _des(0),  
		  _sue(0), _res(0), _vir(0), _con(0), _int(0), 
		  _incVel(0.0), _incFue(0.0), _incDes(0.0), _incSue(0.0), 
		  _incVir(0.0), _incCon(0.0), _incInt(0.0) {}

  /** 
   * Constructor de un objeto de la clase Atributo base
   * 
   * @param PV Puntos de vida iniciales
   * @param PE Puntes especiales iniciales
   * @param ve Velocidad inicial 
   * @param f Fuerza inicial
   * @param d Destreza inicial
   * @param s Suerte inicial
   * @param r Resistencia inicial
   * @param vi Virtuosidad inicial
   * @param c Constitución inicial
   * @param i Inteligencia inicial
   * @param iVe Incremento de velocidad
   * @param iFu Incremento de fuerza
   * @param iDe Incremento de destreza
   * @param iSu Incremento de suerte
   * @param iVi Incremento de virtuosidad
   * @param iCo Incremento de constitucion
   * @param iIn Incremento de inteligencia
   */
  AtributoBase(Uint32 PV, Uint32 PE, Uint32 ve, Uint32 f,
	       Uint32 d, Uint32 s, Uint32 r, Uint32 vi,
	       Uint32 c, Uint32 i, double iVe, double iFu, double iDe, 
	       double iSu, double iVi, double iCo, double iIn)
    : _PV(PV), _PE(PE), _vel(ve), _fue(f), _des(d), _sue(s), _res(r), 
      _vir(vi), _con(c), _int(i), _incVel(iVe), _incFue(iFu), 
      _incDes(iDe), _incSue(iSu), _incVir(iVi), _incCon(iCo), _incInt(iIn) {}

  /** 
   * 
   * Método <i>getter</i> para los puntos de vida.
   * 
   * @return Valor entero sin signo de 32 bits con los puntos de vida.
   */
  Uint32 getPV() const {return _PV;}

  /** 
   * 
   * Método <i>getter</i> para los puntos especiales.
   * 
   * @return Valor entero sin signo de 32 bits con los puntos especiales.
   */
  Uint32 getPE() const {return _PE;}

  /** 
   * 
   * Método <i>getter</i> para el atributo de la velocidad 
   * 
   * @return Valor entero sin signo de 32 bits con el atributo de la velocidad
   */
  Uint32 getVelocidad() const {return _vel;}

  /** 
   * 
   * Método <i>getter</i> para el atributo de la fuerza 
   * 
   * @return Valor entero sin signo de 32 bits con el atributo de la fuerza
   */
  Uint32 getFuerza() const {return _fue;}

  /**
   * 
   * Método <i>getter</i> para el atributo de la destreza
   * 
   * @return Valor entero sin signo de 32 bits con el atributo de la destreza
   */
  Uint32 getDestreza() const {return _des;}


  /** 
   * 
   * Método <i>getter</i> para el atributo de suerte
   * 
   * @return Valor entero sin signo de 32 bits con el atributo de suerte
   */
  Uint32 getSuerte() const {return _sue;}

  /** 
   * 
   * Método <i>getter</i> para el atributo de la resistencia
   * 
   * @return Valor entero sin signo de 32 bits con el atributo de la resistencia
   */
  Uint32 getResistencia() const {return _res;}

  /** 
   * 
   * Método <i>getter</i> para el atributo de la virtuosidad
   * 
   * @return Valor entero sin signo de 32 bits con el atributo de virtuosidad
   */
  Uint32 getVirtuosidad() const {return _vir;}

  /** 
   * 
   * Método <i>getter</i> para el atributo de la constitucion
   * 
   * @return Valor entero sin signo de 32 bits con el atributo de la constitucion
   */
  Uint32 getConstitucion() const {return _con;}

  /** 
   * 
   * Método <i>getter</i> para el atributo de la inteligencia
   * 
   * @return Valor entero sin signo de 32 bits con el atributo de la inteligencia
   */
  Uint32 getInteligencia() const {return _int;}

  /** 
   * 
   * Método <i>getter</i> para el incremento base de velocidad 
   * 
   * @return Valor real sin signo de 32 bits con el incremento base de velocidad
   */
  double getIncrementoVelocidad() const {return _incVel;}

  /** 
   * 
   * Método <i>getter</i> para el incremento base de fuerza
   * 
   * @return Valor real sin signo de 32 bits con el incremento base de fuerza
   */
  double getIncrementoFuerza() const {return _incFue;}

  /** 
   * 
   * Método <i>getter</i> para el incremento base de destreza 
   * 
   * @return Valor real sin signo de 32 bits con el incremento base de destreza
   */
  double getIncrementoDestreza() const {return _incDes;}

  /** 
   * 
   * Método <i>getter</i> para el incremento base de suerte
   * 
   * @return Valor real sin signo de 32 bits con el incremento base de suerte
   */
  double getIncrementoSuerte() const {return _incSue;}

  /** 
   * 
   * Método <i>getter</i> para el incremento base de resistencia
   * 
   * @return Valor real sin signo de 32 bits con el incremento base de resistencia
   */
  double getIncrementoResistencia() const {return _incRes;}

  /** 
   * 
   * Método <i>getter</i> para el incremento base de virtuosidad
   * 
   * @return Valor real sin signo de 32 bits con el incremento base de virtuosidad
   */
  double getIncrementoVirtuosidad() const {return _incVir;}

  /** 
   * 
   * Método <i>getter</i> para el incremento base de constitución
   * 
   * @return Valor real sin signo de 32 bits con el incremento base de constitución
   */
  double getIncrementoConstitucion() const {return _incCon;}

  /** 
   * 
   * Método <i>getter</i> para el incremento base de la inteligencia 
   * 
   * @return Valor real sin signo de 32 bits con el incremento base de la inteligencia
   */
  double getIncrementoInteligencia() const {return _incInt;}

 protected:
  Uint32 _PV;
  Uint32 _PE;
  Uint32 _vel;
  Uint32 _fue;
  Uint32 _des;
  Uint32 _sue;
  Uint32 _res;
  Uint32 _vir;
  Uint32 _con;
  Uint32 _int;

  double _incVel;
  double _incFue;
  double _incDes;
  double _incSue;
  double _incRes;
  double _incVir;
  double _incCon;
  double _incInt;
};

#endif
