// psiz_zad4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "logger.h"
#include "filegenerator.h"
int main()
{
    srand(time(NULL));
    auto temp = rand() % 88 + 1;
    writeLine("test");
    writeLine(temp + "");

    generateFile("file1.bin", 0x55,100);

    //std::cout << "Hello World!\n";
}

//1. Program konsolowy.Jako dwa argumenty przyjmuje œcie¿ki do plików dla których oblicza wartoœæ BER.
//
//2. Wynik obliczeñ drukowany jest w konsoli(Jako wynik podajemy : Iloœæ porównanych bitów, iloœæ ró¿nych bitów, wynik BER, czas obliczeñ)
//
//3. Program tworzy plik log.txt w którym zapisuje swoje logi.Ka¿da wiadomoœæ rozpoczyna siê od timestamp'a.
//
//4. Test 1: Przygotuj dwa identyczne pliki zawieraj¹ce binarnie zapisan¹ wartoœæ 0x55. Ka¿dy plik po 100 Bajtów.
//
//5. Test 2: Przygotuj dwa pliki ka¿dy po 100 bajtów.Pierwszy zawiera binarnie zapisan¹ wartoœæ 0x55. Drugi plik ró¿ni siê od pierwszego o dowolne 10 bitów.
//
//6. Test 3: Przygotuje dwa pliki ka¿dy po 400 MB.Pierwszy zawiera binarnie zapisan¹ wartoœæ 0x55. Drugi plik zawiera binarnie zapisan¹ wartoœæ 0x50.
//