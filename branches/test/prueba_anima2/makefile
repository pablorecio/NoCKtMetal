CXX = g++
CXXFLAGS = -ansi -Wall
LIB = -lSDL -lSDL_image
EXE = main
OBJETOS = tile.o imagen.o main.o 

${EXE}: ${OBJETOS}
	${CXX} -o ${LDFLAGS} $@ $^ ${LIB}

${OBJETOS}: tile.h imagen.h 

clean:
	${RM} ${EXE} ${OBJETOS} *~ *#