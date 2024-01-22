/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 21 "parser.y"


  struct Value {
    long long num;
    char *str;
    char *str1;
  };


#line 59 "parser.hpp"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    T_PROGRAM = 258,               /* T_PROGRAM  */
    T_IS = 259,                    /* T_IS  */
    T_IN = 260,                    /* T_IN  */
    T_END = 261,                   /* T_END  */
    T_PROCEDURE = 262,             /* T_PROCEDURE  */
    T_SEMICOLON = 263,             /* T_SEMICOLON  */
    T_COMMA = 264,                 /* T_COMMA  */
    T_EQ = 265,                    /* T_EQ  */
    T_NEQ = 266,                   /* T_NEQ  */
    T_LT = 267,                    /* T_LT  */
    T_GT = 268,                    /* T_GT  */
    T_LTEQ = 269,                  /* T_LTEQ  */
    T_GTEQ = 270,                  /* T_GTEQ  */
    T_ADD = 271,                   /* T_ADD  */
    T_SUB = 272,                   /* T_SUB  */
    T_DIV = 273,                   /* T_DIV  */
    T_MOD = 274,                   /* T_MOD  */
    T_MUL = 275,                   /* T_MUL  */
    T_ASSIGN = 276,                /* T_ASSIGN  */
    T_READ = 277,                  /* T_READ  */
    T_WRITE = 278,                 /* T_WRITE  */
    T_REPEAT = 279,                /* T_REPEAT  */
    T_UNTIL = 280,                 /* T_UNTIL  */
    T_WHILE = 281,                 /* T_WHILE  */
    T_DO = 282,                    /* T_DO  */
    T_ENDWHILE = 283,              /* T_ENDWHILE  */
    T_IF = 284,                    /* T_IF  */
    T_THEN = 285,                  /* T_THEN  */
    T_ELSE = 286,                  /* T_ELSE  */
    T_ENDIF = 287,                 /* T_ENDIF  */
    T_LEFTPARENTHESIS = 288,       /* T_LEFTPARENTHESIS  */
    T_RIGHTPARENTHESIS = 289,      /* T_RIGHTPARENTHESIS  */
    T_LEFT_BRACKET = 290,          /* T_LEFT_BRACKET  */
    T_RIGHT_BRACKET = 291,         /* T_RIGHT_BRACKET  */
    T_ERROR = 292,                 /* T_ERROR  */
    T = 293,                       /* T  */
    T_IDENTIFIER = 294,            /* T_IDENTIFIER  */
    T_NUM = 295                    /* T_NUM  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 31 "parser.y"

  Value value;
  char *str;
  long long num;

#line 122 "parser.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_HPP_INCLUDED  */
