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
#line 1 "sint_obsact.y"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

FILE *saida = NULL; /** Inicializando saida para utilizar mais tarde*/
void yyerror(const char *s);
int yylex();



/* ===================================================================== */
/* SEÇÃO 3: CÓDIGO C AUXILIAR                                            */
/* ===================================================================== */

/**
 * Função auxiliar para construir uma única chamada de função em C.
 * Ex: alerta_simples("SensorPorta", "Porta aberta")
 */
/**
 * Função auxiliar para construir o bloco de código para o broadcast.
 */
char* construir_bloco_broadcast(const char* dados_params, const char* lista_devices) {
    // --- Passo 1: Pré-calcular o tamanho total do buffer ---
    printf("Dados Params: %s\n", dados_params); // Debug: Imprimindo os parâmetros recebidos
    size_t tamanho_total = 0;
    char* copia_params = strdup(dados_params);
    char* copia_devices = strdup(lista_devices);

    char* nome_funcao = strtok(copia_params, ",");
    char* msg = strtok(NULL, ",");
    char* var_name = strtok(NULL, ","); // Pode ser NULL

    char* device_atual = strtok(copia_devices, ",");
    int num_devices = 0;
    while(device_atual != NULL) {
        while(isspace((unsigned char)*device_atual)) device_atual++;
        num_devices++;
        
        if (strcmp(nome_funcao, "alerta_simples") == 0) {
            tamanho_total += strlen(nome_funcao) + strlen(device_atual) + strlen(msg) + 10;
        } else {
            tamanho_total += strlen(nome_funcao) + strlen(device_atual) + strlen(msg) + strlen(var_name) + 12;
        }
        device_atual = strtok(NULL, ",");
    }
    free(copia_params);
    free(copia_devices);

    // --- Passo 2: Alocar o buffer do tamanho exato e construir a string ---
    char* bloco_de_codigo = malloc(tamanho_total);
    if (!bloco_de_codigo) return NULL; // Falha de alocação
    bloco_de_codigo[0] = '\0'; // Inicializa como string vazia

    // Reinicia o processo de tokenização
    copia_params = strdup(dados_params);
    copia_devices = strdup(lista_devices);
    nome_funcao = strtok(copia_params, ",");
    msg = strtok(NULL, ",");
    var_name = strtok(NULL, ",");

    device_atual = strtok(copia_devices, ",");
    int i = 0;
    while(device_atual != NULL) {
        while(isspace((unsigned char)*device_atual)) device_atual++;
        
        char linha_atual[512]; // Buffer temporário para cada linha
        if (strcmp(nome_funcao, "alerta_simples") == 0) {
            sprintf(linha_atual, "%s(%s, %s);", nome_funcao, device_atual, msg);
        } else {
            sprintf(linha_atual, "%s(%s, %s, %s);", nome_funcao, device_atual, msg, var_name);
        }
        strcat(bloco_de_codigo, linha_atual);
        if (i < num_devices - 1) {
            strcat(bloco_de_codigo, "\n"); // Adiciona quebra de linha entre os comandos
        }
        i++;
        device_atual = strtok(NULL, ",");
    }

    free(copia_params);
    free(copia_devices);
    return bloco_de_codigo;
}

bool contemNumeros(const char *str) {

    if (str == NULL) {
        return false;
    }
    
    for (int i = 0; str[i] != '\0'; i++) {
        if (isdigit(str[i])) {
            return true; // Encontrou um número, pode parar e retornar true.
        }
    }
    
    return false;
}



#line 176 "sint_obsact.tab.c"

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

