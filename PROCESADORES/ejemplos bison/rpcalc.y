/* Calculadora de notacion polaca inversa. */

%{
#define YYSTYPE double
#include <math.h>
#include <stdio.h>
#include <ctype.h>
%}

%token NUM

%% /* A continuaci ́n las reglas gramaticales y las acciones */

input: /* vacio */
      | input line
;

line:	'\n'
	| exp '\n' { printf ("\t%.10g\n", $1); }
;

exp:	NUM		{ $$ = $1; }
	| exp exp '+'	{ $$ = $1 + $2; }
	| exp exp '-'	{ $$ = $1 - $2; }
	| exp exp '*'	{ $$ = $1 * $2; }
	| exp exp '/'	{ $$ = $1 / $2; }
/* Exponenciacion */	
	| exp exp '^'	{ $$ = pow ($1, $2); }
/* Menos unario */
	| exp 'n'	{ $$ = -$1; }
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

	
	
