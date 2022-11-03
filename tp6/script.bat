@echo off
flex Ç.l
echo "lex.yy.c"
pause
gcc lex.yy.c -o compilador.exe
echo "compilador.exe"
pause
compilador.exe brunoElMejor.text
echo "se analiza el text"
pause  
del lex.yy.c
del compilador.exe
echo "borrando ..."
pause