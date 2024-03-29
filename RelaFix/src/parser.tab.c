/* A Bison parser, made by GNU Bison 2.4.2.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2006, 2009-2010 Free Software
   Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 1



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 16 "parser.y"

	#include "array.h"
	#include "domain.h"
	#include "relation.h"
	#include "operation.h"
	#include "function.h"
	#include "negation.h"
	#include "table.h"
	#include "list.h"
	#include "formula.h"
	#include "parse.h"
	#include "tools.h"
	#include <stdio.h>
	#include <stdlib.h>
	int yylex(void);
	void yyerror(char const *);


/* Line 189 of yacc.c  */
#line 91 "parser.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
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
     END = 0,
     T_DOMAIN = 258,
     T_RELATION = 259,
     T_OPERATION = 260,
     T_ARROW_R = 261,
     T_TABLE = 262,
     T_AS = 263,
     T_LOAD = 264,
     T_NEGATION = 265,
     T_FORMULA = 266,
     T_PATH = 267,
     T_LIST = 268,
     T_DELETE = 269,
     T_DOMAINS = 270,
     T_RELATIONS = 271,
     T_OPERATIONS = 272,
     T_NEGATIONS = 273,
     T_FUNCTIONS = 274,
     ID = 275,
     STRING = 276,
     FILENAME = 277
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 42 "parser.y"

	RF_DOMAIN				*domain;
	RF_RELATION				*relation;
	RF_OPERATION			*operation;
	RF_FORMULA				*formula;
	char					*id;
	RF_TABLE				*table;
	RF_PARSER_TABLE_DATA	*table_data;
	RF_LIST					*list;
	RF_ARRAY				*array;



/* Line 214 of yacc.c  */
#line 164 "parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 189 "parser.tab.c"

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
# if defined YYENABLE_NLS && YYENABLE_NLS
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
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   124

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  63
/* YYNRULES -- Number of states.  */
#define YYNSTATES  131

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   277

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      24,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      31,    32,     2,     2,    23,     2,     2,    28,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    26,    25,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    33,    34,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      27,     2,     2,    29,     2,    30,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     4,     7,     9,    11,    13,    15,    17,
      19,    21,    22,    23,    29,    30,    31,    37,    39,    45,
      55,    57,    59,    61,    62,    63,    77,    79,    81,    83,
      91,    95,    99,   103,   107,   111,   115,   119,   123,   126,
     129,   133,   139,   144,   146,   149,   151,   155,   162,   164,
     167,   171,   177,   178,   182,   184,   188,   190,   192,   194,
     196,   200,   205,   207
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      36,     0,    -1,    -1,    36,    37,    -1,    24,    -1,    42,
      -1,    43,    -1,    45,    -1,    49,    -1,    50,    -1,    51,
      -1,    -1,    -1,    12,    38,    22,    39,    25,    -1,    -1,
      -1,     9,    40,    22,    41,    25,    -1,    53,    -1,     3,
      20,     8,    62,    25,    -1,     4,    20,    26,    20,     6,
      20,     8,    44,    25,    -1,    57,    -1,    60,    -1,    62,
      -1,    -1,    -1,     5,    20,    26,    20,    46,    27,    47,
      20,     6,    20,     8,    48,    25,    -1,    57,    -1,    60,
      -1,    62,    -1,    10,    20,    26,    20,     8,    52,    25,
      -1,    13,    15,    25,    -1,    13,    16,    25,    -1,    13,
      17,    25,    -1,    13,    18,    25,    -1,    13,    19,    25,
      -1,    14,    20,    25,    -1,    20,    28,    20,    -1,    52,
      23,    52,    -1,    62,    25,    -1,    21,    25,    -1,    29,
      56,    30,    -1,    20,    26,    29,    56,    30,    -1,    20,
      26,    29,    30,    -1,    20,    -1,    26,    20,    -1,    55,
      -1,    56,    23,    56,    -1,     7,    31,    58,    23,    59,
      32,    -1,    20,    -1,    58,    20,    -1,    20,    26,    58,
      -1,    20,    26,    58,    23,    59,    -1,    -1,    11,    61,
      62,    -1,    63,    -1,    63,    20,    63,    -1,    20,    -1,
      33,    -1,    34,    -1,    54,    -1,    31,    62,    32,    -1,
      20,    31,    64,    32,    -1,    62,    -1,    64,    23,    64,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    93,    93,    94,   101,   102,   103,   104,   105,   106,
     107,   108,   108,   108,   111,   111,   111,   120,   123,   206,
     332,   333,   334,   397,   397,   397,   540,   541,   542,   605,
     696,   697,   698,   699,   700,   703,   741,   759,   779,   846,
     858,   883,   920,   934,   941,   962,   974,   995,  1005,  1010,
    1016,  1026,  1041,  1041,  1050,  1051,  1105,  1111,  1125,  1139,
    1154,  1155,  1223,  1236
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "$undefined", "\"DOMAIN\"", "\"RELATION\"",
  "\"OPERATION\"", "\"->\"", "\"TABLE\"", "\"AS\"", "\"LOAD\"",
  "\"NEGATION\"", "\"FORMULA\"", "\"PATH\"", "\"LIST\"", "\"DELETE\"",
  "\"DOMAINS\"", "\"RELATIONS\"", "\"OPERATIONS\"", "\"NEGATIONS\"",
  "\"FUNCTIONS\"", "ID", "STRING", "FILENAME", "','", "'\\n'", "';'",
  "':'", "'x'", "'/'", "'{'", "'}'", "'('", "')'", "'X'", "'Y'", "$accept",
  "input", "statement", "$@1", "$@2", "$@3", "$@4", "domaindef",
  "relationdef", "relationdefx", "operationdef", "$@5", "$@6",
  "operationdefx", "negationdef", "list", "delete", "neglist", "show",
  "free_domain", "domain", "domainx", "table", "tablea", "tableb",
  "formula", "$@7", "fexpr", "fexprx", "farguments", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,    44,    10,    59,    58,   120,    47,   123,
     125,    40,    41,    88,    89
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    35,    36,    36,    37,    37,    37,    37,    37,    37,
      37,    38,    39,    37,    40,    41,    37,    37,    42,    43,
      44,    44,    44,    46,    47,    45,    48,    48,    48,    49,
      50,    50,    50,    50,    50,    51,    52,    52,    53,    53,
      54,    55,    55,    56,    56,    56,    56,    57,    58,    58,
      59,    59,    61,    60,    62,    62,    63,    63,    63,    63,
      63,    63,    64,    64
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     0,     0,     5,     0,     0,     5,     1,     5,     9,
       1,     1,     1,     0,     0,    13,     1,     1,     1,     7,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       3,     5,     4,     1,     2,     1,     3,     6,     1,     2,
       3,     5,     0,     3,     1,     3,     1,     1,     1,     1,
       3,     4,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     0,     0,     0,    14,     0,    11,     0,
       0,    56,     0,     4,     0,     0,    57,    58,     3,     5,
       6,     7,     8,     9,    10,    17,    59,     0,    54,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    39,    43,     0,    45,     0,     0,    38,     0,
       0,     0,     0,    15,     0,    12,    30,    31,    32,    33,
      34,    35,    62,     0,     0,    44,     0,    40,    60,    55,
       0,     0,    23,     0,     0,     0,     0,    61,     0,    46,
      18,     0,     0,    16,     0,    13,    63,    42,     0,     0,
      24,     0,     0,    41,     0,     0,     0,     0,    29,     0,
      52,     0,    20,    21,    22,     0,    36,    37,     0,     0,
      19,     0,    48,     0,    53,     0,    49,     0,     0,     0,
       0,     0,    26,    27,    28,     0,    47,    25,    50,     0,
      51
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,    18,    34,    75,    32,    73,    19,    20,   101,
      21,    82,    95,   121,    22,    23,    24,    92,    25,    26,
      45,    46,   102,   113,   120,   103,   109,    62,    28,    63
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -58
static const yytype_int8 yypact[] =
{
     -58,     3,   -58,     9,    13,    18,   -58,    31,   -58,    39,
      40,   -12,    37,   -58,    21,    19,   -58,   -58,   -58,   -58,
     -58,   -58,   -58,   -58,   -58,   -58,   -58,    38,    44,    17,
      41,    42,    43,    45,    47,    48,    49,    50,    51,    52,
      53,    19,   -58,    46,    59,   -58,   -19,    34,   -58,    19,
      19,    60,    61,   -58,    62,   -58,   -58,   -58,   -58,   -58,
     -58,   -58,   -58,   -22,    54,   -58,    21,   -58,   -58,   -58,
      63,    64,   -58,    65,    76,    66,    19,   -58,     0,   -58,
     -58,    67,    58,   -58,    69,   -58,   -58,   -58,     5,    78,
     -58,    68,    36,   -58,    11,    72,    74,    69,   -58,    70,
     -58,    73,   -58,   -58,   -58,    89,   -58,   -58,    77,    19,
     -58,    79,   -58,   -18,   -58,    92,   -58,    82,    11,    80,
      71,    84,   -58,   -58,   -58,    77,   -58,   -58,    23,    82,
     -58
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,
     -58,   -58,   -58,   -58,   -58,   -58,   -58,     7,   -58,   -58,
     -58,   -57,   -13,   -15,   -17,   -11,   -58,    -1,    75,    35
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      27,    76,   116,     2,    66,   117,     3,     4,     5,    79,
      77,    67,     6,     7,    47,     8,     9,    10,    99,    41,
      43,    88,   100,    11,    12,    50,    44,    13,    66,    29,
      87,    11,    14,    30,    15,    93,    16,    17,    31,    11,
      14,    43,    15,   116,    16,    17,   129,    44,    14,    70,
      15,    33,    16,    17,    35,    36,    37,    38,    39,    97,
      40,    98,    42,    48,    49,    53,    68,    51,    52,    55,
      81,    54,    64,    56,    57,    58,    59,    60,    61,    65,
      71,    72,    74,    78,    84,    90,    94,    89,    80,    91,
      83,    85,   105,   104,   106,   111,    96,   112,   110,   115,
     118,   108,   119,   126,   107,   122,   125,   123,   114,   127,
     128,    86,   130,     0,     0,     0,     0,   124,     0,     0,
       0,     0,     0,     0,    69
};

