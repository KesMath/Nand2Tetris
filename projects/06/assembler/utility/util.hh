#include <vector>
using namespace std;

uint8_t WHITESPACE = 32;

// All ROM commands within Hack Architecture is 16-bit instruction set
const uint8_t WORD_SIZE = 16;

// for A-instruction @value commands
char* decimal_to_binary(int dec);

//regardless of whitespace index, converts strings of type:
//"     D=D+A      "     ->   "D=D+A"
//"   D  =  D  +  A  "   ->   "D=D+A"
vector<char> strip_leading_and_trailing_whitespace(char* command);

char* to_string(vector<char> charlist);
vector<char*> split(char* command, char* delimiter);