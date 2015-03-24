#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//gcc -c cuadruplas.c

#include "tablaSimbolos.h"


typedef struct
{
    int nextquad;
    int **tabla;  //vector de vectores (las propias cuadruplas)
} nodocuadrupla;


nodocuadrupla crear(int longitud){
	int i;
	nodocuadrupla cuadruplaini;
	cuadruplaini.tabla=(int **)calloc(longitud,sizeof(int *));
	for(i=0;i<longitud;i++){
		cuadruplaini.tabla[i]=(int *)calloc(4,sizeof(int));
	}
	cuadruplaini.nextquad=0;
	return cuadruplaini;
}


void gen(nodocuadrupla *cuadruplaini, int *cuadrupla){
	int i;
	for(i=0;i<4;i++)
		cuadruplaini->tabla[cuadruplaini->nextquad][i]=cuadrupla[i];
	cuadruplaini->nextquad++;
}

