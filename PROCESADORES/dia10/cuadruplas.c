#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//gcc -c cuadruplas.c

#include "tablaSimbolos.h"

#define SUMA 1
#define RESTA 2
#define MULTI 3
#define DIVI 4
#define MENOS_UNARIO 5
#define MOD 6
#define ASIGNACION 7
#define O 8
#define Y 9


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

int* makelist(int nextquad) { 
	int* list = (int*)malloc(sizeof(int)*15);
	list[0] = nextquad;
	list[1] = 0;

	return list;
}



int* merge(int* list1,int* list2) { 		// Une dos listas
	int* temp=list1,count1=0,count2=0;	
	while(list1[count1]!=0){
	      count1++;
	}	
	while(list1[count2]!=0) {
	      list1[count1]=list2[count2];
	      count1++;
	      count2++;
	}
	return temp;
}



/*void backpatch(int* list,int dir_salto) { 	// Rellena los huecos con la direccion de salto
	char addr[10];
	sprintf(addr,"%d",dir_salto);
	while(*list!=0) {
	      int index=*list++-100; 		// WTF!!!
	      strcat(code[index],addr);	
	}
}*/

void escribe_a_fichero(nodocuadrupla cuadruplas, tablasimbolos t, char *nom_fichero){
	FILE *fichero;
	fichero = fopen (nom_fichero, "w");
	int i;
	char *operacion;
	nodo *nodo_resultado;
	nodo *nodo_op1;
	nodo *nodo_op2;
	
	for(i=0; i<cuadruplas.nextquad; i++){
		switch(cuadruplas.tabla[i][0]){
		        case SUMA:		operacion=(char *)calloc(2,sizeof(char));
						sprintf(operacion,"+");
						break;
			case RESTA:		operacion=(char *)calloc(2,sizeof(char));
						sprintf(operacion,"-");
						break;
			case MULTI:		operacion=(char *)calloc(2,sizeof(char));
						sprintf(operacion,"*");
						break;
			case DIVI:		operacion=(char *)calloc(4,sizeof(char));
						sprintf(operacion,"div");
						break;
			case MENOS_UNARIO:	operacion=(char *)calloc(2,sizeof(char));
						sprintf(operacion,"-");
						break;
			case MOD:		operacion=(char *)calloc(4,sizeof(char));
						sprintf(operacion,"mod");
						break;
			case ASIGNACION: 	operacion=(char *)calloc(3,sizeof(char));
						sprintf(operacion,":=");
						break;
			case O:			operacion=(char *)calloc(2,sizeof(char));
						sprintf(operacion,"o");
						break;
			case Y: 		operacion=(char *)calloc(2,sizeof(char));
						sprintf(operacion,"y");
						break;
			default: 		printf("Esa operación no existe.\n");
		}
		nodo_resultado = buscaridTS(t,cuadruplas.tabla[i][3]);
		nodo_op1 = buscaridTS(t,cuadruplas.tabla[i][1]);
		if( cuadruplas.tabla[i][2]==-27){
			if (cuadruplas.tabla[i][0] == ASIGNACION) {
				fprintf(fichero, "%s := %s\n", nodo_resultado->nombre, nodo_op1->nombre);
			}
			else {
				fprintf(fichero, "%s := %s %s\n", nodo_resultado->nombre, operacion, nodo_op1->nombre);
			}
		}else{
			nodo_op2=buscaridTS(t,cuadruplas.tabla[i][2]);
			fprintf(fichero, "%s := %s %s %s\n", nodo_resultado->nombre, nodo_op1->nombre, operacion, nodo_op2->nombre);
		}
	}
	fclose(fichero);
}