/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 3 "tiger.y"

#include <string.h>
#include <stdio.h>
#include "errormsg.h"
#include "util.h"
#include "symbol.h"
#include "absyn.h"
//#include "printabsyn.h"


//A_expre absyn_root;

int yylex( void);


#line 86 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    ID = 258,
    STRING = 259,
    INT = 260,
    COMMA = 261,
    COLON = 262,
    SEMICOLON = 263,
    LPAREN = 264,
    RPAREN = 265,
    LBRACK = 266,
    RBRACK = 267,
    LBRACE = 268,
    RBRACE = 269,
    DOT = 270,
    PLUS = 271,
    MINUS = 272,
    TIMES = 273,
    DIVIDE = 274,
    EQ = 275,
    NEQ = 276,
    LT = 277,
    LE = 278,
    GT = 279,
    GE = 280,
    AND = 281,
    OR = 282,
    ASSIGN = 283,
    ARRAY = 284,
    IF = 285,
    THEN = 286,
    ELSE = 287,
    WHILE = 288,
    FOR = 289,
    TO = 290,
    DO = 291,
    LET = 292,
    IN = 293,
    END = 294,
    OF = 295,
    BREAK = 296,
    NIL = 297,
    FUNCTION = 298,
    VAR = 299,
    TYPE = 300,
    SWITCH = 301,
    CASE = 302,
    DEFAULT = 303,
    UMINUS = 304
  };
#endif
/* Tokens.  */
#define ID 258
#define STRING 259
#define INT 260
#define COMMA 261
#define COLON 262
#define SEMICOLON 263
#define LPAREN 264
#define RPAREN 265
#define LBRACK 266
#define RBRACK 267
#define LBRACE 268
#define RBRACE 269
#define DOT 270
#define PLUS 271
#define MINUS 272
#define TIMES 273
#define DIVIDE 274
#define EQ 275
#define NEQ 276
#define LT 277
#define LE 278
#define GT 279
#define GE 280
#define AND 281
#define OR 282
#define ASSIGN 283
#define ARRAY 284
#define IF 285
#define THEN 286
#define ELSE 287
#define WHILE 288
#define FOR 289
#define TO 290
#define DO 291
#define LET 292
#define IN 293
#define END 294
#define OF 295
#define BREAK 296
#define NIL 297
#define FUNCTION 298
#define VAR 299
#define TYPE 300
#define SWITCH 301
#define CASE 302
#define DEFAULT 303
#define UMINUS 304

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 23 "tiger.y"

	int 					 ival;
	char					*sval;
	//char 					*A_id;
	//int					 A_int;
	//char					*A_str;

	struct AST_var_ 		*A_var;
	struct AST_ty_ 			*A_ty;
	struct AST_expre_ 		*A_expre;
	struct AST_expre_list_ 	*A_expre_list;
	struct AST_dec_ 		*A_dec;
	struct AST_decs_ 		*A_decs;
	struct AST_field_ 		*A_field;
	struct AST_field_list_ 	*A_field_list;
	struct AST_fundec_ 		*A_fundec;
	struct AST_fundecs_ 	*A_fundecs;
	struct AST_efield_ 		*A_efield;
	struct AST_efield_list_ *A_efield_list;
	struct AST_namety_		*A_namety;
	struct AST_name_ty_list_*A_name_ty_list;
	struct AST_namety_ 		*A_name_ty_entry;


	

#line 263 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  45
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   270

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  82
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  166

