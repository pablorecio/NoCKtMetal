CXX = g++
SDLFLAGS = -lSDL -lSDL_image
EXE = main
OBJS = Control_Animacion.o Imagen.o

main: ${OBJS}
	${CXX} ${EXE}.cpp  ${OBJS} -o ${EXE} ${SDLFLAGS}

Control_Animacion.o:
	${CXX} -c Control_Animacion.cpp

Imagen.o:
	${CXX} -c Imagen.cpp

clean:
	${RM} ${EXE} ${OBJS} *~ *.gch