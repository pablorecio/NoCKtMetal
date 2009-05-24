CXX = g++
DEBUG = -g
CXXFLAGS = -ansi -Wall ${DEBUG} -DDEBUG=1 -DFPS=1
LIB = -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
EXE = main
OBJETOS = main.o

${EXE}: ${OBJETOS}
	${CXX} -o ${LDFLAGS} $@ $^ ${LIB}

${OBJETOS}: 

clean:
	${RM} ${EXE} ${OBJETOS} *~ *#
