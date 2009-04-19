#include <iostream>
#include <SDL/SDL.h>

#include "sprite.h"
#include "personaje.h"
#include "pantalla.h"


using namespace std;

int main () {

  if(SDL_Init(SDL_INIT_VIDEO) < 0) {
    cerr << "No se pudo iniciar SDL: " << SDL_GetError() << endl;
    exit(1);
  }

  if(SDL_VideoModeOK(480, 360, 24, SDL_HWSURFACE|SDL_DOUBLEBUF) == 0) {
    cerr << "Modo no soportado: " << SDL_GetError() << endl;
    exit(1);
  }

  Pantalla p = Pantalla();
  p.setTitulo("NoCKt Metal", "./logo.png");

  cout << "pantalla iniciada" << endl;

  Sprite s("./baldos.png", 4, 4);

  cout << "sprite creado" << endl;

  Personaje baldos(1);
  baldos.dibujadoPor(s);
  baldos.animadoEn(p);
  
  baldos.setRango(8,8,2,2);
  baldos.setPosicion();

  p.rellenarPantalla(p.getBuffer(),0, 0, 100, 0);
  p.volcarPantalla(p.getBuffer());
  SDL_Delay(500);
  
  cout << "dibujado en pantalla" << endl;

  baldos.dibujarPosicionFrente();
  p.volcarPantalla(p.getMovimiento());
  cout << "PJ mostrado" << endl;
  SDL_Delay(500);

  for (Uint32 i = 0; i < 10; i++) {
      baldos.moverArriba();
      SDL_Delay(500);
  }

  for (Uint32 i = 0; i < 10; i++) {
    Uint32 mov = 1, res = 0;
    while (mov != 0) {
      mov = baldos.moverAbajo(res,8);
      res = mov;
      SDL_Delay(1000);
    }
    p.rellenarPantalla(p.getFondo(),0, 0, 100, 0);
  }

  cout << "Saliendo de la pantalla" << endl;
  p.cerrarPantalla();

}
