%{
#include <stdio.h>
#include <stdbool.h>
#include "y.tab.h"
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
IDENTIFICADOR           {MAYUSCULA}({CARACTER}|{DIGITO})*



%%
enquanto                    {return MIENTRAS;}
se                          {return SI;}
senao                       {return SINO;}
ensinar                     {return ESCRIBIR;}
veracidade                  {return VERACIDAD;}
quantidade                  {return ENTERO;}
palavra                     {return PALABRA;}
milo                        {return INICIADOR;}
Verdadeiro                  {return VERDADERO;}
Falsificado                 {return FALSO;}
{NUMERO}                    {return NUMERO;}
{CADENA}                    {return CADENA;}
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
{IDENTIFICADOR}             {return IDENTIFICADOR;}
voar                        {return FIN;}
\n
\t
=
" "
.                           error();
%% 

int error(void){
    printf("Error lexico: no se entiende la palabra %s \n", yytext);
    exit(1);
}