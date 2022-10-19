#include <stdio.h>
#include <stdbool.h>

int columna(char caracter, char* caracteresAlfabeto, const int cantCaracteresAlfabeto){
    int columnaDelCaracter = 0;
    while (caracteresAlfabeto[columnaDelCaracter] != caracter && columnaDelCaracter < cantCaracteresAlfabeto)
    {
        columnaDelCaracter++;
    }
    return columnaDelCaracter;
}

bool esEstadoFinal(int estadoActual,int* estadosFinales,int cantEstadosFinales){
    bool r=false;
    for (int i = 0; i < cantEstadosFinales; i++)
    {
        if (estadosFinales[i] == estadoActual)
        {
            r=true;
            break;
        }
    }
    return r;
}

bool automata (char* cadena, char* caracteresAlfabeto, int estadoInicial, int* estadosFinales, int* transiciones,
const int cantEstados, const int cantCaracteresAlfabeto, const int cantEstadosFinales){
    int i=0;
    int estadoActual = estadoInicial;
    char caracterAAnalizar = cadena[i];
    int columnaDelCaracter = columna(caracterAAnalizar, caracteresAlfabeto, cantCaracteresAlfabeto);
    while(caracterAAnalizar!='\0' && columnaDelCaracter < cantCaracteresAlfabeto && estadoActual <= cantEstados){
        columnaDelCaracter = columna(caracterAAnalizar, caracteresAlfabeto, cantCaracteresAlfabeto);
        estadoActual = transiciones[estadoActual*cantCaracteresAlfabeto+columnaDelCaracter];
        i++;
        caracterAAnalizar = cadena[i];
    }
    return esEstadoFinal(estadoActual,estadosFinales,cantEstadosFinales) && columnaDelCaracter < cantCaracteresAlfabeto;
}

bool esMayuscula(char* cadena){
    char caracteresAlfabeto[] = "ABCDEFGHIJKLMNOPKRSTUVWXYZ";
    int estadosFinales[] = {1};
    int estadoInicial = 0;
    int cantEstados = 3;
    int cantCaracteresAlfabeto = 26;
    int cantEstadosFinales = 1;
    int transiciones[78] = {
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2
        };
    return automata(cadena, caracteresAlfabeto, estadoInicial, estadosFinales, transiciones, cantEstados, cantCaracteresAlfabeto, cantEstadosFinales);
}

bool esMinuscula(char* cadena){
    char caracteresAlfabeto[] = "abcdefghijklmnopqrstuvwxyz";
    int estadosFinales[] = {1};
    int estadoInicial = 0;
    int cantEstados = 3;
    int cantCaracteresAlfabeto = 26;
    int cantEstadosFinales = 1;
    int transiciones[78] = {
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2
        };
    return automata(cadena, caracteresAlfabeto, estadoInicial, estadosFinales, transiciones, cantEstados, cantCaracteresAlfabeto, cantEstadosFinales);
}

bool esDigito(char* cadena){
    char caracteresAlfabeto[] = "0123456789";
    int estadosFinales[] = {1};
    int estadoInicial = 0;
    const int cantEstados = 3;
    const int cantCaracteresAlfabeto = 10;
    int cantEstadosFinales = 1;
    int transiciones[30] = {
        1,1,1,1,1,1,1,1,1,1,
        2,2,2,2,2,2,2,2,2,2,
        2,2,2,2,2,2,2,2,2,2
        };
    return automata(cadena, caracteresAlfabeto, estadoInicial, estadosFinales, transiciones, cantEstados, cantCaracteresAlfabeto, cantEstadosFinales);
}


bool esCaracter(char* cadena){
    char caracteresAlfabeto[] = "ABCDEFGHIJKLMNOPKRSTUVWXYZabcdefghijklmnopqrstuvwxyz_";
    int estadosFinales[] = {1};
    int estadoInicial = 0;
    const int cantEstados = 3;
    const int cantCaracteresAlfabeto = 53;
    int cantEstadosFinales = 1;
    int transiciones[159] = {
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
        2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2
    };
    return automata(cadena, caracteresAlfabeto, estadoInicial, estadosFinales, transiciones, cantEstados, cantCaracteresAlfabeto, cantEstadosFinales);
}

