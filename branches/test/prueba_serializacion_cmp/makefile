CXX = g++
CXXFLAGS = -ansi -Wall
LIB = -lSDL -lSDL_image -lboost_serialization
EXE = iniciar_xml
OBJETOS = ${EXE}.o atributos.o combatiente.o grupo.o inventario.o especial.o objeto.o habilidad.o

${EXE}: ${OBJETOS}
	${CXX} -o ${LDFLAGS} $@ $^ ${LIB}

${OBJETOS}: atributos.h atributos_base.h combatiente.h grupo.h inventario.h especial.h objeto.h habilidad.h es-xml.h

clean:
	${RM} ${EXE} ${OBJETOS} *~ *#