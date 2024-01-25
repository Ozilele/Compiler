/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

  #include <iostream>
  #include <fstream>
  #include <vector>
  #include <string>
  #include <cstdio>
  #include "assembler_generator.hpp"
  #include "conditioner.hpp"

  extern int yylex();
  extern int yyparse();
  void yyerror(const char* const message);

  extern FILE *yyin;
  
  Compiler compiler;
  AssemblerGenerator asmGenerator(&compiler);
  Conditioner conditioner(&compiler);

#line 91 "parser.cpp"

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

#include "parser.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_T_PROGRAM = 3,                  /* T_PROGRAM  */
  YYSYMBOL_T_IS = 4,                       /* T_IS  */
  YYSYMBOL_T_IN = 5,                       /* T_IN  */
  YYSYMBOL_T_END = 6,                      /* T_END  */
  YYSYMBOL_T_PROCEDURE = 7,                /* T_PROCEDURE  */
  YYSYMBOL_T_SEMICOLON = 8,                /* T_SEMICOLON  */
  YYSYMBOL_T_COMMA = 9,                    /* T_COMMA  */
  YYSYMBOL_T_EQ = 10,                      /* T_EQ  */
  YYSYMBOL_T_NEQ = 11,                     /* T_NEQ  */
  YYSYMBOL_T_LT = 12,                      /* T_LT  */
  YYSYMBOL_T_GT = 13,                      /* T_GT  */
  YYSYMBOL_T_LTEQ = 14,                    /* T_LTEQ  */
  YYSYMBOL_T_GTEQ = 15,                    /* T_GTEQ  */
  YYSYMBOL_T_ADD = 16,                     /* T_ADD  */
  YYSYMBOL_T_SUB = 17,                     /* T_SUB  */
  YYSYMBOL_T_DIV = 18,                     /* T_DIV  */
  YYSYMBOL_T_MOD = 19,                     /* T_MOD  */
  YYSYMBOL_T_MUL = 20,                     /* T_MUL  */
  YYSYMBOL_T_ASSIGN = 21,                  /* T_ASSIGN  */
  YYSYMBOL_T_READ = 22,                    /* T_READ  */
  YYSYMBOL_T_WRITE = 23,                   /* T_WRITE  */
  YYSYMBOL_T_REPEAT = 24,                  /* T_REPEAT  */
  YYSYMBOL_T_UNTIL = 25,                   /* T_UNTIL  */
  YYSYMBOL_T_WHILE = 26,                   /* T_WHILE  */
  YYSYMBOL_T_DO = 27,                      /* T_DO  */
  YYSYMBOL_T_ENDWHILE = 28,                /* T_ENDWHILE  */
  YYSYMBOL_T_IF = 29,                      /* T_IF  */
  YYSYMBOL_T_THEN = 30,                    /* T_THEN  */
  YYSYMBOL_T_ELSE = 31,                    /* T_ELSE  */
  YYSYMBOL_T_ENDIF = 32,                   /* T_ENDIF  */
  YYSYMBOL_T_LEFTPARENTHESIS = 33,         /* T_LEFTPARENTHESIS  */
  YYSYMBOL_T_RIGHTPARENTHESIS = 34,        /* T_RIGHTPARENTHESIS  */
  YYSYMBOL_T_LEFT_BRACKET = 35,            /* T_LEFT_BRACKET  */
  YYSYMBOL_T_RIGHT_BRACKET = 36,           /* T_RIGHT_BRACKET  */
  YYSYMBOL_T_ERROR = 37,                   /* T_ERROR  */
  YYSYMBOL_T = 38,                         /* T  */
  YYSYMBOL_T_IDENTIFIER = 39,              /* T_IDENTIFIER  */
  YYSYMBOL_T_NUM = 40,                     /* T_NUM  */
  YYSYMBOL_YYACCEPT = 41,                  /* $accept  */
  YYSYMBOL_program_all = 42,               /* program_all  */
  YYSYMBOL_start_main = 43,                /* start_main  */
  YYSYMBOL_procedures = 44,                /* procedures  */
  YYSYMBOL_main = 45,                      /* main  */
  YYSYMBOL_commands = 46,                  /* commands  */
  YYSYMBOL_command = 47,                   /* command  */
  YYSYMBOL_start = 48,                     /* start  */
  YYSYMBOL_proc_head = 49,                 /* proc_head  */
  YYSYMBOL_proc_call = 50,                 /* proc_call  */
  YYSYMBOL_declarations = 51,              /* declarations  */
  YYSYMBOL_args_decl = 52,                 /* args_decl  */
  YYSYMBOL_args = 53,                      /* args  */
  YYSYMBOL_expression = 54,                /* expression  */
  YYSYMBOL_condition = 55,                 /* condition  */
  YYSYMBOL_value = 56,                     /* value  */
  YYSYMBOL_identifier = 57                 /* identifier  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
typedef yytype_int8 yy_state_t;

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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   153

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  48
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  118

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   295


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

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
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    70,    70,    76,    86,    93,   100,   107,   110,   116,
     123,   129,   156,   165,   173,   182,   188,   191,   199,   218,
     225,   238,   282,   285,   288,   291,   297,   303,   308,   313,
     321,   326,   333,   340,   349,   358,   367,   376,   388,   392,
     396,   400,   404,   408,   415,   422,   430,   441,   452
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "T_PROGRAM", "T_IS",
  "T_IN", "T_END", "T_PROCEDURE", "T_SEMICOLON", "T_COMMA", "T_EQ",
  "T_NEQ", "T_LT", "T_GT", "T_LTEQ", "T_GTEQ", "T_ADD", "T_SUB", "T_DIV",
  "T_MOD", "T_MUL", "T_ASSIGN", "T_READ", "T_WRITE", "T_REPEAT", "T_UNTIL",
  "T_WHILE", "T_DO", "T_ENDWHILE", "T_IF", "T_THEN", "T_ELSE", "T_ENDIF",
  "T_LEFTPARENTHESIS", "T_RIGHTPARENTHESIS", "T_LEFT_BRACKET",
  "T_RIGHT_BRACKET", "T_ERROR", "T", "T_IDENTIFIER", "T_NUM", "$accept",
  "program_all", "start_main", "procedures", "main", "commands", "command",
  "start", "proc_head", "proc_call", "declarations", "args_decl", "args",
  "expression", "condition", "value", "identifier", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-47)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -47,     6,     5,   -47,    23,    61,    46,    85,    90,   -47,
     -13,    -3,    -2,    56,   -47,    10,    93,    15,    18,    93,
      51,   -47,    47,   -47,    58,    27,   -22,    -1,   -47,    29,
      97,    96,    78,    93,    80,    12,    93,    81,   -47,    87,
     116,   -47,   117,   -47,    88,    52,   -47,   -47,    93,    27,
      27,   -47,    27,    95,    24,    94,   -47,    26,   -47,   -47,
     -47,   -47,    11,   103,   109,   -15,    99,   123,   118,   138,
     124,   -47,   -47,   107,   -47,   110,   -47,   -47,   -47,    27,
      93,    27,    27,    27,    27,    27,    27,    93,   -47,    27,
      27,    27,    27,    27,   114,   -47,   143,    65,   -47,   -47,
     -47,   -47,   -47,   -47,    89,   -47,   -47,   -47,   -47,   -47,
     -47,   -47,   -47,   -47,    28,    93,    91,   -47
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       6,     0,     3,     1,     0,     0,     0,     0,     0,     2,
       0,     0,     0,     0,    28,     0,    19,    24,     0,    19,
       0,    29,     0,    20,     0,     0,    46,    19,    10,     0,
       0,     0,     0,    19,     0,    19,    19,     0,    26,    46,
       0,    44,     0,    45,     0,     0,     5,     9,    19,     0,
       0,    16,     0,     0,    19,    22,     8,    19,    27,    17,
      18,    31,     0,     0,     0,    19,     0,     0,     0,     0,
      32,    25,     4,     0,     7,     0,    21,    48,    47,     0,
      19,     0,     0,     0,     0,     0,     0,    19,    11,     0,
       0,     0,     0,     0,     0,    30,     0,    19,    38,    39,
      41,    40,    43,    42,    19,    33,    34,    36,    37,    35,
      23,    15,    14,    13,     0,    19,    19,    12
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -47,   -47,   -47,   -47,   -47,   -19,   -26,    48,   -47,   -47,
     141,   -47,   -47,   -47,   -46,    17,    -9
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     5,     2,     9,    27,    28,    29,     7,    30,
      18,    15,    62,    69,    66,    67,    31
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      35,    47,    16,    19,    68,    46,     3,    24,    25,    47,
      79,    44,     4,    45,    54,    40,    43,    57,    56,    22,
      75,    24,    25,    33,    26,    13,    14,    34,    47,    65,
      72,    47,    74,    96,    24,    25,    17,    17,    26,    47,
      43,    43,    42,    43,    23,    76,    24,    25,    24,    25,
      32,    26,    48,    48,    49,    49,    36,    50,    50,   115,
      34,    97,     6,    26,     8,    26,    39,    41,   104,    70,
      43,    47,    43,    43,    43,    43,    43,    43,    47,    10,
      43,    43,    43,    43,    43,    37,    38,    24,    25,    11,
      47,    63,    64,   112,    12,    21,   116,    39,    98,    99,
     100,   101,   102,   103,    26,    51,   105,   106,   107,   108,
     109,    24,    25,    24,    25,    24,    25,    52,    53,    55,
      58,   113,    45,   117,    59,    60,    80,    61,    26,    73,
      26,    71,    26,    81,    82,    83,    84,    85,    86,    77,
      89,    90,    91,    92,    93,    78,    88,    94,    87,    95,
     110,   111,   114,    20
};

static const yytype_int8 yycheck[] =
{
      19,    27,     5,     5,    50,     6,     0,    22,    23,    35,
      25,    33,     7,    35,    33,    24,    25,    36,     6,     9,
       9,    22,    23,     5,    39,    38,    39,     9,    54,    48,
       6,    57,     6,    79,    22,    23,    39,    39,    39,    65,
      49,    50,    25,    52,    34,    34,    22,    23,    22,    23,
      35,    39,    24,    24,    26,    26,     5,    29,    29,    31,
       9,    80,    39,    39,     3,    39,    39,    40,    87,    52,
      79,    97,    81,    82,    83,    84,    85,    86,   104,    33,
      89,    90,    91,    92,    93,    38,    39,    22,    23,     4,
     116,    39,    40,    28,     4,    39,   115,    39,    81,    82,
      83,    84,    85,    86,    39,     8,    89,    90,    91,    92,
      93,    22,    23,    22,    23,    22,    23,    21,    40,    39,
      39,    32,    35,    32,     8,     8,    27,    39,    39,    35,
      39,    36,    39,    10,    11,    12,    13,    14,    15,    36,
      16,    17,    18,    19,    20,    36,     8,    40,    30,    39,
      36,     8,   104,    12
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    42,    44,     0,     7,    43,    39,    49,     3,    45,
      33,     4,     4,    38,    39,    52,     5,    39,    51,     5,
      51,    39,     9,    34,    22,    23,    39,    46,    47,    48,
      50,    57,    35,     5,     9,    46,     5,    38,    39,    39,
      57,    40,    56,    57,    33,    35,     6,    47,    24,    26,
      29,     8,    21,    40,    46,    39,     6,    46,    39,     8,
       8,    39,    53,    39,    40,    46,    55,    56,    55,    54,
      56,    36,     6,    35,     6,     9,    34,    36,    36,    25,
      27,    10,    11,    12,    13,    14,    15,    30,     8,    16,
      17,    18,    19,    20,    40,    39,    55,    46,    56,    56,
      56,    56,    56,    56,    46,    56,    56,    56,    56,    56,
      36,     8,    28,    32,    48,    31,    46,    32
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    43,    44,    44,    44,    45,    45,    46,
      46,    47,    47,    47,    47,    47,    47,    47,    47,    48,
      49,    50,    51,    51,    51,    51,    52,    52,    52,    52,
      53,    53,    54,    54,    54,    54,    54,    54,    55,    55,
      55,    55,    55,    55,    56,    56,    57,    57,    57
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     0,     8,     7,     0,     6,     5,     2,
       1,     4,     9,     6,     6,     6,     2,     3,     3,     0,
       4,     4,     3,     6,     1,     4,     3,     4,     1,     2,
       3,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     1,     4,     4
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program_all: procedures start_main main  */
#line 70 "parser.y"
                                 {
        compiler.add_machine_command("HALT");
      }
