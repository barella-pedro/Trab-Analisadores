%{
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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
char* construir_chamada_alerta(const char* dados_params, const char* device_nome) {
    char* copia_params = strdup(dados_params);
    char* nome_funcao = strtok(copia_params, ",");
    char* resultado = NULL;

    if (strcmp(nome_funcao, "alerta_simples") == 0) {
        char* msg = strtok(NULL, ",");
        // Aloca o tamanho exato necessário
        resultado = malloc(strlen(nome_funcao) + strlen(device_nome) + strlen(msg) + 7);
        sprintf(resultado, "%s(%s, %s);", nome_funcao, device_nome, msg);

    } else if (strcmp(nome_funcao, "alerta_composto") == 0) {
        char* msg = strtok(NULL, ",");
        char* var_name = strtok(NULL, ",");
        // Aloca o tamanho exato
        resultado = malloc(strlen(nome_funcao) + strlen(device_nome) + strlen(msg) + strlen(var_name) + 10);
        sprintf(resultado, "%s(%s, %s, %s);", nome_funcao, device_nome, msg, var_name);
    }
    
    free(copia_params);
    return resultado;
}

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


%}

%union {
    char *var; /** Campos de yyval */
}

/** Esses tokens são referentes aos TOKENS mesmo, ou seja, Terminais da Linguagem*/
%token <var> NUM
%token <var> MSG
%token <var> IDENTIFICADOR
%token DISPOSITIVO ENVIAR_ALERTA PARA_TODOS LIGAR DESLIGAR
%token SET SE ENTAO SENAO TRUE FALSE
%token MAIOR_IGUAL MENOR_IGUAL IGUAL_LOGICO DIFERENTE E_LOGICO MAIOR MENOR
%token DOIS_PONTOS VIRGULA ABRE_CHAVES FECHA_CHAVES ABRE_PARENTESES FECHA_PARENTESES PONTO_FINAL IGUAL

/** Esses types são referentes aos NÃO TERMINAIS da gramática*/
%type <var> program devices device cmds cmd attrib var obsact act obs oplogic bool 
%type <var> action params namedevices



%%

program:
        devices cmds
        ;

devices:
        device devices
        | device
        ;

device: 
        DISPOSITIVO DOIS_PONTOS ABRE_CHAVES IDENTIFICADOR FECHA_CHAVES
        { 
            fprintf(saida, "\tchar *%s = \"%s\";\n", $4, $4);
             /* Liberando a memória alocada para o nome do dispositivo */
        } 
        |
        DISPOSITIVO DOIS_PONTOS ABRE_CHAVES IDENTIFICADOR VIRGULA IDENTIFICADOR FECHA_CHAVES
        /*TODO Mudar IDENTIFICADOR para dois não terminais específicos */
        {
            fprintf(saida, "\tchar *%s = \"%s\";\n", $4, $4);
            fprintf(saida, "\tint %s;\n", $6);
            free($6); // Liberando a memória alocada para o sensor
            free($4); // Liberando a memória alocada para o nome do dispositivo
            
        }
        ;


cmds:
        cmd PONTO_FINAL cmds
        |
        cmd PONTO_FINAL
    
        ;

cmd:
        attrib
        |
        obsact
        |
        act
        {
            // Ação simples, apenas imprime a ação
            fprintf(saida, "\t%s\n", $1);
            free($1); // Liberando a memória alocada para a ação
        }
        ;


attrib: 
        SET IDENTIFICADOR IGUAL var
        {
            fprintf(saida, "\t%s = %s;\n", $2, $4);
             /* Liberando a memória alocada para o nome do atributo */
             /* Liberando a memória alocada para o número */
        }
        ;
obsact:
        SE obs ENTAO act
        {
            fprintf(saida, "\tif (%s) {\n", $2);
            fprintf(saida, "\t\t%s \n", $4);
            fprintf(saida, "\t}\n");
             /* Liberando a memória alocada para a observação */
             /* Liberando a memória alocada para a ação */

        }
        |
        SE obs ENTAO act SENAO act
        {
            fprintf(saida, "\tif (%s) {\n", $2);
            fprintf(saida, "\t\t%s\n", $4);
            fprintf(saida, "\t} else {\n");
            fprintf(saida, "\t\t%s\n", $6);
            fprintf(saida, "\t}\n");
             /* Liberando a memória alocada para a observação */
             /* Liberando a memória alocada para a ação */
             /* Liberando a memória alocada para a ação */
        }
        ;
obs:
        IDENTIFICADOR oplogic var
        {
            // Calcula o tamanho necessário para a nova string: "var1 op var2"
            int len = strlen($1) + strlen($2) + strlen($3) + 3; // +2 para espaços, +1 para '\0'
            $$ = malloc(len);
            if ($$) { // Sempre verifique se o malloc funcionou
                sprintf($$, "%s %s %s", $1, $2, $3);
            }
            
            // Libera a memória das partes que foram usadas
            
            
            
        }
        |
        IDENTIFICADOR oplogic var E_LOGICO obs
        {
            // Calcula o tamanho para "var1 op var2 && condicao_anterior"
            int len = strlen($1) + strlen($2) + strlen($3) + strlen(" && ") + strlen($5) + 1;
            $$ = malloc(len);
            if ($$) {
                sprintf($$, "%s %s %s && %s", $1, $2, $3, $5);
            }

            // Libera a memória das partes
            
            
            
             // Libera a string da condição anterior, que foi copiada
        }
        ;
