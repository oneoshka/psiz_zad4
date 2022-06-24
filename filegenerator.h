#pragma once
#include <iostream>
#include<string>
#include <fstream>
#include "hamming.h"


void generateFile(std::string fileName, char symbolToSave, int symbolCount) {
	std::ifstream file;

	file.open(fileName);
	if (file)
	{
		throw;
	}
	else {
		std::ofstream file(fileName);
		for (size_t i = 0; i < symbolCount; i++)
		{
			file << symbolToSave;

		}
		file.close();
	
	}

}