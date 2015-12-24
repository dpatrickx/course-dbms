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
    IDENTIFIER = 261,
    INSERT = 262,
    INTO = 263,
    VALUES = 264,
    YIN = 265,
    VALUEIT = 266,
    CREATE = 267,
    TABLE = 268,
    PRIMARY = 269,
    KEY = 270,
    TYPE = 271,
    NOTNULL = 272,
    KIND = 273,
    IOKIND = 274,
    SELECT = 275,
    FROM = 276,
    WHERE = 277,
    EXPRESSION = 278,
    JOIN = 279,
    ON = 280,
    USE = 281,
    IF = 282,
    EXISTS = 283,
    DROP = 284,
    JUDGEOP = 285,
    CONNOP = 286,
    UPDATE = 287,
    SET = 288,
    DELETE = 289,
    OPERATOR = 290
  };
#endif

/* Value type.  */


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_YACC_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 158 "yacc.tab.c" /* yacc.c:358  */

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
#define YYFINAL  36
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   157

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  70
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  164

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   290

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    46,     2,     2,     2,    35,     2,     2,
      47,    48,    42,    40,    44,    41,    39,    43,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    45,
      38,    36,    37,    53,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    49,     2,    50,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    51,     2,    52,     2,     2,     2,     2,
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
      54
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    53,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    67,    71,    76,    81,    86,    92,
      97,   102,   107,   113,   119,   124,   129,   134,   138,   144,
     148,   152,   156,   161,   165,   169,   170,   173,   177,   182,
     187,   194,   198,   202,   206,   209,   213,   217,   220,   224,
     227,   231,   235,   240,   244,   247,   252,   253,   256,   262,
     267,   271,   272,   273,   274,   277,   281,   288,   292,   299,
     303
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGER", "DATABASE", "SHOW",
  "IDENTIFIER", "INSERT", "INTO", "VALUES", "YIN", "VALUEIT", "CREATE",
  "TABLE", "PRIMARY", "KEY", "TYPE", "NOTNULL", "KIND", "IOKIND", "SELECT",
  "FROM", "WHERE", "EXPRESSION", "JOIN", "ON", "USE", "IF", "EXISTS",
  "DROP", "JUDGEOP", "CONNOP", "UPDATE", "SET", "DELETE", "'%'", "'='",
  "'>'", "'<'", "'.'", "'+'", "'-'", "'*'", "'/'", "','", "';'", "'!'",
  "'('", "')'", "'['", "']'", "'{'", "'}'", "'?'", "OPERATOR", "$accept",
  "sqllist", "usedbsql", "dropdbsql", "showdbsql", "createdbsql",
  "droptbsql", "showtbsql", "createtbsql", "tablecon", "insertsql",
  "tableitems", "valuesql", "valueitems", "valueitem", "selectsql",
  "attrsql", "attritem", "joinsql", "condsql", "conditem", "expression",
  "exprop", "deletesql", "updatesql", "setsql", YY_NULLPTR
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
     285,   286,   287,   288,   289,    37,    61,    62,    60,    46,
      43,    45,    42,    47,    44,    59,    33,    40,    41,    91,
      93,   123,   125,    63,   290
};
# endif

