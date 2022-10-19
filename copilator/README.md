PS C:\Users\bruno\Documents\Visual Studio Proyect\copilator> gcc -E .\hello2.c -o hello2.i
PS C:\Users\bruno\Documents\Visual Studio Proyect\copilator> gcc -S .\hello2.i -o hello2.s
.\hello2.c: In function 'main':
.\hello2.c:4:5: warning: implicit declaration of function 'prontf'; did you mean 'printf'? [-Wimplicit-function-declaration]
    4 |     prontf("La respuesta es %d\n");
      |     ^~~~~~
      |     printf
.\hello2.c:4:5: error: expected declaration or statement at end of input




PS C:\Users\bruno\Documents\Visual Studio Proyect\copilator> gcc -E .\hello3.c -o hello3.i
PS C:\Users\bruno\Documents\Visual Studio Proyect\copilator> gcc -S .\hello3.i -o hello3.s
.\hello3.c: In function 'main':
.\hello3.c:5:5: warning: implicit declaration of function 'prontf'; did you mean 'printf'? [-Wimplicit-function-declaration]
    5 |     prontf("La respuesta es %d\n");
      |     ^~~~~~
      |     printf
.\hello3.c:5:5: error: expected declaration or statement at end of input




PS C:\Users\bruno\Documents\Visual Studio Proyect\copilator> gcc -E .\hello4.c -o hello4.i
PS C:\Users\bruno\Documents\Visual Studio Proyect\copilator> gcc -S .\hello4.i -o hello4.s
.\hello4.c: In function 'main':
.\hello4.c:5:5: warning: implicit declaration of function 'prontf'; did you mean 'printf'? [-Wimplicit-function-declaration]
    5 |     prontf("La respuesta es %d\n");
      |     ^~~~~~
      |     printf
PS C:\Users\bruno\Documents\Visual Studio Proyect\copilator> gcc -c .\hello4.s -o hello4.o
PS C:\Users\bruno\Documents\Visual Studio Proyect\copilator> gcc .\hello4.o
c:/c/mingw/bin/../lib/gcc/mingw32/9.2.0/../../../../mingw32/bin/ld.exe: .\hello4.o:hello4.c:(.text+0x1e): undefined reference to `prontf'
collect2.exe: error: ld returned 1 exit status












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



