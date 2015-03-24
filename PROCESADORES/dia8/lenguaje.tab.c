
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

/* Line 189 of yacc.c  */
#line 1 "lenguaje.y"

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



/* Line 189 of yacc.c  */
#line 111 "lenguaje.tab.c"

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



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 38 "lenguaje.y"

    struct expr campo_expr;
    char* campo_id;
    int campo_tipo;
    //ampliarrrrrrr



/* Line 214 of yacc.c  */
#line 223 "lenguaje.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 235 "lenguaje.tab.c"

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
#define YYLAST   371

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  68
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  92
/* YYNRULES -- Number of states.  */
#define YYNSTATES  198

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
      28,    31,    32,    35,    38,    41,    45,    49,    53,    54,
      60,    64,    73,    77,    80,    82,    84,    85,    91,    93,
      95,    97,    99,   101,   102,   108,   114,   120,   126,   127,
     131,   135,   138,   140,   143,   145,   148,   151,   155,   159,
     163,   167,   170,   174,   176,   178,   182,   186,   189,   191,
     193,   197,   199,   203,   205,   209,   214,   216,   218,   220,
     222,   224,   226,   230,   232,   234,   236,   238,   240,   242,
     246,   253,   254,   260,   262,   264,   270,   278,   285,   293,
     298,   303,   307
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      69,     0,    -1,    21,     3,    70,    71,    30,    -1,    72,
      73,    88,     5,    -1,    74,     5,    -1,    -1,    76,    72,
      -1,    77,    72,    -1,    -1,   102,    73,    -1,    75,    94,
      -1,    -1,    76,    75,    -1,    77,    75,    -1,    78,    75,
      -1,    51,    79,    37,    -1,    22,    85,    32,    -1,    53,
      86,    40,    -1,    -1,     3,    13,    80,     6,    79,    -1,
      52,    82,    38,    -1,    50,    17,    81,     8,    81,    18,
      24,    83,    -1,    81,     8,    81,    -1,    19,    83,    -1,
      91,    -1,    67,    -1,    -1,     3,     7,    51,     6,    82,
      -1,    84,    -1,     3,    -1,    65,    -1,    66,    -1,    67,
      -1,    -1,     3,    13,     4,     6,    85,    -1,     3,    13,
      67,     6,    85,    -1,     3,    13,    54,     6,    85,    -1,
       3,    13,    31,     6,    85,    -1,    -1,    87,     6,    86,
      -1,     3,     7,    83,    -1,     3,    87,    -1,    89,    -1,
      89,    90,    -1,    90,    -1,    27,    86,    -1,    48,    86,
      -1,    91,    56,    91,    -1,    91,    57,    91,    -1,    91,
      59,    91,    -1,    91,    26,    91,    -1,    58,    91,    -1,
      15,    91,    16,    -1,    92,    -1,     4,    -1,    91,    55,
      91,    -1,    91,    46,    91,    -1,    45,    91,    -1,    54,
      -1,    31,    -1,    91,    93,    91,    -1,   105,    -1,    91,
      44,    91,    -1,     3,    -1,    92,    10,    92,    -1,    92,
      17,    91,    18,    -1,    13,    -1,    60,    -1,    61,    -1,
      62,    -1,    63,    -1,    64,    -1,    95,     6,    94,    -1,
      95,    -1,    23,    -1,    96,    -1,    97,    -1,    99,    -1,
     104,    -1,    92,    14,    91,    -1,    49,    91,    12,    94,
      98,    36,    -1,    -1,    11,    91,    12,    94,    98,    -1,
     101,    -1,   100,    -1,    43,    91,    41,    94,    34,    -1,
      47,    96,    42,    91,    41,    94,    35,    -1,    39,   103,
      74,    25,    91,    33,    -1,     3,    15,    86,    16,    25,
      51,     6,    -1,     3,    15,   106,    16,    -1,     3,    15,
     106,    16,    -1,    91,     9,   106,    -1,    91,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   129,   129,   132,   135,   138,   139,   140,   143,   145,
     148,   151,   152,   153,   154,   158,   161,   164,   168,   169,
     172,   173,   174,   175,   178,   179,   182,   183,   186,   189,
     193,   196,   199,   205,   206,   207,   208,   209,   213,   214,
     220,   223,   228,   229,   230,   233,   236,   240,   249,   258,
     267,   276,   285,   289,   292,   295,   298,   301,   304,   307,
     310,   313,   316,   327,   328,   329,   332,   333,   334,   335,
     336,   337,   342,   343,   346,   347,   348,   349,   350,   353,
     356,   359,   360,   363,   364,   367,   372,   380,   386,   398,
     401,   404,   405
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
  "tipo_escalar", "lista_d_cte", "lista_d_var", "NLI", "decl_ent_sal",
  "decl_ent", "decl_salida", "exp", "operando", "oprel", "instrucciones",
  "instruccion", "asignacion", "alternativa", "lista_opciones",
  "iteracion", "it_cota_exp", "it_cota_fija", "funcion_d", "f_cabecera",
  "accion_ll", "funcion_ll", "l_ll", 0
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
      74,    75,    75,    75,    75,    76,    77,    78,    79,    79,
      80,    80,    80,    80,    81,    81,    82,    82,    83,    83,
      84,    84,    84,    85,    85,    85,    85,    85,    86,    86,
      87,    87,    88,    88,    88,    89,    90,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    92,    92,    92,    93,    93,    93,    93,
      93,    93,    94,    94,    95,    95,    95,    95,    95,    96,
      97,    98,    98,    99,    99,   100,   101,   102,   103,   104,
     105,   106,   106
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     4,     2,     0,     2,     2,     0,     2,
       2,     0,     2,     2,     2,     3,     3,     3,     0,     5,
       3,     8,     3,     2,     1,     1,     0,     5,     1,     1,
       1,     1,     1,     0,     5,     5,     5,     5,     0,     3,
       3,     2,     1,     2,     1,     2,     2,     3,     3,     3,
       3,     2,     3,     1,     1,     3,     3,     2,     1,     1,
       3,     1,     3,     1,     3,     4,     1,     1,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     3,
       6,     0,     5,     1,     1,     5,     7,     6,     7,     4,
       4,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     5,     1,    33,    18,    11,     8,     5,
       5,     0,     0,     0,     0,    38,     0,     0,     0,    11,
      11,    11,     0,     0,     8,     6,     7,     0,    16,     0,
      15,     0,     0,     0,     2,     4,    63,    74,     0,     0,
       0,     0,    10,    73,    75,    76,    77,    84,    83,    78,
      12,    13,    14,     0,    11,    38,    38,     0,    42,    44,
       9,     0,     0,     0,     0,    63,    54,     0,     0,    59,
       0,     0,    26,    58,     0,    25,     0,     0,    24,    53,
      61,     0,    41,    17,    38,     0,     0,    63,     0,     0,
       0,     0,     0,     0,    38,     0,    45,    46,     3,    43,
      33,    33,    33,    33,     0,     0,    29,    30,    31,    32,
      23,    28,    57,     0,     0,     0,    51,    18,     0,    66,
       0,     0,     0,     0,     0,     0,     0,    67,    68,    69,
      70,    71,     0,    40,    39,    92,     0,     0,     0,     0,
      64,    79,     0,    72,     0,     0,    34,    37,    36,    35,
       0,    52,     0,     0,    20,    19,    22,    50,    62,    56,
      55,    47,    48,    49,    60,     0,    89,     0,     0,    81,
      65,     0,     0,    90,     0,     0,    91,    85,     0,     0,
       0,     0,    87,     0,    26,     0,     0,    80,     0,     0,
      27,    86,     0,    88,     0,    81,    21,    82
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     7,    16,     8,    23,    17,    18,    19,    20,
      21,    14,    76,    77,   115,   110,   111,    12,    32,    33,
      57,    58,    59,    78,    79,   132,    42,    43,    44,    45,
     180,    46,    47,    48,    24,    54,    49,    80,   136
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -107
static const yytype_int16 yypact[] =
{
     -15,     1,    17,    -7,  -107,    25,    29,    76,   -19,    -7,
      -7,    30,    15,    32,    27,    63,    43,    75,    13,    76,
      76,    76,    79,     2,   -19,  -107,  -107,     4,  -107,     7,
    -107,    16,    56,    94,  -107,  -107,    95,  -107,   110,   102,
     110,    92,  -107,   101,  -107,  -107,  -107,  -107,  -107,  -107,
    -107,  -107,  -107,    97,    76,    63,    63,   117,    78,  -107,
    -107,   124,   126,   129,   133,   125,  -107,   110,    11,  -107,
     110,   106,   145,  -107,   110,  -107,   150,   151,   307,    24,
    -107,    11,  -107,  -107,    63,   110,   185,  -107,   116,   131,
     102,   110,   110,    13,    63,   136,  -107,  -107,  -107,  -107,
      25,    25,    25,    25,   110,   206,  -107,  -107,  -107,  -107,
    -107,  -107,   307,    66,   155,   138,  -107,    29,    66,  -107,
     110,   110,   110,   110,   110,   110,   110,  -107,  -107,  -107,
    -107,  -107,   110,  -107,  -107,    90,   162,    13,   110,    13,
      24,   307,   238,  -107,   164,   110,  -107,  -107,  -107,  -107,
     165,  -107,   159,   132,  -107,  -107,  -107,  -107,  -107,   -17,
     -17,   -13,   -13,  -107,   307,   110,  -107,   148,   262,   173,
    -107,   171,   283,  -107,    66,   179,  -107,  -107,    13,   110,
     166,   149,  -107,   183,   145,   154,   153,  -107,   197,   180,
    -107,  -107,    13,  -107,    11,   173,  -107,  -107
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -107,  -107,  -107,  -107,   108,   181,   167,   152,   128,   160,
    -107,    89,  -107,  -106,    23,   -79,  -107,    -9,   -31,   187,
    -107,  -107,   169,   -37,   -18,  -107,   -88,  -107,   184,  -107,
      33,  -107,  -107,  -107,  -107,  -107,  -107,  -107,   -86
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      41,    86,   133,    89,     3,   143,     1,   152,    61,   120,
      65,    66,   156,   120,   106,     5,    36,     4,   150,    31,
      22,    41,    67,    81,    96,    97,    68,   121,    11,    55,
     105,   121,    13,   112,    90,    62,    37,   116,    69,   124,
     125,    92,   126,    27,     6,    29,   126,    28,   135,   167,
      56,   169,    70,   134,   141,   142,    38,    71,    63,    72,
      39,    73,    40,   144,    30,    74,    31,   135,   183,    65,
      66,    64,   140,    34,    75,    41,   107,   108,   109,   176,
      35,    67,    53,   157,   158,   159,   160,   161,   162,   163,
     185,   146,   147,   148,   149,   164,    83,    69,     5,   165,
      84,   168,    90,   119,   195,    87,    91,    93,   172,    92,
      85,    70,    94,    65,    66,   196,   120,    25,    26,    41,
      73,    41,    98,   113,    74,    67,    56,     6,   135,    15,
     100,     9,   101,    75,   121,   102,   122,     9,     9,   103,
     104,    69,   186,   139,   119,   123,   124,   125,   114,   126,
     127,   128,   129,   130,   131,    70,   117,   120,   138,   118,
      41,   145,   153,    10,    73,   192,   119,   174,    74,    10,
      10,    50,    51,    52,    41,   121,   154,   122,   166,   120,
     171,   173,   177,   175,   179,   184,   123,   124,   125,   191,
     126,   127,   128,   129,   130,   131,   181,   121,   119,   122,
     188,   189,   187,   193,   194,    60,   155,   190,   123,   124,
     125,   120,   126,   127,   128,   129,   130,   131,    82,   119,
       0,    95,   151,    88,     0,     0,   137,    99,   197,   121,
       0,   122,   120,     0,     0,     0,     0,     0,     0,     0,
     123,   124,   125,     0,   126,   127,   128,   129,   130,   131,
     121,   119,   122,     0,     0,     0,   170,     0,     0,     0,
       0,   123,   124,   125,   120,   126,   127,   128,   129,   130,
     131,     0,     0,     0,     0,   119,     0,     0,     0,     0,
       0,     0,   121,     0,   122,     0,     0,     0,   120,     0,
       0,     0,     0,   123,   124,   125,   119,   126,   127,   128,
     129,   130,   131,   178,     0,     0,   121,     0,   122,   120,
       0,     0,     0,     0,     0,     0,   182,   123,   124,   125,
     119,   126,   127,   128,   129,   130,   131,   121,     0,   122,
       0,     0,     0,   120,     0,     0,     0,     0,   123,   124,
     125,     0,   126,   127,   128,   129,   130,   131,     0,     0,
       0,   121,     0,   122,     0,     0,     0,     0,     0,     0,
       0,     0,   123,   124,   125,     0,   126,   127,   128,   129,
     130,   131
};