#define YYPACT_NINF -123

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-123)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      47,    17,    16,    25,     8,    95,    51,    22,    49,    71,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    47,
      47,    68,    72,    80,    94,    96,    64,  -123,    83,    61,
     100,    62,   102,   103,    77,   105,  -123,  -123,  -123,  -123,
    -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,    67,    69,
       2,    70,    66,   110,   111,     8,    73,  -123,    74,    75,
     115,   -18,  -123,  -123,    76,   116,  -123,    54,  -123,    -2,
    -123,  -123,  -123,  -123,    97,    81,   -13,   115,  -123,    58,
    -123,    82,    84,   108,   113,    85,    56,   107,   115,  -123,
      -9,    -1,   115,   115,  -123,    88,    98,  -123,  -123,    86,
      91,   116,   127,     9,    90,  -123,   114,   133,   134,    99,
     115,  -123,  -123,  -123,  -123,  -123,  -123,  -123,     4,    42,
       4,  -123,   101,  -123,   115,    18,    58,  -123,    76,   -26,
      54,  -123,   135,   136,   118,   120,  -123,   104,    42,     4,
      42,  -123,  -123,    76,  -123,  -123,  -123,    54,  -123,  -123,
     106,   122,   115,   115,  -123,    42,  -123,  -123,   109,   115,
    -123,  -123,  -123,  -123
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     0,     0,     0,     0,     0,    44,    41,     0,    43,
       0,     0,     0,     0,     0,     0,     1,     3,     4,     6,
       5,     8,     9,     7,    10,    11,    12,    13,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    15,     0,     0,
       0,     0,    17,    20,     0,     0,    18,     0,    45,     0,
      42,    14,    16,    19,     0,    70,     0,     0,    66,     0,
      28,    30,     0,     0,     0,     0,     0,     0,     0,    40,
       0,    56,     0,     0,    68,     0,    53,    35,    36,     0,
      34,     0,     0,     0,     0,    21,     0,     0,     0,     0,
       0,    38,    60,    57,    61,    62,    63,    64,    56,    55,
      56,    69,     0,    65,     0,     0,     0,    29,     0,     0,
       0,    25,     0,     0,    50,    48,    39,     0,    54,    56,
      59,    67,    52,     0,    32,    33,    27,     0,    24,    23,
       0,    46,     0,     0,    37,    58,    31,    22,     0,     0,
      51,    49,    26,    47
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -123,    78,  -123,  -123,  -123,  -123,  -123,  -123,  -123,  -122,
    -123,    50,  -109,    24,  -123,  -123,    93,    -4,  -123,   -87,
     -57,   -62,  -107,  -123,  -123,    60
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     9,    10,    11,    12,    13,    14,    15,    16,    85,
      17,    82,    80,    99,   100,    18,    28,    74,    90,    95,
      96,   119,   120,    19,    20,    76
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      29,   109,   112,    75,    77,    26,   122,   112,   149,    93,
     113,    64,   139,   110,    26,   113,    86,    87,   147,   146,
      88,    21,   148,   137,    23,   157,   129,    78,    34,    24,
      22,   139,    94,   139,   156,    75,   111,   142,    25,   114,
     115,   116,   117,    89,   114,   115,   116,   117,   139,    65,
      27,    29,     1,   130,     2,    32,   138,   131,   140,     3,
      83,    97,   143,   144,    33,   160,   161,     4,    84,    98,
      35,    36,   163,     5,    48,   106,     6,   155,    49,     7,
     107,     8,   114,   115,   116,   117,    50,   118,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    30,
      51,    31,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    67,    63,    66,    68,    69,    71,    72,
      73,    26,    81,    79,   103,    92,   101,    91,   104,   124,
     105,   108,   102,   123,   125,   126,   128,   132,   133,   134,
     135,   150,   151,   152,   136,   153,   141,   159,    70,   154,
     145,   127,   121,     0,   158,     0,     0,   162
};

