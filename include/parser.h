#pragma once
#include <string>
#include <vector>

struct Instruction{
    std::string operation;
    std::vector<std::string> operands;
}; 

class Parser{
    public:
        Instruction instruction;
        int parseLine(std::string line, Instruction *instruction);
        bool validateInstruction(Instruction *instruction);
        bool validateOps(Instruction *instruction);
        bool validateImmediate(const std::string& token, int bits);
};