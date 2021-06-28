/* A Bison parser, made by GNU Bison 3.7.5.  */

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
#define YYBISON 30705

/* Bison version string.  */
#define YYBISON_VERSION "3.7.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 3 "../klee/tools/klee/grammar.y"


#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include "../../include/klee/Core/defs.h"

void yyerror(const char *);
int yylex(void);
void writeContractContent();

std::string filename = "../../../output/convertedFile.cpp";
std::ofstream file(filename, std::ios::out);

node* headNode;
std::vector<node*> modifiers;
bool isReturnIden = false;
bool hasFallback = false;
bool isArray = false;
bool hasModifier = false;
bool hasBody = true;
std::vector<std::pair<node*, node*>> funcArgs;
std::vector<node*> retList;
node* baseClass;


#line 99 "../klee/tools/klee/grammar.c"

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

#include "grammar.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ENUM = 3,                       /* ENUM  */
  YYSYMBOL_STRUCT = 4,                     /* STRUCT  */
  YYSYMBOL_WHILE = 5,                      /* WHILE  */
  YYSYMBOL_DO = 6,                         /* DO  */
  YYSYMBOL_FOR = 7,                        /* FOR  */
  YYSYMBOL_IF = 8,                         /* IF  */
  YYSYMBOL_CONTINUE = 9,                   /* CONTINUE  */
  YYSYMBOL_BREAK = 10,                     /* BREAK  */
  YYSYMBOL_RETURN = 11,                    /* RETURN  */
  YYSYMBOL_SWITCH = 12,                    /* SWITCH  */
  YYSYMBOL_IMPORT = 13,                    /* IMPORT  */
  YYSYMBOL_CONTRACT = 14,                  /* CONTRACT  */
  YYSYMBOL_AS = 15,                        /* AS  */
  YYSYMBOL_PUBLIC = 16,                    /* PUBLIC  */
  YYSYMBOL_PRIVATE = 17,                   /* PRIVATE  */
  YYSYMBOL_FUNCTION = 18,                  /* FUNCTION  */
  YYSYMBOL_INTERNAL = 19,                  /* INTERNAL  */
  YYSYMBOL_CONSTANT = 20,                  /* CONSTANT  */
  YYSYMBOL_DEFAULT = 21,                   /* DEFAULT  */
  YYSYMBOL_CASE = 22,                      /* CASE  */
  YYSYMBOL_BEG_TAB = 23,                   /* BEG_TAB  */
  YYSYMBOL_END_TAB = 24,                   /* END_TAB  */
  YYSYMBOL_L_CURLY_B = 25,                 /* L_CURLY_B  */
  YYSYMBOL_R_CURLY_B = 26,                 /* R_CURLY_B  */
  YYSYMBOL_PRAGMA = 27,                    /* PRAGMA  */
  YYSYMBOL_LIBRARY = 28,                   /* LIBRARY  */
  YYSYMBOL_INTERFACE = 29,                 /* INTERFACE  */
  YYSYMBOL_MODIFIER = 30,                  /* MODIFIER  */
  YYSYMBOL_IS = 31,                        /* IS  */
  YYSYMBOL_MEMORY = 32,                    /* MEMORY  */
  YYSYMBOL_STORAGE = 33,                   /* STORAGE  */
  YYSYMBOL_CALLDATA = 34,                  /* CALLDATA  */
  YYSYMBOL_SEND = 35,                      /* SEND  */
  YYSYMBOL_CALL = 36,                      /* CALL  */
  YYSYMBOL_TRANSFER = 37,                  /* TRANSFER  */
  YYSYMBOL_ADDRESS = 38,                   /* ADDRESS  */
  YYSYMBOL_DOT = 39,                       /* DOT  */
  YYSYMBOL_BOOL = 40,                      /* BOOL  */
  YYSYMBOL_OPT_L = 41,                     /* OPT_L  */
  YYSYMBOL_OPT_R = 42,                     /* OPT_R  */
  YYSYMBOL_SPACE = 43,                     /* SPACE  */
  YYSYMBOL_BYTE = 44,                      /* BYTE  */
  YYSYMBOL_HEX = 45,                       /* HEX  */
  YYSYMBOL_PURE = 46,                      /* PURE  */
  YYSYMBOL_VIEW = 47,                      /* VIEW  */
  YYSYMBOL_PAYABLE = 48,                   /* PAYABLE  */
  YYSYMBOL_MAPPING = 49,                   /* MAPPING  */
  YYSYMBOL_IMPLIES = 50,                   /* IMPLIES  */
  YYSYMBOL_HEX_NUMBER = 51,                /* HEX_NUMBER  */
  YYSYMBOL_STRING_LITERAL = 52,            /* STRING_LITERAL  */
  YYSYMBOL_PLUS = 53,                      /* PLUS  */
  YYSYMBOL_MULTIPLY = 54,                  /* MULTIPLY  */
  YYSYMBOL_EQUAL = 55,                     /* EQUAL  */
  YYSYMBOL_EQUAL2 = 56,                    /* EQUAL2  */
  YYSYMBOL_PLUS2 = 57,                     /* PLUS2  */
  YYSYMBOL_MINUS2 = 58,                    /* MINUS2  */
  YYSYMBOL_L_PAREN = 59,                   /* L_PAREN  */
  YYSYMBOL_DOLLAR = 60,                    /* DOLLAR  */
  YYSYMBOL_AMP = 61,                       /* AMP  */
  YYSYMBOL_CARET = 62,                     /* CARET  */
  YYSYMBOL_MOD = 63,                       /* MOD  */
  YYSYMBOL_NUMBER_LITERAL = 64,            /* NUMBER_LITERAL  */
  YYSYMBOL_IDENTIFIER = 65,                /* IDENTIFIER  */
  YYSYMBOL_DECIMAL_NUMBER = 66,            /* DECIMAL_NUMBER  */
  YYSYMBOL_REL_OP = 67,                    /* REL_OP  */
  YYSYMBOL_LOG_OP = 68,                    /* LOG_OP  */
  YYSYMBOL_QUES_MARK = 69,                 /* QUES_MARK  */
  YYSYMBOL_COLON = 70,                     /* COLON  */
  YYSYMBOL_EMIT = 71,                      /* EMIT  */
  YYSYMBOL_UINT = 72,                      /* UINT  */
  YYSYMBOL_SOLIDITY = 73,                  /* SOLIDITY  */
  YYSYMBOL_VERSION = 74,                   /* VERSION  */
  YYSYMBOL_EVENT = 75,                     /* EVENT  */
  YYSYMBOL_INDEXED = 76,                   /* INDEXED  */
  YYSYMBOL_FINNEY = 77,                    /* FINNEY  */
  YYSYMBOL_ETHER = 78,                     /* ETHER  */
  YYSYMBOL_SECONDS = 79,                   /* SECONDS  */
  YYSYMBOL_MINUTES = 80,                   /* MINUTES  */
  YYSYMBOL_HOURS = 81,                     /* HOURS  */
  YYSYMBOL_DAYS = 82,                      /* DAYS  */
  YYSYMBOL_WEEKS = 83,                     /* WEEKS  */
  YYSYMBOL_YEARS = 84,                     /* YEARS  */
  YYSYMBOL_UNDERSCORE = 85,                /* UNDERSCORE  */
  YYSYMBOL_ANONYMOUS = 86,                 /* ANONYMOUS  */
  YYSYMBOL_USING = 87,                     /* USING  */
  YYSYMBOL_NOT = 88,                       /* NOT  */
  YYSYMBOL_FIXED = 89,                     /* FIXED  */
  YYSYMBOL_UFIXED = 90,                    /* UFIXED  */
  YYSYMBOL_R_PAREN = 91,                   /* R_PAREN  */
  YYSYMBOL_COMMA = 92,                     /* COMMA  */
  YYSYMBOL_STAR = 93,                      /* STAR  */
  YYSYMBOL_TRUE = 94,                      /* TRUE  */
  YYSYMBOL_FALSE = 95,                     /* FALSE  */
  YYSYMBOL_TEXT = 96,                      /* TEXT  */
  YYSYMBOL_CONSTRUCTOR = 97,               /* CONSTRUCTOR  */
  YYSYMBOL_DELETE = 98,                    /* DELETE  */
  YYSYMBOL_REQUIRE = 99,                   /* REQUIRE  */
  YYSYMBOL_ASSERT = 100,                   /* ASSERT  */
  YYSYMBOL_AUTO = 101,                     /* AUTO  */
  YYSYMBOL_ELSE = 102,                     /* ELSE  */
  YYSYMBOL_THROW = 103,                    /* THROW  */
  YYSYMBOL_EXTERNAL = 104,                 /* EXTERNAL  */
  YYSYMBOL_RETURNS = 105,                  /* RETURNS  */
  YYSYMBOL_COMMENT = 106,                  /* COMMENT  */
  YYSYMBOL_STRING = 107,                   /* STRING  */
  YYSYMBOL_INT = 108,                      /* INT  */
  YYSYMBOL_NEW = 109,                      /* NEW  */
  YYSYMBOL_FROM = 110,                     /* FROM  */
  YYSYMBOL_MINUS = 111,                    /* MINUS  */
  YYSYMBOL_DIVIDE = 112,                   /* DIVIDE  */
  YYSYMBOL_WEI = 113,                      /* WEI  */
  YYSYMBOL_SZABO = 114,                    /* SZABO  */
  YYSYMBOL_TILDE = 115,                    /* TILDE  */
  YYSYMBOL_SEMICOLON = 116,                /* SEMICOLON  */
  YYSYMBOL_YYACCEPT = 117,                 /* $accept  */
  YYSYMBOL_SourceUnit = 118,               /* SourceUnit  */
  YYSYMBOL_119_1 = 119,                    /* $@1  */
  YYSYMBOL_PragmaDirective = 120,          /* PragmaDirective  */
  YYSYMBOL_ContractDefinition = 121,       /* ContractDefinition  */
  YYSYMBOL_122_2 = 122,                    /* $@2  */
  YYSYMBOL_123_3 = 123,                    /* $@3  */
  YYSYMBOL_BaseClass = 124,                /* BaseClass  */
  YYSYMBOL_ContractPart = 125,             /* ContractPart  */
  YYSYMBOL_UsingForDeclaration = 126,      /* UsingForDeclaration  */
  YYSYMBOL_StructDefinition = 127,         /* StructDefinition  */
  YYSYMBOL_Vars = 128,                     /* Vars  */
  YYSYMBOL_StorageLocation = 129,          /* StorageLocation  */
  YYSYMBOL_ModifierDefinition = 130,       /* ModifierDefinition  */
  YYSYMBOL_ModifierInvocation = 131,       /* ModifierInvocation  */
  YYSYMBOL_EventDefinition = 132,          /* EventDefinition  */
  YYSYMBOL_EventParameterList = 133,       /* EventParameterList  */
  YYSYMBOL_EventParameter = 134,           /* EventParameter  */
  YYSYMBOL_EnumValue = 135,                /* EnumValue  */
  YYSYMBOL_EnumDefinition = 136,           /* EnumDefinition  */
  YYSYMBOL_EnumValues = 137,               /* EnumValues  */
  YYSYMBOL_StateVariableDeclaration = 138, /* StateVariableDeclaration  */
  YYSYMBOL_StateMutability = 139,          /* StateMutability  */
  YYSYMBOL_Qualifier = 140,                /* Qualifier  */
  YYSYMBOL_VariableAttribute = 141,        /* VariableAttribute  */
  YYSYMBOL_FunctionAttribute = 142,        /* FunctionAttribute  */
  YYSYMBOL_FunctionDefinition = 143,       /* FunctionDefinition  */
  YYSYMBOL_ParameterList = 144,            /* ParameterList  */
  YYSYMBOL_Parameter = 145,                /* Parameter  */
  YYSYMBOL_146_4 = 146,                    /* $@4  */
  YYSYMBOL_ReturnList = 147,               /* ReturnList  */
  YYSYMBOL_Parameter2 = 148,               /* Parameter2  */
  YYSYMBOL_VariableDeclaration = 149,      /* VariableDeclaration  */
  YYSYMBOL_TypeName = 150,                 /* TypeName  */
  YYSYMBOL_UserDefinedTypeName = 151,      /* UserDefinedTypeName  */
  YYSYMBOL_Mapping = 152,                  /* Mapping  */
  YYSYMBOL_ArrayTypeName = 153,            /* ArrayTypeName  */
  YYSYMBOL_FunctionTypeName = 154,         /* FunctionTypeName  */
  YYSYMBOL_Block = 155,                    /* Block  */
  YYSYMBOL_Statement = 156,                /* Statement  */
  YYSYMBOL_AssertStatement = 157,          /* AssertStatement  */
  YYSYMBOL_ExpressionStatement = 158,      /* ExpressionStatement  */
  YYSYMBOL_IfStatement = 159,              /* IfStatement  */
  YYSYMBOL_WhileStatement = 160,           /* WhileStatement  */
  YYSYMBOL_SimpleStatement = 161,          /* SimpleStatement  */
  YYSYMBOL_ForStatement = 162,             /* ForStatement  */
  YYSYMBOL_DoWhileStatement = 163,         /* DoWhileStatement  */
  YYSYMBOL_EmitStatement = 164,            /* EmitStatement  */
  YYSYMBOL_VariableDefinition = 165,       /* VariableDefinition  */
  YYSYMBOL_VarDec2 = 166,                  /* VarDec2  */
  YYSYMBOL_Expression = 167,               /* Expression  */
  YYSYMBOL_Operator = 168,                 /* Operator  */
  YYSYMBOL_Unary1 = 169,                   /* Unary1  */
  YYSYMBOL_Unary2 = 170,                   /* Unary2  */
  YYSYMBOL_PrimaryExpression = 171,        /* PrimaryExpression  */
  YYSYMBOL_ExpressionList = 172,           /* ExpressionList  */
  YYSYMBOL_NameValue = 173,                /* NameValue  */
  YYSYMBOL_NameValueList = 174,            /* NameValueList  */
  YYSYMBOL_FunctionCallArguments = 175,    /* FunctionCallArguments  */
  YYSYMBOL_FunctionCall = 176,             /* FunctionCall  */
  YYSYMBOL_NewExpression = 177,            /* NewExpression  */
  YYSYMBOL_MemberAccess = 178,             /* MemberAccess  */
  YYSYMBOL_IndexAccess = 179,              /* IndexAccess  */
  YYSYMBOL_IndexAccess2 = 180,             /* IndexAccess2  */
  YYSYMBOL_BooleanLiteral = 181,           /* BooleanLiteral  */
  YYSYMBOL_NumberLiteral = 182,            /* NumberLiteral  */
  YYSYMBOL_NumberUnit = 183,               /* NumberUnit  */
  YYSYMBOL_ElementaryTypeName = 184        /* ElementaryTypeName  */
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
typedef yytype_int16 yy_state_t;

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

