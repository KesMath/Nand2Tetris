#include <vector>
using namespace std;

// for A-instruction @value commands
char* decimal_to_binary(int dec);

//regardless of whitespace index, converts strings of type:
//"     D=D+A      "     ->   "D=D+A"
//"   D  =  D  +  A  "   ->   "D=D+A"
vector<char> strip_leading_and_trailing_whitespace(char* command);

char* to_string(vector<char> charlist);
vector<char*> split(char* command, char* delimiter);