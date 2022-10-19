PUNTO 1:

B)

PS C:\Users\bruno\Documents\Visual Studio Proyect\copilator> gcc -E .\hello2.c -o hello2.i

Con esta línea el gcc agarra el hello2.c, le quita los comentarios, interpreta las directivas
de preprocesamiento y guarda el resultado en hello2.i (preprocesado)


D) Es la declaración de la funcion printf tal cual está definida en la bibioteca estándar stdio.h


E)

PS C:\Users\bruno\Documents\Visual Studio Proyect\copilator> gcc -E hello3.c -o hello3.i

La única diferencia entre hello3.c y hello3.i son 4 lineas que creemos que no hacen nada.



PUNTO 2:

A)

PS C:\Users\bruno\Documents\Visual Studio Proyect\copilator> gcc -S .\hello3.i -o hello3.s
.\hello3.c: In function 'main':
.\hello3.c:5:5: warning: implicit declaration of function 'prontf'; did you mean 'printf'? [-Wimplicit-function-declaration]
    5 |     prontf("La respuesta es %d\n");
      |     ^~~~~~
      |     printf
.\hello3.c:5:5: error: expected declaration or statement at end of input

El error se debe a un punto y coma, aunque es poco expresivo...


B)

PS C:\Users\bruno\Documents\Visual Studio Proyect\copilator> gcc -E .\hello4.c -o hello4.i
PS C:\Users\bruno\Documents\Visual Studio Proyect\copilator> gcc -S .\hello4.i -o hello4.s
.\hello4.c: In function 'main':
.\hello4.c:5:5: warning: implicit declaration of function 'prontf'; did you mean 'printf'? [-Wimplicit-function-declaration]
    5 |     prontf("La respuesta es %d\n");
      |     ^~~~~~
      |     printf


C) El lenguaje ensamblador es un lenguaje de bajo nivel en donde se manipulan datos de memoria e instrucciones para el procesador


D)

PS C:\Users\bruno\Documents\Visual Studio Proyect\copilator> gcc -c .\hello4.s -o hello4.o



PUNTO 3:

A)

PS C:\Users\bruno\Documents\Visual Studio Proyect\copilator> gcc .\hello4.o -o hello4.exe 
c:/c/mingw/bin/../lib/gcc/mingw32/9.2.0/../../../../mingw32/bin/ld.exe: .\hello4.o:hello4.c:(.text+0x1e): undefined reference to `prontf'
collect2.exe: error: ld returned 1 exit status


B)

PS C:\projects\sintaxis\fanaticos_de_milo\copilator> gcc hello5.c -o hello5.exe


C)

PS C:\projects\sintaxis\fanaticos_de_milo\copilator> .\hello5
La respuesta es -878439504
PS C:\projects\sintaxis\fanaticos_de_milo\copilator> .\hello5
La respuesta es 658510768
PS C:\projects\sintaxis\fanaticos_de_milo\copilator> .\hello5
La respuesta es -391179344
PS C:\projects\sintaxis\fanaticos_de_milo\copilator> .\hello5
La respuesta es -1857154128
PS C:\projects\sintaxis\fanaticos_de_milo\copilator> .\hello5
La respuesta es 72881072

Siempre nos tira un valor distinto. Estamos reservando espacio para imprimir un entero
pero nunca le pasamos la variable, con los cual nos muestra el espacio asignado que termina
siendo una variable basura.



PUNTO 4)

A)

PS C:\projects\sintaxis\fanaticos_de_milo\copilator> gcc hello6.c -o hello6.exe
PS C:\projects\sintaxis\fanaticos_de_milo\copilator> .\hello6
La respuesta es 42



PUNTO 5)

A)

PS C:\projects\sintaxis\fanaticos_de_milo\copilator> gcc -E hello7.c -o hello7.i
PS C:\projects\sintaxis\fanaticos_de_milo\copilator> gcc -S hello7.i -o hello7.s
hello7.c: In function 'main':
hello7.c:3:5: warning: implicit declaration of function 'printf' [-Wimplicit-function-declaration]
    3 |     printf("La respuesta es %d\n", i);
      |     ^~~~~~
hello7.c:1:1: note: include '<stdio.h>' or provide a declaration of 'printf'
  +++ |+#include <stdio.h>
    1 | int main(void) {
hello7.c:3:5: warning: incompatible implicit declaration of built-in function 'printf' [-Wbuiltin-declaration-mismatch]
    3 |     printf("La respuesta es %d\n", i);
      |     ^~~~~~
hello7.c:3:5: note: include '<stdio.h>' or provide a declaration of 'printf'

PS C:\projects\sintaxis\fanaticos_de_milo\copilator> gcc hello7.s -o hello7.exe
PS C:\projects\sintaxis\fanaticos_de_milo\copilator> .\hello7
La respuesta es 42


B)

En principio uno podría pensar que funciona porque incluye la librería estándar stdio.h automáticamente, pero
esto no es cierto. En realidad, eso sólo sirve para poder chequear errores de sintáxis y semántica.
Creemos que la verdadera razón por la que funciona es que el linker, por defecto, busca en las librerías estándares siempre
y por lo tanto encuentra la funcion printf desde ahí.



PUNTO 6)


PS C:\Users\bruno\Documents\Visual Studio Proyect\copilator> gcc -E .\hello8.c -o hello8.i
PS C:\Users\bruno\Documents\Visual Studio Proyect\copilator> gcc -E .\studio.c -o studio.i
PS C:\Users\bruno\Documents\Visual Studio Proyect\copilator> gcc -S .\hello8.i -o hello8.s
.\hello8.c: In function 'main':
.\hello8.c:3:5: warning: implicit declaration of function 'prontf' [-Wimplicit-function-declaration]
    3 |     prontf("La respuesta es %d\n",i);
      |     ^~~~~~
PS C:\Users\bruno\Documents\Visual Studio Proyect\copilator> gcc -S .\studio.i -o studio.s
.\studio.c: In function 'prontf':
.\studio.c:2:5: warning: implicit declaration of function 'printf' [-Wimplicit-function-declaration]
    2 |     printf("La respuesta es %d\n",i);
      |     ^~~~~~
.\studio.c:2:5: warning: incompatible implicit declaration of built-in function 'printf'
.\studio.c:1:1: note: include '<stdio.h>' or provide a declaration of 'printf'
  +++ |+#include <stdio.h>
    1 | void prontf(const char * restrict s, int i){
PS C:\Users\bruno\Documents\Visual Studio Proyect\copilator> gcc -c .\hello8.s -o hello8.o

PS C:\Users\bruno\Documents\Visual Studio Proyect\copilator> gcc -c .\studio.s -o studio.o       
PS C:\Users\bruno\Documents\Visual Studio Proyect\copilator> gcc  studio.o hello8.o -o hello8.exe
PS C:\Users\bruno\Documents\Visual Studio Proyect\copilator> .\hello8.exe
La respuesta es 42


// con un parametro menos
PS C:\Users\bruno\Documents\Visual Studio Proyect\copilator> .\hello8.exe
La respuesta es 4200720

// con un parametro mas
PS C:\Users\bruno\Documents\Visual Studio Proyect\copilator> .\hello8.exe
La respuesta es 42



