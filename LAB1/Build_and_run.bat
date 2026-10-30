@echo off
:: Script de compilation securise pour le Lab 1 de PPOIS
title BSUIR Compiler Tool - Lab1

echo ====================================================
echo    COMPILATION DU CODE C++ DE NATHAN EN COURS...
echo ====================================================

:: Force le terminal a utiliser l'encodage universel pour eviter les bugs
chcp 65001 > nul

:: Nettoyage de l'ancien executable s'il existe pour repartir a neuf
if exist lab1_executable.exe del lab1_executable.exe

:: Localisation du compilateur MSVC de Visual Studio (chemin standard)
call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"

:: Compilation chirurgicale des 3 fichiers sources C++
cl /EHsc Main.cpp Vector3D.cpp Set.cpp /Fe:lab1_executable.exe

:: Verification stricte du resultat de la compilation
if %errorlevel% neq 0 (
    echo.
    echo [ERREUR] La compilation a echoue ! Verifiez les messages ci-dessus.
    echo.
    pause
    exit /b %errorlevel%
)

echo.
echo [SUCCESS] Compilation reussie avec succes !
echo ====================================================
echo    LANCEMENT DE L'APPLICATION DANS LE SHELL...
echo ====================================================
echo.

:: Execution immediate du programme
lab1_executable.exe

pause