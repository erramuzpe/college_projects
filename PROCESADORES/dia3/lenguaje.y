%{
#define YYSTYPE double
#include <stdio.h>
#include <ctype.h>
//Compilar flex lenguaje.lex
//	   gcc -o lenguaje lenguaje.c -lfl
//Bison    bison -d -ly analizador.y
%}


/* Declaraciones de BISON */

%token tok_cadena_long_1
%token tok_id
%token tok_literal_numerico
%token tok_comentario
%token tok_cadena_caracteres
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
%token tok_entonces
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
%token tok_potencia
%token tok_menor
%token tok_mayor
%token tok_menor_igual
%token tok_mayor_igual
%token tok_distinto



%right tok_igual
%left tok_menos tok_mas 
/* asociativo a izda y menos prioritario que lo que 
viene detras */
%left tok_por tok_div
/* negacion--menos unario */
%left tok_menos_unario
%right tok_potencia
/* exponenciacion */


%% /* A continuacion las reglas gramaticales y las acciones */

//La gramatica del algoritmo
desc_algoritmo:	tok_algoritmo tok_id cabecera_alg bloque_alg tok_falgoritmo;

cabecera_alg:	decl_globales decl_a_f decl_ent_sal tok_comentario;

bloque_alg:	bloque tok_comentario;

decl_globales:	//puede ser el vacio
		| declaracion_tipo decl_globales
		| declaracion_const decl_globales;

decl_a_f:	//puede ser el vacio
		| accion_d decl_a_f
		| funcion_d decl_a_f;

bloque:		declaraciones instrucciones;

declaraciones:	//puede ser el vacio
		| declaracion_tipo declaraciones
		| declaracion_const declaraciones
		| declaracion_var declaraciones;
		
//Declaraciones
declaracion_tipo:	tok_tipo lista_d_tipo tok_ftipo;

declaracion_const:	tok_cconst lista_d_cte tok_fconst;

declaracion_var:	tok_var lista_d_var tok_fvar;	

//Declaraciones de tipos
lista_d_tipo:	//puede ser el vacio
		| tok_id tok_igual d_tipo tok_punto_y_coma lista_d_tipo;

d_tipo:		tok_tupla lista_campos tok_ftupla
		| tok_tabla tok_abrec expresion_t tok_puntopunto expresion_t tok_cierrac tok_de tok_id
		| tok_id
		| expresion_t tok_puntopunto expresion_t;
		// | tok_puntero tipo 

expresion_t:	expresion
		| caracter;     

lista_campos: 	//puede ser el vacio
		| tok_id tok_dos_puntos tok_tipo tok_punto_y_coma lista_campos;

tipo:		tipo_escalar //////////////////////////////////////////////////////////////
		| tok_id;

caracter:	tok_cadena_long_1;

//Escalares basicos: entero,bool,caracter /////////////////////////////////////////////////////////////////////////////////////////////


//Declaracion constantes
lista_d_cte:    //puede ser el vacio
		| tok_id tok_igual literal_numerico tok_punto_y_coma lista_d_cte   ///////////
		| tok_id tok_igual caracter tok_punto_y_coma lista_d_cte
		| tok_id tok_igual tok_verdadero tok_punto_y_coma lista_d_cte
		| tok_id tok_igual tok_falso tok_punto_y_coma lista_d_cte;

//Declaracion de variables
lista_d_var:	//puede ser el vacio
		| lista_id tok_dos_puntos tok_id tok_punto_y_coma lista_d_var
		| lista_id tok_dos_puntos d_tipo tok_punto_y_coma lista_d_var;

lista_id:	//puede ser el vacio
		| tok_id tok_coma lista_id;

decl_ent_sal:	decl_ent
		| decl_ent decl_salida
    		| decl_salida;

decl_ent:	tok_ent lista_d_var;

decl_salida:	tok_sal lista_d_var;

//Expresiones
expresion:	exp_a
		| exp_b
		| funcion_ll;

exp_a:		exp_a tok_mas exp_a
		| exp_a tok_menos exp_a
		| exp_a tok_por exp_a
		| exp_a tok_div exp_a
		| tok_menos_unario exp_a
		| tok_abre exp_a tok_cierra
		| operando
		| tok_literal_numerico;

exp_b:		exp_b tok_yy exp_b
		| exp_b tok_oo exp_b
		| tok_no exp_b
		| operando
		| tok_verdadero
		| tok_falso
		| expresion oprel expresion
		| tok_abre exp_b tok_cierra;

operando:	tok_id
		| operando tok_punto operando
		| operando tok_abrec expresion tok_cierrac
		| operando tok_puntero; //no sabemos

oprel:		tok_igual
		| tok_menor
		| tok_mayor
		| tok_menor_igual
		| tok_mayor_igual
		| tok_distinto;

// INSTRUCCIONES

instrucciones: 	instruccion tok_punto_y_coma instrucciones 
		| instruccion;

instruccion:  	tok_continuar 
		| asignacion 
		| alternativa 
		| iteracion 
		| accion_ll;

asignacion: 	operando tok_asignacion expresion;

alternativa:	tok_si expresion tok_flecha instrucciones lista_opciones tok_fsi;

lista_opciones:	//puede ser el vacio
		| tok_corchetes expresion tok_flecha instrucciones lista_opciones; 

iteracion:	it_cota_fija 
		| it_cota_exp;

it_cota_exp:	tok_mientras expresion tok_hacer instrucciones tok_fmientras;

it_cota_fija:	tok_para asignacion tok_hasta expresion tok_hacer instrucciones tok_fpara;

// ACCIONES Y FUNCIONES

accion_d: 	tok_accion a_cabecera bloque tok_faccion;

funcion_d:	tok_funcion f_cabecera bloque tok_dev expresion tok_ffuncion;

a_cabecera:	tok_id tok_abre d_par_form tok_cierra tok_punto_y_coma;

f_cabecera:	tok_id tok_abre lista_d_var tok_cierra tok_dev tok_tipo tok_punto_y_coma;

d_par_form:	// puede ser vacio
		| d_p_form tok_punto_y_coma d_par_form;

d_p_form:	tok_ent lista_id tok_dos_puntos tok_tipo 
		| tok_sal lista_id tok_dos_puntos tok_tipo 
		| tok_e_s lista_id tok_dos_puntos tok_tipo;

accion_ll:	tok_id tok_abre l_ll tok_cierra;

funcion_ll:	tok_id tok_abre l_ll tok_cierra;

l_ll:		expresion tok_coma l_ll
		| expresion;

%%
	



/* El analizador lexico devuelve un numero en coma
flotante (double) en la pila y el token NUM, o el
caracter ASCII leido si no es un numero. Ignora
todos los espacios en blanco y tabuladores,
devuelve 0 como EOF. */



main ()
{
  extern FILE *yyin;
	++argv; --argc;

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

