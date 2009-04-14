#include <cstdlib>
#include <ctime>

#include "atributos_base.h"
#include "atributos.h"

Atributos::Atributos(AtributoBase base, Uint32 exp /*= 0*/): _exp(exp){
  _niv = 1; /*TODO*/

  _expSigNiv = experienciaParaNivel(1);

  /*for(Uint32 i = 1 ; i <= _niv ; i++)
    _expSigNiv += experienciaParaNivel(i);*/

  while(_exp > experienciaParaNivel(_nivel)){
    _nivel++;
    _expSigNiv = experienciaParaNivel(_nivel);
  }

  _vel = base.getVelocidad() + base.getIncrementoVelocidad() * _niv;
  _fue = base.getFuerza() + base.getIncrementoFuerza() * _niv;
  _des = base.getDestreza() + base.getIncrementoDestreza() * _niv;
  _sue = base.getSuerte() + base.getIncrementoSuerte() * _niv;
  _res = base.getResistencia() + base.getIncrementoResistencia() * _niv;
  _vir = base.getVirtuosidad() + base.getIncrementoVirtuosidad() * _niv;
  _con = base.getConstitucion() + base.getIncrementoConstitucion() * _niv;
  _int = base.getInteligencia() + base.getIncrementoInteligencia() * _niv;

  float multiplicadorPV = _niv / 3; //provisional
  float multiplicadorPE = niv / 3; //provisional
  _PV = _base.getPV() + _con * multiplicadorPV;
  _PE = _base.getPE() + _int * multiplicadorPV; 
}

void Atributos::addExperiencia(Uint32 exp){
  _exp+= exp;
  while(_exp >= _expSigNiv) subirNivel();
}

Uint32 Atributos::tiradaSuerte() const{
  srand(time(0));
  return aleatorioRango(1,100) < _sue;
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

  _expSigNiv += experienciaParaNivel(_niv);
  
  _vel = _base.getVelocidad() + _base.getIncrementoVelocidad() * _niv;
  _fue = _base.getFuerza() + _base.getIncrementoFuerza() * _niv;
  _des = _base.getDestreza() + _base.getIncrementoDestreza() * _niv;
  _sue = _base.getSuerte() + _base.getIncrementoSuerte() * _niv;
  _res = _base.getResistencia() + _base.getIncrementoResistencia() * _niv;
  _vir = _base.getVirtuosidad() + _base.getIncrementoVirtuosidad() * _niv;
  _con = _base.getConstitucion() + _base.getIncrementoConstitucion() * _niv;
  _int = _base.getInteligencia() + _base.getIncrementoInteligencia() * _niv;

  float multiplicadorPV = _niv / 3; //provisional
  float multiplicadorPE = niv / 3; //provisional
  _PV = _base.getPV() + _con * multiplicadorPV; 
  _PE = _base.getPE() + _int * multiplicadorPV; 
}

Uint32 Atributos::aleatorioRango(Uint32 a, Uint32 b) const{
  return (rand()%(b-a+1)+a);
}

double Atributos::coeficiente(double n, double a, double b) const{
  return (1 + n*a + n*b*b);
}

Uint32 Atributos::experienciaParaNivel(Uint32 nivel){ //temporal, hay que ajustar para rangos de 
                                                      //niveles
  return 1000 * coeficiente(nivel);
}