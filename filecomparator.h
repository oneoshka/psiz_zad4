#pragma once
#include<string>;
#include<fstream>;
#include "logger.h"
#include "hamming.h"
#include <filesystem>

int getFileSize(std::string path) {
	return std::filesystem::file_size(path);
}


void CompareFiles(std::string file1, std::string file2) {
	std::string dateStart = pretty_time();
	std::string dateEnd;
	std::string msg;
	int file1Size = getFileSize(file1);
	int file2size = getFileSize(file2);
	int currentPCT = 0;
	int lastPCTcomplete = 0;
	
	std::ifstream _file1(file1, std::ios::binary | std::ios::in);
	std::ifstream _file2(file2, std::ios::binary | std::ios::in);
	long long unsigned int numOfBits = 0, bitErrorRate = 0,counter = 0;
	char x{};
	char y{};

	if (!_file1 || !_file2) {
		writeLine("Cant find files");
		return;
	}
	if (file1Size != file2size) {
		writeLine("Different size of files!");
		return;
	}

	writeLine("Comparison starts...");

	while (!_file1.eof()) {
		_file1 >> x;
		_file2 >> y;

		if (_file1.eof()) { break; }
		numOfBits += 8;
		bitErrorRate = hammingDistance(x, y) + bitErrorRate;
		counter++;
		currentPCT = ((counter * 100) / file1Size);
		//writeLine(std::to_string(counter * 100));
		if (file1Size > 1000 && currentPCT > lastPCTcomplete) {
			lastPCTcomplete = currentPCT;
			msg = "Compared " + std::to_string(lastPCTcomplete) + "%" + " of bytes ";
			writeLine(msg);

		}
			

	}

	dateEnd = pretty_time();

	writeLine(std::format("Comparison of {0} and {1} complete! Results:",file1,file2));
	printResult(dateStart, dateEnd, bitErrorRate, numOfBits);


}



