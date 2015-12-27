/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 4 "yacc.y" /* yacc.c:339  */

    #include "main.h"
    #include "../db/sql.h"
    extern "C"
    {
        void yyerror(const char *s);
        extern int yylex(void);
    }

#line 76 "yacc.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "yacc.tab.h".  */
#ifndef YY_YY_YACC_TAB_H_INCLUDED
# define YY_YY_YACC_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INTEGER = 258,
    DATABASE = 259,
    SHOW = 260,
    DATABASES = 261,
    TABLES = 262,
    CHECK = 263,
    IN = 264,
    IDENTIFIER = 265,
    INSERT = 266,
    INTO = 267,
    VALUES = 268,
    YIN = 269,
    VALUEIT = 270,
    CREATE = 271,
    TABLE = 272,
    PRIMARY = 273,
    KEY = 274,
    TYPE = 275,
    NULLL = 276,
    IS = 277,
    KIND = 278,
    IOKIND = 279,
    SELECT = 280,
    FROM = 281,
    WHERE = 282,
    EXPRESSION = 283,
    JOIN = 284,
    ON = 285,
    USE = 286,
    IF = 287,
    EXISTS = 288,
    DROP = 289,
    JUDGEOP = 290,
    CONNOP = 291,
    UPDATE = 292,
    SET = 293,
    DESC = 294,
    DELETE = 295,
    OPERATOR = 296
  };
#endif

/* Value type.  */


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_YACC_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 164 "yacc.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  41
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   219

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  89
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  207

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    52,     2,     2,     2,    41,     2,     2,
      53,    54,    48,    46,    50,    47,    45,    49,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    51,
      44,    42,    43,    59,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    55,     2,    56,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    57,     2,    58,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    60
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    54,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    69,    74,    80,    86,    91,
      97,   104,   110,   116,   121,   127,   132,   145,   158,   171,
     184,   190,   196,   202,   208,   219,   223,   227,   231,   235,
     238,   243,   248,   255,   259,   263,   267,   272,   276,   280,
     281,   284,   289,   296,   300,   304,   308,   311,   315,   319,
     345,   351,   355,   361,   367,   371,   378,   383,   384,   387,
     394,   401,   407,   411,   413,   419,   425,   434,   443,   450,
     455,   456,   457,   458,   461,   466,   474,   479,   487,   491
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGER", "DATABASE", "SHOW",
  "DATABASES", "TABLES", "CHECK", "IN", "IDENTIFIER", "INSERT", "INTO",
  "VALUES", "YIN", "VALUEIT", "CREATE", "TABLE", "PRIMARY", "KEY", "TYPE",
  "NULLL", "IS", "KIND", "IOKIND", "SELECT", "FROM", "WHERE", "EXPRESSION",
  "JOIN", "ON", "USE", "IF", "EXISTS", "DROP", "JUDGEOP", "CONNOP",
  "UPDATE", "SET", "DESC", "DELETE", "'%'", "'='", "'>'", "'<'", "'.'",
  "'+'", "'-'", "'*'", "'/'", "','", "';'", "'!'", "'('", "')'", "'['",
  "']'", "'{'", "'}'", "'?'", "OPERATOR", "$accept", "sqllist", "usedbsql",
  "dropdbsql", "showdbsql", "createdbsql", "droptbsql", "descsql",
  "showtbsql", "createtbsql", "tablecon", "checkval", "insertsql",
  "tableitems", "valuesql", "valueitems", "valueitem", "selectsql",
  "attrsql", "attritem", "tables", "condsql", "conditem", "expression",
  "expr", "exprop", "deletesql", "updatesql", "setsql", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,    37,    61,    62,    60,    46,    43,    45,    42,    47,
      44,    59,    33,    40,    41,    91,    93,   123,   125,    63,
     296
};
# endif

#define YYPACT_NINF -139

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-139)))

