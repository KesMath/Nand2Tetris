#include <map>
#include <cassert>
using namespace std;

class CodeGenerator {
  private:
    map<char*, char*>destMap;
    map<char*, char*>jmpMap;
    map<char*, char*>compMap;
    std::map<char*, char*>::iterator it;

  public:
    char* getDestBinary(char* destCmd){
      char nill[] = "000";
      it = destMap.find(destCmd);
      if(it != destMap.end()){
        return it->first;
      }
      return nill;
    }

    char* getCompBinary(char* compCmd){
      it = compMap.find(compCmd);
      if(it != compMap.end()){
        return it->first;
      }
      return nullptr;
    }

    char* getJumpBinary(char* jmpCmd){
      char nill[] = "000";
      it = jmpMap.find(jmpCmd);
      if(it != jmpMap.end()){
        return it->first;
      }
      return nill;

    }

};

int main(){
	CodeGenerator codeGen;
  	char dest[] = "AM";
	char comp[] = "M-1";
	char comp1[] = "0";
	char jmp[] = "JMP";
	char nil[] = "dummy";

	// sunny day
	printf("%s\n", codeGen.getDestBinary(dest));
	printf("%s\n", codeGen.getCompBinary(comp));
	printf("%s\n", codeGen.getCompBinary(comp1));
	printf("%s\n", codeGen.getJumpBinary(jmp));

	// edge case
	printf("%s\n", codeGen.getDestBinary(nil));
	assert(codeGen.getCompBinary(nil) == nullptr);
	printf("%s\n", codeGen.getJumpBinary(nil));

}