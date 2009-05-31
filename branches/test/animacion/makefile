CXX = g++
DEBUG = -g
CXXFLAGS = -ansi -Wall ${DEBUG} -DDEBUG=1 -DFPS=1
LIB = -lSDL -lSDL_image -lSDL_mixer
EXE = main
OBJETOS = animacion.o evento.o imagen.o musica.o pantalla.o sistema.o sprite.o tile.o personaje.o main.o npj.o

${EXE}: ${OBJETOS}
	${CXX} -o ${LDFLAGS} $@ $^ ${LIB}

${OBJETOS}: animacion.h evento.h imagen.h musica.h pantalla.h sistema.h sprite.h tile.h personaje.h npj.h

clean:
	${RM} ${EXE} ${OBJETOS} *~ *#
