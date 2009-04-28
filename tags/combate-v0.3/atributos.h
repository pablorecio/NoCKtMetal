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

#include <boost/config.hpp>
#include <boost/serialization/access.hpp>

#include <boost/serialization/serialization.hpp>
#include <boost/serialization/nvp.hpp>

#include "atributos_base.h"
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
 * @author Pablo Recio Quijano
 *
 * @date 14 de Abril de 2009
 */
class Atributos {
public:

    /**
     * @brief Constructor predeterminado de un objeto de la clase Atributos.
     */
    Atributos() {
    }

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
     * Método <i>getter</i> para los puntos de vida máximos.
     *
     * @return Valor entero sin signo de 32 bits con los puntos de vida.
     */
    Uint32 getPVMax() const {
        return _PVmax;
    }

    /**
     *
     * Método <i>getter</i> para los puntos de vida actuales.
     *
     * @return Valor entero sin signo de 32 bits con los puntos de vida.
     */
    Uint32 getPV() const {
        return _PV;
    }

    /**
     *
     * Método <i>getter</i> para los puntos especiales máximos.
     *
     * @return Valor entero sin signo de 32 bits con los puntos especiales.
     */
    Uint32 getPEMax() const {
        return _PEmax;
    }

    /**
     *
     * Método <i>getter</i> para los puntos especiales.
     *
     * @return Valor entero sin signo de 32 bits con los puntos especiales.
     */
    Uint32 getPE() const {
        return _PE;
    }

    /**
     *
     * Método <i>getter</i> para el atributo de la velocidad
     *
     * @return Valor entero sin signo de 32 bits con el atributo de la velocidad
     */
    Uint32 getVelocidad() const {
        return _vel;
    }

    /**
     *
     * Método <i>getter</i> para el atributo de la fuerza
     *
     * @return Valor entero sin signo de 32 bits con el atributo de la fuerza
     */
    Uint32 getFuerza() const {
        return _fue;
    }

    /**
     *
     * Método <i>getter</i> para el atributo de la destreza
     *
     * @return Valor entero sin signo de 32 bits con el atributo de la destreza
     */
    Uint32 getDestreza() const {
        return _des;
    }

    /**
     *
     * Método <i>getter</i> para el atributo de suerte
     *
     * @return Valor entero sin signo de 32 bits con el atributo de suerte
     */
    Uint32 getSuerte() const {
        return _sue;
    }

    /**
     *
     * Método <i>getter</i> para el atributo de la resistencia
     *
     * @return Valor entero sin signo de 32 bits con el atributo de la resistencia
     */
    Uint32 getResistencia() const {
        return _res;
    }

    /**
     *
     * Método <i>getter</i> para el atributo de la virtuosidad
     *
     * @return Valor entero sin signo de 32 bits con el atributo de virtuosidad
     */
    Uint32 getVirtuosidad() const {
        return _vir;
    }

    /**
     *
     * Método <i>getter</i> para el atributo de la constitucion
     *
     * @return Valor entero sin signo de 32 bits con el atributo de la constitucion
     */
    Uint32 getConstitucion() const {
        return _con;
    }

    /**
     *
     * Método <i>getter</i> para el atributo de la inteligencia
     *
     * @return Valor entero sin signo de 32 bits con el atributo de la inteligencia
     */
    Uint32 getInteligencia() const {
        return _int;
    }

    /**
     *
     * @brief Método <i>getter</i> para el número de puntos de experiencia.
     *
     * @return Valor entero sin signo de 32 bits con el número de puntos de experiencia.
     */
    Uint32 getExperiencia() const {
        return _exp;
    }

    /**
     *
     * @brief Método <i>getter</i> para el número de puntos de experiencia necesarios para el siguiente nivel.
     *
     * @return Valor entero sin signo de 32 bits con el número de puntos de experiencia necesarios para el siguiente nivel.
     */
    Uint32 getExperienciaSiguienteNivel() const {
        return _expSigNiv;
    }

