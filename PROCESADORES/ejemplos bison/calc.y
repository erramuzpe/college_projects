/* Calculadora de notacion notacion infija--calc */

%{
#define YYSTYPE double
#include <math.h>
#include <stdio.h>
#include <ctype.h>
%}


/* Declaraciones de BISON */

%token NUM
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

exp:	NUM			{ $$ = $1; }
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

while ((c = getchar ()) == ' ' || c == '\t')
;

/* procesa numeros*/

if (c == '.' || isdigit (c))
{
ungetc (c, stdin);
scanf ("%lf", &yylval);
return NUM;
}

/* devuelve fin-de-fichero */

if (c == EOF)
return 0;

/* devuelve caracteres sencillos */
return c;
}

main ()
{
yyparse ();
}



yyerror (s) /* Llamada por yyparse ante un error */
char *s;
{
printf ("%s\n", s);
}

	
	