#define YYTABLE_NINF -80

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      56,    67,    13,    59,     1,    19,    61,    52,    11,    44,
      77,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    69,    32,    46,    84,   102,   110,   113,
      80,  -139,   105,    86,   127,    87,   129,   130,   104,   131,
     133,  -139,  -139,  -139,  -139,  -139,  -139,  -139,  -139,  -139,
    -139,  -139,  -139,  -139,    93,  -139,  -139,    94,    -9,    95,
      96,   137,   138,     1,    99,  -139,   100,   101,   143,   106,
     -14,  -139,  -139,   107,   144,  -139,   103,  -139,   108,    -8,
    -139,  -139,  -139,  -139,    47,   109,    -3,  -139,   143,  -139,
      18,  -139,   111,   112,   114,   135,   145,   117,   138,   143,
    -139,    39,    -1,   143,   143,  -139,   118,   120,  -139,  -139,
     116,   115,   144,   149,   153,   -18,   119,  -139,  -139,   122,
    -139,   150,    37,  -139,     2,     0,    81,    42,    43,  -139,
     123,  -139,   143,    82,    18,  -139,   107,   166,   155,   103,
     174,  -139,   168,  -139,  -139,  -139,    43,    68,  -139,  -139,
    -139,  -139,   176,     2,     2,     4,     5,  -139,  -139,   107,
    -139,  -139,  -139,   128,   -24,  -139,   126,   132,  -139,  -139,
      43,    43,  -139,     0,  -139,     0,  -139,    65,   103,  -139,
     -16,   134,    70,    72,   139,   140,   141,  -139,   161,   103,
    -139,  -139,  -139,  -139,    65,    65,   142,   -23,  -139,  -139,
    -139,   147,   103,  -139,   103,  -139,  -139
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     0,     0,     0,     0,     0,     0,     0,
      56,    53,     0,    55,     0,     0,     0,     0,     0,     0,
       0,     1,     3,     4,     6,     5,     8,    14,     9,     7,
      10,    11,    12,    13,     0,    18,    23,     0,     0,     0,
       0,     0,     0,     0,     0,    16,     0,     0,     0,     0,
       0,    19,    24,     0,     0,    20,     0,    57,    59,     0,
      54,    15,    17,    21,     0,    89,     0,    22,     0,    85,
       0,    42,    44,     0,     0,     0,     0,     0,     0,     0,
      52,     0,    67,     0,     0,    87,     0,    61,    49,    50,
       0,    48,     0,     0,     0,     0,     0,    25,    58,     0,
      62,     0,    72,    68,     0,    67,    66,    64,    73,    88,
       0,    84,     0,     0,     0,    43,     0,     0,     0,     0,
       0,    33,     0,    51,    63,    79,    71,     0,    80,    81,
      82,    83,     0,     0,     0,     0,     0,    86,    60,     0,
      46,    47,    41,     0,     0,    29,     0,     0,    78,    65,
      69,    70,    74,    67,    75,    67,    45,     0,     0,    32,
       0,     0,     0,     0,    40,    39,     0,    28,     0,     0,
      31,    36,    76,    77,     0,     0,     0,     0,    27,    38,
      37,    35,     0,    30,     0,    26,    34
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -139,    88,  -139,  -139,  -139,  -139,  -139,  -139,  -139,  -139,
    -138,   -60,  -139,    71,  -120,    50,  -139,  -139,   124,    -4,
     121,   -82,   -58,  -119,  -112,  -139,  -139,  -139,    89
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      97,   186,    19,    93,    91,   110,   111,    20,    32,    84,
      79,   106,   107,   127,   128,   152,    21,    22,    86
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      33,   165,   122,   122,    73,   145,   147,   172,   174,    30,
      85,    30,   146,    88,   123,   123,   162,   119,   138,    99,
     188,   108,   130,    34,   104,    27,   178,   202,    39,    35,
     179,   203,   139,   109,   189,   140,   141,    89,   190,   176,
     187,   170,   171,   100,    74,    85,   124,   124,   105,    31,
     158,   198,   125,   125,   182,   125,   183,   173,   175,    33,
     120,     1,    38,    28,   205,    36,   206,     2,   184,   101,
      40,    23,     3,    24,    25,   121,    29,    41,    37,    54,
     185,     4,   102,    55,    26,   -79,   -79,     5,   153,   154,
       6,   155,   156,     7,    57,     8,     9,    56,   126,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    94,    58,    95,   153,   154,   153,   154,   153,   154,
      59,    96,   168,    60,   192,    61,   193,   148,   149,   150,
     151,    62,   159,   160,   199,   200,    63,    64,    65,    66,
      67,    69,    68,    70,    71,    72,    75,    77,    78,    76,
      81,    82,    83,    30,    92,   115,   132,    87,    98,   103,
      90,   112,   136,   137,   116,   134,   113,   114,   117,   131,
     133,   144,   142,   143,   157,   163,   164,   166,   167,   169,
     180,   177,   197,   135,   161,     0,   181,    80,   191,   194,
     195,     0,   129,     0,     0,   196,   201,   204,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   118
};

