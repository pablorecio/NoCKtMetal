// Listado: Imagen.cpp
//
// Implementación de la clase imagen para la 
// gestión de imágenes y rejillas

#include <iostream>
#include <SDL/SDL_image.h>

#include "Imagen.h"

using namespace std;


Imagen::Imagen(char *ruta, int filas, int columnas, \
	       Uint32 r, Uint32 g, Uint32 b) {

    this->filas = filas;
    this->columnas = columnas;

#ifdef DEBUG
    cout << "-> Cargando" <<  ruta << endl;
#endif

    // Cargamos la imagen

    imagen = IMG_Load(ruta);

    if(imagen == NULL) {

	cerr << "Error: " << SDL_GetError() << endl;;
	exit(1);

    }

    // Convertimos a formato de pantalla

    SDL_Surface *tmp = imagen;
    
    imagen = SDL_DisplayFormat(tmp);

    SDL_FreeSurface(tmp);
    
    if(imagen == NULL) {

	cerr << "Error: " << SDL_GetError() << endl;
	exit(1);

    }
    
    // Calculamos el color transparente, en nuestro caso el verde

    colorkey = SDL_MapRGB(imagen->format, r, g, b);
    
    // Lo establecemos como color transparente

    SDL_SetColorKey(imagen, SDL_SRCCOLORKEY, colorkey);
    
    
    // Hallamos la imagen invertida utilizada en el mayor de los casos
    // para las imágenes de vuelta

    imagen_invertida = invertir_imagen(imagen);

    if(imagen_invertida == NULL) {

	cerr << "No se pudo invertir la imagen: " << SDL_GetError() << endl;
	exit(1);

    }
    
    // El ancho de una imagen es el total entre el número de columnas	
    w = imagen->w / columnas;

    // El ato de una imagen es el total entre el número de filas
    h = imagen->h / filas;

}



void Imagen::dibujar(SDL_Surface *superficie, int i, int x, int y, int flip)
{

    SDL_Rect destino;
    
    destino.x = x;
    destino.y = y;

    // No se usan

    destino.h = 0;
    destino.w = 0;

    // Comprobamos que el número de imagen indicado sea el correcto
    if(i < 0 || i > (filas * columnas))	{

	cerr << "Imagen::Dibujar = No existe el cuadro: " << i << endl;
	return;
    }
	
    SDL_Rect origen;

    // Separaciones de 2 píxeles dentro de las rejillas para observar
    // bien donde empieza una imagen y donde termina la otra

    origen.w = w - 2;
    origen.h = h - 2;

    // Seleccionamos cual de las imágenes es la que vamos a dibujar
    switch(flip) {

     case 1:

	 // Cálculo de la posición de la imagen
	 // dentro de la rejilla
	 
	 origen.x = ((i % columnas) * w) + 2;
	 origen.y = ((i / columnas) * h) + 2;
			
	 SDL_BlitSurface(imagen, &origen, superficie, &destino);

	 break;

     case -1:

	 // Cálculo de la posición de la imagen
	 // dentro de la rejilla invertida

	 origen.x = ((columnas-1) - (i % columnas)) * w + 1;
	 origen.y = (i / columnas) * h + 2;
	 
	 // Copiamos la imagen en la superficie	 

	 SDL_BlitSurface(imagen_invertida, &origen, superficie, &destino);

	 break;
	 
     default:

	 cerr << "Caso no válido: Imagen invertida o no" << endl;
	 break;
    }
}


// Devuelve la anchura de un cuadro de la rejilla

int Imagen::anchura() {

    return w;
}


// Devuelve la altura de un cuadro de la rejilla

int Imagen::altura() {

    return h;
}

// Devuelve el número de cuadros de la rejilla de la imagen

int Imagen::cuadros() {

    return columnas * filas;
}

Imagen::~Imagen()
{

    SDL_FreeSurface(imagen);
    SDL_FreeSurface(imagen_invertida);

#ifdef DEBUG    
    cout << "<- Liberando imagen" << endl;
#endif

}


SDL_Surface * Imagen::invertir_imagen(SDL_Surface *imagen) {

    SDL_Rect origen;
    SDL_Rect destino;


    // Origen -> ancho una línea
    // Comienzo de copia por el principio

    origen.x = 0;
    origen.y = 0;
    origen.w = 1;
    origen.h = imagen->h;

    // Destino -> ancho una lína
    // Comienzo de 'pegado' por el final
    // Para lograr la inversión

    destino.x = imagen->w;
    destino.y = 0;
    destino.w = 1;
    destino.h = imagen->h;

    SDL_Surface *invertida;

    // Pasamos imagen a formato de pantalla

    invertida = SDL_DisplayFormat(imagen);

    if(invertida == NULL) {

	cerr << "No podemos convertir la imagen al formato de pantalla" << endl;
	return NULL;
    }

    // Preparamos el rectángulo nuevo vacío del color transparente

    SDL_FillRect(invertida, NULL, SDL_MapRGB(invertida->format, 0, 255, 0));

    // Copiamos linea vertical a linea vertical, inversamente

    for(int i = 0; i < imagen->w; i++) {

	SDL_BlitSurface(imagen, &origen, invertida, &destino);

	origen.x = origen.x + 1;
	destino.x = destino.x - 1;
    }

    return invertida;

}
