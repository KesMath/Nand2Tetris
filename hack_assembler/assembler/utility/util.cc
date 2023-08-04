#include "util.hh"
#include <cassert>
#include <bitset>

const uint8_t WHITESPACE = 32;

vector<char> strip_leading_and_trailing_whitespace(char* command){
    int i = 0;
    vector<char> charlist;
    while(command[i] != '\0'){
        if((command[i] != WHITESPACE) && (command[i] != CARRIAGE_RETURN)){
            charlist.push_back(command[i]);
        }
        i++;
    }
    charlist.push_back('\0');
    return charlist;
}

char* strip_inline_comment(char* buffer){
    //NOTE: a comment in this case is just '/' not accurately '//'
    int commentIndex = 0;
    for(long unsigned int i = 0; i < strlen(buffer); i++){
        if(buffer[i] == COMMENT){
            commentIndex = i;
            break;
        }
    }
    if(commentIndex == 0){ // implying no existence of an inline-comment
        return buffer;
    }
    else{
        char* truncatedBuff = (char*) realloc(buffer, commentIndex + 1); // chopping off bytes after index of first comment token is found
        if(truncatedBuff == NULL){
            printf("Unable to re-allocate memory for program usage...\n");
            free(buffer);
            exit(1);
        }
        truncatedBuff[commentIndex] = '\0';
        return truncatedBuff;
    }
}

char* to_string(vector<char> charlist){
    // FIXME: mem leak occurring here!
    char *str = (char*) malloc(charlist.size() + 1);
    if(str == NULL){
        printf("Insufficient heap memory...\n");
        exit(0);
    }
    int i = 0;
    for(char c : charlist){
        str[i] = c;
        i++;
    }
    return str;
}

// NOTE: No requirement to iterate for this use case given that Hack Instruction set
// is simple enough and will always yield vector of size = 2 
vector<string> split(string command, string delimiter){
    vector<string> strList;
    char* str;

    str = strtok(command.data(), delimiter.c_str());
    strList.push_back(str);
    // According to man pages:
    // "The first time that strtok() is called, str should be specified;
    // subsequent calls, wishing to obtain further tokens from the same string, should pass a null pointer instead.
    // The separator string, sep, must be supplied each time, and may change between calls."
    str = strtok(NULL, delimiter.c_str());
    strList.push_back(str);
    return strList;
}

// A-instruction / @value will be between: (0 - Maximum signed 16-bit value = 32,767)
// In base2, A-instruction range is: (0 - 0111111111111111)
string decimal_to_binary(int dec){
    return bitset<WORD_SIZE>(dec).to_string();
}

bool is_charInStr(char* str, char c){
    for(long unsigned int i = 0; i < strlen(str); i++){
        if(str[i] == c){
            return true;
        }
    }
    return false;
}

//FOR UNIT TESTING PURPOSES - uncomment and run 'make util'
// int main(){
//     char cInstruction1[] = "     D=D+A      ";
//     char cInstruction2[] = "   D  =  D  +  A  ";
//     vector<char> vec1 = strip_leading_and_trailing_whitespace(cInstruction1);
//     vector<char> vec2 = strip_leading_and_trailing_whitespace(cInstruction2);

//     // ###########################
//     assert(vec1.size() == vec2.size());

//     char* str1 = to_string(vec1);
//     char* str2 = to_string(vec2);
//     printf("%s\n", str1);
//     printf("%s\n", str2);
//     assert(strlen(str1) == strlen(str2));
//     assert(strcmp(str1, str2) == 0);

//     // ###########################
//     char EQUAL[] = "=";
//     vector<string> vec3 = split(str1, EQUAL);
//     for(string str: vec3){
//         printf("%s\n", str.c_str());
//     }

//     // ###########################
//     string str3 = decimal_to_binary(32767);
//     printf("%s\n", str3.c_str());

//     // ###########################
//     char cInstruction3[] = "A=M-1";
//     printf("Char in Str: %d\n", is_charInStr(cInstruction3, 61));
//     printf("Char in Str: %d\n", is_charInStr(cInstruction3, '?'));
//     // ###########################

//     // ###########################
//     char s[] = "   D=D-M  // D = first number - second number";
//     char* buffer = (char*) malloc(strlen(s) + 1);
//     if(buffer == NULL){
//         printf("unable to allocate buffer...");
//         exit(-1);
//     }
//     strcpy(buffer, s);
//     printf("%s\n", buffer);
//     char* stripped = strip_inline_comment(buffer);
//     printf("%s\n", stripped);
//     printf("Stripped size: %zu\n", strlen(stripped));
//     // ###########################
//     free(str1);
//     free(str2);
//     free(stripped);
// }