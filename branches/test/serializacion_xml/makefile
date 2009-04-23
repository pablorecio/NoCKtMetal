CXX = g++
CXXFLAGS = -ansi -Wall
LIB = -lSDL -lboost_serialization
EXE = prueba_atributos
OBJETOS = prueba_atributos.o atributos.o

${EXE}: ${OBJETOS}
	${CXX} -o ${LDFLAGS} $@ $^ ${LIB}

${OBJETOS}: atributos.h atributos_base.h

clean:
	${RM} ${EXE} ${OBJETOS} *~ *#