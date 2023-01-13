#include <map>
#include <string>
#include "../parser/parser.cc"

using namespace std;

// (LABELS) in assembly language is basically the equivalent of method headers
// where we can optionally section out / modularize our code for readability and reusability

// Hence why we need to initially pass through the entire *.asm file (before parsing and running codegen module)
// and map the labels to their respective line numbers so when a jump statement is executed,
// the program counter gets assigned to that line number and the CPU executes that targeted command!

class SymbolTable{

    private:
        map<string, int> table;
        std::map<string, int>::iterator it;
        Parser parse;

    public:
        SymbolTable(){
            table["@SP"]     = 0;
		    table["@LCL"]    = 1;
		    table["@ARG"]    = 2;
		    table["@THIS"]   = 3;
		    table["@THAT"]   = 4;
            table["@R0"]     = 0;
            table["@R1"]     = 1;
            table["@R2"]     = 2;
            table["@R3"]     = 3;
            table["@R4"]     = 4;
            table["@R5"]     = 5;
            table["@R6"]     = 6;
            table["@R7"]     = 7;
            table["@R8"]     = 8;
            table["@R9"]     = 9;
            table["@R10"]    = 10;
            table["@R11"]    = 11;
            table["@R12"]    = 12;
            table["@R13"]    = 13;
            table["@R14"]    = 14;
            table["@R15"]    = 15;
		    table["@SCREEN"] = 16384;
		    table["@KBD"]    = 24576;


        }
        void addEntry(string label, int line_pos){
            it = table.find(label);
            if(it == table.end()){ //iterator returns null when it cannot find the key in question
                table["@" + parse.parseSymbol(label.data())] = line_pos;
            }
        }
        int getAddress(string label){
            it = table.find(label);
            if(it != table.end()){
                return it->second;
            }
            return -1;
        }
};

// FOR UNIT TESTING PURPOSES - uncomment and run 'make table'
// int main(){
//     SymbolTable symbolTable;

//     string str1 = "(memory.alloc$while_end0)";
//     string str2 = "(OUTPUT_FIRST)";
//     string str3 = "(INFINITE_LOOP)";

//     string newKey1 = "@memory.alloc$while_end0";
//     string newKey2 = "@OUTPUT_FIRST";
//     string newKey3 = "@INFINITE_LOOP";

//     symbolTable.addEntry(str1, 16);
//     symbolTable.addEntry(str2, 17);
//     symbolTable.addEntry(str3, 18);

//     printf("%i\n", symbolTable.getAddress(newKey1));
//     printf("%i\n", symbolTable.getAddress(newKey2));
//     printf("%i\n", symbolTable.getAddress(newKey3));
// }