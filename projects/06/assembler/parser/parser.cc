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
    vector<char*> parseCInstruction(char* command){
        // parses "dest=comp" expressions
        vector<char*> vec;
        if((parseInstructionType(command) == C_INSTRUCTION) && (is_charInStr(command, EQUAL))){
            char equal = EQUAL;
            vec = split(command, &equal);
        }
        return vec;
    }

    // FIXME: '0' in '0;JMP' is not able to be parsed oddly enough ... will just have to account for it in driver file for now
    vector<char*> parseJumpInstruction(char* command){
        // parses "comp;jmp" expressions
        vector<char*> vec;
        // if(command[0] == '0'){
        //     vec.push_back("0");
        // }
        if((parseInstructionType(command) == C_INSTRUCTION) && (is_charInStr(command, SEMICOLON))){
            char semicolon = SEMICOLON;
            vec = split(command, &semicolon);
        }
        return vec;
    }
};

// //FOR UNIT TESTING PURPOSES - uncomment and run 'make parse'
int main(){
    //char aInstruction[] = "@1234";
    //char labelInstruction[] = "(memory.alloc$while_end0)";

    char cInstruction1[] = "AMD=M-1";

    char cInstruction2[] = "0;JMP";
    Parser parse;
    // for (LABEL) or @XXX type of instructions
    //printf("%s\n", parse.parseSymbol(aInstruction));
    //printf("%s\n", parse.parseSymbol(labelInstruction));

    //for "D=D-A" type of instructions
    vector<char*> vec0 = parse.parseCInstruction(cInstruction1);
    printf("%s\n", vec0[0]);
    printf("%s\n", vec0[1]);

    // for "D;JGT" type of instructions
    vector<char*> vec1 = parse.parseJumpInstruction(cInstruction2);
    printf("%s\n", vec1[0]);
    printf("%s\n", vec1[1]);
}