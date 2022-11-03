%{
    //Declaraciones en C
    #include <stdio.h>
    #include <stdbool.h>
    int yylex(void);
    void yyerror(char *s);
    FILE* yyin;
%}

%start inicio

//PALABRAS RESERVADAS
%token MIENTRAS SI SINO ESCRIBIR VERACIDAD ENTERO PALABRA INICIADOR FIN
//VARIABLE
%token IDENTIFICADOR
//OPERADORES
%token MENORIGUAL MENOR MAYORIGUAL MAYOR SEMEJANTE DIFERENTE Y O SUMA RESTA MUTIPLICACION DIVICION POTENCIA
//CONSTANTES
%token NUMERO
%token VERDADERO FALSO 
%token CADENA


//PRECEDENCIA DE ABAJO PARA ARRIBA
%right Y O
%right MENOR MAYOR MENORIGUAL MAYORIGUAL
%right SUMA RESTA
%right MUTIPLICACION DIVICION
%right POTENCIA






%%

inicio:
    INICIADOR  procesos FIN

procesos:
    proceso procesos
    |proceso

proceso:
    usosvariables
    |usarfuncion   

usosvariables:
    declararvariable
    |modificarvariable


declararvariable:
    ENTERO IDENTIFICADOR
    |VERACIDAD IDENTIFICADOR
    |PALABRA IDENTIFICADOR

modificarvariable:
    IDENTIFICADOR '=' expresion

expresion:
    IDENTIFICADOR
    |NUMERO 
    |VERDADERO 
    |FALSO 
    |CADENA 
    |expresion SUMA expresion 
    |expresion RESTA expresion
    |expresion MUTIPLICACION expresion
    |expresion DIVICION expresion 
    |expresion POTENCIA expresion 
    |expresion MENOR expresion 
    |expresion MENORIGUAL expresion 
    |expresion MAYOR expresion 
    |expresion MAYORIGUAL expresion 
    |expresion SEMEJANTE expresion 
    |expresion DIFERENTE expresion
    |expresion Y expresion
    |expresion O expresion

usarfuncion:
    ESCRIBIR '(' ENTERO ' ' IDENTIFICADOR ')'
    |ESCRIBIR '(' PALABRA ' ' IDENTIFICADOR ')'
    |ESCRIBIR '(' VERACIDAD ' ' IDENTIFICADOR ')'
    |MIENTRAS '(' expresion ')'
    |SI
    |SI '(' expresion ')' SINO

//Reglas gramaticales


%%
void yyerror(char *s){
    printf("Error Sintactico (%s) \n",s);
}
//Codigo C adicional

int main (int argc, char *argv[]){
    if( ( yyin = fopen(argv[1],"rt")) ==NULL){
        printf("F en el chat\n");
        return 1;
    }
    else{
        printf("El archivo %s se abrio correctamente\n", argv[1]);
        yyparse();
    }
    fclose(yyin);
    printf("\nfin");
    return 0;
}
