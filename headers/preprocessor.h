#ifndef _AZUART_COMPILER_PREPROCESSOR_
#define _AZUART_COMPILER_PREPROCESSOR_

#include "headers.h"
#include "source_file.h"

class PreProcessor {
    struct PreProcessorDefine {
        std::string name;
        std::string value;
    };

    std::vector<SourceFile>& _sources;

    std::vector<SourceFile> _headers;
    std::vector<PreProcessorDefine> _defines;

    std::vector<SourceFile> _processedFiles;

    std::list<std::string> _sourceQueue;
    std::list<std::string> _preprocessedSource;

    bool _ignoreCode;

    std::string ProcessLine(const std::string& line);
    bool IsDirectiveLine(const std::string& line);
    void HandleDirective(const std::string& line);
    std::string ReplaceDefines(const std::string& line);

    bool IncludeFile(const std::string& path);
    bool LoadHeader(const std::string& path);
public:
    PreProcessor(std::vector<SourceFile>& sources);
    ~PreProcessor();
    
    std::vector<SourceFile> Process();

};

#endif