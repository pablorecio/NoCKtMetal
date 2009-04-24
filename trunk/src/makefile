CXX = g++
CXXFLAGS = -ansi -Wall
LIB = -lSDL -lSDL_image -lboost_serialization
#iniciar = iniciar_xml
leer = leer-xml
OBJETOS = ${leer}.o atributos.o combatiente.o grupo.o inventario.o especial.o objeto.o habilidad.o

${leer}: ${OBJETOS}
	${CXX} -o ${LDFLAGS} $@ $^ ${LIB}

${OBJETOS}: atributos.h atributos_base.h combatiente.h grupo.h inventario.h especial.h objeto.h habilidad.h es-xml.h

clean:
	${RM} ${leer} ${OBJETOS} *~ *#