static const yytype_int16 yycheck[] =
{
      18,    38,    81,    40,     3,    93,    21,   113,     4,    26,
       3,     4,   118,    26,     3,    22,     3,     0,   104,     3,
      39,    39,    15,     7,    55,    56,    19,    44,     3,    27,
      67,    44,     3,    70,    10,    31,    23,    74,    31,    56,
      57,    17,    59,    13,    51,    13,    59,    32,    85,   137,
      48,   139,    45,    84,    91,    92,    43,    50,    54,    52,
      47,    54,    49,    94,    37,    58,     3,   104,   174,     3,
       4,    67,    90,    30,    67,    93,    65,    66,    67,   165,
       5,    15,     3,   120,   121,   122,   123,   124,   125,   126,
     178,   100,   101,   102,   103,   132,    40,    31,    22,     9,
       6,   138,    10,    13,   192,     3,    14,     6,   145,    17,
      15,    45,    15,     3,     4,   194,    26,     9,    10,   137,
      54,   139,     5,    17,    58,    15,    48,    51,   165,    53,
       6,     3,     6,    67,    44,     6,    46,     9,    10,     6,
      15,    31,   179,    12,    13,    55,    56,    57,     3,    59,
      60,    61,    62,    63,    64,    45,     6,    26,    42,     8,
     178,    25,     7,     3,    54,    12,    13,     8,    58,     9,
      10,    19,    20,    21,   192,    44,    38,    46,    16,    26,
      16,    16,    34,    51,    11,     6,    55,    56,    57,    35,
      59,    60,    61,    62,    63,    64,    25,    44,    13,    46,
      51,    18,    36,     6,    24,    24,   117,   184,    55,    56,
      57,    26,    59,    60,    61,    62,    63,    64,    31,    13,
      -1,    54,    16,    39,    -1,    -1,    41,    58,   195,    44,
      -1,    46,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    56,    57,    -1,    59,    60,    61,    62,    63,    64,
      44,    13,    46,    -1,    -1,    -1,    18,    -1,    -1,    -1,
      -1,    55,    56,    57,    26,    59,    60,    61,    62,    63,
      64,    -1,    -1,    -1,    -1,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    44,    -1,    46,    -1,    -1,    -1,    26,    -1,
      -1,    -1,    -1,    55,    56,    57,    13,    59,    60,    61,
      62,    63,    64,    41,    -1,    -1,    44,    -1,    46,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    55,    56,    57,
      13,    59,    60,    61,    62,    63,    64,    44,    -1,    46,
      -1,    -1,    -1,    26,    -1,    -1,    -1,    -1,    55,    56,
      57,    -1,    59,    60,    61,    62,    63,    64,    -1,    -1,
      -1,    44,    -1,    46,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    56,    57,    -1,    59,    60,    61,    62,
      63,    64
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    21,    69,     3,     0,    22,    51,    70,    72,    76,
      77,     3,    85,     3,    79,    53,    71,    74,    75,    76,
      77,    78,    39,    73,   102,    72,    72,    13,    32,    13,
      37,     3,    86,    87,    30,     5,     3,    23,    43,    47,
      49,    92,    94,    95,    96,    97,    99,   100,   101,   104,
      75,    75,    75,     3,   103,    27,    48,    88,    89,    90,
      73,     4,    31,    54,    67,     3,     4,    15,    19,    31,
      45,    50,    52,    54,    58,    67,    80,    81,    91,    92,
     105,     7,    87,    40,     6,    15,    91,     3,    96,    91,
      10,    14,    17,     6,    15,    74,    86,    86,     5,    90,
       6,     6,     6,     6,    15,    91,     3,    65,    66,    67,
      83,    84,    91,    17,     3,    82,    91,     6,     8,    13,
      26,    44,    46,    55,    56,    57,    59,    60,    61,    62,
      63,    64,    93,    83,    86,    91,   106,    41,    42,    12,
      92,    91,    91,    94,    86,    25,    85,    85,    85,    85,
     106,    16,    81,     7,    38,    79,    81,    91,    91,    91,
      91,    91,    91,    91,    91,     9,    16,    94,    91,    94,
      18,    16,    91,    16,     8,    51,   106,    34,    41,    11,
      98,    25,    33,    81,     6,    94,    91,    36,    51,    18,
      82,    35,    12,     6,    24,    94,    83,    98
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
        case 2:

/* Line 1455 of yacc.c  */
#line 129 "lenguaje.y"
    {;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 132 "lenguaje.y"
    {;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 135 "lenguaje.y"
    {;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 139 "lenguaje.y"
    {;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 140 "lenguaje.y"
    {;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 145 "lenguaje.y"
    {;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 148 "lenguaje.y"
    {;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 152 "lenguaje.y"
    {;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 153 "lenguaje.y"
    {;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 154 "lenguaje.y"
    {;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 158 "lenguaje.y"
    {;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 161 "lenguaje.y"
    {;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 164 "lenguaje.y"
    {;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 168 "lenguaje.y"
    {;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 169 "lenguaje.y"
    {;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 172 "lenguaje.y"
    {;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 173 "lenguaje.y"
    {;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 174 "lenguaje.y"
    {;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 175 "lenguaje.y"
    {;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 178 "lenguaje.y"
    {;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 179 "lenguaje.y"
    {;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 182 "lenguaje.y"
    {;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 183 "lenguaje.y"
    {;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 186 "lenguaje.y"
    {
			     
			     ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 189 "lenguaje.y"
    {;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 193 "lenguaje.y"
    {
				  (yyval.campo_tipo) = ENTERO;
			   ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 196 "lenguaje.y"
    {
				  (yyval.campo_tipo) = BOOLEANO;
			       ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 199 "lenguaje.y"
    {
				  (yyval.campo_tipo) = CARACTER;
			       ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 205 "lenguaje.y"
    {;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 206 "lenguaje.y"
    {;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 207 "lenguaje.y"
    {;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 208 "lenguaje.y"
    {;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 209 "lenguaje.y"
    {;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 213 "lenguaje.y"
    {;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 214 "lenguaje.y"
    {
						      
						   ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 220 "lenguaje.y"
    {

					   ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 223 "lenguaje.y"
    {
  
			     ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 228 "lenguaje.y"
    {;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 229 "lenguaje.y"
    {;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 230 "lenguaje.y"
    {;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 233 "lenguaje.y"
    {;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 236 "lenguaje.y"
    {;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 240 "lenguaje.y"
    {
				      nodo *T = newtemp(&t,cont);
				      (yyval.campo_expr).place = T;
				      modificarTipo(&t,ENTERO,cont);
				      cont++;
				      int cuadrupla[4] = {SUMA,(yyvsp[(1) - (3)].campo_expr).place,(yyvsp[(3) - (3)].campo_expr).place,T};
				      gen(&c,cuadrupla);
				      (yyval.campo_expr).tipo = ENTERO;
				;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 249 "lenguaje.y"
    {
				      nodo *T = newtemp(&t,cont);
				      (yyval.campo_expr).place = T;
				      modificarTipo(&t,ENTERO,cont);
				      cont++;
				      int cuadrupla[4] = {RESTA,(yyvsp[(1) - (3)].campo_expr).place,(yyvsp[(3) - (3)].campo_expr).place,T};
				      gen(&c,cuadrupla);
				      (yyval.campo_expr).tipo = ENTERO;
				    ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 258 "lenguaje.y"
    {
				      nodo *T = newtemp(&t,cont);
				      (yyval.campo_expr).place = T;
				      modificarTipo(&t,ENTERO,cont);
				      cont++;
				      int cuadrupla[4] = {MULTI,(yyvsp[(1) - (3)].campo_expr).place,(yyvsp[(3) - (3)].campo_expr).place,T};
				      gen(&c,cuadrupla);
				      (yyval.campo_expr).tipo = ENTERO;
				  ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 267 "lenguaje.y"
    {
				      nodo *T = newtemp(&t,cont);
				      (yyval.campo_expr).place = T;
				      modificarTipo(&t,ENTERO,cont);
				      cont++;
				      int cuadrupla[4] = {DIVI,(yyvsp[(1) - (3)].campo_expr).place,(yyvsp[(3) - (3)].campo_expr).place,T};
				      gen(&c,cuadrupla);
				      (yyval.campo_expr).tipo = ENTERO;		      
				  ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 276 "lenguaje.y"
    {
				      nodo *T = newtemp(&t,cont);
				      (yyval.campo_expr).place = T;
				      modificarTipo(&t,ENTERO,cont);
				      cont++;
				      int cuadrupla[4] = {MENOS_UNARIO,(yyvsp[(2) - (2)].campo_expr).place,NULL,T};
				      gen(&c,cuadrupla);
				      (yyval.campo_expr).tipo = ENTERO;					
				       ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 285 "lenguaje.y"
    {
				      (yyval.campo_expr).place = (yyvsp[(2) - (3)].campo_expr).place;
				      (yyval.campo_expr).tipo = (yyvsp[(2) - (3)].campo_expr).place;
					  ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 289 "lenguaje.y"
    {

			   ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 292 "lenguaje.y"
    {

				       ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 295 "lenguaje.y"
    {

				 ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 298 "lenguaje.y"
    {

				 ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 301 "lenguaje.y"
    {

			     ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 304 "lenguaje.y"
    {

				;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 307 "lenguaje.y"
    {

			    ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 310 "lenguaje.y"
    {

				;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 313 "lenguaje.y"
    {

			     ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 316 "lenguaje.y"
    {
				      nodo *T = newtemp(&t,cont);
				      (yyval.campo_expr).place = T;
				      modificarTipo(&t,ENTERO,cont);
				      cont++;
				      int cuadrupla[4] = {MOD,(yyvsp[(1) - (3)].campo_expr).place,(yyvsp[(3) - (3)].campo_expr).place,T};
				      gen(&c,cuadrupla);
				      (yyval.campo_expr).tipo = ENTERO;      
				  ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 327 "lenguaje.y"
    {;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 328 "lenguaje.y"
    {;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 329 "lenguaje.y"
    {;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 332 "lenguaje.y"
    {;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 333 "lenguaje.y"
    {;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 334 "lenguaje.y"
    {;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 335 "lenguaje.y"
    {;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 336 "lenguaje.y"
    {;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 337 "lenguaje.y"
    {;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 342 "lenguaje.y"
    {;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 343 "lenguaje.y"
    {;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 346 "lenguaje.y"
    {;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 347 "lenguaje.y"
    {;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 348 "lenguaje.y"
    {;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 349 "lenguaje.y"
    {;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 350 "lenguaje.y"
    {;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 353 "lenguaje.y"
    {;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 356 "lenguaje.y"
    {;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 359 "lenguaje.y"
    {;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 360 "lenguaje.y"
    {;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 363 "lenguaje.y"
    {;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 364 "lenguaje.y"
    {;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 367 "lenguaje.y"
    {

								       ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 372 "lenguaje.y"
    {;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 380 "lenguaje.y"
    {;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 386 "lenguaje.y"
    {;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 398 "lenguaje.y"
    {;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 401 "lenguaje.y"
    {;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 404 "lenguaje.y"
    {;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 405 "lenguaje.y"
    {;}
    break;



/* Line 1455 of yacc.c  */
#line 2350 "lenguaje.tab.c"
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



/* Line 1675 of yacc.c  */
#line 408 "lenguaje.y"

	



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


