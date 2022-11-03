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
%token OPERADORCOMPARACION OPERADORLOGICO OPERADORADICION OPERADORPRODUCTO OPERADORPOTENCIA
//sentencias
%token ABRESENTENCIA CIERRASENTENCIA

//CONSTANTES
%token NUMERO
%token VERDADERO FALSO 
%token CADENA
%token IGUAL PABRE PCIERRE

//PRECEDENCIA DE ABAJO PARA ARRIBA
%right OPERADORLOGICO
%right OPERADORCOMPARACION
%right OPERADORADICION
%right OPERADORPRODUCTO
%right POTENCIA






%%

inicio:
    INICIADOR bloque
//PROBANDO LLEGE A LA CONCLUCION Q VA DIRECTO A proceso

bloque: ABRESENTENCIA procesos CIERRASENTENCIA

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
    IDENTIFICADOR IGUAL expresion

expresion:
    IDENTIFICADOR
    |NUMERO 
    |VERDADERO 
    |FALSO 
    |CADENA 
    |expresion operacion expresion

operacion:
    OPERADORCOMPARACION
    |OPERADORLOGICO
    |OPERADORADICION
    |OPERADORPRODUCTO
    |OPERADORPOTENCIA

usarfuncion:
    ESCRIBIR PABRE IDENTIFICADOR PCIERRE
    |MIENTRAS PABRE expresion PCIERRE bloque
    |SI PABRE expresion PCIERRE bloque sino

sino:
    SINO bloque
    |/*epsilon*/

//Reglas gramaticales


%%

//Codigo C adicional
void yyerror(char *s){
    printf("Error Sintactico (%s) \n",s);
}

int main(void)
{
	if(yyparse()==0)
		printf("Compilacion exitosa\n");
	return 0;
}