    /**
     *
     * @brief Método <i>getter</i> para el nivel del personaje con estos atributos.
     *
     * @return Valor entero sin signo de 32 bits con el nivel.
     */
    Uint32 getNivel() const {
        return _niv;
    }

    /**
     *
     * @brief Método <i>getter</i> mediante el cual obtenemos una referencia constante
     * al objeto con los atributos base relacionados con estos atributos.
     *
     * @return Referencia constante al objeto que contiene los atributos base
     */
    const AtributoBase& getAtributosBase() const {
        return _base;
    }

    /**
     * Método que incrementa la experiencia en los atributos, subiendo de nivel si fuera
     * necesario.
     *
     * @param exp Entero sin signo de 32 bits con la experiencia que queremos aumentar.
     */
    void addExperiencia(Uint32 exp);

    /**
     *
     * Método que realiza una tirada de suerte.
     *
     * Esta tirada es algo particular con respecto a las demás. Realmente consiste en un sistema
     * similar a las tiradas de los juegos de rol-mesa. Se realiza una tirada aleatoria entre 1 y 100.
     * Si el resultado es menor o igual al atributo suerte, la tirada ha tenido éxito. Si es mayor,
     * no ha tenido éxito, y si la tirada es 99 o 100, se considera una pifia.
     *
     * @return Devuelve 0, si la tirada no ha tenido éxito, 1 si ha tenido éxito, y -1 si
     * la tirada ha sido una <i>pifia</i>
     */
    Uint32 tiradaSuerte() const;

    /**
     *
     * Método que realiza una tirada de velocidad
     *
     * @return Devuelve el valor de la velocidad, si es una tirada normal, o
     * el doble si ha tenido suerte.
     */
    Uint32 tiradaVelocidad() const;

    /**
     *
     * Método que realiza una tirada de fuerza
     *
     * @return Devuelve el valor de la fuerza, si es una tirada normal, o
     * el doble si ha tenido suerte.
     */
    Uint32 tiradaFuerza() const;

    /**
     *
     * Método que realiza una tirada de destreza
     *
     * @return Devuelve el valor de la destreza si es una tirada normal, o
     * el doble si ha tenido suerte.
     */
    Uint32 tiradaDestreza() const;

    /**
     *
     * Método que realiza una tirada de resistencia
     *
     * @return Devuelve el valor de la resistencia, si es una tirada normal, o
     * el doble si ha tenido suerte.
     */
    Uint32 tiradaResistencia() const;

    /**
     *
     * Método que realiza una tirada de virtuosidad
     *
     * @return Devuelve el valor de la virtuosidad, si es una tirada normal, o
     * el doble si ha tenido suerte.
     */
    Uint32 tiradaVirtuosidad() const;

    /**
     *
     * Método que realiza una tirada de constitucion
     *
     * @return Devuelve el valor de la constitucion, si es una tirada normal, o
     * el doble si ha tenido suerte.
     */
    Uint32 tiradaConstitucion() const;

    /**
     *
     * Método que realiza una tirada de inteligencia
     *
     * @return Devuelve el valor de la inteligencia, si es una tirada normal, o
     * el doble si ha tenido suerte.
     */
    Uint32 tiradaInteligencia() const;

    /**
     * Aumenta el valor del PV máximo
     *
     * @return El valor incrementado del PV máximo
     */
    Uint32 aumentarPVMax(Uint32 pv);

    /**
     * Aumenta el valor del PV
     *
     * @return El valor incrementado del PV
     */
    Uint32 aumentarPV(Uint32 pv);
    
    /**
     * Aumenta el valor del PE máximo
     *
     * @return El valor incrementado del PE máximo
     */
    Uint32 aumentarPEMax(Uint32 pe);

    /**
     * Aumenta el valor del PE
     *
     * @return El valor incrementado del PE
     */
    Uint32 aumentarPE(Uint32 pe);

    /**
     * Aumenta el valor de la velocidad
     *
     * @return El valor incrementado de la velocidad
     */
    Uint32 aumentarVelocidad(Uint32 v);

    /**
     * Aumenta el valor de la fuerza
     *
     * @return El valor incrementado de la fuerza
     */
    Uint32 aumentarFuerza(Uint32 f);

