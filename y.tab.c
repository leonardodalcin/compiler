/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     KW_CHAR = 258,
     KW_INT = 259,
     KW_FLOAT = 260,
     KW_IF = 261,
     KW_THEN = 262,
     KW_ELSE = 263,
     KW_WHILE = 264,
     KW_FOR = 265,
     KW_TO = 266,
     KW_READ = 267,
     KW_RETURN = 268,
     KW_PRINT = 269,
     OPERATOR_LE = 270,
     OPERATOR_GE = 271,
     OPERATOR_EQ = 272,
     OPERATOR_NE = 273,
     OPERATOR_AND = 274,
     OPERATOR_OR = 275,
     TK_IDENTIFIER = 276,
     LIT_INTEGER = 277,
     LIT_REAL = 278,
     LIT_CHAR = 279,
     LIT_STRING = 280,
     TOKEN_ERROR = 281
   };
#endif
/* Tokens.  */
#define KW_CHAR 258
#define KW_INT 259
#define KW_FLOAT 260
#define KW_IF 261
#define KW_THEN 262
#define KW_ELSE 263
#define KW_WHILE 264
#define KW_FOR 265
#define KW_TO 266
#define KW_READ 267
#define KW_RETURN 268
#define KW_PRINT 269
#define OPERATOR_LE 270
#define OPERATOR_GE 271
#define OPERATOR_EQ 272
#define OPERATOR_NE 273
#define OPERATOR_AND 274
#define OPERATOR_OR 275
#define TK_IDENTIFIER 276
#define LIT_INTEGER 277
#define LIT_REAL 278
#define LIT_CHAR 279
#define LIT_STRING 280
#define TOKEN_ERROR 281




/* Copy the first part of user declarations.  */
#line 1 "parser.y"


#include<stdio.h>
#include<stdlib.h>
#include "scanner.h"
#include "hash.h"
#include "astree.h"
#include "semantic.h"


