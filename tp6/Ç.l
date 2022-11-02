%{
#include <stdio.h>
FILE *yyin;
%}

%option noyywrap
%option yylineno

DIGITO                  [0-9]
MAYUSCULA               [A-Z]
MINUSCULA               [a-z]
CARACTER                [{MAYUSCULA}{MINUSCULA}_]
CARACTERPUNTUACION      [")""("","".""}""{""]""[""~"":"";""&""|""\\""-"]
ESPACIO                 " "
OPERADOR                ["+""-""/""*""^""<"">""<="">=""==""/="]
CARACTERLITERAL         {CARACTER}|{CARACTERPUNTUACION}|{ESPACIO}|{OPERADORES}|=
CADENA                  \"{CARACTERLITERAL}*\"
NUMERO                  {DIGITO}+
LOGICO                  "Verdadeiro"|"Falsificado"
IDENTIFICADOR           {MAYUSCULA}({CARACTER}|{DIGITO})*
CONSTANTE               {NUMERO}|{CADENA}|{LOGICO}
PALABRARESERVADA        ["enquanto""se""senao""quantidade""palavra""veracidade""funcao""milo"]

%%

{DIGITO}                  {printf("DIGITO\n");}
{MAYUSCULA}               {printf("MAYUSCULA\n");}
{MINUSCULA}               {printf("MINUSCULA\n");}
{CARACTER}                {printf("CARACTER\n");}
{CARACTERPUNTUACION}      {printf("CARACTERPUNTUACION\n");}
{OPERADOR}                {printf("OPERADOR\n");}
{CARACTERLITERAL}         {printf("CARACTERLITERAL\n");}
{CADENA}                  {printf("CADENA\n");}
{NUMERO}                  {printf("NUMERO\n");}
{LOGICO}                  {printf("LOGICO\n");}
{IDENTIFICADOR}           {printf("IDENTIFICADOR\n");}
{CONSTANTE}               {printf("CONSTANTE\n");}
{PALABRARESERVADA}        {printf("PALABRARESERVADA\n");}
\n
\t
" "
.                           error()

%%
int main (int argc, char *argv[]){
    if((yyin == fopen(argv1[1],"rt"))==NULL){
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
%%