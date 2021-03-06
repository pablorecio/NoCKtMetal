/*
 * motor-combate.cpp
 *
 *  Created on: 06-jun-2009
 *      Author: nessa
 */

#include "motor-combate.h"
#include "atributos.h"
#include "atributos_base.h"
#include "combatiente.h"
#include "grupo.h"
#include "habilidad.h"
#include "objeto.h"
#include "inventario.h"
#include "aleatorio.h"
#include "biblioteca.h"
#include "es-xml.h"
#include "control-combate.h"


MotorCombate::MotorCombate() {
	/* Construcción e inicialización de elementos del motor de combate */
    _bib = Biblioteca();
    _bib.recargarXML("datos-xml/biblioteca.xml");
    cout << "Biblioteca cargada" << endl;

    cargar_XML(_jugador,_bib.getGrupoPrincipal().c_str());
    cout << "Nuestro grupo es: id(" << _jugador.getIdentificador() << ")" << endl;
    _jugador.mostrarGrupo();

    srand(time(0));
    cout << "Mira que de gente nos quiere pegar: "
		 << _bib.getNumeroGruposEnemigos()
		 << endl;

    Aleatorio a;
    Uint32 num_rep =
            a.valorEntero(0, _bib.getNumeroGruposEnemigos() - 1);
    _nombreEnemigos = _bib.getGruposEnemigos();

    cout << "Número elegido..." << num_rep << endl;

    _iterador = _nombreEnemigos.begin();
    for (size_t i = 0; i < num_rep; i++) {
        _iterador++;
    }

    cargar_XML(_enemigosActuales,_bib.getGrupoEnemigo(_iterador->first).c_str());
    cout << "Mamaaaa que me pegan estos: " << endl;
    _enemigosActuales.mostrarGrupo();

    _combate = ControlCombate(_jugador, _enemigosActuales);
}

void MotorCombate::asignarEnemigo(Uint32 clave){
  cargar_XML(_enemigosActuales,_bib.getGrupoEnemigo(clave).c_str());
}

void MotorCombate::ejecutar() {

    cout << endl << "--------------------------------------"
            << "------------------------------------" << endl
            << " Entrando en el motor de movimiento " << endl
            << "--------------------------------------"
            << "------------------------------------" << endl
            << endl;

    /* Lanzar motor de combate */

#ifdef DEBUG
    cout << "Combate inicializado" << endl;
#endif

    _combate.iniciarCombate();
    _combate.postCombate();

    cout << endl << "--------------------------------------"
            << "------------------------------------" << endl
            << " Saliendo del motor de combate " << endl
            << "--------------------------------------"
            << "------------------------------------" << endl
            << endl;

}
