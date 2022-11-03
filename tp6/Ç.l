%{
#include <stdio.h>
#include "y.tab.h"
#include <stdbool.h>
FILE *yyin;
%}

%option noyywrap
%option yylineno


DIGITO                  [0-9]
MAYUSCULA               [A-Z]
MINUSCULA               [a-z]
/*CARACTER                {MAYUSCULA}|{MINUSCULA}|"_"
/*CARACTERPUNTUACION      ")"|"("|","|"."|"}"|"{"|"]"|"["|"~"|":"|";"|"&"|"|"|"\\"|"-"
ESPACIO                 " "
/*OPERADOR                "+"|"-"|"/"|"*"|"^"|"<"|">"|"<="|">="|"=="|"/="
CARACTERLITERAL         {CARACTER}|{CARACTERPUNTUACION}|{ESPACIO}|{OPERADOR}|=
CADENA                  \"{CARACTERLITERAL}*\"
NUMERO                  {DIGITO}+
/*LOGICO                  "Verdadeiro"|"Falsificado"
IDENTIFICADOR           {MAYUSCULA}({CARACTER}|{DIGITO})*
/*CONSTANTE               {NUMERO}|{CADENA}|{LOGICO}
/*PALABRARESERVADA        "enquanto"|"se"|"senao"|"quantidade"|"palavra"|"veracidade"|"funcao"|"ensinar"|"milo"



%%
enquanto                    {return MIENTRAS;}
se                          {return SI;}
senao                       {return SINO;}
ensinar                     {return ESCRIBIR;}
veracidade                  {return VERACIDAD;}
quantidade                  {return ENTERO;}
palavra                     {return PALABRA;}
milo                        {return INICIADOR}
Verdadeiro                  {yylval.valor_booleano =true;return VERDADERO}
Falsificado                 {yylval.valor_booleano =false;return FALSO}
{NUMERO}                    {yylval.valor_entero=atoi(yytext);return NUMERO;}
{CADENA}                    {yylval.valor_cadena=yytext;return CADENA;}
"<="                        {return MENORIGUAL;}
"<"                         {return MENOR;}
">="                        {return MAYORIGUAL;}
">"                         {return MAYOR;}
"=="                        {return SEMEJANTE;}
"!="                        {return DIFERENTE;}
"&&"                        {return Y;}
"||"                        {return O;}
"+"                         {return SUMA;}
"-"                         {return RESTA;}
"*"                         {return MUTIPLICACION;}
"/"                         {return DIVICION;}
"^"                         {return POTENCIA;}
{IDENTIFICADOR}             {return IDENTIFICADOR}



\n
\t
" "
.                           error();

%%
/*
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
}   */

int error(void){
    printf("Error lexico: no se entiende la palabra %s", yytext);
    exit(1);
}