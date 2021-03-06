/* Analizador PRALSIM de flex. */
//Compilar flex lenguaje.lex
//	   gcc -o lenguaje lenguaje.c -lfl
//Bison    bison -d -ly analizador.y
%{

#include <stdio.h>
#include <stdlib.h>

%}
a			[aA]
b			[bB]
c			[cC]
d			[dD]
e			[eE]
f			[fF]
g			[gG]
h			[hH]
i			[iI]
j			[jJ]
k			[kK]
l			[lL]
m			[mM]
n			[nN]
o			[oO]
p			[pP]
q			[qQ]
r			[rR]
s			[sS]
t			[tT]
u			[uU]
v			[vV]
w			[wW]
x			[xX]
y			[yY]
z			[zZ]

letra_mayuscula 	[A-Z]
letra_minuscula 	[a-z]
cifra	 		[0-9]
letra			{letra_mayuscula}|{letra_minuscula}
id			({letra})({letra}|{cifra})*
literal_numerico	[+-]?cifra+
comentario		{[^}|\}]*}
cadena_caracteres	\"[^"|\"]*\" 

/*nuestros*/
punto_y_coma	[;]
dos_puntos	[:]
asignacion	[:][=]
abre		[(]
cierra		[)]


accion		[a][c][c][i][o][n]
algoritmo 	[a][l][g][o][r][i][t][m][o]
cconst		[c][o][n][s][t]
continuar 	[c][o][n][t][i][n][u][a][r]
de		[d][e]
dev		[d][e][v]
div		[d][i][v]
ent		[e][n][t]
e_s		[e][/][s]
entonces	[e][n][t][o][n][c][e][s]
faccion		[f][a][c][c][i][o][n]
falgoritmo	[f][a][l][g][o][r][i][t][m][o]
falso		[f][a][l][s][o]
fconst		[f][c][o][n][s][t]
ffuncion	[f][f][u][n][c][i][o][n]
fmientras	[f][m][i][e][n][t][r][a][s]
fpara		[f][p][a][r][a]
fsi		[f][s][i]
ftipo		[f][t][i][p][o]
ftupla		[f][t][u][p][l][a]
funcion		[f][u][n][c][i][o][n]
fvar		[f][v][a][r]
hacer		[h][a][c][e][r]
hasta		[h][a][s][t][a]
mientras	[m][i][e][n][t][r][a][s]
mod		[m][o][d]
no		[n][o]
o		[o]
para		[p][a][r][a]
sal		[s][a][l]
si		[s][i]
tabla		[t][a][b][l][a]
tipo		[t][i][p][o]
tupla		[t][u][p][l][a]
var		[v][a][r]
verdadero	[v][e][r][d][a][d][e][r][o]
y		[y]



%%

id			{return tok_id;}
literal_numerico	{return tok_literal_numerico;}
comentario		{return tok_comentario;}
cadena_caracteres	{return tok_cadena_caracteres;}
punto_y_coma	{return tok_punto_y_coma;}
dos_puntos	{return tok_dos_puntos;}
asignacion	{return tok_asignacion;}
abre		{return tok_abre;}
cierra		{return tok_cierra;}
accion		{return tok_accion;}
algoritmo 	{return tok_algoritmo;}
cconst		{return tok_cconst;}
continuar 	{return tok_continuar;}
de		{return tok_de;}
dev		{return tok_dev;}
div		{return tok_div;}
ent		{return tok_ent;}
e_s		{return tok_e_s;}
entonces	{return tok_entonces;}
faccion		{return tok_faccion;}
falgoritmo	{return tok_falgoritmo;}
falso		{return tok_falso;}
fconst		{return tok_fconst;}
ffuncion	{return tok_ffuncion;}
fmientras	{return tok_fmientras;}
fpara		{return tok_fpara;}
fsi		{return tok_fsi;}
ftipo		{return tok_ftipo;}
ftupla		{return tok_ftupla;}
funcion		{return tok_funcion;}
fvar		{return tok_fvar;}
hacer		{return tok_hacer;}
hasta		{return tok_hasta;}
mientras	{return tok_mientras;}
mod		{return tok_mod;}
no		{return tok_no;}
o		{return tok_o;}
para		{return tok_para;}
sal		{return tok_sal;}
si		{return tok_si;}
tabla		{return tok_tabla;}
tipo		{return tok_tipo;}
tupla		{return tok_tupla;}
var		{return tok_var;}
verdadero	{return tok_verdadero;}
y		{return tok_y;}


"\n"			{printf("Salto de línea");}

"." 			{printf("waka %s",yylex);}

<<EOF>>			return 0;

%%


int main( int argc, char** argv){

  extern FILE *yyin;
	++argv; --argc;

	yyin = fopen( argv[0], "r" );
  	if (yyin == NULL) {
   	  fprintf(stderr, "Cannot open %s file\n", argv[0]);
  	  return 1;
  	}

  return yylex();
}


