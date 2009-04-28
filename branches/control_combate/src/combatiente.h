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
 * Fichero = combatiente.h
 * Autor = Pablo Recio Quijano
 * Fecha = 15 de abril de 2009
 * --------------------------------------------------------
 */

#ifndef _COMBATIENTE_H
#define	_COMBATIENTE_H

#include <iostream>
#include <map>
#include <boost/serialization/map.hpp>

#include <SDL/SDL.h>
#include <exception>

#include "atributos.h"
#include "atributos_base.h"
#include "habilidad.h"
#include "objeto.h"
#include "inventario.h"
#include "grupo.h"

#include <boost/serialization/access.hpp>

#include <boost/serialization/serialization.hpp>
#include <boost/serialization/nvp.hpp>

#include <boost/serialization/base_object.hpp>

/** 
 * 
 * Declaración adelantada de la clase <code>Grupo</code>, necesaria para la 
 * relación entre ambas clases. 
 * @see grupo.h
 */
class Grupo;

/** 
 * 
 * Clase <code>Combatiente</code>, fundamental en el motor de combate. Esta clase 
 * identifica a cada participante en una batalla. 
 *
 * Esta clase está fuertemente relacionadas con muchas otras como Grupo (al cual
 * pertenece), a Habilidad (las que puede utilizar) y a Objeto e Inventario. Además,
 * hereda de Atributos, ya que utilizaremos esos atributos y sus tiradas para modelar
 * el comportamiento matemático y aleatorio del combatiente.
 * 
 * @todo Mirar si combiene una herencia protegida en vez de publica para Combatiente.
 * @todo Objetos equipables como espadas, armaduras y accesorios.
 *
 * @author Pablo Recio Quijano
 *
 * @date 15 de Abril de 2009
 */
class Combatiente : public Atributos {
public:

    class AtaqueFallado: public std::exception{
    public:
      const char* what() const throw(){
            return "¡El ataque ha fallado!";
        }
    };
    /**
     *
     * Constructor vacio, no hace nada.
     *
     */
    Combatiente() {
    }

    /**
     * Construye un objeto de la clase <code>Combatiente</code> con los parámetros dados
     *
     * @param nombre Nombre del combatiente
     * @param id Identificador único del combatiente
     * @param atr Objeto con los atributos báse del combatiente
     * @param grupo Referencia al grupo al que pertenece el combaitente
     * @param rangoArma (TEMPORAL) Rango de daño del arma del personaje
     * @param exp Cantidad de puntos de experiencia, la cual define el nivel del combatiente.
     * @param aciertoArma
     * @param armadura
     */
    Combatiente(std::string nombre, Uint32 id, AtributoBase atr,
            Grupo &grupo, std::pair<Uint32,Uint32> rangoArma,
            Uint32 exp = 0, Uint32 aciertoArma = 15, Uint32 armadura = 20);

    /**
     *
     * Método <i>getter</i> que obtiene el nombre del combatiente actual.
     *
     * @return Cadena con el nombre del combatiente actual.
     */
    std::string getNombre() const {
        return _nombre;
    }

    /**
     *
     * Método <i>getter</i> que obtiene el valor identificativo.
     *
     * @return Entero sin signo de 32 bits con el identificador del combatiente
     */
    Uint32 getIdentificador() const {
        return _idCombatiente;
    }

    /**
     *
     * Método <i>getter</i> que obtiene la habilidad con la clave <code>i</code>
     * disponible del combatiente
     *
     * @param i Valor entero sin signo de 32 bits clave de una habilidad
     * @return Referencia constante a la habilidad con la clave <code>i</code>
     */
    const Habilidad& getHabilidad(Uint32 i) const {
        return *_habilidades.at(i);
    }

    /**
     * Método <i>getter</i> para obtener acceso al grupo al que pertenece el combatiente
     *
     * @return Referencia constante al grupo.
     */
    const Grupo& getGrupo() const {
        return *_grupo;
    }

    /**
     * Método <i>getter</i> para obtener acceso al grupo al que pertenece el combatiente
     *
     * @return Referencia al grupo.
     */
    Grupo& getGrupo() {
        return *_grupo;
    }

    /**
     * Método <i>getter</i> para obtener acceso al inventario disponible para el combatiente
     *
     * @return Referencia constante al inventario.
     */
    const Inventario& getInventario() const {
        return *_inventario;
    }

    /**
     * Método <i>getter</i> para obtener acceso al inventario disponible para el combatiente
     *
     * @return Referencia al inventario.
     */
    Inventario& getInventario() {
        return *_inventario;
    }

  const std::map<Uint32, Habilidad*>& getHabilidades() const{
    return _habilidades;
  }

  std::map<Uint32, Habilidad*>& getHabilidades(){
    return _habilidades;
  }

    Uint32 getAciertoArma() {
        return _aciertoArma;
    }

    Uint32 getArmadura() {
        return _armadura;
    }

    std::pair<Uint32, Uint32> getRangoArma() {
        return _rangoArma;
    }

    Uint32 tiradaArma(){
        return aleatorioRango(_rangoArma.first,_rangoArma.second);
    }

    /**
     * Método para añadir una habilidad determinada al combatiente.
     *
     * @param h Referencia a una habilidad a añadir en el combatiente.
     */
    void addHabilidad(Habilidad& h);

    /**
     *
     *
     * @param objetivo
     *
     * @return
     */
    Uint32 ataqueSimple(Combatiente& objetivo) throw (AtaqueFallado);

    /**
     *
     *
     * @param i
     * @param objetivo
     *
     * @return
     */
    Uint32 usarObjeto(Uint32 i, Combatiente& objetivo) //revisar si CantidadItem se lanza aqui
      throw (Inventario::ObjetoNoEnInventario, Objeto::CantidadItemInsuficiente);

    /**
     *
     *
     * @param i
     * @param objetivo
     *
     * @return
     */
    Uint32 ataqueEspecial(Uint32 i, Combatiente& objetivo);

    /**
     *
     *
     *
     * @return
     */
    Uint32 defenderse();

    /**
     *
     *
     *
     * @return
     */
    bool huir();
private:
    std::string _nombre;
    Uint32 _idCombatiente;
    std::map<Uint32, Habilidad*> _habilidades;
    Inventario *_inventario;
    Grupo* _grupo;
    bool _pasarTurno;

    //temporal:
    std::pair<Uint32, Uint32> _rangoArma;
    Uint32 _aciertoArma;
    Uint32 _armadura;

  friend class boost::serialization::access;
  template<class Archive>
  void serialize(Archive & ar, const unsigned int version)
  {
    // serialize base class information
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
    ar & BOOST_SERIALIZATION_NVP(_nombre);
    ar & BOOST_SERIALIZATION_NVP(_idCombatiente);
    ar & BOOST_SERIALIZATION_NVP(_habilidades);
    ar & BOOST_SERIALIZATION_NVP(_inventario);
    ar & BOOST_SERIALIZATION_NVP(_grupo);
    ar & BOOST_SERIALIZATION_NVP(_pasarTurno);
    ar & BOOST_SERIALIZATION_NVP(_aciertoArma);
    ar & BOOST_SERIALIZATION_NVP(_armadura);
    ar & BOOST_SERIALIZATION_NVP(_rangoArma);
  }
};

#endif	/* _COMBATIENTE_H */
