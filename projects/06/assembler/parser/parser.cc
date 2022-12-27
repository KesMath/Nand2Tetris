#include "tokens.hh"

class Parser {
  public:
    uint8_t parseInstructionType(char* buffer){
        
    }

    char* parseSymbol(char* buffer){
        // ONLY CALLED FOR A_INSTRUCTION OR L_INSTRUCTIONS
        // if buffer is (XXX) or 'Label-Type-Instruction', returns symbol XXX
        // else if buffer is @XXX, returns the symbol or decimal XXX
        if(parseInstructionType(buffer) == A_INSTRUCTION ||
           parseInstructionType(buffer) == L_INSTRUCTION){

        }
    }

    char* parseDest(char* buffer){
        // returns the symbolic 'dest' part of C_INSTRUCTION
        if(parseInstructionType(buffer) == C_INSTRUCTION){

        }
    }
    char* parseComp(char* buffer){
        // returns the symbolic 'comp' part of C_INSTRUCTION
        if(parseInstructionType(buffer) == C_INSTRUCTION){

        }
    }
    char* parseJump(char* buffer){
        // returns the symbolic 'jump' part of C_INSTRUCTION
        if(parseInstructionType(buffer) == C_INSTRUCTION){

        }
    }
};