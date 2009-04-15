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

#include <cstdlib>
#include <ctime>

#include "especial.h"

Especial::Especial(std::string nombre, Uint32 id, tipoEspecial tipo,
		   Uint32 cotaInf, Uint32 cotaSup): _nombre(nombre), _idEspecial(id), 
						    _tipoEsp(tipo) {
  _rangoDamage = new std::pair<Uint32,Uint32>(contaInf,cotaSup);
}

Uint32 Especial::calculaDamage() const{
  //srand(time(0));
  return aleatorioRango(_rangoDamage->first, _rangoDamage->first);
}

Uint32 Especial::aleatorioRango(Uint32 a, Uint32 b) const{
  return (rand()%(b-a+1)+a);
}
