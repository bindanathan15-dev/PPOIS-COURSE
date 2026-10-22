@echo off
:: Script de compilation industrielle pour le Lab 1 de PPOIS
title BSUIR Compiler Tool - Lab1

echo ====================================================
echo    COMPILATION DU CODE C++ DE NATHAN EN COURS...
echo ====================================================

:: Localisation du compilateur MSVC de Visual Studio (chemin standard)
call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"

:: Compilation des fichiers du dossier
cl /EHsc Main.cpp Vector3D.cpp Set.cpp /Fe:lab1_executable.exe

if %errorlevel% neq 0 (
    echo [ERROR] La compilation a echoue. Verifiez la syntaxe C++.
    pause
    exit /b %errorlevel%
)

echo [✓] Compilation reussie avec succes !
echo.
echo ====================================================
echo    LANCEMENT DE L'APPLICATION DANS LE SHELL...
echo ====================================================
echo.

:: Execution immediate du programme dans la fenetre cmd
lab1_executable.exe

pause
