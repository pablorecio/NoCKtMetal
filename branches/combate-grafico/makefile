CXX = g++
DEBUG = -g
CXXFLAGS = -ansi -Wall ${DEBUG} -DDEBUG=1 -DFPS=1
LIB = -lSDL -lSDL_image -lSDL_ttf -lboost_serialization 
EXE = main-combate
GENERA = generar-xml
OBJS = aleatorio.o animacion.o atributos.o biblioteca.o combatiente.o combatiente-grafico.o control-combate.o control-grafico.o especial.o evento.o generar-xml.o grupo.o grupo-grafico.o habilidad.o iacombate.o imagen.o iniciar-objetos.o inventario.o menu.o npj.o objeto.o pantalla.o personaje.o sistema.o sprite.o tile.o 

OBJETOS =  ${OBJS} ${EXE}.o
OBJS-G =  ${OBJS} iniciar-objetos.o biblioteca.o ${GENERA}.o

${EXE}: ${OBJETOS}
	${CXX} -o ${LDFLAGS} $@ $^ ${LIB}

${GENERA}: ${OBJS-G}
	${CXX} -o ${LDFLAGS} $@ $^ ${LIB}

#atributos.o: atributos.h atributos_base.h es-xml.h aleatorio.h
#combatiente.o: combatiente.h grupo.h inventario.h objeto.h aleatorio.h
#control-combate.o: grupo.h atributos.h combatiente.h habilidad.h objeto.h inventario.h control-combate.h iacombate.h
#especial.o: especial.h aleatorio.h
#grupo.o: grupo.h combatiente.h inventario.h
#habilidad.o: habilidad.h especial.h
#iniciar-objetos.o: iniciar-objetos.h atributos.h atributos_base.h combatiente.h grupo.h habilidad.h objeto.h inventario.h biblioteca.h
#inventario.o: inventario.h objeto.h
#habilidad.o: objeto.h especial.h
#iacombate.o: iacombate.h grupo.h objeto.h combatiente.h habilidad.h inventario.h aleatorio.h
#aleatorio.o: aleatorio.h
#biblioteca.o: combatiente.h grupo.h objeto.h habilidad.h biblioteca.h
#combatiente-grafico.o: combatiente.h sprite.h atributos.h inventario.h grupo.h combatiente-grafico.h
#control-grafico.o: control-combate.h grupo.h menu.h
#menu.o: evento.h pantalla.h
#grupo-grafico.o: grupo.h combatiente-grafico.h grupo-grafico.h pantalla.h

#${EXE}.o:atributos.h atributos_base.h combatiente.h grupo.h inventario.h objeto.h habilidad.h es-xml.h control-combate.h biblioteca.h
${EXE}.o: aleatorio.h animacion.h armadura.h arma.h atributos_base.h atributos.h biblioteca.h combatiente-grafico.h  combatiente.h control-combate.h control-grafico.h especial.h es-xml.h evento.h grupo-grafico.h grupo.h habilidad.h iacombate.h imagen.h inventario.h item_equipable.h  menu.h npj.o objeto.h pantalla.h personaje.h sistema.h sprite.h tile.h





 

${GENERA}.o: biblioteca.h iniciar-objetos.h

clean:
	${RM} ${EXE} ${OBJETOS} ${OBJS-G} ${GENERA} *~ *#

clean-all:
	make clean & ${RM} datos-xml/*