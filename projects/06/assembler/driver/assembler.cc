#include <stdio.h>
#include <stdlib.h>


int indexOfNewLine(FILE *fstream);

int main(int argc, char *argv[])
{
    if(argc != 2){
        printf("Please provide the filepath to to the assembly source code...");
        exit(-1);
    }

    FILE *assembly_file = fopen(argv[1], "r");

    if(assembly_file == NULL){
        printf("Unable to open file at path: %s", argv[1]);
        exit(-1);
    }

    // first pass to populate SymbolTable with programmer-defined labels

    // NOTE: we cannot assume the number of characters (or size of bytes) per line in order to allocate on to a buffer in advance with fgets() approach
    // so we must use fgetc() (supplemented with a counter) for safer approach until NEWLINE is met
    while(char ch = fgetc(assembly_file) != EOF){
        int newlineOffset = indexOfNewLine(assembly_file);
        void* buffer = calloc(1, newlineOffset);
        // rewind file position indicator (*newlineOffset times*) so buffer can consume all characters inbetween using fgets()
        // as a side effect, fast-forward file position indicator will be done by fgets() so we can proceed to next line without being infinitely stuck reading first line
    }


    // second pass to create executable

}

int indexOfNewLine(FILE *fstream){
    int cout = 0;
    while(char ch = fgetc(fstream) != '\n'){
        cout++;
    }
    return cout;
}