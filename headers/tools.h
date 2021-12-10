#ifndef _AZUART_COMPILER_TOOLS_
#define _AZUART_COMPILER_TOOLS_

#include "headers.h"

std::string ToString(const std::list<std::string>& lines);

inline bool IsChar(char c);

bool IsEmptyString(const std::string& str);

std::vector<std::string> TokenizeString(const std::string& str);

#endif