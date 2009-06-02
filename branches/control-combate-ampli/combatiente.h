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

#include <SDL/SDL.h>
#include <exception>

#include "atributos.h"
#include "atributos_base.h"
#include "habilidad.h"
#include "objeto.h"
#include "inventario.h"
#include "grupo.h"
#include "aleatorio.h"
#include "arma.h"
#include "armadura.h"

#include <boost/serialization/access.hpp>
#include <boost/serialization/serialization.hpp>
#include <boost/serialization/nvp.hpp>
#include <boost/serialization/map.hpp>
#include <boost/serialization/base_object.hpp>

#include "es-xml.h"

/**
 *
 * Declaración adelantada de la clase <code>Grupo</code>, necesaria para la
 * relación entre ambas clases.
 * @see grupo.h
 */
class Grupo;
class Arma;
class Armadura;

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
 * @todo Objetos equipables como espadas, armaduras y accesorios.
 *
 * @author Pablo Recio Quijano
 *
 * @date 15 de Abril de 2009
 */
class Combatiente: public Atributos {
public:

	class AtaqueFallado: public std::exception {
	public:

		const char* what() const throw () {
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
	 * @param rXML Ruta donde se almacenará el fichero serializado de este objeto.
	 * @param exp Cantidad de puntos de experiencia, la cual define el nivel del combatiente.
	 * @param aciertoArma (TEMPORAL) Valor de acierto con el arma que porta el combatiente
	 * @param armadura (TEMPORAL) Valor de la armadura equipada del combatiente
	 */
	Combatiente(std::string nombre, Uint32 id, AtributoBase atr, Grupo &grupo,
				string rXML, Arma &arma, Armadura &armadura,
				Uint32 exp = 0, Uint32 exp_ganable = 0);
	/**
	 * Construye un objeto de la clase <code>AtributoCombatiente</code> a partir de
	 * un fichero XML.
	 *
	 * @param ruta_XML Ruta al fichero que contiene el objeto que queremos
	 * deserializar.
	 */
	Combatiente(const char* ruta_XML) {
		cargar_XML(*this, ruta_XML);
	}

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

	/**
	 * Método <i>getter</i> para obtener acceso a todas las habilidades
	 * disponibles para el combatiente.
	 *
	 * @return Referencia constante al <code>map</code> de habilidades.
	 */
	const std::map<Uint32, Habilidad*>& getHabilidades() const {
		return _habilidades;
	}

	/**
	 * Método <i>getter</i> para obtener acceso a todas las habilidades
	 * disponibles para el combatiente.
	 *
	 * @return Referencia al <code>map</code> de habilidades.
	 */
	std::map<Uint32, Habilidad*>& getHabilidades() {
		return _habilidades;
	}

	Uint32 getExperienciaGanable() const {
		return _experienciaGanable;
	}

	/**
	 * Método <i>getter</i> para obtener el valor del acierto del arma del
	 * combatiente
	 *
	 * @return Valor entero sin signo de 32 bits con el acierto del arma del combatiente.
	 */
	Uint32 getAciertoArma() const {
		return _arma->getAcierto();
	}

	/**
	 * Método <i>getter</i> para obtener el valor de la armadura equipada del combatiente
	 *
	 * @return Valor entero sin signo de 32 bits con la armadura del combatiente
	 */
	Uint32 getArmadura() const {
		return _armadura->getIncrementoArmadura();
	}

	/**
	 * Método <i>getter</i> para obtener el rango de daño del arma equipada
	 *
	 * @return Par de enteros sin signo de 32 bits con el rango de daño del arma.
	 */
	std::pair<Uint32, Uint32> getRangoArma() const {
		return _arma->getRangoAtaque();
	}

	/**
	 * Método que calcula el valor de una tirada del arma
	 *
	 * @return Entero sin signo de 32 bits con el valor de una tirada del arma
	 */
	Uint32 tiradaArma() const {
		Aleatorio a;
		return a.valorEntero(getRangoArma().first, getRangoArma().second);
	}

	/**
	 * Método para añadir una habilidad determinada al combatiente.
	 *
	 * @param h Referencia a una habilidad a añadir en el combatiente.
	 */
	void addHabilidad(Habilidad& h);

	/**
	 * Este método modela el comportamiento y el alcance de un ataque simple de
	 * un combatiente. Se realizan dos tiradas, una para comprobar si se acierta
	 * el golpe, y otra para calcular el daño causado en dicho golpe.
	 * Estas tiradas dependen de los valores de destreza y fuerza del atacante,
	 * y de los valores de destreza y resistencia del objetivo, así com también
	 * influyen la armadura y las armas usadas.
	 *
	 * @param objetivo Referencia al objetivo del ataque.
	 *
	 * @return El valor del daño realizado en el golpe, por si se quisiera
	 * mostrar dicho valor.
	 * @except AtaqueFallado Es lanzada si la tirada para ver si acierta el golpe
	 * falla, por lo que el golpe se erra.
	 */
	Uint32 ataqueSimple(Combatiente& objetivo) throw (AtaqueFallado);

	/**
	 * Método que modela el comportamiento y repercusión del uso de un objeto
	 * en el inventario accesible al combatiente.
	 *
	 * @param i Clave del objeto que se quiere utilizar
	 * @param objetivo Referencia al objetivo del ataque.
	 *
	 * @return El valor del daño realizado por el objeto, por si se quisiera
	 * mostrar dicho valor.
	 * @except Inventario::ObjetoNoEnInventario Es lanzada si el objeto al cual
	 * se quiere acceder, no se encuentra en el inventario.
	 * @except Objeto::CantidadItemInsuficiente Es lanzada si no tenemos suficientes
	 * items disponibles en el inventario.
	 */
	Uint32 usarObjeto(Uint32 i, Combatiente& objetivo)
			//revisar si CantidadItem se lanza aqui
			throw (Inventario::ObjetoNoEnInventario,
			Objeto::CantidadItemInsuficiente);

	/**
	 * Método que modela el comportamiento y repercusión del uso de una habilidad
	 * especial del combatiente.
	 *
	 * @param i Clave de la habilidad que se quiere utilizar
	 * @param objetivo Referencia al objetivo del ataque.
	 *
	 * @return El valor del daño realizado por la habilidad, por si se quisiera
	 * mostrar dicho valor.
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

	/**
	 * Método <i>getter</i> para la ruta del fichero XML con el contenido
	 * serializado del objeto.
	 *
	 * @return Cadena que contiene la ruta al fichero XML.
	 */
	string getRutaXML() const {
		return _ruta_XML;
	}

	/**
	 * Método que serializa el objeto en la ruta XML del mismo, borrando
	 * lo que hubiera antes.
	 */
	void actualizarXML() {
		guardar_XML(*this, _ruta_XML.c_str());
	}
private:
	std::string _nombre;
	Uint32 _idCombatiente;
	std::map<Uint32, Habilidad*> _habilidades;
	Inventario *_inventario;
	Grupo* _grupo;
	bool _pasarTurno;
	Uint32 _experienciaGanable;
	Arma *_arma;
	Armadura *_armadura;

	friend class boost::serialization::access;

	template<class Archive>
	void serialize(Archive & ar, const unsigned int version) {
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
		ar & BOOST_SERIALIZATION_NVP(_arma);
		ar & BOOST_SERIALIZATION_NVP(_armadura);
		ar & BOOST_SERIALIZATION_NVP(_experienciaGanable);
		ar & BOOST_SERIALIZATION_NVP(_ruta_XML);
	}
};

#endif	/* _COMBATIENTE_H */

