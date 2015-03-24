#include <stdio.h>
#include <stdlib.h>
#include <string.h>

  typedef struct{
    int id;
    char *nombre;
    int tipo;
    // otros datos
  }nodo;
  
  typedef struct{
    nodo nodoTS;
    struct tabla_simbolos *sig;
  }tabla_simbolos;

  typedef tabla_simbolos *tablasimbolos;
  
  tablasimbolos crearTablaSimbolos();
  void insertarNodo(tablasimbolos *t, char *nombre, int id);
  void borrarNodo(tablasimbolos *t, char *nombre);
  void modificarTipo(tablasimbolos *t, int tipo, int id);
  nodo *buscaridTS(tablasimbolos t,int id);
  nodo *buscarnombreTS(tablasimbolos t,char *nombre);
  int dimeTipo(tablasimbolos *t, char *nombre);
  nodo *newtemp(tablasimbolos *t, int id);
  


  tablasimbolos crearTablaSimbolos() {
    tablasimbolos t;
    t = NULL;
    return t;
  }
  
  void insertarNodo(tablasimbolos *t, char *nombre, int id)
  {
	tabla_simbolos *aux;
	aux=(tabla_simbolos *)malloc(sizeof(tabla_simbolos));
	aux->nodoTS.id=id;
	aux->nodoTS.nombre = (char *) malloc((strlen(nombre) +1) * sizeof(char));
	strcpy(aux->nodoTS.nombre, nombre);
	aux->sig=*t;
	*t=aux;
  }

  void borrarNodo(tablasimbolos *t, char *nombre)
  {
	tablasimbolos aux;
	tablasimbolos aux2;
	tablasimbolos pa;
	pa = *t;
	if(pa!=NULL)
	{
		if(pa->nodoTS.nombre==nombre) {
			aux=pa;
			pa=pa->sig;
			free(aux);
		}
		aux2=aux;
		aux=pa->sig;
		while(aux!=NULL){
			if(aux->nodoTS.nombre==nombre){
				aux2->sig=aux->sig;
				free(aux);
				aux=aux2->sig;
				aux=aux->sig;
			}
			else{
				aux2=aux;
				aux=aux->sig;
			}
		}
	}
  }
  
  void modificarTipo(tablasimbolos *t, int tipo, int id)
  {
	nodo *nodoTSaux;
	nodoTSaux = buscaridTS(*t, id);
	nodoTSaux->tipo=tipo;
  }

  nodo *buscaridTS(tablasimbolos t,int id)
  {
    tabla_simbolos *aux;
    aux=t;
    if(aux==NULL)
	return NULL;
    else{
        while(aux->sig!=NULL && (aux->nodoTS.id)!=id)
            aux=aux->sig;
	if(aux->nodoTS.id!=id)
            return NULL;
        else
            return &(aux->nodoTS);
    }
  }

  nodo *buscarnombreTS(tablasimbolos t, char *nombre) {
    tabla_simbolos *aux;
    aux=t;
    if(aux==NULL)
	return NULL;
    else{
        while(aux->sig!=NULL && (strcmp(aux->nodoTS.nombre,nombre) != 0)) {
            	aux=aux->sig;
	}
	if (strcmp(aux->nodoTS.nombre,nombre) != 0 )
		return NULL;
	else
		return &(aux->nodoTS);
	}
  }
  
  int dimeTipo(tablasimbolos *t, char *nombre) {
        nodo *nodoTSaux;
	nodoTSaux = buscarnombreTS(*t, nombre);
	return nodoTSaux->tipo;
  }
  
  nodo *newtemp(tablasimbolos *t, int id) {
	tabla_simbolos *aux;
	aux=(tabla_simbolos *)malloc(sizeof(tabla_simbolos));
	aux->nodoTS.id=id;
	aux->nodoTS.nombre = (char *) malloc((8) * sizeof(char)); 
	sprintf(aux->nodoTS.nombre,"temp%d",id);
	aux->sig=*t;
	*t=aux;
	return &(aux->nodoTS);  //comprobar
  }
