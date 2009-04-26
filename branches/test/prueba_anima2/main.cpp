#include <iostream>
#include <SDL/SDL.h>

#include "sprite.h"
#include "personaje.h"
#include "pantalla.h"
#include "imagen.h"
#include "tile.h"

using namespace std;



void MovimientoEstatico(char direccion, Uint32 cx, Uint32 cy,
			Imagen& imag, Personaje& pers, Pantalla& pant);

void MovimientoDinamico(char direccion, Imagen& imag, Personaje& pers,
			Pantalla& pant);

int main() {

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cerr << "No se pudo iniciar SDL: " << SDL_GetError() << endl;
        exit(1);
    }

    Pantalla p = Pantalla();
    p.setTitulo("NoCKt Metal", "./logo.png");

    cout << "pantalla iniciada" << endl;

    Personaje baldos(1, 1, 1, 30, &p, "./baldos.png");

    baldos.setRango(6,6);
    baldos.setPosicion();

    /* Creamos un fondo liso */
    //    p.cargarImagen(p.getFondo(), "./fondo.png");
    //    p.volcarPantalla(p.getFondo(), p.getBuffer());

    /*Creamos la matriz*/
    Uint32** matriz = (Uint32**)malloc(sizeof(Uint32*)*48);
    for(Uint32 i=0; i<48; i++)
      matriz[i]=(Uint32*)malloc(sizeof(Uint32)*36);

    for(Uint32 i=0; i<48; i++)
      for(Uint32 j=0; j<36; j++)
	matriz[i][j]=0;
    
    cout << "matriz creada." << endl;

    Imagen imag(48,36,matriz);
    Tile til("arena.png");
    cout << "imagen y tile creado" << endl;

    imag.relacionarTile(0,til);
    cout << "relación del tile" << endl;
    imag.relacionarPantalla(p);

    imag.dibujarFondo(0,0);
    cout << " imagen dibujada (en buffer)" << endl;

    baldos.setPosicion();
    baldos.dibujarPosicionFrente();
    p.volcarPantalla(p.getBuffer());
    SDL_Delay(50);
    

    SDL_Event evento;

    for( ; ; ) {
      while(SDL_PollEvent(&evento)) {  
	if(evento.type == SDL_KEYDOWN) {
	  //SDL_FillRect(pantalla, NULL,SDL_MapRGB(pantalla->format, 0, 0, 0));

	  switch(evento.key.keysym.sym){
	  case SDLK_DOWN: 
	    if(baldos.fueraRango(baldos.getX(), baldos.getY()+1))
	      MovimientoEstatico('d',imag.getCX(), imag.getCY()+1, 
				 imag, baldos,p);
	    else
	      MovimientoDinamico('d',imag,baldos,p);
	    break;

	  case SDLK_UP: 
	    if(baldos.fueraRango(baldos.getX(), baldos.getY()-1))
	      MovimientoEstatico('u',imag.getCX(), imag.getCY()-1, 
				 imag, baldos,p);
	    else
	      MovimientoDinamico('u',imag,baldos,p);
	    break;
	    
	  case SDLK_RIGHT:
	    if(baldos.fueraRango(baldos.getX()+1, baldos.getY()))
	      MovimientoEstatico('r',imag.getCX()-1, imag.getCY(), 
				 imag, baldos,p);
	    else
	      MovimientoDinamico('r',imag,baldos,p);
	    break;
	    
	  case SDLK_LEFT:
	    if(baldos.fueraRango(baldos.getX()-1, baldos.getY()))
	      MovimientoEstatico('l',imag.getCX()-1, imag.getCY(), 
				 imag, baldos,p);
	    else
	      MovimientoDinamico('l',imag,baldos,p);
	    break;

	  default: break;
	  }
	  
	  if(evento.key.keysym.sym == SDLK_ESCAPE)
	    return 0;
	}
	if(evento.type == SDL_QUIT)
	  return 0;
      }
    }
  

    cout << "Saliendo de la pantalla" << endl;
    p.cerrarPantalla();
}


void MovimientoEstatico(char direccion, Uint32 cx, Uint32 cy,
			Imagen& imag, Personaje& pers, Pantalla& pant){
  
  Uint32 num_mov = 4;
  for(int i=num_mov; i>0; i--){
    imag.dibujarFondo(cx,cy,num_mov-i+1,num_mov);
    switch(direccion){
    case 'u': pers.moverArriba(i-1,0); break;
    case 'd': pers.moverAbajo(i-1,0); break;
    case 'l': pers.moverIzda(i-1,0); break;
    case 'r': pers.moverDcha(i-1,0); break;
    default: break;
    }
    pant.volcarPantalla(pant.getBuffer());
  }
}


void MovimientoDinamico(char direccion, Imagen& imag, Personaje& pers,
			Pantalla& pant){
  
  Uint32 desp = 7;
  Uint32 num_mov=4;
  for(int i=num_mov; i>0; i--){
    pant.volcarPantalla(pant.getFondo(), pant.getBuffer());
    if(i > 3) desp = 8;
    switch(direccion){
    case 'u': pers.moverArriba(i-1,desp); break;
    case 'd': pers.moverAbajo(i-1,desp); break;
    case 'l': pers.moverIzda(i-1,desp); break;
    case 'r': pers.moverDcha(i-1,desp); break;
    default: break;
    }
    desp=7;
  }
}
