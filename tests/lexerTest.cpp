#include <iostream>
#include <string>
#include <vector>
#include "lexer.h"

std::string tokenTypeToString(Token_Type type)
{
    switch (type)
    {
    case Token_Type::Identifier:
        return "Identifier";
    case Token_Type::Number:
        return "Number";
    case Token_Type::Comma:
        return "Comma";
    case Token_Type::Hash:
        return "Hash";
    case Token_Type::Newline:
        return "Newline";
    case Token_Type::LeftBracket:
        return "LeftBracket";
    case Token_Type::RightBracket:
        return "RightBracket";
    case Token_Type::Colon:
        return "Colon";
    case Token_Type::Exclamation:
        return "Exclamation";
    case Token_Type::End:
        return "End";
    }

    return "Unknown";
}

void testLexer(const std::string &name, const std::string &source)
{
    std::cout << "\n========== " << name << " ==========\n";

    Lexer lexer;
    std::vector<Token> tokens = lexer.Tokenize(source);

    for (const Token &token : tokens)
    {
        std::string text = token.text;

        if (token.type == Token_Type::Newline)
        {
            text = "\\n";
        }

        std::cout << "Type: " << tokenTypeToString(token.type)
                  << " | Text: \"" << text << "\""
                  << " | Line: " << token.line
                  << " | Column: " << token.column
                  << '\n';
    }
}

int main()
{
    testLexer("Basic ADD", "ADD X1, X2, X3");

    testLexer("Immediate Value", "MOV X1, #100");

    testLexer("Label", "loop:\nADD X1, X2, X3");

    testLexer("Memory Addressing", "LDUR X1, [X2, #8]");

    testLexer("Exclamation", "STUR X1, [X2, #8]!");

    testLexer("Inline Comment", "ADD X1, X2, X3 // addition");

    testLexer("Comment Without Space", "ADD X1, X2, X3//addition");

    testLexer("Full Line Comment", "// This is a comment\nMOV X1, #10");

    testLexer("Malformed Number", "MOV X1, #123abc");

    testLexer("Invalid Register", "ADD X1/X2, X3");

    testLexer("Multiple Instructions",
              "MOV X1, #100\n"
              "ADD X2, X1, X3\n"
              "SUB X4, X2, X1");

    testLexer("Windows Line Endings",
              "MOV X1, #100\r\n"
              "ADD X2, X1, X3\r\n");

    testLexer("Tabs", "\tADD\tX1,\tX2,\tX3");

    testLexer("Empty Source", "");

    testLexer("Only Comment", "// Nothing here");

    return 0;
}