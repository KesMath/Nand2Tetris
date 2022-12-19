#include <stdio.h>
#include <stdlib.h>
#include "../utility/util.hh"


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

    //##################################################################################
    // ####### First Pass to populate SymbolTable with programmer-defined labels #######
    //##################################################################################

    // NOTE: we cannot assume the number of characters (or size of bytes) per line in order to allocate on to a buffer in advance
    // so we must use fgetc() (supplemented with a counter) for safer approach until NEWLINE is met
    char* buffer = NULL;
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
        printf("Buffer: %s\n", (char*)buffer);
    } while(fgetc(assembly_file) != EOF);

    free(buffer);
    fclose(assembly_file);
    exit(0);

    //##################################################################################
    // Second Pass to create executable ################################################
    //##################################################################################
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