static const yytype_int16 yycheck[] =
{
       4,    88,     3,    60,    22,     6,    93,     3,   130,    22,
      11,     9,   119,    22,     6,    11,    18,    19,    44,   128,
      22,     4,    48,   110,     8,   147,    17,    45,     6,     4,
      13,   138,    45,   140,   143,    92,    45,   124,    13,    40,
      41,    42,    43,    45,    40,    41,    42,    43,   155,    47,
      42,    55,     5,    44,     7,     4,   118,    48,   120,    12,
       6,     3,    44,    45,    13,   152,   153,    20,    14,    11,
      21,     0,   159,    26,     6,    19,    29,   139,     6,    32,
      24,    34,    40,    41,    42,    43,     6,    91,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,     4,
       6,     6,     6,    39,    21,    44,     6,    45,     6,     6,
      33,     6,    45,    47,    45,    45,     6,     6,    45,    45,
      45,     6,     6,    47,    16,    44,    44,    30,    15,    31,
      45,    24,    48,    45,    48,    44,     9,    47,    24,     6,
       6,     6,     6,    25,    45,    25,    45,    25,    55,    45,
     126,   101,    92,    -1,    48,    -1,    -1,    48
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,     7,    12,    20,    26,    29,    32,    34,    56,
      57,    58,    59,    60,    61,    62,    63,    65,    70,    78,
      79,     4,    13,     8,     4,    13,     6,    42,    71,    72,
       4,     6,     4,    13,     6,    21,     0,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,     6,     6,
       6,     6,     6,    39,    21,    44,     6,    45,     6,     6,
      33,     6,    45,    45,     9,    47,    45,    47,     6,     6,
      71,    45,    45,    45,    72,    75,    80,    22,    45,    47,
      67,     6,    66,     6,    14,    64,    18,    19,    22,    45,
      73,    30,    44,    22,    45,    74,    75,     3,    11,    68,
      69,    44,    48,    16,    15,    45,    19,    24,    24,    74,
      22,    45,     3,    11,    40,    41,    42,    43,    72,    76,
      77,    80,    74,    45,    31,    48,    44,    66,     9,    17,
      44,    48,    47,    24,     6,     6,    45,    74,    76,    77,
      76,    45,    74,    44,    45,    68,    67,    44,    48,    64,
       6,     6,    25,    25,    45,    76,    67,    64,    48,    25,
      74,    74,    48,    74
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    55,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    57,    57,    58,    59,    60,    61,
      62,    63,    64,    64,    64,    64,    64,    65,    65,    66,
      66,    67,    67,    68,    68,    69,    69,    70,    70,    70,
      70,    71,    71,    71,    72,    72,    73,    73,    73,    73,
      73,    73,    74,    74,    75,    75,    76,    76,    76,    76,
      76,    77,    77,    77,    77,    78,    78,    79,    79,    80,
      80
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     4,     3,     4,     4,     4,     4,
       4,     6,     5,     4,     4,     3,     6,     8,     5,     3,
       1,     5,     4,     3,     1,     1,     1,     8,     6,     7,
       5,     1,     3,     1,     1,     3,     4,     6,     3,     5,
       3,     5,     3,     1,     4,     3,     0,     1,     3,     2,
       1,     1,     1,     1,     1,     6,     4,     7,     5,     3,
       1
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
#line 53 "yacc.y" /* yacc.c:1646  */
    {}
#line 1345 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 67 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_usedb).init((yyvsp[-1].m_sId));
        (yyval.m_usedb).display();
    }
#line 1354 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 71 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_usedb).init((yyvsp[-1].m_sId));
        (yyval.m_usedb).display();
    }
#line 1363 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 76 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_dropdb).init((yyvsp[-1].m_sId));
        (yyval.m_dropdb).display();
    }
#line 1372 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 81 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_showdb).init((yyvsp[-1].m_sId));
        (yyval.m_showdb).display();
    }
#line 1381 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 86 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_credb).init((yyvsp[-1].m_sId));
        (yyval.m_credb).display();
    }
#line 1390 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 92 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_droptb).init((yyvsp[-1].m_sId));
        (yyval.m_droptb).display();
    }
#line 1399 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 97 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_showtb).init((yyvsp[-1].m_sId));
        (yyval.m_showtb).display();
    }
#line 1408 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 102 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_cretb).init((yyvsp[-3].m_sId), (yyvsp[-1].m_con));
        (yyval.m_cretb).display();
    }
#line 1417 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 107 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_con) = (yyvsp[0].m_con);
        (yyval.m_con).name.push_back((yyvsp[-4].m_sId));
        (yyval.m_con).type.push_back((yyvsp[-3].m_sId));
        (yyval.m_con).notNull.push_back(true);
    }
#line 1428 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 113 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_con) = (yyvsp[0].m_con);
        (yyval.m_con).name.push_back((yyvsp[-3].m_sId));
        (yyval.m_con).type.push_back((yyvsp[-2].m_sId));
        (yyval.m_con).notNull.push_back(false);
    }
#line 1439 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 119 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_con).name.push_back((yyvsp[-3].m_sId));
        (yyval.m_con).type.push_back((yyvsp[-2].m_sId));
        (yyval.m_con).notNull.push_back(true);
    }
#line 1449 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 124 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_con).name.push_back((yyvsp[-2].m_sId));
        (yyval.m_con).type.push_back((yyvsp[-1].m_sId));
        (yyval.m_con).notNull.push_back(false);
    }
#line 1459 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 129 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_con).priKey = (yyvsp[-2].m_sId);
    }
#line 1467 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 134 "yacc.y" /* yacc.c:1646  */
    {
        InsertSql ins((yyvsp[-5].m_sId), (yyvsp[-3].m_strv), (yyvsp[0].m_vecv));
        ins.display();
    }
