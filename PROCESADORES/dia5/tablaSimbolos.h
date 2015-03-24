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
  
  *tabla_simbolos crearTablaSimbolos();
  bool estaEnTabla(tabla_simbolos *t, char nombre);
  void insertarNodo(tabla_simbolos *t, char nombre, int id);
  int dimeTipo(tabla_simbolos *t, char nombre);
  void modificarTipo(tabla_simbolos *t, char nombre, int tipo);
  void borrarNodo(tabla_simbolos *t, char nombre);
  newtemp(tabla_simbolos *t, int id);
  
#endif