static const yytype_int16 yycheck[] =
{
       4,   139,     3,     3,    13,     3,   125,     3,     3,    10,
      68,    10,   124,    27,    15,    15,   136,    99,    36,    27,
      36,     3,   104,     4,    27,    12,    50,    50,    17,    10,
      54,    54,    50,    15,    50,    53,    54,    51,    54,   159,
     178,   153,   154,    51,    53,   103,    47,    47,    51,    48,
     132,   189,    53,    53,   173,    53,   175,    53,    53,    63,
      21,     5,    10,     4,   202,     4,   204,    11,     3,    22,
      26,     4,    16,     6,     7,    36,    17,     0,    17,    10,
      15,    25,    35,    51,    17,    48,    49,    31,    46,    47,
      34,    48,    49,    37,    10,    39,    40,    51,   102,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,     8,    10,    10,    46,    47,    46,    47,    46,    47,
      10,    18,    54,    10,    54,    45,    54,    46,    47,    48,
      49,    26,    50,    51,   194,   195,    50,    10,    51,    10,
      10,    10,    38,    10,    51,    51,    51,    10,    10,    53,
      51,    51,    51,    10,    10,    20,    36,    51,    50,    50,
      53,    50,    13,    10,    19,    50,    54,    53,    51,    51,
      54,    21,    53,    51,    51,     9,    21,     3,    10,     3,
      54,    53,    21,   112,   134,    -1,    54,    63,    54,    50,
      50,    -1,   103,    -1,    -1,    54,    54,    50,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    98
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,    11,    16,    25,    31,    34,    37,    39,    40,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    73,
      78,    87,    88,     4,     6,     7,    17,    12,     4,    17,
      10,    48,    79,    80,     4,    10,     4,    17,    10,    17,
      26,     0,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    10,    51,    51,    10,    10,    10,
      10,    45,    26,    50,    10,    51,    10,    10,    38,    10,
      10,    51,    51,    13,    53,    51,    53,    10,    10,    81,
      79,    51,    51,    51,    80,    83,    89,    51,    27,    51,
      53,    75,    10,    74,     8,    10,    18,    71,    50,    27,
      51,    22,    35,    50,    27,    51,    82,    83,     3,    15,
      76,    77,    50,    54,    53,    20,    19,    51,    81,    82,
      21,    36,     3,    15,    47,    53,    80,    84,    85,    89,
      82,    51,    36,    54,    50,    74,    13,    10,    36,    50,
      53,    54,    53,    51,    21,     3,    85,    84,    46,    47,
      48,    49,    86,    46,    47,    48,    49,    51,    82,    50,
      51,    76,    75,     9,    21,    71,     3,    10,    54,     3,
      85,    85,     3,    53,     3,    53,    75,    53,    50,    54,
      54,    54,    84,    84,     3,    15,    72,    71,    36,    50,
      54,    54,    54,    54,    50,    50,    54,    21,    71,    72,
      72,    54,    50,    54,    50,    71,    71
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    61,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    63,    63,    64,    65,    65,
      66,    67,    68,    69,    69,    70,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    72,    72,    72,
      72,    73,    73,    74,    74,    75,    75,    76,    76,    77,
      77,    78,    78,    79,    79,    79,    80,    80,    81,    81,
      82,    82,    83,    83,    83,    83,    83,    84,    84,    84,
      84,    84,    84,    84,    85,    85,    85,    85,    85,    85,
      86,    86,    86,    86,    87,    87,    88,    88,    89,    89
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     4,     3,     4,     3,     4,
       4,     4,     4,     3,     4,     6,     9,     7,     6,     4,
       8,     6,     5,     3,    10,     8,     6,     3,     3,     1,
       1,     8,     5,     3,     1,     5,     4,     3,     1,     1,
       1,     7,     5,     1,     3,     1,     1,     3,     3,     1,
       3,     1,     3,     4,     3,     5,     3,     0,     1,     3,
       3,     2,     1,     1,     3,     3,     5,     5,     3,     1,
       1,     1,     1,     1,     6,     4,     7,     5,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

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
#line 54 "yacc.y" /* yacc.c:1646  */
    {}
#line 1380 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 69 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_usedb).init((yyvsp[-1].m_sId));
        (yyval.m_usedb).display();
        (yyval.m_usedb).work();
    }
#line 1390 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 74 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_usedb).init((yyvsp[-1].m_sId));
        (yyval.m_usedb).display();
        (yyval.m_usedb).work();
    }
