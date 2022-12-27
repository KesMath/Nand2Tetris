#include <stdint.h>

// ASCII TABLE REF: cs.cmu.edu/~pattis/15-1XX/common/handouts/ascii.html

uint8_t EQUAL = 61;         // '='
uint8_t PLUS = 43;          // '+'
uint8_t MINUS = 45;         // '-'
uint8_t AT_SIGN = 64;       // '@'
uint8_t SEMICOLON = 59;     // ';'
uint8_t LEFT_BRACKET = 40;  // '('
uint8_t RIGHT_BRACKET = 41; // ')'
uint8_t A_INSTRUCTION = 0;  // in Hack Architecture @XXX
uint8_t L_INSTRUCTION = 1;  // in Hack Architecture (XXX)
uint8_t C_INSTRUCTION = 2;  // in Hack Architecture dest=comp;jump