extern FILE *yyin;


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
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

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 15 "parser.y"
{
    struct hash_node *symbol;
    struct s_astree *astree;
}
/* Line 193 of yacc.c.  */
#line 166 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 179 "y.tab.c"

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
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
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
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   337

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  80
/* YYNRULES -- Number of states.  */
#define YYNSTATES  156

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   281

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    40,    46,     2,    39,     2,     2,    43,     2,
      33,    34,    31,    29,    27,    30,     2,    32,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    38,    35,
      44,    28,    45,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    36,     2,    37,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    41,     2,    42,     2,     2,     2,     2,
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
      25,    26
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    11,    13,    15,    17,
      23,    32,    39,    46,    53,    56,    57,    59,    61,    63,
      65,    66,    68,    70,    72,    74,    76,    78,    82,    85,
      88,    89,    94,    98,   102,   103,   105,   107,   109,   111,
     113,   114,   118,   122,   124,   128,   135,   142,   151,   157,
     167,   170,   173,   176,   178,   180,   183,   187,   189,   192,
     196,   198,   203,   206,   209,   211,   213,   217,   221,   225,
     229,   233,   237,   240,   244,   248,   252,   256,   260,   264,
     268
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      48,     0,    -1,    49,    -1,    50,    49,    -1,    -1,    51,
      -1,    52,    -1,    53,    -1,    54,    -1,    57,    61,    28,
      58,    35,    -1,    57,    61,    36,    22,    37,    38,    55,
      35,    -1,    57,    61,    36,    22,    37,    35,    -1,    57,
      61,    33,    59,    34,    63,    -1,    57,    39,    61,    28,
      58,    35,    -1,    56,    55,    -1,    -1,    22,    -1,    24,
      -1,    23,    -1,    40,    -1,    -1,     3,    -1,     4,    -1,
       5,    -1,    22,    -1,    24,    -1,    23,    -1,    57,    61,
      60,    -1,    58,    60,    -1,    61,    60,    -1,    -1,    27,
      57,    61,    60,    -1,    27,    58,    60,    -1,    27,    61,
      60,    -1,    -1,    21,    -1,    65,    -1,    66,    -1,    67,
      -1,    63,    -1,    -1,    41,    64,    42,    -1,    62,    35,
      64,    -1,    62,    -1,    61,    28,    70,    -1,    61,    36,
      70,    37,    28,    70,    -1,     6,    33,    70,    34,     7,
      62,    -1,     6,    33,    70,    34,     7,    62,     8,    62,
      -1,     9,    33,    70,    34,    62,    -1,    10,    33,    61,
      28,    70,    11,    70,    34,    62,    -1,    14,    69,    -1,
      12,    61,    -1,    13,    70,    -1,    25,    -1,    68,    -1,
      68,    69,    -1,    68,    40,    69,    -1,    70,    -1,    70,
      69,    -1,    70,    40,    69,    -1,    61,    -1,    61,    36,
      70,    37,    -1,    39,    61,    -1,    43,    61,    -1,    22,
      -1,    24,    -1,    70,    29,    70,    -1,    70,    30,    70,
      -1,    70,    31,    70,    -1,    70,    32,    70,    -1,    70,
      44,    70,    -1,    70,    45,    70,    -1,    46,    70,    -1,
      33,    70,    34,    -1,    70,    15,    70,    -1,    70,    16,
      70,    -1,    70,    17,    70,    -1,    70,    18,    70,    -1,
      70,    19,    70,    -1,    70,    20,    70,    -1,    61,    33,
      59,    34,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    82,    82,    85,    86,    89,    90,    91,    92,    95,
      98,    99,   102,   104,   106,   107,   110,   111,   112,   113,
     114,   117,   118,   119,   122,   123,   124,   127,   128,   129,
     130,   133,   134,   135,   136,   139,   142,   143,   144,   145,
     146,   149,   152,   153,   156,   157,   160,   161,   162,   163,
     166,   167,   168,   171,   174,   175,   176,   177,   178,   179,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "KW_CHAR", "KW_INT", "KW_FLOAT", "KW_IF",
  "KW_THEN", "KW_ELSE", "KW_WHILE", "KW_FOR", "KW_TO", "KW_READ",
  "KW_RETURN", "KW_PRINT", "OPERATOR_LE", "OPERATOR_GE", "OPERATOR_EQ",
  "OPERATOR_NE", "OPERATOR_AND", "OPERATOR_OR", "TK_IDENTIFIER",
  "LIT_INTEGER", "LIT_REAL", "LIT_CHAR", "LIT_STRING", "TOKEN_ERROR",
  "','", "'='", "'+'", "'-'", "'*'", "'/'", "'('", "')'", "';'", "'['",
  "']'", "':'", "'#'", "' '", "'{'", "'}'", "'&'", "'<'", "'>'", "'!'",
  "$accept", "program", "decl", "dec", "decvar", "decvetor", "decfunction",
  "decpointer", "decvl", "decv", "typevar", "literal", "paramlist", "rest",
  "name", "cmd", "body", "lcmd", "attribution", "flux_control", "inout",
  "stringSymbol", "print_elem", "exp", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,    44,    61,    43,
      45,    42,    47,    40,    41,    59,    91,    93,    58,    35,
      32,   123,   125,    38,    60,    62,    33
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    49,    49,    50,    50,    50,    50,    51,
      52,    52,    53,    54,    55,    55,    56,    56,    56,    56,
      56,    57,    57,    57,    58,    58,    58,    59,    59,    59,
      59,    60,    60,    60,    60,    61,    62,    62,    62,    62,
      62,    63,    64,    64,    65,    65,    66,    66,    66,    66,
      67,    67,    67,    68,    69,    69,    69,    69,    69,    69,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     1,     1,     5,
       8,     6,     6,     6,     2,     0,     1,     1,     1,     1,
       0,     1,     1,     1,     1,     1,     1,     3,     2,     2,
       0,     4,     3,     3,     0,     1,     1,     1,     1,     1,
       0,     3,     3,     1,     3,     6,     6,     8,     5,     9,
       2,     2,     2,     1,     1,     2,     3,     1,     2,     3,
       1,     4,     2,     2,     1,     1,     3,     3,     3,     3,
       3,     3,     2,     3,     3,     3,     3,     3,     3,     3,
       4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,    21,    22,    23,     0,     2,     4,     5,     6,     7,
       8,     0,     1,     3,    35,     0,     0,     0,     0,    30,
       0,     0,    24,    26,    25,     0,     0,    34,     0,    34,
       0,     0,     9,    34,     0,    28,     0,    29,     0,    13,
      27,     0,    34,    34,    40,    12,    11,    15,    34,    32,
      33,     0,     0,     0,     0,     0,     0,     0,    43,    39,
       0,    36,    37,    38,    16,    18,    17,    19,     0,    15,
      31,     0,     0,     0,    51,    64,    65,     0,     0,     0,
       0,    60,    52,    53,    54,    50,    57,     0,     0,    40,
      41,    10,    14,     0,     0,     0,     0,    62,    63,    72,
      30,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    55,     0,    58,    44,     0,
      42,     0,    40,     0,    73,     0,     0,    74,    75,    76,
      77,    78,    79,    66,    67,    68,    69,    70,    71,    56,
      59,     0,    40,    48,     0,    80,    61,     0,    46,     0,
      45,    40,     0,    47,    40,    49
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,     7,     8,     9,    10,    68,    69,
      11,    27,    28,    35,    81,    58,    59,    60,    61,    62,
      63,    84,    85,    86
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -79
static const yytype_int16 yypact[] =
{
     102,   -79,   -79,   -79,     5,   -79,   102,   -79,   -79,   -79,
     -79,   -14,   -79,   -79,   -79,     1,     3,     4,   156,   299,
       6,   156,   -79,   -79,   -79,    11,     1,    34,    29,    34,
      32,    36,   -79,    34,   299,   -79,    -3,   -79,     2,   -79,
     -79,     1,    34,    34,     0,   -79,   -79,    79,    34,   -79,
     -79,    39,    41,    47,     1,    71,   291,   -25,    46,   -79,
      48,   -79,   -79,   -79,   -79,   -79,   -79,   -79,    56,    79,
     -79,    71,    71,     1,   -79,   -79,   -79,    71,     1,     1,
      71,   -16,   242,   -79,   268,   -79,   105,    71,    71,     0,
     -79,   -79,   -79,   137,   143,    80,   174,   -79,   -79,   242,
     299,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,   291,   -79,   291,   -79,   242,   180,
     -79,   108,     0,    71,   -79,    75,   211,   191,   191,   191,
     191,   265,   265,   170,   170,    21,    21,   242,   242,   -79,
     -79,    88,     0,   -79,    68,   -79,   -79,    71,   110,    71,
     242,     0,   234,   -79,     0,   -79
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -79,   -79,   127,   -79,   -79,   -79,   -79,   -79,    70,   -79,
     -18,     8,    64,    99,   -11,   -78,   129,    57,   -79,   -79,
     -79,   -79,   -39,   -53
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      16,    26,    82,    87,    17,    12,    51,    14,    29,    52,
      53,    88,    54,    55,    56,    33,    41,   100,    93,    94,
     101,    14,    14,    43,    96,    15,    25,    99,    30,    31,
      48,    18,    21,    57,   118,   119,    19,    46,    44,    20,
      47,    44,    42,    74,   143,   115,    32,   117,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,    34,    95,    36,   148,   112,   113,    97,    98,    38,
     144,    39,    71,   153,    72,   139,   155,   140,    57,   149,
      73,    89,    26,   102,   103,   104,   105,   106,   107,    29,
      90,    91,    14,    75,   150,    76,   152,   108,   109,   110,
     111,    64,    65,    66,    77,     1,     2,     3,   123,   145,
      78,    57,   112,   113,    79,   142,   147,    80,   151,    67,
     102,   103,   104,   105,   106,   107,    14,    75,    37,    76,
      83,    57,    40,    13,   108,   109,   110,   111,    77,    92,
      57,    49,    50,    57,    78,   116,   120,    70,    79,   112,
     113,    80,   102,   103,   104,   105,   106,   107,   102,   103,
     104,   105,   106,   107,   125,    45,   108,   109,   110,   111,
       0,   121,   108,   109,   110,   111,     0,   122,    22,    23,
      24,   112,   113,     0,     0,     0,     0,   112,   113,   102,
     103,   104,   105,   106,   107,   102,   103,   104,   105,   106,
     107,   110,   111,   108,   109,   110,   111,     0,   124,   108,
     109,   110,   111,     0,   112,   113,     0,   141,   112,   113,
     108,   109,   110,   111,   112,   113,   102,   103,   104,   105,
     106,   107,     0,     0,     0,   112,   113,     0,     0,     0,
     108,   109,   110,   111,     0,     0,     0,     0,   146,   102,
     103,   104,   105,   106,   107,   112,   113,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,     0,   154,     0,
       0,   108,   109,   110,   111,     0,     0,     0,   112,   113,
     102,   103,   104,   105,     0,     0,   112,   113,     0,    14,
      75,     0,    76,    83,   108,   109,   110,   111,     0,     0,
       0,    77,     1,     2,     3,     0,     0,    78,   114,   112,
     113,    79,    14,    75,    80,    76,    83,     0,     0,     0,
      14,    22,    23,    24,    77,     0,     0,     0,     0,     0,
      78,     0,     0,     0,    79,     0,     0,    80
};

