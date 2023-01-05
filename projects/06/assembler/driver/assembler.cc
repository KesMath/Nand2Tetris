#include <stdio.h>
#include <stdlib.h>
#include "../binary/codegen.cc"
#include "../parser/parser.cc"

const uint8_t COMMENT = 47;

const uint8_t ZERO = 48;
const uint8_t ONE = ZERO + 1;

const uint8_t NUL_BYTE = 0; // '\0'
const string HACK_BINARY_EXTENSION = ".hack";
const string HACK_ASM_EXTENSION = ".asm";

// assembler logic will ignore lines starting with this
bool ignoreLine(char* line){
    if((line[0] == CARRIAGE_RETURN)
    || (line[0] == COMMENT && line[1] == COMMENT)
    || (line[0] == NUL_BYTE)){
        return true;
    }
    return false;
}

bool isCharSetBinary(string bin);
int offsetOfNewLine(FILE *fstream);

int main(int argc, char *argv[])
{
    if(argc != 2){
        printf("Please provide the filepath to to the assembly source code...\n");
        exit(-1);
    }

    FILE *assembly_file = fopen(argv[1], "r");
    if(assembly_file == NULL){
        printf("Unable to open file at path: %s\n", argv[1]);
        exit(-1);
    }

    string exeName = argv[1];
    exeName.erase(exeName.find(HACK_ASM_EXTENSION), exeName.rfind(HACK_ASM_EXTENSION)); // removing '.asm' name
    exeName += HACK_BINARY_EXTENSION;
    FILE *executable_file = fopen(exeName.c_str(), "w");
    if(executable_file == NULL){
        printf("Unable to create executable file");
        exit(-1);
    }

    //##################################################################################
    // ####### First Pass to populate SymbolTable with programmer-defined labels #######
    //##################################################################################

    //##################################################################################
    // Second Pass to create executable ################################################
    //##################################################################################

    // NOTE: we cannot assume the number of characters (or size of bytes) per line in order to allocate on to a buffer in advance
    // so we must use fgetc() (supplemented with a counter) for safer approach until NEWLINE is met
    char* buffer = NULL;
    Parser parse;
    CodeGenerator codeGen;
    do{
        int newlineOffset = offsetOfNewLine(assembly_file) + 1;

        if(newlineOffset == -1){
            break;
        }
        buffer = (char*) calloc(1, newlineOffset);

        if(buffer == NULL){
            printf("Unable to allocate memory for program usage...\n");
            exit(0);
        }

        // rewind file position indicator (*newlineOffset times*) so buffer can consume all characters inbetween using fgets()
        // Reference of negative offsets to move file pointer backwards
        // https://www.oreilly.com/library/view/c-in-a/0596006977/re96.html
        fseek(assembly_file, (-1) * newlineOffset, SEEK_CUR);

        // as a side effect, fast-forwarding file position indicator will be done by fgets() 
        //so we can proceed to next line without being infinitely stuck reading first line
        fgets(buffer, newlineOffset, assembly_file);
        
        // only processing lines with instructions
        if(!ignoreLine(buffer)){
            printf("Buffer: %s\n", (char*)buffer);
            //printf("Size of buffer: %lu\n", string(buffer).size());
            vector<char> instructionChars = strip_leading_and_trailing_whitespace(buffer);
            string command = to_string(instructionChars);

            // determine instruction type
            // IMPROVEMENT POINTS FOR EFFICIENCY: leverage pointers (which will mutate contents at that address)
            // instead of having to pass-by-value which creates a number of disposable global variables
            // REFERENCE: https://blog.penjee.com/passing-by-value-vs-by-reference-java-graphical/ 
            string parsedCmd;
            string binOut;
            uint8_t instructionType = parse.parseInstructionType(&command[0]);

            if(instructionType == A_INSTRUCTION){
                parsedCmd = parse.parseSymbol(&command[0]);
                binOut = decimal_to_binary(atoi(parsedCmd.c_str()));
                assert(binOut[0] == ZERO);
            }
            else if(instructionType == L_INSTRUCTION){
                // handled by symbol table

            }
            else if(instructionType == C_INSTRUCTION){
                // parse and get codegen mapping
                string compBin;
                string destBin;
                string jmpBin;
                string startBits = "111";
                vector<string> parseCmds;
                if(parse.isAssignmentInstruction(&command[0])){
                    parseCmds = parse.parseAssignmentInstruction(command);
                    printf("parseCmds Size: %lu\n", parseCmds.size());
                    printf("parseCmds[0]: %s\n", parseCmds[0].c_str());
                    printf("parseCmds[1]: %s\n", parseCmds[1].c_str());

                    destBin = codeGen.getDestBinary(parseCmds[0]);
                    printf("destBin: %s\n", destBin.c_str());
                    compBin = codeGen.getCompBinary(parseCmds[1]);
                    printf("compBin: %s\n", compBin.c_str());
                    jmpBin = "000";                    
                }
                else if(parse.isJumpInstruction(&command[0])){
                    parseCmds = parse.parseJumpInstruction(command);
                    compBin = codeGen.getCompBinary(parseCmds[0]);
                    jmpBin = codeGen.getJumpBinary(parseCmds[1]);
                    destBin = "000";
                }
                char aBit = codeGen.getABit(parseCmds[1]);
                binOut = startBits + aBit + compBin + destBin + jmpBin;
            }
        
            // write binary output to new file
            //FIXME: 
            // leading whitespace on binOut
            printf("BinOut: %s\n", binOut.c_str());
            printf("BinOut Size: %lu\n", binOut.size());
            assert(binOut.size() == WORD_SIZE);
            assert(isCharSetBinary(binOut));
            
            fprintf(executable_file, "%s\n", binOut.c_str());
        }
        free(buffer); 
    } while(fgetc(assembly_file) != EOF);


    fclose(assembly_file);
    fclose(executable_file);
    exit(0);
}

int offsetOfNewLine(FILE *fstream){
    int cout = 0;
    char ch;
    while((ch = fgetc(fstream)) != '\n'){
        // must account for EOF edge case since
        // this function executes before 'readline' loop in main()  
        if(ch == EOF){
            cout = -1;
            return cout;
        }
        cout++;
    }
    return cout;
}

bool isCharSetBinary(string bin){
    for(int i = 0; i < bin.size(); i++){
        if((bin[i] != ZERO) && (bin[i] != ONE)){
            return false;
        }
    }
    return true;
}