#pragma once
#include <string>

enum class Token_Type{
    Identifier, 
    Comma, 
    Hash,
    Number,
    Newline,
    LeftBracket,
    RightBracket,
    Colon,
    Exclamation,
    End
};

struct Token{
    Token_Type type;
    std::string text;
    int line;
    int column;
};