#line 1476 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 138 "yacc.y" /* yacc.c:1646  */
    {
        vector<string> temp;
        InsertSql ins((yyvsp[-2].m_sId), temp, (yyvsp[0].m_vecv));
        ins.display();
    }
#line 1486 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 144 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_strv).push_back((yyvsp[-2].m_sId));
        (yyval.m_strv).insert((yyval.m_strv).end(), (yyvsp[0].m_strv).begin(), (yyvsp[0].m_strv).end());
    }
#line 1495 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 148 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_strv).push_back((yyvsp[0].m_sId));
    }
#line 1503 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 152 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_vecv).push_back((yyvsp[-3].m_strv));
        (yyval.m_vecv).insert((yyval.m_vecv).end(), (yyvsp[0].m_vecv).begin(), (yyvsp[0].m_vecv).end());
    }
#line 1512 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 157 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_vecv).push_back((yyvsp[-2].m_strv));
    }
#line 1520 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 161 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_strv).push_back((yyvsp[-2].m_sId));
        (yyval.m_strv).insert((yyval.m_strv).end(), (yyvsp[0].m_strv).begin(), (yyvsp[0].m_strv).end());
    }
#line 1529 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 165 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_strv).push_back((yyvsp[0].m_sId));
    }
#line 1537 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 169 "yacc.y" /* yacc.c:1646  */
    {(yyval.m_sId) = (yyvsp[0].m_sId);}
#line 1543 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 170 "yacc.y" /* yacc.c:1646  */
    {(yyval.m_sId) = (yyvsp[0].m_sId);}
#line 1549 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 173 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_sel).init((yyvsp[-6].m_attr), (yyvsp[-4].m_sId), (yyvsp[-3].m_join), (yyvsp[-1].m_cond));
        (yyval.m_sel).display();
    }
#line 1558 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 177 "yacc.y" /* yacc.c:1646  */
    {
        CondSql cond;
        (yyval.m_sel).init((yyvsp[-4].m_attr), (yyvsp[-2].m_sId), (yyvsp[-1].m_join), cond);
        (yyval.m_sel).display();
    }
#line 1568 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 182 "yacc.y" /* yacc.c:1646  */
    {
        JoinSql join;
        (yyval.m_sel).init((yyvsp[-5].m_attr), (yyvsp[-3].m_sId), join, (yyvsp[-1].m_cond));
        (yyval.m_sel).display();
    }
#line 1578 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 187 "yacc.y" /* yacc.c:1646  */
    {
        CondSql cond;
        JoinSql join;
        (yyval.m_sel).init((yyvsp[-3].m_attr), (yyvsp[-1].m_sId), join, cond);
        (yyval.m_sel).display();
    }
#line 1589 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 194 "yacc.y" /* yacc.c:1646  */
    {
        AttrItem item("*", "*");
        (yyval.m_attr).push_back(item);
    }
#line 1598 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 198 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_attr) = (yyvsp[0].m_attr);
        (yyval.m_attr).push_back((yyvsp[-2].m_sitem));
    }
#line 1607 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 202 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_attr).push_back((yyvsp[0].m_sitem));
    }
#line 1615 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 206 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_sitem).init("", (yyvsp[0].m_sId));
    }
#line 1623 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 209 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_sitem).init((yyvsp[-2].m_sId), (yyvsp[0].m_sId));
    }
#line 1631 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 213 "yacc.y" /* yacc.c:1646  */
    {
        CondSql c;
        (yyval.m_join).init((yyvsp[-3].m_sId), (yyvsp[-2].m_sId), (yyvsp[0].m_sId), c);
    }
#line 1640 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 217 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_join).init((yyvsp[-5].m_sId), (yyvsp[-4].m_sId), (yyvsp[-2].m_sId), (yyvsp[0].m_cond));
    }
#line 1648 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 220 "yacc.y" /* yacc.c:1646  */
    {
        CondSql c;
        (yyval.m_join).init("", (yyvsp[-2].m_sId), (yyvsp[0].m_sId), c);
    }
#line 1657 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 224 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_join).init("", (yyvsp[-4].m_sId), (yyvsp[-2].m_sId), (yyvsp[0].m_cond));
    }
#line 1665 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 227 "yacc.y" /* yacc.c:1646  */
    {
        CondSql c;
        (yyval.m_join).init((yyvsp[-2].m_sId), "", (yyvsp[0].m_sId), c);
    }
