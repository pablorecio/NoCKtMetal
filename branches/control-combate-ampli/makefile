CXX = g++
DEBUG = -g
CXXFLAGS = -ansi -Wall #${DEBUG} -DDEBUG=0 -DFPS=0
LIB = -lSDL -lboost_serialization
EXE = main-combate
OBJS = atributos.o combatiente.o grupo.o inventario.o especial.o objeto.o habilidad.o control-combate.o iacombate.o aleatorio.o biblioteca.o iniciar-objetos.o
OBJETOS =  ${OBJS} ${EXE}.o 

${EXE}: ${OBJETOS}
	${CXX} -o ${LDFLAGS} $@ $^ ${LIB}

atributos.o: atributos.h atributos_base.h es-xml.h aleatorio.h
combatiente.o: combatiente.h grupo.h inventario.h objeto.h aleatorio.h
control-combate.o: grupo.h atributos.h combatiente.h habilidad.h objeto.h inventario.h control-combate.h iacombate.h
especial.o: especial.h aleatorio.h
grupo.o: grupo.h combatiente.h inventario.h
habilidad.o: habilidad.h especial.h
iniciar-objetos.o: iniciar-objetos.h atributos.h atributos_base.h combatiente.h grupo.h habilidad.h objeto.h inventario.h biblioteca.h
inventario.o: inventario.h objeto.h
${EXE}.o:atributos.h atributos_base.h combatiente.h grupo.h inventario.h objeto.h habilidad.h es-xml.h control-combate.h biblioteca.h
habilidad.o: objeto.h especial.h
iacombate.o: iacombate.h grupo.h objeto.h combatiente.h habilidad.h inventario.h aleatorio.h
aleatorio.o: aleatorio.h
biblioteca.o: combatiente.h grupo.h objeto.h habilidad.h

clean:
	${RM} ${EXE} ${OBJETOS} ${OBJS-INI} ${INICIADOR} *~ *#