#line 1212 "parser.cpp"
    break;

  case 3: /* start_main: %empty  */
#line 76 "parser.y"
  {
    compiler.add_beginning_procedure("", compiler.getCommandsNumber());
    if(compiler.getCommandsNumber() == 1) {
      compiler.clearCommands();
    } else {
      compiler.change_command(std::to_string(compiler.getCommandsNumber()), 0, 1);
    }
  }
#line 1225 "parser.cpp"
    break;

  case 4: /* procedures: procedures T_PROCEDURE proc_head T_IS declarations T_IN commands T_END  */
#line 86 "parser.y"
                                                                             {
        compiler.set_number(compiler.get_declaration(" RETURN"), 1);
        compiler.add_machine_command("LOAD b");
        compiler.clear_declaration();
        compiler.add_machine_command("JUMPR a");
        compiler.clear_register_value();
      }
#line 1237 "parser.cpp"
    break;

  case 5: /* procedures: procedures T_PROCEDURE proc_head T_IS T_IN commands T_END  */
#line 93 "parser.y"
                                                                  {
        compiler.set_number(compiler.get_declaration(" RETURN"), 1);
        compiler.add_machine_command("LOAD b");
        compiler.clear_declaration();
        compiler.add_machine_command("JUMPR a");
        compiler.clear_register_value();
      }
