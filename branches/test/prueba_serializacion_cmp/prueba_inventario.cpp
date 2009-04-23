#include <iostream>

#include <SDL/SDL.h>

#include "especial.h"
#include "objeto.h"
#include "inventario.h"

using namespace std;

void mostrarObjeto(Objeto O);

int main(){
  Objeto o1("Espada",1,ATAQUE,4,9,1);
  Objeto o2("Pocion", 2,CURATIVO,10,22,5);
  Objeto o3("Pua del destino", 10,ATAQUE,8,15,2);
  Objeto o4("Grifa",8,CAMBIO_ESTADO,40,70,1);

  cout << "Objetos en memoria: " << endl;
  mostrarObjeto(o1);
  mostrarObjeto(o2);
  mostrarObjeto(o3);
  mostrarObjeto(o4);
  cout << "-----------------------------" << endl;

  Inventario I;

  I.addObjeto(o1);
  I.addObjeto(o2);
  I.addObjeto(o3);
  I.addObjeto(o4);
  
 cout << "Objetos en el inventario: " << endl;
 try{
   mostrarObjeto(I.getObjeto(1));
   mostrarObjeto(I.getObjeto(2));
   mostrarObjeto(I.getObjeto(8));
   mostrarObjeto(I.getObjeto(10));
 }catch(Inventario::ObjetoNoEnInventario o){
   cerr << o.what() << endl;
 }
  cout << "-----------------------------" << endl; 

  I.getObjeto(1).usarObjeto();
  I.getObjeto(10).usarObjeto();
  I.getObjeto(10).usarObjeto();
  I.getObjeto(8).usarObjeto();

cout << "Objetos en el inventario tras usar una espada, dos puas y una grifa: " << endl;
 try{
   mostrarObjeto(I.getObjeto(1));
   mostrarObjeto(I.getObjeto(2));
   mostrarObjeto(I.getObjeto(8));
   mostrarObjeto(I.getObjeto(10));
 }catch(Inventario::ObjetoNoEnInventario o){
   cerr << o.what() << endl;
 }
  cout << "-----------------------------" << endl; 



}

void mostrarObjeto(Objeto O){
  cout << "-------------------------" << endl;
  cout << "Nombre: " << O.getNombre() << endl;
  cout << "Identificador: " << O.getIdentificador() << endl;
  cout << "Tipo: " << O.getTipoAtaque() << endl;
  cout << "Rango ataque: [" << O.getRangoAtaque().first 
       << ", " << O.getRangoAtaque().second << "]" << endl;

  cout << "Cantidad: " << O.getCantidad() << endl;  
}
