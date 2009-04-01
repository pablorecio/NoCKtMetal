// Listado: Control_Animacion.cpp
//
// Implementación de la clase Control Animacion

#include <iostream>
#include <cstring>
#include <cstdlib>
#include "Control_Animacion.h"


using namespace std;


Control_Animacion::Control_Animacion(char *frames) {

    int i = 0;
    char frames_tmp[1024];
    char *proximo;
    
    
    strcpy(frames_tmp, frames);

    // Trabajamos con una copia de los cuadros indicados

    for(proximo = strtok(frames_tmp, ","); proximo; i++){

	// Desmembramos la cadena separada por comas

	this->cuadros[i] = atoi(proximo);
	proximo = strtok(NULL, ",\0");
    }

    // Inicializamos las variables
    
    this->cuadros[i] = -1;
    this->paso = 0;
	
#ifdef DEBUG    
    cout << "Control_Animacion::Control_Animacion()" << endl;
#endif
}


int Control_Animacion::cuadro(void) {

    return cuadros[paso];
}


int Control_Animacion::avanzar(void) {	

    if(cuadros[++paso] == -1) {
	paso = 0;
	return 1;
    }
    
    return 0;
}


void Control_Animacion::reiniciar(void) {

    // Volvemos al principio

    paso = 0;
}


bool Control_Animacion::es_primer_cuadro(void) {

    if(paso == 0)
	return true;

    return false;
}

Control_Animacion::~Control_Animacion() {

#ifdef DEBUG
    cout << "Control_Animacion::~Control_Animacion()" << endl;
#endif
}
