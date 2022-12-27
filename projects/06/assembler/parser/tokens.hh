#include <stdint.h>

// ASCII TABLE REF: cs.cmu.edu/~pattis/15-1XX/common/handouts/ascii.html

int EQUAL = 61;         // '='
int PLUS = 43;          // '+'
int MINUS = 45;         // '-'
int AT_SIGN = 64;       // '@'
int SEMICOLON = 59;     // ';'
int LEFT_BRACKET = 40;  // '('
int RIGHT_BRACKET = 41; // ')'
int A_INSTRUCTION = 0;  // in Hack Architecture @XXX
int L_INSTRUCTION = 1;  // in Hack Architecture (XXX)
int C_INSTRUCTION = 2;  // in Hack Architecture 'dest=comp;jump'
int NULL_INSTRUCT = 3;  // uninterpreted instruction