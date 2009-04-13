

#ifndef _IMAGEN_H_
#define _IMAGEN_H_

class Imagen{
 public:
  void inicializar(SDL_Surface *p);
  void dibujarFondo1();
  
 private:
  int alto,ancho;
  SDL_Surface *pantalla;

};

#endif
