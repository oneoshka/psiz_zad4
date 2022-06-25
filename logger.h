#pragma once
#include <string>
#include <iostream>
#include <format>
#include <chrono>
#include <ctime>
#include <format>
#include <time.h>
#include <fstream>


template <typename T>
static int to_ms(const std::chrono::time_point<T>& tp)
{
    auto dur = tp.time_since_epoch();
    return static_cast<int>(duration_cast<std::chrono::milliseconds>(dur).count());
}

static std::string pretty_time(std::string format="%Y-%m-%d %H:%M:%S")
{
    auto tp = std::chrono::system_clock::now();
    std::time_t current_time = std::chrono::system_clock::to_time_t(tp);

    std::tm* time_info = std::localtime(&current_time);

    char buffer[128];

    int string_size = strftime(
        buffer, sizeof(buffer),
        format.data(),
        time_info
    );

    int ms = to_ms(tp) % 1000;

    string_size += std::snprintf(
        buffer + string_size, sizeof(buffer) - string_size,""
    );

    return std::string(buffer, buffer + string_size);
}


void writeLine(std::string msg, bool toFile=true,std::string fileName="log.txt") {
    std::string line = "[" + pretty_time() + "] - " + msg;
    std::cout << line << '\n';
    if (toFile) {
        std::ofstream file;
        file.open(fileName, std::ios_base::app);
        file << line + "\n";
        file.close();
    }
    
}

void printResult(std::string dateStart, std::string dateEnd, int bitErrorRate, int numOfBits) {
   std::string longString = std::format(R""""(RESULTS:
Comparison start: {2}
Comparison end:   {3}
Number of bits: {0}
Bit error rate: {1}

)"""",numOfBits,bitErrorRate,dateStart,dateEnd);
   writeLine(longString);
}