    /**
     * Aumenta el valor de la destreza
     *
     * @return El valor incrementado de la destreza
     */
    Uint32 aumentarDestreza(Uint32 d);

    /**
     * Aumenta el valor de la suerte
     *
     * @return El valor incrementado de la suerte
     */
    Uint32 aumentarSuerte(Uint32 s);

    /**
     * Aumenta el valor de la resistencia
     *
     * @return El valor incrementado de la resistencia
     */
    Uint32 aumentarResistencia(Uint32 r);

    /**
     * Aumenta el valor de la virtuosidad
     *
     * @return El valor incrementado de la virtuosidad
     */
    Uint32 aumentarVirtuosidad(Uint32 v);

    /**
     * Aumenta el valor de la constitucion
     *
     * @return El valor incrementado de la constitucion
     */
    Uint32 aumentarConstitucion(Uint32 c);

    /**
     * Aumenta el valor de la inteligencia
     *
     * @return El valor incrementado de la inteligencia
     */
    Uint32 aumentarInteligencia(Uint32 i);

    /**
     * Decrementa el valor del PV máximo
     *
     * @return El valor decrementado del PV máximo
     */
    Uint32 decrementarPVMax(Uint32);

    /**
     * Decrementa el valor del PV
     *
     * @return El valor decrementado del PV
     */
    Uint32 decrementarPV(Uint32 pv);
    
    /**
     * Decrementa el valor del PE máximo
     *
     * @return El valor decrementado del PE máximo
     */
    Uint32 decrementarPEMax(Uint32);

    /**
     * Decrementa el valor del PE
     *
     * @return El valor decrementado del PE
     */
    Uint32 decrementarPE(Uint32 pe);

    /**
     * Decrementa el valor de la velocidad
     *
     * @return El valor decrementado de la velocidad
     */
    Uint32 decrementarVelocidad(Uint32 v);

    /**
     * Decrementa el valor de la fuerza
     *
     * @return El valor decrementado de la fuerza
     */
    Uint32 decrementarFuerza(Uint32 f);

    /**
     * Decrementa el valor de la destreza
     *
     * @return El valor decrementado de la destreza
     */
    Uint32 decrementarDestreza(Uint32 d);

    /**
     * Decrementa el valor de la suerte
     *
     * @return El valor decrementado de la suerte
     */
    Uint32 decrementarSuerte(Uint32 s);

    /**
     * Decrementa el valor de la resistencia
     *
     * @return El valor decrementado de la resistencia
     */
    Uint32 decrementarResistencia(Uint32 r);

    /**
     * Decrementa el valor de la virtuosidad
     *
     * @return El valor decrementado de la virtuosidad
     */
    Uint32 decrementarVirtuosidad(Uint32 v);

    /**
     * Decrementa el valor de la constitución
     *
     * @return El valor decrementado de la constitución
     */
    Uint32 decrementarConstitucion(Uint32 c);

    /**
     * Decrementa el valor de la inteligencia
     *
     * @return El valor decrementado de la inteligencia
     */
    Uint32 decrementarInteligencia(Uint32 i);

protected:
    AtributoBase _base;

    Uint32 _exp;
    Uint32 _niv;

    Uint32 _expSigNiv;

    Uint32 _PVmax;
    Uint32 _PV;
    Uint32 _PEmax;
    Uint32 _PE;
    Uint32 _vel;
    Uint32 _fue;
    Uint32 _des;
    Uint32 _sue;
    Uint32 _res;
    Uint32 _vir;
    Uint32 _con;
    Uint32 _int;

friend class boost::serialization::access;
  /// Serialization function
  template<class Archive>
  void serialize(Archive& ar, const unsigned int version){
    ar & BOOST_SERIALIZATION_NVP(_base);
    ar & BOOST_SERIALIZATION_NVP(_exp);
    ar & BOOST_SERIALIZATION_NVP(_niv);
    ar & BOOST_SERIALIZATION_NVP(_expSigNiv);
    ar & BOOST_SERIALIZATION_NVP(_PV);
    ar & BOOST_SERIALIZATION_NVP(_PVmax);
    ar & BOOST_SERIALIZATION_NVP(_PE);
    ar & BOOST_SERIALIZATION_NVP(_PEmax);
    ar & BOOST_SERIALIZATION_NVP(_vel);
    ar & BOOST_SERIALIZATION_NVP(_fue);
    ar & BOOST_SERIALIZATION_NVP(_des);
    ar & BOOST_SERIALIZATION_NVP(_sue);
    ar & BOOST_SERIALIZATION_NVP(_res);
    ar & BOOST_SERIALIZATION_NVP(_vir);
    ar & BOOST_SERIALIZATION_NVP(_con);
    ar & BOOST_SERIALIZATION_NVP(_int);
  }

