#include "../headers/tools.h"

std::string ToString(const std::list<std::string>& lines){
    std::string str = "";
    for(auto it = lines.begin(); it != lines.end(); it++) str += *it + "\n";
    return str;
}

inline bool IsChar(char c){
    return (c > 0x20 && c < 0x7f);
}

bool IsEmptyString(const std::string& str){
    if(str.length() == 0) return true;
    for(s32 i = 0; i < str.length(); i++)
        if(IsChar(str[i])) return false;
    return true;
}

std::vector<std::string> TokenizeString(const std::string& str){
    std::vector<std::string> tokens;
    std::string token = "";
    for(s32 i = 0; i < str.length(); i++){
        if(IsChar(str[i])) {
            token += str[i];
        } else if(!IsEmptyString(token)){
            tokens.push_back(token);
            token = "";
        }
    }

    return tokens;
}