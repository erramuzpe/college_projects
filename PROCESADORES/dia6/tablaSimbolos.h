#ifndef SDS_TABLASIMBOLOB_H
  #define SDS_TABLASIMBOLOB_H
  
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
   
  typedef struct { //Para cualquier expresión, aritmética o booleana
    int place;
    int tipo;
  }expr;
  
  // ampliarrrrrrrrr
    
  typedef union {
    expr campo_expr;
    char* campo_id;
    //ampliarrrrrrr
  }infopila;
  
  tablasimbolos crearTablaSimbolos();
  void insertarNodo(tablasimbolos *t, char *nombre, int id);
  void borrarNodo(tablasimbolos *t, char *nombre);
  void modificarTipo(tablasimbolos *t, int tipo, int id);
  nodo *buscaridTS(tablasimbolos t,int id)
  nodo *buscarnombreTS(tablasimbolos t,char *nombre)
  int dimeTipo(tablasimbolos *t, char nombre);
  nodo *newtemp(tablasimbolos *t, int id);
  
#endif

