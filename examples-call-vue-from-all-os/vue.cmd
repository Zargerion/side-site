@ECHO off 
REM 0 сверху отключение вывода каждой строчки в командную строку

GOTO start REM 1 отправление к строчке кода :start

:find_dp0 REM 5 обозначение точки :find_dp0
SET dp0=%~dp0 & REM 6 в переменную dp0 записывается параметр "%~dp0" который записывает в эту переменную путь относительно прямо вот этого скрипта
EXIT /b REM 7 возвращение к последней выпосленной строке с CALL (call = вызов)

:start REM 2 обозначение точки :старт

REM 3 далее от SETLOCAL до endLocal все переменные обозначаемые через SET будет видны точки внутри этой области (от SETLOCAL до endLocal)
SETLOCAL

CALL :find_dp0 REM 4 оправка к строчке :find_dp0

IF EXIST "%dp0%\node.exe" ( REM 8 если относительно этого скрипта существует (EXIST) файл node.exe делай все что в скобках ниже
  SET "_prog=%dp0%\node.exe" & REM 9 запись пути до node.exe в переменную _prog
) ELSE ( REM 10 иначе делай все что в скобках ниже
  SET "_prog=node" & REM 11 записать значения переменной node из системных переменных виндовс в переменную _prog
  SET PATHEXT=%PATHEXT:;.JS;=;% & REM 12 перезаписывает переменную PATHEXT уберая из нее .JS (PATHEXT используется для запуска программы из командной строки без указания расширения)

)

REM 13 завершение локальной области видимости переменных, все переменные пропе тех что начинаются с _ и PATHEXT (переменная винды) начиная со строки SETLOCAL были удалены.
REM 13 "goto #_undefined_# 2>NUL || title %COMSPEC%" надо для того, чтобы обойти тупое завешения .cmd скриптов. Намеренное использование бага системы CMD.
REM 13 ну, а после наконец вывод двух аргументов для командной строки. ону хранятся в двух переменных %_prog% %dp0% это два тупи до двух файлов.
endLocal & goto #_undefined_# 2>NUL || title %COMSPEC% & "%_prog%"  "%dp0%\node_modules\@vue\cli\bin\vue.js" %* 
REM 13 грубо говоря, скрипт одной командой позволяет выводить в командную строку путь до node и его аргумент при вызове vue.js
REM 13 то есть в командной строке пишется node vue.js. node запускает файлы .js на винде, если файл написан сразу после него. 