%{
#include "sint_obsact.tab.h"    
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
%}

%%
"dispositivo"     { return DISPOSITIVO; }
"enviar alerta"   { return ENVIAR_ALERTA; }
"para todos"      { return PARA_TODOS; }
"ligar"           { return LIGAR; }
"desligar"        { return DESLIGAR; }
"set"             { return SET; }
"se"              { return SE; }
"entao"           { return ENTAO; }
"senao"           { return SENAO; }
"TRUE"            { return TRUE; }
"FALSE"           { return FALSE; }



">="             { return MAIOR_IGUAL; }
"<="             { return MENOR_IGUAL; }
"=="             { return IGUAL_LOGICO; }
"!="             { return DIFERENTE; }
"&&"             { return E_LOGICO; }
">"              { return MAIOR; } 
"<"              { return MENOR; }

":"              { return DOIS_PONTOS; }
","              { return VIRGULA; }
"{"              { return ABRE_CHAVES; }
"}"              { return FECHA_CHAVES; }
"("              { return ABRE_PARENTESES; }
")"              { return FECHA_PARENTESES; }
"."              { return PONTO_FINAL; }
"="              { return IGUAL; } 


\"[^"]*\"       {
    if (yyleng - 2 > 100) {
        fprintf(stderr, "Erro Léxico: Mensagem excede o limite de 100 caracteres.\n");
    } else {
        yylval.var = strdup(yytext);
        return MSG;
    }
}

[0-9]+          { yylval.var = strdup(yytext); return NUM; } 


[a-zA-Z][a-zA-Z0-9_]* {
    if (yyleng > 100) {
        fprintf(stderr, "Erro Léxico: Identificador '%.100s...' excede o limite de 100 caracteres.\n", yytext);

    } 
    else {
        yylval.var = strdup(yytext);
        return IDENTIFICADOR;
    }
}

[ \t\n]+              {  }


.                     { fprintf(stderr, "Erro LExico: Caractere inesperado '%s'\n", yytext); }


%%