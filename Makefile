CC 		= g++
CFLAGS 	= -W -pedantic
CDEPS 	= -lGL -lGLU -lglut

all: Tugas clean

render.o: src/render.hh src/render.cc
	${CC} ${CFLAGS} -c src/render.cc -o render.o

main.o: src/main.cc
	${CC} ${CFLAGS} -c src/main.cc -o main.o

Tugas: render.o main.o
	${CC} ${CFLAGS} main.o render.o ${CDEPS} -o Tugas

clean:
	@rm -rf *.o