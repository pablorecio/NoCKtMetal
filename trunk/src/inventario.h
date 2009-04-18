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
 * Fichero = inventario.h
 * Autor = Pablo Recio Quijano
 * Fecha = 16 de abril de 2009
 * --------------------------------------------------------
 */

#ifndef _INVENTARIO_H
#define	_INVENTARIO_H

#include <iostream>
#include <map>
#include <exception>

#include <SDL/SDL.h>

#include "objeto.h"

/**
 * Clase que utilzamos para encapsular un conjunto único de objetos, de forma
 * que podamos modelar el inventario del que dispone un grupo, el cual es 
 * accesible para cada uno de sus miembros.
 */
class Inventario {
public:
  /**
   * Clase de excepción que nos servirá para indicar que el objeto al que 
   * queremos acceder o insertar, ya se encuentra disponible en el inventario
   */
  class ObjetoEnInventario: public std::exception{
  public:
    const char* what() const throw(){
      return "El objeto ya se encuentra en el inventario";
    }
  };
  
  /**
   * Clase de excepción que nos servirá para indicar que el objeto al que 
   * queremos acceder no se encuentra disponible en el inventario.
   */
  class ObjetoNoEnInventario: public std::exception{
  public:
    const char* what() const throw(){
      return "El objeto no se encuentra en el inventario";
    }
  };

  /** 
   * Constructor vacio, no hace nada. 
   */  
  Inventario(){}
  
  /** 
   * Método que añade al inventario un objeto dado, copiándolo en
   * memoria.
   * 
   * @param obj Referencia constante del objeto que queremos insertar
   * en el inventario.
   *
   * @exception ObjetoEnInventario Lanza esta excepción si el objeto
   * ya se encuentra disponible en el inventario
   * @todo ¿Quitar excepción y aumentar la cantidad del objeto?
   */
  void addObjeto(const Objeto& obj) throw (ObjetoEnInventario);

  /** 
   * Método <i>getter</i> para acceder a un objeto determinado del 
   * inventario, mediante una referencia constante.
   * 
   * @param i Identificador del objeto al cual queremos acceder
   * 
   * @return Referencia constante al objeto que tiene como 
   * identificador <code>i</code> 
   *
   * @exception ObjetoNoEnInventario Lanza esta excepción si el objeto
   * no se encuentra disponible en el inventario
   */
  const Objeto& getObjeto(Uint32 i) const throw (ObjetoNoEnInventario);

  /** 
   * Método <i>getter</i> para acceder a un objeto determinado del 
   * inventario, mediante una referencia.
   * 
   * @param i Identificador del objeto al cual queremos acceder
   * 
   * @return Referencia al objeto que tiene como identificador <code>i</code> 
   *
   * @exception ObjetoNoEnInventario Lanza esta excepción si el objeto
   * no se encuentra disponible en el inventario
   */
  Objeto& getObjeto(Uint32 i) throw (ObjetoNoEnInventario);

  /**
   * Método <i>getter</i> para obtener acceso a la estructura de datos que contiene
   * el inventario en si.
   *
   * @return Referencia constante al <code>map</code> con el inventario completo.
   */
  const std::map<Uint32,Objeto>& getInventarioCompleto() const { return _inventario; }

  /**
   * Método <i>getter</i> para obtener acceso a la estructura de datos que contiene
   * el inventario en si.
   *
   * @return Referencia al <code>map</code> con el inventario completo.
   */
  std::map<Uint32,Objeto>& getInventarioCompleto() { return _inventario; }

  /** 
   * Método para borrar un objeto determinado del Inventario.
   * 
   * @param i Identificador del objeto el cual queremos borrar.
   *
   * @exception ObjetoNoEnInventario Lanza esta excepción si el objeto
   * no se encuentra disponible en el inventario
   */  
  void borrarObjeto(Uint32 i) throw (ObjetoNoEnInventario);
private:
  std::map<Uint32,Objeto> _inventario;
  
};

#endif	/* _INVENTARIO_H */