#line 1249 "parser.cpp"
    break;

  case 6: /* procedures: %empty  */
#line 100 "parser.y"
        {
        // std::cout << " Nie ma procedur " << std::endl;
        compiler.add_machine_command("JUMP ");
      }
#line 1258 "parser.cpp"
    break;

  case 7: /* main: T_PROGRAM T_IS declarations T_IN commands T_END  */
#line 107 "parser.y"
                                                    {
      // Finish compilation
    }
#line 1266 "parser.cpp"
    break;

  case 8: /* main: T_PROGRAM T_IS T_IN commands T_END  */
#line 110 "parser.y"
                                         {
      // Finish compilation
    }
#line 1274 "parser.cpp"
    break;

  case 9: /* commands: commands command  */
#line 116 "parser.y"
                          {
        if((yyvsp[-1].num) > (yyvsp[0].num)) {
          (yyval.num) = (yyvsp[-1].num);
        } else {
          (yyval.num) = (yyvsp[0].num);
        }
      }
#line 1286 "parser.cpp"
    break;

  case 10: /* commands: command  */
#line 123 "parser.y"
                {
        (yyval.num) = (yyvsp[0].num);
      }
#line 1294 "parser.cpp"
    break;

  case 11: /* command: identifier T_ASSIGN expression T_SEMICOLON  */
