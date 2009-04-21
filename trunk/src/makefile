CXX = g++
CXXFLAGS = -ansi -Wall
LIB = -lSDL -lSDL_image
EXE = main
OBJETOS = ${EXE}.o atributos.o combatiente.o grupo.o inventario.o especial.o objeto.o habilidad.o
TIXML = tinyxml/tinyxml.o tinyxml/tinystr.o tinyxml/tinyxmlparser.o tinyxml/tinyxmlerror.o

${EXE}: ${OBJETOS} ${TIXML}
	${CXX} -o ${LDFLAGS} $@ $^ ${LIB}

${OBJETOS}: atributos.h atributos_base.h combatiente.h grupo.h inventario.h especial.h objeto.h habilidad.h

${TIXML}: tinyxml/tinyxml.h tinyxml/tinystr.h

clean:
	${RM} ${EXE} ${OBJETOS} ${TIXML} *~ *#