#define YYUNDEFTOK  2
#define YYMAXUTOK   304


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      45,    46,    47,    48,    49
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    94,    94,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   114,
     115,   116,   117,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   129,   131,   132,   134,   135,   137,   138,   139,
     140,   142,   144,   145,   147,   148,   150,   152,   153,   154,
     156,   157,   159,   161,   163,   165,   167,   168,   170,   171,
     173,   175,   176,   178,   179,   180,   182,   183,   185,   186,
     188,   189,   191,   192,   194,   196,   197,   199,   200,   202,
     204,   205,   206
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "STRING", "INT", "COMMA", "COLON",
  "SEMICOLON", "LPAREN", "RPAREN", "LBRACK", "RBRACK", "LBRACE", "RBRACE",
  "DOT", "PLUS", "MINUS", "TIMES", "DIVIDE", "EQ", "NEQ", "LT", "LE", "GT",
  "GE", "AND", "OR", "ASSIGN", "ARRAY", "IF", "THEN", "ELSE", "WHILE",
  "FOR", "TO", "DO", "LET", "IN", "END", "OF", "BREAK", "NIL", "FUNCTION",
  "VAR", "TYPE", "SWITCH", "CASE", "DEFAULT", "UMINUS", "$accept",
  "program", "expre", "expre_opera", "expre_compa", "expre_fun_call",
  "args", "arg_list", "lvalue", "expre_record", "efields", "efield_list",
  "efield", "expre_seq", "expre_if", "expre_for", "expre_while",
  "expre_switch", "op_swi", "var_swi", "ops_swi", "expre_let", "decs",
  "dec", "fun_decs", "fundec", "tyfields", "field_list", "tyfield",
  "var_dec", "type_decs", "ty_dec", "ty", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304
};
# endif

#define YYPACT_NINF (-14)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -1,     1,   -14,   -14,    -1,    -1,    -1,    -1,     9,    60,
     -14,   -14,    12,    24,   243,   -14,   -14,   -14,    -2,   -14,
     -14,   -14,   -14,   -14,   -14,    -1,    34,   243,    10,    42,
     215,    70,    11,    41,    56,    65,    32,    60,   -14,    55,
     -14,   -14,    62,    26,   -14,   -14,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,
      -1,    -1,   106,    99,   -14,    88,    96,   -14,   115,    -1,
     -14,    -1,    -1,    -1,   125,    -6,   116,    -1,   -14,   -14,
     -14,   -14,   -14,   128,    42,    42,    42,    42,    93,    93,
      93,    93,    93,    93,    42,    42,   231,   -14,    42,   243,
      -1,   -14,    -1,   -14,    34,   243,   198,   243,   166,   132,
     136,    -1,    14,     3,   127,   -14,   -14,   243,   -14,    -1,
      -1,   134,    13,   -14,   114,   243,   -14,   132,   103,   -14,
     -14,   -13,   243,   145,   142,   132,     8,    -1,   133,   140,
     146,    26,   143,   137,    -1,   -14,   -14,   149,    -1,   243,
     -14,   -14,   147,    -1,   -14,   243,   135,   243,    -1,   186,
      -1,    58,   -14,   243,   150,   -14
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    37,     4,     3,    47,     0,     0,     0,     0,    61,
       6,     5,     0,     0,     2,    10,    11,    12,     7,    13,
      14,    15,    16,    17,    18,    33,    42,    48,     0,    31,
       0,     0,     0,     0,     0,     0,     0,    61,    63,    66,
      64,    65,    77,     0,    54,     1,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    35,     0,    34,     0,     0,    43,    44,     0,
       9,     0,     0,     0,     0,     0,     0,    47,    62,    67,
      78,    57,    56,     0,    19,    20,    21,    22,    27,    28,
      23,    24,    25,    26,    29,    30,     0,    38,     8,    40,
       0,    32,     0,    41,     0,    49,    50,    53,     0,     0,
       0,     0,     0,     0,     0,    39,    36,    46,    45,     0,
       0,     0,     0,    72,     0,    75,    80,    70,     0,    79,
      60,     0,    51,     0,     0,     0,     0,     0,     0,    71,
       0,     0,     0,     0,     0,    74,    73,     0,     0,    76,
      81,    82,     0,     0,    55,    52,     0,    68,     0,     0,
       0,     0,    59,    69,     0,    58
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -14,   -14,     0,   -14,   -14,   -14,   -14,    59,   -14,   -14,
     -14,    52,   -14,    97,   -14,   -14,   -14,   -14,   -14,    35,
     -14,   -14,   138,   -14,   139,   -14,   -14,    46,    44,   -14,
     153,   -14,   -14
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    13,    27,    15,    16,    17,    63,    64,    18,    19,
      66,    67,    68,    28,    20,    21,    22,    23,    44,    83,
     143,    24,    36,    37,    38,    39,   138,   122,   123,    40,
      41,    42,   129
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      14,   110,     1,     2,     3,    29,    30,    31,     4,    58,
      25,    69,    32,    59,    26,   147,     5,   126,    69,   135,
      70,    43,   111,   136,    45,    62,    60,   127,   148,     6,
      81,    82,     7,     8,   141,   142,     9,    65,    61,    73,
      10,    11,   130,   128,    74,    12,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    75,
      98,    99,    50,    51,    52,    53,    54,    55,    76,   105,
      77,   106,   107,   108,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    33,   164,
      62,    97,   117,    33,    34,    35,    72,    35,   102,   101,
     103,   125,   100,    -1,    -1,    -1,    -1,    -1,    -1,   132,
     133,   104,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,   109,   121,   112,   149,   114,   124,
     131,   134,   137,   140,   155,   145,   135,   150,   157,   151,
     153,   154,   156,   159,   158,   160,   118,   165,   161,   116,
     163,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,   139,   113,    78,   152,     0,    79,   146,
       0,   144,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,   162,    80,     0,     0,     0,     0,
       0,   120,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,     0,     0,     0,     0,
     119,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,   115,     0,     0,    71,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57
};

