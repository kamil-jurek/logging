#pragma once

#include <iostream>
#include <vector>
#include <sstream>

#include "date.hpp"

#define TRACE(...) kjtrace::trace(__LINE__, __FILE__, __func__, __VA_ARGS__)

namespace kj
{   
    static std::vector<std::string> splitString(const std::string& s, char delimiter)
    {
        std::vector<std::string> tokens;
        std::string token;
        std::istringstream tokenStream(s);
        while (std::getline(tokenStream, token, delimiter))
        {
            tokens.push_back(token);
        }
        
        return tokens;
    } 
    
} //kj 

namespace kjtrace {
    template <typename... Args>
    static void trace(int line, const char* filePath, 
                        const char* functionName, Args&&... args)
    {   
        using namespace date;
        using namespace kj;

        auto currentTime = std::chrono::system_clock::now();
        auto splittedFilePath = kj::splitString(std::string(filePath), '/');
        std::string fileName = splittedFilePath[splittedFilePath.size()-1];

        std::ostringstream stream;   
        stream << "[" << currentTime << "] [" << fileName << "(" << line << ") " << functionName << "()] [trace]: \"";
        (stream << ... << std::forward<Args>(args)) << "\"\n";

        std::cout << stream.str();
    }
} // kjtrace
