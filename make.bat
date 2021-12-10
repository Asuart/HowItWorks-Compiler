@echo off

set prg_name=main.exe

set compiler=g++
set flags=-g3 -Wall
set sources=main.cpp sources/compiler.cpp sources/console.cpp sources/preprocessor.cpp sources/source_file.cpp sources/tools.cpp
set out=-o %prg_name%

set test_arguments=test_project/main.cpp test_project/math.cpp

if "%1" == "" (
    @echo on
    %compiler% %flags% %sources% %out%
    @echo off
)

if "%1" == "run" (
    @echo on
    %compiler% %flags% %sources% %out%
    .\%prg_name%
    @echo off
)

if "%1" == "test" (
    @echo on
    %compiler% %flags% %sources% %out%
    .\%prg_name% %test_arguments%
    @echo off
)

if "%1" == "clear" (
    @echo on
    del *.o *.exe
    @echo off
)