static const yytype_int16 yycheck[] =
{
       0,     7,     3,     4,     5,     5,     6,     7,     9,    11,
       9,     8,     3,    15,    13,     7,    17,     3,     8,     6,
      10,     9,    28,    10,     0,    25,    28,    13,    20,    30,
       4,     5,    33,    34,    47,    48,    37,     3,    40,    28,
      41,    42,    39,    29,     3,    46,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,     3,
      60,    61,    20,    21,    22,    23,    24,    25,     3,    69,
      38,    71,    72,    73,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    43,    41,
     100,     3,   102,    43,    44,    45,    36,    45,    20,    10,
      14,   111,     6,    20,    21,    22,    23,    24,    25,   119,
     120,     6,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,     9,     3,    20,   137,    10,     3,
      13,     7,    28,    40,   144,     3,     6,    14,   148,     3,
       7,    14,     3,   153,     7,    20,   104,     7,   158,   100,
     160,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,   127,    77,    37,   141,    -1,    39,   135,
      -1,    36,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,     8,    42,    -1,    -1,    -1,    -1,
      -1,    35,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    -1,    -1,    -1,    -1,
      32,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    12,    -1,    -1,    31,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     9,    17,    30,    33,    34,    37,
      41,    42,    46,    51,    52,    53,    54,    55,    58,    59,
      64,    65,    66,    67,    71,     9,    13,    52,    63,    52,
      52,    52,     3,    43,    44,    45,    72,    73,    74,    75,
      79,    80,    81,     9,    68,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    11,    15,
      28,    40,    52,    56,    57,     3,    60,    61,    62,     8,
      10,    31,    36,    28,     3,     3,     3,    38,    72,    74,
      80,     4,     5,    69,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,     3,    52,    52,
       6,    10,    20,    14,     6,    52,    52,    52,    52,     9,
       7,    28,    20,    63,    10,    12,    57,    52,    61,    32,
      35,     3,    77,    78,     3,    52,     3,    13,    29,    82,
      39,    13,    52,    52,     7,     6,    10,    28,    76,    77,
      40,    47,    48,    70,    36,     3,    78,     7,    20,    52,
      14,     3,    69,     7,    14,    52,     3,    52,     7,    52,
      20,    52,     8,    52,    41,     7
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    50,    51,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    53,
      53,    53,    53,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    55,    56,    56,    57,    57,    58,    58,    58,
      58,    59,    60,    60,    61,    61,    62,    63,    63,    63,
      64,    64,    65,    66,    67,    68,    69,    69,    70,    70,
      71,    72,    72,    73,    73,    73,    74,    74,    75,    75,
      76,    76,    77,    77,    78,    79,    79,    80,    80,    81,
      82,    82,    82
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     3,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     4,     0,     1,     1,     3,     1,     3,     4,
       3,     4,     0,     1,     1,     3,     3,     0,     1,     3,
       4,     6,     8,     4,     2,     6,     1,     1,     6,     4,
       5,     0,     2,     1,     1,     1,     1,     2,     7,     9,
       0,     1,     1,     3,     3,     4,     6,     1,     2,     4,
       1,     3,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 94 "tiger.y"
                                                                                        {AST_root = AST_ProgramExp((yylsp[0]).first_line, (yylsp[0]).first_comumn, (yyvsp[0].A_expre));}
#line 1688 "y.tab.c"
    break;

  case 3:
#line 97 "tiger.y"
                                                                                {(yyval.A_expre) = A_IntExp((yylsp[0]).first_line, (yylsp[0]).first_column, (yyvsp[0].ival));}
#line 1694 "y.tab.c"
    break;

  case 4:
#line 98 "tiger.y"
                                                                                {(yyval.A_expre) = A_StringExp((yylsp[0]).first_line, (yylsp[0]).first_column, (yyvsp[0].sval));}
#line 1700 "y.tab.c"
    break;

  case 5:
#line 99 "tiger.y"
                                                                                {(yyval.A_expre) = A_NilExp((yylsp[0]).first_line, (yylsp[0]).first_column);}
#line 1706 "y.tab.c"
    break;

  case 6:
#line 100 "tiger.y"
                                                                                {(yyval.A_expre) = A_BreakExp((yylsp[0]).first_line, (yylsp[0]).first_column);}
#line 1712 "y.tab.c"
    break;

  case 7:
#line 101 "tiger.y"
                                                                                                {(yyval.A_expre) = A_VarExp((yylsp[0]).first_line, (yylsp[0]).first_column, (yyvsp[0].A_var));}
#line 1718 "y.tab.c"
    break;

  case 8:
#line 102 "tiger.y"
                                                                    {(yyval.A_expre) = A_AssignExp((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[-2].A_var), (yyvsp[0].A_expre));}
#line 1724 "y.tab.c"
    break;

  case 9:
#line 103 "tiger.y"
                                                                    {(yyval.A_expre) = A_SeqExp((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[-1].A_expre_list));}
#line 1730 "y.tab.c"
    break;

  case 10:
#line 104 "tiger.y"
                                                                        {(yyval.A_expre) = (yyvsp[0].A_expre);}
#line 1736 "y.tab.c"
    break;

  case 11:
#line 105 "tiger.y"
                                                                        {(yyval.A_expre) = (yyvsp[0].A_expre);}
#line 1742 "y.tab.c"
    break;

  case 12:
#line 106 "tiger.y"
                                                                        {(yyval.A_expre) = (yyvsp[0].A_expre);}
#line 1748 "y.tab.c"
    break;

  case 13:
#line 107 "tiger.y"
                                                                                {(yyval.A_expre) = (yyvsp[0].A_expre);}
#line 1754 "y.tab.c"
    break;

  case 14:
#line 108 "tiger.y"
                                                                                {(yyval.A_expre) = (yyvsp[0].A_expre);}
#line 1760 "y.tab.c"
    break;

  case 15:
#line 109 "tiger.y"
                                                                                {(yyval.A_expre) = (yyvsp[0].A_expre);}
#line 1766 "y.tab.c"
    break;

  case 16:
#line 110 "tiger.y"
                                                                        {(yyval.A_expre) = (yyvsp[0].A_expre);}
#line 1772 "y.tab.c"
    break;

  case 17:
#line 111 "tiger.y"
                                                                        {(yyval.A_expre) = (yyvsp[0].A_expre);}
#line 1778 "y.tab.c"
    break;

  case 18:
#line 112 "tiger.y"
                                                                                {(yyval.A_expre) = (yyvsp[0].A_expre);}
#line 1784 "y.tab.c"
    break;

  case 19:
#line 114 "tiger.y"
                                                                        {(yyval.A_expre) = A_OpExp((yylsp[-2]).first_line, (yylsp[-2]).first_column, A_plusOp, (yyvsp[-2].A_expre), (yyvsp[0].A_expre));}
#line 1790 "y.tab.c"
    break;

  case 20:
#line 115 "tiger.y"
                                                                                {(yyval.A_expre) = A_OpExp((yylsp[-2]).first_line, (yylsp[-2]).first_column, A_minusOp, (yyvsp[-2].A_expre), (yyvsp[0].A_expre));}
#line 1796 "y.tab.c"
    break;

  case 21:
#line 116 "tiger.y"
                                                                        {(yyval.A_expre) = A_OpExp((yylsp[-2]).first_line, (yylsp[-2]).first_column, A_timesOp, (yyvsp[-2].A_expre), (yyvsp[0].A_expre));}
#line 1802 "y.tab.c"
    break;

  case 22:
#line 117 "tiger.y"
                                                                        {(yyval.A_expre) = A_OpExp((yylsp[-2]).first_line, (yylsp[-2]).first_column, A_divideOp, (yyvsp[-2].A_expre), (yyvsp[0].A_expre));}
#line 1808 "y.tab.c"
    break;

  case 23:
#line 119 "tiger.y"
                                                                        {(yyval.A_expre) = A_OpExp((yylsp[-2]).first_line, (yylsp[-2]).first_column, A_ltOp, (yyvsp[-2].A_expre), (yyvsp[0].A_expre));}
#line 1814 "y.tab.c"
    break;

  case 24:
#line 120 "tiger.y"
                                                                                {(yyval.A_expre) = A_OpExp((yylsp[-2]).first_line, (yylsp[-2]).first_column, A_leOp, (yyvsp[-2].A_expre), (yyvsp[0].A_expre));}
#line 1820 "y.tab.c"
    break;

  case 25:
#line 121 "tiger.y"
                                                                                {(yyval.A_expre) = A_OpExp((yylsp[-2]).first_line, (yylsp[-2]).first_column, A_gtOp, (yyvsp[-2].A_expre), (yyvsp[0].A_expre));}
#line 1826 "y.tab.c"
    break;

  case 26:
#line 122 "tiger.y"
                                                                                {(yyval.A_expre) = A_OpExp((yylsp[-2]).first_line, (yylsp[-2]).first_column, A_geOp, (yyvsp[-2].A_expre), (yyvsp[0].A_expre));}
#line 1832 "y.tab.c"
    break;

  case 27:
#line 123 "tiger.y"
                                                                                {(yyval.A_expre) = A_OpExp((yylsp[-2]).first_line, (yylsp[-2]).first_column, A_eqOp, (yyvsp[-2].A_expre), (yyvsp[0].A_expre));}
#line 1838 "y.tab.c"
    break;

  case 28:
#line 124 "tiger.y"
                                                                        {(yyval.A_expre) = A_OpExp((yylsp[-2]).first_line, (yylsp[-2]).first_column, A_neqOp, (yyvsp[-2].A_expre), (yyvsp[0].A_expre));}
#line 1844 "y.tab.c"
    break;

  case 29:
#line 125 "tiger.y"
                                                                                {(yyval.A_expre) = A_OpExp((yylsp[-2]).first_line, (yylsp[-2]).first_column, A_andOp, (yyvsp[-2].A_expre), (yyvsp[0].A_expre));}
#line 1850 "y.tab.c"
    break;

  case 30:
#line 126 "tiger.y"
                                                                                {(yyval.A_expre) = A_OpExp((yylsp[-2]).first_line, (yylsp[-2]).first_column, A_orOp, (yyvsp[-2].A_expre), (yyvsp[0].A_expre));}
#line 1856 "y.tab.c"
    break;

  case 31:
#line 127 "tiger.y"
                                                                {(yyval.A_expre) = A_OpExp((yylsp[-1]).first_line, (yylsp[-1]).first_column, A_minusOp, A_IntExp((yylsp[-1]).first_line, (yylsp[-1]).first_column, 0), (yyvsp[0].A_expre));}
#line 1862 "y.tab.c"
    break;

  case 32:
#line 129 "tiger.y"
                                                                {(yyval.A_expre) = A_CallExp((yylsp[-3]).first_line, (yylsp[-3]).first_column, S_Symbol((yyvsp[-3].sval)), (yyvsp[-1].A_expre_list));}
#line 1868 "y.tab.c"
    break;

  case 33:
#line 131 "tiger.y"
                                                                                                {(yyval.A_expre_list) = NULL;}
#line 1874 "y.tab.c"
    break;

  case 34:
#line 132 "tiger.y"
                                                                                {(yyval.A_expre_list) = (yyvsp[0].A_expre_list);}
#line 1880 "y.tab.c"
    break;

  case 35:
#line 134 "tiger.y"
                                                                {(yyval.A_expre_list) = A_ExpList((yylsp[0]).first_line, (yylsp[0]).first_column, (yyvsp[0].A_expre), NULL);}
#line 1886 "y.tab.c"
    break;

  case 36:
#line 135 "tiger.y"
                                                                {(yyval.A_expre_list) = A_ExpList((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[-2].A_expre), (yyvsp[0].A_expre_list));}
#line 1892 "y.tab.c"
    break;

  case 37:
#line 137 "tiger.y"
                                                                {(yyval.A_var) = A_SimpleVar((yylsp[0]).first_line, (yylsp[0]).first_column, S_Symbol((yyvsp[0].sval)));}
#line 1898 "y.tab.c"
    break;

  case 38:
#line 138 "tiger.y"
                                                                {(yyval.A_var) = A_FieldVar((yylsp[-2]).first_line, (yylsp[-2]).first_column, S_Symbol((yyvsp[-2].A_var))), S_Symbol((yyvsp[0].sval))));}
