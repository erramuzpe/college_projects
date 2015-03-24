
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     tok_id = 258,
     tok_literal_numerico = 259,
     tok_comentario = 260,
     tok_punto_y_coma = 261,
     tok_dos_puntos = 262,
     tok_puntopunto = 263,
     tok_coma = 264,
     tok_punto = 265,
     tok_corchetes = 266,
     tok_flecha = 267,
     tok_igual = 268,
     tok_asignacion = 269,
     tok_abre = 270,
     tok_cierra = 271,
     tok_abrec = 272,
     tok_cierrac = 273,
     tok_puntero = 274,
     tok_accion = 275,
     tok_algoritmo = 276,
     tok_cconst = 277,
     tok_continuar = 278,
     tok_de = 279,
     tok_dev = 280,
     tok_div = 281,
     tok_ent = 282,
     tok_e_s = 283,
     tok_faccion = 284,
     tok_falgoritmo = 285,
     tok_falso = 286,
     tok_fconst = 287,
     tok_ffuncion = 288,
     tok_fmientras = 289,
     tok_fpara = 290,
     tok_fsi = 291,
     tok_ftipo = 292,
     tok_ftupla = 293,
     tok_funcion = 294,
     tok_fvar = 295,
     tok_hacer = 296,
     tok_hasta = 297,
     tok_mientras = 298,
     tok_mod = 299,
     tok_no = 300,
     tok_oo = 301,
     tok_para = 302,
     tok_sal = 303,
     tok_si = 304,
     tok_tabla = 305,
     tok_tipo = 306,
     tok_tupla = 307,
     tok_var = 308,
     tok_verdadero = 309,
     tok_yy = 310,
     tok_mas = 311,
     tok_menos = 312,
     tok_menos_unario = 313,
     tok_por = 314,
     tok_menor = 315,
     tok_mayor = 316,
     tok_menor_igual = 317,
     tok_mayor_igual = 318,
     tok_distinto = 319,
     tok_entero = 320,
     tok_booleano = 321,
     tok_caracter = 322
   };
#endif
/* Tokens.  */
#define tok_id 258
#define tok_literal_numerico 259
#define tok_comentario 260
#define tok_punto_y_coma 261
#define tok_dos_puntos 262
#define tok_puntopunto 263
#define tok_coma 264
#define tok_punto 265
#define tok_corchetes 266
#define tok_flecha 267
#define tok_igual 268
#define tok_asignacion 269
#define tok_abre 270
#define tok_cierra 271
#define tok_abrec 272
#define tok_cierrac 273
#define tok_puntero 274
#define tok_accion 275
#define tok_algoritmo 276
#define tok_cconst 277
#define tok_continuar 278
#define tok_de 279
#define tok_dev 280
#define tok_div 281
#define tok_ent 282
#define tok_e_s 283
#define tok_faccion 284
#define tok_falgoritmo 285
#define tok_falso 286
#define tok_fconst 287
#define tok_ffuncion 288
#define tok_fmientras 289
#define tok_fpara 290
#define tok_fsi 291
#define tok_ftipo 292
#define tok_ftupla 293
#define tok_funcion 294
#define tok_fvar 295
#define tok_hacer 296
#define tok_hasta 297
#define tok_mientras 298
#define tok_mod 299
#define tok_no 300
#define tok_oo 301
#define tok_para 302
#define tok_sal 303
#define tok_si 304
#define tok_tabla 305
#define tok_tipo 306
#define tok_tupla 307
#define tok_var 308
#define tok_verdadero 309
#define tok_yy 310
#define tok_mas 311
#define tok_menos 312
#define tok_menos_unario 313
#define tok_por 314
#define tok_menor 315
#define tok_mayor 316
#define tok_menor_igual 317
#define tok_mayor_igual 318
#define tok_distinto 319
#define tok_entero 320
#define tok_booleano 321
#define tok_caracter 322




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{


    expr campo_expr;
    char* campo_id;
    int campo_tipo;
    //ampliarrrrrrr



} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


