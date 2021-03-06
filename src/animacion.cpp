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
 * Fichero: animacion.cpp
 * Autor: Noelia Sales Montes
 * Fecha: 19 de abril de 2009
 * Proyecto: NoCKt Metal
 */

#include <iostream>

#include <vector>
#include <set>

#include "personaje.h"
#include "animacion.h"
#include "evento.h"
#include "imagen.h"
#include "npj.h"
#include "dialogo.h"
#include "motor-combate.h"
using namespace std;

Animacion::Animacion() {
    _evento = new Evento();
}

Animacion::Animacion(Pantalla *p, Evento* e): _pant(p), _evento(e) { }

Animacion::~Animacion() { }

void Animacion::inicializarAnimacion() {
    /* Inicializamos el mapa */
 
  cout << "inicializarAnimacion" << endl;
  
  vector<vector<Uint32> > matriz;
  vector<Uint32> auxiliar(36);

  for(Uint32 i=0; i<48; i++)
    matriz.push_back(auxiliar);

  for (Uint32 j = 0; j < 48; j++) {
    for(Uint32 i = 0; i < 36; i++) {
      matriz[j][i] = 6;
      if(j <= 6 || j >= 40 || i <= 4 || i >= 31) {
	matriz[j][i] = 1;
      }
      if(i == 5 && j > 6 && j < 40) {
                matriz[j][i] = 5;
      }
      if(i == 6 && j > 6 && j < 40) {
	matriz[j][i] = 4;
      }
      if(i == 17 && j > 10 && j < 30) {
	matriz[j][i] = 5;
      }
    }
  }
  
  cout << "matriz de tiles echo" << endl;

  Uint32 fondoX = 10, fondoY = 10;

  std::map<Uint32,Tile> tiles;
  tiles.insert(make_pair(1,Tile("./tiles/piedra.png", true)));
  tiles.insert(make_pair(2,Tile("./tiles/arena.png")));
  tiles.insert(make_pair(3,Tile("./tiles/madera.png", false)));
  tiles.insert(make_pair(4,Tile("./tiles/ladrillos.png", true)));
  tiles.insert(make_pair(5,Tile("./tiles/ladrillosTope.png", true)));
  tiles.insert(make_pair(6,Tile("./tiles/metal.png")));
  
  cout << "imagen!" << endl;
  _imag = new Imagen(48, 36, fondoX, fondoY, *_pant, matriz, tiles);
  
  cout << "dibujar fondoo!" << endl;
  _imag->dibujarFondo();

  cout << "personaje" << endl;
  /* Personaje */
  _principal = new Personaje(1,1,1,30,_pant, "./sprites/manolo.png");
  _principal->setRango(2, 2);
  _principal->setPosicion();
  _principal->setMapa(fondoX + _principal->getPantX(),
		      fondoY + _principal->getPantY());
  _principal->setVelocidad(80);
  _principal->dibujarPosicionFrente(); 

  _pant->volcarPantalla(_pant->getBuffer());

  cout << "NPJS" << endl;
  _persSecs.push_back(NPJ(0,23,23,"./sprites/baldos.png",_pant, _imag->getCX(), _imag->getCY()));
  _persSecs.push_back(NPJ(1,14,14,"./sprites/dentacos.png",_pant, _imag->getCX(), _imag->getCY()));

  for(Uint32 i=0; i<_persSecs.size(); i++){
    _imag->setColisionable(_persSecs.at(i).getX(), _persSecs.at(i).getY(), 1);
    _imag->setInteractuable(_persSecs.at(i).getY(), _persSecs.at(i).getY(), 1);

    if(_persSecs.at(i).dentroPantalla())
      _persSecs.at(i).dibujarPosicionFrente();
  }
  _pant->volcarPantalla(_pant->getBuffer());
  

  
}

