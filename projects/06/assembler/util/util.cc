#include "util.hh"
#include <cassert>
#include <string.h>

uint8_t WHITESPACE = 32;

vector<char> strip_leading_and_trailing_whitespace(char* command){
    int i = 0;
    vector<char> charlist;
    while(command[i] != '\0'){
        if(command[i] != WHITESPACE){
            charlist.push_back(command[i]);
        }
        i++;
    }
    charlist.push_back('\0');
    return charlist;
}

char* to_string(vector<char> charlist){
    char str[charlist.size()];
    int i = 0;
    for(char c : charlist){
        str[i] = c;
        i++;
    }
    return str;
}

int main(){
    //TODO: test below, test linker procedure into driver file
    vector<char> vec1 = strip_leading_and_trailing_whitespace("     D=D+A      ");
    vector<char> vec2 = strip_leading_and_trailing_whitespace("   D  =  D  +  A  ");

    assert(vec1.size() == vec2.size());

    char* str1 = to_string(vec1);
    char* str2 = to_string(vec2);
    assert(strlen(str1) == strlen(str2));
    assert(strcmp(str1, str2));

}