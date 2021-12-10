#ifndef _AZUART_COMPILER_SOURCE_FILE_
#define _AZUART_COMPILER_SOURCE_FILE_

#include "headers.h"

class SourceFile {
    std::list<std::string> _source;
    std::string _path;
public:
    SourceFile();
    SourceFile(const std::string& path);
    SourceFile(const std::string& path, const std::list<std::string>& source);
    ~SourceFile();

    bool LoadFile(const std::string& path);
    bool ReloadFile();
    bool SaveFile();
    bool SaveFileCopy(const std::string& path);
    void SetSource(const std::list<std::string>& source);
    void SetPath(const std::string& path);

    std::list<std::string> GetSource();
    std::string GetSourceAsString();
    std::string GetPath();
};

#endif