bool Animacion::procesarAccion() {
  /* Cargamos las posiciones iniciales del personaje y del fondo */
  Uint32 x = _principal->getPantX();
  Uint32 y = _principal->getPantY();
  Uint32 mx = _principal->getMapaX();
  Uint32 my = _principal->getMapaY();
  Sint32 cx = _imag->getCX();
  Sint32 cy = _imag->getCY();
  
  /* Comprobación de qué npjs están ahora dentro de la pantalla*/
  for(Uint32 i=0; i<_persSecs.size(); i++){
    _persSecs.at(i).dentroPantalla(cx,cy);
  }
  /* Movimiento actual tomado como NULO */
  _mov = NULO;

  char dir = ' ';
  
  /* Lectura del nuevo evento */
  switch (_evento->getEvento()) {
  case SALIR:
    cout << "Saliendo de la ejecucion del programa" << endl;
    return true;
  case MENU:
    cout << "Desea ver el menu... va a tener que esperar un poco..." << endl;
    break;
  case ACEPTAR: {
    int x,y;
    _pant->volcarPantalla(_pant->getFondo());
    if(_imag->isInteractuable(mx+1, my)){
      x = mx+1; y = my;
      cout << "mx+1,my: " << _imag->isInteractuable(mx+1,my) << endl;
      persAactuar(mx+1,my).dibujarPosicion(mx+1,my,_principal->getMapaX(), _principal->getMapaY());
      _principal->dibujarPosicionLatDcha();
    } else if (_imag->isInteractuable(mx-1,my)){
      x = mx-1; y = my; 
      cout << "mx-1,my: " << _imag->isInteractuable(mx-1,my) << endl;
      persAactuar(mx-1,my).dibujarPosicion(mx-1,my,_principal->getMapaX(), _principal->getMapaY());
      _principal->dibujarPosicionLatIzda();
    } else if(_imag->isInteractuable(mx,my+1)){
      x = mx; y = my+1;
      cout << "mx,my+1: " << _imag->isInteractuable(mx,my+1) << endl;
      _principal->dibujarPosicionFrente();
      persAactuar(mx,my+1).dibujarPosicion(mx,my+1,_principal->getMapaX(), _principal->getMapaY());
    } else if(_imag->isInteractuable(mx,my-1)){
      x = mx; y = my-1;
      cout << "mx,my-1: " << _imag->isInteractuable(mx,my-1) << endl;
      persAactuar(mx,my-1).dibujarPosicion(mx,my-1,_principal->getMapaX(), _principal->getMapaY());
      _principal->dibujarPosicionEspaldas();
    }
    _pant->volcarPantalla(_pant->getBuffer());
    // for(size_t i=0; i<cozaz.size(); i++)
      // 	switch(cozaz.at(i)){
      // 	case NPJ::DIALOGO: cout << "DIALOGO" << endl; break;
      // 	case NPJ::OBJETO: cout << "OBJETO" << endl; break;
      // 	case NPJ::PELEA: cout << "PELEA" << endl; break;
      // 	default: break;
      // 	}
      
      // cout << "Ha aceptado algo... Pero aqui no sirve de nada... "
      // 	   << " eso solo vale en los menus..." << endl;
    
    if(persAactuar(x,y).getId() == 0) {
      dialogos(1);
      iniciarMotorCombate();
    }
    else
      dialogos(2);
    
    } 
      break;
      
    case ATRAS:
        cout << "Ha rechazado algo... eso solo sirve en un menu... "
                << endl;
        break;
    case ARRIBA:
        dir = 'u';
        y = _principal->getPantY() - 1;
        my = _principal->getMapaY() - 1;
        cy = _imag->getCY() - 1;
        _mov = SUBIR;
        break;
    case ABAJO:
        dir = 'd';
        y = _principal->getPantY() + 1;
        my = _principal->getMapaY() + 1;
        cy = _imag->getCY() + 1;
        _mov = BAJAR;
        break;
    case IZQUIERDA:
        dir = 'l';
        x = _principal->getPantX() - 1;
        mx = _principal->getMapaX() - 1;
        cx = _imag->getCX() - 1;
        _mov = IZDA;
        break;
    case DERECHA:
        dir = 'r';
        x = _principal->getPantX() + 1;
        mx = _principal->getMapaX() + 1;
        cx = _imag->getCX() + 1;
        _mov = DCHA;
        break;
    default:
        break;
    }

    /* Si la opción elegida es realizar un movimiento... */
    if (_mov != NULO) {
        /* Si se puede mover a la siguiente posicion (no colisionable) */
        if (!_imag->isColisionable(mx, my)) {
            actualizarMapa();
            /* Si el movimiento queda fuera del rango de pantalla del personaje,
             * se moverá de forma estática, desplazándose el fondo por debajo */
            if (_principal->fueraRango(x, y)) {
                hacerMovimientoEstatico(cx, cy, dir);
		
            } else {
	      /* En caso de que se desplace el personaje, el fondo quedará tal y
	       * como estaba (por lo que no tendremos que pintarlo de nuevo,
	       * tan sólo hemos de volcarlo repetidas veces desde el buffer). */
	      hacerMovimientoDinamico();
	    } 
	    
	} else {
	  cout << "COLISION EN (" << mx << ", " << my << ")" << endl;
	  dibujarPosicionEstatica();
	  
        }
	
	//_pant->volcarPantalla(_pant->getBuffer());
    }
    return false;
}

