flex: 	gramar.lex
	flex gramar.lex

cuadruplas: cuadruplas.c
	gcc -c -g cuadruplas.c

tablaSimbolos: tablaSimbolos.c
	gcc -c -g tablaSimbolos.c

bison:	lenguaje.y
	bison -dv lenguaje.y

leng:	lenguaje.tab.c
	gcc -c -g lenguaje.tab.c

lenguaje: 	cuadruplas.o tablaSimbolos.o lenguaje.tab.o
	gcc -o lenguaje lex.yy.c cuadruplas.o tablaSimbolos.o  lenguaje.tab.o -lfl

all: flex cuadruplas tablaSimbolos bison leng lenguaje
