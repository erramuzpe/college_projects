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
  
  tabla_simbolos crearTablaSimbolos() {
    tabla_simbolos t;
    
    t = null;
    return t;
  }
  
  bool estaEnTabla(tabla_simbolos *t, char nombre) {
    
  }
  
  void insertarNodo(tabla_simbolos *t, char nombre, int id) {
    tabla_simbolos *aux;
    
    aux = (tabla_simbolos *) malloc (sizeof (tabla_simbolos));
    aux->nombre = (char *) malloc (strlen (nombre) + 1);
    strcpy (aux->nombre,nombre);
    //aux->type = sym_type;
    aux->sig = (struct tabla_simbolos *)tabla_simbolos;
    *tabla_simbolos = aux;
  }
  
  int dimeTipo(tabla_simbolos *t, char nombre) {
    
  }
  
  void modificarTipo(tabla_simbolos *t, char nombre, int tipo) {
    
  }
  
  void borrarNodo(tabla_simbolos *t, char nombre) {
    
  }