#line 1400 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 80 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_dropdb).init((yyvsp[-1].m_sId));
        (yyval.m_dropdb).display();
        (yyval.m_dropdb).work();
    }
#line 1410 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 86 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_showdb).init("");
        (yyval.m_showdb).display();
        (yyval.m_showdb).work();
    }
#line 1420 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 91 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_showdb).init((yyvsp[-1].m_sId));
        (yyval.m_showdb).display();
        (yyval.m_showdb).work();
    }
#line 1430 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 97 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_credb).init((yyvsp[-1].m_sId));
        (yyval.m_credb).display();
        (yyval.m_credb).work();
    }
#line 1440 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 104 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_droptb).init((yyvsp[-1].m_sId));
        (yyval.m_droptb).display();
        (yyval.m_droptb).work();
    }
#line 1450 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 110 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_desc).init((yyvsp[-1].m_sId));
        (yyval.m_desc).display();
        (yyval.m_desc).work();
    }
#line 1460 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 116 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_showtb).init("");
        (yyval.m_showtb).display();
        (yyval.m_showtb).work();
    }
#line 1470 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 121 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_showtb).init((yyvsp[-1].m_sId));
        (yyval.m_showtb).display();
        (yyval.m_showtb).work();
    }
#line 1480 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 127 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_cretb).init((yyvsp[-3].m_sId), (yyvsp[-1].m_con));
        (yyval.m_cretb).work();
    }
#line 1489 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 132 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_con).length.push_back((yyvsp[-5].m_sId));
        (yyval.m_con).name.push_back((yyvsp[-8].m_sId));
        (yyval.m_con).type.push_back((yyvsp[-7].m_sId));
        (yyval.m_con).notNull.push_back(true);
        (yyval.m_con).length.insert((yyval.m_con).length.end(), (yyvsp[0].m_con).length.begin(), (yyvsp[0].m_con).length.end());
        (yyval.m_con).name.insert((yyval.m_con).name.end(), (yyvsp[0].m_con).name.begin(), (yyvsp[0].m_con).name.end());
        (yyval.m_con).type.insert((yyval.m_con).type.end(), (yyvsp[0].m_con).type.begin(), (yyvsp[0].m_con).type.end());
        (yyval.m_con).notNull.insert((yyval.m_con).notNull.end(), (yyvsp[0].m_con).notNull.begin(), (yyvsp[0].m_con).notNull.end());
        (yyval.m_con).checkAttrs = (yyvsp[0].m_con).checkAttrs;
        (yyval.m_con).checkVal = (yyvsp[0].m_con).checkVal;
        (yyval.m_con).priKey = (yyvsp[0].m_con).priKey;
    }
#line 1507 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 145 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_con).length.push_back((yyvsp[-3].m_sId));
        (yyval.m_con).name.push_back((yyvsp[-6].m_sId));
        (yyval.m_con).type.push_back((yyvsp[-5].m_sId));
        (yyval.m_con).notNull.push_back(false);
        (yyval.m_con).length.insert((yyval.m_con).length.end(), (yyvsp[0].m_con).length.begin(), (yyvsp[0].m_con).length.end());
        (yyval.m_con).name.insert((yyval.m_con).name.end(), (yyvsp[0].m_con).name.begin(), (yyvsp[0].m_con).name.end());
        (yyval.m_con).type.insert((yyval.m_con).type.end(), (yyvsp[0].m_con).type.begin(), (yyvsp[0].m_con).type.end());
        (yyval.m_con).notNull.insert((yyval.m_con).notNull.end(), (yyvsp[0].m_con).notNull.begin(), (yyvsp[0].m_con).notNull.end());
        (yyval.m_con).checkAttrs = (yyvsp[0].m_con).checkAttrs;
        (yyval.m_con).checkVal = (yyvsp[0].m_con).checkVal;
        (yyval.m_con).priKey = (yyvsp[0].m_con).priKey;
    }
#line 1525 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 158 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_con).length.push_back("0");
        (yyval.m_con).name.push_back((yyvsp[-5].m_sId));
        (yyval.m_con).type.push_back((yyvsp[-4].m_sId));
        (yyval.m_con).notNull.push_back(true);
        (yyval.m_con).length.insert((yyval.m_con).length.end(), (yyvsp[0].m_con).length.begin(), (yyvsp[0].m_con).length.end());
        (yyval.m_con).name.insert((yyval.m_con).name.end(), (yyvsp[0].m_con).name.begin(), (yyvsp[0].m_con).name.end());
        (yyval.m_con).type.insert((yyval.m_con).type.end(), (yyvsp[0].m_con).type.begin(), (yyvsp[0].m_con).type.end());
        (yyval.m_con).notNull.insert((yyval.m_con).notNull.end(), (yyvsp[0].m_con).notNull.begin(), (yyvsp[0].m_con).notNull.end());
        (yyval.m_con).checkAttrs = (yyvsp[0].m_con).checkAttrs;
        (yyval.m_con).checkVal = (yyvsp[0].m_con).checkVal;
        (yyval.m_con).priKey = (yyvsp[0].m_con).priKey;
    }