#line 1904 "y.tab.c"
    break;

  case 39:
#line 139 "tiger.y"
                                                                {(yyval.A_var) = A_SubscriptVar((yylsp[-3]).first_line, (yylsp[-3]).first_column, (yyvsp[-3].A_var), (yyvsp[-1].A_expre));}
#line 1910 "y.tab.c"
    break;

  case 40:
#line 140 "tiger.y"
                                                                        {(yyval.A_var) = A_ArrayExp((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[-2].A_var), (yyvsp[0].A_expre));}
#line 1916 "y.tab.c"
    break;

  case 41:
#line 142 "tiger.y"
                                                                {(yyval.A_expre) = A_RecordExp((yylsp[-3]).first_line, (yylsp[-3]).first_column, S_Symbol((yyvsp[-3].sval)), (yyvsp[-1].A_efield_list));}
#line 1922 "y.tab.c"
    break;

  case 42:
#line 144 "tiger.y"
                                                                                                {(yyval.A_efield_list) = NULL;}
#line 1928 "y.tab.c"
    break;

  case 43:
#line 145 "tiger.y"
                                                                    {(yyval.A_efield_list) = (yyvsp[0].A_efield_list);}
#line 1934 "y.tab.c"
    break;

  case 44:
#line 147 "tiger.y"
                                                                        {(yyval.A_efield_list) = A_Efield_list((yylsp[0]).first_line, (yylsp[0]).first_column, (yyvsp[0].A_efield), NULL);}
