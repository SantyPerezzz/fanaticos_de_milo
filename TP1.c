#include <stdio.h>

int longitudDeCadena (char* cadena)
{
    int cantidad =0;
    while (cadena[cantidad]= '\0')
    {   
        cantidad++;
    } 
    return cantidad;
}

double convertirEnNumeros (char* cadena)
{
    double numero =0;
    int i=0;
    for (;cadena[i] != '\0' || cadena[i] != ',' || cadena[i] != '.';i++) //PARTE ENTERA
    {   
        numero *=10;
        numero+=(cadena[i]-'0');
    } 
    if (cadena[i] == ',' || cadena[i] == '.') //PARTE DECIMAL
    {
        i++;
        int decimal = 0;
        int divDeDecimal = 1;
        for (;cadena[i] != '\0';i++)
        {
            divDeDecimal *= 10;
            decimal *=10;
            decimal+=(cadena[i]-48);
        }
        numero += (double)(decimal/divDeDecimal);
    }
    return numero;
}

void palabraEnMayus (char* palabra, char*palabraEnMayuscula)
{
    for (int i=0;palabra[i] != '\0';i++)
    {
        if (palabra[i] <='z' && palabra[i] >='a')
        {
            palabraEnMayuscula[i] = (palabra[i]-'a'+'A');
        }
        else
        {
            palabraEnMayuscula[i] = palabra[i];
        }
    }
}

void eliminarCaracter (char* cadena, char caracter , char* cadenaSinCaracter)
{
    int j =0;
    for (int i = 0; cadena[i] != '\0'; i++)
    {
        if (cadena[i] != caracter)
        {
            cadenaSinCaracter[j] = cadena[i];
            j++;
        }   
    }
    
}

void concatenar(char* cadena1, char* cadena2, char* cadenaFinal)
{
    int i=0;
    int j=0;
    int cantCaracteres = longitudDeCadena (cadena1) + longitudDeCadena(cadena2);
    for(i = 0; cadena1[i] != '\0' && i < cantCaracteres; i++){
        cadenaFinal[i] = cadena1[i];
    }
    for(j = 0; cadena2[j] != '\0' && i+j < cantCaracteres; j++){
        cadenaFinal[i+j] = cadena2[j];
    }
    cadenaFinal[i+j] = '\0';
}

void cadanaObtenida (char* cadena, int pos1, int pos2,char* cadenafinal)
{
    int j =0;
    for (int i=pos1;cadena[i] != '\0' || pos1!=pos2;i++)
    {
        cadenafinal[j]=cadena[i];
        j++;
    }
}

void ingresarElCaracterEnUnaPosicion (char* cadena, char caracter, int pos, char* cadenaFinal)
{
    char cadenaAnterior[pos] ;
    cadanaObtenida(cadena,0,pos,cadenaAnterior);
    char cadenaSiguiente[longitudDeCadena(cadena)-pos];
    cadanaObtenida(cadena,pos,longitudDeCadena(cadena),cadenaSiguiente);
    char caracteraux[1];
    caracteraux[1]=caracter;
    char cadenaaux [pos+1];
    concatenar(cadenaAnterior,caracteraux,cadenaaux);
    concatenar(cadenaaux,cadenaSiguiente,cadenaFinal);
}

int main(){

    char ej_a_c_d_f []="electrodomestico";
    char ej_b []="123.123";
    char ej_e []="importado";

    int cant =longitudDeCadena (ej_a_c_d_f);
    double num = convertirEnNumeros(ej_b);
    char mayus[cant];
    palabraEnMayus(ej_a_c_d_f,mayus);
    char sine[cant-3];
    eliminarCaracter(ej_a_c_d_f,'e',sine);
    char cont[cant+longitudDeCadena(ej_e)];
    concatenar(ej_a_c_d_f,ej_e,cont);
    char conh[cant+1];
    ingresarElCaracterEnUnaPosicion(ej_a_c_d_f,'h',0,conh);

    printf("%i %d %s %s %s %s",cant,num,mayus,sine,cont,conh);


    return 0;
}