static const yytype_int16 yycheck[] =
{
      11,    19,    55,    28,    15,     0,     6,    21,    19,     9,
      10,    36,    12,    13,    14,    26,    34,    33,    71,    72,
      36,    21,    21,    34,    77,    39,    18,    80,    22,    21,
      41,    28,    28,    44,    87,    88,    33,    35,    41,    36,
      38,    41,    34,    54,   122,    84,    35,    86,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,    27,    73,    34,   142,    44,    45,    78,    79,    37,
     123,    35,    33,   151,    33,   114,   154,   116,    89,    11,
      33,    35,   100,    15,    16,    17,    18,    19,    20,   100,
      42,    35,    21,    22,   147,    24,   149,    29,    30,    31,
      32,    22,    23,    24,    33,     3,     4,     5,    28,    34,
      39,   122,    44,    45,    43,     7,    28,    46,     8,    40,
      15,    16,    17,    18,    19,    20,    21,    22,    29,    24,
      25,   142,    33,     6,    29,    30,    31,    32,    33,    69,
     151,    42,    43,   154,    39,    40,    89,    48,    43,    44,
      45,    46,    15,    16,    17,    18,    19,    20,    15,    16,
      17,    18,    19,    20,   100,    36,    29,    30,    31,    32,
      -1,    34,    29,    30,    31,    32,    -1,    34,    22,    23,
      24,    44,    45,    -1,    -1,    -1,    -1,    44,    45,    15,
      16,    17,    18,    19,    20,    15,    16,    17,    18,    19,
      20,    31,    32,    29,    30,    31,    32,    -1,    34,    29,
      30,    31,    32,    -1,    44,    45,    -1,    37,    44,    45,
      29,    30,    31,    32,    44,    45,    15,    16,    17,    18,
      19,    20,    -1,    -1,    -1,    44,    45,    -1,    -1,    -1,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    37,    15,
      16,    17,    18,    19,    20,    44,    45,    15,    16,    17,
      18,    19,    20,    29,    30,    31,    32,    -1,    34,    -1,
      -1,    29,    30,    31,    32,    -1,    -1,    -1,    44,    45,
      15,    16,    17,    18,    -1,    -1,    44,    45,    -1,    21,
      22,    -1,    24,    25,    29,    30,    31,    32,    -1,    -1,
      -1,    33,     3,     4,     5,    -1,    -1,    39,    40,    44,
      45,    43,    21,    22,    46,    24,    25,    -1,    -1,    -1,
      21,    22,    23,    24,    33,    -1,    -1,    -1,    -1,    -1,
      39,    -1,    -1,    -1,    43,    -1,    -1,    46
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,    48,    49,    50,    51,    52,    53,
      54,    57,     0,    49,    21,    39,    61,    61,    28,    33,
      36,    28,    22,    23,    24,    58,    57,    58,    59,    61,
      22,    58,    35,    61,    27,    60,    34,    60,    37,    35,
      60,    57,    58,    61,    41,    63,    35,    38,    61,    60,
      60,     6,     9,    10,    12,    13,    14,    61,    62,    63,
      64,    65,    66,    67,    22,    23,    24,    40,    55,    56,
      60,    33,    33,    33,    61,    22,    24,    33,    39,    43,
      46,    61,    70,    25,    68,    69,    70,    28,    36,    35,
      42,    35,    55,    70,    70,    61,    70,    61,    61,    70,
      33,    36,    15,    16,    17,    18,    19,    20,    29,    30,
      31,    32,    44,    45,    40,    69,    40,    69,    70,    70,
      64,    34,    34,    28,    34,    59,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    69,
      69,    37,     7,    62,    70,    34,    37,    28,    62,    11,
      70,     8,    70,    62,    34,    62
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
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
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



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

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
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
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
#line 82 "parser.y"
    {(yyval.astree) = (yyvsp[(1) - (1)].astree); astreePrint((yyvsp[(1) - (1)].astree)); root = (yyval.astree);}
    break;

  case 3:
#line 85 "parser.y"
    {(yyval.astree) = astreeCreate(AST_DECLARACAO, 0, (yyvsp[(1) - (2)].astree), (yyvsp[(2) - (2)].astree), 0, 0);}
    break;

  case 4:
#line 86 "parser.y"
    {(yyval.astree) = 0;}
    break;

  case 5:
#line 89 "parser.y"
    {(yyval.astree) = astreeCreate(AST_DECLARACAO, 0, (yyvsp[(1) - (1)].astree), 0, 0, 0);}
    break;

  case 6:
#line 90 "parser.y"
    {(yyval.astree) = astreeCreate(AST_DECLARACAO, 0, (yyvsp[(1) - (1)].astree), 0, 0, 0);}
    break;

  case 7:
#line 91 "parser.y"
    {(yyval.astree) = astreeCreate(AST_DECLARACAO, 0, (yyvsp[(1) - (1)].astree), 0, 0, 0);}
    break;

  case 8:
#line 92 "parser.y"
    {(yyval.astree) = astreeCreate(AST_DECLARACAO, 0, (yyvsp[(1) - (1)].astree), 0, 0, 0);}
    break;

  case 9:
#line 95 "parser.y"
    {(yyval.astree) = astreeCreate(AST_VAR, 0, (yyvsp[(1) - (5)].astree), (yyvsp[(2) - (5)].astree), (yyvsp[(4) - (5)].astree), 0);}
    break;

  case 10:
#line 98 "parser.y"
    {(yyval.astree) = astreeCreate(AST_VECTOR_INIT, (yyvsp[(4) - (8)].symbol), (yyvsp[(1) - (8)].astree), (yyvsp[(2) - (8)].astree), (yyvsp[(7) - (8)].astree), astreeCreate(AST_SYMBOL, (yyvsp[(4) - (8)].symbol), 0, 0, 0, 0));}
    break;

  case 11:
#line 99 "parser.y"
    {(yyval.astree) = astreeCreate(AST_VECTOR_INIT, (yyvsp[(4) - (6)].symbol), (yyvsp[(1) - (6)].astree), (yyvsp[(2) - (6)].astree), 0, astreeCreate(AST_SYMBOL, (yyvsp[(4) - (6)].symbol), 0, 0, 0, 0));}
    break;

  case 12:
#line 102 "parser.y"
    {(yyval.astree) = astreeCreate(AST_DEC_FUNC, 0, (yyvsp[(1) - (6)].astree), (yyvsp[(2) - (6)].astree), (yyvsp[(4) - (6)].astree), (yyvsp[(6) - (6)].astree));}
    break;

  case 13:
#line 104 "parser.y"
    {(yyval.astree) = astreeCreate(AST_DEC_POINTER, 0, (yyvsp[(1) - (6)].astree), (yyvsp[(3) - (6)].astree), (yyvsp[(5) - (6)].astree), 0);}
    break;

  case 14:
#line 106 "parser.y"
    { (yyval.astree) = astreeCreate(ASTREE_INIT_LIST, 0, (yyvsp[(1) - (2)].astree), (yyvsp[(2) - (2)].astree), 0, 0); }
    break;

  case 15:
#line 107 "parser.y"
    { (yyval.astree) = 0; }
    break;

  case 16:
#line 110 "parser.y"
    {(yyval.astree) = astreeCreate(AST_SYMBOL, (yyvsp[(1) - (1)].symbol), 0, 0, 0, 0);}
    break;

  case 17:
#line 111 "parser.y"
    {(yyval.astree) = astreeCreate(AST_SYMBOL, (yyvsp[(1) - (1)].symbol), 0, 0, 0, 0);}
    break;

  case 18:
#line 112 "parser.y"
    {(yyval.astree) = astreeCreate(AST_SYMBOL, (yyvsp[(1) - (1)].symbol), 0, 0, 0, 0);}
    break;

  case 19:
#line 113 "parser.y"
    {(yyval.astree) = astreeCreate(AST_SYMBOL, 0, 0, 0, 0, 0);}
    break;

  case 20:
#line 114 "parser.y"
    {(yyval.astree) = 0;}
    break;

  case 21:
#line 117 "parser.y"
    {(yyval.astree) = astreeCreate(AST_CHAR, 0, 0, 0 , 0, 0);}
    break;

  case 22:
#line 118 "parser.y"
    {(yyval.astree) = astreeCreate(AST_INT, 0, 0, 0, 0, 0);}
    break;

  case 23:
#line 119 "parser.y"
    {(yyval.astree) = astreeCreate(AST_FLOAT, 0, 0, 0, 0, 0);}
    break;

  case 24:
#line 122 "parser.y"
    {(yyval.astree) = astreeCreate(AST_SYMBOL, (yyvsp[(1) - (1)].symbol), 0, 0, 0, 0);}
    break;

  case 25:
#line 123 "parser.y"
    {(yyval.astree) = astreeCreate(AST_SYMBOL, (yyvsp[(1) - (1)].symbol), 0, 0, 0, 0);}
    break;

  case 26:
#line 124 "parser.y"
    {(yyval.astree) = astreeCreate(AST_SYMBOL, (yyvsp[(1) - (1)].symbol), 0, 0, 0, 0);}
    break;

  case 27:
#line 127 "parser.y"
    {(yyval.astree) = astreeCreate(AST_PARAML, 0, (yyvsp[(1) - (3)].astree), (yyvsp[(2) - (3)].astree), (yyvsp[(3) - (3)].astree), 0);}
    break;

  case 28:
#line 128 "parser.y"
    {(yyval.astree) = astreeCreate(AST_PARAML, 0, (yyvsp[(1) - (2)].astree), 0, (yyvsp[(2) - (2)].astree), 0);}
    break;

  case 29:
#line 129 "parser.y"
    {(yyval.astree) = astreeCreate(AST_PARAML, 0, (yyvsp[(1) - (2)].astree), 0, (yyvsp[(2) - (2)].astree), 0);}
    break;

  case 30:
#line 130 "parser.y"
    {(yyval.astree) = 0;}
    break;

  case 31:
#line 133 "parser.y"
    {(yyval.astree) = astreeCreate(AST_REST, 0, (yyvsp[(2) - (4)].astree), (yyvsp[(3) - (4)].astree), (yyvsp[(4) - (4)].astree), 0);}
    break;

  case 32:
#line 134 "parser.y"
    {(yyval.astree) = astreeCreate(AST_REST, 0, (yyvsp[(2) - (3)].astree), (yyvsp[(3) - (3)].astree), 0, 0);}
    break;

  case 33:
#line 135 "parser.y"
    {(yyval.astree) = astreeCreate(AST_REST, 0, (yyvsp[(2) - (3)].astree), (yyvsp[(3) - (3)].astree), 0, 0);}
    break;

  case 34:
#line 136 "parser.y"
    {(yyval.astree) = 0;}
    break;

  case 35:
#line 139 "parser.y"
    {(yyval.astree) = astreeCreate(AST_SYMBOL, (yyvsp[(1) - (1)].symbol), 0, 0, 0, 0);}
    break;

  case 36:
#line 142 "parser.y"
    {(yyval.astree) = astreeCreate(AST_CMD, 0, (yyvsp[(1) - (1)].astree), 0, 0, 0);}
    break;

  case 37:
#line 143 "parser.y"
    {(yyval.astree) = astreeCreate(AST_CMD, 0, (yyvsp[(1) - (1)].astree), 0, 0, 0);}
    break;

  case 38:
#line 144 "parser.y"
    {(yyval.astree) = astreeCreate(AST_CMD, 0, (yyvsp[(1) - (1)].astree), 0, 0, 0);}
    break;

  case 39:
#line 145 "parser.y"
    {(yyval.astree) = astreeCreate(AST_CMD, 0, (yyvsp[(1) - (1)].astree), 0, 0, 0);}
    break;

  case 40:
#line 146 "parser.y"
    {(yyval.astree) = 0;}
    break;

  case 41:
#line 149 "parser.y"
    {(yyval.astree) = astreeCreate(AST_BLOCO, 0, (yyvsp[(2) - (3)].astree), 0, 0, 0);}
    break;

  case 42:
#line 152 "parser.y"
    {(yyval.astree) = astreeCreate(AST_CMDLIST, 0, (yyvsp[(1) - (3)].astree), 0, (yyvsp[(3) - (3)].astree), 0);}
    break;

  case 43:
#line 153 "parser.y"
    {(yyval.astree) = astreeCreate(AST_CMDLIST, 0, (yyvsp[(1) - (1)].astree), 0, 0, 0);}
    break;

  case 44:
#line 156 "parser.y"
    {(yyval.astree) = astreeCreate(AST_ATTRIBUTION, 0, (yyvsp[(1) - (3)].astree), (yyvsp[(3) - (3)].astree), 0, 0);}
    break;

  case 45:
#line 157 "parser.y"
    {(yyval.astree) = astreeCreate(AST_ATTRIBUTION, 0, (yyvsp[(1) - (6)].astree), (yyvsp[(3) - (6)].astree), (yyvsp[(6) - (6)].astree), 0);}
    break;

  case 46:
#line 160 "parser.y"
    {(yyval.astree) = astreeCreate(AST_IF, 0, (yyvsp[(3) - (6)].astree), (yyvsp[(6) - (6)].astree), 0, 0);}
    break;

  case 47:
#line 161 "parser.y"
    {(yyval.astree) = astreeCreate(AST_ELSE, 0, (yyvsp[(3) - (8)].astree), (yyvsp[(6) - (8)].astree), (yyvsp[(8) - (8)].astree), 0);}
    break;

  case 48:
#line 162 "parser.y"
    {(yyval.astree) = astreeCreate(AST_WHILE, 0, (yyvsp[(3) - (5)].astree), (yyvsp[(5) - (5)].astree), 0, 0);}
    break;

  case 49:
#line 163 "parser.y"
    {(yyval.astree) = astreeCreate(AST_FOR, 0, (yyvsp[(3) - (9)].astree), (yyvsp[(5) - (9)].astree), (yyvsp[(7) - (9)].astree), (yyvsp[(9) - (9)].astree));}
    break;

  case 50:
#line 166 "parser.y"
    {(yyval.astree) = astreeCreate(AST_PRINT, 0, (yyvsp[(2) - (2)].astree), 0, 0, 0);}
    break;

  case 51:
#line 167 "parser.y"
    {(yyval.astree) = astreeCreate(AST_READ, 0, (yyvsp[(2) - (2)].astree), 0, 0, 0);}
    break;

  case 52:
#line 168 "parser.y"
    {(yyval.astree) = astreeCreate(AST_RET, 0, (yyvsp[(2) - (2)].astree), 0, 0, 0);}
    break;

  case 53:
#line 171 "parser.y"
    {(yyval.astree) = astreeCreate(AST_SYMBOL, (yyvsp[(1) - (1)].symbol), 0, 0, 0, 0);}
    break;

  case 54:
#line 174 "parser.y"
    {(yyval.astree) = astreeCreate(AST_PRINTL,0, (yyvsp[(1) - (1)].astree), 0, 0, 0);}
    break;

  case 55:
#line 175 "parser.y"
    {(yyval.astree) = astreeCreate(AST_PRINTL,0, (yyvsp[(1) - (2)].astree), (yyvsp[(2) - (2)].astree), 0, 0);}
    break;

  case 56:
#line 176 "parser.y"
    {(yyval.astree) = astreeCreate(AST_PRINTL,0, (yyvsp[(1) - (3)].astree), (yyvsp[(3) - (3)].astree), 0, 0);}
    break;

  case 57:
#line 177 "parser.y"
    {(yyval.astree) = astreeCreate(AST_PRINTL, 0, (yyvsp[(1) - (1)].astree), 0, 0, 0);}
    break;

  case 58:
#line 178 "parser.y"
    {(yyval.astree) = astreeCreate(AST_PRINTL, 0, (yyvsp[(1) - (2)].astree), (yyvsp[(2) - (2)].astree), 0, 0);}
    break;

  case 59:
#line 179 "parser.y"
    {(yyval.astree) = astreeCreate(AST_PRINTL, 0, (yyvsp[(1) - (3)].astree), (yyvsp[(3) - (3)].astree), 0, 0);}
    break;

  case 60:
#line 182 "parser.y"
    {(yyval.astree) = (yyvsp[(1) - (1)].astree);}
    break;

  case 61:
#line 183 "parser.y"
    {(yyval.astree) = astreeCreate(AST_EXPR_VECTOR, 0, (yyvsp[(1) - (4)].astree), (yyvsp[(3) - (4)].astree), 0, 0);}
    break;

  case 62:
#line 184 "parser.y"
    {(yyval.astree) = astreeCreate(AST_HASHTAG, 0, (yyvsp[(2) - (2)].astree), 0, 0, 0);}
    break;

  case 63:
#line 185 "parser.y"
    {(yyval.astree) = astreeCreate(AST_E, 0, (yyvsp[(2) - (2)].astree), 0, 0, 0);}
    break;

  case 64:
#line 186 "parser.y"
    {(yyval.astree) = astreeCreate(AST_SYMBOL, (yyvsp[(1) - (1)].symbol), 0, 0, 0, 0); }
    break;

  case 65:
#line 187 "parser.y"
    {(yyval.astree) = astreeCreate(AST_SYMBOL, (yyvsp[(1) - (1)].symbol), 0, 0, 0, 0); }
    break;

  case 66:
#line 188 "parser.y"
    {(yyval.astree) = astreeCreate(AST_ADD, 0, (yyvsp[(1) - (3)].astree), (yyvsp[(3) - (3)].astree), 0, 0);}
    break;

  case 67:
#line 189 "parser.y"
    {(yyval.astree) = astreeCreate(AST_SUB, 0, (yyvsp[(1) - (3)].astree), (yyvsp[(3) - (3)].astree), 0, 0);}
    break;

  case 68:
#line 190 "parser.y"
    {(yyval.astree) = astreeCreate(AST_MULT, 0, (yyvsp[(1) - (3)].astree), (yyvsp[(3) - (3)].astree), 0, 0);}
    break;

  case 69:
#line 191 "parser.y"
    {(yyval.astree) = astreeCreate(AST_DIV, 0, (yyvsp[(1) - (3)].astree), (yyvsp[(3) - (3)].astree), 0, 0);}
    break;

  case 70:
#line 192 "parser.y"
    {(yyval.astree) = astreeCreate(AST_LESS, 0, (yyvsp[(1) - (3)].astree), (yyvsp[(3) - (3)].astree), 0, 0);}
    break;

  case 71:
#line 193 "parser.y"
    {(yyval.astree) = astreeCreate(AST_GREATER, 0, (yyvsp[(1) - (3)].astree), (yyvsp[(3) - (3)].astree), 0, 0);}
    break;

  case 72:
#line 194 "parser.y"
    {(yyval.astree) = astreeCreate(AST_NEG, 0, (yyvsp[(2) - (2)].astree), 0 , 0, 0);}
    break;

  case 73:
#line 195 "parser.y"
    {(yyval.astree) = astreeCreate(AST_EXPR, 0, (yyvsp[(2) - (3)].astree), 0 , 0, 0);}
    break;

  case 74:
#line 196 "parser.y"
    {(yyval.astree) = astreeCreate(AST_LE, 0, (yyvsp[(1) - (3)].astree), (yyvsp[(3) - (3)].astree), 0, 0);}
    break;

  case 75:
#line 197 "parser.y"
    {(yyval.astree) = astreeCreate(AST_GE, 0, (yyvsp[(1) - (3)].astree), (yyvsp[(3) - (3)].astree), 0, 0);}
    break;

  case 76:
#line 198 "parser.y"
    {(yyval.astree) = astreeCreate(AST_EQ, 0, (yyvsp[(1) - (3)].astree), (yyvsp[(3) - (3)].astree), 0, 0);}
    break;

  case 77:
#line 199 "parser.y"
    {(yyval.astree) = astreeCreate(AST_NE, 0, (yyvsp[(1) - (3)].astree), (yyvsp[(3) - (3)].astree), 0, 0);}
    break;

  case 78:
#line 200 "parser.y"
    {(yyval.astree) = astreeCreate(AST_AND, 0, (yyvsp[(1) - (3)].astree), (yyvsp[(3) - (3)].astree), 0, 0);}
    break;

  case 79:
#line 201 "parser.y"
    {(yyval.astree) = astreeCreate(AST_OR, 0, (yyvsp[(1) - (3)].astree), (yyvsp[(3) - (3)].astree), 0, 0);}
    break;

  case 80:
#line 202 "parser.y"
    {(yyval.astree) = astreeCreate(AST_EXPR_FUNC, 0, (yyvsp[(1) - (4)].astree), (yyvsp[(3) - (4)].astree), 0, 0);}
    break;


/* Line 1267 of yacc.c.  */
#line 1943 "y.tab.c"
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
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  if (yyn == YYFINAL)
    YYACCEPT;

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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
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


#line 206 "parser.y"


int main(int argc, char* argv[])
{
if(!(FileTree = fopen(argv[2],"w")))
  {
    fprintf(stderr, "Cannot Create: %s \n",argv[2]);
    exit(2);
  }
  if (argc > 1 && (yyin = fopen(argv[1], "r")))
  {
  initMe();
 	 yydebug = 0;
    if(yyparse() == 0)
    {
      printf("Sucess, this is a program!\nLines: %d\n", getLineNumber());
        hashPrint();
    }
  } else {
    printf("Usage: ./etapa2 input_filepath\n");
  }
  printf("%d", root->type);

}

  int yyerror(char *s)
  {
    fprintf(stderr, "line %d: %s\n", getLineNumber(), s);
//    hashPrint();
    exit(3);
  }
