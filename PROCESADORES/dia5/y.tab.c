
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */


#define YYSTYPE double

#define ENTERO 1
#define BOOLEANO 2
#define CARACTER 3

#include <stdio.h>
#include <ctype.h>
//Compilar flex gramar.lex
//Bison    bison -d -v -ly lenguaje.y
//	   gcc -o lenguaje lex.yy.c -lfl




/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


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
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */



#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   427

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  68
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  102
/* YYNRULES -- Number of states.  */
#define YYNSTATES  231

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   322

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     9,    14,    17,    18,    21,    24,    25,
      28,    31,    34,    35,    38,    41,    44,    48,    52,    56,
      57,    63,    67,    76,    80,    83,    85,    87,    88,    94,
      96,    98,   100,   102,   104,   105,   111,   117,   123,   129,
     130,   136,   142,   143,   147,   149,   152,   154,   157,   160,
     164,   168,   172,   176,   179,   183,   185,   187,   191,   195,
     198,   200,   202,   206,   208,   212,   214,   218,   223,   226,
     228,   230,   232,   234,   236,   238,   242,   244,   246,   248,
     250,   252,   254,   258,   265,   266,   272,   274,   276,   282,
     290,   295,   302,   308,   316,   317,   321,   326,   331,   336,
     341,   346,   350
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      69,     0,    -1,    21,     3,    70,    71,    30,    -1,    72,
      73,    88,     5,    -1,    74,     5,    -1,    -1,    76,    72,
      -1,    77,    72,    -1,    -1,   102,    73,    -1,   103,    73,
      -1,    75,    94,    -1,    -1,    76,    75,    -1,    77,    75,
      -1,    78,    75,    -1,    51,    79,    37,    -1,    22,    85,
      32,    -1,    53,    86,    40,    -1,    -1,     3,    13,    80,
       6,    79,    -1,    52,    82,    38,    -1,    50,    17,    81,
       8,    81,    18,    24,     3,    -1,    81,     8,    81,    -1,
      19,    83,    -1,    91,    -1,    67,    -1,    -1,     3,     7,
      51,     6,    82,    -1,    84,    -1,     3,    -1,    65,    -1,
      66,    -1,    67,    -1,    -1,     3,    13,     4,     6,    85,
      -1,     3,    13,    67,     6,    85,    -1,     3,    13,    54,
       6,    85,    -1,     3,    13,    31,     6,    85,    -1,    -1,
      87,     7,    83,     6,    86,    -1,    87,     7,    80,     6,
      86,    -1,    -1,     3,     9,    87,    -1,    89,    -1,    89,
      90,    -1,    90,    -1,    27,    86,    -1,    48,    86,    -1,
      91,    56,    91,    -1,    91,    57,    91,    -1,    91,    59,
      91,    -1,    91,    26,    91,    -1,    58,    91,    -1,    15,
      91,    16,    -1,    92,    -1,     4,    -1,    91,    55,    91,
      -1,    91,    46,    91,    -1,    45,    91,    -1,    54,    -1,
      31,    -1,    91,    93,    91,    -1,   109,    -1,    91,    44,
      91,    -1,     3,    -1,    92,    10,    92,    -1,    92,    17,
      91,    18,    -1,    92,    19,    -1,    13,    -1,    60,    -1,
      61,    -1,    62,    -1,    63,    -1,    64,    -1,    95,     6,
      94,    -1,    95,    -1,    23,    -1,    96,    -1,    97,    -1,
      99,    -1,   108,    -1,    92,    14,    91,    -1,    49,    91,
      12,    94,    98,    36,    -1,    -1,    11,    91,    12,    94,
      98,    -1,   101,    -1,   100,    -1,    43,    91,    41,    94,
      34,    -1,    47,    96,    42,    91,    41,    94,    35,    -1,
      20,   104,    74,    29,    -1,    39,   105,    74,    25,    91,
      33,    -1,     3,    15,   106,    16,     6,    -1,     3,    15,
      86,    16,    25,    51,     6,    -1,    -1,   107,     6,   106,
      -1,    27,    87,     7,    51,    -1,    48,    87,     7,    51,
      -1,    28,    87,     7,    51,    -1,     3,    15,   110,    16,
      -1,     3,    15,   110,    16,    -1,    91,     9,   110,    -1,
      91,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    98,    98,   100,   102,   104,   105,   106,   108,   109,
     110,   112,   114,   115,   116,   117,   120,   122,   124,   127,
     128,   130,   131,   132,   133,   135,   136,   138,   139,   141,
     142,   145,   146,   147,   150,   151,   152,   153,   154,   157,
     158,   159,   161,   162,   164,   165,   166,   168,   170,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   190,   191,   192,   193,   195,
     196,   197,   198,   199,   200,   204,   205,   207,   208,   209,
     210,   211,   213,   215,   217,   218,   220,   221,   223,   225,
     229,   231,   233,   235,   237,   238,   240,   241,   242,   244,
     246,   248,   249
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "tok_id", "tok_literal_numerico",
  "tok_comentario", "tok_punto_y_coma", "tok_dos_puntos", "tok_puntopunto",
  "tok_coma", "tok_punto", "tok_corchetes", "tok_flecha", "tok_igual",
  "tok_asignacion", "tok_abre", "tok_cierra", "tok_abrec", "tok_cierrac",
  "tok_puntero", "tok_accion", "tok_algoritmo", "tok_cconst",
  "tok_continuar", "tok_de", "tok_dev", "tok_div", "tok_ent", "tok_e_s",
  "tok_faccion", "tok_falgoritmo", "tok_falso", "tok_fconst",
  "tok_ffuncion", "tok_fmientras", "tok_fpara", "tok_fsi", "tok_ftipo",
  "tok_ftupla", "tok_funcion", "tok_fvar", "tok_hacer", "tok_hasta",
  "tok_mientras", "tok_mod", "tok_no", "tok_oo", "tok_para", "tok_sal",
  "tok_si", "tok_tabla", "tok_tipo", "tok_tupla", "tok_var",
  "tok_verdadero", "tok_yy", "tok_mas", "tok_menos", "tok_menos_unario",
  "tok_por", "tok_menor", "tok_mayor", "tok_menor_igual",
  "tok_mayor_igual", "tok_distinto", "tok_entero", "tok_booleano",
  "tok_caracter", "$accept", "desc_algoritmo", "cabecera_alg",
  "bloque_alg", "decl_globales", "decl_a_f", "bloque", "declaraciones",
  "declaracion_tipo", "declaracion_const", "declaracion_var",
  "lista_d_tipo", "d_tipo", "expresion_t", "lista_campos", "tipo",
  "tipo_escalar", "lista_d_cte", "lista_d_var", "lista_id", "decl_ent_sal",
  "decl_ent", "decl_salida", "exp", "operando", "oprel", "instrucciones",
  "instruccion", "asignacion", "alternativa", "lista_opciones",
  "iteracion", "it_cota_exp", "it_cota_fija", "accion_d", "funcion_d",
  "a_cabecera", "f_cabecera", "d_par_form", "d_p_form", "accion_ll",
  "funcion_ll", "l_ll", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    68,    69,    70,    71,    72,    72,    72,    73,    73,
      73,    74,    75,    75,    75,    75,    76,    77,    78,    79,
      79,    80,    80,    80,    80,    81,    81,    82,    82,    83,
      83,    84,    84,    84,    85,    85,    85,    85,    85,    86,
      86,    86,    87,    87,    88,    88,    88,    89,    90,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    92,    92,    92,    92,    93,
      93,    93,    93,    93,    93,    94,    94,    95,    95,    95,
      95,    95,    96,    97,    98,    98,    99,    99,   100,   101,
     102,   103,   104,   105,   106,   106,   107,   107,   107,   108,
     109,   110,   110
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     4,     2,     0,     2,     2,     0,     2,
       2,     2,     0,     2,     2,     2,     3,     3,     3,     0,
       5,     3,     8,     3,     2,     1,     1,     0,     5,     1,
       1,     1,     1,     1,     0,     5,     5,     5,     5,     0,
       5,     5,     0,     3,     1,     2,     1,     2,     2,     3,
       3,     3,     3,     2,     3,     1,     1,     3,     3,     2,
       1,     1,     3,     1,     3,     1,     3,     4,     2,     1,
       1,     1,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     3,     6,     0,     5,     1,     1,     5,     7,
       4,     6,     5,     7,     0,     3,     4,     4,     4,     4,
       4,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     5,     1,    34,    19,    12,     8,     5,
       5,     0,     0,     0,     0,    39,     0,     0,     0,    12,
      12,    12,     0,     0,     0,     8,     8,     6,     7,     0,
      17,     0,    16,     0,     0,     0,     2,     4,    65,    77,
       0,     0,     0,     0,    11,    76,    78,    79,    80,    87,
      86,    81,    13,    14,    15,     0,    12,     0,    12,    39,
      39,     0,    44,    46,     9,    10,     0,     0,     0,     0,
      65,    56,     0,     0,    61,     0,     0,    27,    60,     0,
      26,     0,     0,    25,    55,    63,    42,    18,     0,     0,
       0,    65,     0,     0,     0,     0,     0,    68,     0,    94,
       0,    39,     0,    47,    48,     3,    45,    34,    34,    34,
      34,     0,     0,    30,    31,    32,    33,    24,    29,    59,
       0,     0,     0,    53,    19,     0,    69,     0,     0,     0,
       0,     0,     0,     0,    70,    71,    72,    73,    74,     0,
      43,    65,    26,     0,     0,   102,     0,     0,     0,     0,
      66,    82,     0,    75,    42,    42,    42,     0,     0,    90,
       0,     0,    35,    38,    37,    36,     0,    54,     0,     0,
      21,    20,    23,    52,    64,    58,    57,    49,    50,    51,
      62,    39,    39,     0,    99,     0,     0,    84,    67,     0,
       0,     0,     0,    94,     0,     0,   100,     0,     0,    41,
      40,   101,    88,     0,     0,     0,     0,     0,     0,    92,
      95,     0,    91,     0,    27,     0,     0,    83,    96,    98,
      97,     0,     0,    28,    89,     0,    93,     0,    84,    22,
      85
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     7,    16,     8,    24,    17,    18,    19,    20,
      21,    14,    81,    82,   122,   117,   118,    12,    34,    35,
      61,    62,    63,    83,    84,   139,    44,    45,    46,    47,
     205,    48,    49,    50,    25,    26,    56,    58,   157,   158,
      51,    85,   146
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -119
static const yytype_int16 yypact[] =
{
      -4,    22,    51,    -7,  -119,    70,    92,     2,    -2,    -7,
      -7,    41,    67,   102,    69,    28,   103,   118,    64,     2,
       2,     2,   122,   127,   -19,    -2,    -2,  -119,  -119,    10,
    -119,   137,  -119,   123,    97,   132,  -119,  -119,   131,  -119,
      17,   139,    17,    49,  -119,   142,  -119,  -119,  -119,  -119,
    -119,  -119,  -119,  -119,  -119,   134,     2,   135,     2,    28,
      28,   148,   106,  -119,  -119,  -119,   149,   151,   155,   157,
     152,  -119,    17,    36,  -119,    17,   147,   170,  -119,    17,
    -119,   168,   167,   363,   100,  -119,   173,  -119,    93,    17,
     232,  -119,   136,   180,   139,    17,    17,  -119,    64,    -1,
     154,    28,   156,  -119,  -119,  -119,  -119,    70,    70,    70,
      70,    17,   258,  -119,  -119,  -119,  -119,  -119,  -119,   363,
       7,   177,   150,  -119,    92,     7,  -119,    17,    17,    17,
      17,    17,    17,    17,  -119,  -119,  -119,  -119,  -119,    17,
    -119,    13,   171,   174,   184,   153,   178,    64,    17,    64,
     100,   363,   285,  -119,   173,   173,   173,   182,   190,  -119,
     185,    17,  -119,  -119,  -119,  -119,   186,  -119,   192,   160,
    -119,  -119,  -119,  -119,  -119,   -14,   -14,   -10,   -10,  -119,
     363,    28,    28,    17,  -119,   169,   310,   175,  -119,   198,
     213,   214,   216,    -1,   200,   342,  -119,     7,   217,  -119,
    -119,  -119,  -119,    64,    17,   191,   179,   183,   187,  -119,
    -119,   195,  -119,   210,   170,   194,   206,  -119,  -119,  -119,
    -119,   225,   209,  -119,  -119,    64,  -119,   244,   175,  -119,
    -119
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -119,  -119,  -119,  -119,   111,    44,    60,    65,    95,   125,
    -119,   124,   161,  -118,    37,   165,  -119,    62,   -55,   -73,
    -119,  -119,   193,   -39,   -18,  -119,   -89,  -119,   215,  -119,
      26,  -119,  -119,  -119,  -119,  -119,  -119,  -119,    66,  -119,
    -119,  -119,  -105
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -43
static const yytype_int16 yytable[] =
{
      43,    90,   168,    93,   103,   104,   166,   172,    59,   153,
      70,    71,   127,   140,    66,     5,   127,     1,    22,   -30,
      70,    71,    72,    43,     5,     3,   154,   155,   111,    60,
     128,    33,    72,   112,   128,   -42,   119,    23,    74,   113,
     123,    67,   131,   132,     6,   133,   160,   156,    74,   133,
     145,     4,    75,     6,    29,    15,   151,   152,   185,    94,
     187,    78,    75,    95,    68,    79,    96,    38,    97,    64,
      65,    78,   145,    11,    80,    79,   150,    69,   201,   213,
      43,   189,   190,   191,    52,    53,    54,    39,   173,   174,
     175,   176,   177,   178,   179,    13,   141,    71,     9,    30,
     180,   114,   115,   116,     9,     9,    32,    40,    72,   186,
      94,    41,    73,    42,   215,    31,   100,    96,   102,    97,
      27,    28,   195,    37,    74,    55,   199,   200,    10,    43,
      57,    43,    86,    36,    10,    10,   228,    87,    75,    88,
      70,    71,    91,    76,   145,    77,    89,    78,    98,    99,
     101,    79,    72,   105,    60,   107,    73,   108,   114,   115,
     142,   109,   183,   110,   120,   216,   126,   111,    74,   162,
     163,   164,   165,   121,   124,   125,    33,   -33,   148,   127,
     181,   161,    75,   159,   169,    43,   204,    76,   170,    77,
     182,    78,   149,   126,   184,    79,   193,   128,   192,   129,
     197,   194,   196,   202,    80,   206,   127,    43,   130,   131,
     132,   198,   133,   134,   135,   136,   137,   138,   225,   126,
     207,   208,   209,   214,   128,   211,   129,   217,   222,   224,
     218,   226,   127,   227,   219,   130,   131,   132,   220,   133,
     134,   135,   136,   137,   138,   126,   221,   229,   171,   143,
     128,   223,   129,   144,   230,   106,    92,     0,   127,   210,
       0,   130,   131,   132,     0,   133,   134,   135,   136,   137,
     138,   126,     0,   147,   167,     0,   128,     0,   129,     0,
       0,     0,     0,     0,   127,     0,     0,   130,   131,   132,
       0,   133,   134,   135,   136,   137,   138,     0,   126,     0,
       0,     0,   128,   188,   129,     0,     0,     0,     0,     0,
       0,   127,     0,   130,   131,   132,     0,   133,   134,   135,
     136,   137,   138,   126,     0,     0,     0,     0,     0,   128,
       0,   129,     0,     0,     0,     0,   127,     0,     0,     0,
     130,   131,   132,     0,   133,   134,   135,   136,   137,   138,
       0,   203,     0,     0,   128,   126,   129,     0,     0,     0,
       0,     0,     0,     0,     0,   130,   131,   132,   127,   133,
     134,   135,   136,   137,   138,   212,   126,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   128,     0,   129,   127,
       0,     0,     0,     0,     0,     0,     0,   130,   131,   132,
       0,   133,   134,   135,   136,   137,   138,   128,     0,   129,
       0,     0,     0,     0,     0,     0,     0,     0,   130,   131,
     132,     0,   133,   134,   135,   136,   137,   138
};

static const yytype_int16 yycheck[] =
{
      18,    40,   120,    42,    59,    60,   111,   125,    27,    98,
       3,     4,    26,    86,     4,    22,    26,    21,    20,     6,
       3,     4,    15,    41,    22,     3,    27,    28,    15,    48,
      44,     3,    15,    72,    44,     7,    75,    39,    31,     3,
      79,    31,    56,    57,    51,    59,   101,    48,    31,    59,
      89,     0,    45,    51,    13,    53,    95,    96,   147,    10,
     149,    54,    45,    14,    54,    58,    17,     3,    19,    25,
      26,    54,   111,     3,    67,    58,    94,    67,   183,   197,
      98,   154,   155,   156,    19,    20,    21,    23,   127,   128,
     129,   130,   131,   132,   133,     3,     3,     4,     3,    32,
     139,    65,    66,    67,     9,    10,    37,    43,    15,   148,
      10,    47,    19,    49,   203,    13,    56,    17,    58,    19,
       9,    10,   161,     5,    31,     3,   181,   182,     3,   147,
       3,   149,     9,    30,     9,    10,   225,    40,    45,     7,
       3,     4,     3,    50,   183,    52,    15,    54,     6,    15,
      15,    58,    15,     5,    48,     6,    19,     6,    65,    66,
      67,     6,     9,     6,    17,   204,    13,    15,    31,   107,
     108,   109,   110,     3,     6,     8,     3,     6,    42,    26,
       6,    25,    45,    29,     7,   203,    11,    50,    38,    52,
       6,    54,    12,    13,    16,    58,     6,    44,    16,    46,
       8,    16,    16,    34,    67,     7,    26,   225,    55,    56,
      57,    51,    59,    60,    61,    62,    63,    64,    12,    13,
       7,     7,     6,     6,    44,    25,    46,    36,    18,    35,
      51,     6,    26,    24,    51,    55,    56,    57,    51,    59,
      60,    61,    62,    63,    64,    13,    51,     3,   124,    88,
      44,   214,    46,    88,   228,    62,    41,    -1,    26,   193,
      -1,    55,    56,    57,    -1,    59,    60,    61,    62,    63,
      64,    13,    -1,    41,    16,    -1,    44,    -1,    46,    -1,
      -1,    -1,    -1,    -1,    26,    -1,    -1,    55,    56,    57,
      -1,    59,    60,    61,    62,    63,    64,    -1,    13,    -1,
      -1,    -1,    44,    18,    46,    -1,    -1,    -1,    -1,    -1,
      -1,    26,    -1,    55,    56,    57,    -1,    59,    60,    61,
      62,    63,    64,    13,    -1,    -1,    -1,    -1,    -1,    44,
      -1,    46,    -1,    -1,    -1,    -1,    26,    -1,    -1,    -1,
      55,    56,    57,    -1,    59,    60,    61,    62,    63,    64,
      -1,    41,    -1,    -1,    44,    13,    46,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    56,    57,    26,    59,
      60,    61,    62,    63,    64,    33,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    -1,    46,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,
      -1,    59,    60,    61,    62,    63,    64,    44,    -1,    46,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,
      57,    -1,    59,    60,    61,    62,    63,    64
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    21,    69,     3,     0,    22,    51,    70,    72,    76,
      77,     3,    85,     3,    79,    53,    71,    74,    75,    76,
      77,    78,    20,    39,    73,   102,   103,    72,    72,    13,
      32,    13,    37,     3,    86,    87,    30,     5,     3,    23,
      43,    47,    49,    92,    94,    95,    96,    97,    99,   100,
     101,   108,    75,    75,    75,     3,   104,     3,   105,    27,
      48,    88,    89,    90,    73,    73,     4,    31,    54,    67,
       3,     4,    15,    19,    31,    45,    50,    52,    54,    58,
      67,    80,    81,    91,    92,   109,     9,    40,     7,    15,
      91,     3,    96,    91,    10,    14,    17,    19,     6,    15,
      74,    15,    74,    86,    86,     5,    90,     6,     6,     6,
       6,    15,    91,     3,    65,    66,    67,    83,    84,    91,
      17,     3,    82,    91,     6,     8,    13,    26,    44,    46,
      55,    56,    57,    59,    60,    61,    62,    63,    64,    93,
      87,     3,    67,    80,    83,    91,   110,    41,    42,    12,
      92,    91,    91,    94,    27,    28,    48,   106,   107,    29,
      86,    25,    85,    85,    85,    85,   110,    16,    81,     7,
      38,    79,    81,    91,    91,    91,    91,    91,    91,    91,
      91,     6,     6,     9,    16,    94,    91,    94,    18,    87,
      87,    87,    16,     6,    16,    91,    16,     8,    51,    86,
      86,   110,    34,    41,    11,    98,     7,     7,     7,     6,
     106,    25,    33,    81,     6,    94,    91,    36,    51,    51,
      51,    51,    18,    82,    35,    12,     6,    24,    94,     3,
      98
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
      

      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}




	



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