#line 1940 "y.tab.c"
    break;

  case 45:
#line 148 "tiger.y"
                                                                        {(yyval.A_efield_list) = A_Efield_list((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[-2].A_efield), (yyvsp[0].A_efield_list));}
#line 1946 "y.tab.c"
    break;

  case 46:
#line 150 "tiger.y"
                                                                        {(yyval.A_efield) = A_Efield((yylsp[-2]).first_line, (yylsp[-2]).first_column, S_Symbol((yyvsp[-2].sval)), (yyvsp[0].A_expre));}
#line 1952 "y.tab.c"
    break;

  case 47:
#line 152 "tiger.y"
                                                                                                {(yyval.A_expre_list) = NULL;}
#line 1958 "y.tab.c"
    break;

  case 48:
#line 153 "tiger.y"
                                                                                {(yyval.A_expre_list) = A_ExpList((yylsp[0]).first_line, (yylsp[0]).first_column, (yyvsp[0].A_expre), NULL);}
#line 1964 "y.tab.c"
    break;

  case 49:
#line 154 "tiger.y"
                                                                        {(yyval.A_expre_list) = A_ExpList((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[0].A_expre), (yyvsp[-2].A_expre_list));}
#line 1970 "y.tab.c"
    break;

  case 50:
#line 156 "tiger.y"
                                                                {(yyval.A_expre) = A_IfExp((yylsp[-3]).first_line, (yylsp[-3]).first_column, (yyvsp[-2].A_expre), (yyvsp[0].A_expre));}
