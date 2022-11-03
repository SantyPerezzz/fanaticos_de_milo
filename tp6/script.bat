@echo off
flex .\milo.l
echo "crea el lex.yy.c"
pause
bison -dy .\parser.y
echo "crea el y.tab.c y el y.tab.h"
pause
gcc .\lex.yy.c .\y.tab.c -o compilador.exe
echo "crea el compilador.exe"
pause
echo "se analiza el text:"
compilador.exe < brunoElMejor.txt
pause  
echo "borrando ..."
del lex.yy.c
del y.tab.c
del y.tab.h
del compilador.exe
pause