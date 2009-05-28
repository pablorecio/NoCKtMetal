CXX = g++
DEBUG = -g
CXXFLAGS = -ansi -Wall ${DEBUG} -DDEBUG=0 -DFPS=0
LIB = -lSDL -lSDL_image -lboost_serialization
#iniciar = iniciar_xml
EXE = main-combate
OBJETOS = atributos.o combatiente.o grupo.o inventario.o especial.o objeto.o habilidad.o iniciar-objetos.o control-combate.o ${EXE}.o 

${EXE}: ${OBJETOS}
	${CXX} -o ${LDFLAGS} $@ $^ ${LIB}


atributos.o: atributos.h atributos_base.h
combatiente.o: combatiente.h grupo.h inventario.h objeto.h
control-combate.o: grupo.h atributos.h combatiente.h habilidad.h objeto.h inventario.h control-combate.h
especial.o: especial.h
grupo.o: grupo.h combatiente.h inventario.h
habilidad.o: habilidad.h especial.h
iniciar-objetos.o: iniciar-objetos.h atributos.h atributos_base.h combatiente.h grupo.h habilidad.h objeto.h inventario.h es-xml.h
inventario.o: inventario.h objeto.h
${EXE}.o:atributos.h atributos_base.h combatiente.h grupo.h inventario.h objeto.h habilidad.h es-xml.h iniciar-objetos.h control-combate.h
habilidad.o: objeto.h especial.h

clean:
	${RM} ${EXE} ${OBJETOS} *~ *#