#line 1543 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 171 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_con).length.push_back("0");
        (yyval.m_con).name.push_back((yyvsp[-3].m_sId));
        (yyval.m_con).type.push_back((yyvsp[-2].m_sId));
        (yyval.m_con).notNull.push_back(false);
        (yyval.m_con).length.insert((yyval.m_con).length.end(), (yyvsp[0].m_con).length.begin(), (yyvsp[0].m_con).length.end());
        (yyval.m_con).name.insert((yyval.m_con).name.end(), (yyvsp[0].m_con).name.begin(), (yyvsp[0].m_con).name.end());
        (yyval.m_con).type.insert((yyval.m_con).type.end(), (yyvsp[0].m_con).type.begin(), (yyvsp[0].m_con).type.end());
        (yyval.m_con).notNull.insert((yyval.m_con).notNull.end(), (yyvsp[0].m_con).notNull.begin(), (yyvsp[0].m_con).notNull.end());
        (yyval.m_con).checkAttrs = (yyvsp[0].m_con).checkAttrs;
        (yyval.m_con).checkVal = (yyvsp[0].m_con).checkVal;
        (yyval.m_con).priKey = (yyvsp[0].m_con).priKey;
    }
#line 1561 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 184 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_con).name.push_back((yyvsp[-7].m_sId));
        (yyval.m_con).type.push_back((yyvsp[-6].m_sId));
        (yyval.m_con).length.push_back((yyvsp[-4].m_sId));
        (yyval.m_con).notNull.push_back(true);
    }
#line 1572 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 190 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_con).name.push_back((yyvsp[-5].m_sId));
        (yyval.m_con).type.push_back((yyvsp[-4].m_sId));
        (yyval.m_con).length.push_back((yyvsp[-2].m_sId));
        (yyval.m_con).notNull.push_back(false);
    }
#line 1583 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 196 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_con).name.push_back((yyvsp[-4].m_sId));
        (yyval.m_con).type.push_back((yyvsp[-3].m_sId));
        (yyval.m_con).length.push_back("0");
        (yyval.m_con).notNull.push_back(true);
    }
#line 1594 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 202 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_con).name.push_back((yyvsp[-2].m_sId));
        (yyval.m_con).type.push_back((yyvsp[-1].m_sId));
        (yyval.m_con).length.push_back("0");
        (yyval.m_con).notNull.push_back(false);
    }
#line 1605 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 208 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_con).checkAttrs.push_back((yyvsp[-7].m_sId));
        (yyval.m_con).checkVal.push_back((yyvsp[-4].m_strv));
        (yyval.m_con).checkAttrs.insert((yyval.m_con).checkAttrs.end(), (yyvsp[0].m_con).checkAttrs.begin(), (yyvsp[0].m_con).checkAttrs.end());
        (yyval.m_con).checkVal.insert((yyval.m_con).checkVal.end(), (yyvsp[0].m_con).checkVal.begin(), (yyvsp[0].m_con).checkVal.end());
        (yyval.m_con).name = (yyvsp[0].m_con).name;
        (yyval.m_con).type = (yyvsp[0].m_con).type;
        (yyval.m_con).length = (yyvsp[0].m_con).length;
        (yyval.m_con).notNull = (yyvsp[0].m_con).notNull;
        (yyval.m_con).priKey = (yyvsp[0].m_con).priKey;
    }
#line 1621 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 219 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_con).checkAttrs.push_back((yyvsp[-5].m_sId));
        (yyval.m_con).checkVal.push_back((yyvsp[-2].m_strv));
    }
#line 1630 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 223 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_con).priKey = (yyvsp[-2].m_sId);
    }
#line 1638 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 227 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_strv).push_back((yyvsp[-2].m_sId));
        (yyval.m_strv).insert((yyval.m_strv).end(), (yyvsp[0].m_strv).begin(), (yyvsp[0].m_strv).end());
    }
