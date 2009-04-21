CXX = g++
CXXFLAGS = -ansi -Wall
LIB = -lSDL -lSDL_image
EXE = main
OBJETOS = tile.o imagen.o main.o animacion2.o personaje.o sprite.o pantalla.o

${EXE}: ${OBJETOS}
	${CXX} -o ${LDFLAGS} $@ $^ ${LIB}

${OBJETOS}: tile.h imagen.h animacion2.h personaje.h sprite.h pantalla.h

clean:
	${RM} ${EXE} ${OBJETOS} *~ *#