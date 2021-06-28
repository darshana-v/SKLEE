/* A Bison parser, made by GNU Bison 3.7.5.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_KLEE_TOOLS_KLEE_GRAMMAR_H_INCLUDED
# define YY_YY_KLEE_TOOLS_KLEE_GRAMMAR_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    ENUM = 258,                    /* ENUM  */
    STRUCT = 259,                  /* STRUCT  */
    WHILE = 260,                   /* WHILE  */
    DO = 261,                      /* DO  */
    FOR = 262,                     /* FOR  */
    IF = 263,                      /* IF  */
    CONTINUE = 264,                /* CONTINUE  */
    BREAK = 265,                   /* BREAK  */
    RETURN = 266,                  /* RETURN  */
    SWITCH = 267,                  /* SWITCH  */
    IMPORT = 268,                  /* IMPORT  */
    CONTRACT = 269,                /* CONTRACT  */
    AS = 270,                      /* AS  */
    PUBLIC = 271,                  /* PUBLIC  */
    PRIVATE = 272,                 /* PRIVATE  */
    FUNCTION = 273,                /* FUNCTION  */
    INTERNAL = 274,                /* INTERNAL  */
    CONSTANT = 275,                /* CONSTANT  */
    DEFAULT = 276,                 /* DEFAULT  */
    CASE = 277,                    /* CASE  */
    BEG_TAB = 278,                 /* BEG_TAB  */
    END_TAB = 279,                 /* END_TAB  */
    L_CURLY_B = 280,               /* L_CURLY_B  */
    R_CURLY_B = 281,               /* R_CURLY_B  */
    PRAGMA = 282,                  /* PRAGMA  */
    LIBRARY = 283,                 /* LIBRARY  */
    INTERFACE = 284,               /* INTERFACE  */
    MODIFIER = 285,                /* MODIFIER  */
    IS = 286,                      /* IS  */
    MEMORY = 287,                  /* MEMORY  */
    STORAGE = 288,                 /* STORAGE  */
    CALLDATA = 289,                /* CALLDATA  */
    SEND = 290,                    /* SEND  */
    CALL = 291,                    /* CALL  */
    TRANSFER = 292,                /* TRANSFER  */
    ADDRESS = 293,                 /* ADDRESS  */
    DOT = 294,                     /* DOT  */
    BOOL = 295,                    /* BOOL  */
    OPT_L = 296,                   /* OPT_L  */
    OPT_R = 297,                   /* OPT_R  */
    SPACE = 298,                   /* SPACE  */
    BYTE = 299,                    /* BYTE  */
    HEX = 300,                     /* HEX  */
    PURE = 301,                    /* PURE  */
    VIEW = 302,                    /* VIEW  */
    PAYABLE = 303,                 /* PAYABLE  */
    MAPPING = 304,                 /* MAPPING  */
    IMPLIES = 305,                 /* IMPLIES  */
    HEX_NUMBER = 306,              /* HEX_NUMBER  */
    STRING_LITERAL = 307,          /* STRING_LITERAL  */
    PLUS = 308,                    /* PLUS  */
    MULTIPLY = 309,                /* MULTIPLY  */
    EQUAL = 310,                   /* EQUAL  */
    EQUAL2 = 311,                  /* EQUAL2  */
    PLUS2 = 312,                   /* PLUS2  */
    MINUS2 = 313,                  /* MINUS2  */
    L_PAREN = 314,                 /* L_PAREN  */
    DOLLAR = 315,                  /* DOLLAR  */
    AMP = 316,                     /* AMP  */
    CARET = 317,                   /* CARET  */
    MOD = 318,                     /* MOD  */
    NUMBER_LITERAL = 319,          /* NUMBER_LITERAL  */
    IDENTIFIER = 320,              /* IDENTIFIER  */
    DECIMAL_NUMBER = 321,          /* DECIMAL_NUMBER  */
    REL_OP = 322,                  /* REL_OP  */
    LOG_OP = 323,                  /* LOG_OP  */
    QUES_MARK = 324,               /* QUES_MARK  */
    COLON = 325,                   /* COLON  */
    EMIT = 326,                    /* EMIT  */
    UINT = 327,                    /* UINT  */
    SOLIDITY = 328,                /* SOLIDITY  */
    VERSION = 329,                 /* VERSION  */
    EVENT = 330,                   /* EVENT  */
    INDEXED = 331,                 /* INDEXED  */
    FINNEY = 332,                  /* FINNEY  */
    ETHER = 333,                   /* ETHER  */
    SECONDS = 334,                 /* SECONDS  */
    MINUTES = 335,                 /* MINUTES  */
    HOURS = 336,                   /* HOURS  */
    DAYS = 337,                    /* DAYS  */
    WEEKS = 338,                   /* WEEKS  */
    YEARS = 339,                   /* YEARS  */
    UNDERSCORE = 340,              /* UNDERSCORE  */
    ANONYMOUS = 341,               /* ANONYMOUS  */
    USING = 342,                   /* USING  */
    NOT = 343,                     /* NOT  */
    FIXED = 344,                   /* FIXED  */
    UFIXED = 345,                  /* UFIXED  */
    R_PAREN = 346,                 /* R_PAREN  */
    COMMA = 347,                   /* COMMA  */
    STAR = 348,                    /* STAR  */
    TRUE = 349,                    /* TRUE  */
    FALSE = 350,                   /* FALSE  */
    TEXT = 351,                    /* TEXT  */
    CONSTRUCTOR = 352,             /* CONSTRUCTOR  */
    DELETE = 353,                  /* DELETE  */
    REQUIRE = 354,                 /* REQUIRE  */
    ASSERT = 355,                  /* ASSERT  */
    AUTO = 356,                    /* AUTO  */
    ELSE = 357,                    /* ELSE  */
    THROW = 358,                   /* THROW  */
    EXTERNAL = 359,                /* EXTERNAL  */
    RETURNS = 360,                 /* RETURNS  */
    COMMENT = 361,                 /* COMMENT  */
    STRING = 362,                  /* STRING  */
    INT = 363,                     /* INT  */
    NEW = 364,                     /* NEW  */
    FROM = 365,                    /* FROM  */
    MINUS = 366,                   /* MINUS  */
    DIVIDE = 367,                  /* DIVIDE  */
    WEI = 368,                     /* WEI  */
    SZABO = 369,                   /* SZABO  */
    TILDE = 370,                   /* TILDE  */
    SEMICOLON = 371                /* SEMICOLON  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 35 "../klee/tools/klee/grammar.y"

    char* s;
    int i;
    struct node* var;

#line 186 "../klee/tools/klee/grammar.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_KLEE_TOOLS_KLEE_GRAMMAR_H_INCLUDED  */
