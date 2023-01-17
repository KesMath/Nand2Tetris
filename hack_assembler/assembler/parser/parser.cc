#include "tokens.hh"
#include <string>
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
            return NULL_INSTRUCTION;
        }
    }

    string parseSymbol(char* command){
        // ONLY CALLED FOR A_INSTRUCTION OR L_INSTRUCTIONS
        // if command is (XXX) or 'Label-Type-Instruction', returns symbol XXX
        // else if command is @XXX, returns the symbol or decimal XXX
        string str;
        if(parseInstructionType(command) == A_INSTRUCTION){
            char s [strlen(command) + 1];
            strcpy(s, command);
            str = s;
            str = str.substr(1, str.length() - 1);
        }
        else if(parseInstructionType(command) == L_INSTRUCTION){
            char s [strlen(command) + 1];
            strcpy(s, command);
            str = s;
            str = str.substr(1, str.length() - 2);
        }
        return str;
    }
    vector<string> parseAssignmentInstruction(string command){
        // parses "dest=comp" expressions
        vector<string> vec;
        if(isAssignmentInstruction(command.data())){
            char equal = EQUAL;
            string equalStr(1, equal);
            vec = split(command, equalStr);
        }
        return vec;
    }

    vector<string> parseJumpInstruction(string command){
        // parses "comp;jmp" expressions
        vector<string> vec;
        if(isJumpInstruction(command.data())){
            char semicolon = SEMICOLON;
            string semicolStr(1, semicolon);
            vec = split(command, semicolStr);
        }
        return vec;
    }

    bool isAssignmentInstruction(char* command){
        // returns true for "dest=comp" expressions
        if((parseInstructionType(command) == C_INSTRUCTION) && (is_charInStr(command, EQUAL))){
            return true;
        }
        return false;
    }

    bool isJumpInstruction(char* command){
        // returns true for "comp;jmp" expressions
        if((parseInstructionType(command) == C_INSTRUCTION) && (is_charInStr(command, SEMICOLON))){
            return true;
        }
        return false;
    }
};

// //FOR UNIT TESTING PURPOSES - uncomment and run 'make parse'
// int main(){
//     char aInstruction[] = "@1234";
//     char labelInstruction[] = "(memory.alloc$while_end0)";
//     string cInstruction1 = "AMD=M-1";
//     string cInstruction2 = "0;JMP";

//     Parser parse;
//     // for (LABEL) or @XXX type of instructions
//     printf("%s\n", parse.parseSymbol(aInstruction).c_str());
//     printf("%s\n", parse.parseSymbol(labelInstruction).c_str());

//     //for "D=D-A" type of instructions
//     vector<string> vec0 = parse.parseAssignmentInstruction(cInstruction1);
//     printf("Vector0 Size: %lu\n", vec0.size());
//     for(string str: vec0){
//         printf("%s\n", str.c_str());
//     }

//     // for "D;JGT" type of instructions
//     vector<string> vec1 = parse.parseJumpInstruction(cInstruction2);
//     printf("Vector1 Size: %lu\n", vec1.size());
//     for(string str: vec1){
//         printf("%s\n", str.c_str());
//     }
// }