#include "sint_obsact.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUM = 3,                        /* NUM  */
  YYSYMBOL_MSG = 4,                        /* MSG  */
  YYSYMBOL_IDENTIFICADOR = 5,              /* IDENTIFICADOR  */
  YYSYMBOL_DISPOSITIVO = 6,                /* DISPOSITIVO  */
  YYSYMBOL_ENVIAR_ALERTA = 7,              /* ENVIAR_ALERTA  */
  YYSYMBOL_PARA_TODOS = 8,                 /* PARA_TODOS  */
  YYSYMBOL_LIGAR = 9,                      /* LIGAR  */
  YYSYMBOL_DESLIGAR = 10,                  /* DESLIGAR  */
  YYSYMBOL_SET = 11,                       /* SET  */
  YYSYMBOL_SE = 12,                        /* SE  */
  YYSYMBOL_ENTAO = 13,                     /* ENTAO  */
  YYSYMBOL_SENAO = 14,                     /* SENAO  */
  YYSYMBOL_TRUE = 15,                      /* TRUE  */
  YYSYMBOL_FALSE = 16,                     /* FALSE  */
  YYSYMBOL_MAIOR_IGUAL = 17,               /* MAIOR_IGUAL  */
  YYSYMBOL_MENOR_IGUAL = 18,               /* MENOR_IGUAL  */
  YYSYMBOL_IGUAL_LOGICO = 19,              /* IGUAL_LOGICO  */
  YYSYMBOL_DIFERENTE = 20,                 /* DIFERENTE  */
  YYSYMBOL_E_LOGICO = 21,                  /* E_LOGICO  */
  YYSYMBOL_MAIOR = 22,                     /* MAIOR  */
  YYSYMBOL_MENOR = 23,                     /* MENOR  */
  YYSYMBOL_DOIS_PONTOS = 24,               /* DOIS_PONTOS  */
  YYSYMBOL_VIRGULA = 25,                   /* VIRGULA  */
  YYSYMBOL_ABRE_CHAVES = 26,               /* ABRE_CHAVES  */
  YYSYMBOL_FECHA_CHAVES = 27,              /* FECHA_CHAVES  */
  YYSYMBOL_ABRE_PARENTESES = 28,           /* ABRE_PARENTESES  */
  YYSYMBOL_FECHA_PARENTESES = 29,          /* FECHA_PARENTESES  */
  YYSYMBOL_PONTO_FINAL = 30,               /* PONTO_FINAL  */
  YYSYMBOL_IGUAL = 31,                     /* IGUAL  */
  YYSYMBOL_YYACCEPT = 32,                  /* $accept  */
  YYSYMBOL_program = 33,                   /* program  */
  YYSYMBOL_devices = 34,                   /* devices  */
  YYSYMBOL_device = 35,                    /* device  */
  YYSYMBOL_cmds = 36,                      /* cmds  */
  YYSYMBOL_cmd = 37,                       /* cmd  */
  YYSYMBOL_attrib = 38,                    /* attrib  */
  YYSYMBOL_obsact = 39,                    /* obsact  */
  YYSYMBOL_obs = 40,                       /* obs  */
  YYSYMBOL_oplogic = 41,                   /* oplogic  */
  YYSYMBOL_var = 42,                       /* var  */
  YYSYMBOL_bool = 43,                      /* bool  */
  YYSYMBOL_act = 44,                       /* act  */
  YYSYMBOL_params = 45,                    /* params  */
  YYSYMBOL_namedevices = 46,               /* namedevices  */
  YYSYMBOL_action = 47                     /* action  */
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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   60

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  16
/* YYNRULES -- Number of rules.  */
#define YYNRULES  37
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  66

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   286


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
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   128,   128,   132,   133,   137,   151,   170,   172,   177,
     179,   181,   191,   199,   209,   222,   239,   256,   261,   266,
     271,   276,   281,   288,   290,   294,   299,   307,   317,   329,
     343,   348,   356,   364,   378,   383,   395,   400
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
  "\"end of file\"", "error", "\"invalid token\"", "NUM", "MSG",
  "IDENTIFICADOR", "DISPOSITIVO", "ENVIAR_ALERTA", "PARA_TODOS", "LIGAR",
  "DESLIGAR", "SET", "SE", "ENTAO", "SENAO", "TRUE", "FALSE",
  "MAIOR_IGUAL", "MENOR_IGUAL", "IGUAL_LOGICO", "DIFERENTE", "E_LOGICO",
  "MAIOR", "MENOR", "DOIS_PONTOS", "VIRGULA", "ABRE_CHAVES",
  "FECHA_CHAVES", "ABRE_PARENTESES", "FECHA_PARENTESES", "PONTO_FINAL",
  "IGUAL", "$accept", "program", "devices", "device", "cmds", "cmd",
  "attrib", "obsact", "obs", "oplogic", "var", "bool", "act", "params",
  "namedevices", "action", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-40)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-31)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       6,    -6,    23,    19,     6,     1,   -40,    -4,   -40,   -40,
      28,    32,   -40,     9,   -40,   -40,   -40,    35,   -40,    36,
     -40,    38,    14,    12,    -9,    31,    -5,   -40,    11,    -8,
     -40,    21,     0,   -40,   -40,   -40,   -40,   -40,   -40,     0,
      25,   -40,    41,   -40,    42,   -40,    43,   -40,   -40,   -40,
     -40,   -40,    29,    37,    22,    24,    27,   -40,    32,    25,
     -40,   -40,    43,   -40,   -40,   -40
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,    30,     4,     0,     1,     0,    36,    37,
       0,     0,     2,     0,     9,    10,    11,     0,     3,     0,
      31,     0,     0,     0,     0,     0,     8,    27,     0,     0,
      28,     0,     0,    19,    20,    17,    18,    21,    22,     0,
      30,     7,     0,     5,     0,    32,     0,    23,    25,    26,
      12,    24,    15,    13,     0,     0,    34,    29,     0,    30,
       6,    33,     0,    16,    14,    35
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -40,   -40,    50,   -40,    30,   -40,   -40,   -40,    -3,   -40,
      18,   -40,   -39,   -40,    -2,   -40
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     3,     4,    12,    13,    14,    15,    25,    39,
      50,    51,    16,    22,    57,    17
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      20,    53,     7,    47,     8,     9,    10,    11,    33,    34,
      35,    36,     1,    37,    38,    48,    49,    44,     5,    30,
      64,    45,    31,     6,    21,   -30,     7,    19,     8,     9,
      10,    11,     7,    23,     8,     9,    42,    24,    43,    26,
      27,    28,    29,    32,    40,    46,    54,    55,    56,    60,
      58,    59,    62,    61,    18,    63,    41,    52,     0,     0,
      65
};

