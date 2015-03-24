%{
//#define YYSTYPE double

#define ENTERO -1
#define BOOLEANO -2
#define CARACTER -3

#define SUMA 1
#define RESTA 2
#define MULTI 3
#define DIVI 4
#define MENOS_UNARIO 5
#define MOD 6

#define O 7
#define Y 8

#include <stdio.h>
#include <ctype.h>
#include "tablaSimbolos.h"
#include "cuadruplas.h"

int cont = 0;
// Declaramos la tabla de simbolos y la tabla de cuadruplas
tablasimbolos t;
nodocuadrupla c;

//Para cualquier expresión, aritmética o booleana
typedef struct expr { 
    int place;
    int tipo;
}expr;
  
// ampliarrrrrrrrr

%}
    
%union {
    struct expr campo_expr;
    char* campo_id;
    int campo_tipo;
    //ampliarrrrrrr
}

%type <campo_expr> exp
%type <campo_tipo> tipo_escalar

/* Declaraciones de BISON */

%token <campo_id> tok_id
%token tok_literal_numerico
%token tok_comentario
%token tok_punto_y_coma
%token tok_dos_puntos
%token tok_puntopunto
%token tok_coma
%token tok_punto
%token tok_corchetes
%token tok_flecha
%token tok_igual
%token tok_asignacion
%token tok_abre
%token tok_cierra
%token tok_abrec
%token tok_cierrac
%token tok_puntero
%token tok_accion
%token tok_algoritmo
%token tok_cconst
%token tok_continuar
%token tok_de
%token tok_dev
%token tok_div
%token tok_ent
%token tok_e_s
%token tok_faccion
%token tok_falgoritmo
%token tok_falso
%token tok_fconst
%token tok_ffuncion
%token tok_fmientras
%token tok_fpara
%token tok_fsi
%token tok_ftipo
%token tok_ftupla
%token tok_funcion
%token tok_fvar
%token tok_hacer
%token tok_hasta
%token tok_mientras
%token tok_mod
%token tok_no
%token tok_oo
%token tok_para
%token tok_sal
%token tok_si
%token tok_tabla
%token tok_tipo
%token tok_tupla
%token tok_var
%token tok_verdadero
%token tok_yy
%token tok_mas
%token tok_menos
%token tok_menos_unario
%token tok_por
%token tok_menor
%token tok_mayor
%token tok_menor_igual
%token tok_mayor_igual
%token tok_distinto
%token tok_entero
%token tok_booleano
%token tok_caracter


%right tok_igual tok_menor tok_mayor tok_menor_igual tok_mayor_igual tok_distinto
%left tok_yy tok_oo
%left tok_menos tok_mas 
/* asociativo a izda y menos prioritario que lo que viene detras */
%left tok_por tok_div tok_mod 
/* negacion--menos unario */
%left tok_menos_unario


%% /* A continuacion las reglas gramaticales y las acciones */

//La gramatica del algoritmo
desc_algoritmo:	tok_algoritmo tok_id cabecera_alg bloque_alg tok_falgoritmo {}
		;

cabecera_alg:	decl_globales decl_a_f decl_ent_sal tok_comentario {}
		;

bloque_alg:	bloque tok_comentario {}
		;

decl_globales:	//puede ser el vacio
		| declaracion_tipo decl_globales {}
		| declaracion_const decl_globales {}
		;

decl_a_f:	//puede ser el vacio
		//| accion_d decl_a_f {}
		| funcion_d decl_a_f {}
		;

bloque:		declaraciones instrucciones {}
		;

declaraciones:	//puede ser el vacio
		| declaracion_tipo declaraciones {}
		| declaracion_const declaraciones {}
		| declaracion_var declaraciones {}
		;
		
//Declaraciones
declaracion_tipo:	tok_tipo lista_d_tipo tok_ftipo {}
		;

declaracion_const:	tok_cconst lista_d_cte tok_fconst {}
		;

declaracion_var:	tok_var lista_d_var tok_fvar {}
		;	

