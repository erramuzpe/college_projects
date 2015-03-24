/* Calculadora de notacion notacion infija--calc */

%{
#define YYSTYPE double
#include <math.h> /* Para funciones matematicas, cos(), sin(), etc */
#include "calc.h" /* Contiene definicion de ‘symrec' */
#include <stdio.h>
#include <ctype.h>
//Compilar flex lenguaje.lex
//	   gcc -o lenguaje lenguaje.c -lfl
//Bison    bison -d -ly analizador.y
%}

%union {
double val; /* Para devolver numeros */
symrec *tptr; /* Para devolver punteros a la tabla de simbolos*/
}


/* Declaraciones de BISON */

%token <val> NUM          /* Numero simple en doble precision */
%token <tptr> VAR FNCT    /* Variable y Funcion */
%type <val> exp

%right '='
%left '-' '+' 
/* asociativo a izda y menos prioritario que lo que 
viene detras */
%left '*' '/'
/* negacion--menos unario */
%left NEG
%right '^'
/* exponenciacion */


%% /* A continuacion las reglas gramaticales y las acciones */

input: /*  cadena vacia */
      | input line
;

line:	'\n'
	| exp '\n' { printf ("\t%.10g\n", $1);  }
	| error '\n' { yyerrok;			} /* si quitas esta linea, error y termina. con esto, error y sigue ejecucion */
;

exp:	  NUM			{ $$ = $1; }
	| VAR	 		{ $$ = $1->value.var; }
	| VAR '=' exp	 	{ $$ = $3; $1->value.var = $3; }
	| FNCT '(' exp ')'	{ $$ = (*($1->value.fnctptr)) ($3); }
	| exp '+' exp 		{ $$ = $1 + $3; } /* ahora es $3,porque es el tercer elemento */
	| exp '-' exp		{ $$ = $1 - $3; }
	| exp '*' exp		{ $$ = $1 * $3; }
	| exp '/' exp		{ $$ = $1 / $3; }
/* Menos unario */	
	| '-' exp %prec NEG	{ $$ = -$2; }
/* Exponenciacion  */
	| exp '^' exp		{ $$ = pow ($1, $3); }
/* parentesis */
	| '(' exp ')'		{ $$ = $2; }
;
%%
	



/* El analizador lexico devuelve un numero en coma
flotante (double) en la pila y el token NUM, o el
caracter ASCII leido si no es un numero. Ignora
todos los espacios en blanco y tabuladores,
devuelve 0 como EOF. */


yylex ()
{
int c;

/* ignora los espacios en blanco */
while ((c = getchar ()) == ' ' || c == '\t') ;
/* procesa numeros*/
if (c == EOF)
return 0;
/* Comienza un numero => analiza el numero.*/
if (c == '.' || isdigit (c))
  {
    ungetc (c, stdin);
    scanf ("%lf", &yylval.val);
    return NUM;
  }

/* Comienza un identificador => lee el nombre. */
if (isalpha (c))
    {
      symrec *s;
      static char *symbuf = 0;
      static int length = 0;
      int i;
      /* Inicialmente hace el buffer lo suficientemente
  largo para un nombre de s ́mbolo de 40 caracteres. */

    if (length == 0)
      length = 40, symbuf = (char *)malloc (length + 1);
    i = 0;
    do
      {
	/* Si el buffer esta lleno, hacerlo mayor.*/
	if (i == length)
	  {
	    length *= 2;
	    symbuf = (char *)realloc (symbuf, length + 1);
	  }
	/* Añadir este caracter al buffer.*/
	symbuf[i++] = c;
	/* Obtiene otro caracter.*/
	c = getchar ();
      }
    while (c != EOF && isalnum (c));
    
    ungetc (c, stdin);
    symbuf[i] = '\0';
    s = getsym (symbuf);
    if (s == 0)
      s = putsym (symbuf, VAR);
    yylval.tptr = s;
    return s->type;
    }
  /* Cualquier otro caracter es un token por si mismo. */
  return c;

}







main ()
{
  init_table ();
  yyparse ();
}
yyerror (s) /* Llamada por yyparse ante un error */
char *s;
{
  printf ("%s\n", s);
}

struct init
{
  char *fname;
  double (*fnct)();
};

struct init arith_fncts[]
  = {
    "sin", sin,
    "cos", cos,
    "atan", atan,
    "ln", log,
    "exp", exp,
    "sqrt", sqrt,
    0, 0
  };
/* La tabla de simbolos: una cadena de ‘struct symrec'.*/

symrec *sym_table = (symrec *)0; /*MAGIA NEGRA!*/

init_table () /* pone las funciones aritmeticas en una tabla. */

{
  int i;
  symrec *ptr;
  for (i = 0; arith_fncts[i].fname != 0; i++)
    {
      ptr = putsym (arith_fncts[i].fname, FNCT);
      ptr->value.fnctptr = arith_fncts[i].fnct;
    }
}



symrec *putsym (sym_name,sym_type)
    
    char *sym_name;
    int sym_type;
{
    ptr = (symrec *) malloc (sizeof (symrec));
    ptr->name = (char *) malloc (strlen (sym_name) + 1);
    strcpy (ptr->name,sym_name);
    ptr->type = sym_type;
    ptr->value.var = 0; /* pone valor a 0 incluso si es fctn.*/
    ptr->next = (struct symrec *)sym_table;
    sym_table = ptr;
    return ptr;
}



symrec *getsym (sym_name) 
    
    char *sym_name;
{
  symrec *ptr;
  for (ptr = sym_table; ptr != (symrec *) 0;
      ptr = (symrec *)ptr->next)
    if (strcmp (ptr->name,sym_name) == 0)
      return ptr;
  return 0;
}




yyerror (s) /* Llamada por yyparse ante un error */
char *s;
{
printf ("%s\n", s);
}
