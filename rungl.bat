@echo off
setlocal

if "%~1"=="" (
    echo Usage: rungl your_file.c
    exit /b 1
)

set FILENAME=%~1
set OUTFILE=%~n1.exe

gcc -IC:/msys64/mingw64/include %FILENAME% ^
    -LC:/msys64/mingw64/lib ^
    -lfreeglut -lglew32 -lopengl32 -lglu32 -o %OUTFILE%

if errorlevel 1 (
    echo Compilation failed!
    exit /b 1
)

echo Running %OUTFILE%...
%OUTFILE%
