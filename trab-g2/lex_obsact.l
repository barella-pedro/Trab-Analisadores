%{
#include "y.tab.h"    
%}

%%
"enviar"          { return enviar; }
"dispositivo"     { return dispositivo; }
"enviar alerta"   { return enviar_alerta; }
"para todos"      { return para_todos; }
"ligar"           { return ligar; }
"desligar"        { return desligar; }
"status"          { return status; }
"set"             { return set; }
"se"              { return se; }
"entao"          { return entao; }
"senao"           { return senao; }
"TRUE"            { return TRUE; }
"FALSE"           { return FALSE; }
//Regras para OPLOGIC:

">"              { return maior; } 
"<"              { return menor; }
">="             { return maior_igual; }
"<="             { return menor_igual; }
"=="             { return igual; }
"!="             { return diferente; }
"&&"             { return e_logico; }
""


//Regras com regex:

[0-9]+          { yylval.var = atoi(yytext); return num; } //Está certo esse .var?

[A-Za-z][A-Za-z0-9]*    { yylval.var = strdup(yytext); return NAMEDEVICE; }

[A-Za-z][A-Za-z]*    { yylval.var = strdup(yytext); return OBSERVATION; }

%%






















%%