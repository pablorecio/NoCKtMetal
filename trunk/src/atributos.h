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
 * Fichero = atributos.h
 * Autor = Pablo Recio Quijano
 * Fecha = 14 / 04 / 2009
 */

#ifndef _ATRIBUTOS_
#define _ATRIBUTOS_

#include <SDL/SDL.h>

#include "atributos.h"

/** 
 * @brief Clase con la que encapsulamos los atributos que tendrá un personaje del juego,
 * además de las tiradas y operaciones que podemos realizar con ellas.
 *
 * El uso de esta clase es el siguiente:
 * <code>AtributoBase base(120,10,12,........);
 * Atributos PJ(base, 20000);</code>
 *
 * De forma que que se calcula automáticamente, el nivel que tiene el personaje
 * con esos atributos, según los puntos de experiencia, y incrementándose los
 * atributos base en función al nivel y sus incrementadores.
 *
 * A través de esta clase, podemos obtener también las tiradas sobre esos atributos.
 * Por ejemplo, si queremos calcular una tirada de velocidad, usaremos:
 *
 * <code>Uint32 tirada = PJ.tiradaVelocidad();</code>
 *
 * lo cual nos proporciona el valor de dicha tirada, teniendo en cuenta también la suerte,
 * puediendo ser una tirada crítica ó una tirada <i>pifia</i>.
 *
 * @author Pablo Recio
 */
class Atributos{
 public:
  /**
   * @brief Constructor predeterminado de un objeto de la clase Atributos.
   */
  Atributos(){}

  /** 
   * @brief Constructor de un objeto de la clase atributo a partir de unos atributos básicos,
   * y unos puntos de experiencia, del que sacaremos el nivel.
   * @param base AtributoBase que contiene la base de estos atributos. A partir de ellos y el 
   * nivel del personaje
   * @param exp Entero sin signo de 32 bits que indica la experiencia que tiene el PJ.
   */
  Atributos(AtributoBase base, Uint32 exp = 0);
  
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
   * @brief Método <i>getter</i> para el número de puntos de experiencia. 
   *  
   * @return Valor entero sin signo de 32 bits con el número de puntos de experiencia.
   */
  Uint32 getExperiencia() const {return _exp;}


  /** 
   *
   * @brief Método <i>getter</i> para el número de puntos de experiencia necesarios para el siguiente nivel. 
   *  
   * @return Valor entero sin signo de 32 bits con el número de puntos de experiencia necesarios para el siguiente nivel.
   */
  Uint32 getExperienciaSiguienteNivel() const {return _expSigNiv;}
  /** 
   * 
   * @brief Método <i>getter</i> para el nivel del personaje con estos atributos.
   * 
   * @return Valor entero sin signo de 32 bits con el nivel.
   */
  Uint32 getNivel() const {return _niv;}

  /** 
   * 
   * @brief Método <i>getter</i> mediante el cual obtenemos una referencia constante
   * al objeto con los atributos base relacionados con estos atributos.
   * 
   * @return Referencia constante al objeto que contiene los atributos base
   */
  const AtributoBase& getAtributosBase() const {return _base;}

  /** 
   * Método que incrementa la experiencia en los atributos, subiendo de nivel si fuera
   * necesario.
   * 
   * @param exp Entero sin signo de 32 bits con la experiencia que queremos aumentar. 
   */
  void addExperiencia(Uint32 exp);

  /** 
   * 
   * @brief Método que realiza una tirada de suerte. 
   *
   * Esta tirada es algo particular con respecto a las demás. Realmente consiste en un sistema
   * similar a las tiradas de los juegos de rol-mesa. Se realiza una tirada aleatoria entre 1 y 100.
   * Si el resultado es menor o igual al atributo suerte, la tirada ha tenido éxito. Si es mayor,
   * no ha tenido éxito, y si la tirada es 99 o 100, se considera una pifia.
   * 
   * @return Devuelve 0, si la tirada no ha tenido éxito, 1 si ha tenido éxito, y -1 si
   * la tirada ha sido una <i>pifia</i>
   */
  Uint32 tiradaSuerte() const ;

  Uint32 tiradaVelocidad() const ;
  Uint32 tiradaFuerza() const ;
  Uint32 tiradaDestreza() const ;
  Uint32 tiradaResistencia() const ;
  Uint32 tiradaVirtuosidad() const ;
  Uint32 tiradaConstitucion() const ;
  Uint32 tiradaInteligencia() const ;

 protected:
  AtributoBase _base;

  Uint32 _exp;
  Uint32 _niv;

  Uint32 _expSigNiv;

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

  Uint32 aleatorioRango(Uint32 a, Uint32 b) const;
  void subirNivel();
  //TODO calcular los coeficientes correctamente, provisionales
  double coeficiente(double n, double a = 0.1, double b = 0.002) const;
  Uint32 experienciaParaNivel(Uint32 n) const;
};

#endif
