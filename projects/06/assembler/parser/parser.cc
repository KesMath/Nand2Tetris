#include "tokens.hh"
#include <string.h>
#include "../utility/util.hh"

class Parser {
  public:
    uint8_t parseInstructionType(char* buffer){
        if((buffer[0] == LEFT_BRACKET) && (buffer[strlen(buffer) - 1] == RIGHT_BRACKET)){
            return L_INSTRUCTION;
        }
        else if(buffer[0] == AT_SIGN){
            return A_INSTRUCTION;
        }
        else if((strchr(buffer, SEMICOLON) != NULL) || (strchr(buffer, EQUAL) != NULL)){
            return C_INSTRUCTION;
        }
    }

    char* parseSymbol(char* buffer){
        // ONLY CALLED FOR A_INSTRUCTION OR L_INSTRUCTIONS
        // if buffer is (XXX) or 'Label-Type-Instruction', returns symbol XXX
        // else if buffer is @XXX, returns the symbol or decimal XXX
        if(parseInstructionType(buffer) == A_INSTRUCTION){

        }
        else if(parseInstructionType(buffer) == L_INSTRUCTION){

        }
    }

    char* parseDest(char* buffer){
        // returns the symbolic 'dest' part of C_INSTRUCTION
        vector<char*> vec;
        if((parseInstructionType(buffer) == C_INSTRUCTION) && (strchr(buffer, EQUAL) != NULL)){ // need to distinguish which C-type instruction ... namely "dest=comp"
            char equal = EQUAL;
            vec = split(buffer, &equal);
        }
        return vec.front();
    }

    char* parseComp(char* buffer){
        // returns the symbolic 'comp' part of C_INSTRUCTION
        vector<char*> vec;
        if((parseInstructionType(buffer) == C_INSTRUCTION) && (strchr(buffer, EQUAL) != NULL)){ // need to distinguish which C-type instruction ... namely "dest=comp"
            char equal = EQUAL;
            vec = split(buffer, &equal);
            return vec.back();
        }
        else if((parseInstructionType(buffer) == C_INSTRUCTION) && (strchr(buffer, SEMICOLON) != NULL)){ // need to distinguish which C-type instruction ... namely "comp;jmp"
            char semicolon = SEMICOLON;
            vec = split(buffer, &semicolon);
            return vec.front();
        }
    }

    char* parseJump(char* buffer){
        // returns the symbolic 'comp' part of C_INSTRUCTION
        vector<char*> vec;
        if((parseInstructionType(buffer) == C_INSTRUCTION) && (strchr(buffer, SEMICOLON) != NULL)){ // need to distinguish which C-type instruction ... namely "comp;jmp"
            char semicolon = SEMICOLON;
            vec = split(buffer, &semicolon);
        }
        return vec.back();
    }
};

int main(){
    char* aInstruction = "@1234";
    char* labelInstruction = "(memory.alloc$while_end0)";
    char* cInstruction1 = "AM=M-1";
    char* cInstruction2 = "0;JMP";
    Parser parse;
    // for (LABEL) or @XXX type of instructions
    printf("%s\n", parse.parseSymbol(aInstruction));
    printf("%s\n", parse.parseSymbol(labelInstruction));

    // for "D=D-A" type of instructions
    printf("%s\n", parse.parseDest(cInstruction1));
    printf("%s\n", parse.parseComp(cInstruction1));
    // sanity check
    printf("%s\n", parse.parseJump(cInstruction1));

    // for "D;JGT" type of instructions
    printf("%s\n", parse.parseComp(cInstruction2));
    printf("%s\n", parse.parseJump(cInstruction2));
    // sanity check
    printf("%s\n", parse.parseDest(cInstruction2));
}