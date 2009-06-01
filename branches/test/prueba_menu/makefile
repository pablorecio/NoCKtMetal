CXX = g++
CXXFLAGS = -ansi -Wall
LIB = -lSDL -lSDL_image
EXE = main
OBJETOS = pantalla.o evento.o menu.o main.o 

${EXE}: ${OBJETOS}
	${CXX} -o ${LDFLAGS} $@ $^ ${LIB}

${OBJETOS}: pantalla.h evento.h menu.h

clean:
	${RM} ${EXE} ${OBJETOS} *~ *#