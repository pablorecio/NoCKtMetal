
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
 * Fichero: dialogo.cpp
 * Autor: Rosa María Durante Lerate
 * Fecha: 24 05 2009
 * Proyecto: NoCKt Metal
 */

#include "dialogo.h"
#include <iostream>
#include "sistema.h"
using namespace std;


Dialogo::Mensaje::Mensaje(Uint32 personaje_hablador, const char* msj):pers_(personaje_hablador), mens_(msj) {}
// Suponemos personaje_hablador [0-1]: 0 Principal, 1 Secundario.

// Ya se ha tenido que iniciar el subsistema para poder crear objetos.
Dialogo::Dialogo(std::vector<Dialogo::Mensaje> m, Pantalla& p, 
	Uint32 rP1, Uint32 gP1, Uint32 bP1, Uint32 rP2, Uint32 gP2, Uint32 bP2):
  p_(&p){

  iniciarSubsistemaTTF();

  cout << "cargando los mensajes" << endl;
  for(Uint32 i=0; i<m.size(); i++)
    mensajes_.push_back(m.at(i));
  
  cout << "definiendo colores de la fuente" << endl;
  c1.r=rP1; c1.g=gP1; c1.b=bP1; 
  c2.r=rP2; c2.g=gP2; c2.b=bP2;

  cout << "definiendo tipo de la fuente" << endl;
  // tipo de la fuente del diálogo. Suponemos siempre la misma.
  tipoFuente_ = TTF_OpenFont("fuentes/FontMenu.ttf", 15);

  SDL_Rect r1, r2;

  SDL_Surface *texto1, *texto2;

  for(size_t i=0; i<mensajes_.size(); i++){
    p_->volcarPantalla(p_->getBuffer(), p_->getMovimiento());
    if(mensajes_[i].Personaje() == 0){
      // Cargamos el mensaje del jugador principal
      texto1 = TTF_RenderText_Blended(tipoFuente_, mensajes_.at(i).mensaje(), c1);
      // Comenzará en la esquina superior izquierda.
      r1.x = 10;
      r1.y = 10;
      r1.h = texto1->h;
      r1.w = texto1->w;
      p_->volcarPantalla(texto1, NULL, p_->getMovimiento(), &r1);
    }
    else{
      texto2 = TTF_RenderText_Blended(tipoFuente_, mensajes_[i].mensaje(), c2);
      r2.x = 10;
      r2.y = 340;
      r2.h = texto2->h;
      r2.w = texto2->w;
      
      p_->volcarPantalla(texto2, NULL, p_->getMovimiento(), &r2);
    }
    
    // Actualizamos toda la pantalla para poder borrar la frase anterior. 
    // p_->volcarPantalla(p_->getFondo());
    // p_->volcarPantalla(p_->getBuffer());
    p_->volcarPantalla(p_->getMovimiento());
    SDL_Delay(3000);
    // Limpiamos el buffer para no superponer las frases.
    p_->limpiarBuffer(p_->getMovimiento());
  }
  
}
