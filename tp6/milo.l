%{
#include <stdio.h>
#include <stdbool.h>
#include "y.tab.h"
FILE* yyin;
%}

%option noyywrap
%option yylineno


DIGITO                  [0-9]
MAYUSCULA               [A-Z]
MINUSCULA               [a-z]
CARACTER                {MAYUSCULA}|{MINUSCULA}|"_"
CARACTERPUNTUACION      ")"|"("|","|"."|"}"|"{"|"]"|"["|"~"|":"|";"|"&"|"|"|"\\"|"-"
ESPACIO                 " "
OPERADORES                "+"|"-"|"/"|"*"|"^"|"<"|">"|"<="|">="|"=="|"/="
CARACTERLITERAL         {CARACTER}|{CARACTERPUNTUACION}|{ESPACIO}|{OPERADORES}|"="
CADENA                  \"{CARACTERLITERAL}*\"
NUMERO                  {DIGITO}+
IDENTIFICADOR           {MAYUSCULA}({CARACTER}|{DIGITO})*



%%
enquanto                        {return MIENTRAS;}
se                              {return SI;}
senao                           {return SINO;}
ensinar                         {return ESCRIBIR;}
veracidade                      {return VERACIDAD;}
quantidade                      {return ENTERO;}
palavra                         {return PALABRA;}
milo                            {return INICIADOR;}
Verdadeiro                      {return VERDADERO;}
Falsificado                     {return FALSO;}
{NUMERO}                        {return NUMERO;}
{CADENA}                        {return CADENA;}
"<<"                              {return ABRESENTENCIA;}
">>"                              {return CIERRASENTENCIA;}
"<="|">="|"=="|"!="|"<"|">"     {return OPERADORCOMPARACION;}
"&&"|"||"                       {return OPERADORLOGICO;}
"+"|"-"                         {return OPERADORADICION;}
"*"|"/"                         {return OPERADORPRODUCTO;}
"^"                             {return OPERADORPOTENCIA;}
{IDENTIFICADOR}                 {return IDENTIFICADOR;}
\n
\t
"("                             {return PABRE;}
")"                             {return PCIERRE;}
=                               {return IGUAL;}
" "
.                               error();
%% 

int error(void){
    printf("Error lexico: no se entiende la palabra %s \n", yytext);
    exit(1);
}