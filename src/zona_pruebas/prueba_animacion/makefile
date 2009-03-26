CXX = g++
CXXFLAGS = -ansi -Wall
LIB = -lSDL -lSDL_image
EXE = test
OBJETOS =  Teclado.o Personaje.o main.o

${EXE}: ${OBJETOS}
	${CXX} -o ${LDFLAGS} $@ $^ ${LIB}

${OBJETOS}: Teclado.h Personaje.h

clean:
	${RM} ${EXE} ${OBJETOS} *~ *#