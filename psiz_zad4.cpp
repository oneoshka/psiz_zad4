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

//1. Program konsolowy.Jako dwa argumenty przyjmuje �cie�ki do plik�w dla kt�rych oblicza warto�� BER.
//
//2. Wynik oblicze� drukowany jest w konsoli(Jako wynik podajemy : Ilo�� por�wnanych bit�w, ilo�� r�nych bit�w, wynik BER, czas oblicze�)
//
//3. Program tworzy plik log.txt w kt�rym zapisuje swoje logi.Ka�da wiadomo�� rozpoczyna si� od timestamp'a.
//
//4. Test 1: Przygotuj dwa identyczne pliki zawieraj�ce binarnie zapisan� warto�� 0x55. Ka�dy plik po 100 Bajt�w.
//
//5. Test 2: Przygotuj dwa pliki ka�dy po 100 bajt�w.Pierwszy zawiera binarnie zapisan� warto�� 0x55. Drugi plik r�ni si� od pierwszego o dowolne 10 bit�w.
//
//6. Test 3: Przygotuje dwa pliki ka�dy po 400 MB.Pierwszy zawiera binarnie zapisan� warto�� 0x55. Drugi plik zawiera binarnie zapisan� warto�� 0x50.
//