#if 1

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
#endif /* 1 */

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
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1922

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  117
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  68
/* YYNRULES -- Number of rules.  */
#define YYNRULES  210
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  389

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   371


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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    73,    73,    72,    77,    80,    83,    86,    85,   101,
     100,   116,   117,   121,   124,   127,   130,   133,   136,   139,
     142,   145,   148,   152,   156,   159,   162,   163,   164,   167,
     170,   174,   176,   179,   184,   187,   191,   193,   196,   199,
     201,   203,   205,   208,   210,   213,   217,   220,   223,   226,
     230,   231,   232,   235,   236,   237,   238,   239,   242,   245,
     248,   251,   254,   257,   260,   263,   298,   312,   316,   321,
     324,   324,   325,   326,   327,   328,   331,   334,   335,   336,
     337,   340,   341,   342,   343,   346,   347,   348,   349,   350,
     351,   354,   359,   368,   369,   372,   375,   376,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   396,   400,   401,   402,   403,   406,
     408,   409,   412,   415,   416,   419,   423,   426,   428,   429,
     430,   433,   434,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   453,   454,   455,   456,
     457,   458,   459,   460,   463,   464,   467,   468,   469,   470,
     471,   472,   473,   476,   477,   478,   479,   480,   483,   484,
     488,   489,   493,   497,   498,   499,   502,   503,   506,   509,
     510,   511,   512,   515,   516,   518,   519,   520,   523,   524,
     527,   528,   529,   530,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   546,   547,   548,   549,   550,   551,
     552
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ENUM", "STRUCT",
  "WHILE", "DO", "FOR", "IF", "CONTINUE", "BREAK", "RETURN", "SWITCH",
  "IMPORT", "CONTRACT", "AS", "PUBLIC", "PRIVATE", "FUNCTION", "INTERNAL",
  "CONSTANT", "DEFAULT", "CASE", "BEG_TAB", "END_TAB", "L_CURLY_B",
  "R_CURLY_B", "PRAGMA", "LIBRARY", "INTERFACE", "MODIFIER", "IS",
  "MEMORY", "STORAGE", "CALLDATA", "SEND", "CALL", "TRANSFER", "ADDRESS",
  "DOT", "BOOL", "OPT_L", "OPT_R", "SPACE", "BYTE", "HEX", "PURE", "VIEW",
  "PAYABLE", "MAPPING", "IMPLIES", "HEX_NUMBER", "STRING_LITERAL", "PLUS",
  "MULTIPLY", "EQUAL", "EQUAL2", "PLUS2", "MINUS2", "L_PAREN", "DOLLAR",
  "AMP", "CARET", "MOD", "NUMBER_LITERAL", "IDENTIFIER", "DECIMAL_NUMBER",
  "REL_OP", "LOG_OP", "QUES_MARK", "COLON", "EMIT", "UINT", "SOLIDITY",
  "VERSION", "EVENT", "INDEXED", "FINNEY", "ETHER", "SECONDS", "MINUTES",
  "HOURS", "DAYS", "WEEKS", "YEARS", "UNDERSCORE", "ANONYMOUS", "USING",
  "NOT", "FIXED", "UFIXED", "R_PAREN", "COMMA", "STAR", "TRUE", "FALSE",
  "TEXT", "CONSTRUCTOR", "DELETE", "REQUIRE", "ASSERT", "AUTO", "ELSE",
  "THROW", "EXTERNAL", "RETURNS", "COMMENT", "STRING", "INT", "NEW",
  "FROM", "MINUS", "DIVIDE", "WEI", "SZABO", "TILDE", "SEMICOLON",
  "$accept", "SourceUnit", "$@1", "PragmaDirective", "ContractDefinition",
  "$@2", "$@3", "BaseClass", "ContractPart", "UsingForDeclaration",
  "StructDefinition", "Vars", "StorageLocation", "ModifierDefinition",
  "ModifierInvocation", "EventDefinition", "EventParameterList",
  "EventParameter", "EnumValue", "EnumDefinition", "EnumValues",
  "StateVariableDeclaration", "StateMutability", "Qualifier",
  "VariableAttribute", "FunctionAttribute", "FunctionDefinition",
  "ParameterList", "Parameter", "$@4", "ReturnList", "Parameter2",
  "VariableDeclaration", "TypeName", "UserDefinedTypeName", "Mapping",
  "ArrayTypeName", "FunctionTypeName", "Block", "Statement",
  "AssertStatement", "ExpressionStatement", "IfStatement",
  "WhileStatement", "SimpleStatement", "ForStatement", "DoWhileStatement",
  "EmitStatement", "VariableDefinition", "VarDec2", "Expression",
  "Operator", "Unary1", "Unary2", "PrimaryExpression", "ExpressionList",
  "NameValue", "NameValueList", "FunctionCallArguments", "FunctionCall",
  "NewExpression", "MemberAccess", "IndexAccess", "IndexAccess2",
  "BooleanLiteral", "NumberLiteral", "NumberUnit", "ElementaryTypeName", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371
};
#endif

#define YYPACT_NINF (-297)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-128)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      53,    21,   -20,    46,    53,    98,    51,    -6,  -297,  -297,
      53,  -297,    41,  -297,  -297,    69,    37,    83,    67,    71,
      57,    72,    63,  -297,  -297,    80,  -297,  -297,    77,    84,
      86,  -297,  -297,  -297,   124,    69,    69,    69,    69,    69,
      69,    69,   286,  -297,  -297,  -297,  -297,  -297,    41,  -297,
     126,   127,   125,    86,    49,   -19,  -297,    19,    96,   150,
      16,   175,  -297,  -297,  -297,  -297,  -297,  -297,  -297,  -297,
    -297,  -297,  -297,  -297,  1063,  -297,  -297,  -297,  -297,   267,
     267,    95,  -297,    69,   -17,    16,    86,   175,    70,   197,
     175,    86,   137,  -297,   -22,  -297,  -297,   114,   217,   -69,
     135,   108,   175,   175,   175,   -22,  1351,  -297,   430,  -297,
    -297,  -297,  -297,  1351,    62,   430,  -297,  -297,  -297,  -297,
      16,  -297,  -297,  1521,  1351,  -297,  -297,  -297,  -297,  -297,
    -297,  -297,  -297,  -297,  -297,   -45,   142,  -297,  -297,    88,
     145,    56,   213,   -22,  -297,  -297,  -297,  -297,    89,   113,
     -21,  -297,   137,   369,  -297,    16,  -297,    91,    28,    73,
    -297,    82,   -27,  1135,  -297,  -297,  -297,  -297,  1542,   141,
    -297,  -297,  -297,  -297,  -297,  -297,  -297,  -297,  -297,  -297,
    -297,  1583,   121,  1207,  -297,   146,   128,  -297,  -297,  -297,
    -297,  -297,  -297,   912,  -297,  -297,  1351,  1351,  1351,  -297,
    -297,  -297,  1351,  -297,  1231,  1351,  -297,  -297,   134,   180,
    -297,    16,   154,   147,  -297,  -297,  -297,   155,  -297,   480,
     158,   137,   166,   178,   123,   133,   984,  -297,   768,   169,
    1351,   140,   182,   185,   143,  -297,   144,  -297,  -297,   149,
    -297,   151,   156,  -297,  1231,   321,   -29,  -297,   159,   188,
    -297,  -297,  -297,  -297,   183,  1351,  -297,  -297,   232,  -297,
    -297,  1622,   232,  -297,   -10,  -297,  -297,   184,  1231,  1231,
    1643,  1231,   720,    88,  -297,  -297,  1351,   225,    16,    16,
     -22,  -297,  1351,   624,   840,  1351,  -297,  -297,  1351,  -297,
     864,    16,   189,   200,  1231,   172,  -297,  1351,  1351,  -297,
    -297,  -297,  -297,  -297,  -297,    16,   201,  -297,  -297,   251,
    -297,   226,   269,  -297,  1351,  -297,  -297,  1231,  1351,  -297,
     208,   -26,  -297,  1682,   241,   193,  1709,  1412,   210,  -297,
    -297,   220,  -297,  1439,  1480,  -297,    16,  1279,  -297,  1351,
    -297,  1231,  1231,  -297,   224,    16,   137,  1351,  1351,   137,
     196,   262,  -297,   270,  -297,   271,  -297,  -297,  1748,  1769,
      16,  -297,   696,  1810,  1087,   552,  -297,  1351,   240,   244,
    -297,   273,  -297,  -297,   -14,  1351,   137,  1231,  -297,  -297,
     274,   248,  1231,   696,  1351,   137,  1769,   696,  -297
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     2,     0,     0,     1,     5,
       0,     7,     0,     6,     3,    20,    11,     0,     0,     0,
       0,     0,   204,   205,   209,     0,    91,   208,     0,     0,
       0,   210,   206,   207,     0,    20,    20,    20,    20,    20,
      20,    20,    60,    87,    86,    88,    89,    85,     0,     9,
       0,     0,     0,     0,     0,     0,    90,     0,     0,     0,
      75,    64,     8,    15,    16,    17,    18,    19,    13,    14,
      53,    54,    56,    55,     0,    50,    51,    52,    57,    60,
      60,     0,    12,    20,     0,     0,     0,    64,     0,    74,
      64,     0,   114,    97,     0,    30,   204,     0,     0,     0,
       0,    31,    64,    64,    64,     0,     0,    93,   190,   165,
     157,   156,   161,     0,   166,   191,   162,   188,   189,   160,
       0,   158,   159,     0,     0,   145,   136,   134,   137,   135,
     163,   164,   167,    59,    58,     0,     0,    44,    43,    47,
       0,     0,     0,     0,    69,    26,    27,    28,    73,     0,
       0,    95,   114,     0,    29,     0,    37,     0,    42,     0,
      35,     0,     0,     0,    63,    62,    61,    67,   168,     0,
     196,   197,   198,   199,   200,   201,   202,   203,   194,   195,
     192,     0,     0,     0,   193,   178,     0,    94,   147,   146,
     152,   154,   155,     0,   153,   151,     0,     0,     0,   150,
     148,   149,     0,   133,   140,     0,    48,    10,     0,     0,
      23,    25,    83,     0,    68,    70,    72,     0,    66,     0,
       0,   114,     0,     0,     0,     0,     0,    96,   132,   166,
       0,   111,     0,     0,     0,   128,     0,    98,    99,     0,
     100,     0,     0,   124,   123,   167,     0,    36,    41,     0,
      34,    21,    22,    33,     0,     0,   138,   139,   180,   181,
     184,     0,   179,   182,     0,   177,   175,     0,   144,   141,
       0,   143,     0,    47,    45,    24,     0,    82,    75,     0,
       0,   101,     0,     0,     0,     0,   104,   105,     0,   108,
       0,     0,   132,     0,     0,   136,   112,     0,     0,   109,
     113,   102,   103,   110,    92,     0,    39,    32,   169,   187,
     174,     0,     0,   176,     0,    49,    46,    84,     0,    71,
       0,    77,    65,     0,     0,     0,     0,     0,     0,   107,
     131,     0,   130,     0,     0,    40,     0,     0,   183,     0,
     173,   142,    81,    76,    78,     0,   114,     0,     0,   114,
       0,     0,   115,     0,   116,     0,    38,   186,     0,   171,
       0,    79,   122,     0,     0,   120,   106,     0,     0,     0,
     185,     0,   172,    80,   114,     0,   114,   129,   117,   118,
       0,     0,   119,   121,     0,   114,   171,   125,   170
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -297,   115,  -297,  -297,  -297,  -297,  -297,   298,   363,  -297,
    -297,   138,   206,  -297,  -297,  -297,  -297,  -286,   148,  -297,
      78,  -297,    35,    79,   -44,   239,  -297,   -12,    85,  -297,
    -297,  -296,   -80,    -8,  -297,  -297,  -297,  -297,   -92,   -91,
    -297,  -297,  -297,  -297,    74,  -297,  -297,  -297,  -297,    65,
      22,  -297,  -297,  -297,  -297,  -155,   -13,  -297,  -297,   130,
    -297,  -297,  -108,  -297,  -297,  -297,   249,   -15
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     3,    10,     4,     5,    15,    83,    17,    34,    35,
      36,   140,   149,    37,   102,    38,    99,   157,   139,    39,
     209,    40,   103,   104,    81,   105,    41,    54,    88,   278,
     280,   320,   235,   142,    43,    44,    45,    46,    95,   362,
     236,   381,   237,   238,   239,   240,   241,   242,   243,   293,
     244,   202,   203,   124,   125,   169,   372,   312,   267,   126,
     127,   128,   129,   338,   130,   131,   180,   132
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      47,   153,   154,    92,    92,   141,    92,    42,   254,   137,
     205,   152,    74,   167,    74,    74,   310,   159,    61,   335,
      47,    47,    47,    47,    47,    47,    47,    42,    42,    42,
      42,    42,    42,    42,    86,   133,   134,    47,   266,   344,
      60,    90,    97,    94,    89,    47,     8,   160,   138,   361,
     356,   214,    89,     7,    22,   311,    23,    96,   218,    23,
      24,   219,   304,    24,   373,    25,   345,     1,    47,    74,
      47,   206,    18,    19,   259,    42,    11,    79,   263,   151,
       2,    26,    12,    47,   217,    47,     6,    20,    27,   252,
     158,    27,   162,   248,    93,    93,   123,    93,    -4,    21,
     308,   182,  -126,   183,   249,    47,    16,    22,    49,    23,
      13,    56,   185,    24,    79,    79,    52,    31,    25,     9,
      31,    80,    53,    32,    33,    14,    32,    33,   168,    48,
     283,   141,    50,   328,    26,   181,    51,    55,   245,    57,
      47,    27,    58,    86,    28,    60,   204,   246,   292,    59,
      62,    84,    85,    86,    91,    98,    29,   100,    80,    80,
     135,   144,   152,    22,   155,    23,    30,   163,   207,    24,
      31,   210,   211,    22,    25,    23,    32,    33,   216,    24,
     208,   215,   247,   256,    25,   168,   258,    74,   322,   250,
      26,    70,    71,   262,    72,    73,    47,    27,   251,   138,
      26,   -91,   -91,   -91,   245,   261,   274,    27,   182,   276,
     183,   330,   277,   245,   279,   168,    87,   282,   268,   269,
     270,    75,    76,    77,   271,   284,    31,   272,   161,   145,
     146,   147,    32,    33,   -91,    86,    31,   285,    74,   286,
     101,   297,    32,    33,   298,   145,   146,   147,   290,   287,
     181,   305,   294,   306,    74,    22,   296,    23,   365,   299,
     300,    24,   148,    47,    47,   301,    25,   302,   245,   245,
      89,   321,   303,   183,   307,   313,    47,   168,   212,    78,
     318,   291,    26,    70,    71,   383,    72,    73,  -127,    27,
      47,   332,   337,   336,   387,   340,   339,   158,   317,   343,
     347,   350,    70,    71,   323,    72,    73,   326,   156,   348,
     327,   351,   366,    75,    76,    77,   360,   367,    31,   333,
     334,    47,   368,   369,    32,    33,   143,    74,   158,   150,
      47,   378,    75,    76,    77,   379,   341,   321,   380,   385,
     342,   164,   165,   166,   384,    47,    82,   245,   213,   275,
     245,   316,   321,   -85,   -85,   -85,   273,   331,   325,   358,
     295,   359,   -85,   319,   184,     0,     0,     0,   245,   363,
     364,    78,   245,   388,   220,   221,   222,   223,   224,   225,
     226,     0,     0,     0,     0,     0,   -85,    86,     0,   377,
      78,     0,     0,     0,     0,   227,     0,   382,    63,    64,
      65,    66,    67,    68,    69,     0,   386,    22,     0,    23,
     106,     0,     0,    24,     0,     0,     0,     0,    25,     0,
     108,   109,   110,     0,     0,     0,   111,   112,   228,     0,
       0,     0,     0,     0,   229,   115,     0,     0,     0,     0,
     230,    27,     0,     0,     0,     0,   136,     0,     0,     0,
       0,     0,     0,     0,   231,     0,     0,   116,     0,     0,
       0,     0,     0,   117,   118,     0,     0,   119,   232,   233,
      31,     0,   234,     0,     0,     0,    32,    33,   120,     0,
     121,     0,     0,     0,   122,   220,   221,   222,   223,   224,
     225,   226,     0,     0,     0,     0,     0,     0,    86,     0,
       0,     0,     0,     0,     0,     0,   281,   170,   171,   172,
     173,   174,   175,   176,   177,     0,     0,     0,    22,     0,
      23,   106,     0,     0,    24,     0,     0,     0,     0,    25,
       0,   108,   109,   110,     0,     0,     0,   111,   112,   228,
       0,     0,     0,   178,   179,   229,   115,     0,     0,     0,
       0,   230,    27,     0,     0,     0,     0,   220,   221,   222,
     223,   224,   225,   226,     0,   231,     0,     0,   116,     0,
      86,     0,     0,     0,   117,   118,     0,     0,   119,   232,
     233,    31,     0,   234,     0,     0,     0,    32,    33,   120,
      22,   121,    23,   106,     0,   122,    24,     0,     0,     0,
       0,    25,     0,   108,   109,   110,     0,     0,     0,   111,
     112,   228,     0,     0,     0,     0,     0,   229,   115,     0,
       0,     0,     0,   230,    27,     0,     0,     0,     0,   324,
     221,   222,   223,   224,   225,   226,     0,   231,     0,     0,
     116,     0,    86,     0,     0,     0,   117,   118,     0,     0,
     119,   232,   233,    31,   376,   234,     0,     0,     0,    32,
      33,   120,    22,   121,    23,   106,     0,   122,    24,     0,
       0,     0,     0,    25,     0,   108,   109,   110,     0,     0,
       0,   111,   112,   228,     0,     0,     0,     0,     0,   229,
     115,     0,     0,     0,     0,   230,    27,     0,     0,     0,
       0,   220,   221,   222,   223,   224,   225,   226,     0,   231,
       0,     0,   116,     0,    86,     0,     0,     0,   117,   118,
       0,     0,   119,   232,   233,    31,     0,   234,     0,     0,
       0,    32,    33,   120,    22,   121,    23,   106,     0,   122,
      24,     0,     0,     0,     0,    25,     0,   108,   109,   110,
       0,     0,     0,   111,   112,   228,     0,     0,     0,   186,
       0,   229,   115,     0,     0,     0,     0,   230,    27,     0,
       0,     0,     0,   188,     0,   189,   190,   191,   192,   193,
       0,   231,   194,   195,   116,     0,    86,   196,   197,   198,
     117,   118,     0,     0,   119,   232,   233,    31,     0,   234,
       0,     0,     0,    32,    33,   120,    22,   121,    23,   106,
       0,   122,    24,   199,     0,     0,     0,    25,     0,   108,
     109,   110,     0,     0,     0,   111,   112,   113,     0,     0,
       0,   200,   201,   229,   115,     0,   315,     0,     0,     0,
      27,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   116,     0,    86,     0,
     291,     0,   117,   118,     0,     0,   119,     0,     0,    31,
       0,     0,     0,     0,     0,    32,    33,   120,    22,   121,
      23,   106,     0,   122,    24,     0,     0,     0,     0,    25,
       0,   108,   109,   110,     0,     0,     0,   111,   112,   228,
       0,     0,     0,   186,     0,   229,   115,     0,     0,     0,
       0,     0,    27,     0,     0,     0,     0,   188,     0,   189,
     190,   191,   192,   193,     0,     0,   194,   195,   116,     0,
       0,   196,   197,   198,   117,   118,     0,   264,   119,     0,
       0,    31,     0,     0,     0,     0,     0,    32,    33,   120,
      96,   121,    23,   106,     0,   122,    24,   199,     0,     0,
       0,     0,     0,   108,   109,   110,     0,     0,     0,   111,
     112,   113,     0,     0,     0,   200,   201,   114,   115,     0,
     329,     0,     0,     0,    27,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     116,     0,     0,   265,     0,     0,   117,   118,     0,     0,
     119,     0,     0,    31,     0,     0,     0,     0,     0,    32,
      33,   120,    96,   121,    23,   106,     0,   122,    24,     0,
       0,     0,     0,     0,     0,   108,   109,   110,     0,     0,
       0,   111,   112,   288,     0,     0,     0,     0,     0,   114,
     115,     0,     0,     0,     0,     0,    27,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   116,     0,     0,     0,     0,     0,   117,   118,
       0,     0,   119,     0,     0,    31,     0,     0,     0,     0,
       0,    32,    33,   120,     0,   121,     0,     0,     0,   122,
     289,    96,     0,    23,   106,   107,     0,    24,     0,     0,
       0,     0,     0,     0,   108,   109,   110,     0,     0,     0,
     111,   112,   113,     0,     0,     0,   186,     0,   114,   115,
       0,     0,     0,     0,     0,    27,     0,     0,     0,     0,
     188,     0,   189,   190,   191,   192,   193,     0,     0,   194,
     195,   116,     0,     0,   196,   197,   198,   117,   118,     0,
       0,   119,     0,     0,    31,     0,     0,     0,     0,     0,
      32,    33,   120,    96,   121,    23,   106,     0,   122,    24,
     199,     0,     0,     0,     0,     0,   108,   109,   110,     0,
       0,     0,   111,   112,   113,     0,     0,     0,   200,   201,
     114,   115,     0,   375,     0,     0,     0,    27,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   116,     0,     0,   253,     0,     0,   117,
     118,     0,     0,   119,     0,     0,    31,     0,     0,     0,
       0,     0,    32,    33,   120,    96,   121,    23,   106,   260,
     122,    24,     0,     0,     0,     0,     0,     0,   108,   109,
     110,     0,     0,     0,   111,   112,   113,     0,     0,     0,
     186,     0,   114,   115,     0,     0,     0,     0,     0,    27,
       0,     0,     0,     0,   188,     0,   189,   190,   191,   192,
     193,     0,     0,   194,   195,   116,     0,     0,   196,   197,
     198,   117,   118,     0,     0,   119,     0,     0,    31,     0,
       0,     0,     0,     0,    32,    33,   120,    96,   121,    23,
     106,   357,   122,    24,   199,     0,     0,     0,     0,     0,
     108,   109,   110,     0,     0,     0,   111,   112,   113,     0,
       0,     0,   200,   201,   114,   115,     0,     0,     0,     0,
       0,    27,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   116,     0,     0,
       0,     0,     0,   117,   118,     0,     0,   119,     0,     0,
      31,     0,     0,     0,     0,     0,    32,    33,   120,    96,
     121,    23,   106,     0,   122,    24,     0,     0,     0,     0,
       0,     0,   108,   109,   110,     0,     0,     0,   111,   112,
     113,     0,     0,     0,     0,     0,   114,   115,     0,     0,
       0,     0,     0,    27,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   116,
       0,     0,     0,     0,     0,   117,   118,     0,     0,   119,
       0,   186,    31,     0,     0,     0,     0,     0,    32,    33,
     120,     0,   121,     0,     0,   188,   122,   189,   190,   191,
     192,   193,     0,     0,   194,   195,     0,     0,   186,   196,
     197,   198,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   188,     0,   189,   190,   191,   192,   193,     0,
       0,   194,   195,   257,   255,   199,   196,   197,   198,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   186,
       0,     0,     0,   200,   201,     0,     0,     0,     0,     0,
     352,   353,   199,   188,     0,   189,   190,   191,   192,   193,
       0,     0,   194,   195,     0,     0,     0,   196,   197,   198,
     200,   201,     0,     0,     0,     0,     0,     0,     0,     0,
     186,     0,     0,   187,     0,     0,     0,     0,     0,     0,
       0,   354,   355,   199,   188,     0,   189,   190,   191,   192,
     193,   186,     0,   194,   195,     0,     0,     0,   196,   197,
     198,   200,   201,     0,     0,   188,     0,   189,   190,   191,
     192,   193,     0,     0,   194,   195,     0,     0,     0,   196,
     197,   198,     0,     0,   199,     0,     0,     0,     0,     0,
       0,     0,   186,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   200,   201,   255,   199,   188,     0,   189,   190,
     191,   192,   193,     0,     0,   194,   195,     0,     0,     0,
     196,   197,   198,   200,   201,     0,     0,     0,     0,     0,
       0,   186,     0,     0,   309,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   257,   188,   199,   189,   190,   191,
     192,   193,   186,     0,   194,   195,     0,     0,     0,   196,
     197,   198,     0,     0,   200,   201,   188,     0,   189,   190,
     191,   192,   193,     0,     0,   194,   195,     0,     0,     0,
     196,   197,   198,   314,     0,   199,     0,     0,     0,     0,
       0,   186,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   200,   201,   188,   199,   189,   190,   191,
     192,   193,     0,     0,   194,   195,     0,     0,   186,   196,
     197,   198,     0,     0,   200,   201,     0,     0,     0,     0,
       0,     0,   188,     0,   189,   190,   191,   192,   193,     0,
       0,   194,   195,   346,     0,   199,   196,   197,   198,     0,
       0,     0,     0,     0,     0,     0,     0,   186,     0,     0,
     370,     0,     0,   200,   201,     0,     0,     0,     0,     0,
     349,   188,   199,   189,   190,   191,   192,   193,   186,     0,
     194,   195,     0,     0,     0,   196,   197,   198,     0,     0,
     200,   201,   188,     0,   189,   190,   191,   192,   193,     0,
       0,   194,   195,     0,     0,     0,   196,   197,   198,     0,
       0,   199,     0,     0,     0,     0,     0,     0,     0,   186,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   200,
     201,   371,   199,   188,     0,   189,   190,   191,   192,   193,
       0,     0,   194,   195,     0,     0,     0,   196,   197,   198,
     200,   201,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   374,     0,   199,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   200,   201
};

