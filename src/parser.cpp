#include "parser.h"
#include <vector>
#include <string>

using namespace std;

int Parser::parseLine(std::string line, Instruction *instruction){
    string currToken = "";
    if(line[0] == ',' || line[0] == ' '){
        return 0;
    }

    int charIndex;
    int tokenIndex = 0;
    int lineIndex = 0;

    for(int i = 0; i < line.size(); i++) {

        // handle edge cases later
        if(line[i] != ' ' && line[i] != ',' && i != 0){
            continue;
        }

        if(i == 0){
            while(line[i] != ' ' && line[i] != ',' && i != 0){
                currToken = currToken + line[i];
                i++;
            }
            instruction->operation = currToken;
        } else {
            while(line[i] != ' ' && line[i] != ',' && i != 0){
                currToken = currToken + line[i];
                i++;
            }
            instruction->operands.push_back(currToken);
        }

        

    }
}

bool Parser::validateInstruction(Instruction *instruction){

}

bool Parser::validateOps(Instruction *instruction){

}

bool Parser::validateImmediate(const std::string &token, int bits){


}