void Animacion::hacerMovimientoEstatico(Sint32 x, Sint32 y, char dir) {
  /* Mientras necesitemos mover al personaje */
  for (Sint32 sec = _principal->getSecuenciasMovimiento() - 1; sec >= 0;
       --sec) {
    /* Desplazamos el mapa */
    _imag->dibujarSecuencia(dir, _principal->getSecuenciasMovimiento() - sec,
			    _principal->getSecuenciasMovimiento());
    
    /* Mover los npjs que están encima del pj primero.*/
    for(Uint32 i=0; i<_persSecs.size(); i++){
      _persSecs.at(i).dentroPantalla(_imag->getCX(), _imag->getCY(), 
				     _principal->getSecuenciasMovimiento() - sec, dir);	  
      if(_persSecs.at(i).dentroPantalla() && _principal->getMapaY() > _persSecs.at(i).getY()){
	_persSecs.at(i).dibujarPosicionFrente();
      }
    }

    /* Mover el personaje (autovolcado en buffer) */
    mover(sec, 0);
    
    /* Mover los npjs que están debajo del pj despues.*/
    for(Uint32 i=0; i<_persSecs.size(); i++){
      _persSecs.at(i).dentroPantalla(_imag->getCX(), _imag->getCY(), 
				     _principal->getSecuenciasMovimiento() - sec, dir);	  
      if(_persSecs.at(i).dentroPantalla() && _principal->getMapaY() <= _persSecs.at(i).getY()){
	_persSecs.at(i).dibujarPosicionFrente();
      }
    }
    
    /* Pantalla visible */
    _pant->volcarPantalla(_pant->getBuffer());
  }
}

void Animacion::hacerMovimientoDinamico() {
  /* Mientras necesitemos mover al personaje */
  for (Sint32 sec = _principal->getSecuenciasMovimiento() - 1; sec >= 0;
       --sec) {
    /* Volcar fondo en buffer */
    _pant->volcarPantalla(_pant->getFondo(), _pant->getBuffer());
    /* primero npj de arriba*/
    for(Uint32 i=0; i<_persSecs.size(); i++){
      if(_persSecs.at(i).dentroPantalla() && _principal->getMapaY() > _persSecs.at(i).getY()){
	_persSecs.at(i).dibujarPosicionFrente();
      }
    }
    /* Volcar seccion de movimiento del PJ en buffer */
    mover(sec, _principal->getDesp(sec));
    /* dp npjs de abajo. */
    for(Uint32 i=0; i<_persSecs.size(); i++){
      if(_persSecs.at(i).dentroPantalla() && _principal->getMapaY() <= _persSecs.at(i).getY()){
	_persSecs.at(i).dibujarPosicionFrente();
      }
    }
    _pant->volcarPantalla(_pant->getBuffer());
  }
  
  /* En función de la orientación del movimiento, indicamos que se ha
   * producido una variación en la posición de pantalla medida en casillas */
  switch (_mov) {
  case SUBIR:
    _principal->subirEnPantalla();
    break;
  case BAJAR:
    _principal->bajarEnPantalla();
    break;
  case IZDA:
    _principal->izdaEnPantalla();
    break;
  case DCHA:
    _principal->dchaEnPantalla();
    break;
  default:
    break;
  }
}

void Animacion::mover(Uint32 sec, Uint32 desp) {
  switch (_mov) {
  case SUBIR:
    _principal->moverArriba(sec, desp);
    break;
  case BAJAR:
    _principal->moverAbajo(sec, desp);
    break;
  case IZDA:
    _principal->moverIzda(sec, desp);
    break;
  case DCHA:
    _principal->moverDcha(sec, desp);
    break;
  default:
    break;
  }
}

