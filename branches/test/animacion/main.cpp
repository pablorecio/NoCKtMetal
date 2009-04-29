#include <iostream>
#include <SDL/SDL.h>

#include "sistema.h"
#include "pantalla.h"
#include "animacion.h"
#include "musica.h"


using namespace std;

int main() {
    if (iniciarSistema()) {
        Pantalla p = Pantalla();
        p.setTitulo("NoCKt Metal", "./tiles/logo.png");

	Musica m("musica/NIN-1m.ogg");
	m.reproducir();
	cout << "Music on" << endl;

        Animacion a = Animacion(&p);
        a.inicializarAnimacion();

        bool salir = false;

        while (!salir) {
            salir = a.procesarAccion();
        }

	cout << "Music off" << endl;
	m.pausar();

        cout << "Saliendo de la pantalla" << endl;
        p.cerrarPantalla();
    } else {
        cerr << "ERROR INICIAL" << endl;
    }
}