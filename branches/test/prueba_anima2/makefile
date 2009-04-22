CXX = g++
CXXFLAGS = -ansi -Wall
LIB = -lSDL -lSDL_image
EXE = main
OBJETOS = tile.o imagen.o sprite.o personaje.o pantalla.o main.o 

${EXE}: ${OBJETOS}
	${CXX} -o ${LDFLAGS} $@ $^ ${LIB}

${OBJETOS}: tile.h imagen.h sprite.h personaje.h pantalla.h 

clean:
	${RM} ${EXE} ${OBJETOS} *~ *#