#line 1976 "y.tab.c"
    break;

  case 51:
#line 157 "tiger.y"
                                                                {(yyval.A_expre) = A_IfExp((yylsp[-5]).first_line, (yylsp[-5]).first_column, (yyvsp[-4].A_expre), (yyvsp[-2].A_expre), (yyvsp[0].A_expre));}
#line 1982 "y.tab.c"
    break;

  case 52:
#line 159 "tiger.y"
                                                      {(yyval.A_expre) = A_ForExp((yylsp[-7]).first_line, (yylsp[-7]).first_column, S_Symbol((yyvsp[-6].sval)), (yyvsp[-4].A_expre), (yyvsp[-2].A_expre), (yyvsp[0].A_expre));}
#line 1988 "y.tab.c"
    break;

  case 53:
#line 161 "tiger.y"
                                                                {(yyval.A_expre) = A_WhileExp((yylsp[-3]).first_line, (yylsp[-3]).first_column, (yyvsp[-2].A_expre), (yyvsp[0].A_expre));}
#line 1994 "y.tab.c"
    break;

  case 54:
#line 163 "tiger.y"
                                                                        {(yyval.A_expre) = A_SwitchExp((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[0].A_expre));}
#line 2000 "y.tab.c"
    break;

  case 55:
#line 165 "tiger.y"
                                                                    {(yyval.A_expre) = A_SwitchExp((yylsp[-5]).first_line, (yylsp[-5]).first_column, (yyvsp[-4].A_expre), (yyvsp[-1].A_expre));}
