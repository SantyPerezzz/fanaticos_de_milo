%{
    //Declaraciones en C
    #include <stdio.h>
    #include <stdbool.h>
    int yylex(void);
    void yyerror(char *s);
%}

%start inicio

//PALABRAS RESERVADAS
%token MIENTRAS SI SINO ESCRIBIR VERACIDAD ENTERO PALABRA INICIADOR
//VARIABLE
%token IDENTIFICADOR
//OPERADORES
%token MENORIGUAL MENOR MAYORIGUAL MAYOR SEMEJANTE DIFERENTE Y O SUMA RESTA MUTIPLICACION DIVICION POTENCIA
//CONSTANTES
%token <valor_entero> NUMERO
%token <valor_booleano> VERDADERO FALSO 
%token <valor_cadena> CADENA


//PRECEDENCIA DE ABAJO PARA ARRIBA
%right Y O
%right MENOR MAYOR MENORIGUAL MAYORIGUAL
%right SUMA RESTA
%right MUTIPLICACION DIVICION
%right POTENCIA


%union
{
    int <valor_entero>;
    bool <valor_booleano>;
    char[1000] <valor_cadena>;
}

%type<valor_entero> enteros
%type<valor_booleano> boolianos
%type<valor_cadena> strings


%%

inicio:
    INICIADOR procesos
    |procesos inicio

procesos:
    usosvariables
    |usarfuncion    

usosvariables:
    declararvariable
    |modificarvariable

declararvariable:
    enteros
    |boolianos
    |strings

enteros: ENTERO IDENTIFICADOR {$$=int $2;}
boolianos: VERACIDAD IDENTIFICADOR {bool $2;}
strings: PALABRA IDENTIFICADOR {har[1000] $2;}
/*declararvariable:
    ENTERO IDENTIFICADOR {int $2;}
    |VERACIDAD IDENTIFICADOR {bool $2;}
    |PALABRA IDENTIFICADOR {har[1000] $2;}
*/
modificarvariable:
    IDENTIFICADOR '=' exprecion {$1 = $3;}

exprecion:
    IDENTIFICADOR {$1;}
    |NUMERO {$1;}
    |VERDADERO {$1;}
    |FALSO {$1;}
    |CADENA {$1;}
    |exprecion SUMA exprecion {$1 + $3;}
    |exprecion RESTA exprecion {$1 - $3;}
    |exprecion MUTIPLICACION exprecion {$1 * $3;}
    |exprecion DIVICION exprecion {$1 / $3;}
    |exprecion POTENCIA exprecion {potencia($1,$3);}
    |exprecion MENOR exprecion {$1 < $3;}
    |exprecion MENORIGUAL exprecion {$1 <= $3;}
    |exprecion MAYOR exprecion {$1 > $3;}
    |exprecion MAYORIGUAL exprecion {$1 >= $3;}
    |exprecion SEMEJANTE exprecion {$1 == $3;}
    |exprecion DIFERENTE exprecion {$1 != $3;}
    |exprecion Y exprecion {$1 && $3;}
    |exprecion O exprecion  {$1 || $3;}

usarfuncion:
    ESCRIBIR '(' ENTERO ' ' IDENTIFICADOR ')' {printf("$d",$5)}
    |ESCRIBIR '(' PALABRA ' ' IDENTIFICADOR ')' {printf("$s",$5)}
    |ESCRIBIR '(' VERACIDAD ' ' IDENTIFICADOR ')' {printf("$d",$5)}
    |MIENTRAS '(' exprecion ')' {printf("while")}
    |SI {printf("while")}
    |SI '(' exprecion ')' SINO {printf("while")}

//Reglas gramaticales


%%
void yyerror(char *s){
    printf(" ->Error Sintactico %s \n",s);
}
//Codigo C adicional

int main (){
    printf("play\n");
    yyparse();
    printf("\nfin");
    return 0;
}

int potencia(int a,int b){
    int r=1;
    for(int i=1;i<b;i++)
    {
        r*=a;
    }
    return r;
}