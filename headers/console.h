#ifndef _AZUART_COMPILER_CONSOLE_
#define _AZUART_COMPILER_CONSOLE_

#include <string>
#include <iostream>
#include "configs.h"

class Console{
public:
    static void Error(const std::string errorMessage);
    static void Log(const std::string logMessage);
};

#endif