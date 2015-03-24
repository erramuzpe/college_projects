
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
     tok_cadena_long_1 = 258,
     tok_id = 259,
     tok_literal_numerico = 260,
     tok_comentario = 261,
     tok_cadena_caracteres = 262,
     tok_punto_y_coma = 263,
     tok_dos_puntos = 264,
     tok_puntopunto = 265,
     tok_coma = 266,
     tok_punto = 267,
     tok_corchetes = 268,
     tok_flecha = 269,
     tok_igual = 270,
     tok_asignacion = 271,
     tok_abre = 272,
     tok_cierra = 273,
     tok_abrec = 274,
     tok_cierrac = 275,
     tok_puntero = 276,
     tok_accion = 277,
     tok_algoritmo = 278,
     tok_cconst = 279,
     tok_continuar = 280,
     tok_de = 281,
     tok_dev = 282,
     tok_div = 283,
     tok_ent = 284,
     tok_e_s = 285,
     tok_entonces = 286,
     tok_faccion = 287,
     tok_falgoritmo = 288,
     tok_falso = 289,
     tok_fconst = 290,
     tok_ffuncion = 291,
     tok_fmientras = 292,
     tok_fpara = 293,
     tok_fsi = 294,
     tok_ftipo = 295,
     tok_ftupla = 296,
     tok_funcion = 297,
     tok_fvar = 298,
     tok_hacer = 299,
     tok_hasta = 300,
     tok_mientras = 301,
     tok_mod = 302,
     tok_no = 303,
     tok_oo = 304,
     tok_para = 305,
     tok_sal = 306,
     tok_si = 307,
     tok_tabla = 308,
     tok_tipo = 309,
     tok_tupla = 310,
     tok_var = 311,
     tok_verdadero = 312,
     tok_yy = 313,
     tok_mas = 314,
     tok_menos = 315,
     tok_menos_unario = 316,
     tok_por = 317,
     tok_potencia = 318,
     tok_menor = 319,
     tok_mayor = 320,
     tok_menor_igual = 321,
     tok_mayor_igual = 322,
     tok_distinto = 323,
     tok_entero = 324,
     tok_booleano = 325,
     tok_caracacter = 326
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