//Declaraciones de tipos
lista_d_tipo:	{} //puede ser el vacio
		| tok_id tok_igual d_tipo tok_punto_y_coma lista_d_tipo {}
		;

d_tipo:		tok_tupla lista_campos tok_ftupla {}
		| tok_tabla tok_abrec expresion_t tok_puntopunto expresion_t tok_cierrac tok_de tipo {}
		| expresion_t tok_puntopunto expresion_t {}
		| tok_puntero tipo {}
		;

expresion_t:	exp {}
		| tok_caracter {}
		;    

lista_campos: 	{} //puede ser el vacio
		| tok_id tok_dos_puntos tok_tipo tok_punto_y_coma lista_campos {}
		;

tipo:		tipo_escalar {
			     
			     }
		| tok_id {}
		;

//Escalares basicos
tipo_escalar:	tok_entero {
				  $$ = ENTERO;
			   }
		| tok_booleano {
				  $$ = BOOLEANO;
			       }
		| tok_caracter {
				  $$ = CARACTER;
			       }
		;

//Declaracion constantes
lista_d_cte:    {} //puede ser el vacio
		| tok_id tok_igual tok_literal_numerico tok_punto_y_coma lista_d_cte {} 
		| tok_id tok_igual tok_caracter tok_punto_y_coma lista_d_cte {}
		| tok_id tok_igual tok_verdadero tok_punto_y_coma lista_d_cte {}
		| tok_id tok_igual tok_falso tok_punto_y_coma lista_d_cte {}
		;

//Declaracion de variables
lista_d_var:	{}//puede ser el vacio
		| NLI tok_punto_y_coma lista_d_var {
						      
						   }
		//| lista_id tok_dos_puntos d_tipo tok_punto_y_coma lista_d_var {}
		;

NLI:		tok_id tok_dos_puntos tipo {

					   }
		| tok_id NLI {
  
			     }
		;

decl_ent_sal:	decl_ent {}
		| decl_ent decl_salida {}
    		| decl_salida {}
		;

decl_ent:	tok_ent lista_d_var {}
		;

decl_salida:	tok_sal lista_d_var {}
		;

//Expresiones
exp:		exp tok_mas exp {
				      nodo *T = newtemp(&t,cont);
				      $$.place = T;
				      modificarTipo(&t,ENTERO,cont);
				      cont++;
				      int cuadrupla[4] = {SUMA,$1.place,$3.place,T};
				      gen(&c,cuadrupla);
				      $$.tipo = ENTERO;
				}		  
		| exp tok_menos exp {
				      nodo *T = newtemp(&t,cont);
				      $$.place = T;
				      modificarTipo(&t,ENTERO,cont);
				      cont++;
				      int cuadrupla[4] = {RESTA,$1.place,$3.place,T};
				      gen(&c,cuadrupla);
				      $$.tipo = ENTERO;
				    }
		| exp tok_por exp {
				      nodo *T = newtemp(&t,cont);
				      $$.place = T;
				      modificarTipo(&t,ENTERO,cont);
				      cont++;
				      int cuadrupla[4] = {MULTI,$1.place,$3.place,T};
				      gen(&c,cuadrupla);
				      $$.tipo = ENTERO;
				  }
		| exp tok_div exp {
				      nodo *T = newtemp(&t,cont);
				      $$.place = T;
				      modificarTipo(&t,ENTERO,cont);
				      cont++;
				      int cuadrupla[4] = {DIVI,$1.place,$3.place,T};
				      gen(&c,cuadrupla);
				      $$.tipo = ENTERO;		      
				  }
		| tok_menos_unario exp {
				      nodo *T = newtemp(&t,cont);
				      $$.place = T;
				      modificarTipo(&t,ENTERO,cont);
				      cont++;
				      int cuadrupla[4] = {MENOS_UNARIO,$2.place,NULL,T};
				      gen(&c,cuadrupla);
				      $$.tipo = ENTERO;					
				       }
		| tok_abre exp tok_cierra {
				      $$.place = $2.place;
				      $$.tipo = $2.place;
					  }
		| operando {

			   }
		| tok_literal_numerico {

				       }
		| exp tok_yy exp {

				 }
		| exp tok_oo exp {

				 }
		| tok_no exp {

			     }
		| tok_verdadero {

				}
		| tok_falso {

			    }
		| exp oprel exp {

				}
		| funcion_ll {

			     }
		| exp tok_mod exp {
				      nodo *T = newtemp(&t,cont);
				      $$.place = T;
				      modificarTipo(&t,ENTERO,cont);
				      cont++;
				      int cuadrupla[4] = {MOD,$1.place,$3.place,T};
				      gen(&c,cuadrupla);
				      $$.tipo = ENTERO;      
				  }
		;