static const yytype_int16 yycheck[] =
{
      15,    92,    94,    25,    25,    85,    25,    15,   163,    26,
      55,    25,    41,   105,    41,    41,    26,    86,    30,   305,
      35,    36,    37,    38,    39,    40,    41,    35,    36,    37,
      38,    39,    40,    41,    18,    79,    80,    52,   193,    65,
      59,    53,    57,    55,    52,    60,     0,   116,    65,   345,
     336,   143,    60,    73,    38,    65,    40,    38,   150,    40,
      44,   152,    91,    44,   360,    49,    92,    14,    83,    41,
      85,   116,     3,     4,   182,    83,    25,    42,   186,    91,
      27,    65,    31,    98,   105,   100,    65,    18,    72,   116,
      98,    72,   100,    65,   116,   116,    74,   116,     0,    30,
     255,    39,   116,    41,    76,   120,    65,    38,    25,    40,
     116,    48,   120,    44,    79,    80,    59,   101,    49,     4,
     101,    42,    65,   107,   108,    10,   107,   108,   106,    92,
     221,   211,    65,   288,    65,   113,    65,    65,   153,    59,
     155,    72,    65,    18,    75,    59,   124,   155,   228,    65,
      26,    25,    25,    18,   105,    59,    87,     7,    79,    80,
      65,    91,    25,    38,    50,    40,    97,    59,    26,    44,
     101,    26,   116,    38,    49,    40,   107,   108,    65,    44,
      92,    92,    91,    42,    49,   163,    65,    41,   280,   116,
      65,    16,    17,    65,    19,    20,   211,    72,   116,    65,
      65,    32,    33,    34,   219,   183,    26,    72,    39,    55,
      41,   291,    65,   228,    59,   193,    91,    59,   196,   197,
     198,    46,    47,    48,   202,    59,   101,   205,    93,    32,
      33,    34,   107,   108,    65,    18,   101,    59,    41,   116,
      65,    59,   107,   108,    59,    32,    33,    34,   226,   116,
     228,    92,   230,    65,    41,    38,   116,    40,   349,   116,
     116,    44,    65,   278,   279,   116,    49,   116,   283,   284,
     278,   279,   116,    41,    91,    91,   291,   255,    65,   104,
      55,    92,    65,    16,    17,   376,    19,    20,   116,    72,
     305,    91,    41,    92,   385,    26,    70,   305,   276,    91,
      59,    91,    16,    17,   282,    19,    20,   285,    91,   116,
     288,    91,   116,    46,    47,    48,    92,    55,   101,   297,
     298,   336,    52,    52,   107,   108,    87,    41,   336,    90,
     345,    91,    46,    47,    48,    91,   314,   345,    65,    91,
     318,   102,   103,   104,    70,   360,    48,   362,   142,   211,
     365,   273,   360,    32,    33,    34,   208,   292,   284,   337,
     230,   339,    41,   278,   115,    -1,    -1,    -1,   383,   347,
     348,   104,   387,   386,     5,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,    -1,    65,    18,    -1,   367,
     104,    -1,    -1,    -1,    -1,    26,    -1,   375,    35,    36,
      37,    38,    39,    40,    41,    -1,   384,    38,    -1,    40,
      41,    -1,    -1,    44,    -1,    -1,    -1,    -1,    49,    -1,
      51,    52,    53,    -1,    -1,    -1,    57,    58,    59,    -1,
      -1,    -1,    -1,    -1,    65,    66,    -1,    -1,    -1,    -1,
      71,    72,    -1,    -1,    -1,    -1,    83,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    85,    -1,    -1,    88,    -1,    -1,
      -1,    -1,    -1,    94,    95,    -1,    -1,    98,    99,   100,
     101,    -1,   103,    -1,    -1,    -1,   107,   108,   109,    -1,
     111,    -1,    -1,    -1,   115,     5,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    26,    77,    78,    79,
      80,    81,    82,    83,    84,    -1,    -1,    -1,    38,    -1,
      40,    41,    -1,    -1,    44,    -1,    -1,    -1,    -1,    49,
      -1,    51,    52,    53,    -1,    -1,    -1,    57,    58,    59,
      -1,    -1,    -1,   113,   114,    65,    66,    -1,    -1,    -1,
      -1,    71,    72,    -1,    -1,    -1,    -1,     5,     6,     7,
       8,     9,    10,    11,    -1,    85,    -1,    -1,    88,    -1,
      18,    -1,    -1,    -1,    94,    95,    -1,    -1,    98,    99,
     100,   101,    -1,   103,    -1,    -1,    -1,   107,   108,   109,
      38,   111,    40,    41,    -1,   115,    44,    -1,    -1,    -1,
      -1,    49,    -1,    51,    52,    53,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    -1,    -1,    -1,    65,    66,    -1,
      -1,    -1,    -1,    71,    72,    -1,    -1,    -1,    -1,     5,
       6,     7,     8,     9,    10,    11,    -1,    85,    -1,    -1,
      88,    -1,    18,    -1,    -1,    -1,    94,    95,    -1,    -1,
      98,    99,   100,   101,   102,   103,    -1,    -1,    -1,   107,
     108,   109,    38,   111,    40,    41,    -1,   115,    44,    -1,
      -1,    -1,    -1,    49,    -1,    51,    52,    53,    -1,    -1,
      -1,    57,    58,    59,    -1,    -1,    -1,    -1,    -1,    65,
      66,    -1,    -1,    -1,    -1,    71,    72,    -1,    -1,    -1,
      -1,     5,     6,     7,     8,     9,    10,    11,    -1,    85,
      -1,    -1,    88,    -1,    18,    -1,    -1,    -1,    94,    95,
      -1,    -1,    98,    99,   100,   101,    -1,   103,    -1,    -1,
      -1,   107,   108,   109,    38,   111,    40,    41,    -1,   115,
      44,    -1,    -1,    -1,    -1,    49,    -1,    51,    52,    53,
      -1,    -1,    -1,    57,    58,    59,    -1,    -1,    -1,    39,
      -1,    65,    66,    -1,    -1,    -1,    -1,    71,    72,    -1,
      -1,    -1,    -1,    53,    -1,    55,    56,    57,    58,    59,
      -1,    85,    62,    63,    88,    -1,    18,    67,    68,    69,
      94,    95,    -1,    -1,    98,    99,   100,   101,    -1,   103,
      -1,    -1,    -1,   107,   108,   109,    38,   111,    40,    41,
      -1,   115,    44,    93,    -1,    -1,    -1,    49,    -1,    51,
      52,    53,    -1,    -1,    -1,    57,    58,    59,    -1,    -1,
      -1,   111,   112,    65,    66,    -1,   116,    -1,    -1,    -1,
      72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    88,    -1,    18,    -1,
      92,    -1,    94,    95,    -1,    -1,    98,    -1,    -1,   101,
      -1,    -1,    -1,    -1,    -1,   107,   108,   109,    38,   111,
      40,    41,    -1,   115,    44,    -1,    -1,    -1,    -1,    49,
      -1,    51,    52,    53,    -1,    -1,    -1,    57,    58,    59,
      -1,    -1,    -1,    39,    -1,    65,    66,    -1,    -1,    -1,
      -1,    -1,    72,    -1,    -1,    -1,    -1,    53,    -1,    55,
      56,    57,    58,    59,    -1,    -1,    62,    63,    88,    -1,
      -1,    67,    68,    69,    94,    95,    -1,    25,    98,    -1,
      -1,   101,    -1,    -1,    -1,    -1,    -1,   107,   108,   109,
      38,   111,    40,    41,    -1,   115,    44,    93,    -1,    -1,
      -1,    -1,    -1,    51,    52,    53,    -1,    -1,    -1,    57,
      58,    59,    -1,    -1,    -1,   111,   112,    65,    66,    -1,
     116,    -1,    -1,    -1,    72,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      88,    -1,    -1,    91,    -1,    -1,    94,    95,    -1,    -1,
      98,    -1,    -1,   101,    -1,    -1,    -1,    -1,    -1,   107,
     108,   109,    38,   111,    40,    41,    -1,   115,    44,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    52,    53,    -1,    -1,
      -1,    57,    58,    59,    -1,    -1,    -1,    -1,    -1,    65,
      66,    -1,    -1,    -1,    -1,    -1,    72,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    88,    -1,    -1,    -1,    -1,    -1,    94,    95,
      -1,    -1,    98,    -1,    -1,   101,    -1,    -1,    -1,    -1,
      -1,   107,   108,   109,    -1,   111,    -1,    -1,    -1,   115,
     116,    38,    -1,    40,    41,    42,    -1,    44,    -1,    -1,
      -1,    -1,    -1,    -1,    51,    52,    53,    -1,    -1,    -1,
      57,    58,    59,    -1,    -1,    -1,    39,    -1,    65,    66,
      -1,    -1,    -1,    -1,    -1,    72,    -1,    -1,    -1,    -1,
      53,    -1,    55,    56,    57,    58,    59,    -1,    -1,    62,
      63,    88,    -1,    -1,    67,    68,    69,    94,    95,    -1,
      -1,    98,    -1,    -1,   101,    -1,    -1,    -1,    -1,    -1,
     107,   108,   109,    38,   111,    40,    41,    -1,   115,    44,
      93,    -1,    -1,    -1,    -1,    -1,    51,    52,    53,    -1,
      -1,    -1,    57,    58,    59,    -1,    -1,    -1,   111,   112,
      65,    66,    -1,   116,    -1,    -1,    -1,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    88,    -1,    -1,    91,    -1,    -1,    94,
      95,    -1,    -1,    98,    -1,    -1,   101,    -1,    -1,    -1,
      -1,    -1,   107,   108,   109,    38,   111,    40,    41,    42,
     115,    44,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,
      53,    -1,    -1,    -1,    57,    58,    59,    -1,    -1,    -1,
      39,    -1,    65,    66,    -1,    -1,    -1,    -1,    -1,    72,
      -1,    -1,    -1,    -1,    53,    -1,    55,    56,    57,    58,
      59,    -1,    -1,    62,    63,    88,    -1,    -1,    67,    68,
      69,    94,    95,    -1,    -1,    98,    -1,    -1,   101,    -1,
      -1,    -1,    -1,    -1,   107,   108,   109,    38,   111,    40,
      41,    42,   115,    44,    93,    -1,    -1,    -1,    -1,    -1,
      51,    52,    53,    -1,    -1,    -1,    57,    58,    59,    -1,
      -1,    -1,   111,   112,    65,    66,    -1,    -1,    -1,    -1,
      -1,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    -1,    -1,
      -1,    -1,    -1,    94,    95,    -1,    -1,    98,    -1,    -1,
     101,    -1,    -1,    -1,    -1,    -1,   107,   108,   109,    38,
     111,    40,    41,    -1,   115,    44,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    52,    53,    -1,    -1,    -1,    57,    58,
      59,    -1,    -1,    -1,    -1,    -1,    65,    66,    -1,    -1,
      -1,    -1,    -1,    72,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,
      -1,    -1,    -1,    -1,    -1,    94,    95,    -1,    -1,    98,
      -1,    39,   101,    -1,    -1,    -1,    -1,    -1,   107,   108,
     109,    -1,   111,    -1,    -1,    53,   115,    55,    56,    57,
      58,    59,    -1,    -1,    62,    63,    -1,    -1,    39,    67,
      68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    53,    -1,    55,    56,    57,    58,    59,    -1,
      -1,    62,    63,    91,    92,    93,    67,    68,    69,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,
      -1,    -1,    -1,   111,   112,    -1,    -1,    -1,    -1,    -1,
      91,    92,    93,    53,    -1,    55,    56,    57,    58,    59,
      -1,    -1,    62,    63,    -1,    -1,    -1,    67,    68,    69,
     111,   112,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      39,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    91,    92,    93,    53,    -1,    55,    56,    57,    58,
      59,    39,    -1,    62,    63,    -1,    -1,    -1,    67,    68,
      69,   111,   112,    -1,    -1,    53,    -1,    55,    56,    57,
      58,    59,    -1,    -1,    62,    63,    -1,    -1,    -1,    67,
      68,    69,    -1,    -1,    93,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   111,   112,    92,    93,    53,    -1,    55,    56,
      57,    58,    59,    -1,    -1,    62,    63,    -1,    -1,    -1,
      67,    68,    69,   111,   112,    -1,    -1,    -1,    -1,    -1,
      -1,    39,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    91,    53,    93,    55,    56,    57,
      58,    59,    39,    -1,    62,    63,    -1,    -1,    -1,    67,
      68,    69,    -1,    -1,   111,   112,    53,    -1,    55,    56,
      57,    58,    59,    -1,    -1,    62,    63,    -1,    -1,    -1,
      67,    68,    69,    70,    -1,    93,    -1,    -1,    -1,    -1,
      -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   111,   112,    53,    93,    55,    56,    57,
      58,    59,    -1,    -1,    62,    63,    -1,    -1,    39,    67,
      68,    69,    -1,    -1,   111,   112,    -1,    -1,    -1,    -1,
      -1,    -1,    53,    -1,    55,    56,    57,    58,    59,    -1,
      -1,    62,    63,    91,    -1,    93,    67,    68,    69,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,
      42,    -1,    -1,   111,   112,    -1,    -1,    -1,    -1,    -1,
      91,    53,    93,    55,    56,    57,    58,    59,    39,    -1,
      62,    63,    -1,    -1,    -1,    67,    68,    69,    -1,    -1,
     111,   112,    53,    -1,    55,    56,    57,    58,    59,    -1,
      -1,    62,    63,    -1,    -1,    -1,    67,    68,    69,    -1,
      -1,    93,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,
     112,    92,    93,    53,    -1,    55,    56,    57,    58,    59,
      -1,    -1,    62,    63,    -1,    -1,    -1,    67,    68,    69,
     111,   112,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    91,    -1,    93,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   111,   112
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    14,    27,   118,   120,   121,    65,    73,     0,   118,
     119,    25,    31,   116,   118,   122,    65,   124,     3,     4,
      18,    30,    38,    40,    44,    49,    65,    72,    75,    87,
      97,   101,   107,   108,   125,   126,   127,   130,   132,   136,
     138,   143,   150,   151,   152,   153,   154,   184,    92,    25,
      65,    65,    59,    65,   144,    65,    48,    59,    65,    65,
      59,   144,    26,   125,   125,   125,   125,   125,   125,   125,
      16,    17,    19,    20,    41,    46,    47,    48,   104,   139,
     140,   141,   124,   123,    25,    25,    18,    91,   145,   150,
     144,   105,    25,   116,   144,   155,    38,   184,    59,   133,
       7,    65,   131,   139,   140,   142,    41,    42,    51,    52,
      53,    57,    58,    59,    65,    66,    88,    94,    95,    98,
     109,   111,   115,   167,   170,   171,   176,   177,   178,   179,
     181,   182,   184,   141,   141,    65,   125,    26,    65,   135,
     128,   149,   150,   142,    91,    32,    33,    34,    65,   129,
     142,   144,    25,   156,   155,    50,    91,   134,   150,    86,
     116,    93,   150,    59,   142,   142,   142,   155,   167,   172,
      77,    78,    79,    80,    81,    82,    83,    84,   113,   114,
     183,   167,    39,    41,   183,   150,    39,    42,    53,    55,
      56,    57,    58,    59,    62,    63,    67,    68,    69,    93,
     111,   112,   168,   169,   167,    55,   116,    26,    92,   137,
      26,   116,    65,   129,   155,    92,    65,   105,   155,   156,
       5,     6,     7,     8,     9,    10,    11,    26,    59,    65,
      71,    85,    99,   100,   103,   149,   157,   159,   160,   161,
     162,   163,   164,   165,   167,   184,   150,    91,    65,    76,
     116,   116,   116,    91,   172,    92,    42,    91,    65,   179,
      42,   167,    65,   179,    25,    91,   172,   175,   167,   167,
     167,   167,   167,   135,    26,   128,    55,    65,   146,    59,
     147,    26,    59,   156,    59,    59,   116,   116,    59,   116,
     167,    92,   149,   166,   167,   176,   116,    59,    59,   116,
     116,   116,   116,   116,    91,    92,    65,    91,   172,    42,
      26,    65,   174,    91,    70,   116,   137,   167,    55,   145,
     148,   150,   155,   167,     5,   161,   167,   167,   172,   116,
     149,   166,    91,   167,   167,   134,    92,    41,   180,    70,
      26,   167,   167,    91,    65,    92,    91,    59,   116,    91,
      91,    91,    91,    92,    91,    92,   134,    42,   167,   167,
      92,   148,   156,   167,   167,   156,   116,    55,    52,    52,
      42,    92,   173,   148,    91,   116,   102,   167,    91,    91,
      65,   158,   167,   156,    70,    91,   167,   156,   173
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   117,   119,   118,   118,   118,   120,   122,   121,   123,
     121,   124,   124,   125,   125,   125,   125,   125,   125,   125,
     125,   126,   126,   127,   128,   128,   129,   129,   129,   130,
     130,   131,   131,   131,   132,   132,   133,   133,   134,   134,
     134,   134,   134,   135,   136,   136,   137,   137,   138,   138,
     139,   139,   139,   140,   140,   140,   140,   140,   141,   141,
     141,   142,   142,   142,   142,   143,   143,   143,   143,   144,
     146,   145,   145,   145,   145,   145,   147,   148,   148,   148,
     148,   149,   149,   149,   149,   150,   150,   150,   150,   150,
     150,   151,   152,   153,   153,   154,   155,   155,   156,   156,
     156,   156,   156,   156,   156,   156,   156,   156,   156,   156,
     156,   156,   156,   156,   156,   157,   157,   157,   157,   158,
     159,   159,   160,   161,   161,   162,   163,   164,   165,   165,
     165,   166,   166,   167,   167,   167,   167,   167,   167,   167,
     167,   167,   167,   167,   167,   167,   168,   168,   168,   168,
     168,   168,   168,   168,   169,   169,   170,   170,   170,   170,
     170,   170,   170,   171,   171,   171,   171,   171,   172,   172,
     173,   173,   174,   175,   175,   175,   176,   176,   177,   178,
     178,   178,   178,   179,   179,   180,   180,   180,   181,   181,
     182,   182,   182,   182,   183,   183,   183,   183,   183,   183,
     183,   183,   183,   183,   184,   184,   184,   184,   184,   184,
     184
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     3,     1,     2,     3,     0,     6,     0,
       8,     1,     3,     2,     2,     2,     2,     2,     2,     2,
       0,     5,     5,     5,     3,     2,     1,     1,     1,     4,
       3,     1,     4,     3,     5,     4,     3,     2,     5,     3,
       4,     2,     1,     1,     4,     6,     3,     0,     4,     6,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       0,     2,     2,     2,     0,     7,     5,     4,     5,     3,
       0,     5,     3,     2,     1,     0,     3,     1,     2,     3,
       4,     5,     3,     2,     4,     1,     1,     1,     1,     1,
       2,     1,     6,     3,     4,     4,     3,     1,     2,     2,
       2,     3,     3,     3,     3,     3,     6,     4,     3,     3,
       3,     2,     3,     3,     0,     4,     4,     6,     6,     1,
       5,     7,     5,     1,     1,     9,     6,     2,     1,     6,
       3,     2,     0,     2,     1,     1,     1,     1,     3,     3,
       2,     3,     5,     3,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       5,     0,     4,     3,     2,     1,     4,     3,     2,     3,
       3,     3,     3,     5,     3,     3,     2,     0,     1,     1,
       1,     1,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

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

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


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
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
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
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
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
# endif
#endif

#ifndef yytnamerr
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
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
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
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
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
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
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

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

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
  case 2: /* $@1: %empty  */
#line 73 "../klee/tools/klee/grammar.y"
{   clearContractData(); writeContractContent();
    writefile.str(std::string()); writeDecl.str(std::string());}
#line 2162 "../klee/tools/klee/grammar.c"
    break;

  case 3: /* SourceUnit: ContractDefinition $@1 SourceUnit  */
#line 75 "../klee/tools/klee/grammar.y"
               {(yyval.var) = new_node({(yyvsp[-2].var), (yyvsp[0].var)}); headNode = (yyval.var);}
#line 2168 "../klee/tools/klee/grammar.c"
    break;

  case 4: /* SourceUnit: ContractDefinition  */
#line 78 "../klee/tools/klee/grammar.y"
{(yyval.var) = (yyvsp[0].var); headNode = (yyval.var);}
#line 2174 "../klee/tools/klee/grammar.c"
    break;

  case 5: /* SourceUnit: PragmaDirective SourceUnit  */
#line 81 "../klee/tools/klee/grammar.y"
{(yyval.var) = (yyvsp[0].var); headNode = (yyval.var);}
#line 2180 "../klee/tools/klee/grammar.c"
    break;

  case 7: /* $@2: %empty  */
#line 86 "../klee/tools/klee/grammar.y"
{	createContract({(yyvsp[-2].var), (yyvsp[-1].var), new_node(": virtual public address"), (yyvsp[0].var)}); contract.name = (yyvsp[-1].var)->data;}
#line 2186 "../klee/tools/klee/grammar.c"
    break;

  case 8: /* ContractDefinition: CONTRACT IDENTIFIER L_CURLY_B $@2 ContractPart R_CURLY_B  */
#line 88 "../klee/tools/klee/grammar.y"
{
	addContractName((yyvsp[-4].var));
	writefile << "public:\n";
	writeAddrConstructor(contract.name);
	if(!contract.hasDefaultConstructor /*&& contract.hasParaConstructor*/){
        writefile << "public:\n";
        writeConstructor(writefile, contract.name);
        writefile << '\n';
    }
	writefile << "};\n"; (yyval.var) = new_node({(yyvsp[-5].var), (yyvsp[-4].var), new_node(": virtual public address"), (yyvsp[-3].var), (yyvsp[-1].var), (yyvsp[0].var)});
}
#line 2202 "../klee/tools/klee/grammar.c"
    break;

  case 9: /* $@3: %empty  */
#line 101 "../klee/tools/klee/grammar.y"
{	createContract({(yyvsp[-4].var), (yyvsp[-3].var), new_node(": virtual public address, "), (yyvsp[-1].var), (yyvsp[0].var)}); contract.name = (yyvsp[-3].var)->data; baseClass = (yyvsp[-1].var);}
#line 2208 "../klee/tools/klee/grammar.c"
    break;

  case 10: /* ContractDefinition: CONTRACT IDENTIFIER IS BaseClass L_CURLY_B $@3 ContractPart R_CURLY_B  */
#line 103 "../klee/tools/klee/grammar.y"
{
	addContractName((yyvsp[-6].var));
	writefile << "public:\n";
	writeAddrConstructor(contract.name);
	if(!contract.hasDefaultConstructor /*&& contract.hasParaConstructor*/){
        writefile << "public:\n";
        writeConstructor(writefile, contract.name);
        writefile << '\n';
    }
	writefile << "};\n"; (yyval.var) = new_node({(yyvsp[-7].var), (yyvsp[-6].var), new_node(": virtual public address, "), (yyvsp[-4].var), (yyvsp[-3].var), (yyvsp[-1].var), (yyvsp[0].var)});
}
#line 2224 "../klee/tools/klee/grammar.c"
    break;

  case 11: /* BaseClass: IDENTIFIER  */
#line 116 "../klee/tools/klee/grammar.y"
                       {(yyval.var) = new_node({new_node("public "), (yyvsp[0].var)});}
#line 2230 "../klee/tools/klee/grammar.c"
    break;

  case 12: /* BaseClass: IDENTIFIER COMMA BaseClass  */
#line 117 "../klee/tools/klee/grammar.y"
                             {(yyval.var) = new_node({new_node("public "), (yyvsp[-2].var), (yyvsp[-1].var), (yyvsp[0].var)});}
#line 2236 "../klee/tools/klee/grammar.c"
    break;

  case 13: /* ContractPart: StateVariableDeclaration ContractPart  */
#line 122 "../klee/tools/klee/grammar.y"
{(yyval.var) = new_node({(yyvsp[-1].var), (yyvsp[0].var)});}
#line 2242 "../klee/tools/klee/grammar.c"
    break;

  case 14: /* ContractPart: FunctionDefinition ContractPart  */
#line 125 "../klee/tools/klee/grammar.y"
{(yyval.var) = new_node({(yyvsp[-1].var), (yyvsp[0].var)});}
#line 2248 "../klee/tools/klee/grammar.c"
    break;

  case 15: /* ContractPart: UsingForDeclaration ContractPart  */
#line 128 "../klee/tools/klee/grammar.y"
{(yyval.var) = new_node({(yyvsp[-1].var), (yyvsp[0].var)});}
#line 2254 "../klee/tools/klee/grammar.c"
    break;

  case 16: /* ContractPart: StructDefinition ContractPart  */
#line 131 "../klee/tools/klee/grammar.y"
{(yyval.var) = new_node({(yyvsp[-1].var), (yyvsp[0].var)});}
#line 2260 "../klee/tools/klee/grammar.c"
    break;

  case 17: /* ContractPart: ModifierDefinition ContractPart  */
#line 134 "../klee/tools/klee/grammar.y"
{(yyval.var) = new_node({(yyvsp[-1].var), (yyvsp[0].var)});}
#line 2266 "../klee/tools/klee/grammar.c"
    break;

  case 18: /* ContractPart: EventDefinition ContractPart  */
#line 137 "../klee/tools/klee/grammar.y"
{(yyval.var) = new_node({(yyvsp[-1].var), (yyvsp[0].var)});}
#line 2272 "../klee/tools/klee/grammar.c"
    break;

  case 19: /* ContractPart: EnumDefinition ContractPart  */
#line 140 "../klee/tools/klee/grammar.y"
{(yyval.var) = new_node({(yyvsp[-1].var), (yyvsp[0].var)});}
#line 2278 "../klee/tools/klee/grammar.c"
    break;

  case 20: /* ContractPart: %empty  */
#line 142 "../klee/tools/klee/grammar.y"
   { (yyval.var) = new_node(); }
#line 2284 "../klee/tools/klee/grammar.c"
    break;

  case 21: /* UsingForDeclaration: USING IDENTIFIER FOR STAR SEMICOLON  */
#line 146 "../klee/tools/klee/grammar.y"
{(yyval.var) = new_node({(yyvsp[-4].var), (yyvsp[-3].var), (yyvsp[-2].var), (yyvsp[-1].var), (yyvsp[0].var)});}
#line 2290 "../klee/tools/klee/grammar.c"
    break;

  case 22: /* UsingForDeclaration: USING IDENTIFIER FOR TypeName SEMICOLON  */
#line 149 "../klee/tools/klee/grammar.y"
{(yyval.var) = new_node({(yyvsp[-4].var), (yyvsp[-3].var), (yyvsp[-2].var), (yyvsp[-1].var), (yyvsp[0].var)});}
#line 2296 "../klee/tools/klee/grammar.c"
    break;

  case 23: /* StructDefinition: STRUCT IDENTIFIER L_CURLY_B Vars R_CURLY_B  */
#line 153 "../klee/tools/klee/grammar.y"
{(yyval.var) = new_node({(yyvsp[-4].var), (yyvsp[-3].var), (yyvsp[-2].var), (yyvsp[-1].var), (yyvsp[0].var)}); createStruct({(yyvsp[-4].var), (yyvsp[-3].var), (yyvsp[-2].var), (yyvsp[-1].var)});}
#line 2302 "../klee/tools/klee/grammar.c"
    break;

  case 24: /* Vars: VariableDeclaration SEMICOLON Vars  */
#line 157 "../klee/tools/klee/grammar.y"
{(yyval.var) = new_node({(yyvsp[-2].var), (yyvsp[-1].var), (yyvsp[0].var)});}
#line 2308 "../klee/tools/klee/grammar.c"
    break;

  case 25: /* Vars: VariableDeclaration SEMICOLON  */
#line 159 "../klee/tools/klee/grammar.y"
                                {(yyval.var) = new_node({(yyvsp[-1].var), (yyvsp[0].var)});}
#line 2314 "../klee/tools/klee/grammar.c"
    break;

  case 26: /* StorageLocation: MEMORY  */
#line 162 "../klee/tools/klee/grammar.y"
                        {(yyval.var) = (yyvsp[0].var);}
#line 2320 "../klee/tools/klee/grammar.c"
    break;

  case 27: /* StorageLocation: STORAGE  */
#line 163 "../klee/tools/klee/grammar.y"
          {(yyval.var) = (yyvsp[0].var);}
#line 2326 "../klee/tools/klee/grammar.c"
    break;

  case 28: /* StorageLocation: CALLDATA  */
#line 164 "../klee/tools/klee/grammar.y"
           {(yyval.var) = (yyvsp[0].var);}
#line 2332 "../klee/tools/klee/grammar.c"
    break;

  case 29: /* ModifierDefinition: MODIFIER IDENTIFIER ParameterList Block  */
#line 168 "../klee/tools/klee/grammar.y"
{(yyval.var) = new_node({(yyvsp[-3].var), (yyvsp[-2].var), (yyvsp[-1].var), (yyvsp[0].var)}); FunctionData* f = createFunction(MODIFIER_TYPE, {(yyvsp[-2].var), (yyvsp[-1].var), (yyvsp[0].var)}, new_node("public")); contract.functions.push_back(f); funcArgs.clear();}
#line 2338 "../klee/tools/klee/grammar.c"
    break;

  case 30: /* ModifierDefinition: MODIFIER IDENTIFIER Block  */
#line 171 "../klee/tools/klee/grammar.y"
{(yyval.var) = new_node({(yyvsp[-2].var), (yyvsp[-1].var), (yyvsp[0].var)}); FunctionData* f = createFunction(MODIFIER_TYPE, {(yyvsp[-1].var), new_node("()"), (yyvsp[0].var)}, new_node("public")); contract.functions.push_back(f);}
#line 2344 "../klee/tools/klee/grammar.c"
    break;

  case 31: /* ModifierInvocation: IDENTIFIER  */
#line 174 "../klee/tools/klee/grammar.y"
                               {(yyval.var) = (yyvsp[0].var); hasModifier = true; modifiers.push_back(new_node({(yyvsp[0].var), new_node("()")}));}
#line 2350 "../klee/tools/klee/grammar.c"
    break;

  case 32: /* ModifierInvocation: IDENTIFIER L_PAREN ExpressionList R_PAREN  */
#line 177 "../klee/tools/klee/grammar.y"
{(yyval.var) = new_node({(yyvsp[-3].var), (yyvsp[-2].var), (yyvsp[-1].var), (yyvsp[0].var)}); hasModifier = true; modifiers.push_back((yyval.var));}
#line 2356 "../klee/tools/klee/grammar.c"
    break;

  case 33: /* ModifierInvocation: IDENTIFIER L_PAREN R_PAREN  */
#line 180 "../klee/tools/klee/grammar.y"
{(yyval.var) = new_node({(yyvsp[-2].var), (yyvsp[-1].var), (yyvsp[0].var)}); hasModifier = true; modifiers.push_back((yyval.var));}
#line 2362 "../klee/tools/klee/grammar.c"
    break;

  case 34: /* EventDefinition: EVENT IDENTIFIER EventParameterList ANONYMOUS SEMICOLON  */
#line 185 "../klee/tools/klee/grammar.y"
{(yyval.var) = new_node({(yyvsp[-4].var), (yyvsp[-3].var), (yyvsp[-2].var), (yyvsp[0].var)}); createFunction(NORETURN_TYPE, {(yyvsp[-3].var), (yyvsp[-2].var), new_node("{}")}, new_node("public")); funcArgs.clear();}
#line 2368 "../klee/tools/klee/grammar.c"
    break;

  case 35: /* EventDefinition: EVENT IDENTIFIER EventParameterList SEMICOLON  */
#line 188 "../klee/tools/klee/grammar.y"
{(yyval.var) = new_node({(yyvsp[-3].var), (yyvsp[-2].var), (yyvsp[-1].var), (yyvsp[0].var)}); createFunction(NORETURN_TYPE, {(yyvsp[-2].var), (yyvsp[-1].var), new_node("{}")}, new_node("public")); funcArgs.clear();}
#line 2374 "../klee/tools/klee/grammar.c"
    break;

  case 36: /* EventParameterList: L_PAREN EventParameter R_PAREN  */
#line 191 "../klee/tools/klee/grammar.y"
                                                   {(yyval.var) = new_node({(yyvsp[-2].var), (yyvsp[-1].var), (yyvsp[0].var)});}
#line 2380 "../klee/tools/klee/grammar.c"
    break;

  case 37: /* EventParameterList: L_PAREN R_PAREN  */
#line 193 "../klee/tools/klee/grammar.y"
                  {(yyval.var) = new_node({(yyvsp[-1].var), (yyvsp[0].var)});}
#line 2386 "../klee/tools/klee/grammar.c"
    break;

  case 38: /* EventParameter: TypeName INDEXED IDENTIFIER COMMA EventParameter  */
#line 197 "../klee/tools/klee/grammar.y"
{(yyval.var) = new_node({(yyvsp[-4].var), (yyvsp[-2].var), (yyvsp[-1].var), (yyvsp[0].var)});}
#line 2392 "../klee/tools/klee/grammar.c"
    break;

  case 39: /* EventParameter: TypeName INDEXED IDENTIFIER  */
#line 199 "../klee/tools/klee/grammar.y"
                              {(yyval.var) = new_node({(yyvsp[-2].var), (yyvsp[0].var)});}
#line 2398 "../klee/tools/klee/grammar.c"
    break;

  case 40: /* EventParameter: TypeName IDENTIFIER COMMA EventParameter  */
#line 201 "../klee/tools/klee/grammar.y"
                                           {(yyval.var) = new_node({(yyvsp[-3].var), (yyvsp[-2].var), (yyvsp[-1].var), (yyvsp[0].var)});}
#line 2404 "../klee/tools/klee/grammar.c"
    break;

  case 41: /* EventParameter: TypeName IDENTIFIER  */
#line 203 "../klee/tools/klee/grammar.y"
                      {(yyval.var) = new_node({(yyvsp[-1].var), (yyvsp[0].var)});}
#line 2410 "../klee/tools/klee/grammar.c"
    break;

  case 42: /* EventParameter: TypeName  */
#line 205 "../klee/tools/klee/grammar.y"
           {(yyval.var) = (yyvsp[0].var);}
#line 2416 "../klee/tools/klee/grammar.c"
    break;

  case 43: /* EnumValue: IDENTIFIER  */
#line 208 "../klee/tools/klee/grammar.y"
                      {(yyval.var) = (yyvsp[0].var);}
#line 2422 "../klee/tools/klee/grammar.c"
    break;

  case 44: /* EnumDefinition: ENUM IDENTIFIER L_CURLY_B R_CURLY_B  */
#line 211 "../klee/tools/klee/grammar.y"
{(yyval.var) = new_node({(yyvsp[-3].var), (yyvsp[-2].var), (yyvsp[-1].var), (yyvsp[0].var)}); createEnum({(yyvsp[-3].var), (yyvsp[-2].var), (yyvsp[-1].var), (yyvsp[0].var)});}
#line 2428 "../klee/tools/klee/grammar.c"
    break;

  case 45: /* EnumDefinition: ENUM IDENTIFIER L_CURLY_B EnumValue EnumValues R_CURLY_B  */
#line 214 "../klee/tools/klee/grammar.y"
{(yyval.var) = new_node({(yyvsp[-5].var), (yyvsp[-4].var), (yyvsp[-3].var), (yyvsp[-2].var), (yyvsp[-1].var), (yyvsp[0].var)}); createEnum({(yyvsp[-5].var), (yyvsp[-4].var), (yyvsp[-3].var), (yyvsp[-2].var), (yyvsp[-1].var), (yyvsp[0].var)});}
#line 2434 "../klee/tools/klee/grammar.c"
    break;

  case 46: /* EnumValues: COMMA EnumValue EnumValues  */
#line 218 "../klee/tools/klee/grammar.y"
{(yyval.var) = new_node({(yyvsp[-2].var), (yyvsp[-1].var), (yyvsp[0].var)});}
#line 2440 "../klee/tools/klee/grammar.c"
    break;

  case 47: /* EnumValues: %empty  */
#line 220 "../klee/tools/klee/grammar.y"
 { (yyval.var) = new_node(); }
#line 2446 "../klee/tools/klee/grammar.c"
    break;

  case 48: /* StateVariableDeclaration: TypeName VariableAttribute IDENTIFIER SEMICOLON  */
#line 224 "../klee/tools/klee/grammar.y"
{(yyval.var) = new_node({(yyvsp[-3].var), (yyvsp[-2].var), (yyvsp[-1].var), (yyvsp[0].var)}); createState({(yyvsp[-3].var), (yyvsp[-1].var), (yyvsp[0].var)}, (yyvsp[-2].var), false);}
#line 2452 "../klee/tools/klee/grammar.c"
    break;

  case 49: /* StateVariableDeclaration: TypeName VariableAttribute IDENTIFIER EQUAL Expression SEMICOLON  */
#line 227 "../klee/tools/klee/grammar.y"
{(yyval.var) = new_node({(yyvsp[-5].var), (yyvsp[-4].var), (yyvsp[-3].var), (yyvsp[-2].var), (yyvsp[-1].var), (yyvsp[0].var)}); createState({(yyvsp[-5].var), (yyvsp[-3].var), (yyvsp[-2].var), (yyvsp[-1].var), (yyvsp[0].var)}, (yyvsp[-4].var), true);}
#line 2458 "../klee/tools/klee/grammar.c"
    break;

  case 50: /* StateMutability: PURE  */
#line 230 "../klee/tools/klee/grammar.y"
                      {(yyval.var) = (yyvsp[0].var);}
#line 2464 "../klee/tools/klee/grammar.c"
    break;

  case 51: /* StateMutability: VIEW  */
#line 231 "../klee/tools/klee/grammar.y"
       {(yyval.var) = (yyvsp[0].var);}
#line 2470 "../klee/tools/klee/grammar.c"
    break;

  case 52: /* StateMutability: PAYABLE  */
#line 232 "../klee/tools/klee/grammar.y"
          {(yyval.var) = (yyvsp[0].var);}
#line 2476 "../klee/tools/klee/grammar.c"
    break;

  case 53: /* Qualifier: PUBLIC  */
#line 235 "../klee/tools/klee/grammar.y"
                  {(yyval.var) = (yyvsp[0].var);}
#line 2482 "../klee/tools/klee/grammar.c"
    break;

  case 54: /* Qualifier: PRIVATE  */
#line 236 "../klee/tools/klee/grammar.y"
          {(yyval.var) = (yyvsp[0].var);}
#line 2488 "../klee/tools/klee/grammar.c"
    break;

  case 55: /* Qualifier: CONSTANT  */
#line 237 "../klee/tools/klee/grammar.y"
           {(yyval.var) = (yyvsp[0].var);}
#line 2494 "../klee/tools/klee/grammar.c"
    break;

  case 56: /* Qualifier: INTERNAL  */
#line 238 "../klee/tools/klee/grammar.y"
            {(yyval.var) = (yyvsp[0].var);}
#line 2500 "../klee/tools/klee/grammar.c"
    break;

  case 57: /* Qualifier: EXTERNAL  */
#line 239 "../klee/tools/klee/grammar.y"
           {(yyval.var) = (yyvsp[0].var);}
#line 2506 "../klee/tools/klee/grammar.c"
    break;

  case 58: /* VariableAttribute: Qualifier VariableAttribute  */
#line 243 "../klee/tools/klee/grammar.y"
{(yyval.var) = new_node({(yyvsp[-1].var), (yyvsp[0].var)});}
#line 2512 "../klee/tools/klee/grammar.c"
    break;

  case 59: /* VariableAttribute: StateMutability VariableAttribute  */
#line 246 "../klee/tools/klee/grammar.y"
{(yyval.var) = new_node({(yyvsp[-1].var), (yyvsp[0].var)});}
#line 2518 "../klee/tools/klee/grammar.c"
    break;

  case 60: /* VariableAttribute: %empty  */
#line 248 "../klee/tools/klee/grammar.y"
  { (yyval.var) = new_node(); }
#line 2524 "../klee/tools/klee/grammar.c"
    break;

  case 61: /* FunctionAttribute: Qualifier FunctionAttribute  */
#line 252 "../klee/tools/klee/grammar.y"
{(yyval.var) = new_node({(yyvsp[-1].var), (yyvsp[0].var)});}
#line 2530 "../klee/tools/klee/grammar.c"
    break;

  case 62: /* FunctionAttribute: StateMutability FunctionAttribute  */
#line 255 "../klee/tools/klee/grammar.y"
{(yyval.var) = new_node({(yyvsp[-1].var), (yyvsp[0].var)});}
#line 2536 "../klee/tools/klee/grammar.c"
    break;

  case 63: /* FunctionAttribute: ModifierInvocation FunctionAttribute  */
#line 258 "../klee/tools/klee/grammar.y"
{(yyval.var) = new_node({(yyvsp[-1].var), (yyvsp[0].var)});}
#line 2542 "../klee/tools/klee/grammar.c"
    break;

  case 64: /* FunctionAttribute: %empty  */
#line 260 "../klee/tools/klee/grammar.y"
  { (yyval.var) = new_node(); }
#line 2548 "../klee/tools/klee/grammar.c"
    break;

  case 65: /* FunctionDefinition: FUNCTION IDENTIFIER ParameterList FunctionAttribute RETURNS ReturnList Block  */
#line 264 "../klee/tools/klee/grammar.y"
{	(yyval.var) = new_node({(yyvsp[-6].var), (yyvsp[-5].var), (yyvsp[-4].var), (yyvsp[-3].var), (yyvsp[-2].var), (yyvsp[-1].var), (yyvsp[0].var)});
	node* ret = (yyvsp[-1].var);
	if(!hasBody && isReturnIden){
		addRetVariables((yyvsp[-1].var), (yyvsp[0].var), hasBody);
		ret = getRetType((yyvsp[-1].var));
		hasBody = true;
		isReturnIden = false;
	}
	if(!hasBody){
		addRetVariables((yyvsp[-1].var), (yyvsp[0].var), hasBody);
		// ret = getRetType($6);
		hasBody = true;
	}

	if(isReturnIden){
		addRetVariables((yyvsp[-1].var), (yyvsp[0].var), hasBody);
		ret = getRetType((yyvsp[-1].var)/*retList*/);
		isReturnIden = false;
	}

	if(hasModifier){
		addModifier(modifiers, (yyvsp[0].var));
		hasModifier = false;
	}

	FunctionData* f = createFunction(RETURN_TYPE, {ret, (yyvsp[-5].var), (yyvsp[-4].var), (yyvsp[0].var)}, (yyvsp[-3].var));
	setFunctionDataAttr(f, funcArgs);
	contract.functions.push_back(f);
	funcArgs.clear();
	// if(!retList.empty())
	retList.clear();
	modifiers.clear();
}
#line 2586 "../klee/tools/klee/grammar.c"
    break;

  case 66: /* FunctionDefinition: FUNCTION IDENTIFIER ParameterList FunctionAttribute Block  */
#line 299 "../klee/tools/klee/grammar.y"
{	(yyval.var) = new_node({(yyvsp[-4].var), (yyvsp[-3].var), (yyvsp[-2].var), (yyvsp[-1].var), (yyvsp[0].var)});
	if(hasModifier){
		addModifier(modifiers, (yyvsp[0].var));
	}
	hasModifier = false;

	FunctionData* f = createFunction(NORETURN_TYPE, {(yyvsp[-3].var), (yyvsp[-2].var), (yyvsp[0].var)}, (yyvsp[-1].var));
	setFunctionDataAttr(f, funcArgs);
	contract.functions.push_back(f);
	funcArgs.clear();
	modifiers.clear();
}
#line 2603 "../klee/tools/klee/grammar.c"
    break;

  case 67: /* FunctionDefinition: CONSTRUCTOR ParameterList FunctionAttribute Block  */
#line 313 "../klee/tools/klee/grammar.y"
{(yyval.var) = new_node({(yyvsp[-3].var), (yyvsp[-2].var), (yyvsp[-1].var), (yyvsp[0].var)}); FunctionData* f = createFunction(CONSTRUCTOR_TYPE, {(yyvsp[-2].var), (yyvsp[0].var)}, (yyvsp[-1].var));
setFunctionDataAttr(f, funcArgs); contract.functions.push_back(f); funcArgs.clear(); hasModifier = false;}
#line 2610 "../klee/tools/klee/grammar.c"
    break;

  case 68: /* FunctionDefinition: FUNCTION L_PAREN R_PAREN FunctionAttribute Block  */
#line 317 "../klee/tools/klee/grammar.y"
{(yyval.var) = new_node({(yyvsp[-4].var), (yyvsp[-3].var), (yyvsp[-2].var), (yyvsp[-1].var), (yyvsp[0].var)}); FunctionData* f = createFunction(FALLBACK_TYPE, {new_node("void fallback()"), (yyvsp[0].var)}, (yyvsp[-1].var));
setFunctionDataAttr(f, funcArgs); contract.functions.push_back(f); funcArgs.clear(); hasFallback = true; hasModifier = false;}
#line 2617 "../klee/tools/klee/grammar.c"
    break;

  case 69: /* ParameterList: L_PAREN Parameter R_PAREN  */
#line 321 "../klee/tools/klee/grammar.y"
                                         {(yyval.var) = new_node({(yyvsp[-2].var), (yyvsp[-1].var), (yyvsp[0].var)});}
#line 2623 "../klee/tools/klee/grammar.c"
    break;

  case 70: /* $@4: %empty  */
#line 324 "../klee/tools/klee/grammar.y"
                                     {funcArgs.push_back(std::make_pair((yyvsp[-1].var), (yyvsp[-2].var)));}
#line 2629 "../klee/tools/klee/grammar.c"
    break;

  case 71: /* Parameter: TypeName IDENTIFIER COMMA $@4 Parameter  */
#line 324 "../klee/tools/klee/grammar.y"
                                                                                             {(yyval.var) = new_node({(yyvsp[-4].var), (yyvsp[-3].var), (yyvsp[-2].var), (yyvsp[0].var)});}
#line 2635 "../klee/tools/klee/grammar.c"
    break;

  case 72: /* Parameter: TypeName StorageLocation IDENTIFIER  */
#line 325 "../klee/tools/klee/grammar.y"
                                      {(yyval.var) = new_node({(yyvsp[-2].var), (yyvsp[0].var)}); funcArgs.push_back(std::make_pair((yyvsp[0].var), (yyvsp[-2].var)));}
#line 2641 "../klee/tools/klee/grammar.c"
    break;

  case 73: /* Parameter: TypeName IDENTIFIER  */
#line 326 "../klee/tools/klee/grammar.y"
                      {(yyval.var) = new_node({(yyvsp[-1].var), (yyvsp[0].var)}); funcArgs.push_back(std::make_pair((yyvsp[0].var), (yyvsp[-1].var)));}
#line 2647 "../klee/tools/klee/grammar.c"
    break;

  case 74: /* Parameter: TypeName  */
#line 327 "../klee/tools/klee/grammar.y"
           {(yyval.var) = (yyvsp[0].var);}
#line 2653 "../klee/tools/klee/grammar.c"
    break;

  case 75: /* Parameter: %empty  */
#line 328 "../klee/tools/klee/grammar.y"
  { (yyval.var) = new_node();}
#line 2659 "../klee/tools/klee/grammar.c"
    break;

  case 76: /* ReturnList: L_PAREN Parameter2 R_PAREN  */
#line 331 "../klee/tools/klee/grammar.y"
                                       {(yyval.var) = (yyvsp[-1].var);}
#line 2665 "../klee/tools/klee/grammar.c"
    break;

  case 77: /* Parameter2: TypeName  */
#line 334 "../klee/tools/klee/grammar.y"
                     {(yyval.var) = (yyvsp[0].var); retList.push_back((yyvsp[0].var));}
#line 2671 "../klee/tools/klee/grammar.c"
    break;

  case 78: /* Parameter2: TypeName IDENTIFIER  */
#line 335 "../klee/tools/klee/grammar.y"
                      {(yyval.var) = new_node({(yyvsp[-1].var), (yyvsp[0].var), new_node(";")}); retList.push_back((yyvsp[-1].var)); isReturnIden = true; }
#line 2677 "../klee/tools/klee/grammar.c"
    break;

  case 79: /* Parameter2: TypeName COMMA Parameter2  */
#line 336 "../klee/tools/klee/grammar.y"
                            { (yyval.var) = new_node({(yyvsp[-2].var), (yyvsp[-1].var), (yyvsp[0].var)}); retList.push_back((yyvsp[-1].var)); retList.push_back((yyvsp[-2].var)); isReturnIden = true;}
#line 2683 "../klee/tools/klee/grammar.c"
    break;

  case 80: /* Parameter2: TypeName IDENTIFIER COMMA Parameter2  */
#line 337 "../klee/tools/klee/grammar.y"
                                       {(yyval.var) = new_node({(yyvsp[-3].var), (yyvsp[-2].var), new_node(";"), (yyvsp[0].var)}); retList.push_back((yyvsp[-1].var)); retList.push_back((yyvsp[-3].var)); isReturnIden = true; }
#line 2689 "../klee/tools/klee/grammar.c"
    break;

  case 81: /* VariableDeclaration: TypeName StorageLocation IDENTIFIER EQUAL Expression  */
#line 340 "../klee/tools/klee/grammar.y"
                                                                          {(yyval.var) = new_node({(yyvsp[-4].var), (yyvsp[-2].var), (yyvsp[-1].var), (yyvsp[0].var)});}
#line 2695 "../klee/tools/klee/grammar.c"
    break;

  case 82: /* VariableDeclaration: TypeName StorageLocation IDENTIFIER  */
#line 341 "../klee/tools/klee/grammar.y"
                                      {(yyval.var) = new_node({(yyvsp[-2].var), (yyvsp[0].var)});}
#line 2701 "../klee/tools/klee/grammar.c"
    break;

  case 83: /* VariableDeclaration: TypeName IDENTIFIER  */
#line 342 "../klee/tools/klee/grammar.y"
                      {(yyval.var) = new_node({(yyvsp[-1].var), (yyvsp[0].var)});}
#line 2707 "../klee/tools/klee/grammar.c"
    break;

  case 84: /* VariableDeclaration: TypeName IDENTIFIER EQUAL Expression  */
#line 343 "../klee/tools/klee/grammar.y"
                                       {(yyval.var) = new_node({(yyvsp[-3].var), (yyvsp[-2].var), (yyvsp[-1].var), (yyvsp[0].var)});}
#line 2713 "../klee/tools/klee/grammar.c"
    break;

  case 85: /* TypeName: ElementaryTypeName  */
#line 346 "../klee/tools/klee/grammar.y"
                             {(yyval.var) = (yyvsp[0].var);}
#line 2719 "../klee/tools/klee/grammar.c"
    break;

  case 86: /* TypeName: Mapping  */
#line 347 "../klee/tools/klee/grammar.y"
          {(yyval.var) = (yyvsp[0].var);}
#line 2725 "../klee/tools/klee/grammar.c"
    break;

  case 87: /* TypeName: UserDefinedTypeName  */
#line 348 "../klee/tools/klee/grammar.y"
                      {(yyval.var) = (yyvsp[0].var);}
#line 2731 "../klee/tools/klee/grammar.c"
    break;

  case 88: /* TypeName: ArrayTypeName  */
#line 349 "../klee/tools/klee/grammar.y"
                {(yyval.var) = (yyvsp[0].var);}
#line 2737 "../klee/tools/klee/grammar.c"
    break;

  case 89: /* TypeName: FunctionTypeName  */
#line 350 "../klee/tools/klee/grammar.y"
                   {(yyval.var) = (yyvsp[0].var);}
#line 2743 "../klee/tools/klee/grammar.c"
    break;

  case 90: /* TypeName: ADDRESS PAYABLE  */
#line 351 "../klee/tools/klee/grammar.y"
                  {(yyval.var) = new_node({(yyvsp[-1].var), (yyvsp[0].var)});}
#line 2749 "../klee/tools/klee/grammar.c"
    break;

  case 91: /* UserDefinedTypeName: IDENTIFIER  */
#line 354 "../klee/tools/klee/grammar.y"
                                {(yyval.var) = (yyvsp[0].var);}
#line 2755 "../klee/tools/klee/grammar.c"
    break;

  case 92: /* Mapping: MAPPING L_PAREN ElementaryTypeName IMPLIES TypeName R_PAREN  */
#line 360 "../klee/tools/klee/grammar.y"
{
	node* temp1 = new_node("std::map");
	node* temp2 = new_node("<");
	node* temp3 = new_node(">");
	node* temp4 = new_node(",");
	(yyval.var) = new_node({temp1, temp2, (yyvsp[-3].var), temp4, (yyvsp[-1].var), temp3});
}
#line 2767 "../klee/tools/klee/grammar.c"
    break;

  case 93: /* ArrayTypeName: TypeName OPT_L OPT_R  */
#line 368 "../klee/tools/klee/grammar.y"
                                    {(yyval.var) = new_node({new_node("struct Vector"), new_node("<"), (yyvsp[-2].var), new_node(">")}); isArray = true;}
#line 2773 "../klee/tools/klee/grammar.c"
    break;

  case 94: /* ArrayTypeName: TypeName OPT_L Expression OPT_R  */
#line 369 "../klee/tools/klee/grammar.y"
                                   {(yyval.var) = new_node({(yyvsp[-3].var), (yyvsp[-2].var), (yyvsp[-1].var), (yyvsp[0].var)}); isArray = true;}
#line 2779 "../klee/tools/klee/grammar.c"
    break;

  case 95: /* FunctionTypeName: FUNCTION ParameterList RETURNS ParameterList  */
#line 372 "../klee/tools/klee/grammar.y"
                                                               {(yyval.var) = new_node({(yyvsp[-3].var), (yyvsp[-2].var), (yyvsp[-1].var), (yyvsp[0].var)});}
#line 2785 "../klee/tools/klee/grammar.c"
    break;

  case 96: /* Block: L_CURLY_B Statement R_CURLY_B  */
#line 375 "../klee/tools/klee/grammar.y"
                                     {(yyval.var) = new_node({(yyvsp[-2].var), (yyvsp[-1].var), (yyvsp[0].var)});}
#line 2791 "../klee/tools/klee/grammar.c"
    break;

  case 97: /* Block: SEMICOLON  */
#line 376 "../klee/tools/klee/grammar.y"
            {(yyval.var) = new_node({new_node("{"), new_node("}")}); hasBody = false;}
#line 2797 "../klee/tools/klee/grammar.c"
    break;

  case 98: /* Statement: Statement IfStatement  */
#line 379 "../klee/tools/klee/grammar.y"
                                  {(yyval.var) = new_node({(yyvsp[-1].var), (yyvsp[0].var)});}
#line 2803 "../klee/tools/klee/grammar.c"
    break;

  case 99: /* Statement: Statement WhileStatement  */
#line 380 "../klee/tools/klee/grammar.y"
                           {(yyval.var) = new_node({(yyvsp[-1].var), (yyvsp[0].var)});}
#line 2809 "../klee/tools/klee/grammar.c"
    break;

  case 100: /* Statement: Statement ForStatement  */
#line 381 "../klee/tools/klee/grammar.y"
                         {(yyval.var) = new_node({(yyvsp[-1].var), (yyvsp[0].var)});}
#line 2815 "../klee/tools/klee/grammar.c"
    break;

  case 101: /* Statement: L_CURLY_B Statement R_CURLY_B  */
#line 382 "../klee/tools/klee/grammar.y"
                                {(yyval.var) = new_node({(yyvsp[-2].var), (yyvsp[-1].var), (yyvsp[0].var)});}
#line 2821 "../klee/tools/klee/grammar.c"
    break;

  case 102: /* Statement: Statement SimpleStatement SEMICOLON  */
#line 383 "../klee/tools/klee/grammar.y"
                                      {(yyval.var) = new_node({(yyvsp[-2].var), (yyvsp[-1].var), (yyvsp[0].var)});}
#line 2827 "../klee/tools/klee/grammar.c"
    break;

  case 103: /* Statement: Statement DoWhileStatement SEMICOLON  */
#line 384 "../klee/tools/klee/grammar.y"
                                       {(yyval.var) = new_node({(yyvsp[-2].var), (yyvsp[-1].var), (yyvsp[0].var)});}
#line 2833 "../klee/tools/klee/grammar.c"
    break;

  case 104: /* Statement: Statement CONTINUE SEMICOLON  */
#line 385 "../klee/tools/klee/grammar.y"
                               {(yyval.var) = new_node({(yyvsp[-2].var), (yyvsp[-1].var), (yyvsp[0].var)});}
#line 2839 "../klee/tools/klee/grammar.c"
    break;

  case 105: /* Statement: Statement BREAK SEMICOLON  */
#line 386 "../klee/tools/klee/grammar.y"
                            {(yyval.var) = new_node({(yyvsp[-2].var), (yyvsp[-1].var), (yyvsp[0].var)});}
#line 2845 "../klee/tools/klee/grammar.c"
    break;

  case 106: /* Statement: Statement RETURN L_PAREN ExpressionList R_PAREN SEMICOLON  */
#line 387 "../klee/tools/klee/grammar.y"
                                                            {(yyval.var) = new_node({(yyvsp[-5].var), (yyvsp[-4].var), new_node("std::make_tuple"), (yyvsp[-3].var), (yyvsp[-2].var), (yyvsp[-1].var), (yyvsp[0].var)});}
#line 2851 "../klee/tools/klee/grammar.c"
    break;

  case 107: /* Statement: Statement RETURN Expression SEMICOLON  */
#line 388 "../klee/tools/klee/grammar.y"
                                        {(yyval.var) = new_node({(yyvsp[-3].var), (yyvsp[-2].var), (yyvsp[-1].var), (yyvsp[0].var)});}
#line 2857 "../klee/tools/klee/grammar.c"
    break;

  case 108: /* Statement: Statement RETURN SEMICOLON  */
#line 389 "../klee/tools/klee/grammar.y"
                             {(yyval.var) = new_node({(yyvsp[-2].var), (yyvsp[-1].var), (yyvsp[0].var)});}
#line 2863 "../klee/tools/klee/grammar.c"
    break;

  case 109: /* Statement: Statement THROW SEMICOLON  */
#line 390 "../klee/tools/klee/grammar.y"
                            {(yyval.var) = new_node({(yyvsp[-2].var), (yyvsp[-1].var), (yyvsp[0].var)});}
#line 2869 "../klee/tools/klee/grammar.c"
    break;

  case 110: /* Statement: Statement EmitStatement SEMICOLON  */
#line 391 "../klee/tools/klee/grammar.y"
                                    {(yyval.var) = new_node({(yyvsp[-2].var), (yyvsp[-1].var), (yyvsp[0].var)});}
#line 2875 "../klee/tools/klee/grammar.c"
    break;

  case 111: /* Statement: Statement UNDERSCORE  */
#line 392 "../klee/tools/klee/grammar.y"
                       {(yyval.var) = new_node({(yyvsp[-1].var), new_node("return true; return false;")});}
#line 2881 "../klee/tools/klee/grammar.c"
    break;

  case 112: /* Statement: Statement UNDERSCORE SEMICOLON  */
#line 393 "../klee/tools/klee/grammar.y"
                                 {(yyval.var) = new_node({(yyvsp[-2].var), new_node("return true; return false"), (yyvsp[0].var)});}
#line 2887 "../klee/tools/klee/grammar.c"
    break;

  case 113: /* Statement: Statement AssertStatement SEMICOLON  */
#line 394 "../klee/tools/klee/grammar.y"
                                      {(yyval.var) = new_node({(yyvsp[-2].var), (yyvsp[-1].var), (yyvsp[0].var)});}
#line 2893 "../klee/tools/klee/grammar.c"
    break;

  case 114: /* Statement: %empty  */
#line 396 "../klee/tools/klee/grammar.y"
  { (yyval.var) = new_node(); }
#line 2899 "../klee/tools/klee/grammar.c"
    break;

  case 115: /* AssertStatement: REQUIRE L_PAREN Expression R_PAREN  */
#line 400 "../klee/tools/klee/grammar.y"
                                                     {(yyval.var) = new_node({(yyvsp[-3].var), (yyvsp[-2].var), (yyvsp[-1].var), (yyvsp[0].var)});}
#line 2905 "../klee/tools/klee/grammar.c"
    break;

  case 116: /* AssertStatement: ASSERT L_PAREN Expression R_PAREN  */
#line 401 "../klee/tools/klee/grammar.y"
                                    {(yyval.var) = new_node({(yyvsp[-3].var), (yyvsp[-2].var), (yyvsp[-1].var), (yyvsp[0].var)});}
#line 2911 "../klee/tools/klee/grammar.c"
    break;

  case 117: /* AssertStatement: REQUIRE L_PAREN Expression COMMA STRING_LITERAL R_PAREN  */
#line 402 "../klee/tools/klee/grammar.y"
                                                          {node* temp = new_node("&&"); (yyval.var) = new_node({(yyvsp[-5].var), (yyvsp[-4].var), (yyvsp[-3].var), temp, (yyvsp[-1].var), (yyvsp[0].var)});}
#line 2917 "../klee/tools/klee/grammar.c"
    break;

  case 118: /* AssertStatement: ASSERT L_PAREN Expression COMMA STRING_LITERAL R_PAREN  */
#line 403 "../klee/tools/klee/grammar.y"
                                                         {node* temp = new_node("&&"); (yyval.var) = new_node({(yyvsp[-5].var), (yyvsp[-4].var), (yyvsp[-3].var), temp, (yyvsp[-1].var), (yyvsp[0].var)});}
#line 2923 "../klee/tools/klee/grammar.c"
    break;

  case 119: /* ExpressionStatement: Expression  */
#line 406 "../klee/tools/klee/grammar.y"
                                {(yyval.var) = (yyvsp[0].var);}
#line 2929 "../klee/tools/klee/grammar.c"
    break;

  case 120: /* IfStatement: IF L_PAREN Expression R_PAREN Statement  */
#line 408 "../klee/tools/klee/grammar.y"
                                                     {(yyval.var) = new_node({(yyvsp[-4].var), (yyvsp[-3].var), (yyvsp[-2].var), (yyvsp[-1].var), (yyvsp[0].var)});}
#line 2935 "../klee/tools/klee/grammar.c"
    break;

  case 121: /* IfStatement: IF L_PAREN Expression R_PAREN Statement ELSE Statement  */
#line 409 "../klee/tools/klee/grammar.y"
                                                          {(yyval.var) = new_node({(yyvsp[-6].var), (yyvsp[-5].var), (yyvsp[-4].var), (yyvsp[-3].var), (yyvsp[-2].var), (yyvsp[-1].var), (yyvsp[0].var)});}
#line 2941 "../klee/tools/klee/grammar.c"
    break;

  case 122: /* WhileStatement: WHILE L_PAREN Expression R_PAREN Statement  */
#line 412 "../klee/tools/klee/grammar.y"
                                                            {(yyval.var) = new_node({(yyvsp[-4].var), (yyvsp[-3].var), (yyvsp[-2].var), (yyvsp[-1].var), (yyvsp[0].var)});}
#line 2947 "../klee/tools/klee/grammar.c"
    break;

  case 123: /* SimpleStatement: Expression  */
#line 415 "../klee/tools/klee/grammar.y"
                            {(yyval.var) = (yyvsp[0].var);}
#line 2953 "../klee/tools/klee/grammar.c"
    break;

  case 124: /* SimpleStatement: VariableDefinition  */
#line 416 "../klee/tools/klee/grammar.y"
                     {(yyval.var) = (yyvsp[0].var);}
#line 2959 "../klee/tools/klee/grammar.c"
    break;

  case 125: /* ForStatement: FOR L_PAREN SimpleStatement SEMICOLON Expression SEMICOLON ExpressionStatement R_PAREN Statement  */
#line 420 "../klee/tools/klee/grammar.y"
{(yyval.var) = new_node({(yyvsp[-8].var), (yyvsp[-7].var), (yyvsp[-6].var), (yyvsp[-5].var), (yyvsp[-4].var), (yyvsp[-3].var), (yyvsp[-2].var), (yyvsp[-1].var), (yyvsp[0].var)});}
#line 2965 "../klee/tools/klee/grammar.c"
    break;

  case 126: /* DoWhileStatement: DO Statement WHILE L_PAREN Expression R_PAREN  */
#line 423 "../klee/tools/klee/grammar.y"
                                                                 {(yyval.var) = new_node({(yyvsp[-5].var), (yyvsp[-4].var), (yyvsp[-3].var), (yyvsp[-2].var), (yyvsp[-1].var), (yyvsp[0].var)});}
#line 2971 "../klee/tools/klee/grammar.c"
    break;

  case 127: /* EmitStatement: EMIT FunctionCall  */
#line 426 "../klee/tools/klee/grammar.y"
                                 {(yyval.var) = (yyvsp[0].var);}
#line 2977 "../klee/tools/klee/grammar.c"
    break;

  case 128: /* VariableDefinition: VariableDeclaration  */
#line 428 "../klee/tools/klee/grammar.y"
                                        {(yyval.var) = (yyvsp[0].var);}
#line 2983 "../klee/tools/klee/grammar.c"
    break;

  case 129: /* VariableDefinition: L_PAREN VariableDeclaration VarDec2 R_PAREN EQUAL Expression  */
#line 429 "../klee/tools/klee/grammar.y"
                                                               {(yyval.var) = new_node({(yyvsp[-5].var), (yyvsp[-4].var), (yyvsp[-3].var), (yyvsp[-2].var), (yyvsp[-1].var), (yyvsp[0].var)});}
#line 2989 "../klee/tools/klee/grammar.c"
    break;

  case 130: /* VariableDefinition: L_PAREN VarDec2 R_PAREN  */
#line 430 "../klee/tools/klee/grammar.y"
                           {(yyval.var) = new_node({(yyvsp[-2].var), (yyvsp[-1].var), (yyvsp[0].var)});}
#line 2995 "../klee/tools/klee/grammar.c"
    break;

  case 131: /* VarDec2: COMMA VariableDeclaration  */
#line 433 "../klee/tools/klee/grammar.y"
                                   {(yyval.var) = new_node({(yyvsp[-1].var), (yyvsp[0].var)});}
#line 3001 "../klee/tools/klee/grammar.c"
    break;

  case 132: /* VarDec2: %empty  */
#line 434 "../klee/tools/klee/grammar.y"
  { (yyval.var) = new_node(); }
#line 3007 "../klee/tools/klee/grammar.c"
    break;

  case 133: /* Expression: Expression Unary1  */
#line 438 "../klee/tools/klee/grammar.y"
                              {(yyval.var) = new_node({(yyvsp[-1].var), (yyvsp[0].var)});}
#line 3013 "../klee/tools/klee/grammar.c"
    break;

  case 134: /* Expression: NewExpression  */
#line 439 "../klee/tools/klee/grammar.y"
                {(yyval.var) = (yyvsp[0].var);}
#line 3019 "../klee/tools/klee/grammar.c"
    break;

  case 135: /* Expression: IndexAccess  */
#line 440 "../klee/tools/klee/grammar.y"
              {(yyval.var) = (yyvsp[0].var);}
#line 3025 "../klee/tools/klee/grammar.c"
    break;

  case 136: /* Expression: FunctionCall  */
#line 441 "../klee/tools/klee/grammar.y"
               {(yyval.var) = (yyvsp[0].var);}
#line 3031 "../klee/tools/klee/grammar.c"
    break;

  case 137: /* Expression: MemberAccess  */
#line 442 "../klee/tools/klee/grammar.y"
               {(yyval.var) = (yyvsp[0].var);}
#line 3037 "../klee/tools/klee/grammar.c"
    break;

  case 138: /* Expression: OPT_L ExpressionList OPT_R  */
#line 443 "../klee/tools/klee/grammar.y"
                             {(yyval.var) = new_node({new_node("{"), (yyvsp[-1].var), new_node("}")});}
#line 3043 "../klee/tools/klee/grammar.c"
    break;

  case 139: /* Expression: L_PAREN Expression R_PAREN  */
#line 444 "../klee/tools/klee/grammar.y"
                             {(yyval.var) = new_node({(yyvsp[-2].var), (yyvsp[-1].var), (yyvsp[0].var)});}
#line 3049 "../klee/tools/klee/grammar.c"
    break;

  case 140: /* Expression: Unary2 Expression  */
#line 445 "../klee/tools/klee/grammar.y"
                    {(yyval.var) = new_node({(yyvsp[-1].var), (yyvsp[0].var)});}
#line 3055 "../klee/tools/klee/grammar.c"
    break;

  case 141: /* Expression: Expression LOG_OP Expression  */
#line 446 "../klee/tools/klee/grammar.y"
                               {(yyval.var) = new_node({(yyvsp[-2].var), (yyvsp[-1].var), (yyvsp[0].var)});}
#line 3061 "../klee/tools/klee/grammar.c"
    break;

  case 142: /* Expression: Expression QUES_MARK Expression COLON Expression  */
#line 447 "../klee/tools/klee/grammar.y"
                                                   {(yyval.var) = new_node({(yyvsp[-4].var), (yyvsp[-3].var), (yyvsp[-2].var), (yyvsp[-1].var), (yyvsp[0].var)});}
#line 3067 "../klee/tools/klee/grammar.c"
    break;

  case 143: /* Expression: Expression Operator Expression  */
#line 448 "../klee/tools/klee/grammar.y"
                                 {(yyval.var) = new_node({(yyvsp[-2].var), (yyvsp[-1].var), (yyvsp[0].var)});}
#line 3073 "../klee/tools/klee/grammar.c"
    break;

  case 144: /* Expression: Expression REL_OP Expression  */
#line 449 "../klee/tools/klee/grammar.y"
                               {(yyval.var) = new_node({(yyvsp[-2].var), (yyvsp[-1].var), (yyvsp[0].var)});}
#line 3079 "../klee/tools/klee/grammar.c"
    break;

  case 145: /* Expression: PrimaryExpression  */
#line 450 "../klee/tools/klee/grammar.y"
                    {(yyval.var) = (yyvsp[0].var);}
#line 3085 "../klee/tools/klee/grammar.c"
    break;

  case 146: /* Operator: EQUAL  */
#line 453 "../klee/tools/klee/grammar.y"
                {(yyval.var) = (yyvsp[0].var);}
#line 3091 "../klee/tools/klee/grammar.c"
    break;

  case 147: /* Operator: PLUS  */
#line 454 "../klee/tools/klee/grammar.y"
       {(yyval.var) = (yyvsp[0].var);}
#line 3097 "../klee/tools/klee/grammar.c"
    break;

  case 148: /* Operator: MINUS  */
#line 455 "../klee/tools/klee/grammar.y"
        {(yyval.var) = (yyvsp[0].var);}
#line 3103 "../klee/tools/klee/grammar.c"
    break;

  case 149: /* Operator: DIVIDE  */
#line 456 "../klee/tools/klee/grammar.y"
         {(yyval.var) = (yyvsp[0].var);}
#line 3109 "../klee/tools/klee/grammar.c"
    break;

  case 150: /* Operator: STAR  */
#line 457 "../klee/tools/klee/grammar.y"
       {(yyval.var) = (yyvsp[0].var);}
#line 3115 "../klee/tools/klee/grammar.c"
    break;

  case 151: /* Operator: MOD  */
#line 458 "../klee/tools/klee/grammar.y"
      {(yyval.var) = (yyvsp[0].var);}
#line 3121 "../klee/tools/klee/grammar.c"
    break;

  case 152: /* Operator: EQUAL2  */
#line 459 "../klee/tools/klee/grammar.y"
         {(yyval.var) = (yyvsp[0].var);}
#line 3127 "../klee/tools/klee/grammar.c"
    break;

  case 153: /* Operator: CARET  */
#line 460 "../klee/tools/klee/grammar.y"
        {(yyval.var) = (yyvsp[0].var);}
#line 3133 "../klee/tools/klee/grammar.c"
    break;

  case 154: /* Unary1: PLUS2  */
#line 463 "../klee/tools/klee/grammar.y"
              {(yyval.var) = (yyvsp[0].var);}
#line 3139 "../klee/tools/klee/grammar.c"
    break;

  case 155: /* Unary1: MINUS2  */
#line 464 "../klee/tools/klee/grammar.y"
         {(yyval.var) = (yyvsp[0].var);}
#line 3145 "../klee/tools/klee/grammar.c"
    break;

  case 156: /* Unary2: PLUS2  */
#line 467 "../klee/tools/klee/grammar.y"
              {(yyval.var) = (yyvsp[0].var);}
#line 3151 "../klee/tools/klee/grammar.c"
    break;

  case 157: /* Unary2: PLUS  */
#line 468 "../klee/tools/klee/grammar.y"
       {(yyval.var) = (yyvsp[0].var);}
#line 3157 "../klee/tools/klee/grammar.c"
    break;

  case 158: /* Unary2: MINUS  */
#line 469 "../klee/tools/klee/grammar.y"
        {(yyval.var) = (yyvsp[0].var);}
#line 3163 "../klee/tools/klee/grammar.c"
    break;

  case 159: /* Unary2: TILDE  */
#line 470 "../klee/tools/klee/grammar.y"
        {(yyval.var) = (yyvsp[0].var);}
#line 3169 "../klee/tools/klee/grammar.c"
    break;

  case 160: /* Unary2: DELETE  */
#line 471 "../klee/tools/klee/grammar.y"
         {(yyval.var) = (yyvsp[0].var);}
#line 3175 "../klee/tools/klee/grammar.c"
    break;

  case 161: /* Unary2: MINUS2  */
#line 472 "../klee/tools/klee/grammar.y"
         {(yyval.var) = (yyvsp[0].var);}
#line 3181 "../klee/tools/klee/grammar.c"
    break;

  case 162: /* Unary2: NOT  */
#line 473 "../klee/tools/klee/grammar.y"
      {(yyval.var) = (yyvsp[0].var);}
#line 3187 "../klee/tools/klee/grammar.c"
    break;

  case 163: /* PrimaryExpression: BooleanLiteral  */
#line 476 "../klee/tools/klee/grammar.y"
                                  {(yyval.var) = (yyvsp[0].var);}
#line 3193 "../klee/tools/klee/grammar.c"
    break;

  case 164: /* PrimaryExpression: NumberLiteral  */
#line 477 "../klee/tools/klee/grammar.y"
                {(yyval.var) = (yyvsp[0].var);}
#line 3199 "../klee/tools/klee/grammar.c"
    break;

  case 165: /* PrimaryExpression: STRING_LITERAL  */
#line 478 "../klee/tools/klee/grammar.y"
                 {node* temp = changeQuotes((yyvsp[0].var)); (yyval.var) = temp;}
#line 3205 "../klee/tools/klee/grammar.c"
    break;

  case 166: /* PrimaryExpression: IDENTIFIER  */
#line 479 "../klee/tools/klee/grammar.y"
             {(yyval.var) = (yyvsp[0].var);}
#line 3211 "../klee/tools/klee/grammar.c"
    break;

  case 167: /* PrimaryExpression: ElementaryTypeName  */
#line 480 "../klee/tools/klee/grammar.y"
                     {(yyval.var) = (yyvsp[0].var);}
#line 3217 "../klee/tools/klee/grammar.c"
    break;

  case 168: /* ExpressionList: Expression  */
#line 483 "../klee/tools/klee/grammar.y"
                           {(yyval.var) = (yyvsp[0].var);}
#line 3223 "../klee/tools/klee/grammar.c"
    break;

  case 169: /* ExpressionList: Expression COMMA ExpressionList  */
#line 484 "../klee/tools/klee/grammar.y"
                                  {(yyval.var) = new_node({(yyvsp[-2].var), (yyvsp[-1].var), (yyvsp[0].var)});}
#line 3229 "../klee/tools/klee/grammar.c"
    break;

  case 170: /* NameValue: COMMA IDENTIFIER COLON Expression NameValue  */
#line 488 "../klee/tools/klee/grammar.y"
                                                       {(yyval.var) = new_node({(yyvsp[-4].var), (yyvsp[-1].var), (yyvsp[0].var)});}
#line 3235 "../klee/tools/klee/grammar.c"
    break;

  case 171: /* NameValue: %empty  */
#line 489 "../klee/tools/klee/grammar.y"
  { (yyval.var) = new_node(); }
#line 3241 "../klee/tools/klee/grammar.c"
    break;

  case 172: /* NameValueList: IDENTIFIER COLON Expression NameValue  */
#line 493 "../klee/tools/klee/grammar.y"
                                                     {(yyval.var) = new_node({(yyvsp[-1].var), (yyvsp[0].var)});}
#line 3247 "../klee/tools/klee/grammar.c"
    break;

  case 173: /* FunctionCallArguments: L_CURLY_B NameValueList R_CURLY_B  */
#line 497 "../klee/tools/klee/grammar.y"
                                                         {(yyval.var) = new_node({(yyvsp[-1].var)});}
#line 3253 "../klee/tools/klee/grammar.c"
    break;

  case 174: /* FunctionCallArguments: L_CURLY_B R_CURLY_B  */
#line 498 "../klee/tools/klee/grammar.y"
                      {(yyval.var) = new_node();}
#line 3259 "../klee/tools/klee/grammar.c"
    break;

  case 175: /* FunctionCallArguments: ExpressionList  */
#line 499 "../klee/tools/klee/grammar.y"
                 {(yyval.var) = (yyvsp[0].var);}
#line 3265 "../klee/tools/klee/grammar.c"
    break;

  case 176: /* FunctionCall: Expression L_PAREN FunctionCallArguments R_PAREN  */
#line 502 "../klee/tools/klee/grammar.y"
                                                               {(yyval.var) = new_node({(yyvsp[-3].var), (yyvsp[-2].var), (yyvsp[-1].var), (yyvsp[0].var)});}
#line 3271 "../klee/tools/klee/grammar.c"
    break;

  case 177: /* FunctionCall: Expression L_PAREN R_PAREN  */
#line 503 "../klee/tools/klee/grammar.y"
                              {(yyval.var) = new_node({(yyvsp[-2].var), (yyvsp[-1].var), (yyvsp[0].var)});}
#line 3277 "../klee/tools/klee/grammar.c"
    break;

  case 178: /* NewExpression: NEW TypeName  */
#line 506 "../klee/tools/klee/grammar.y"
                            {(yyval.var) = new_node({(yyvsp[-1].var), (yyvsp[0].var)});}
#line 3283 "../klee/tools/klee/grammar.c"
    break;

  case 179: /* MemberAccess: Expression DOT IDENTIFIER  */
#line 509 "../klee/tools/klee/grammar.y"
                                         {(yyval.var) = new_node({(yyvsp[-2].var), (yyvsp[-1].var), (yyvsp[0].var)});}
#line 3289 "../klee/tools/klee/grammar.c"
    break;

  case 180: /* MemberAccess: IDENTIFIER DOT IDENTIFIER  */
#line 510 "../klee/tools/klee/grammar.y"
                            {(yyval.var) = new_node({(yyvsp[-2].var), (yyvsp[-1].var), (yyvsp[0].var)});}
#line 3295 "../klee/tools/klee/grammar.c"
    break;

  case 181: /* MemberAccess: IDENTIFIER DOT IndexAccess  */
#line 511 "../klee/tools/klee/grammar.y"
                             {(yyval.var) = new_node({(yyvsp[-2].var), (yyvsp[-1].var), (yyvsp[0].var)});}
#line 3301 "../klee/tools/klee/grammar.c"
    break;

  case 182: /* MemberAccess: Expression DOT IndexAccess  */
#line 512 "../klee/tools/klee/grammar.y"
                              {(yyval.var) = new_node({(yyvsp[-2].var), (yyvsp[-1].var), (yyvsp[0].var)});}
#line 3307 "../klee/tools/klee/grammar.c"
    break;

  case 183: /* IndexAccess: IDENTIFIER OPT_L Expression OPT_R IndexAccess2  */
#line 515 "../klee/tools/klee/grammar.y"
                                                             {(yyval.var) = new_node({(yyvsp[-4].var), (yyvsp[-3].var), (yyvsp[-2].var), (yyvsp[-1].var), (yyvsp[0].var)});}
#line 3313 "../klee/tools/klee/grammar.c"
    break;

  case 184: /* IndexAccess: IDENTIFIER OPT_L OPT_R  */
#line 516 "../klee/tools/klee/grammar.y"
                          {(yyval.var) = new_node({(yyvsp[-2].var), (yyvsp[-1].var), (yyvsp[0].var)});}
#line 3319 "../klee/tools/klee/grammar.c"
    break;

  case 185: /* IndexAccess2: OPT_L Expression OPT_R  */
#line 518 "../klee/tools/klee/grammar.y"
                                     {(yyval.var) = new_node({(yyvsp[-2].var), (yyvsp[-1].var), (yyvsp[0].var)});}
#line 3325 "../klee/tools/klee/grammar.c"
    break;

  case 186: /* IndexAccess2: OPT_L OPT_R  */
#line 519 "../klee/tools/klee/grammar.y"
              {(yyval.var) = new_node({(yyvsp[-1].var), (yyvsp[0].var)});}
#line 3331 "../klee/tools/klee/grammar.c"
    break;

  case 187: /* IndexAccess2: %empty  */
#line 520 "../klee/tools/klee/grammar.y"
  { (yyval.var) = new_node();}
#line 3337 "../klee/tools/klee/grammar.c"
    break;

  case 188: /* BooleanLiteral: TRUE  */
#line 523 "../klee/tools/klee/grammar.y"
                     {(yyval.var) = (yyvsp[0].var);}
#line 3343 "../klee/tools/klee/grammar.c"
    break;

  case 189: /* BooleanLiteral: FALSE  */
#line 524 "../klee/tools/klee/grammar.y"
        {(yyval.var) = (yyvsp[0].var);}
#line 3349 "../klee/tools/klee/grammar.c"
    break;

  case 190: /* NumberLiteral: HEX_NUMBER  */
#line 527 "../klee/tools/klee/grammar.y"
                          {(yyval.var) = (yyvsp[0].var);}
#line 3355 "../klee/tools/klee/grammar.c"
    break;

  case 191: /* NumberLiteral: DECIMAL_NUMBER  */
#line 528 "../klee/tools/klee/grammar.y"
                 {(yyval.var) = (yyvsp[0].var);}
#line 3361 "../klee/tools/klee/grammar.c"
    break;

  case 192: /* NumberLiteral: HEX_NUMBER NumberUnit  */
#line 529 "../klee/tools/klee/grammar.y"
                        {(yyval.var) = new_node({(yyvsp[-1].var), (yyvsp[0].var)});}
#line 3367 "../klee/tools/klee/grammar.c"
    break;

  case 193: /* NumberLiteral: DECIMAL_NUMBER NumberUnit  */
#line 530 "../klee/tools/klee/grammar.y"
                             {(yyval.var) = new_node({(yyvsp[-1].var), (yyvsp[0].var)});}
#line 3373 "../klee/tools/klee/grammar.c"
    break;

  case 194: /* NumberUnit: WEI  */
#line 533 "../klee/tools/klee/grammar.y"
                {(yyval.var) = (yyvsp[0].var);}
#line 3379 "../klee/tools/klee/grammar.c"
    break;

  case 195: /* NumberUnit: SZABO  */
#line 534 "../klee/tools/klee/grammar.y"
        {(yyval.var) = (yyvsp[0].var);}
#line 3385 "../klee/tools/klee/grammar.c"
    break;

  case 196: /* NumberUnit: FINNEY  */
#line 535 "../klee/tools/klee/grammar.y"
         {(yyval.var) = (yyvsp[0].var);}
#line 3391 "../klee/tools/klee/grammar.c"
    break;

  case 197: /* NumberUnit: ETHER  */
#line 536 "../klee/tools/klee/grammar.y"
        {(yyval.var) = (yyvsp[0].var);}
#line 3397 "../klee/tools/klee/grammar.c"
    break;

  case 198: /* NumberUnit: SECONDS  */
#line 537 "../klee/tools/klee/grammar.y"
          {(yyval.var) = (yyvsp[0].var);}
#line 3403 "../klee/tools/klee/grammar.c"
    break;

  case 199: /* NumberUnit: MINUTES  */
#line 538 "../klee/tools/klee/grammar.y"
          {(yyval.var) = (yyvsp[0].var);}
#line 3409 "../klee/tools/klee/grammar.c"
    break;

  case 200: /* NumberUnit: HOURS  */
#line 539 "../klee/tools/klee/grammar.y"
        {(yyval.var) = (yyvsp[0].var);}
#line 3415 "../klee/tools/klee/grammar.c"
    break;

  case 201: /* NumberUnit: DAYS  */
#line 540 "../klee/tools/klee/grammar.y"
       {(yyval.var) = (yyvsp[0].var);}
#line 3421 "../klee/tools/klee/grammar.c"
    break;

  case 202: /* NumberUnit: WEEKS  */
#line 541 "../klee/tools/klee/grammar.y"
        {(yyval.var) = (yyvsp[0].var);}
#line 3427 "../klee/tools/klee/grammar.c"
    break;

  case 203: /* NumberUnit: YEARS  */
#line 542 "../klee/tools/klee/grammar.y"
        {(yyval.var) = (yyvsp[0].var);}
#line 3433 "../klee/tools/klee/grammar.c"
    break;

  case 204: /* ElementaryTypeName: ADDRESS  */
#line 546 "../klee/tools/klee/grammar.y"
                            {(yyval.var) = (yyvsp[0].var);}
#line 3439 "../klee/tools/klee/grammar.c"
    break;

  case 205: /* ElementaryTypeName: BOOL  */
#line 547 "../klee/tools/klee/grammar.y"
       {(yyval.var) = (yyvsp[0].var);}
#line 3445 "../klee/tools/klee/grammar.c"
    break;

  case 206: /* ElementaryTypeName: STRING  */
#line 548 "../klee/tools/klee/grammar.y"
         {(yyval.var) = (yyvsp[0].var);}
#line 3451 "../klee/tools/klee/grammar.c"
    break;

  case 207: /* ElementaryTypeName: INT  */
#line 549 "../klee/tools/klee/grammar.y"
      {(yyval.var) = (yyvsp[0].var);}
#line 3457 "../klee/tools/klee/grammar.c"
    break;

  case 208: /* ElementaryTypeName: UINT  */
#line 550 "../klee/tools/klee/grammar.y"
       {(yyval.var) = (yyvsp[0].var);}
#line 3463 "../klee/tools/klee/grammar.c"
    break;

  case 209: /* ElementaryTypeName: BYTE  */
#line 551 "../klee/tools/klee/grammar.y"
       {(yyval.var) = (yyvsp[0].var);}
#line 3469 "../klee/tools/klee/grammar.c"
    break;

  case 210: /* ElementaryTypeName: AUTO  */
#line 552 "../klee/tools/klee/grammar.y"
       {(yyval.var) = (yyvsp[0].var);}
#line 3475 "../klee/tools/klee/grammar.c"
    break;


#line 3479 "../klee/tools/klee/grammar.c"

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
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          goto yyexhaustedlab;
      }
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
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if 1
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 560 "../klee/tools/klee/grammar.y"


void writeContractContent(){
	std::string content = writeDecl.str() + writefile.str();
    file << content;
}

void yyerror(const char *msg)
{
    printf("\nError:\n");
    fprintf(stderr,"%s\n",msg);
}

int main(int argc, char* argv[])
{
    int x = yyparse();

    dfs(headNode);

    std::string content = writeDecl.str() + writefile.str();

    file << content;

    file.close();

    replaceKeywords(filename);

    file.open(filename, std::ios::app);
    addMainFunction(file);
    file.close();

    // rewriteContent(filename);

    contract.writeContract();
    writeContractNames();
    
    return x;
}
