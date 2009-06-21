CXX = g++
CXXFLAGS = -ansi -Wall ${DEBUG} -DDEBUG=1 -DFPS=1
DEBUG = -g
LIB = -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -lboost_serialization
EXE = main-menu
GENERA = generar-xml
OBJS = animacion.o imagen.o musica.o sprite.o tile.o personaje.o npj.o atributos.o combatiente.o grupo.o inventario.o especial.o objeto.o habilidad.o control-combate.o iacombate.o aleatorio.o biblioteca.o sistema.o pantalla.o evento.o menu.o menu-principal.o dialogo.o motor-movimiento.o motor-combate.o
OBJETOS = ${OBJS} ${EXE}.o
OBJS-G =  ${OBJS} iniciar-objetos.o biblioteca.o ${GENERA}.o

${EXE}: ${OBJETOS}
	${CXX} -o ${LDFLAGS} $@ $^ ${LIB}

${GENERA}: ${OBJS-G}
	${CXX} -o ${LDFLAGS} $@ $^ ${LIB}

# -------------------------------------------------------------------
atributos.o: atributos.h atributos_base.h es-xml.h aleatorio.h
combatiente.o: combatiente.h grupo.h inventario.h objeto.h aleatorio.h
control-combate.o: grupo.h atributos.h combatiente.h habilidad.h objeto.h inventario.h control-combate.h iacombate.h
especial.o: especial.h aleatorio.h
grupo.o: grupo.h combatiente.h inventario.h
habilidad.o: habilidad.h especial.h
iniciar-objetos.o: iniciar-objetos.h atributos.h atributos_base.h combatiente.h grupo.h habilidad.h objeto.h inventario.h biblioteca.h
inventario.o: inventario.h objeto.h
habilidad.o: objeto.h especial.h
iacombate.o: iacombate.h grupo.h objeto.h combatiente.h habilidad.h inventario.h aleatorio.h
aleatorio.o: aleatorio.h
biblioteca.o: combatiente.h grupo.h objeto.h habilidad.h biblioteca.h
# ---------------------------------------------------------------------
animacion.o: evento.h pantalla.h personaje.h imagen.h npj.h dialogo.h animacion.h
dialogo.o: pantalla.h dialogo.h
imagen.o: pantalla.h npj.h tile.h imagen.h
musica.o: musica.h
sprite.o: sprite.h
tile.o: tile.h
personaje.o: sprite.h pantalla.h personaje.h
npj.o: sprite.h imagen.h npj.h
motor-combate.o: atributos.h atributos_base.h combatiente.h grupo.h habilidad.h objeto.h inventario.h aleatorio.h biblioteca.h es-xml.h control-combate.h motor-combate.h
# ---------------------------------------------------------------------
sistema.o: sistema.h
pantalla.o: pantalla.h
evento.o: evento.h
menu.o: pantalla.h evento.h menu.h
menu-principal.o: menu.h menu-principal.h
motor-movimiento.o: animacion.h pantalla.h evento.h motor-movimiento.h
musica.o: musica.h
# ---------------------------------------------------------------------
${EXE}.o: sistema.h menu-principal.h motor-movimiento.h motor-combate.h musica.h evento.h

${GENERA}.o: biblioteca.h iniciar-objetos.h


all:	${GENERA} ${EXE}
	./generar-xml

clean:
	${RM} ${EXE} ${OBJETOS} ${OBJS-G} ${GENERA} *~ *#

clean-all:
	make clean & ${RM} datos-xml/*