bool esLogico(char* cadena){
    char caracteresAlfabeto[] = "VerdaioFlsfc";
    int estadosFinales[] = {10,21};
    int estadoInicial = 0;
    const int cantEstados = 23;
    const int cantCaracteresAlfabeto = 12;
    int cantEstadosFinales = 2;
    int transiciones[276] = {
        1,22,22,22,22,22,22,11,22,22,22,22,
        22,2,22,22,22,22,22,22,22,22,22,22,
        22,22,3,22,22,22,22,22,22,22,22,22,
        22,22,22,4,22,22,22,22,22,22,22,22,
        22,22,22,22,5,22,22,22,22,22,22,22,
        22,22,22,6,22,22,22,22,22,22,22,22,
        22,7,22,22,22,22,22,22,22,22,22,22,
        22,22,22,22,22,8,22,22,22,22,22,22,
        22,22,9,22,22,22,22,22,22,22,22,22,
        22,22,22,22,22,22,10,22,22,22,22,22,
        22,22,22,22,22,22,22,22,22,22,22,22,
        22,22,22,22,12,22,22,22,22,22,22,22,
        22,22,22,22,22,22,22,22,13,22,22,22,
        22,22,22,22,22,22,22,22,22,14,22,22,
        22,22,22,22,22,15,22,22,22,22,22,22,
        22,22,22,22,22,22,22,22,22,22,16,22,
        22,22,22,22,22,17,22,22,22,22,22,22,
        22,22,22,22,22,22,22,22,22,22,22,18,
        22,22,22,22,19,22,22,22,22,22,22,22,
        22,22,22,20,22,22,22,22,22,22,22,22,
        22,22,22,22,22,22,21,22,22,22,22,22,
        22,22,22,22,22,22,22,22,22,22,22,22,
        22,22,22,22,22,22,22,22,22,22,22,22
    };
    return automata(cadena, caracteresAlfabeto, estadoInicial, estadosFinales, transiciones, cantEstados, cantCaracteresAlfabeto, cantEstadosFinales);   
}

bool esOperador(char* cadena){
    char caracteresAlfabeto[] = "+-/*^<>=";
    int estadosFinales[] = {1,2};
    int estadoInicial = 0;
    const int cantEstados = 5;
    const int cantCaracteresAlfabeto = 8;
    int cantEstadosFinales = 2;
    int transiciones[40] = {
        1,1,2,1,1,2,2,3,
        5,5,5,5,5,5,5,5,
        5,5,5,5,5,5,5,1,
        5,5,5,5,5,5,5,1,
        5,5,5,5,5,5,5,5
        };
    return automata(cadena, caracteresAlfabeto, estadoInicial, estadosFinales, transiciones, cantEstados, cantCaracteresAlfabeto, cantEstadosFinales);
}

bool esCadena(char* cadena){
    char caracteresAlfabeto[] = "\" +-/*^<>=ABCDEFGHIJKLMNOPKRSTUVWXYZabcdefghijklmnopqrstuvwxyz_(),.{}[]|~:&;\\";
    int estadosFinales[] = {2};
    int estadoInicial = 0;
    const int cantEstados = 4;
    const int cantCaracteresAlfabeto = 77;
    int cantEstadosFinales = 1;
    int transiciones[308] = {
        1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
        2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
        3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
        };
    return automata(cadena, caracteresAlfabeto, estadoInicial, estadosFinales, transiciones, cantEstados, cantCaracteresAlfabeto, cantEstadosFinales);
}

bool esNumero(char* cadena){
    char caracteresAlfabeto[] = "0123456789";
    int estadosFinales[] = {1};
    int estadoInicial = 0;
    const int cantEstados = 2;
    const int cantCaracteresAlfabeto = 10;
    int cantEstadosFinales = 1;
    int transiciones[20] = {
        1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,
        };
    return automata(cadena, caracteresAlfabeto, estadoInicial, estadosFinales, transiciones, cantEstados, cantCaracteresAlfabeto, cantEstadosFinales);
}




int main (){
    int r = esNumero("156166858488513510a");
    printf("8 %d  7",r);
}
