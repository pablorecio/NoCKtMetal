/*
 * grupo-grafico.h
 *
 *  Created on: 21-jun-2009
 *      Author: nessa
 */

#ifndef GRUPOGRAFICO_H_
#define GRUPOGRAFICO_H_

#include <vector>
#include "grupo.h"
#include "combatiente-grafico.h"
#include "pantalla.h"

using namespace std;

class GrupoGrafico: public Grupo {
public:
	GrupoGrafico();

	/**
	 * Constructor de un objeto de la clase <code>Grupo</code>, determinando el
	 * inventario del que dispone, y si es controlable o no.
	 *
	 * @param invent Inventario sobre el cual trabaja todos los miembros
	 * del grupo.
	 * @param contr Determina si el grupo es controlable o no.
	 * @param rXML Ruta donde se almacenará el fichero serializado de este objeto.
	 *
	GrupoGrafico(Inventario& invent, bool contr, Uint32 i, string rXML,
			Pantalla* p, vector<const char*> sprites);
*/

	/**
	 * Construye un objeto de la clase <code>Grupo</code> a partir de
	 * un fichero XML.
	 *
	 * @param ruta_XML Ruta al fichero que contiene el objeto que queremos
	 * deserializar.
	 */
	GrupoGrafico(const char* ruta_XML, Pantalla* p, vector<const char*> sprites,
			bool izdaOdcha);

	void mostrarGrupo();

	void setPosicion(bool izdaOdcha);

	virtual ~GrupoGrafico();
private:
	vector<CombatienteGrafico*> _combGraficos;
	Pantalla* _pant;
	Uint32 _posIniX;
	Uint32 _posIniY;
	Sint32 _despX;
	Sint32 _despY;
};

inline GrupoGrafico::GrupoGrafico() {}
inline GrupoGrafico::~GrupoGrafico() {}
inline void GrupoGrafico::setPosicion(bool izdaOdcha) {
	if (izdaOdcha) { // Izda: posición inicial = (20, 120)
		_posIniX = 20;
	} else { // Dcha: posición incial = (280, 120)
		_posIniX = 280;
	}
	_posIniY = 120;
}

#endif /* GRUPOGRAFICO_H_ */
