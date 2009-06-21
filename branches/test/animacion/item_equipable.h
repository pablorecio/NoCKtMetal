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
 * Fichero = item_equipable.h
 * Autor = Pablo Recio Quijano
 * Fecha = 02-jun-2009
 * --------------------------------------------------------
 */

#ifndef ITEM_EQUIPABLE_H_
#define ITEM_EQUIPABLE_H_

#include <iostream>

#include <SDL/SDL.h>

#include "especial.h"

/**
 * ItemEquipable
 */
class ItemEquipable: public Especial {
public:
	ItemEquipable() {}
	ItemEquipable(std::string nombre, Uint32 id, tipoEspecial tipo,
			Uint32 cotaInf, Uint32 cotaSup, bool equipado);
	void equiparItem(Uint32 id);

	bool isEquipado() const;
protected:
	bool _equipado;
	Uint32 _id;
};

inline ItemEquipable::ItemEquipable(std::string nombre, Uint32 id,
		tipoEspecial tipo, Uint32 cotaInf, Uint32 cotaSup, bool equipado) :
	Especial(nombre, id, tipo, cotaInf, cotaSup), _equipado(equipado) {
	_id = 0;
}

inline void ItemEquipable::equiparItem(Uint32 id){
	_id = id;
}

inline bool ItemEquipable::isEquipado() const {
	return _equipado;
}

#endif /* ITEM_EQUIPABLE_H_ */