operando:	tok_id {}
		| operando tok_punto operando {}
		| operando tok_abrec exp tok_cierrac {}
		;

oprel:		tok_igual {}
		| tok_menor {}
		| tok_mayor {}
		| tok_menor_igual {}
		| tok_mayor_igual {}
		| tok_distinto {}
		;

// INSTRUCCIONES

instrucciones: 	instruccion tok_punto_y_coma instrucciones {} 
		| instruccion {}
		;

instruccion:  	tok_continuar {} 
		| asignacion {} 
		| alternativa {} 
		| iteracion {} 
		| accion_ll {}
		;

asignacion: 	operando tok_asignacion exp {}
		;

alternativa:	tok_si exp tok_flecha instrucciones lista_opciones tok_fsi {}
		;

lista_opciones:	{}//puede ser el vacio
		| tok_corchetes exp tok_flecha instrucciones lista_opciones {}
		;

iteracion:	it_cota_fija {} 
		| it_cota_exp {}
		;

it_cota_exp:	tok_mientras exp tok_hacer instrucciones tok_fmientras {

								       }
		;

it_cota_fija:	tok_para asignacion tok_hasta exp tok_hacer instrucciones tok_fpara {}
		;

// ACCIONES Y FUNCIONES

/*accion_d: 	tok_accion a_cabecera bloque tok_faccion {}*/
		;

funcion_d:	tok_funcion f_cabecera bloque tok_dev exp tok_ffuncion {}
		;

/*a_cabecera:	tok_id tok_abre d_par_form tok_cierra tok_punto_y_coma {}
		;*/

f_cabecera:	tok_id tok_abre lista_d_var tok_cierra tok_dev tok_tipo tok_punto_y_coma {}
		;

/*d_par_form:	{}// puede ser vacio
		| d_p_form tok_punto_y_coma d_par_form {}
		;*/

/*d_p_form:	tok_ent lista_id tok_dos_puntos tok_tipo {} 
		| tok_sal lista_id tok_dos_puntos tok_tipo {} 
		| tok_e_s lista_id tok_dos_puntos tok_tipo {}
		;*/

accion_ll:	tok_id tok_abre l_ll tok_cierra {}
		;

funcion_ll:	tok_id tok_abre l_ll tok_cierra {}
		;

l_ll:		exp tok_coma l_ll {}
		| exp {}
		;

%%
	



/* El analizador lexico devuelve un numero en coma
flotante (double) en la pila y el token NUM, o el
caracter ASCII leido si no es un numero. Ignora
todos los espacios en blanco y tabuladores,
devuelve 0 como EOF. */



main (int argc, char *argv[]) {
    // Creamos la tabla de simbolos y la de cuadruplas
    t = crearTablaSimbolos();
    c = crear(200);

    extern FILE *yyin;
    //++argv; --argc;

    yyin = fopen( argv[0], "r" );
    if (yyin == NULL) {
	fprintf(stderr, "Cannot open %s file\n", argv[0]);
	return 1;
    }
    yyparse ();
}




yyerror (s) /* Llamada por yyparse ante un error */
char *s;
{
  printf ("%s\n", s);
}

