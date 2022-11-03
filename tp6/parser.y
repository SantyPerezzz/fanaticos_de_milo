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
%token ENTER ESPACIO IGUAL PABRE PCIERRE

//PRECEDENCIA DE ABAJO PARA ARRIBA
%right Y O
%right MENOR MAYOR MENORIGUAL MAYORIGUAL
%right SUMA RESTA
%right MUTIPLICACION DIVICION
%right POTENCIA






%%

inicio:
    INICIADOR proceso FIN {printf("encontro el milo voar\n");}
//PROBANDO LLEGE A LA CONCLUCION Q VA DIRECTO A proceso
procesos:
    procesos procesos {printf("encontro el procesos\n");}
    |proceso {printf("encontro el proceso\n");}

proceso:
    usosvariables
    |usarfuncion
    |ENTER {printf("encontro el ENTER\n");}

usosvariables:
    declararvariable
    |modificarvariable

declararvariable:
    ENTERO ESPACIO IDENTIFICADOR ESPACIO {printf("encontro el declararvariable\n");}
    |VERACIDAD ESPACIO IDENTIFICADOR
    |PALABRA ESPACIO IDENTIFICADOR

modificarvariable:
    ESPACIO IDENTIFICADOR IGUAL expresion ESPACIO{printf("encontro el modificarvariable\n");}

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
    ESCRIBIR PABRE IDENTIFICADOR PCIERRE {printf("encontro el ESCRIBIR\n");}
    |MIENTRAS PABRE expresion PCIERRE
    |SI
    |SI PABRE expresion PCIERRE SINO

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
