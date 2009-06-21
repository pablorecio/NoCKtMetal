/*
 * combatiente-grafico.h
 *
 *  Created on: 20-jun-2009
 *      Author: nessa
 */

#ifndef COMBATIENTEGRAFICO_H_
#define COMBATIENTEGRAFICO_H_

#include "combatiente.h"
#include "sprite.h"

using namespace std;

class CombatienteGrafico: public Combatiente {
public:
	CombatienteGrafico();

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
	CombatienteGrafico(string nombre, Uint32 id, AtributoBase atr, Grupo &grupo,
				string rXML, Arma &arma, Armadura &armadura, const char* sprite,
				Uint32 f, Uint32 c, bool pos, Uint32 exp = 0,
				Uint32 exp_ganable = 0);

//	CombatienteGrafico(const Combatiente& c);

	Sprite* getSprite();

	void setSprite(const char* sprite, Uint32 numF, Uint32 numC);

	bool getPosNormal() const;

	void setPosNormal(bool pos);

	/**
	 * Obtener el estado del combatiente.
	 */
	Uint32 getEstado() const;

	/**
	 * Devolver el estado al inicial.
	 */
	void estadoNormal(Uint32 estado);

	/**
	 * Empeorar el estado actual del combatiente.
	 */
	void empeorarEstado();

	virtual ~CombatienteGrafico();
	CombatienteGrafico& operator= (const Combatiente& c);
private:
	Sprite _sprite;

	/* Booleano que indica si el sprite se dibujará en su posición normal, o
	 * en su posición inversa.
	 */
	bool _posNormal;

	/**
	 * Estado actual del combatiente.
	 * 0 para el estado normal, va aumentando el valor cuanto mayor sea el daño.
	 * El intervalo de valores aceptados para este estado variará en función
	 * del
	 */
	Uint32 _estado;
};


inline CombatienteGrafico::CombatienteGrafico (string nombre, Uint32 id,
		AtributoBase atr, Grupo &grupo, string rXML, Arma &arma,
		Armadura &armadura, const char* sprite,	Uint32 f, Uint32 c, bool pos,
		Uint32 exp, Uint32 exp_ganable):
			Combatiente(nombre, id, atr, grupo, rXML, arma, armadura, exp,
					exp_ganable), _sprite(sprite, f, c), _posNormal(pos) {}

inline Sprite* CombatienteGrafico::getSprite() { return &_sprite; }

inline void CombatienteGrafico::setSprite(const char* sprite, Uint32 numF,
		Uint32 numC) { _sprite = Sprite(sprite, numF, numC); }

inline bool CombatienteGrafico::getPosNormal() const { return _posNormal; }

inline void CombatienteGrafico::setPosNormal(bool pos) { _posNormal = pos; }

inline CombatienteGrafico::~CombatienteGrafico() {}

#endif /* COMBATIENTEGRAFICO_H_ */
