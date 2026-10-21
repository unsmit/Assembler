#pragma once
#include "token.h"
#include <vector>
#include <string>
#include <unordered_map>

class Lexer{
    private:
    
    public:
        std::vector<Token> Tokenize(const std::string &source);
        
};