#line 2006 "y.tab.c"
    break;

  case 56:
#line 167 "tiger.y"
                                                                                                {(yyval.A_expre) = A_SwitchExp((yylsp[0]).first_line, (yylsp[0]).first_column, (yyvsp[0].ival));}
#line 2012 "y.tab.c"
    break;

  case 57:
#line 168 "tiger.y"
                                                                                                {(yyval.A_expre) = A_SwitchExp((yylsp[0]).first_line, (yylsp[0]).first_column, (yyvsp[0].sval));}
#line 2018 "y.tab.c"
    break;

  case 58:
#line 170 "tiger.y"
                                                             {(yyval.A_expre) = A_SwitchExp((yylsp[-5]).first_line, (yylsp[-5]).first_column, (yyvsp[-4].A_expre), (yyvsp[-2].A_expre));}
#line 2024 "y.tab.c"
    break;

  case 59:
#line 171 "tiger.y"
                                                                        {(yyval.A_expre) = A_SwitchExp((yylsp[-3]).first_line, (yylsp[-3]).first_column, (yyvsp[-1].A_expre));}
#line 2030 "y.tab.c"
    break;

  case 60:
#line 173 "tiger.y"
                                                                        {(yyval.A_expre) = A_LetExp((yylsp[-4]).first_line, (yylsp[-4]).first_column, (yyvsp[-3].A_decs), (yyvsp[-1].A_expre_list));}
#line 2036 "y.tab.c"
    break;

  case 61:
#line 175 "tiger.y"
                                                                                                {(yyval.A_decs) = NULL;}
#line 2042 "y.tab.c"
    break;

  case 62:
#line 176 "tiger.y"
                                                                                        {(yyval.A_decs) = A_DecList((yyvsp[-1].A_dec), (yyvsp[0].A_decs));}
#line 2048 "y.tab.c"
    break;

  case 63:
#line 178 "tiger.y"
                                                                        {(yyval.A_dec) = A_FunctionDec((yylsp[0]).first_line, (yylsp[0]).first_column, (yyvsp[0].A_fundecs));}
#line 2054 "y.tab.c"
    break;

  case 64:
#line 179 "tiger.y"
                                                                                {(yyval.A_dec) = (yyvsp[0].A_dec);}
#line 2060 "y.tab.c"
    break;

  case 65:
#line 180 "tiger.y"
                                                                                {(yyval.A_dec) = A_TypeDec((yylsp[0]).first_line, (yylsp[0]).first_column, (yyvsp[0].A_name_ty_list));}
#line 2066 "y.tab.c"
    break;

  case 66:
#line 182 "tiger.y"
                                                                                {(yyval.A_fundecs) = A_FundecList((yyvsp[0].A_fundec), NULL);}
#line 2072 "y.tab.c"
    break;

  case 67:
#line 183 "tiger.y"
                                                                        {(yyval.A_fundecs) = A_FundecList((yyvsp[-1].A_fundec), (yyvsp[0].A_fundecs));}
#line 2078 "y.tab.c"
    break;

  case 68:
