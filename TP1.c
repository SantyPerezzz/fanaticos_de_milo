#include <stdio.h>

int longitudDeCadena (char* cadena)
{
    int cantidad =0;
    while (cadena[cantidad] != '\0')
    {   
        cantidad++;
    } 
    return cantidad;
}

double convertirEnNumeros (char* cadena)
{
    double numero =0;
    int i=0;
    for (i = 0;cadena[i] != '\0' && cadena[i] != ',' && cadena[i] != '.';i++) //PARTE ENTERA
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
        numero += ((double)decimal/(double)divDeDecimal);
    }
    return numero;
}

void palabraEnMayus (char* palabra, char*palabraEnMayuscula)
{
    int i;
    for (i = 0; palabra[i] != '\0'; i++)
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
    palabraEnMayuscula[i] = '\0';
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
    cadenaSinCaracter[j]='\0';
    
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

/*
void cadanaObtenida (char* cadena, int pos1, int pos2,char* cadenafinal)
{
    int j =0;
    for (int i=pos1;cadena[i] != '\0' && i != pos2;i++)
    {
        cadenafinal[j]=cadena[i];
        j++;
    }
    cadenafinal[j] = '\0';
}
*/

void ingresarElCaracterEnUnaPosicion (char* cadena, char caracter, int pos, char* cadenaFinal)
{
    for (int i=0;cadena[i]!='\0' && i!=pos;i++)
    {
        cadenaFinal[i]=cadena[i];
    }
    cadenaFinal[pos]=caracter;
    int j = pos+1;
    for(int i=pos;cadena[i]!='\0';i++)
    {
        cadenaFinal[j]=cadena[i];
        j++;
    }
    cadenaFinal[j]='\0';
    /*
    char cadenaAnterior[pos] ;
    cadanaObtenida(cadena,0,pos,cadenaAnterior);
    char cadenaSiguiente[longitudDeCadena(cadena)-pos];
    cadanaObtenida(cadena,pos,longitudDeCadena(cadena),cadenaSiguiente);
    char caracteraux[1];
    caracteraux[1]=caracter;
    char cadenaaux [pos+1];
    concatenar(cadenaAnterior,caracteraux,cadenaaux);
    concatenar(cadenaaux,cadenaSiguiente,cadenaFinal);
    */
}

int calcularOcurrencias (char* cadena,char letra)
{
    int cant=0;
    for (int i=0;cadena[i]!='\0'; i++)
    {
        if (cadena [i]==letra)
        {
            cant++;
        }
    } 
    return cant;
}
int main(){
    printf("Elegir la opcion: \n1 = Calcular y retornar la longitud de una cadena dada \n2 = Convertir una cadena de dígitos en su equivalente numérico \n3 = Convertir una cadena de caracteres a la misma cadena con todos sus caracteres en mayúscula\n4 = Eliminar de una cadena dada todas las ocurrencias de un carácter dado \n5 = Concatenar al final de la primer cadena dada una segunda cadena dada \n6 = Modificar la cadena dada con la inserción de un carácter dado en una posición determinada \n");
    int caracter;
    scanf("%d",&caracter);


    printf("Ingrese una cadena \n");
    char cadena [81];
    scanf("%s",&cadena);
    //getc();

    if (1==caracter){
        int cantidad= longitudDeCadena (cadena);
        printf("Tu cadena mide %i \n",cantidad);
    }
    else if (2==caracter){
        double numero= convertirEnNumeros(cadena);
        printf("Tu numero es %.3f \n",numero);
    }
    else if (3==caracter){
        char mayu[longitudDeCadena(cadena)];
        palabraEnMayus(cadena,mayu);
        printf("Tu cadena es %s \n",mayu);
    }
    else if (4==caracter){
        printf("Ingrese una letra \n");
        char letra1;
        fflush(stdin);
        scanf("%c",&letra1);
        int cantcarac = calcularOcurrencias(cadena,letra1);
        char cadenaSin[longitudDeCadena(cadena)-cantcarac];
        eliminarCaracter(cadena, letra1, cadenaSin);
        printf("Su palabra es %s \n",cadenaSin);
    }
    else if (5==caracter){
        char cadena2[81];
        printf("Ingrese otra cadena \n");
        char cadenaFinal1[longitudDeCadena(cadena)+longitudDeCadena(cadena2)];
        scanf("%s",cadena2);
        concatenar (cadena, cadena2, cadenaFinal1);
        printf("Su cadena es %s \n",cadenaFinal1);
    }
    else if (6==caracter){
        printf("Ingrese una letra \n");
        char letra;
        fflush(stdin);
        scanf("%c",&letra);
        printf("Ingrese una posicion \n");
        int pos;
        scanf("%i",&pos);
        char cadenaFinal[longitudDeCadena(cadena)+1];
        ingresarElCaracterEnUnaPosicion(cadena,letra,pos,cadenaFinal);
        printf("Tu cadena es: %s \n",cadenaFinal);
    }
    /*
    switch (caracter)
    {
    case 1:
        int cantidad= longitudDeCadena (cadena);
        printf("Tu cadena mide %i \n",cantidad);
        break;

    case 2:
        double numero= convertirEnNumeros(cadena);
        printf("Tu numero es %.3f \n",numero);
        break;

    case 3:
        char mayu[longitudDeCadena(cadena)];
        palabraEnMayus(cadena,mayu);
        printf("Tu cadena es %s \n",mayu);    
        break;
    
    case 4:
        printf("Ingrese una letra \n");
        char letra1;
        fflush(stdin);
        scanf("%c",&letra1);
        int cantcarac = calcularOcurrencias(cadena,letra1);
        char cadenaSin[longitudDeCadena(cadena)-cantcarac];
        eliminarCaracter(cadena, letra1, cadenaSin);
        printf("Su palabra es %s \n",cadenaSin);
        break;
    
    case 5:
        char cadena2[81];
        printf("Ingrese otra cadena \n");
        char cadenaFinal1[longitudDeCadena(cadena)+longitudDeCadena(cadena2)];
        scanf("%s",cadena2);
        concatenar (cadena, cadena2, cadenaFinal1);
        printf("Su cadena es %s \n",cadenaFinal1);
        break;
    
    case 6:
        printf("Ingrese una letra \n");
        char letra;
        fflush(stdin);
        scanf("%c",&letra);
        printf("Ingrese una posicion \n");
        int pos;
        scanf("%i",&pos);
        char cadenaFinal[longitudDeCadena(cadena)+1];
        ingresarElCaracterEnUnaPosicion(cadena,letra,pos,cadenaFinal);
        printf("Tu cadena es: %s \n",cadenaFinal);
        break;
    }

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

    printf("Resultado es %i %.3f %s %s %s %s",cant,num,mayus,sine,cont,conh);
    */
    
    printf("Fin6");
    return 0;
}
