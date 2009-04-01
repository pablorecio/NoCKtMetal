CXX = g++
CXXFLAGS = -ansi -Wall
LIB = -lSDL -lSDL_image
EXE = main
OBJETOS = Control_Animacion.o Animacion.o Imagen.o main.o

${EXE}: ${OBJETOS}
	${CXX} -o ${LDFLAGS} $@ $^ ${LIB}

${OBJETOS}: Control_Animacion.h Animacion.h Imagen.h

clean:
	${RM} ${EXE} ${OBJETOS} *~ *#