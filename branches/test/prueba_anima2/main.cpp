// Listado: main.cpp
//
// Programa de prueba de la clase Imagen

#include <iostream>
#include <SDL/SDL.h>

#include "imagen.h"
#include "personaje.h"
#include "pantalla.h"

using namespace std;

int main () {

  if(SDL_Init(SDL_INIT_VIDEO) < 0) {
    cerr << "No se pudo iniciar SDL: " << SDL_GetError() << endl;
    exit(1);
  }

  Pantalla pant;
  pant.rellenarPantalla(pant.getBuffer());
  pant.volcarPantalla(pant.getBuffer());

  cout << "pantalla iniciada" << endl;

  Uint32 **matriz_para_dibujar;
  matriz_para_dibujar= (Uint32**)malloc(sizeof(Uint32*)*48);
  for(Uint32 i=0; i<48; i++){
    matriz_para_dibujar[i] = (Uint32*)malloc(sizeof(Uint32)*36);
  }
  
  cout << "matriz creada" << endl;

  for(Uint32 i=0; i<48; i++){
    for(Uint32 j=0; j<36; j++){
      if(i < 24){
	if(j < 18)
	  matriz_para_dibujar[i][j]=0;
	else
	  matriz_para_dibujar[i][j]=1;
      }
      else{
	if(j < 18)
	  matriz_para_dibujar[i][j] = 2;
	else
	  matriz_para_dibujar[i][j] = 3;
      }
	 
    }
  }

  cout << "matriz inicializada" << endl;
  /*for(Uint32 i=0; i<5; i++){
    for(Uint32 j=0; j<5; j++)
      cout << matriz_para_dibujar[i][j] << endl;
      }*/

  Tile t1("../prueba_tiles/suelo.png");
  Tile t2("../prueba_tiles/piedra3.png");
  Tile t3("../prueba_tiles/tierra.png");
  Tile t4("../prueba_tiles/oscuro.png");

  cout << "tiles creados" << endl;
  
  Imagen i((Uint32)48, (Uint32)36, matriz_para_dibujar);
  
  cout << "imagen creada" << endl;

  i.relacionarTile(0,t1);
  i.relacionarTile(1,t2);
  i.relacionarTile(2,t3);
  i.relacionarTile(3,t4);

  cout << "tiles relacionados" << endl;

  i.dibujarFondo(5,0,pant.getBuffer());
  pant.volcarPantalla(pant.getBuffer());

  cout << "dibujado en pantalla" << endl;

  Sprite baldito("baldos.png",4,4,16);
  Personaje baldos(0);

  baldos.dibujadoPor(baldito);
  baldos.animadoEn(pant);

  baldos.setRango(3,3,4,4);

  baldos.setPosicion();


  SDL_Event evento;

  int repeat = SDL_EnableKeyRepeat(20,50);

  if(repeat < 0) {
    cerr << "No se pudo establecer el modo repetición "
	 << SDL_GetError() << endl;
    exit(1);
  }

  else {
    cout << "Modo repetición activado:\n "
	 << " Retardo: " << SDL_DEFAULT_REPEAT_DELAY
	 << "\nIntervalo: " <<SDL_DEFAULT_REPEAT_INTERVAL << endl;
  }
  
  int x=0, y=0;

  for( ; ; ) {
    while(SDL_PollEvent(&evento)) {  
      if(evento.type == SDL_KEYDOWN) {

	switch(evento.key.keysym.sym){

	case SDLK_DOWN: 
	  if(baldos.fueraRango(baldos.getX(), baldos.getY()+1)){
	    y++; // title abajo
	    i.dibujarFondo(x,y,pant.getMovimiento());
	    baldos.dibujarPosicionFrente();
	   }
	  else{
	    baldos.moverAbajo(0,1);
	  }
	  break;

	case SDLK_UP:
	  if(baldos.fueraRango(baldos.getX(), baldos.getY()-1)){
	    y--; // title arriba 
	    i.dibujarFondo(x,y,pant.getMovimiento());
	    baldos.dibujarPosicionEspaldas();
	  }
	  else{
	    baldos.moverArriba(0,1);
	  }
	  break;
	  
	case SDLK_RIGHT: 
	  if(baldos.fueraRango(baldos.getX()+1, baldos.getY())){
	    x++; // title derecha
	    i.dibujarFondo(x,y,pant.getMovimiento());
	    baldos.dibujarPosicionLatDcha();
	  }
	  else{
	    baldos.moverDcha(0,1);
	  }
	  break;

	case SDLK_LEFT: 
	  if(baldos.fueraRango(baldos.getX()-1, baldos.getY())){
	    x--; // title izquierda
	    i.dibujarFondo(x,y,pant.getMovimiento());
	    baldos.dibujarPosicionLatIzda();
	  }
	  else{
	    baldos.moverIzda(0,1);
	  }
	  break;

	default: break;
	}
	pant.volcarPantalla(pant.getMovimiento());
	
	if(evento.key.keysym.sym == SDLK_ESCAPE)
	  return 0;
      }
      if(evento.type == SDL_QUIT)
	return 0;
    }
  }


}