#line 129 "parser.y"
                                                 { // tested
        bool whether = false;
        for(auto i : compiler.function_arguments) {
          if((i.first <= compiler.get_declaration((yyvsp[-3].value).str) && compiler.get_declaration((yyvsp[-3].value).str) < i.second) || (i.first <= compiler.get_declaration((yyvsp[-3].value).str1) && compiler.get_declaration((yyvsp[-3].value).str1) < i.second)) {
            compiler.add_machine_command("PUT h");
            whether = true;
            break;
          }
        }

        if(whether == false && (yyvsp[-3].value).num == -1) { // case T[a] := ...
          compiler.add_machine_command("PUT h");
          whether = true;
        }

        compiler.check_declaration((yyvsp[-3].value).num, (yyvsp[-3].value).str, (yyvsp[-3].value).str1); // check if variable was declared
        compiler.get_register_value((yyvsp[-3].value).num, (yyvsp[-3].value).str, (yyvsp[-3].value).str1, 1);

        if(whether) {
          compiler.add_machine_command("PUT b"); // r_b <- r_a
          compiler.add_machine_command("GET h"); // r_a <- r_h
        }
        compiler.add_machine_command("STORE b");
        compiler.add_machine_command("RST b");
        compiler.set_variable_initialization((yyvsp[-3].value).str);
        (yyval.num) = compiler.getCommandsNumber();
      }
#line 1326 "parser.cpp"
    break;

  case 12: /* command: start T_IF condition T_THEN commands start T_ELSE commands T_ENDIF  */
#line 156 "parser.y"
                                                                           { // tested
        std::cout << (yyvsp[-4].num) << ", if scope" << std::endl;
        std::cout << (yyvsp[-6].num)  << ", cond scope " << std::endl;
        std::cout << (yyvsp[-1].num) << ", else scope" << std::endl;
        compiler.change_command(std::to_string((yyvsp[-4].num) + 1), (yyvsp[-6].num) - 1, 1); // albo $3 -1
        compiler.add_commands_inside("JUMP " + std::to_string((yyvsp[-1].num) + 1), (yyvsp[-4].num)); // method which adds jump when the if ends so that else block will not be completedx
        (yyval.num) = compiler.getCommandsNumber();
        compiler.clear_register_value();
      }
#line 1340 "parser.cpp"
    break;

  case 13: /* command: start T_IF condition T_THEN commands T_ENDIF  */
#line 165 "parser.y"
                                                     { // tested
        // $5 is the number of line where the scope of this if ends, $3 is the number of line where the condition of if ends
        std::cout << (yyvsp[-1].num) << ", ifik" << std::endl;
        std::cout << (yyvsp[-3].num) << ", cond" << std::endl;
        compiler.change_command(std::to_string((yyvsp[-1].num)), (yyvsp[-3].num) - 1, 1); // -1 because of index, last command of condition is always a jump
        (yyval.num) = compiler.getCommandsNumber();
        compiler.clear_register_value();
      }
#line 1353 "parser.cpp"
    break;

  case 14: /* command: start T_WHILE condition T_DO commands T_ENDWHILE  */
#line 173 "parser.y"
                                                         { // tested
        std::cout << (yyvsp[-3].num) << ", cond while" << std::endl;
        std::cout << std::to_string(compiler.getCommandsNumber() + 1) << " command nr" << std::endl;
        // $3 to koniec warunku condition, $1 to numer linii od ktorej zaczyna sie petla while
        compiler.change_command(std::to_string(compiler.getCommandsNumber() + 1), (yyvsp[-3].num), 1); // dodanie wartosci jumpa w przypadku niespelnienia condition
        compiler.add_machine_command("JUMP " + std::to_string((yyvsp[-5].num))); // dodanie jumpa do startu pętli
        (yyval.num) = compiler.getCommandsNumber();
        compiler.clear_register_value();
      }
#line 1367 "parser.cpp"
    break;

  case 15: /* command: start T_REPEAT commands T_UNTIL condition T_SEMICOLON  */
