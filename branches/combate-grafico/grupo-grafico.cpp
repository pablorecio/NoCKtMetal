/*
 * grupo-grafico.cpp
 *
 *  Created on: 21-jun-2009
 *      Author: nessa
 */

#include "grupo-grafico.h"
#include "combatiente-grafico.h"
#include <vector>

using namespace std;
/*
GrupoGrafico::GrupoGrafico(Inventario& invent, bool contr, Uint32 i,
		string rXML, Pantalla* p, vector<const char*> sprites, bool izdaOdcha):
			Grupo(invent, contr, i, rXML), _pant(p) {
    _inventario = &invent;
    vector<Combatiente*> temp(4);
    _componentes = temp;
    _combGraficos = vector<CombatienteGrafico*>(4);
    _numComp = 0;

    for(size_t i=0; i < _componentes.size(); ++i) {
    	_combGraficos.at(i) = _componentes.at(i); //<dynamic_cast>
    	_combGraficos.at(i)->_sprite = Sprite(sprites.at(i), 1,1);
    }

    if(izdaOdcha) { //izda: 20, 120
    	_posIniX = 20;
    	_despX = 10;
    } else { // dcha: 280, 120
    	_posIniX = 280;
    	_despX = -10;
    }
    _posIniY = 120;
    _despY = 52;
}
*/


GrupoGrafico::GrupoGrafico(const char* ruta_XML, Pantalla* p,
		vector<const char*> sprites, bool izdaOdcha): _pant(p) {
    _combGraficos = vector<CombatienteGrafico*>(4);

    Grupo g;
    cargar_XML(g,ruta_XML);

    for(size_t i=0; i < g.getNumeroCombatientes(); ++i) {
    	Combatiente c = g.getCombatiente(i);
    	_combGraficos.at(i) = new CombatienteGrafico(c.getNombre(), c.getIdentificador(), c.getAtributosBase(), g, c.getRutaXML(), *(c.getArma()), *(c.getArmaduraReal()),sprites.at(i), 1, 1, true, c.getExperiencia(), c.getExperienciaGanable());
    	//_combGraficos.at(i)->setSprite(sprites.at(i), 1,1);
    }

    if(izdaOdcha) { //izda: 20, 120
    	_posIniX = 20;
    	_despX = 10;
    } else { // dcha: 280, 120
    	_posIniX = 280;
    	_despX = -10;
    }
    _posIniY = 120;
    _despY = 52;
}


void GrupoGrafico::mostrarGrupo() {
    for(size_t i = 0; i < _numComp ; i++) {
    	cout << _combGraficos.at(i)->getIdentificador() << " - "
			<< _combGraficos.at(i)->getNombre() << " -- PV: "
			<< _combGraficos.at(i)->getPV() << "/"
			<< _combGraficos.at(i)->getPVMax() << " -- PE: "
			<< _combGraficos.at(i)->getPE() << "/"
			<< _combGraficos.at(i)->getPEMax() << endl;
    }

    for(size_t i=0; i < _combGraficos.size(); ++i) {
    	_combGraficos.at(i)->getSprite()->dibujar(1,1,_pant->getBuffer(),
    			_posIniX + i*_despX, _posIniY + i*_despY);
    }
    _pant->volcarPantalla(_pant->getBuffer());
}
