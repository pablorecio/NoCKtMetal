CXX = g++
DEBUG = -g
CXXFLAGS = -ansi -Wall ${DEBUG} -DDEBUG=1 -DFPS=1
LIB = -lSDL -lSDL_image -lboost_serialization
#iniciar = iniciar_xml
EXE = main-combate
OBJETOS = atributos.o combatiente.o grupo.o inventario.o especial.o objeto.o habilidad.o iniciar-objetos.o control-combate.o ${EXE}.o 

${EXE}: ${OBJETOS}
	${CXX} -o ${LDFLAGS} $@ $^ ${LIB}

${OBJETOS}: atributos.h atributos_base.h combatiente.h grupo.h inventario.h especial.h objeto.h habilidad.h es-xml.h iniciar-objetos.h control-combate.h

clean:
	${RM} ${EXE} ${OBJETOS} *~ *#