#line 182 "parser.y"
                                                              { // tested
        std::cout << (yyvsp[-5].num) << ", " << (yyvsp[-1].num) << ", " << std::endl;
        compiler.change_command(std::to_string((yyvsp[-5].num)), (yyvsp[-1].num) - 1, 1); // Jump to the start of repeat loop after condition is checked
        (yyval.num) = compiler.getCommandsNumber();
        compiler.clear_register_value();
      }
#line 1378 "parser.cpp"
    break;

  case 16: /* command: proc_call T_SEMICOLON  */
#line 188 "parser.y"
                              {
        (yyval.num) = compiler.getCommandsNumber();
      }
#line 1386 "parser.cpp"
    break;

  case 17: /* command: T_READ identifier T_SEMICOLON  */
#line 191 "parser.y"
                                      { // READ x, READ T[2], T[a] // tested
        compiler.add_machine_command("READ");
        compiler.get_register_value((yyvsp[-1].value).num, (yyvsp[-1].value).str, (yyvsp[-1].value).str1, 1);
        compiler.add_machine_command("STORE b"); // p_rb <- ra
        // change_variable_initialization
        // compiler.set_variable_initialization($2.str);
        (yyval.num) = compiler.getCommandsNumber();
      }
#line 1399 "parser.cpp"
    break;

  case 18: /* command: T_WRITE value T_SEMICOLON  */
#line 199 "parser.y"
                                  { // tested
        if(strcmp((yyvsp[-1].value).str, "") == 0) {
          compiler.set_number((yyvsp[-1].value).num, 0);
        } else {
          compiler.get_register_value((yyvsp[-1].value).num, (yyvsp[-1].value).str, (yyvsp[-1].value).str1, 1);
          if(!compiler.checkLastCommand("STORE b")) {
            if(compiler.checkLastCommand("LOAD b")) {
              compiler.add_machine_command("LOAD a");
            } else {
              compiler.add_machine_command("LOAD b");
            }
          }
        }
        compiler.add_machine_command("WRITE");
        (yyval.num) = compiler.getCommandsNumber();
      }
#line 1420 "parser.cpp"
    break;

  case 19: /* start: %empty  */
#line 218 "parser.y"
    {
      (yyval.num) = compiler.getCommandsNumber();
      compiler.clear_register_value();
    }
#line 1429 "parser.cpp"
    break;

  case 20: /* proc_head: T_IDENTIFIER T_LEFTPARENTHESIS args_decl T_RIGHTPARENTHESIS  */
#line 225 "parser.y"
                                                                  {
        std::cout << "Procedure name: " << (yyvsp[-3].str) << std::endl;
        compiler.add_beginning_procedure((yyvsp[-3].str), compiler.getCommandsNumber());
        compiler.add_declaration(" RETURN", 1);
        compiler.add_procedure((yyvsp[-3].str));
        int min = compiler.get_first_declaration();
        int max = compiler.get_declaration(" RETURN"); // zakres komorek pamieci ktore sa zarezerwowane dla procedury
        std::cout << "func args " << min << ", " << max << std::endl;
        compiler.function_arguments.push_back(std::make_pair(min, max));
      }
#line 1444 "parser.cpp"
    break;

  case 21: /* proc_call: T_IDENTIFIER T_LEFTPARENTHESIS args T_RIGHTPARENTHESIS  */
#line 238 "parser.y"
                                                             {
        if(compiler.size_args_procedure((yyvsp[-3].str)) - 1 != compiler.arguments.size()) {
          if(compiler.size_args_procedure((yyvsp[-3].str)) == -1) {
            yyerror((std::string("Undefined procedure ") + (yyvsp[-3].str)).c_str());
          }
          yyerror((std::string("Invalid procedure params ") + (yyvsp[-3].str)).c_str());
        }
        if(compiler.getCommandsNumber() < compiler.get_beginning_next_procedure((yyvsp[-3].str)) || compiler.get_beginning_next_procedure((yyvsp[-3].str)) == -1) {
          yyerror((std::string("Invalid procedure use ") + (yyvsp[-3].str)).c_str());
        }

        std::vector<std::pair<int, bool>> args = compiler.get_procedure_args((yyvsp[-3].str));
        
        for(size_t i = 0; i < compiler.arguments.size(); ++i) { // procedure call arg. size
          compiler.set_variable_initialization(compiler.arguments[i]);
          std::cout << "Param to procedure " << compiler.arguments[i] << std::endl;
          if(args[i].second == 1) {
            if(!compiler.is_Tab(compiler.arguments[i])) {
              yyerror((std::string("Invalid procedure params ") + (yyvsp[-3].str)).c_str());
            }
          }
          compiler.get_register_value(0, compiler.arguments[i], nullptr, 0); // r_a <- 
          std::cout << " po reg: " << compiler.getIndex((yyvsp[-3].str)) << std::endl;
          // compiler.add_machine_command("RST b");  
          // std::cout << compiler.get_declaration(compiler.arguments[i]) << " ss" << std::endl;
          compiler.set_number(compiler.getIndex((yyvsp[-3].str)), 1);
          compiler.add_machine_command("STORE b");
          compiler.add_machine_command("RST a");
        }

        compiler.set_number(compiler.getIndex((yyvsp[-3].str)), 1);
        compiler.add_machine_command("RST a");
        compiler.add_machine_command("INC a");
        compiler.add_machine_command("SHL a");
        compiler.add_machine_command("SHL a");
        compiler.add_machine_command("STRK c");
        compiler.add_machine_command("ADD c");
        compiler.add_machine_command("STORE b");
        compiler.add_machine_command("JUMP " + std::to_string(compiler.get_beginning_procedure((yyvsp[-3].str)))); // jump to the line in which procedure starts
        compiler.arguments.clear();
      }