static const yytype_int16 yycheck[] =
{
       1,    23,    20,     0,    23,    23,     3,     4,     5,    66,
      32,    30,     9,    10,    15,    12,    13,    14,     7,    31,
      20,    78,    11,    20,    21,     8,    26,    24,    23,    20,
      30,    20,    29,    20,    31,    30,    33,    34,    20,    20,
      29,    20,    31,    20,    33,    34,    23,    26,    29,    50,
      31,    20,    33,    34,    15,    16,    17,    18,    19,    23,
      20,    25,    25,    25,    20,    22,    32,    26,    26,    22,
       6,    26,    26,    25,    25,    25,    25,    25,    25,    20,
      20,    20,    20,    29,     8,    27,     8,    20,    25,    20,
      25,    25,    20,    94,    20,     6,    28,    20,    25,    20,
       8,    31,    20,    32,    97,   118,    26,   118,   109,    25,
     125,    76,   129,    -1,    -1,    -1,    -1,   118,    -1,    -1,
      -1,    -1,    -1,    -1,    49
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    36,     0,     3,     4,     5,     9,    10,    12,    13,
      14,    20,    21,    24,    29,    31,    33,    34,    37,    42,
      43,    45,    49,    50,    51,    53,    54,    62,    63,    20,
      20,    20,    40,    20,    38,    15,    16,    17,    18,    19,
      20,    31,    25,    20,    26,    55,    56,    62,    25,    20,
       8,    26,    26,    22,    26,    22,    25,    25,    25,    25,
      25,    25,    62,    64,    26,    20,    23,    30,    32,    63,
      62,    20,    20,    41,    20,    39,    23,    32,    29,    56,
      25,     6,    46,    25,     8,    25,    64,    30,    56,    20,
      27,    20,    52,    30,     8,    47,    28,    23,    25,     7,
      11,    44,    57,    60,    62,    20,    20,    52,    31,    61,
      25,     6,    20,    58,    62,    20,    20,    23,     8,    20,
      59,    48,    57,    60,    62,    26,    32,    25,    58,    23,
      59
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

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
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
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
		  Type, Value, Location); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
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
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {
      case 20: /* "ID" */

/* Line 1009 of yacc.c  */
#line 80 "parser.y"
	{if((yyvaluep->id)) free((yyvaluep->id));};

/* Line 1009 of yacc.c  */
#line 1215 "parser.tab.c"
	break;
      case 21: /* "STRING" */

/* Line 1009 of yacc.c  */
#line 80 "parser.y"
	{if((yyvaluep->id)) free((yyvaluep->id));};

/* Line 1009 of yacc.c  */
#line 1224 "parser.tab.c"
	break;
      case 22: /* "FILENAME" */

/* Line 1009 of yacc.c  */
#line 80 "parser.y"
	{if((yyvaluep->id)) free((yyvaluep->id));};

/* Line 1009 of yacc.c  */
#line 1233 "parser.tab.c"
	break;
      case 44: /* "relationdefx" */

/* Line 1009 of yacc.c  */
#line 87 "parser.y"
	{if((yyvaluep->table_data)) rf_parser_destroy_table_data((yyvaluep->table_data));};

/* Line 1009 of yacc.c  */
#line 1242 "parser.tab.c"
	break;
      case 48: /* "operationdefx" */

/* Line 1009 of yacc.c  */
#line 87 "parser.y"
	{if((yyvaluep->table_data)) rf_parser_destroy_table_data((yyvaluep->table_data));};

/* Line 1009 of yacc.c  */
#line 1251 "parser.tab.c"
	break;
      case 52: /* "neglist" */

/* Line 1009 of yacc.c  */
#line 83 "parser.y"
	{if((yyvaluep->list)) rf_list_destroy((yyvaluep->list), free);};

/* Line 1009 of yacc.c  */
#line 1260 "parser.tab.c"
	break;
      case 54: /* "free_domain" */

/* Line 1009 of yacc.c  */
#line 81 "parser.y"
	{if((yyvaluep->domain)) rf_domain_destroy((yyvaluep->domain));};

/* Line 1009 of yacc.c  */
#line 1269 "parser.tab.c"
	break;
      case 55: /* "domain" */

/* Line 1009 of yacc.c  */
#line 81 "parser.y"
	{if((yyvaluep->domain)) rf_domain_destroy((yyvaluep->domain));};

/* Line 1009 of yacc.c  */
#line 1278 "parser.tab.c"
	break;
      case 56: /* "domainx" */

/* Line 1009 of yacc.c  */
#line 82 "parser.y"
	{if((yyvaluep->list)) rf_list_destroy((yyvaluep->list), (void (*)(void *))rf_element_destroy);};

/* Line 1009 of yacc.c  */
#line 1287 "parser.tab.c"
	break;
      case 57: /* "table" */

/* Line 1009 of yacc.c  */
#line 87 "parser.y"
	{if((yyvaluep->table_data)) rf_parser_destroy_table_data((yyvaluep->table_data));};

/* Line 1009 of yacc.c  */
#line 1296 "parser.tab.c"
	break;
      case 58: /* "tablea" */

/* Line 1009 of yacc.c  */
#line 83 "parser.y"
	{if((yyvaluep->list)) rf_list_destroy((yyvaluep->list), free);};

/* Line 1009 of yacc.c  */
#line 1305 "parser.tab.c"
	break;
      case 59: /* "tableb" */

/* Line 1009 of yacc.c  */
#line 84 "parser.y"
	{if((yyvaluep->list)) rf_list_destroy((yyvaluep->list), (void (*)(void *))rf_parser_destroy_table_row);};

/* Line 1009 of yacc.c  */
#line 1314 "parser.tab.c"
	break;
      case 60: /* "formula" */

/* Line 1009 of yacc.c  */
#line 87 "parser.y"
	{if((yyvaluep->table_data)) rf_parser_destroy_table_data((yyvaluep->table_data));};

/* Line 1009 of yacc.c  */
#line 1323 "parser.tab.c"
	break;
      case 62: /* "fexpr" */

/* Line 1009 of yacc.c  */
#line 86 "parser.y"
	{if((yyvaluep->formula)) rf_formula_destroy((yyvaluep->formula));};

/* Line 1009 of yacc.c  */
#line 1332 "parser.tab.c"
	break;
      case 63: /* "fexprx" */

/* Line 1009 of yacc.c  */
#line 86 "parser.y"
	{if((yyvaluep->formula)) rf_formula_destroy((yyvaluep->formula));};

/* Line 1009 of yacc.c  */
#line 1341 "parser.tab.c"
	break;
      case 64: /* "farguments" */

/* Line 1009 of yacc.c  */
#line 85 "parser.y"
	{if((yyvaluep->array)) rf_array_destroy((yyvaluep->array), (void (*)(void *))rf_formula_destroy);};

/* Line 1009 of yacc.c  */
#line 1350 "parser.tab.c"
	break;

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

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc;

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
       `yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[2];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yyls = yylsa;
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
  yylsp = yyls;

#if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 1;
#endif

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
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);

	yyls = yyls1;
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
	YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 3:

/* Line 1464 of yacc.c  */
#line 94 "parser.y"
    {
								rf_parser_record = RF_TRUE;
								rf_parser_record_clear();
								rf_parser_with_variable = RF_FALSE;
							;}
    break;

  case 11:

/* Line 1464 of yacc.c  */
#line 108 "parser.y"
    {rf_lexer_mode = RF_LEXER_FILE;;}
    break;

  case 12:

/* Line 1464 of yacc.c  */
#line 108 "parser.y"
    {rf_lexer_mode = RF_LEXER_NORMAL;;}
    break;

  case 13:

/* Line 1464 of yacc.c  */
#line 108 "parser.y"
    {
																											rf_parser_set_path((yyvsp[(3) - (5)].id));
																										;}
    break;

  case 14:

/* Line 1464 of yacc.c  */
#line 111 "parser.y"
    {rf_lexer_mode = RF_LEXER_FILE;;}
    break;

  case 15:

/* Line 1464 of yacc.c  */
#line 111 "parser.y"
    {rf_lexer_mode = RF_LEXER_NORMAL;;}
    break;

  case 16:

/* Line 1464 of yacc.c  */
#line 111 "parser.y"
    {
																											if(rf_lexer_need_load_file(rf_string_copy((yyvsp[(3) - (5)].id)), (RF_LOCATION *)&yylloc) != 0)
																											{
																												if(rf_lexer_need_load_file(rf_string_combine(2, rf_parser_get_path(), (yyvsp[(3) - (5)].id)), (RF_LOCATION *)&yylloc) != 0)
																													rf_parser_error((yylsp[(3) - (5)]).last_line, (yylsp[(3) - (5)]).last_column, "Can not find file '", 2, (yyvsp[(3) - (5)].id), "'");
																											}
																											
																											free((yyvsp[(3) - (5)].id));
																										;}
    break;

  case 17:

/* Line 1464 of yacc.c  */
#line 120 "parser.y"
    {rf_parser_record = RF_FALSE;;}
    break;

  case 18:

/* Line 1464 of yacc.c  */
#line 123 "parser.y"
    {
													if(!(yyvsp[(4) - (5)].formula))
													{
														rf_parser_error((yylsp[(4) - (5)]).first_line, (yylsp[(4) - (5)]).first_column, "no expression", 0);
														
														if((yyvsp[(2) - (5)].id))
															free((yyvsp[(2) - (5)].id));
													}
													else if(rf_parser_get_domain((yyvsp[(2) - (5)].id)))
													{
														rf_parser_error((yylsp[(2) - (5)]).first_line, (yylsp[(2) - (5)]).first_column, "found DOMAIN '", 2, (yyvsp[(2) - (5)].id), "' , expected free ID");
														rf_formula_destroy((yyvsp[(4) - (5)].formula));
														free((yyvsp[(2) - (5)].id));
													}
													else if(rf_parser_get_relation((yyvsp[(2) - (5)].id)))
													{
														rf_parser_error((yylsp[(2) - (5)]).first_line, (yylsp[(2) - (5)]).first_column, "found RELATION '", 2, (yyvsp[(2) - (5)].id), "' , expected free ID");
														rf_formula_destroy((yyvsp[(4) - (5)].formula));
														free((yyvsp[(2) - (5)].id));
													}
													else if(rf_parser_get_operation((yyvsp[(2) - (5)].id)))
													{
														rf_parser_error((yylsp[(2) - (5)]).first_line, (yylsp[(2) - (5)]).first_column, "found OPERATION '", 2, (yyvsp[(2) - (5)].id), "' , expected free ID");
														rf_formula_destroy((yyvsp[(4) - (5)].formula));
														free((yyvsp[(2) - (5)].id));
													}
													else if(rf_parser_get_negation((yyvsp[(2) - (5)].id)))
													{
														rf_parser_error((yylsp[(2) - (5)]).first_line, (yylsp[(2) - (5)]).first_column, "found NEGATION '", 2, (yyvsp[(2) - (5)].id), "' , expected free ID");
														rf_formula_destroy((yyvsp[(4) - (5)].formula));
														free((yyvsp[(2) - (5)].id));
													}
													else if(rf_parser_get_function((yyvsp[(2) - (5)].id)))
													{
														rf_parser_error((yylsp[(2) - (5)]).first_line, (yylsp[(2) - (5)]).first_column, "found FUNCTION '", 2, (yyvsp[(2) - (5)].id), "' , expected free ID");
														rf_formula_destroy((yyvsp[(4) - (5)].formula));
														free((yyvsp[(2) - (5)].id));
													}
													else
													{
														RF_FORMULA_RESULT *result = 0;
														if(rf_formula_calc((yyvsp[(4) - (5)].formula), 0, 0, &result) != 0)
														{
															rf_parser_error((yylsp[(4) - (5)]).first_line, (yylsp[(4) - (5)]).first_column, result->error, 0);
															free((yyvsp[(2) - (5)].id));
														}
														else
														{
															if(result->type == RF_FO_ID || result->type == RF_FO_ELEMENT)
															{
																RF_DOMAIN *domain = rf_parser_get_domain(result->element);
														
																if(!domain)
																{
																	rf_parser_error((yylsp[(4) - (5)]).first_line, (yylsp[(4) - (5)]).first_column, "'", 2, result->element, "' is not a DOMAIN.");
																	free((yyvsp[(2) - (5)].id));
																}
																else
																{
																	domain = rf_domain_copy(domain);
																	rf_domain_set_name(domain, (yyvsp[(2) - (5)].id));
																	rf_parser_add_domain(domain);
																}
															}
															else if(result->type == RF_FO_DOMAIN)
															{
																RF_DOMAIN *domain = rf_domain_copy(result->domain);
																rf_domain_set_name(domain, (yyvsp[(2) - (5)].id));
																rf_parser_add_domain(domain);
															}
															else
															{
																rf_parser_error((yylsp[(4) - (5)]).first_line, (yylsp[(4) - (5)]).first_column, "The result of the expression is not a DOMAIN", 0);
																free((yyvsp[(2) - (5)].id));
															}
														}
														
														rf_formula_destroy_result(result);
														rf_formula_destroy((yyvsp[(4) - (5)].formula));
													}
												;}
    break;

  case 19:

/* Line 1464 of yacc.c  */
#line 206 "parser.y"
    {
																		RF_DOMAIN *domain_1, *domain_2;
																		RF_RELATION *relation;
																		
																		if(!(yyvsp[(8) - (9)].table_data));
																		else if(rf_parser_get_relation((yyvsp[(2) - (9)].id)))
																		{
																			rf_parser_error((yylsp[(2) - (9)]).first_line, (yylsp[(2) - (9)]).first_column, "found RELATION '", 2, (yyvsp[(2) - (9)].id), "' , expected free ID");
																			free((yyvsp[(2) - (9)].id));
																		}
																		else if(rf_parser_get_domain((yyvsp[(2) - (9)].id)))
																		{
																			rf_parser_error((yylsp[(2) - (9)]).first_line, (yylsp[(2) - (9)]).first_column, "found DOMAIN '", 2, (yyvsp[(2) - (9)].id), "' , expected free ID");
																			free((yyvsp[(2) - (9)].id));
																		}
																		else if(rf_parser_get_operation((yyvsp[(2) - (9)].id)))
																		{
																			rf_parser_error((yylsp[(2) - (9)]).first_line, (yylsp[(2) - (9)]).first_column, "found OPERATION '", 2, (yyvsp[(2) - (9)].id), "' , expected free ID");
																			free((yyvsp[(2) - (9)].id));
																		}
																		else if(rf_parser_get_negation((yyvsp[(2) - (9)].id)))
																		{
																			rf_parser_error((yylsp[(2) - (9)]).first_line, (yylsp[(2) - (9)]).first_column, "found NEGATION '", 2, (yyvsp[(2) - (9)].id), "' , expected free ID");
																			free((yyvsp[(2) - (9)].id));
																		}
																		else if(rf_parser_get_function((yyvsp[(2) - (9)].id)))
																		{
																			rf_parser_error((yylsp[(2) - (9)]).first_line, (yylsp[(2) - (9)]).first_column, "found FUNCTION '", 2, (yyvsp[(2) - (9)].id), "' , expected free ID");
																			free((yyvsp[(2) - (9)].id));
																		}
																		else if(!(domain_1 = rf_parser_get_domain((yyvsp[(4) - (9)].id))))
																		{
																			rf_parser_error((yylsp[(4) - (9)]).first_line, (yylsp[(4) - (9)]).first_column, "'", 2, (yyvsp[(4) - (9)].id), "' is not a DOMAIN");
																			free((yyvsp[(2) - (9)].id));
																		}
																		else if(!(domain_2 = rf_parser_get_domain((yyvsp[(6) - (9)].id))))
																		{
																			rf_parser_error((yylsp[(6) - (9)]).first_line, (yylsp[(6) - (9)]).first_column, "'", 2, (yyvsp[(6) - (9)].id), "' is not a DOMAIN");
																			free((yyvsp[(2) - (9)].id));
																		}
																		else if((yyvsp[(8) - (9)].table_data))
																		{

																			if((yyvsp[(8) - (9)].table_data)->type == RF_PTD_DATA)
																			{
																				int result;
																				RF_ERROR error;
																				relation = rf_relation_create((yyvsp[(2) - (9)].id), domain_1, domain_2);
																				result = rf_relation_build_table(relation, (yyvsp[(8) - (9)].table_data), &error);
																				if(result == 0)
																					rf_parser_add_relation(relation);
																				else
																				{
																					rf_parser_error((yylsp[(8) - (9)]).first_line, (yylsp[(8) - (9)]).first_column, error.string, 0);
																					free(error.string);
																					rf_relation_destroy(relation);
																				}

																			}
																			else if((yyvsp[(8) - (9)].table_data)->type == RF_PTD_FORMULA)
																			{
																				if((yyvsp[(8) - (9)].table_data)->formula)
																				{
																					int result;
																					RF_ERROR error;
																					relation = rf_relation_create((yyvsp[(2) - (9)].id), domain_1, domain_2);
																					result = rf_relation_build_table_by_formula(relation, (yyvsp[(8) - (9)].table_data)->formula, &error);
																					if(result == 0)
																						rf_parser_add_relation(relation);
																					else
																					{
																						rf_parser_error(error.location.first_line, error.location.first_column, error.string, 0);
																						if(error.string)
																							free(error.string);
																						rf_relation_destroy(relation);
																					}
																				}
																				else
																					free((yyvsp[(2) - (9)].id));
																			}
																			else if((yyvsp[(8) - (9)].table_data)->type == RF_PTD_RELATION)
																			{
																				if((yyvsp[(8) - (9)].table_data)->relation)
																				{
																					relation = (yyvsp[(8) - (9)].table_data)->relation;
																					(yyvsp[(8) - (9)].table_data)->relation = 0;
																					
																					if(domain_1 != rf_relation_get_domain_1(relation))
																					{
																						rf_parser_error((yylsp[(4) - (9)]).first_line, (yylsp[(4) - (9)]).first_column, "domain mismatch '", 4,
																							rf_domain_get_name(domain_1), "' != '",
																							rf_domain_get_name(rf_relation_get_domain_1(relation)), "'");
																						free((yyvsp[(2) - (9)].id));
																						rf_relation_destroy(relation);
																					}
																					else if(domain_2 != rf_relation_get_domain_2(relation))
																					{
																						rf_parser_error((yylsp[(6) - (9)]).first_line, (yylsp[(6) - (9)]).first_column, "domain mismatch '", 4,
																							rf_domain_get_name(domain_2), "' != '",
																							rf_domain_get_name(rf_relation_get_domain_2(relation)), "'");
																						free((yyvsp[(2) - (9)].id));
																						rf_relation_destroy(relation);
																					}
																					else
																					{
																						rf_relation_set_name(relation, (yyvsp[(2) - (9)].id));
																						rf_parser_add_relation(relation);
																					}
																				}
																				else
																					free((yyvsp[(2) - (9)].id));
																			}
																			else
																			{
																				rf_parser_error((yylsp[(8) - (9)]).first_line, (yylsp[(8) - (9)]).first_column, "program error - not implemented", 0);
																				free((yyvsp[(2) - (9)].id));
																			}
																		}

																		free((yyvsp[(4) - (9)].id));
																		free((yyvsp[(6) - (9)].id));
																		if((yyvsp[(8) - (9)].table_data))
																			rf_parser_destroy_table_data((yyvsp[(8) - (9)].table_data));
																	;}
    break;

  case 20:

/* Line 1464 of yacc.c  */
#line 332 "parser.y"
    {(yyval.table_data) = (yyvsp[(1) - (1)].table_data);;}
    break;

  case 21:

/* Line 1464 of yacc.c  */
#line 333 "parser.y"
    {(yyval.table_data) = (yyvsp[(1) - (1)].table_data);;}
    break;

  case 22:

/* Line 1464 of yacc.c  */
#line 334 "parser.y"
    {
							RF_RELATION *relation = 0;
							RF_FORMULA_RESULT *result;
							int err = rf_formula_calc((yyvsp[(1) - (1)].formula), 0, 0, &result);
							
							if(err)
							{
								if(result)
									rf_parser_error(result->location.first_line, result->location.first_column,
										result->error, 0);
								else
									rf_parser_error((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column,
										"program error - no errormessage after failed formula_calc", 0);
							}
							else if(result->type == RF_FO_RELATION)
							{
								if(result->is_temporary && result->can_delete)
								{
									relation = result->relation;
									result->can_delete = RF_FALSE;
								}
								else
									relation = rf_relation_copy(result->relation);
							}
							else if(result->type == RF_FO_ELEMENT || result->type == RF_FO_ID)
							{
								relation = rf_parser_get_relation(result->element);
								relation = rf_relation_copy(relation);
								
								if(!relation)
								{
									rf_parser_error((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, "found ELEMENT '", 2, result->element, "', expected RELATION", 0);
								}
							}
							else
								rf_parser_error((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, "expression has wrong result, expected RELATION", 0);
							
							if(result)
								rf_formula_destroy_result(result);
							if((yyvsp[(1) - (1)].formula))
								rf_formula_destroy((yyvsp[(1) - (1)].formula));
							
							if(relation)
							{
								RF_PARSER_TABLE_DATA *table_data = calloc(1, sizeof(RF_PARSER_TABLE_DATA));
								if(!table_data)
								{
									rf_parser_error((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, "program error - no memory", 0);
									(yyval.table_data) = 0;
								}
								else
								{
									table_data->type = RF_PTD_RELATION;
									table_data->relation = relation;
									
									(yyval.table_data) = table_data;
								}
							}
							else
								(yyval.table_data) = 0;
						;}
    break;

  case 23:

/* Line 1464 of yacc.c  */
#line 397 "parser.y"
    {rf_lexer_mode = RF_LEXER_CROSS;;}
    break;

  case 24:

/* Line 1464 of yacc.c  */
#line 397 "parser.y"
    {rf_lexer_mode = RF_LEXER_NORMAL;;}
    break;

  case 25:

/* Line 1464 of yacc.c  */
#line 398 "parser.y"
    {
															RF_DOMAIN *domain_1, *domain_2, *domain_3;
															RF_OPERATION *operation;

															if(rf_parser_get_operation((yyvsp[(2) - (13)].id)))
															{
																rf_parser_error((yylsp[(2) - (13)]).first_line, (yylsp[(2) - (13)]).first_column, "found OPERATION '", 2, (yyvsp[(2) - (13)].id), "' , expected free ID");
																free((yyvsp[(2) - (13)].id));
															}
															else if(rf_parser_get_negation((yyvsp[(2) - (13)].id)))
															{
																rf_parser_error((yylsp[(2) - (13)]).first_line, (yylsp[(2) - (13)]).first_column, "found NEGATION '", 2, (yyvsp[(2) - (13)].id), "' , expected free ID");
																free((yyvsp[(2) - (13)].id));
															}
															else if(rf_parser_get_domain((yyvsp[(2) - (13)].id)))
															{
																rf_parser_error((yylsp[(2) - (13)]).first_line, (yylsp[(2) - (13)]).first_column, "found DOMAIN '", 2, (yyvsp[(2) - (13)].id), "' , expected free ID");
																free((yyvsp[(2) - (13)].id));
															}
															else if(rf_parser_get_relation((yyvsp[(2) - (13)].id)))
															{
																rf_parser_error((yylsp[(2) - (13)]).first_line, (yylsp[(2) - (13)]).first_column, "found RELATION '", 2, (yyvsp[(2) - (13)].id), "' , expected free ID");
																free((yyvsp[(2) - (13)].id));
															}
															else if(rf_parser_get_function((yyvsp[(2) - (13)].id)))
															{
																rf_parser_error((yylsp[(2) - (13)]).first_line, (yylsp[(2) - (13)]).first_column, "found FUNCTION '", 2, (yyvsp[(2) - (13)].id), "' , expected free ID");
																free((yyvsp[(2) - (13)].id));
															}
															else if(!(domain_1 = rf_parser_get_domain((yyvsp[(4) - (13)].id))))
															{
																rf_parser_error((yylsp[(4) - (13)]).first_line, (yylsp[(4) - (13)]).first_column, "'", 2, (yyvsp[(4) - (13)].id), "' is not a DOMAIN");
																free((yyvsp[(2) - (13)].id));
															}
															else if(!(domain_2 = rf_parser_get_domain((yyvsp[(8) - (13)].id))))
															{
																rf_parser_error((yylsp[(8) - (13)]).first_line, (yylsp[(8) - (13)]).first_column, "'", 2, (yyvsp[(8) - (13)].id), "' is not a DOMAIN");
																free((yyvsp[(2) - (13)].id));
															}
															else if(!(domain_3 = rf_parser_get_domain((yyvsp[(10) - (13)].id))))
															{
																rf_parser_error((yylsp[(10) - (13)]).first_line, (yylsp[(10) - (13)]).first_column, "'", 2, (yyvsp[(10) - (13)].id), "' is not a DOMAIN");
																free((yyvsp[(2) - (13)].id));
															}
															else if((yyvsp[(12) - (13)].table_data))
															{

																if((yyvsp[(12) - (13)].table_data)->type == RF_PTD_DATA)
																{
																	int result;
																	RF_ERROR error;
																	operation = rf_operation_create((yyvsp[(2) - (13)].id), domain_1, domain_2, domain_3);
																	result = rf_operation_build_table(operation, (yyvsp[(12) - (13)].table_data), &error);
																	if(result == 0)
																		rf_parser_add_operation(operation);
																	else
																	{
																		rf_parser_error((yylsp[(12) - (13)]).first_line, (yylsp[(12) - (13)]).first_column, error.string, 0);
																		free(error.string);
																		rf_operation_destroy(operation);
																	}
																}
																else if((yyvsp[(12) - (13)].table_data)->type == RF_PTD_FORMULA)
																{
																	if((yyvsp[(12) - (13)].table_data)->formula)
																	{
																		int result;
																		RF_ERROR error;
																		operation = rf_operation_create((yyvsp[(2) - (13)].id), domain_1, domain_2, domain_3);
																		result = rf_operation_build_table_by_formula(operation, (yyvsp[(12) - (13)].table_data)->formula, &error);
																		if(result == 0)
																			rf_parser_add_operation(operation);
																		else
																		{
																			rf_parser_error(error.location.first_line, error.location.first_column, error.string, 0);
																			if(error.string)
																				free(error.string);
																			rf_operation_destroy(operation);
																		}
																	}
																	else
																		free((yyvsp[(2) - (13)].id));
																}
																else if((yyvsp[(12) - (13)].table_data)->type == RF_PTD_OPERATION)
																{
																	if((yyvsp[(12) - (13)].table_data)->operation)
																	{
																		operation = (yyvsp[(12) - (13)].table_data)->operation;
																		(yyvsp[(12) - (13)].table_data)->operation = 0;
																		
																		if(domain_1 != rf_operation_get_domain_1(operation))
																		{
																			rf_parser_error((yylsp[(4) - (13)]).first_line, (yylsp[(4) - (13)]).first_column, "domain mismatch '", 4,
																				rf_domain_get_name(domain_1), "' != '",
																				rf_domain_get_name(rf_operation_get_domain_1(operation)), "'");
																			free((yyvsp[(2) - (13)].id));
																			rf_operation_destroy(operation);
																		}
																		else if(domain_2 != rf_operation_get_domain_2(operation))
																		{
																			rf_parser_error((yylsp[(8) - (13)]).first_line, (yylsp[(8) - (13)]).first_column, "domain mismatch '", 4,
																				rf_domain_get_name(domain_2), "' != '",
																				rf_domain_get_name(rf_operation_get_domain_2(operation)), "'");
																			free((yyvsp[(2) - (13)].id));
																			rf_operation_destroy(operation);
																		}
																		else if(domain_3 != rf_operation_get_domain_3(operation))
																		{
																			rf_parser_error((yylsp[(10) - (13)]).first_line, (yylsp[(10) - (13)]).first_column, "domain mismatch '", 4,
																				rf_domain_get_name(domain_3), "' != '",
																				rf_domain_get_name(rf_operation_get_domain_3(operation)), "'");
																			free((yyvsp[(2) - (13)].id));
																			rf_operation_destroy(operation);
																		}
																		else
																		{
																			rf_operation_set_name(operation, (yyvsp[(2) - (13)].id));
																			rf_parser_add_operation(operation);
																		}
																	}
																	else
																		free((yyvsp[(2) - (13)].id));
																}
																else
																{
																	rf_parser_add_operation((yyvsp[(12) - (13)].table_data)->operation);
																	(yyvsp[(12) - (13)].table_data)->operation = 0;
																	free((yyvsp[(2) - (13)].id));
																}
															}
															
															if((yyvsp[(4) - (13)].id))
																free((yyvsp[(4) - (13)].id));
															if((yyvsp[(8) - (13)].id))
																free((yyvsp[(8) - (13)].id));
															if((yyvsp[(10) - (13)].id))
																free((yyvsp[(10) - (13)].id));
															if((yyvsp[(12) - (13)].table_data))
																rf_parser_destroy_table_data((yyvsp[(12) - (13)].table_data));
														;}
    break;

  case 26:

/* Line 1464 of yacc.c  */
#line 540 "parser.y"
    {(yyval.table_data) = (yyvsp[(1) - (1)].table_data);;}
    break;

  case 27:

/* Line 1464 of yacc.c  */
#line 541 "parser.y"
    {(yyval.table_data) = (yyvsp[(1) - (1)].table_data);;}
    break;

  case 28:

/* Line 1464 of yacc.c  */
#line 542 "parser.y"
    {
							RF_OPERATION *operation = 0;
							RF_FORMULA_RESULT *result;
							int err = rf_formula_calc((yyvsp[(1) - (1)].formula), 0, 0, &result);
							
							if(err)
							{
								if(result)
									rf_parser_error(result->location.first_line, result->location.first_column,
										result->error, 0);
								else
									rf_parser_error((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column,
										"program error - no errormessage after failed formula_calc", 0);
							}
							else if(result->type == RF_FO_OPERATION)
							{
								if(result->is_temporary && result->can_delete)
								{
									operation = result->operation;
									result->can_delete = RF_FALSE;
								}
								else
									operation = rf_operation_copy(result->operation);
							}
							else if(result->type == RF_FO_ELEMENT || result->type == RF_FO_ID)
							{
								operation = rf_parser_get_operation(result->element);
								operation = rf_operation_copy(operation);
								
								if(!operation)
								{
									rf_parser_error((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, "found ELEMENT '", 2, result->element, "', expected OPERATION", 0);
								}
							}
							else
								rf_parser_error((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, "expression has wrong result, expected OPERATION", 0);
							
							if(result)
								rf_formula_destroy_result(result);
							if((yyvsp[(1) - (1)].formula))
								rf_formula_destroy((yyvsp[(1) - (1)].formula));
							
							if(operation)
							{
								RF_PARSER_TABLE_DATA *table_data = calloc(1, sizeof(RF_PARSER_TABLE_DATA));
								if(!table_data)
								{
									rf_parser_error((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, "program error - no memory", 0);
									(yyval.table_data) = 0;
								}
								else
								{
									table_data->type = RF_PTD_OPERATION;
									table_data->operation = operation;
									
									(yyval.table_data) = table_data;
								}
							}
							else
								(yyval.table_data) = 0;
						;}
    break;

  case 29:

/* Line 1464 of yacc.c  */
#line 605 "parser.y"
    {
															RF_NEGATION *negation = 0;
															RF_DOMAIN *domain = 0;
															
															if(rf_parser_get_negation((yyvsp[(2) - (7)].id)))
															{
																rf_parser_error((yylsp[(2) - (7)]).first_line, (yylsp[(2) - (7)]).first_column, "found NEGATION '", 2, (yyvsp[(2) - (7)].id), "' , expected free ID");
																if((yyvsp[(6) - (7)].list))
																	rf_list_destroy((yyvsp[(6) - (7)].list), free);
																if((yyvsp[(2) - (7)].id))
																	free((yyvsp[(2) - (7)].id));
																if((yyvsp[(4) - (7)].id))
																	free((yyvsp[(4) - (7)].id));
															}
															else if(rf_parser_get_operation((yyvsp[(2) - (7)].id)))
															{
																rf_parser_error((yylsp[(2) - (7)]).first_line, (yylsp[(2) - (7)]).first_column, "found OPERATION '", 2, (yyvsp[(2) - (7)].id), "' , expected free ID");
																if((yyvsp[(6) - (7)].list))
																	rf_list_destroy((yyvsp[(6) - (7)].list), free);
																if((yyvsp[(2) - (7)].id))
																	free((yyvsp[(2) - (7)].id));
																if((yyvsp[(4) - (7)].id))
																	free((yyvsp[(4) - (7)].id));
															}
															else if(rf_parser_get_function((yyvsp[(2) - (7)].id)))
															{
																rf_parser_error((yylsp[(2) - (7)]).first_line, (yylsp[(2) - (7)]).first_column, "found FUNCTION '", 2, (yyvsp[(2) - (7)].id), "' , expected free ID");
																if((yyvsp[(6) - (7)].list))
																	rf_list_destroy((yyvsp[(6) - (7)].list), free);
																if((yyvsp[(2) - (7)].id))
																	free((yyvsp[(2) - (7)].id));
																if((yyvsp[(4) - (7)].id))
																	free((yyvsp[(4) - (7)].id));
															}
															else if(rf_parser_get_domain((yyvsp[(2) - (7)].id)))
															{
																rf_parser_error((yylsp[(2) - (7)]).first_line, (yylsp[(2) - (7)]).first_column, "found DOMAIN '", 2, (yyvsp[(2) - (7)].id), "' , expected free ID");
																if((yyvsp[(6) - (7)].list))
																	rf_list_destroy((yyvsp[(6) - (7)].list), free);
																if((yyvsp[(2) - (7)].id))
																	free((yyvsp[(2) - (7)].id));
																if((yyvsp[(4) - (7)].id))
																	free((yyvsp[(4) - (7)].id));
															}
															else if(rf_parser_get_relation((yyvsp[(2) - (7)].id)))
															{
																rf_parser_error((yylsp[(2) - (7)]).first_line, (yylsp[(2) - (7)]).first_column, "found RELATION '", 2, (yyvsp[(2) - (7)].id), "' , expected free ID");
																if((yyvsp[(6) - (7)].list))
																	rf_list_destroy((yyvsp[(6) - (7)].list), free);
																if((yyvsp[(2) - (7)].id))
																	free((yyvsp[(2) - (7)].id));
																if((yyvsp[(4) - (7)].id))
																	free((yyvsp[(4) - (7)].id));
															}
															else if(!(domain = rf_parser_get_domain((yyvsp[(4) - (7)].id))))
															{
																rf_parser_error((yylsp[(4) - (7)]).first_line, (yylsp[(4) - (7)]).first_column, "found ID '", 2, (yyvsp[(4) - (7)].id), "' , expected DOMAIN");
																if((yyvsp[(6) - (7)].list))
																	rf_list_destroy((yyvsp[(6) - (7)].list), free);
																if((yyvsp[(2) - (7)].id))
																	free((yyvsp[(2) - (7)].id));
																if((yyvsp[(4) - (7)].id))
																	free((yyvsp[(4) - (7)].id));
															}
															else
															{
																RF_ERROR error;
																negation = rf_negation_create((yyvsp[(2) - (7)].id), domain);
																if(negation)
																{
																	int result = rf_negation_set_items(negation, (yyvsp[(6) - (7)].list), &error);
																	if(result)
																	{
																		rf_parser_error((yylsp[(6) - (7)]).first_line, (yylsp[(6) - (7)]).first_column, error.string, 0);
																		if(error.string)
																			free(error.string);
																	}
																	else
																		rf_parser_add_negation(negation);
																}
																else
																{
																	rf_list_destroy((yyvsp[(6) - (7)].list), free);
																	rf_parser_error((yylsp[(1) - (7)]).first_line, (yylsp[(1) - (7)]).first_column, "no memory", 0);
																}
																	
																free((yyvsp[(4) - (7)].id));
															}
														;}
    break;

  case 30:

/* Line 1464 of yacc.c  */
#line 696 "parser.y"
    {rf_parser_list_domains();;}
    break;

  case 31:

/* Line 1464 of yacc.c  */
#line 697 "parser.y"
    {rf_parser_list_relations();;}
    break;

  case 32:

/* Line 1464 of yacc.c  */
#line 698 "parser.y"
    {rf_parser_list_operations();;}
    break;

  case 33:

/* Line 1464 of yacc.c  */
#line 699 "parser.y"
    {rf_parser_list_negations();;}
    break;

  case 34:

/* Line 1464 of yacc.c  */
#line 700 "parser.y"
    {rf_parser_list_functions();;}
    break;

  case 35:

/* Line 1464 of yacc.c  */
#line 703 "parser.y"
    {
							RF_DOMAIN *domain = 0;
							RF_RELATION *relation = 0;
							RF_OPERATION *operation = 0;
							RF_NEGATION *negation = 0;
							
							if(!(yyvsp[(2) - (3)].id))
							{
								rf_parser_error((yylsp[(2) - (3)]).first_line, (yylsp[(2) - (3)]).first_column, "program error - empty ID", 0);
							}
							else if(domain = rf_parser_get_domain((yyvsp[(2) - (3)].id)))
							{
								rf_parser_delete_domain(domain);
								free((yyvsp[(2) - (3)].id));
							}
							else if(relation = rf_parser_get_relation((yyvsp[(2) - (3)].id)))
							{
								rf_parser_delete_relation(relation);
								free((yyvsp[(2) - (3)].id));
							}
							else if(operation = rf_parser_get_operation((yyvsp[(2) - (3)].id)))
							{
								rf_parser_delete_operation(operation);
								free((yyvsp[(2) - (3)].id));
							}
							else if(negation = rf_parser_get_negation((yyvsp[(2) - (3)].id)))
							{
								rf_parser_delete_negation(negation);
								free((yyvsp[(2) - (3)].id));
							}
							else
							{
								rf_parser_error((yylsp[(2) - (3)]).first_line, (yylsp[(2) - (3)]).first_column, "Cant delete ID '", 2, (yyvsp[(2) - (3)].id), "', expected DOMAIN or RELATION or OPERATION or NEGATION.");
								free((yyvsp[(2) - (3)].id));
							}
						;}
    break;

  case 36:

/* Line 1464 of yacc.c  */
#line 741 "parser.y"
    {
							RF_LIST *list = rf_list_create();
							if(!list)
							{
								rf_parser_error((yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, "no memory", 0);
								free((yyvsp[(1) - (3)].id));
								free((yyvsp[(3) - (3)].id));
								(yyval.list) = 0;
							}
							else
							{
								rf_list_append(list, (yyvsp[(1) - (3)].id));
								rf_list_append(list, (yyvsp[(3) - (3)].id));

								(yyval.list) = list;
							}
								
						;}
    break;

  case 37:

/* Line 1464 of yacc.c  */
#line 759 "parser.y"
    {
										if((yyvsp[(1) - (3)].list) == 0 || (yyvsp[(3) - (3)].list) == 0)
										{
											if((yyvsp[(1) - (3)].list))
												rf_list_destroy((yyvsp[(1) - (3)].list), free);
											if((yyvsp[(3) - (3)].list))
												rf_list_destroy((yyvsp[(3) - (3)].list), free);
												
											(yyval.list) = 0;
										}
										else
										{
											rf_list_merge((yyvsp[(1) - (3)].list), (yyvsp[(3) - (3)].list));
											rf_list_destroy((yyvsp[(3) - (3)].list), 0);
											
											(yyval.list) = (yyvsp[(1) - (3)].list);
										}
									;}
    break;

  case 38:

/* Line 1464 of yacc.c  */
#line 779 "parser.y"
    {
						RF_FORMULA_RESULT *result = 0;
						
						if(!(yyvsp[(1) - (2)].formula));
						else if(rf_formula_calc((yyvsp[(1) - (2)].formula), 0, 0, &result) != 0)
						{
							if(result == 0)
								rf_parser_error((yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column, "error in formula", 0);
							else
								rf_parser_error(result->location.first_line,
									result->location.first_column, result->error, 0);
						}
						else if(result->type == RF_FO_DOMAIN)
						{
							rf_parser_show_domain(result->domain);
						}
						else if(result->type == RF_FO_RELATION)
						{
							rf_parser_show_relation(result->relation);
						}
						else if(result->type == RF_FO_NEGATION)
						{
							rf_parser_show_negation(result->negation);
						}
						else if(result->type == RF_FO_OPERATION)
						{
							rf_parser_show_operation(result->operation);
						}
						else if(result->type == RF_FO_ELEMENT)
						{
							rf_parser_show_string(rf_parser_record_read());
							rf_parser_show_string("  =  ");
							rf_parser_show_element(result->element);
							rf_parser_show_string("\n");
						}
						else if(result->type == RF_FO_ID)
						{
							RF_RELATION *relation = rf_parser_get_relation(result->element);
							RF_OPERATION *operation = rf_parser_get_operation(result->element);
							RF_NEGATION *negation = rf_parser_get_negation(result->element);
							RF_DOMAIN *domain = rf_parser_get_domain(result->element);
							RF_FUNCTION *function = rf_parser_get_function(result->element);
							
							if(relation)
								rf_parser_show_relation(relation);
							else if(operation)
								rf_parser_show_operation(operation);
							else if(negation)
								rf_parser_show_negation(negation);
							else if(domain)
								rf_parser_show_domain(domain);
							else if(function)
								rf_parser_show_function(function);
							else
								rf_parser_error((yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column, "found free ID '", 2, result->element, "', expected"
									" RELATION or OPERATION or NEGATION or DOMAIN or FUNCTION or EXPRESSION");
						}
						else
						{
							rf_parser_error((yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column, "program error - not implemented", 0);
						}

						if(result)
							rf_formula_destroy_result(result);
						if((yyvsp[(1) - (2)].formula))
							rf_formula_destroy((yyvsp[(1) - (2)].formula));
					;}
    break;

  case 39:

/* Line 1464 of yacc.c  */
#line 846 "parser.y"
    {
							if(!(yyvsp[(1) - (2)].id))
								rf_parser_error((yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column, "program error: no string", 0);
							else
							{
								rf_parser_show_string((yyvsp[(1) - (2)].id));
								rf_parser_show_string("\n\n");
								free((yyvsp[(1) - (2)].id));
							}
						;}
    break;

  case 40:

/* Line 1464 of yacc.c  */
#line 858 "parser.y"
    {
									if((yyvsp[(2) - (3)].list))
									{
										RF_DOMAIN *domain = rf_domain_create(rf_string_copy("no name"));
										RF_ERROR error;
										
										if(rf_domain_check_elements((yyvsp[(2) - (3)].list), &error) == 1)
										{
											rf_parser_error((yylsp[(2) - (3)]).first_line, (yylsp[(2) - (3)]).first_column, error.string, 0);
											free(error.string);
											rf_domain_destroy(domain);
											rf_list_destroy((yyvsp[(2) - (3)].list), (void (*)(void *))rf_element_destroy);
											(yyval.domain) = 0;
										}
										else
										{
											rf_domain_set_list(domain, (yyvsp[(2) - (3)].list));
		
											(yyval.domain) = domain;
										}
									}
									else
										(yyval.domain) = 0;
								;}
    break;

  case 41:

/* Line 1464 of yacc.c  */
#line 883 "parser.y"
    {
									if(!(yyvsp[(1) - (5)].id))
									{
										rf_parser_error((yylsp[(1) - (5)]).first_line, (yylsp[(1) - (5)]).first_column, "program error - no id", 0);
										
										if((yyvsp[(4) - (5)].list))
											rf_list_destroy((yyvsp[(4) - (5)].list), (void (*)(void *))rf_element_destroy);
											
										(yyval.domain) = 0;
									}
									else if((yyvsp[(4) - (5)].list))
									{
										RF_DOMAIN *domain = rf_domain_create((yyvsp[(1) - (5)].id));
										RF_ERROR error;
										
										if(rf_domain_check_elements((yyvsp[(4) - (5)].list), &error) == 1)
										{
											rf_parser_error((yylsp[(4) - (5)]).first_line, (yylsp[(4) - (5)]).first_column, error.string, 0);
											free(error.string);
											rf_domain_destroy(domain);
											
											(yyval.domain) = 0;
										}
										else
										{
											rf_domain_set_list(domain, (yyvsp[(4) - (5)].list));
			
											(yyval.domain) = domain;
										}
									}
									else
									{
										free((yyvsp[(1) - (5)].id));
										
										(yyval.domain) = 0;
									}
								;}
    break;

  case 42:

/* Line 1464 of yacc.c  */
#line 920 "parser.y"
    {
								if(!(yyvsp[(1) - (4)].id))
								{
									rf_parser_error((yylsp[(1) - (4)]).first_line, (yylsp[(1) - (4)]).first_column, "program error - no id", 0);
									(yyval.domain) = 0;
								}
								else
								{
									RF_DOMAIN *domain = rf_domain_create((yyvsp[(1) - (4)].id));
									(yyval.domain) = domain;
								}
							;}
    break;

  case 43:

/* Line 1464 of yacc.c  */
#line 934 "parser.y"
    {
					RF_LIST *elemente = rf_list_create();
					RF_ELEMENT *element = rf_element_create(RF_ET_NAME, (yyvsp[(1) - (1)].id));
					rf_list_append(elemente, element);

					(yyval.list) = elemente;
				;}
    break;

  case 44:

/* Line 1464 of yacc.c  */
#line 941 "parser.y"
    {
							RF_DOMAIN *domain = rf_parser_get_domain((yyvsp[(2) - (2)].id));
							RF_LIST *elemente = 0;
							RF_ELEMENT *element = 0;
							
							if(!domain)
							{
								rf_parser_error((yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column, "'", 2, (yyvsp[(2) - (2)].id), "' is not a DOMAIN");
								if((yyvsp[(2) - (2)].id))
									free((yyvsp[(2) - (2)].id));
								(yyval.list) = 0;
							}
							else
							{
								elemente = rf_list_create();
								element = rf_element_create(RF_ET_GLOBAL_DOMAIN, domain);
								rf_list_append(elemente, element);
								
								(yyval.list) = elemente;
							}
						;}
    break;

  case 45:

/* Line 1464 of yacc.c  */
#line 962 "parser.y"
    {
							if((yyvsp[(1) - (1)].domain))
							{
								RF_ELEMENT *element = rf_element_create(RF_ET_DOMAIN, (yyvsp[(1) - (1)].domain));
								RF_LIST *elemente = rf_list_create();
								rf_list_append(elemente, element);

								(yyval.list) = elemente;
							}
							else
								(yyval.list) = 0;
						;}
    break;

  case 46:

/* Line 1464 of yacc.c  */
#line 974 "parser.y"
    {
										if((yyvsp[(1) - (3)].list) && (yyvsp[(3) - (3)].list))
										{
											rf_list_merge((yyvsp[(1) - (3)].list), (yyvsp[(3) - (3)].list));
											rf_list_destroy((yyvsp[(3) - (3)].list), 0);

											(yyval.list) = (yyvsp[(1) - (3)].list);
										}
										else if((yyvsp[(1) - (3)].list))
										{
											rf_list_destroy((yyvsp[(1) - (3)].list), (void (*)(void *))rf_element_destroy);
											(yyval.list) = 0;
										}
										else if((yyvsp[(3) - (3)].list))
										{
											rf_list_destroy((yyvsp[(3) - (3)].list), (void (*)(void *))rf_element_destroy);
											(yyval.list) = 0;
										}
									;}
    break;

  case 47:

/* Line 1464 of yacc.c  */
#line 995 "parser.y"
    {
												RF_PARSER_TABLE_DATA *table = malloc(sizeof(RF_PARSER_TABLE_DATA));
												table->type = RF_PTD_DATA;
												table->rows = (yyvsp[(5) - (6)].list);
												table->columns = (yyvsp[(3) - (6)].list);

												(yyval.table_data) = table;
											;}
    break;

  case 48:

/* Line 1464 of yacc.c  */
#line 1005 "parser.y"
    {
				RF_LIST *list = rf_list_create();
				rf_list_append(list, (yyvsp[(1) - (1)].id));
				(yyval.list) = list;
			;}
    break;

  case 49:

/* Line 1464 of yacc.c  */
#line 1010 "parser.y"
    {
						rf_list_append((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].id));
						(yyval.list) = (yyvsp[(1) - (2)].list);
					;}
    break;

  case 50:

/* Line 1464 of yacc.c  */
#line 1016 "parser.y"
    {
							RF_LIST *row_list = rf_list_create();
							RF_PARSER_TABLE_ROW *row = rf_parser_create_table_row((yyvsp[(1) - (3)].id));
							RF_LIST *list = rf_parser_table_row_get_list(row);
							rf_list_merge(list, (yyvsp[(3) - (3)].list));
							rf_list_destroy((yyvsp[(3) - (3)].list), 0);
							rf_list_append(row_list, row);

							(yyval.list) = row_list;
						;}
    break;

  case 51:

/* Line 1464 of yacc.c  */
#line 1026 "parser.y"
    {
										RF_LIST *row_list = rf_list_create();
										RF_PARSER_TABLE_ROW *row = rf_parser_create_table_row((yyvsp[(1) - (5)].id));
										RF_LIST *list = rf_parser_table_row_get_list(row);
										rf_list_merge(list, (yyvsp[(3) - (5)].list));
										rf_list_destroy((yyvsp[(3) - (5)].list), 0);
										rf_list_append(row_list, row);

										rf_list_merge(row_list, (yyvsp[(5) - (5)].list));
										rf_list_destroy((yyvsp[(5) - (5)].list), 0);

										(yyval.list) = row_list;
									;}
    break;

  case 52:

/* Line 1464 of yacc.c  */
#line 1041 "parser.y"
    {rf_parser_with_variable = RF_TRUE;;}
    break;

  case 53:

/* Line 1464 of yacc.c  */
#line 1041 "parser.y"
    {
																		RF_PARSER_TABLE_DATA *table = malloc(sizeof(RF_PARSER_TABLE_DATA));
																		table->type = RF_PTD_FORMULA;
																		table->formula = (yyvsp[(3) - (3)].formula);
										
																		(yyval.table_data) = table;
																	;}
    break;

  case 54:

/* Line 1464 of yacc.c  */
#line 1050 "parser.y"
    {(yyval.formula) = (yyvsp[(1) - (1)].formula);;}
    break;

  case 55:

/* Line 1464 of yacc.c  */
#line 1051 "parser.y"
    {
								RF_OPERATION *operation = rf_parser_get_operation((yyvsp[(2) - (3)].id));
								RF_RELATION *relation = rf_parser_get_relation((yyvsp[(2) - (3)].id));
								RF_FORMULA *formula = 0;
								
								if(!(yyvsp[(1) - (3)].formula) || !(yyvsp[(3) - (3)].formula))
								{
									if((yyvsp[(1) - (3)].formula))
										rf_formula_destroy((yyvsp[(1) - (3)].formula));
									if((yyvsp[(3) - (3)].formula))
										rf_formula_destroy((yyvsp[(3) - (3)].formula));
										
									free((yyvsp[(2) - (3)].id));
									
									(yyval.formula) = 0;
								}
								else if(operation)
								{
									formula = rf_formula_create();
									rf_formula_set_operation(formula, operation);
									rf_formula_set_location(formula, (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(1) - (3)]).last_line, (yylsp[(1) - (3)]).last_column);
									rf_formula_append_argument(formula, (yyvsp[(1) - (3)].formula));
									rf_formula_append_argument(formula, (yyvsp[(3) - (3)].formula));
									
									free((yyvsp[(2) - (3)].id));
									
									(yyval.formula) = formula;
								}
								else if(relation)
								{
									formula = rf_formula_create();
									rf_formula_set_relation(formula, relation);
									rf_formula_set_location(formula, (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(1) - (3)]).last_line, (yylsp[(1) - (3)]).last_column);
									rf_formula_append_argument(formula, (yyvsp[(1) - (3)].formula));
									rf_formula_append_argument(formula, (yyvsp[(3) - (3)].formula));
									
									free((yyvsp[(2) - (3)].id));
									
									(yyval.formula) = formula;
								}
								else
								{
									rf_parser_error((yylsp[(2) - (3)]).first_line, (yylsp[(2) - (3)]).first_column, "'", 2, (yyvsp[(2) - (3)].id), "' is not a OPERATION or RELATION");
									free((yyvsp[(2) - (3)].id));
									if((yyvsp[(1) - (3)].formula))
										rf_formula_destroy((yyvsp[(1) - (3)].formula));
									if((yyvsp[(3) - (3)].formula))
										rf_formula_destroy((yyvsp[(3) - (3)].formula));
										
									(yyval.formula) = 0;
								}
							;}
    break;

  case 56:

/* Line 1464 of yacc.c  */
#line 1105 "parser.y"
    {
				RF_FORMULA *formula = rf_formula_create();
				rf_formula_set_element(formula, (yyvsp[(1) - (1)].id));
				rf_formula_set_location(formula, (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				(yyval.formula) = formula;
			;}
    break;

  case 57:

/* Line 1464 of yacc.c  */
#line 1111 "parser.y"
    {
					if(rf_parser_with_variable == RF_TRUE)
					{
						RF_FORMULA *formula = rf_formula_create();
						rf_formula_set_variable(formula, 'X');
						rf_formula_set_location(formula, (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
						(yyval.formula) = formula;
					}
					else
					{
						rf_parser_error((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, "Variable 'X' is only in FORMULA allowed", 0);
						(yyval.formula) = 0;
					}
				;}
    break;

  case 58:

/* Line 1464 of yacc.c  */
#line 1125 "parser.y"
    {
					if(rf_parser_with_variable == RF_TRUE)
					{
						RF_FORMULA *formula = rf_formula_create();
						rf_formula_set_variable(formula, 'Y');
						rf_formula_set_location(formula, (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
						(yyval.formula) = formula;
					}
					else
					{
						rf_parser_error((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, "Variable 'Y' is only in FORMULA allowed", 0);
						(yyval.formula) = 0;
					}
				;}
    break;

  case 59:

/* Line 1464 of yacc.c  */
#line 1139 "parser.y"
    {
							RF_FORMULA *formula = 0;
							
							if(!(yyvsp[(1) - (1)].domain))
							{
								(yyval.formula) = 0;
							}
							else
							{
								formula = rf_formula_create();
								rf_formula_set_domain(formula, (yyvsp[(1) - (1)].domain));
								
								(yyval.formula) = formula;
							}
						;}
    break;

  case 60:

/* Line 1464 of yacc.c  */
#line 1154 "parser.y"
    {(yyval.formula) = (yyvsp[(2) - (3)].formula);;}
    break;

  case 61:

/* Line 1464 of yacc.c  */
#line 1155 "parser.y"
    {
									RF_FUNCTION *function = rf_parser_get_function((yyvsp[(1) - (4)].id));
									RF_NEGATION *negation = rf_parser_get_negation((yyvsp[(1) - (4)].id));
									RF_FORMULA *formula = 0;
									
									if(!(yyvsp[(1) - (4)].id) || !(yyvsp[(3) - (4)].array) || (!function && !negation))
									{
										if((yyvsp[(1) - (4)].id) && (!function && !negation))
											rf_parser_error((yylsp[(1) - (4)]).first_line, (yylsp[(1) - (4)]).first_column, "'", 2, (yyvsp[(1) - (4)].id), "' is not a FUNCTION or NEGATION");
										if(!(yyvsp[(1) - (4)].id))
											rf_parser_error((yylsp[(1) - (4)]).first_line, (yylsp[(1) - (4)]).first_column, "program error - no ID", 0);
										if(!(yyvsp[(3) - (4)].array))
											rf_parser_error((yylsp[(3) - (4)]).first_line, (yylsp[(3) - (4)]).first_column, "no arguments for '", 2, (yyvsp[(1) - (4)].id), "'");
										
										if((yyvsp[(1) - (4)].id))
											free((yyvsp[(1) - (4)].id));
										if((yyvsp[(3) - (4)].array))
											rf_array_destroy((yyvsp[(3) - (4)].array), (void (*)(void *))rf_formula_destroy);
											
										(yyval.formula) = 0;
									}
									else if(function)
									{
										if(rf_function_get_argument_count(function) != rf_array_size((yyvsp[(3) - (4)].array)))
										{
											rf_parser_error((yylsp[(3) - (4)]).first_line, (yylsp[(3) - (4)]).first_column, "Wrong argument count for function '", 2, (yyvsp[(1) - (4)].id), "'");
											free((yyvsp[(1) - (4)].id));
											rf_array_destroy((yyvsp[(3) - (4)].array), (void (*)(void *))rf_formula_destroy);
											
											(yyval.formula) = 0;
										}
										else
										{
											formula = rf_formula_create();
											rf_formula_set_function(formula, function);
											rf_formula_set_location(formula, (yylsp[(1) - (4)]).first_line, (yylsp[(1) - (4)]).first_column, (yylsp[(1) - (4)]).last_line, (yylsp[(1) - (4)]).last_column);
											rf_formula_set_arguments(formula, (yyvsp[(3) - (4)].array));
											
											free((yyvsp[(1) - (4)].id));
											
											(yyval.formula) = formula;
										}
									}
									else if(negation)
									{
										if(rf_array_size((yyvsp[(3) - (4)].array)) != 1)
										{
											rf_parser_error((yylsp[(3) - (4)]).first_line, (yylsp[(3) - (4)]).first_column, "Wrong argument count for negation '", 2, (yyvsp[(1) - (4)].id), "'");
											free((yyvsp[(1) - (4)].id));
											rf_array_destroy((yyvsp[(3) - (4)].array), (void (*)(void *))rf_formula_destroy);
											
											(yyval.formula) = 0;
										}
										else
										{
											formula = rf_formula_create();
											rf_formula_set_negation(formula, negation);
											rf_formula_set_location(formula, (yylsp[(1) - (4)]).first_line, (yylsp[(1) - (4)]).first_column, (yylsp[(1) - (4)]).last_line, (yylsp[(1) - (4)]).last_column);
											rf_formula_set_arguments(formula, (yyvsp[(3) - (4)].array));
											
											free((yyvsp[(1) - (4)].id));
											
											(yyval.formula) = formula;
										}
									}
								;}
    break;

  case 62:

/* Line 1464 of yacc.c  */
#line 1223 "parser.y"
    {
						RF_ARRAY *array = 0;
						
						if(!(yyvsp[(1) - (1)].formula))
							(yyval.array) = 0;
						else
						{
							array = rf_array_create();
							rf_array_append(array, (yyvsp[(1) - (1)].formula));
							
							(yyval.array) = array;
						}
					;}
    break;

  case 63:

/* Line 1464 of yacc.c  */
#line 1236 "parser.y"
    {
											if(!(yyvsp[(1) - (3)].array) || !(yyvsp[(3) - (3)].array))
											{
												if((yyvsp[(1) - (3)].array))
													rf_array_destroy((yyvsp[(1) - (3)].array), (void (*)(void *))rf_formula_destroy);
												if((yyvsp[(3) - (3)].array))
													rf_array_destroy((yyvsp[(3) - (3)].array), (void (*)(void *))rf_formula_destroy);
													
												(yyval.array) = 0;
											}
											else
											{
												rf_array_merge((yyvsp[(1) - (3)].array), (yyvsp[(3) - (3)].array));
												rf_array_destroy((yyvsp[(3) - (3)].array), (void (*)(void *))rf_formula_destroy);
												
												(yyval.array) = (yyvsp[(1) - (3)].array);
											}
										;}
    break;



/* Line 1464 of yacc.c  */
#line 3124 "parser.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

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

  yyerror_range[0] = yylloc;

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
		      yytoken, &yylval, &yylloc);
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

  yyerror_range[0] = yylsp[1-yylen];
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

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
  *++yylsp = yyloc;

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
		 yytoken, &yylval, &yylloc);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
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



/* Line 1684 of yacc.c  */
#line 1256 "parser.y"



/* c code */

/* see lexer.c */

