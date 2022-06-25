// psiz_zad4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "logger.h"
#include "filegenerator.h"
#include "filecomparator.h"
void main(int argc, char* argv[])
{
    

    if (argc == 3) {
        writeLine("RUNNING Comparison for 2 files from commandLine! ...");
        generateFile(argv[1], 0x55, 100);
        generateFile(argv[2], 0x55, 100);
        CompareFiles(argv[1], argv[2]);
        return;
    }

    if (argc == 2 && std::string(argv[1]) == "test1") {
        writeLine("RUNNING TEST 1!! ...");
        generateFile("Test1File1.bin", 0x55, 100);
        generateFile("Test1File2.bin", 0x55, 100);
        CompareFiles("Test1File1.bin", "Test1File2.bin");
        return;
    }
    if (argc == 2 && std::string(argv[1]) == "test2") {
        writeLine("RUNNING TEST 2!! ...");
        generateFile("test2File1.bin", 0x55, 100);
        generateFile("test2File2.bin", 0x55, 100, 10, 0x22);
        CompareFiles("test2File1.bin","test2File2.bin");
        return;
    }
    if (argc == 2 && std::string(argv[1]) == "test3") {
        writeLine("RUNNING TEST 3!! It can take about 8 mins...");
        generateFile("test3_BIG_File1.bin", 0x55, 1024 * 1024 * 400);
        generateFile("test3_BIG_File2.bin", 0x50, 1024 * 1024 * 400);
        CompareFiles("test3_BIG_File1.bin", "test3_BIG_File2.bin");
        return;
    }
    writeLine("Unknown arguments or bad ammount of arguments");
    writeLine("argc:" +std::to_string(argc));
    for (int i = 0; i < argc; ++i) {
        std::cout <<"argv:"<<i << ":" << argv[i] << "\n";

    }
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