#include <stdio.h>

int longitudDeCadena (string cadena)
{
    int cant = 0; 
    char* aux=&cadena;
    while (*aux != '\0')
    {   
        cant++;
        aux=aux+1;
    } 
    return cant;
}

double convertirEnNumeros (string cadena)
{
    double numero =0;
    char* aux=&cadena;
    while (*aux != '\0' || *aux != ',' || *aux != '.') //PARTE ENTERA
    {   
        numero *=10;
        numero+=(*aux-48);
        aux=aux+1;
    } 
    if (*aux != ',' || *aux != '.') //PARTE DECIMAL
    {
        aux=aux+1;
        int decimal = 0;
        int divDeDecimal = 1;
        while (*aux != '\0')
        {
            divDeDecimal *= 10;
            decimal *=10;
            decimal+=(*aux-48);
            aux=aux+1;
        }
        numero += (double)(decimal/divDeDecimal);
    }
    return numero;
}

string palabraEnMayus (string palabra)
{
    string palabraEnMayuscula = "";
    char* aux= &palabra;
    while (*aux != '\0')
    {
        if (*aux <123 && *aux > 96)
        {
            palabraEnMayuscula+= (*aux-'a'+'A');
        }
        else
        {
            palabraEnMayuscula+=*aux;
        }
        aux=aux+1;
    }
    return palabraEnMayuscula;
}

string eliminarCaracter (string cadena, char caracter)
{
    string cadenaSinCaracter = "";
    char* aux= &cadena;
    while (*aux !='\0')
    {
        if (*aux != caracter)
        {
            cadenaSinCaracter+= aux*;
        }
        aux=aux+1;        
    }
    return cadenaSinCaracter;
}

string concatenar (string cadena1, string cadena2)
{
    char* aux= &cadena2
    string cadenaFinal = cadena1;
    
    while (*aux !='\0')
     {
        cadenaFinal+= *aux;
        aux=aux+1;
     }
    return cadenaFinal;
}

string cadanaObtenida (string cadena, int pos1, int pos2)
{
    string cadenafinal ="";
    char* aux = &cadena;
    int pos = pos1;
    while (*aux != '\0' || pos!=pos2)
    {
        cadenafinal+=*aux;
        aux=aux+1;
        pos+=1;
    }
    return cadenafinal;
    
}

string ingresarElCaracterEnUnaPosicion (string cadena, char caracter, int pos)
{
    string cadenaAnterior = cadanaObtenida(cadena,0,pos);
    string cadenaSiguiente = cadanaObtenida(cadena,pos,longitudDeCadena(cadena);
    
    string cadenafinal=concatenar(concatenar(cadenaAnterior,(string)caracter),cadenaSiguiente);
    
    return cadenaFinal;
}

int main(){
    printf("Ingrese la operacion q deseas \n 
    a=Calcular y retornar la longitud de una cadena dada \n 
    b=Converte una cadena de dígitos en su equivalente numérico \n 
    c=Converte una cadena de caracteres a la misma cadena con todos sus caracteres en mayúscula \n 
    d=Elimina de una cadena dada todas las ocurrencias de un carácter dado \n 
    e=Concatena al final de la primer cadena dada una segunda cadena también dada \n 
    f=Modifica la cadena dada con la inserción de un carácter dado en una posición determinada");
    char opcion;
    scanf("%c\n",&opcion);


    switch (opcion)
    {
    case 'a':
        string cadena;
        printf("Ingrese una cadena \n");
        scanf("%s\n",&cadena);
        int cant = longitudDeCadena (cadena);
        printf("La longitid es de %d" , cant);
        break;
    case 'b':
        string cadena;
        printf("Ingrese una cadena \n");
        scanf("%s\n",&cadena);
        double numero = convertirEnNumeros (string cadena);
        printf("El nunmero es %f",numero);
        break;
        
    case 'c':
        string cadena;
        printf("Ingrese una cadena \n"):
        scanf("%s\n",&cadena);
        string palabraEnMayuscula= palabraEnMayus (cadena)
        printf("La cadena en mayuscula es %s",palabraEnMayuscula);
        break;

    case 'd':
        string cadena = "";
        printf("Ingrese una cadena \n"):
        scanf("%s\n",&cadena); 
        char caracter = '';
        printf("Ingrese una caracter \n"):
        scanf("%c\n",&caracter); 
        string cadenaSinCaracter = eliminarCaracter(cadena,caracter);
        printf("La cadena en mayuscula es %s",cadenaSinCaracter);
        break;
        
    case 'e':
        string cadena1="";
        
        printf("Ingrese la primer cadena \n");
        scanf("%s\n",&cadena1);

        string cadena2="";
        
        printf("Ingrese la segunda cadena \n");
        scanf("%s\n",&cadena2);
        
        string cadenaFinal= concatenar (cadena1 , cadena2);
        
        printf("La combinacion de cadenas es %s",cadenaFinal);
        break;
    
    case 'f':
        string cadena = "";
        printf("Ingrese una cadena \n"):
        scanf("%s\n",&cadena);

        char caracter = '';
        printf("Ingrese una caracter \n"):
        scanf("%c\n",&caracter); 

        int pos = 0;
        printf("Ingrese la posicion \n"):
        scanf("%c\n",&pos); 

        string cadenaConElCaracter = ingresarElCaracterEnUnaPosicion (cadena,caracter,pos);
        printf("La cadenas con el caracter es %s",cadenaConElCaracter);
        break;
    default:
        printf("ERROR");
        break;
    return 0;
}