#line 1490 "parser.cpp"
    break;

  case 22: /* declarations: declarations T_COMMA T_IDENTIFIER  */
#line 282 "parser.y"
                                        {
        compiler.add_declaration((yyvsp[0].str), 1); // memory Cell to 1
      }
#line 1498 "parser.cpp"
    break;

  case 23: /* declarations: declarations T_COMMA T_IDENTIFIER T_LEFT_BRACKET T_NUM T_RIGHT_BRACKET  */
#line 285 "parser.y"
                                                                               {
        compiler.add_declaration((yyvsp[-3].str), (yyvsp[-1].num)); // tab 
      }
#line 1506 "parser.cpp"
    break;

  case 24: /* declarations: T_IDENTIFIER  */
#line 288 "parser.y"
                     {
        compiler.add_declaration((yyvsp[0].str), 1);
      }
#line 1514 "parser.cpp"
    break;

  case 25: /* declarations: T_IDENTIFIER T_LEFT_BRACKET T_NUM T_RIGHT_BRACKET  */
#line 291 "parser.y"
                                                          { // sito[100]
        compiler.add_declaration((yyvsp[-3].str), (yyvsp[-1].num));
      }
#line 1522 "parser.cpp"
    break;

  case 26: /* args_decl: args_decl T_COMMA T_IDENTIFIER  */
#line 297 "parser.y"
                                     { // args_decl, x
        // parametry definiowane w procedurze proc_name(a, b, c)
        compiler.procedure_args.push_back(false);
        compiler.add_declaration((yyvsp[0].str), 1);
        compiler.set_variable_initialization((yyvsp[0].str));
      }
#line 1533 "parser.cpp"
    break;

  case 27: /* args_decl: args_decl T_COMMA T T_IDENTIFIER  */
#line 303 "parser.y"
                                         { // args_decl, T x
        compiler.procedure_args.push_back(true);
        compiler.add_declaration((yyvsp[0].str), 1);
        compiler.set_variable_initialization((yyvsp[0].str));
      }
#line 1543 "parser.cpp"
    break;

  case 28: /* args_decl: T_IDENTIFIER  */
#line 308 "parser.y"
                     { // variable
        compiler.procedure_args.push_back(false);
        compiler.add_declaration((yyvsp[0].str), 1);
        compiler.set_variable_initialization((yyvsp[0].str));
      }
#line 1553 "parser.cpp"
    break;

  case 29: /* args_decl: T T_IDENTIFIER  */
#line 313 "parser.y"
                       {
        compiler.procedure_args.push_back(true);
        compiler.add_declaration((yyvsp[0].str), 1);
        compiler.set_variable_initialization((yyvsp[0].str));
      }
#line 1563 "parser.cpp"
    break;

  case 30: /* args: args T_COMMA T_IDENTIFIER  */
#line 321 "parser.y"
                              {
      // procedure call
      compiler.arguments.insert(compiler.arguments.begin(), (yyvsp[0].str));
      // compiler.arguments.push_back($3); // dodanie przekazanych procedurze parametrów
    }
#line 1573 "parser.cpp"
    break;

  case 31: /* args: T_IDENTIFIER  */
#line 326 "parser.y"
                   {
      compiler.arguments.push_back((yyvsp[0].str));
      // compiler.arguments.insert(compiler.arguments.begin(), $1);
    }
#line 1582 "parser.cpp"
    break;

  case 32: /* expression: value  */
#line 333 "parser.y"
            {
        std::cout << (yyvsp[0].value).num << " val " << std::endl;
        if(strcmp((yyvsp[0].value).str, "") != 0) {
          compiler.check_declaration((yyvsp[0].value).num, (yyvsp[0].value).str, (yyvsp[0].value).str1);
        }
        asmGenerator.get_number((yyvsp[0].value).num, (yyvsp[0].value).str, (yyvsp[0].value).str1);
      }
#line 1594 "parser.cpp"
    break;

  case 33: /* expression: value T_ADD value  */
