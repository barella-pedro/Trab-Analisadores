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

#ifndef YY_YY_SINT_OBSACT_TAB_H_INCLUDED
# define YY_YY_SINT_OBSACT_TAB_H_INCLUDED
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
    NUM = 258,                     /* NUM  */
    MSG = 259,                     /* MSG  */
    IDENTIFICADOR = 260,           /* IDENTIFICADOR  */
    DISPOSITIVO = 261,             /* DISPOSITIVO  */
    ENVIAR_ALERTA = 262,           /* ENVIAR_ALERTA  */
    PARA_TODOS = 263,              /* PARA_TODOS  */
    LIGAR = 264,                   /* LIGAR  */
    DESLIGAR = 265,                /* DESLIGAR  */
    SET = 266,                     /* SET  */
    SE = 267,                      /* SE  */
    ENTAO = 268,                   /* ENTAO  */
    SENAO = 269,                   /* SENAO  */
    TRUE = 270,                    /* TRUE  */
    FALSE = 271,                   /* FALSE  */
    MAIOR_IGUAL = 272,             /* MAIOR_IGUAL  */
    MENOR_IGUAL = 273,             /* MENOR_IGUAL  */
    IGUAL_LOGICO = 274,            /* IGUAL_LOGICO  */
    DIFERENTE = 275,               /* DIFERENTE  */
    E_LOGICO = 276,                /* E_LOGICO  */
    MAIOR = 277,                   /* MAIOR  */
    MENOR = 278,                   /* MENOR  */
    DOIS_PONTOS = 279,             /* DOIS_PONTOS  */
    VIRGULA = 280,                 /* VIRGULA  */
    ABRE_CHAVES = 281,             /* ABRE_CHAVES  */
    FECHA_CHAVES = 282,            /* FECHA_CHAVES  */
    ABRE_PARENTESES = 283,         /* ABRE_PARENTESES  */
    FECHA_PARENTESES = 284,        /* FECHA_PARENTESES  */
    PONTO_FINAL = 285,             /* PONTO_FINAL  */
    IGUAL = 286                    /* IGUAL  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 106 "sint_obsact.y"

    char *var; /** Campos de yyval */

#line 99 "sint_obsact.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SINT_OBSACT_TAB_H_INCLUDED  */
