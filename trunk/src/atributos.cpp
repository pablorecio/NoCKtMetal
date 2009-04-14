#include <cstdlib>
#include <ctime>

#include "atributos_base.h"
#include "atributos.h"

Atributos::Atributos(AtributoBase base, Uint32 exp /*= 0*/): _exp(exp){
  _niv = 0; /*TODO*/
  
  _PV = 0; /*TODO*/
  _PE = 0; /*TODO*/

  _vel = base.getVelocidad + base.getIncrementoVelocidad() * _niv;
  _fue = base.getFuerza + base.getIncrementoFuerza() * _niv;
  _des = base.getDestreza + base.getIncrementoDestreza() * _niv;
  _sue = base.getSuerte + base.getIncrementoSuerte() * _niv;
  _res = base.getResistencia + base.getIncrementoResistencia() * _niv;
  _vir = base.getVirtuosidad + base.getIncrementoVirtuosidad() * _niv;
  _con = base.getConstitucion + base.getIncrementoConstitucion() * _niv;
  _int = base.getInteligencia + base.getIncrementoInteligencia() * _niv;
}

Uint32 Atributos::tiradaSuerte() const{
  srand(time(0));
  return aleatorioRango(1,100) < sue_;
}

Uint32 Atributos::tiradaVelocidad() const { 
  return _vel * (tiradaSuerte() + 1);
}

Uint32 Atributos::tiradaFuerza() const { 
  return _fue * (tiradaSuerte() + 1);
}

Uint32 Atributos::tiradaDestreza() const { 
  return _des * (tiradaSuerte() + 1);
}

Uint32 Atributos::tiradaResistencia() const{ 
  return _res * (tiradaSuerte() + 1);
}

Uint32 Atributos::tiradaVirtuosidad() const{ 
  return _vir * (tiradaSuerte() + 1);
}

Uint32 Atributos::tiradaConstitucion() const{ 
  return _con * (tiradaSuerte() + 1);
}

Uint32 Atributos::tiradaInteligencia() const{ 
  return _int * (tiradaSuerte() + 1);
}

void Atributos::subirNivel(){
  _niv++;
  
  _PV = 0; /*TODO*/
  _PE = 0; /*TODO*/

  _vel = base.getVelocidad + base.getIncrementoVelocidad() * _niv;
  _fue = base.getFuerza + base.getIncrementoFuerza() * _niv;
  _des = base.getDestreza + base.getIncrementoDestreza() * _niv;
  _sue = base.getSuerte + base.getIncrementoSuerte() * _niv;
  _res = base.getResistencia + base.getIncrementoResistencia() * _niv;
  _vir = base.getVirtuosidad + base.getIncrementoVirtuosidad() * _niv;
  _con = base.getConstitucion + base.getIncrementoConstitucion() * _niv;
  _int = base.getInteligencia + base.getIncrementoInteligencia() * _niv;
}

Uint32 Atributos::aleatorioRango(Uint32 a, Uint32 b) const{
  return (rand()%(b-a+1)+a);
}
