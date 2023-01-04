#include <vector>
using namespace std;

// All ROM commands within Hack Architecture is 16-bit instruction set
const uint8_t WORD_SIZE = 16;
const uint8_t CARRIAGE_RETURN = 13;

// for A-instruction @value commands
string decimal_to_binary(int dec);

//regardless of whitespace index, converts strings of type:
//"     D=D+A      "     ->   "D=D+A"
//"   D  =  D  +  A  "   ->   "D=D+A"
vector<char> strip_leading_and_trailing_whitespace(char* command);

char* to_string(vector<char> charlist);
vector<string> split(string command, string delimiter);
bool is_charInStr(char* str, char c);