  Uint32 aleatorioRango(Uint32 a, Uint32 b) const;
  void subirNivel();
  //TODO calcular los coeficientes correctamente, provisionales
  double coeficiente(double n, double a = 0.1, double b = 0.002) const;
  Uint32 experienciaParaNivel(Uint32 n) const;
  
  
};

inline Uint32 Atributos::aumentarPV(Uint32 pv){
    if(_PV+pv > _PVmax){
        _PV = _PVmax;
        return _PV;
    }
    else{
        return (_PV += pv);
    }
}

inline Uint32 Atributos::aumentarPVMax(Uint32 pv){
    return (_PVmax += pv);
}

inline Uint32 Atributos::aumentarPE(Uint32 pe){
    if(_PE+pe > _PEmax){
        _PE = _PEmax;
        return _PE;
    }
    else{
        return (_PE += pe);
    }
}

inline Uint32 Atributos::aumentarPEMax(Uint32 pe){
    return (_PEmax += pe);
}

inline Uint32 Atributos::aumentarVelocidad(Uint32 v){
    return (_vel += v);
}

inline Uint32 Atributos::aumentarFuerza(Uint32 f){
    return (_fue += f);
}

inline Uint32 Atributos::aumentarDestreza(Uint32 d){
    return (_des += d);
}

inline Uint32 Atributos::aumentarSuerte(Uint32 s){
    return (_sue += s);
}

inline Uint32 Atributos::aumentarResistencia(Uint32 r){
    return (_res += r);
}

inline Uint32 Atributos::aumentarVirtuosidad(Uint32 v){
    return (_vir += v);
}

inline Uint32 Atributos::aumentarConstitucion(Uint32 c){
    return (_con += c);
}

inline Uint32 Atributos::aumentarInteligencia(Uint32 i){
    return (_int += i);
}

inline Uint32 Atributos::decrementarPVMax(Uint32 pv){
    return (_PVmax += pv);
}

inline Uint32 Atributos::decrementarPV(Uint32 pv){
    if (_PV < pv){
        _PV = 0;
        return _PV;
    }
    else
        return (_PV -= pv);
}

inline Uint32 Atributos::decrementarPEMax(Uint32 pe){
    return (_PEmax -= pe);
}

inline Uint32 Atributos::decrementarPE(Uint32 pe){
    if (_PE < pe){
        _PE = 0;
        return _PE;
    }
    else
        return (_PE -= pe);
}

inline Uint32 Atributos::decrementarVelocidad(Uint32 v){
    return (_vel -= v);
}

inline Uint32 Atributos::decrementarFuerza(Uint32 f){
    return (_fue -= f);
}

inline Uint32 Atributos::decrementarDestreza(Uint32 d){
    return (_des -= d);
}

inline Uint32 Atributos::decrementarSuerte(Uint32 s){
    return (_sue -= s);
}

inline Uint32 Atributos::decrementarResistencia(Uint32 r){
    return (_res -= r);
}

inline Uint32 Atributos::decrementarVirtuosidad(Uint32 v){
    return (_vir -= v);
}

inline Uint32 Atributos::decrementarConstitucion(Uint32 c){
    return (_con -= c);
}

inline Uint32 Atributos::decrementarInteligencia(Uint32 i){
    return (_int -= i);
}


#endif