#line 340 "parser.y"
                          {
        if(strcmp((yyvsp[-2].value).str, "") != 0) {
          compiler.check_declaration((yyvsp[-2].value).num, (yyvsp[-2].value).str, (yyvsp[-2].value).str1);
        }
        if(strcmp((yyvsp[0].value).str, "") != 0) {
          compiler.check_declaration((yyvsp[0].value).num, (yyvsp[0].value).str, (yyvsp[0].value).str1);
        }
        asmGenerator.add((yyvsp[-2].value).num, (yyvsp[-2].value).str, (yyvsp[-2].value).str1, (yyvsp[0].value).num, (yyvsp[0].value).str, (yyvsp[0].value).str1);
      }
#line 1608 "parser.cpp"
    break;

  case 34: /* expression: value T_SUB value  */
#line 349 "parser.y"
                          {
        if(strcmp((yyvsp[-2].value).str, "") != 0) {
          compiler.check_declaration((yyvsp[-2].value).num, (yyvsp[-2].value).str, (yyvsp[-2].value).str1);
        }
        if(strcmp((yyvsp[0].value).str, "") != 0) {
          compiler.check_declaration((yyvsp[0].value).num, (yyvsp[0].value).str, (yyvsp[0].value).str1);
        }
        asmGenerator.subtract((yyvsp[-2].value).num, (yyvsp[-2].value).str, (yyvsp[-2].value).str1, (yyvsp[0].value).num, (yyvsp[0].value).str, (yyvsp[0].value).str1);
      }
#line 1622 "parser.cpp"
    break;

  case 35: /* expression: value T_MUL value  */
#line 358 "parser.y"
                          {
        if(strcmp((yyvsp[-2].value).str, "") != 0) {
          compiler.check_declaration((yyvsp[-2].value).num, (yyvsp[-2].value).str, (yyvsp[-2].value).str1);
        }
        if(strcmp((yyvsp[0].value).str, "") != 0) {
          compiler.check_declaration((yyvsp[0].value).num, (yyvsp[0].value).str, (yyvsp[0].value).str1);
        }
        asmGenerator.multiply((yyvsp[-2].value).num, (yyvsp[-2].value).str, (yyvsp[-2].value).str1, (yyvsp[0].value).num, (yyvsp[0].value).str, (yyvsp[0].value).str1);
      }
#line 1636 "parser.cpp"
    break;

  case 36: /* expression: value T_DIV value  */
#line 367 "parser.y"
                          {
        if(strcmp((yyvsp[-2].value).str, "") != 0) {
          compiler.check_declaration((yyvsp[-2].value).num, (yyvsp[-2].value).str, (yyvsp[-2].value).str1);
        }
        if(strcmp((yyvsp[0].value).str, "") != 0) {
          compiler.check_declaration((yyvsp[0].value).num, (yyvsp[0].value).str, (yyvsp[0].value).str1);
        }
        asmGenerator.divide((yyvsp[-2].value).num, (yyvsp[-2].value).str, (yyvsp[-2].value).str1, (yyvsp[0].value).num, (yyvsp[0].value).str, (yyvsp[0].value).str1);
      }
#line 1650 "parser.cpp"
    break;

  case 37: /* expression: value T_MOD value  */
#line 376 "parser.y"
                          {
        if(strcmp((yyvsp[-2].value).str, "") != 0) {
          compiler.check_declaration((yyvsp[-2].value).num, (yyvsp[-2].value).str, (yyvsp[-2].value).str1);
        }
        if(strcmp((yyvsp[0].value).str, "") != 0) {
          compiler.check_declaration((yyvsp[0].value).num, (yyvsp[0].value).str, (yyvsp[0].value).str1);
        }
        asmGenerator.modulo((yyvsp[-2].value).num, (yyvsp[-2].value).str, (yyvsp[-2].value).str1, (yyvsp[0].value).num, (yyvsp[0].value).str, (yyvsp[0].value).str1);
      }
#line 1664 "parser.cpp"
    break;

  case 38: /* condition: value T_EQ value  */
#line 388 "parser.y"
                       {
        conditioner.equal((yyvsp[-2].value).num, (yyvsp[-2].value).str, (yyvsp[-2].value).str1, (yyvsp[0].value).num, (yyvsp[0].value).str, (yyvsp[0].value).str1);
        (yyval.num) = compiler.getCommandsNumber();
      }
#line 1673 "parser.cpp"
    break;

  case 39: /* condition: value T_NEQ value  */
#line 392 "parser.y"
                          {
        conditioner.not_equal((yyvsp[-2].value).num, (yyvsp[-2].value).str, (yyvsp[-2].value).str1, (yyvsp[0].value).num, (yyvsp[0].value).str, (yyvsp[0].value).str1);
        (yyval.num) = compiler.getCommandsNumber();
      }
#line 1682 "parser.cpp"
    break;

  case 40: /* condition: value T_GT value  */
