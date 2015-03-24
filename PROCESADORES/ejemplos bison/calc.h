/* Tipo de datos para enlaces en la cadena de simbolos.*/

struct symrec
{
  char *name; 		  /* nombre del simbolo */


  int type; 		  /* tipo del simbolo: bien VAR o FNCT */
  union {
    double var;		  /* valor de una VAR*/
    double (*fnctptr)();  /* valor de una FNCT */
  } value;
  struct symrec *next;    /* campo de enlace*/
};

typedef struct symrec symrec;

/* La tabla de simbolos: una cadena de ‘struct symrec’.*/
extern symrec *sym_table;

symrec *putsym ();
symrec *getsym ();
