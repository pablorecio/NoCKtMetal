CXX = g++
CXXFLAGS = -ansi -Wall
LIB = -lSDL -lSDL_image -lSDL_mixer
EXE = main
OBJETOS = pantalla.o evento.o sprite.o tile.o personaje.o imagen.o animacion.o musica.o main.o

${EXE}: ${OBJETOS}
	${CXX} -o ${LDFLAGS} $@ $^ ${LIB}

${OBJETOS}: pantalla.h evento.h sprite.h tile.h personaje.h imagen.h musica.h animacion.h

clean:
	${RM} ${EXE} ${OBJETOS} *~ *#
