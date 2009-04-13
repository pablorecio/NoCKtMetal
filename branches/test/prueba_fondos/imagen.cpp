

#include <iostream>
#include <SDL/SDL_image.h>

#include "tile.h"
#include "imagen.h"

using namespace std;

void Imagen::inicializar(SDL_Surface *p)
{
  pantalla = p;
  
  /* tamaño del fondo final (siempre mayor o igual que la pantalla*/
  alto= p->h; 
  ancho= p->w;
}

void Imagen::dibujarFondo1()
{
  Tile acero1("../prueba_tiles/acero1.png");
  SDL_Rect origen,destino;

  cout << "PANTALLA: (" << pantalla->h << "," << pantalla->w << ")." << endl;

  origen.w = acero1.anchura();
  origen.h = acero1.altura();
  origen.x = 0;
  origen.y = 0;
  
  for(int i=0; i<pantalla->w; i=i+30)
    for(int j=0; j<pantalla->h; j=j+30){
      destino.x=i;
      destino.y=j;
      
      cout << "Dibujo en ("<< i << "," << j << ")." << endl;
      
      SDL_BlitSurface(acero1.imagen(), &origen, pantalla, &destino);
    }


  Tile acero2("../prueba_tiles/acero2.png");
  origen.w = acero2.anchura();
  origen.h = acero2.altura();
  origen.x = 0;
  origen.y = 0;

  for(int i=100; i<pantalla->w-100; i=i+30)
    for(int j=100; j<pantalla->h-100; j=j+30){
      destino.x=i;
      destino.y=j;
      
      cout << "Dibujo en ("<< i << "," << j << ")." << endl;
      
      SDL_BlitSurface(acero2.imagen(), &origen, pantalla, &destino);
    }
  
}
