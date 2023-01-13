#include <map>
#include <string>

using namespace std;

class CodeGenerator {
  private:
    map<string, string>destMap;
    map<string, string>jmpMap;
    map<string, string>compMap;
    std::map<string, string>::iterator it;

  public:
	CodeGenerator(){
		// destination mapping
		destMap["M"]   = "001";
		destMap["D"]   = "010";
		destMap["MD"]  = "011";
		destMap["A"]   = "100";
		destMap["AM"]  = "101";
		destMap["AD"]  = "110";
		destMap["AMD"] = "111";

		// compute mapping: (when a = 0)
		compMap["0"]    = "101010";
		compMap["1"]    = "111111";
		compMap["-1"]   = "111010";
		compMap["D"]    = "001100";
		compMap["A"]    = "110000";
		compMap["!D"]   = "001101";
		compMap["!A"]   = "110001";

		compMap["-D"]   = "001111";
		compMap["-A"]   = "110011";
		compMap["D+1"]  = "011111";
		compMap["A+1"]  = "110111";
		compMap["D-1"]  = "001110";
		compMap["A-1"]  = "110010";

		compMap["D+A"]  = "000010";
		compMap["D-A"]  = "010011";
		compMap["A-D"]  = "000111";
		compMap["D&A"]  = "000000";
		compMap["D|A"]  = "010101";

		// compute mapping: (when a = 1)
		compMap["M"]    = "110000";
		compMap["!M"]   = "110001";
		compMap["-M"]   = "110011";
		compMap["M+1"]  = "110111";
		compMap["M-1"]  = "110010";
		compMap["D+M"]  = "000010";
		compMap["D-M"]  = "010011";
		compMap["M-D"]  = "000111";
		compMap["D&M"]  = "000000";
		compMap["D|M"]  = "010101";

		// jump mapping
		jmpMap["JGT"] = "001";
		jmpMap["JEQ"] = "010";
		jmpMap["JGE"] = "011";
		jmpMap["JLT"] = "100";
		jmpMap["JNE"] = "101";
		jmpMap["JLE"] = "110";
		jmpMap["JMP"] = "111";
	}
    string getDestBinary(string destCmd){
      char nill[] = "000";
      it = destMap.find(destCmd);
      if(it != destMap.end()){
        return it->second;
      }
      return nill;
    }

    string getCompBinary(string compCmd){
      it = compMap.find(compCmd);
      if(it != compMap.end()){
        return it->second;
      }
	  printf("%s not found\n", compCmd.c_str());
      return "";
    }

    string getJumpBinary(string jmpCmd){
      char nill[] = "000";
      it = jmpMap.find(jmpCmd);
      if(it != jmpMap.end()){
        return it->second;
      }
      return nill;

    }
	
	char getABit(string compCmd){
		// According to Figure 4.3, 
		// all comp mnemonics that contain 'M' will return a = 1 else, a = 0;
		// This soln can base this 'quick-and-dirty' approach rather than an elegant one
		// (i.e. map<char, map<string, string>> => '0', map<"A-1", "110010">, '1', map<"M-1", "110010">)
		
		uint8_t bitIdentifier = 77; // 'M'
		for(int i = 0; i < compCmd.size(); i++){
			if(compCmd[i] == bitIdentifier){
				return '1';
			}
		}
		return '0';
	}
};

// int main(){
// 	CodeGenerator codeGen;
//   	string dest = "AM";
// 	string comp = "M-1";
// 	string comp1 = "0";
// 	string jmp = "JMP";
// 	string nil = "dummy";

// 	// sunny day
// 	printf("%s\n", codeGen.getDestBinary(dest).c_str());
// 	printf("%s\n", codeGen.getCompBinary(comp).c_str());
// 	printf("%s\n", codeGen.getCompBinary(comp1).c_str());
// 	printf("%s\n", codeGen.getJumpBinary(jmp).c_str());

// 	// edge case
// 	printf("%s\n", codeGen.getDestBinary(nil).c_str());
// 	printf("%s\n", codeGen.getCompBinary(nil).c_str());
// 	printf("%s\n", codeGen.getJumpBinary(nil).c_str());

// 	// bitIdentifier
// 	printf("%c\n", codeGen.getABit(comp));
// 	printf("%c\n", codeGen.getABit(comp1));
// }