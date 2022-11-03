%{
#include <stdio.h>
FILE *yyin;
%}

%option noyywrap
%option yylineno

DIGITO                  [0-9]
MAYUSCULA               [A-Z]
MINUSCULA               [a-z]
CARACTER                {MAYUSCULA}|{MINUSCULA}|"_"
CARACTERPUNTUACION      ")"|"("|","|"."|"}"|"{"|"]"|"["|"~"|":"|";"|"&"|"|"|"\\"|"-"
ESPACIO                 " "
OPERADOR                "+"|"-"|"/"|"*"|"^"|"<"|">"|"<="|">="|"=="|"/="
CARACTERLITERAL         {CARACTER}|{CARACTERPUNTUACION}|{ESPACIO}|{OPERADOR}|=
CADENA                  \"{CARACTERLITERAL}*\"
NUMERO                  {DIGITO}+
LOGICO                  "Verdadeiro"|"Falsificado"
IDENTIFICADOR           {MAYUSCULA}({CARACTER}|{DIGITO})*
CONSTANTE               {NUMERO}|{CADENA}|{LOGICO}
PALABRARESERVADA        "enquanto"|"se"|"senao"|"quantidade"|"palavra"|"veracidade"|"funcao"|"milo"

%%

{PALABRARESERVADA}        {printf("PALABRARESERVADA (%s) \n" ,yytext);}
{IDENTIFICADOR}           {printf("IDENTIFICADOR (%s) \n",yytext);}
{CONSTANTE}               {printf("CONSTANTE (%s) \n",yytext);}
{OPERADOR}                {printf("OPERADOR (%s) \n",yytext);}
{CARACTERPUNTUACION}      {printf("CARACTERPUNTUACION (%s) \n",yytext);}
\n
\t
" "
.                           error("aaaah");

%%
int main (int argc, char *argv[]){
    if( ( yyin = fopen(argv[1],"rt")) ==NULL){
        printf("F en el chat\n");
        return 1;
    }
    else{
        printf("El archivo %s se abrio correctamente\n", argv[1]);
        yylex();
    }
    fclose(yyin);
    printf("FIN \n");
    return 0;
}

int error(void){
    printf("Error lexico: no se entiende la palabra %s", yytext);
    exit(1);
}