#ifndef SDS_CUADRUPLAS_H
  #define SDS_CUADRUPLAS_H
  
    typedef struct
  {
      int nextquad;
      int **tabla;  //vector de vectores (las propias cuadruplas)
  } nodocuadrupla;


  nodocuadrupla crear(int longitud);
  void gen(nodocuadrupla *cuadruplaini, int *cuadrupla);
  void escribe_a_fichero(nodocuadrupla cuadruplas, tablasimbolos t, char *nom_fichero);
  
#endif