#line 1647 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 231 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_strv).push_back((yyvsp[-2].m_sId));
        (yyval.m_strv).insert((yyval.m_strv).end(), (yyvsp[0].m_strv).begin(), (yyvsp[0].m_strv).end());
    }
#line 1656 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 235 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_strv).push_back((yyvsp[0].m_sId));
    }
#line 1664 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 238 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_strv).push_back((yyvsp[0].m_sId));
    }
#line 1672 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 243 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_ins).init((yyvsp[-5].m_sId), (yyvsp[-3].m_strv), (yyvsp[0].m_vecv));
        (yyval.m_ins).display();
        (yyval.m_ins).work();
    }
#line 1682 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 248 "yacc.y" /* yacc.c:1646  */
    {
        vector<string> temp;
        (yyval.m_ins).init((yyvsp[-2].m_sId), temp, (yyvsp[0].m_vecv));
        (yyval.m_ins).display();
        (yyval.m_ins).work();
    }
#line 1693 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 255 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_strv).push_back((yyvsp[-2].m_sId));
        (yyval.m_strv).insert((yyval.m_strv).end(), (yyvsp[0].m_strv).begin(), (yyvsp[0].m_strv).end());
    }
#line 1702 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 259 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_strv).push_back((yyvsp[0].m_sId));
    }
#line 1710 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 263 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_vecv).push_back((yyvsp[-3].m_strv));
        (yyval.m_vecv).insert((yyval.m_vecv).end(), (yyvsp[0].m_vecv).begin(), (yyvsp[0].m_vecv).end());
    }
#line 1719 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 268 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_vecv).push_back((yyvsp[-2].m_strv));
    }
#line 1727 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 272 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_strv).push_back((yyvsp[-2].m_sId));
        (yyval.m_strv).insert((yyval.m_strv).end(), (yyvsp[0].m_strv).begin(), (yyvsp[0].m_strv).end());
    }
#line 1736 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 276 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_strv).push_back((yyvsp[0].m_sId));
    }
#line 1744 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 280 "yacc.y" /* yacc.c:1646  */
    {(yyval.m_sId) = (yyvsp[0].m_sId);}
#line 1750 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 281 "yacc.y" /* yacc.c:1646  */
    {(yyval.m_sId) = (yyvsp[0].m_sId);}
#line 1756 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 284 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_sel).init((yyvsp[-5].m_attr), (yyvsp[-3].m_strv), (yyvsp[-1].m_cond));
        (yyval.m_sel).display();
        (yyval.m_sel).work();
    }
#line 1766 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 289 "yacc.y" /* yacc.c:1646  */
    {
        CondSql cond;
        (yyval.m_sel).init((yyvsp[-3].m_attr), (yyvsp[-1].m_strv), cond);
        (yyval.m_sel).display();
        (yyval.m_sel).work();
    }
#line 1777 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 296 "yacc.y" /* yacc.c:1646  */
    {
        AttrItem item("*", "*");
        (yyval.m_attr).push_back(item);
    }
#line 1786 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 300 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_attr) = (yyvsp[0].m_attr);
        (yyval.m_attr).push_back((yyvsp[-2].m_sitem));
    }
#line 1795 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 304 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_attr).push_back((yyvsp[0].m_sitem));
    }
#line 1803 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 308 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_sitem).init("", (yyvsp[0].m_sId));
    }
#line 1811 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 311 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_sitem).init((yyvsp[-2].m_sId), (yyvsp[0].m_sId));
    }
#line 1819 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 315 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_strv).push_back((yyvsp[-2].m_sId));
        (yyval.m_strv).insert((yyval.m_strv).end(), (yyvsp[0].m_strv).begin(), (yyvsp[0].m_strv).end());
    }
#line 1828 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 319 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_strv).push_back((yyvsp[0].m_sId));
    }
#line 1836 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 345 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_cond).conditions.push_back((yyvsp[-2].m_citem));
        (yyval.m_cond).connops.push_back((yyvsp[-1].m_sId));
        (yyval.m_cond).conditions.insert((yyval.m_cond).conditions.end(), (yyvsp[0].m_cond).conditions.begin(), (yyvsp[0].m_cond).conditions.end());
        (yyval.m_cond).connops.insert((yyval.m_cond).connops.end(), (yyvsp[0].m_cond).connops.begin(), (yyvsp[0].m_cond).connops.end());
    }
#line 1847 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 351 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_cond).conditions.push_back((yyvsp[0].m_citem));
    }
