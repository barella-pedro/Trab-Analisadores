%{
    
    
    

%}

%union {
    char *var; /** Campos de yyval */
}

/** Esses tokens são referentes aos TOKENS mesmo, ou seja, Terminais da Linguagem*/
%token <var> NUM
%token <var> MSG
%token <var> IDENTIFICADOR
%token ENVIAR DISPOSITIVO ENVIAR_ALERTA PARA_TODOS LIGAR DESLIGAR STATUS
%token SET SE ENTAO SENAO TRUE FALSE
%token MAIOR_IGUAL MENOR_IGUAL IGUAL_LOGICO DIFERENTE E_LOGICO MAIOR MENOR
%token DOIS_PONTOS VIRGULA ABRE_CHAVES FECHA_CHAVES ABRE_PARENTESES FECHA_PARENTESES PONTO_FINAL IGUAL

%type <var> program devices device cmds namedevice observation cmd attrib var obsact act obs oplogic bool
%type <var> action params namedevices


%%

program:
        devices cmds;

devices:
        device devices
        | device;

device: 
        DISPOSITIVO DOIS_PONTOS ABRE_CHAVES IDENTIFICADOR FECHA_CHAVES
        {   }
        |
        DISPOSITIVO DOIS_PONTOS ABRE_CHAVES IDENTIFICADOR VIRGULA IDENTIFICADOR FECHA_CHAVES
%% 