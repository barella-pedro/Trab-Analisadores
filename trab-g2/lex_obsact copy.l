%{
#include "y.tab.h"    
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
%}

%%
"enviar"          { return ENVIAR; }
"dispositivo"     { return DISPOSITIVO; }
"enviar alerta"   { return ENVIAR_ALERTA; }
"para todos"      { return PARA_TODOS; }
"ligar"           { return LIGAR; }
"desligar"        { return DESLIGAR; }
"status"          { return STATUS; }
"set"             { return SET; }
"se"              { return SE; }
"entao"           { return ENTAO; }
"senao"           { return SENAO; }
"TRUE"            { return TRUE; }
"FALSE"           { return FALSE; }


//Regras para OPLOGIC:

">="             { return MAIOR_IGUAL; }
"<="             { return MENOR_IGUAL; }
"=="             { return IGUAL_LOGICO; }
"!="             { return DIFERENTE; }
"&&"             { return E_LOGICO; }
">"              { return MAIOR; } 
"<"              { return MENOR; }

//Regras de caracteres "atomicos" - Não sei se será útil.
":"              { return DOIS_PONTOS; }
","              { return VIRGULA; }
"{"              { return ABRE_CHAVES; }
"}"              { return FECHA_CHAVES; }
"("              { return ABRE_PARENTESES; }
")"              { return FECHA_PARENTESES; }
"."              { return PONTO_FINAL; }
"="              { return IGUAL; } /* Token para o '=' em 'set OBS = VAR' */

//Regras com regex:

\"[^"]*\"       { yylval.var = strdup(yytext); return MSG; }

[0-9]+          { yylval.var = strdup(yytext); return NUM; } //Está certo esse .var? POR ENQUANTO APENAS NUMEROS NATURAIS


//** PELO VISTO ISSO AQUI É UMA MÁ PRÁTICA, POIS ELE NUNCA ACEITARÁ OBSERVATION, POIS NAMEDEVICE É DEFINIDO PRIMEIRO;
/* [A-Za-z][A-Za-z0-9]*    { yylval.var = strdup(yytext); return NAMEDEVICE; }

[A-Za-z][A-Za-z]*    { yylval.var = strdup(yytext); return OBSERVATION; } */


/** Identificador genérico (para NAMEDEVICE e OBSERVATION) -> quem cuidará se é Ndevice ou Observ. é o yacc*/
/* DEVE VIR DEPOIS DAS PALAVRAS-CHAVE */
[a-zA-Z][a-zA-Z0-9_]* { yylval.var = strdup(yytext); return IDENTIFICADOR; }


[ \t\n]+              { /* Não faz nada quanto a espaços em branco, apenas ignora */ }

/* Regra de erro caso no arquivo do */
.                     { fprintf(stderr, "Erro LExico: Caractere inesperado '%s'\n", yytext); }


%%