#line 1855 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 355 "yacc.y" /* yacc.c:1646  */
    {
        AttrItem attr2;
        Expression expre;
        expre.str = "NULLLL";
        (yyval.m_citem).init("=", (yyvsp[-2].m_sitem), attr2, expre);
    }
#line 1866 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 361 "yacc.y" /* yacc.c:1646  */
    {
        AttrItem attr2;
        Expression expre;
        expre.str = "NULLLL";
        (yyval.m_citem).init(">", (yyvsp[-3].m_sitem), attr2, expre);
    }
#line 1877 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 367 "yacc.y" /* yacc.c:1646  */
    {
        AttrItem attr2;
        (yyval.m_citem).init((yyvsp[-1].m_sId), (yyvsp[-2].m_sitem), attr2, (yyvsp[0].m_expr));
    }
#line 1886 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 371 "yacc.y" /* yacc.c:1646  */
    {
        Expression expre;
        expre.numbers.push_back((yyvsp[0].m_sId));
        expre.ops.push_back((yyvsp[-1].m_sId));
        expre.value = 0;
        (yyval.m_citem).init((yyvsp[-3].m_sId), (yyvsp[-4].m_sitem), (yyvsp[-2].m_sitem), expre);
    }
#line 1898 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 378 "yacc.y" /* yacc.c:1646  */
    {
        Expression expre;
        (yyval.m_citem).init((yyvsp[-1].m_sId), (yyvsp[-2].m_sitem), (yyvsp[0].m_sitem), expre);
    }
#line 1907 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 383 "yacc.y" /* yacc.c:1646  */
    {}
#line 1913 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 384 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_expr).str = (yyvsp[0].m_sId);
    }
#line 1921 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 387 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_expr) = (yyvsp[-2].m_expr);
        (yyval.m_expr).ops.push_back((yyvsp[-1].m_sId));
        (yyval.m_expr).numbers.insert((yyval.m_expr).numbers.end(), (yyvsp[0].m_expr).numbers.begin(), (yyvsp[0].m_expr).numbers.end());
        (yyval.m_expr).ops.insert((yyval.m_expr).ops.end(), (yyvsp[0].m_expr).ops.begin(), (yyvsp[0].m_expr).ops.end());
        (yyval.m_expr).value = (yyvsp[-2].m_expr).value+(yyvsp[0].m_expr).value;
    }
#line 1933 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 394 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_expr) = (yyvsp[-2].m_expr);
        (yyval.m_expr).ops.push_back((yyvsp[-1].m_sId));
        (yyval.m_expr).numbers.insert((yyval.m_expr).numbers.end(), (yyvsp[0].m_expr).numbers.begin(), (yyvsp[0].m_expr).numbers.end());
        (yyval.m_expr).ops.insert((yyval.m_expr).ops.end(), (yyvsp[0].m_expr).ops.begin(), (yyvsp[0].m_expr).ops.end());
        (yyval.m_expr).value = (yyvsp[-2].m_expr).value-(yyvsp[0].m_expr).value;
    }
#line 1945 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 401 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_expr).ops.push_back((yyvsp[-1].m_sId));
        (yyval.m_expr).numbers.insert((yyval.m_expr).numbers.end(), (yyvsp[0].m_expr).numbers.begin(), (yyvsp[0].m_expr).numbers.end());
        (yyval.m_expr).ops.insert((yyval.m_expr).ops.end(), (yyvsp[0].m_expr).ops.begin(), (yyvsp[0].m_expr).ops.end());
        (yyval.m_expr).value = 0-(yyvsp[0].m_expr).value;
    }
#line 1956 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 407 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_expr).numbers.push_back((yyvsp[0].m_sId));
        (yyval.m_expr).transVal((yyvsp[0].m_sId));
    }
#line 1965 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 413 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_expr) = (yyvsp[-2].m_expr);
        (yyval.m_expr).ops.push_back((yyvsp[-1].m_sId));
        (yyval.m_expr).numbers.push_back((yyvsp[0].m_sId));
        (yyval.m_expr).value = (yyvsp[-2].m_expr).value * atoi((yyvsp[0].m_sId).c_str());
    }
#line 1976 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 419 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_expr) = (yyvsp[-2].m_expr);
        (yyval.m_expr).ops.push_back((yyvsp[-1].m_sId));
        (yyval.m_expr).numbers.push_back((yyvsp[0].m_sId));
        (yyval.m_expr).value = (yyvsp[-2].m_expr).value / atoi((yyvsp[0].m_sId).c_str());
    }