static const yytype_int8 yycheck[] =
{
       4,    40,     7,     3,     9,    10,    11,    12,    17,    18,
      19,    20,     6,    22,    23,    15,    16,    25,    24,     5,
      59,    29,     8,     0,    28,    30,     7,    26,     9,    10,
      11,    12,     7,     5,     9,    10,    25,     5,    27,    30,
       5,     5,     4,    31,    13,    24,     5,     5,     5,    27,
      21,    14,    25,    29,     4,    58,    26,    39,    -1,    -1,
      62
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,    33,    34,    35,    24,     0,     7,     9,    10,
      11,    12,    36,    37,    38,    39,    44,    47,    34,    26,
       4,    28,    45,     5,     5,    40,    30,     5,     5,     4,
       5,     8,    31,    17,    18,    19,    20,    22,    23,    41,
      13,    36,    25,    27,    25,    29,    24,     3,    15,    16,
      42,    43,    42,    44,     5,     5,     5,    46,    21,    14,
      27,    29,    25,    40,    44,    46
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    32,    33,    34,    34,    35,    35,    36,    36,    37,
      37,    37,    38,    39,    39,    40,    40,    41,    41,    41,
      41,    41,    41,    42,    42,    43,    43,    44,    44,    44,
      44,    45,    45,    45,    46,    46,    47,    47
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     1,     5,     7,     3,     2,     1,
       1,     1,     4,     4,     6,     3,     5,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     3,     5,
       0,     1,     3,     5,     1,     3,     1,     1
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
  case 5: /* device: DISPOSITIVO DOIS_PONTOS ABRE_CHAVES IDENTIFICADOR FECHA_CHAVES  */
#line 138 "sint_obsact.y"
        { 
            //Quero verificar se o nome do dispositivo possui numeros ou não

            if (contemNumeros((yyvsp[-1].var))) {
                fprintf(stderr, "Erro: O nome do dispositivo '%s' não pode conter números.\n", (yyvsp[-1].var));
                exit(EXIT_FAILURE); // Encerra o programa com erro
            }
            fprintf(saida, "\tchar *%s = \"%s\";\n", (yyvsp[-1].var), (yyvsp[-1].var));
            fprintf(saida, "\tint %s_status = 0;\n", (yyvsp[-1].var)); /* Cria uma variável de status para o dispositivo que comeca desligada */
             /* Liberando a memória alocada para o nome do dispositivo */
             free((yyvsp[-1].var));
        }
#line 1258 "sint_obsact.tab.c"
    break;

  case 6: /* device: DISPOSITIVO DOIS_PONTOS ABRE_CHAVES IDENTIFICADOR VIRGULA IDENTIFICADOR FECHA_CHAVES  */
#line 153 "sint_obsact.y"
        {
            if (contemNumeros((yyvsp[-3].var))) {
                fprintf(stderr, "Erro: O nome do dispositivo '%s' não pode conter números.\n", (yyvsp[-3].var));
                exit(EXIT_FAILURE); // Encerra o programa com erro
            }
            
            fprintf(saida, "\tchar *%s = \"%s\";\n", (yyvsp[-3].var), (yyvsp[-3].var));
            fprintf(saida, "\tint %s_status = 0;\n", (yyvsp[-3].var));
            fprintf(saida, "\tint %s = 0;\n", (yyvsp[-1].var));
            free((yyvsp[-1].var)); // Liberando a memória alocada para o sensor
            free((yyvsp[-3].var)); // Liberando a memória alocada para o nome do dispositivo
            
        }
#line 1276 "sint_obsact.tab.c"
    break;

  case 11: /* cmd: act  */
#line 182 "sint_obsact.y"
        {
            // Ação simples, apenas imprime a ação
            fprintf(saida, "\t%s\n", (yyvsp[0].var));
            free((yyvsp[0].var)); // Liberando a memória alocada para a ação
        }
#line 1286 "sint_obsact.tab.c"
    break;

  case 12: /* attrib: SET IDENTIFICADOR IGUAL var  */
#line 192 "sint_obsact.y"
        {
            fprintf(saida, "\t%s = %s;\n", (yyvsp[-2].var), (yyvsp[0].var));
            free((yyvsp[-2].var));
            free((yyvsp[0].var));
        }
#line 1296 "sint_obsact.tab.c"
    break;

  case 13: /* obsact: SE obs ENTAO act  */
#line 200 "sint_obsact.y"
        {
            fprintf(saida, "\tif (%s) {\n", (yyvsp[-2].var));
            fprintf(saida, "\t\t%s \n", (yyvsp[0].var));
            fprintf(saida, "\t}\n");
            free((yyvsp[-2].var)); // Liberando a memória alocada para a observação
            free((yyvsp[0].var)); // Liberando a memória alocada para a ação

        }
#line 1309 "sint_obsact.tab.c"
    break;

  case 14: /* obsact: SE obs ENTAO act SENAO act  */
#line 210 "sint_obsact.y"
        {
            fprintf(saida, "\tif (%s) {\n", (yyvsp[-4].var));
            fprintf(saida, "\t\t%s\n", (yyvsp[-2].var));
            fprintf(saida, "\t} else {\n");
            fprintf(saida, "\t\t%s\n", (yyvsp[0].var));
            fprintf(saida, "\t}\n");
            free((yyvsp[-4].var)); // Liberando a memória alocada para a observação
            free((yyvsp[-2].var)); // Liberando a memória alocada para a ação do if
            free((yyvsp[0].var)); // Liberando a memória alocada para a ação do else
        }
#line 1324 "sint_obsact.tab.c"
    break;

  case 15: /* obs: IDENTIFICADOR oplogic var  */
#line 223 "sint_obsact.y"
        {
            // Calcula o tamanho necessário para a nova string: "var1 op var2"
            int len = strlen((yyvsp[-2].var)) + strlen((yyvsp[-1].var)) + strlen((yyvsp[0].var)) + 3; // +2 para espaços, +1 para '\0'
            (yyval.var) = malloc(len);
            if ((yyval.var)) { // Sempre verifique se o malloc funcionou
                sprintf((yyval.var), "%s %s %s", (yyvsp[-2].var), (yyvsp[-1].var), (yyvsp[0].var));
            }
            
            free((yyvsp[-2].var)); 
            free((yyvsp[-1].var));
            free((yyvsp[0].var));
            
            
            
        }
#line 1344 "sint_obsact.tab.c"
    break;

  case 16: /* obs: IDENTIFICADOR oplogic var E_LOGICO obs  */
#line 240 "sint_obsact.y"
        {
            // Calcula o tamanho para "var1 op var2 && condicao_anterior"
            int len = strlen((yyvsp[-4].var)) + strlen((yyvsp[-3].var)) + strlen((yyvsp[-2].var)) + strlen(" && ") + strlen((yyvsp[0].var)) + 1;
            (yyval.var) = malloc(len);
            if ((yyval.var)) {
                sprintf((yyval.var), "%s %s %s && %s", (yyvsp[-4].var), (yyvsp[-3].var), (yyvsp[-2].var), (yyvsp[0].var));
            }

            // Libera a memória das partes
            free((yyvsp[-4].var));
            free((yyvsp[-3].var));
            free((yyvsp[-2].var));
            free((yyvsp[0].var));
        }
#line 1363 "sint_obsact.tab.c"
    break;

  case 17: /* oplogic: IGUAL_LOGICO  */
#line 257 "sint_obsact.y"
        { 
            (yyval.var) = strdup("=="); /* Representando IGUAL_LOGICO como == */
        }
#line 1371 "sint_obsact.tab.c"
    break;

  case 18: /* oplogic: DIFERENTE  */
#line 262 "sint_obsact.y"
        { 
            (yyval.var) = strdup("!="); /* Representando DIFERENTE como != */
        }
#line 1379 "sint_obsact.tab.c"
    break;

  case 19: /* oplogic: MAIOR_IGUAL  */
#line 267 "sint_obsact.y"
        { 
            (yyval.var) = strdup(">="); /* Representando MAIOR_IGUAL como >= */
        }
#line 1387 "sint_obsact.tab.c"
    break;

  case 20: /* oplogic: MENOR_IGUAL  */
#line 272 "sint_obsact.y"
        { 
            (yyval.var) = strdup("<="); /* Representando MENOR_IGUAL como <= */
        }
#line 1395 "sint_obsact.tab.c"
    break;

  case 21: /* oplogic: MAIOR  */
#line 277 "sint_obsact.y"
        { 
            (yyval.var) = strdup(">"); /* Representando MAIOR como > */
        }
#line 1403 "sint_obsact.tab.c"
    break;

  case 22: /* oplogic: MENOR  */
#line 282 "sint_obsact.y"
        { 
            (yyval.var) = strdup("<"); /* Representando MENOR como < */
        }
#line 1411 "sint_obsact.tab.c"
    break;

  case 25: /* bool: TRUE  */
#line 295 "sint_obsact.y"
        { 
            (yyval.var) = strdup("1"); /* Representando TRUE como 1 */
        }
#line 1419 "sint_obsact.tab.c"
    break;

  case 26: /* bool: FALSE  */
#line 300 "sint_obsact.y"
        { 
            (yyval.var) = strdup("0"); /* Representando FALSE como 0 */
        }
#line 1427 "sint_obsact.tab.c"
    break;

  case 27: /* act: action IDENTIFICADOR  */
#line 308 "sint_obsact.y"
    {
        char* resultado = malloc(strlen((yyvsp[-1].var)) + strlen((yyvsp[0].var)) + 5);
        sprintf(resultado, "%s(\"%s\", *%s_status );", (yyvsp[-1].var), (yyvsp[0].var), (yyvsp[0].var));
        (yyval.var) = resultado;
        free((yyvsp[0].var));
        free((yyvsp[-1].var));
    }
#line 1439 "sint_obsact.tab.c"
    break;

  case 28: /* act: ENVIAR_ALERTA params IDENTIFICADOR  */
#line 318 "sint_obsact.y"
    {
        // Delega a construção da string para a função auxiliar
        
        (yyval.var) = construir_bloco_broadcast((yyvsp[-1].var), (yyvsp[0].var));

        // Libera a memória usada pelos tokens
        free((yyvsp[-1].var));
        free((yyvsp[0].var));
    }
#line 1453 "sint_obsact.tab.c"
    break;

  case 29: /* act: ENVIAR_ALERTA params PARA_TODOS DOIS_PONTOS namedevices  */
#line 330 "sint_obsact.y"
    {
        // Delega a construção do bloco de código para a função auxiliar
        printf("OI\n");
        printf("%s\n", (yyvsp[-3].var)); // Debug: Imprimindo os parâmetros recebidos
        printf("%s\n", (yyvsp[0].var)); // Debug: Imprimindo os dispositivos recebidos
        (yyval.var) = construir_bloco_broadcast((yyvsp[-3].var), (yyvsp[0].var));
        printf("%s\n", (yyval.var)); // Debug: Imprimindo o bloco de código construído
        
        // Libera a memória usada pelos tokens
        free((yyvsp[-3].var));
        free((yyvsp[0].var));
    }
#line 1470 "sint_obsact.tab.c"
    break;

  case 30: /* act: %empty  */
#line 343 "sint_obsact.y"
           {
        (yyval.var) = strdup(""); /* Representando ação vazia como string vazia */
    }
#line 1478 "sint_obsact.tab.c"
    break;

  case 31: /* params: MSG  */
#line 349 "sint_obsact.y"
        {
            (yyval.var) = malloc(strlen((yyvsp[0].var)) + 3 + strlen("alerta_simples"));
            sprintf((yyval.var), "alerta_simples, %s", (yyvsp[0].var));
            printf("%s\n", (yyval.var)); // Debug: Imprimindo a string formatada
            free((yyvsp[0].var));
        }
#line 1489 "sint_obsact.tab.c"
    break;

  case 32: /* params: ABRE_PARENTESES MSG FECHA_PARENTESES  */
#line 357 "sint_obsact.y"
        {
            (yyval.var) = malloc(strlen((yyvsp[-1].var)) + 3 + strlen("alerta_simples"));
            sprintf((yyval.var), "alerta_simples, %s", (yyvsp[-1].var)); /* Representando MSG entre parênteses como mensagem */
            printf("%s\n", (yyval.var)); // Debug: Imprimindo a string formatada
            free((yyvsp[-1].var));
        }
#line 1500 "sint_obsact.tab.c"
    break;

  case 33: /* params: ABRE_PARENTESES MSG VIRGULA IDENTIFICADOR FECHA_PARENTESES  */
#line 365 "sint_obsact.y"
        {
            (yyval.var) = malloc(strlen((yyvsp[-3].var)) + strlen((yyvsp[-1].var)) + 3 + strlen("alerta_comp"));
            sprintf((yyval.var), "alerta_comp, %s, %s", (yyvsp[-3].var), (yyvsp[-1].var)); /* Concatenando mensagem e variável 

            */
             /* Liberando a memória alocada para a mensagem */
             /* Liberando a memória alocada para a variável */
             printf("%s\n", (yyval.var)); // Debug: Imprimindo a string formatada
            free((yyvsp[-3].var));
            free((yyvsp[-1].var));
        }
#line 1516 "sint_obsact.tab.c"
    break;

  case 34: /* namedevices: IDENTIFICADOR  */
#line 379 "sint_obsact.y"
        {
            (yyval.var) = strdup((yyvsp[0].var)); /* Representando IDENTIFICADOR como nome do dispositivo */
        }
#line 1524 "sint_obsact.tab.c"
    break;

  case 35: /* namedevices: IDENTIFICADOR VIRGULA namedevices  */
#line 384 "sint_obsact.y"
        {
            (yyval.var) = malloc(strlen((yyvsp[-2].var)) + strlen((yyvsp[0].var)) + 2);
            sprintf((yyval.var), "%s, %s", (yyvsp[-2].var), (yyvsp[0].var));
             /* Liberando a memória alocada para o nome do dispositivo */
             /* Liberando a memória alocada para os nomes dos dispositivos */
            free((yyvsp[-2].var));
            free((yyvsp[0].var));
        }
#line 1537 "sint_obsact.tab.c"
    break;

  case 36: /* action: LIGAR  */
#line 396 "sint_obsact.y"
        {
            (yyval.var) = strdup("ligar"); /* Representando LIGAR como ligar */
        }
#line 1545 "sint_obsact.tab.c"
    break;

  case 37: /* action: DESLIGAR  */
#line 401 "sint_obsact.y"
        {
            (yyval.var) = strdup("desligar"); /* Representando DESLIGAR como desligar 8*/

        }
#line 1554 "sint_obsact.tab.c"
    break;


#line 1558 "sint_obsact.tab.c"

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

#line 410 "sint_obsact.y"


void yyerror(const char *s) {
    fprintf(stderr, "Erro de Sintaxe: %s\n", s);
}

int main() {
    saida = fopen("saidas/saida_.c", "w");
    if (!saida) {
        perror("Erro ao criar arquivo traduzido!");
        return 1;
    }

    fprintf(saida, "#include <stdio.h>\n\n\n");
    

    // Correção: trocar "%s" por "%%s" para que a string literal "%s" seja escrita no arquivo.
    fprintf(saida, "\tvoid ligar(char* namedevice, int *status_device)\n\t{\n\t\tif (*status_device == 1) {\n\t\t\tprintf(\"O Dispositivo ja esta ligado!\\n\");\n\t\t} else {\n\t\t\t*status_device = 1;\n\t\t\tprintf(\"%%s ligado!\\n\", namedevice);\n\t\t}\n\t}\n\n");

    fprintf(saida, "\tvoid desligar(char* namedevice, int* status_device)\n\t{\n\t\tif (*status_device == 0) {\n\t\t\tprintf(\"O Dispositivo ja esta desligado!\\n\");\n\t\t} else {\n\t\t\t*status_device = 0;\n\t\t\tprintf(\"%%s desligado!\\n\", namedevice);\n\t\t}\n\t}\n\n");


    fprintf(saida, "\tvoid alerta_simples(char* namedevice, char* msg)\n\t{\n\t\tprintf(\"%%s recebeu o alerta:\\n\", namedevice);\n\t\tprintf(\"%%s\\n\", msg);\n\t}\n\n");

    // Nota: Você tem duas funções com o mesmo nome "alerta", o que causaria um erro de compilação.
    // Renomeei a segunda para "alerta2" como exemplo.
    fprintf(saida, "\tvoid alerta_comp(char* namedevice, char* msg, char* var)\n\t{\n\t\tprintf(\"%%s recebeu o alerta:\\n\", namedevice);\n\t\tprintf(\"%%s %%s\\n\", msg, var);\n\t}\n\n");

    fprintf(saida, "\tvoid verifica_status(char* namedevice, int *status_device)\n\t{\n\t\tif (*status_device == 1) {\n\t\t\tprintf(\"%%s está ativo!\\n\", namedevice);\n\t\t} else {\n\t\t\tprintf(\"%%s está inativo!\\n\", namedevice);\n\t\t}\n\t}\n\n");

    fprintf(saida, "int main() {\n\n");
    yyparse(); //Aqui a mágica acontece e o programa é traduzido.
    fprintf(saida, "\nreturn 0;\n}\n");
    fclose(saida);
    return 0;
}
