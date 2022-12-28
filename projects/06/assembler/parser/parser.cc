#include "tokens.hh"
#include <string.h>
#include "../utility/util.hh"

class Parser {
  public:
    uint8_t parseInstructionType(char* command){
        if((command[0] == LEFT_BRACKET) && (command[strlen(command) - 1] == RIGHT_BRACKET)){
            return L_INSTRUCTION;
        }
        else if(command[0] == AT_SIGN){
            return A_INSTRUCTION;
        }
        else if((strchr(command, SEMICOLON) != NULL) || (strchr(command, EQUAL) != NULL)){
            return C_INSTRUCTION;
        }
        else{
            return NULL_INSTRUCT;
        }
    }

    char* parseSymbol(char* command){
        // ONLY CALLED FOR A_INSTRUCTION OR L_INSTRUCTIONS
        // if command is (XXX) or 'Label-Type-Instruction', returns symbol XXX
        // else if command is @XXX, returns the symbol or decimal XXX
        printf("inside func");
        vector<char> charlist;
        if(parseInstructionType(command) == A_INSTRUCTION){
            int i = 1; // exclude AT_SIGN
            printf("inside A");
            while(command[i] != '\0'){
               charlist.push_back(command[i]);
            }
            charlist.push_back('\0');
            return to_string(charlist);
        }
        else if(parseInstructionType(command) == L_INSTRUCTION){
            int i = 1; // exlcude LEFT_BRACKET
            while(command[i] != '\0'){
               charlist.push_back(command[i]);
            }
            charlist.pop_back(); //remove trailing RIGHT_BRACKET
            charlist.push_back('\0');
            return to_string(charlist);
        }
        return nullptr;
    }

    char* parseDest(char* command){
        // returns the symbolic 'dest' part of C_INSTRUCTION
        vector<char*> vec;
        if((parseInstructionType(command) == C_INSTRUCTION) && (is_charInStr(command, EQUAL))){ // need to distinguish which C-type instruction ... namely "dest=comp"
            char equal = EQUAL;
            //FIXME
            vec = split(command, &equal);
            return vec.front();
        }
        return nullptr;
    }

    char* parseComp(char* command){
        // returns the symbolic 'comp' part of C_INSTRUCTION
        vector<char*> vec;
        if((parseInstructionType(command) == C_INSTRUCTION) && (is_charInStr(command, EQUAL))){ // need to distinguish which C-type instruction ... namely "dest=comp"
            char equal = EQUAL;
            //FIXME
            vec = split(command, &equal);
            return vec.back();
        }
        else if((parseInstructionType(command) == C_INSTRUCTION) && (is_charInStr(command, SEMICOLON))){ // need to distinguish which C-type instruction ... namely "comp;jmp"
            char semicolon = SEMICOLON;
            vec = split(command, &semicolon);
            return vec.front();
        }
        return nullptr;
    }

    char* parseJump(char* command){
        // returns the symbolic 'comp' part of C_INSTRUCTION
        vector<char*> vec;
        if((parseInstructionType(command) == C_INSTRUCTION) && (is_charInStr(command, SEMICOLON))){ // need to distinguish which C-type instruction ... namely "comp;jmp"
            char semicolon = SEMICOLON;
            //FIXME
            vec = split(command, &semicolon);
            return vec.back();
        }
        return nullptr;
    }
};

// //FOR UNIT TESTING PURPOSES - uncomment and run 'make parse'
int main(){
    char* aInstruction = "@1234";
    char* labelInstruction = "(memory.alloc$while_end0)";
    char* cInstruction1 = "AM=M-1";
    char* cInstruction2 = "0;JMP";
    Parser parse;
    // for (LABEL) or @XXX type of instructions
    //printf("%s\n", parse.parseSymbol(aInstruction));
    //printf("%s\n", parse.parseSymbol(labelInstruction));

    // // for "D=D-A" type of instructions
    printf("%s\n", parse.parseDest(cInstruction1));
    //printf("%s\n", parse.parseComp(cInstruction1));
    // // sanity check
    //printf("%s\n", parse.parseJump(cInstruction1));

    // // for "D;JGT" type of instructions
    //printf("%s\n", parse.parseComp(cInstruction2));
    //printf("%s\n", parse.parseJump(cInstruction2));
    // // sanity check
    //printf("%s\n", parse.parseDest(cInstruction2));
}