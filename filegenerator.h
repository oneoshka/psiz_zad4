#pragma once
#include <iostream>
#include<string>
#include <fstream>
#include "hamming.h"
#include "logger.h"

void generateFile(std::string fileName, char symbolToSave, int symbolCount, int randomSymbolCount = 0, char randomSymbol=0x22) {
	std::ifstream file;
	srand(time(NULL));
	std::string msg = "";
	int lastPCTcomplete = 0;
	int currPCT = 0;

	file.open(fileName);
	if (file)
	{
		writeLine("File " + fileName + " already exists!");
		return;
	}
	else {
		std::ofstream file(fileName);
		for (size_t i = 0; i < symbolCount; i++)
		{
			if (randomSymbolCount > 0 && rand() % 2 == 0) {
				file << randomSymbol;
				randomSymbolCount--;
			}
			else {
				file << symbolToSave;
				currPCT = ((i * 100)/ symbolCount);
				if(symbolCount > 1000 && currPCT > lastPCTcomplete * 2 || currPCT > lastPCTcomplete + 5) {
					lastPCTcomplete = currPCT;
				msg = "Wrote "+ std::to_string(lastPCTcomplete) + "%" + " of bytes to file " + fileName;
				writeLine(msg);

				}
			}
		}
		
		file.close();
		writeLine(fileName + " generated successfully!" );
	
	}

}