#line 185 "tiger.y"
                                                              {(yyval.A_fundec) = A_Fundec((yylsp[-6]).first_line, (yylsp[-6]).first_column, S_Symbol((yyvsp[-5].sval)), (yyvsp[-3].A_field_list), NULL, (yyvsp[0].A_expre));}
#line 2084 "y.tab.c"
    break;

  case 69:
#line 186 "tiger.y"
                                                                               {(yyval.A_fundec) = A_Fundec((yylsp[-8]).first_line, (yylsp[-8]).first_column, S_Symbol((yyvsp[-7].sval)), (yyvsp[-5].A_field_list), S_Symbol((yyvsp[-2].sval)), (yyvsp[0].A_expre));}
#line 2090 "y.tab.c"
    break;

  case 70:
#line 188 "tiger.y"
                                                                        {(yyval.A_field_list) = NULL;}
#line 2096 "y.tab.c"
    break;

  case 71:
#line 189 "tiger.y"
                                                                                {(yyval.A_field_list) = (yyvsp[0].A_field_list);}
#line 2102 "y.tab.c"
    break;

  case 72:
#line 191 "tiger.y"
                                                                        {(yyval.A_field_list) = A_FieldList((yyvsp[0].A_field), NULL);}
#line 2108 "y.tab.c"
    break;

  case 73:
#line 192 "tiger.y"
                                                                        {(yyval.A_field_list) = A_FieldList((yyvsp[-2].A_field_list), (yyvsp[0].A_field));}
#line 2114 "y.tab.c"
    break;

  case 74:
#line 194 "tiger.y"
                                                                        {(yyval.A_field) = A_Field((yylsp[-2]).first_line, (yylsp[-2]).first_column, S_Symbol((yyvsp[-2].sval)), S_Symbol((yyvsp[0].sval)));}
#line 2120 "y.tab.c"
    break;

  case 75:
#line 196 "tiger.y"
                                                                {(yyval.A_dec) = A_VarDec((yylsp[-3]).first_line, (yylsp[-3]).first_column, S_Symbol((yyvsp[-2].sval)), NULL, (yyvsp[0].A_expre));}
#line 2126 "y.tab.c"
    break;

  case 76:
#line 197 "tiger.y"
                                                                {(yyval.A_dec) = A_VarDec((yylsp[-5]).first_line, (yylsp[-5]).first_column, S_Symbol((yyvsp[-4].sval)), S_Symbol((yyvsp[-2].sval)), (yyvsp[0].A_expre));}
#line 2132 "y.tab.c"
    break;

  case 77:
#line 199 "tiger.y"
                                                                                        {(yyval.A_name_ty_list)=A_NametyList((yyvsp[0].A_namety), NULL);}
#line 2138 "y.tab.c"
    break;

  case 78:
#line 200 "tiger.y"
                                                                                {(yyval.A_name_ty_list)=A_NametyList((yyvsp[-1].A_namety), (yyvsp[0].A_name_ty_list));}
#line 2144 "y.tab.c"
    break;

  case 79:
#line 202 "tiger.y"
                                                                                {(yyval.A_namety) = A_Namety((yylsp[-3]).first_line, (yylsp[-3]).first_column, S_Symbol((yyvsp[-2].sval)), (yyvsp[0].A_ty));}
#line 2150 "y.tab.c"
    break;

  case 80:
#line 204 "tiger.y"
                                                                                {(yyval.A_ty) = A_NameTy((yylsp[0]).first_line, (yylsp[0]).first_column,S_Symbol((yyvsp[0].sval)));}
#line 2156 "y.tab.c"
    break;

  case 81:
#line 205 "tiger.y"
                                                                        {(yyval.A_ty) = A_RecordTy((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[-1].A_field_list));}
#line 2162 "y.tab.c"
    break;

  case 82:
#line 206 "tiger.y"
                                                                                {(yyval.A_ty) = A_ArrayTy((yylsp[-2]).first_line, (yylsp[-2]).first_column, S_Symbol((yyvsp[0].sval)));}
#line 2168 "y.tab.c"
    break;


#line 2172 "y.tab.c"

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
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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

  yyerror_range[1] = yylloc;

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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
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


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp, yylsp);
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
#line 210 "tiger.y"

int yyerror(const char *s)
{
	Error::error(s);
	exit(1);
}
