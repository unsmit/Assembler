#include "lexer.h"
#include <vector>
#include <string>
#include <cctype>

std::vector<Token> Lexer::Tokenize(const std::string &source)
{
    std::string temp;
    std::vector<Token> tokens;

    int line = 0;
    int column = 0;
    for (int i = 0; i < source.size(); i++)
    {
        temp = "";

        Token currToken;

        switch (source[i])
        {
        case ',':
            currToken.type = Token_Type::Comma;
            currToken.text = ",";
            currToken.line = line;
            currToken.column = column;
            tokens.push_back(currToken);
            column++;
            continue;
        case '\n':
            currToken.type = Token_Type::Newline;
            currToken.text = "\n";
            currToken.line = line;
            currToken.column = column;
            tokens.push_back(currToken);
            column = 0;
            line++;
            continue;
        case '#':
            currToken.type = Token_Type::Hash;
            currToken.text = "#";
            currToken.column = column;
            currToken.line = line;
            tokens.push_back(currToken);
            column++;
            continue;
        case '[':
            currToken.type = Token_Type::LeftBracket;
            currToken.text = "[";
            currToken.column = column;
            currToken.line = line;
            tokens.push_back(currToken);
            column++;
            continue;
        case ']':
            currToken.type = Token_Type::RightBracket;
            currToken.text = "]";
            currToken.column = column;
            currToken.line = line;
            tokens.push_back(currToken);
            column++;
            continue;
        case ':':
            currToken.type = Token_Type::Colon;
            currToken.text = ":";
            currToken.column = column;
            currToken.line = line;
            tokens.push_back(currToken);
            column++;
            continue;
        case '!':
            currToken.type = Token_Type::Exclamation;
            currToken.text = "!";
            currToken.column = column;
            currToken.line = line;
            tokens.push_back(currToken);
            column++;
            continue;
        case '/':
            if (i + 1 < source.size() && source[i + 1] == '/')
            {
                while (i < source.size() && source[i] != '\n' && source[i] != '\0')
                {
                    i++;
                    column++;
                }
                i--;
                continue;
            } 
            break;
        case ' ':
            column++;
            continue;
        case '\t':
            column += 4;
            continue;
        case '\r':
            continue;
        }

        int tempColumn = column;
        while (i < source.size() && source[i] != ' ' && source[i] != ',' && source[i] != '\n' && source[i] != '!' && source[i] != ':' && source[i] != '[' && source[i] != ']' && source[i] != '#' && source[i] != '\t' && source[i] != '\r')
        {
            if(i+1 < source.size()){
                if(source[i] == '/' && source[i+1] == '/'){
                    break;
                }
            }
            temp += source[i];
            column++;
            i++;
        }
        i--;

        currToken.column = tempColumn;
        currToken.line = line;
        currToken.text = temp;
        if (!temp.empty() && std::isdigit(temp[0]))
        {
            currToken.type = Token_Type::Number;
            tokens.push_back(currToken);
        }
        else
        {
            currToken.type = Token_Type::Identifier;
            tokens.push_back(currToken);
        }
    }

    Token endToken;
    endToken.type = Token_Type::End;
    endToken.text = "\0";
    endToken.column = column;
    endToken.line = line;
    tokens.push_back(endToken);

    return tokens;
}