#include <stdint.h>

// ASCII TABLE REF: cs.cmu.edu/~pattis/15-1XX/common/handouts/ascii.html

const int EQUAL = 61;         // '='
const int PLUS = 43;          // '+'
const int MINUS = 45;         // '-'
const int AT_SIGN = 64;       // '@'
const int SEMICOLON = 59;     // ';'
const int LEFT_BRACKET = 40;  // '('
const int RIGHT_BRACKET = 41; // ')'
const int A_INSTRUCTION = 0;  // in Hack Architecture @XXX
const int L_INSTRUCTION = 1;  // in Hack Architecture (XXX)
const int C_INSTRUCTION = 2;  // in Hack Architecture 'dest=comp;jump'
const int NULL_INSTRUCTION = 3;  // uninterpreted instruction