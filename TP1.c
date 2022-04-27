#include <stdio.h>

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
        int cant = 0; 
         cadena*;
         aux*=cadena;
         while (aux!= NULL)
         {
             cant++;
             aux=aux+1;
         } 
         printf("La longitid es de %d" , cant);
            break;
    case 'b':
    default:
        break;
    }    

    printf("holamundo\n");
    return 0;

}