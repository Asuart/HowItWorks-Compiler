#ifndef _AZUART_COMPILER_
#define _AZUART_COMPILER_

#include "headers.h"
#include "source_file.h"
#include "preprocessor.h"

class Compiler {
    std::vector<SourceFile> _sources;
    std::vector<SourceFile> _preprocessed;

    PreProcessor _preProc;
public:
    Compiler(int argc, char** argv);
    ~Compiler();

    void Start();
    void Preprocess();
};

#endif