oplogic:
        IGUAL_LOGICO
        { 
            $$ = strdup("=="); /* Representando IGUAL_LOGICO como == */
        }
        |
        DIFERENTE
        { 
            $$ = strdup("!="); /* Representando DIFERENTE como != */
        }
        |
        MAIOR_IGUAL
        { 
            $$ = strdup(">="); /* Representando MAIOR_IGUAL como >= */
        }
        |
        MENOR_IGUAL
        { 
            $$ = strdup("<="); /* Representando MENOR_IGUAL como <= */
        }
        |
        MAIOR
        { 
            $$ = strdup(">"); /* Representando MAIOR como > */
        }
        |
        MENOR
        { 
            $$ = strdup("<"); /* Representando MENOR como < */
        }
        ;

var: 
        NUM
        |
        bool
        ;

bool:
        TRUE
        { 
            $$ = strdup("1"); /* Representando TRUE como 1 */
        }
        |
        FALSE
        { 
            $$ = strdup("0"); /* Representando FALSE como 0 */
        }
        ;

act:
    /* Alternativa 1: action IDENTIFICADOR */
    action IDENTIFICADOR
    {
        char* resultado = malloc(strlen($1) + strlen($2) + 5);
        sprintf(resultado, "%s(\"%s\");", $1, $2);
        $$ = resultado;
        free($2);
    }
    |
    /* Alternativa 2: ENVIAR_ALERTA params IDENTIFICADOR */
    ENVIAR_ALERTA params IDENTIFICADOR
    {
        // Delega a construção da string para a função auxiliar
        
        $$ = construir_bloco_broadcast($2, $3);

        // Libera a memória usada pelos tokens
        free($2);
        free($3);
    }
    |
    /* Alternativa 3: ENVIAR_ALERTA params PARA_TODOS ... (Broadcast) */
    ENVIAR_ALERTA params PARA_TODOS DOIS_PONTOS namedevices
    {
        // Delega a construção do bloco de código para a função auxiliar
        printf("OI\n");
        printf("%s\n", $2); // Debug: Imprimindo os parâmetros recebidos
        printf("%s\n", $5); // Debug: Imprimindo os dispositivos recebidos
        $$ = construir_bloco_broadcast($2, $5);
        printf("%s\n", $$); // Debug: Imprimindo o bloco de código construído
        
        // Libera a memória usada pelos tokens
        free($2);
        free($5);
    }
    |
    %empty {
        $$ = strdup(""); /* Representando ação vazia como string vazia */
    }
    ;
params: 
        MSG
        {
            $$ = malloc(strlen($1) + 3 + strlen("alerta_simples"));
            sprintf($$, "alerta_simples, %s", $1);
            printf("%s\n", $$); // Debug: Imprimindo a string formatada

        }
        |
        ABRE_PARENTESES MSG FECHA_PARENTESES
        {
            $$ = malloc(strlen($2) + 3 + strlen("alerta_simples"));
            sprintf($$, "alerta_simples, %s", $2); /* Representando MSG entre parênteses como mensagem */
             printf("%s\n", $$); // Debug: Imprimindo a string formatada

        }
        |
        ABRE_PARENTESES MSG VIRGULA IDENTIFICADOR FECHA_PARENTESES
        {
            $$ = malloc(strlen($2) + strlen($4) + 3 + strlen("alerta_comp"));
            sprintf($$, "alerta_comp, %s, %s", $2, $4); /* Concatenando mensagem e variável 

            */
             /* Liberando a memória alocada para a mensagem */
             /* Liberando a memória alocada para a variável */
             printf("%s\n", $$); // Debug: Imprimindo a string formatada
        }
        ;
namedevices:    
        IDENTIFICADOR
        {
            $$ = strdup($1); /* Representando IDENTIFICADOR como nome do dispositivo */
        }
        |
        IDENTIFICADOR VIRGULA namedevices
        {
            $$ = malloc(strlen($1) + strlen($3) + 2);
            sprintf($$, "%s, %s", $1, $3);
             /* Liberando a memória alocada para o nome do dispositivo */
             /* Liberando a memória alocada para os nomes dos dispositivos */
        }
        ;

action: 
        LIGAR
        {
            $$ = strdup("ligar"); /* Representando LIGAR como ligar */
        }
        |
        DESLIGAR
        {
            $$ = strdup("desligar"); /* Representando DESLIGAR como desligar 8*/

        }
        ;




%%

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
    fprintf(saida, "\tvoid ligar(char* namedevice)\n\t{\n\t\tprintf(\"%%s ligado!\\n\", namedevice);\n\t}\n\n");

    fprintf(saida, "\tvoid desligar(char* namedevice)\n\t{\n\t\tprintf(\"%%s desligado!\\n\", namedevice);\n\t}\n\n");

    fprintf(saida, "\tvoid alerta_simples(char* namedevice, char* msg)\n\t{\n\t\tprintf(\"%%s recebeu o alerta:\\n\", namedevice);\n\t\tprintf(\"%%s\\n\", msg);\n\t}\n\n");

    // Nota: Você tem duas funções com o mesmo nome "alerta", o que causaria um erro de compilação.
    // Renomeei a segunda para "alerta2" como exemplo.
    fprintf(saida, "\tvoid alerta_comp(char* namedevice, char* msg, char* var)\n\t{\n\t\tprintf(\"%%s recebeu o alerta:\\n\", namedevice);\n\t\tprintf(\"%%s %%s\\n\", msg, var);\n\t}\n\n");

    fprintf(saida, "int main() {\n\n");
    yyparse(); //Aqui a mágica acontece e o programa é traduzido.
    fprintf(saida, "\nreturn 0;\n}\n");
    fclose(saida);
    return 0;
}