#line 1674 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 231 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_join).init((yyvsp[-4].m_sId), "", (yyvsp[-2].m_sId), (yyvsp[0].m_cond));
    }
#line 1682 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 235 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_cond) = (yyvsp[0].m_cond);
        (yyval.m_cond).conditions.push_back((yyvsp[-2].m_citem));
        (yyval.m_cond).connops.push_back((yyvsp[-1].m_sId));
    }
#line 1692 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 240 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_cond).conditions.push_back((yyvsp[0].m_citem));
    }
#line 1700 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 244 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_citem).init((yyvsp[-2].m_sId), (yyvsp[-3].m_sitem), (yyvsp[-1].m_sitem), (yyvsp[0].m_expr));
    }
#line 1708 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 247 "yacc.y" /* yacc.c:1646  */
    {
        AttrItem attr2;
        (yyval.m_citem).init((yyvsp[-1].m_sId), (yyvsp[-2].m_sitem), attr2, (yyvsp[0].m_expr));
    }
#line 1717 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 252 "yacc.y" /* yacc.c:1646  */
    {}
#line 1723 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 253 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_expr).str = (yyvsp[0].m_sId);
    }
#line 1731 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 256 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_expr) = (yyvsp[-2].m_expr);
        (yyval.m_expr).ops.push_back((yyvsp[-1].m_sId));
        (yyval.m_expr).numbers.insert((yyval.m_expr).numbers.end(), (yyvsp[0].m_expr).numbers.begin(), (yyvsp[0].m_expr).numbers.end());
        (yyval.m_expr).ops.insert((yyval.m_expr).ops.end(), (yyvsp[0].m_expr).ops.begin(), (yyvsp[0].m_expr).ops.end());
    }
#line 1742 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 262 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_expr).ops.push_back((yyvsp[-1].m_sId));
        (yyval.m_expr).numbers.insert((yyval.m_expr).numbers.end(), (yyvsp[0].m_expr).numbers.begin(), (yyvsp[0].m_expr).numbers.end());
        (yyval.m_expr).ops.insert((yyval.m_expr).ops.end(), (yyvsp[0].m_expr).ops.begin(), (yyvsp[0].m_expr).ops.end());
    }
#line 1752 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 267 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_expr).numbers.push_back((yyvsp[0].m_sId));
    }
#line 1760 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 271 "yacc.y" /* yacc.c:1646  */
    { (yyval.m_sId) = (yyvsp[0].m_sId); }
#line 1766 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 272 "yacc.y" /* yacc.c:1646  */
    { (yyval.m_sId) = (yyvsp[0].m_sId); }
#line 1772 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 273 "yacc.y" /* yacc.c:1646  */
    { (yyval.m_sId) = (yyvsp[0].m_sId); }
#line 1778 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 274 "yacc.y" /* yacc.c:1646  */
    { (yyval.m_sId) = (yyvsp[0].m_sId); }
#line 1784 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 277 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_dele).init((yyvsp[-3].m_sId), (yyvsp[-1].m_cond));
        (yyval.m_dele).display();
    }
#line 1793 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 281 "yacc.y" /* yacc.c:1646  */
    {
        CondSql cond;
        (yyval.m_dele).init((yyvsp[-1].m_sId), cond);
        (yyval.m_dele).display();
    }
#line 1803 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 288 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_upda).init((yyvsp[-5].m_sId), (yyvsp[-1].m_cond), (yyvsp[-3].m_set));
        (yyval.m_upda).display();
    }
#line 1812 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 292 "yacc.y" /* yacc.c:1646  */
    {
        CondSql cond;
        (yyval.m_upda).init((yyvsp[-3].m_sId), cond, (yyvsp[-1].m_set));
        (yyval.m_upda).display();
    }
#line 1822 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 299 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_set) = (yyvsp[0].m_set);
        (yyval.m_set).push_back((yyvsp[-2].m_citem));
    }
#line 1831 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 303 "yacc.y" /* yacc.c:1646  */
    {
        (yyval.m_set).push_back((yyvsp[0].m_citem));
    }
#line 1839 "yacc.tab.c" /* yacc.c:1646  */
    break;


#line 1843 "yacc.tab.c" /* yacc.c:1646  */
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
#line 307 "yacc.y" /* yacc.c:1906  */


void yyerror(const char *s)
{
    cerr<<s<<endl;
}