#line 1987 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 425 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_expr) = (yyvsp[-4].m_expr);
        (yyval.m_expr).ops.push_back((yyvsp[-3].m_sId));
        (yyval.m_expr).ops.push_back((yyvsp[-2].m_sId));
        (yyval.m_expr).ops.insert((yyval.m_expr).ops.end(), (yyvsp[-1].m_expr).ops.begin(), (yyvsp[-1].m_expr).ops.end());
        (yyval.m_expr).numbers.insert((yyval.m_expr).numbers.end(), (yyvsp[-1].m_expr).numbers.begin(), (yyvsp[-1].m_expr).numbers.end());
        (yyval.m_expr).ops.push_back((yyvsp[0].m_sId));
        (yyval.m_expr).value = (yyvsp[-4].m_expr).value * (yyvsp[-1].m_expr).value;
    }
#line 2001 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 434 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_expr) = (yyvsp[-4].m_expr);
        (yyval.m_expr).ops.push_back((yyvsp[-3].m_sId));
        (yyval.m_expr).ops.push_back((yyvsp[-2].m_sId));
        (yyval.m_expr).ops.insert((yyval.m_expr).ops.end(), (yyvsp[-1].m_expr).ops.begin(), (yyvsp[-1].m_expr).ops.end());
        (yyval.m_expr).numbers.insert((yyval.m_expr).numbers.end(), (yyvsp[-1].m_expr).numbers.begin(), (yyvsp[-1].m_expr).numbers.end());
        (yyval.m_expr).ops.push_back((yyvsp[0].m_sId));
        (yyval.m_expr).value = (yyvsp[-4].m_expr).value / (yyvsp[-1].m_expr).value;
    }
#line 2015 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 443 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_expr).ops.push_back((yyvsp[-2].m_sId));
        (yyval.m_expr).ops.insert((yyval.m_expr).ops.end(), (yyvsp[-1].m_expr).ops.begin(), (yyvsp[-1].m_expr).ops.end());
        (yyval.m_expr).numbers.insert((yyval.m_expr).numbers.end(), (yyvsp[-1].m_expr).numbers.begin(), (yyvsp[-1].m_expr).numbers.end());
        (yyval.m_expr).ops.push_back((yyvsp[0].m_sId));
        (yyval.m_expr).value = (yyvsp[-1].m_expr).value;
    }
#line 2027 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 450 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_expr).numbers.push_back((yyvsp[0].m_sId));
        (yyval.m_expr).transVal((yyvsp[0].m_sId));
    }
#line 2036 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 455 "yacc.y" /* yacc.c:1646  */
    { (yyval.m_sId) = (yyvsp[0].m_sId); }
#line 2042 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 456 "yacc.y" /* yacc.c:1646  */
    { (yyval.m_sId) = (yyvsp[0].m_sId); }
#line 2048 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 457 "yacc.y" /* yacc.c:1646  */
    { (yyval.m_sId) = (yyvsp[0].m_sId); }
#line 2054 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 458 "yacc.y" /* yacc.c:1646  */
    { (yyval.m_sId) = (yyvsp[0].m_sId); }
#line 2060 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 461 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_dele).init((yyvsp[-3].m_sId), (yyvsp[-1].m_cond));
        (yyval.m_dele).display();
        (yyval.m_dele).work();
    }
#line 2070 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 466 "yacc.y" /* yacc.c:1646  */
    {
        CondSql cond;
        (yyval.m_dele).init((yyvsp[-1].m_sId), cond);
        (yyval.m_dele).display();
        (yyval.m_dele).work();
    }
#line 2081 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 474 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_upda).init((yyvsp[-5].m_sId), (yyvsp[-1].m_cond), (yyvsp[-3].m_set));
        (yyval.m_upda).display();
        (yyval.m_upda).work();
    }
#line 2091 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 479 "yacc.y" /* yacc.c:1646  */
    {
        CondSql cond;
        (yyval.m_upda).init((yyvsp[-3].m_sId), cond, (yyvsp[-1].m_set));
        (yyval.m_upda).display();
        (yyval.m_upda).work();
    }
#line 2102 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 487 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_set) = (yyvsp[0].m_set);
        (yyval.m_set).push_back((yyvsp[-2].m_citem));
    }
#line 2111 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 491 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_set).push_back((yyvsp[0].m_citem));
    }
#line 2119 "yacc.tab.c" /* yacc.c:1646  */
    break;


#line 2123 "yacc.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 495 "yacc.y" /* yacc.c:1906  */


void yyerror(const char *s)
{
    cerr<<s<<endl;
}
