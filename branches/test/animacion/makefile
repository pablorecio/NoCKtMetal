CXX = g++
CXXFLAGS = -ansi -Wall
LIB = -lSDL -lSDL_image
EXE = main
OBJETOS = pantalla.o evento.o sprite.o tile.o personaje.o imagen.o animacion.o main.o

${EXE}: ${OBJETOS}
	${CXX} -o ${LDFLAGS} $@ $^ ${LIB}

${OBJETOS}: pantalla.h evento.h sprite.h tile.h personaje.h imagen.h animacion.h

clean:
	${RM} ${EXE} ${OBJETOS} *~ *#