void Animacion::actualizarMapa() {
  switch (_mov) {
  case SUBIR:
    _principal->subirEnMapa();
    break;
  case BAJAR:
    _principal->bajarEnMapa();
    break;
  case IZDA:
    _principal->izdaEnMapa();
    break;
  case DCHA:
    _principal->dchaEnMapa();
    break;
  default:
    break;
  }
}

void Animacion::dibujarPosicionEstatica() {
    /* Mientras necesitemos mover al personaje */
  for (Sint32 sec = _principal->getSecuenciasMovimiento() - 1; sec >= 0;
       --sec) {
    /* Volcar fondo en buffer */
    _pant->volcarPantalla(_pant->getFondo(), _pant->getBuffer());
    /* Mover el personaje (autovolcado en buffer) */
    for(Uint32 i=0; i<_persSecs.size(); i++){
      if(_persSecs.at(i).dentroPantalla() && _principal->getMapaY() > _persSecs.at(i).getY()){
     	_persSecs.at(i).dibujarPosicionFrente();
      }
    }
    mover(sec, 0);
    for(Uint32 i=0; i<_persSecs.size(); i++){
      if(_persSecs.at(i).dentroPantalla() && _principal->getMapaY() <= _persSecs.at(i).getY()){
     	_persSecs.at(i).dibujarPosicionFrente();
      }
    }
    /* Pantalla visible */
    _pant->volcarPantalla(_pant->getBuffer());
  }
}


NPJ& Animacion::persAactuar(Uint32 mx, Uint32 my) // posicion del npj.
{//.dibujarPosicion(mx+1,my,_principal->getMapaX(), _principal->getMapaY());
  
  for(Uint32 i =0; _persSecs.size(); i++){
    if(_persSecs.at(i).getX() == mx && _persSecs.at(i).getY() == my)
      return _persSecs.at(i);
  }
  
}



void Animacion::dialogos(Uint32 i)
{
  vector<Dialogo::Mensaje> aux;
  switch(i){
  case 1: {
    aux.clear();
    aux.push_back(Dialogo::Mensaje(0, "hola! que tal!"));
    aux.push_back(Dialogo::Mensaje(1, "no muy bien :("));
    aux.push_back(Dialogo::Mensaje(0, "que te pasa colega?"));
    aux.push_back(Dialogo::Mensaje(1, "unos kinkis que me an destrozao la harly"));
    aux.push_back(Dialogo::Mensaje(1, "no me dejan vivir en paz :("));
    aux.push_back(Dialogo::Mensaje(0, "que dices!!!"));
    aux.push_back(Dialogo::Mensaje(1, "si quilla, estoy desanimao..."));
    aux.push_back(Dialogo::Mensaje(0, "se van a enterar de lo que es bueno esos kinkis! vamos!!"));
  } break;
    
  case 2:{
    aux.clear();
    aux.push_back(Dialogo::Mensaje(0, "Que de tiempo Dentacos!"));
    aux.push_back(Dialogo::Mensaje(1, "Holaa!! ^^ que alegria me da verte"));
    aux.push_back(Dialogo::Mensaje(0, "Si si y a mi :D como estas?"));
    aux.push_back(Dialogo::Mensaje(1, "bien bien! y tu? como es que estas por aqui?"));
    aux.push_back(Dialogo::Mensaje(0, "pues estoy buscando a Baldos"));
    aux.push_back(Dialogo::Mensaje(1, "a si? creo que lo e visto... hacia el sur"));
    aux.push_back(Dialogo::Mensaje(0, "ahh gracias!! voy hacia alli :P"));
    aux.push_back(Dialogo::Mensaje(1, "de nada mujer!! adios!! "));
    aux.push_back(Dialogo::Mensaje(0, "adioss!!"));  
  }
    break;
  default: break;
  }
  cout << "comienza el diálogo!!" << endl;
  Dialogo a2(aux, *_pant, 0,0,0,0,0,0);
}


void Animacion::iniciarMotorCombate()
{
  MotorCombate a;
  a.asignarEnemigo(70);
  a.ejecutar();
}