#line 396 "parser.y"
                         {
        conditioner.greater((yyvsp[-2].value).num, (yyvsp[-2].value).str, (yyvsp[-2].value).str1, (yyvsp[0].value).num, (yyvsp[0].value).str, (yyvsp[0].value).str1);
        (yyval.num) = compiler.getCommandsNumber();
      }
#line 1691 "parser.cpp"
    break;

  case 41: /* condition: value T_LT value  */
#line 400 "parser.y"
                         {
        conditioner.less((yyvsp[-2].value).num, (yyvsp[-2].value).str, (yyvsp[-2].value).str1, (yyvsp[0].value).num, (yyvsp[0].value).str, (yyvsp[0].value).str1);
        (yyval.num) = compiler.getCommandsNumber();
      }
#line 1700 "parser.cpp"
    break;

  case 42: /* condition: value T_GTEQ value  */
#line 404 "parser.y"
                           {
        conditioner.greater_equal((yyvsp[-2].value).num, (yyvsp[-2].value).str, (yyvsp[-2].value).str1, (yyvsp[0].value).num, (yyvsp[0].value).str, (yyvsp[0].value).str1);
        (yyval.num) = compiler.getCommandsNumber();
      }
#line 1709 "parser.cpp"
    break;

  case 43: /* condition: value T_LTEQ value  */
#line 408 "parser.y"
                           {
        conditioner.less_equal((yyvsp[-2].value).num, (yyvsp[-2].value).str, (yyvsp[-2].value).str1, (yyvsp[0].value).num, (yyvsp[0].value).str, (yyvsp[0].value).str1);
        (yyval.num) = compiler.getCommandsNumber();
      }
#line 1718 "parser.cpp"
    break;

  case 44: /* value: T_NUM  */
#line 415 "parser.y"
          {
      (yyval.value).num = (yyvsp[0].num);
      (yyval.value).str = new char[1];
      (yyval.value).str1 = new char[1];
      (yyval.value).str[0] = '\0';
      (yyval.value).str1[0] = '\0';
    }
#line 1730 "parser.cpp"
    break;

  case 45: /* value: identifier  */
#line 422 "parser.y"
                 {
      (yyval.value).num = (yyvsp[0].value).num;
      (yyval.value).str = (yyvsp[0].value).str;
      (yyval.value).str1 = (yyvsp[0].value).str1;
    }
#line 1740 "parser.cpp"
    break;

  case 46: /* identifier: T_IDENTIFIER  */
#line 430 "parser.y"
                   {
        std::string check = compiler.check_var_declaration((yyvsp[0].str), false);
        if(check != "") {
          std::cout << check << std::endl;
          exit(1);
        }
        (yyval.value).num = 0;
        (yyval.value).str = (yyvsp[0].str); // nazwa zmiennej
        (yyval.value).str1 = new char[1];
        (yyval.value).str1[0] = '\0';
      }
#line 1756 "parser.cpp"
    break;

  case 47: /* identifier: T_IDENTIFIER T_LEFT_BRACKET T_NUM T_RIGHT_BRACKET  */
#line 441 "parser.y"
                                                          { // sito[10]
        std::string check = compiler.check_var_declaration((yyvsp[-3].str), true);
        if(check != "") {
          std::cout << check << std::endl;
          exit(1);
        }
        (yyval.value).num = (yyvsp[-1].num); // numer indeksu w tablicy
        (yyval.value).str = (yyvsp[-3].str); // nazwa tablicy(zmiennej)
        (yyval.value).str1 = new char[1];
        (yyval.value).str1[0] = '\0';
      }
#line 1772 "parser.cpp"
    break;

  case 48: /* identifier: T_IDENTIFIER T_LEFT_BRACKET T_IDENTIFIER T_RIGHT_BRACKET  */
#line 452 "parser.y"
                                                                 { // T[a]
        std::string check = compiler.check_var_declaration((yyvsp[-3].str), true);
        if(check != "") {
          std::cout << check << std::endl;
          exit(1);
        }
        (yyval.value).num = -1; // -1 bo indeks nie jest cyfra tylko zmienna
        (yyval.value).str = (yyvsp[-3].str);
        (yyval.value).str1 = (yyvsp[-1].str); // indeks w tablicy to zmienna
      }
#line 1787 "parser.cpp"
    break;


#line 1791 "parser.cpp"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 464 "parser.y"


void yyerror(const char* const message) {
  std::cout << "CO tam " << std::endl;
  std::cout << "Error: " <<  message << std::endl;
  exit(1);
}

int execute(const char* input_file, const char* output_file) {
  // kompilator <nazwa input file> <nazwa_output_file>
  yyin = fopen(input_file, "r");

  std::ofstream outputStream;
  outputStream.open(output_file);

  yyparse();

  for(const auto &code : compiler.getCommands()) {
    outputStream << code << std::endl;
  }

  fclose(yyin);

  return 0;
}
