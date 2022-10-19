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


