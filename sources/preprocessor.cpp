#include "../headers/preprocessor.h"

PreProcessor::PreProcessor(std::vector<SourceFile>& sources)
    : _sources(sources), _ignoreCode(false) {}

PreProcessor::~PreProcessor(){}
    
std::vector<SourceFile> PreProcessor::Process(){
    for(size_t i = 0; i < _sources.size(); i++){
        //Console::Log(std::to_string(i) + "/" + std::to_string(_sources.size()));
        _sourceQueue = _sources[i].GetSource();
        _preprocessedSource = std::list<std::string>();
        for(; _sourceQueue.size() > 0; ){
            std::string line = _sourceQueue.front();
            _sourceQueue.pop_front();
            line = ProcessLine(line);
            if(IsEmptyString(line)) continue;
            _preprocessedSource.push_back(line);
        }
        Console::Log(ToString(_preprocessedSource));
        _processedFiles.push_back(SourceFile(_sources[i].GetPath() + ".pre", _preprocessedSource));
    }
    return _processedFiles;
}

std::string PreProcessor::ProcessLine(const std::string& line){
    if(IsEmptyString(line)) return "";
    if(IsDirectiveLine(line)){
        HandleDirective(line);
        return "";
    }
    if(_ignoreCode) return "";
    return ReplaceDefines(line);
}

bool PreProcessor::IsDirectiveLine(const std::string& line){
    if(line.length() > 1 && line[0] == '#') return true;
    return false;
}

void PreProcessor::HandleDirective(const std::string& line){
    std::vector<std::string> tokens = TokenizeString(line);
    //Console::Log(std::to_string(tokens.size()));
    //Console::Log(tokens[0]);
    if(tokens[0] == "#include"){
        if(tokens.size() < 2){
            Console::Error("Could not find #include path");
            return;
        } 
        std::string path = PROJECT_PATH + StripPath(tokens[1]);
        IncludeFile(path);
    } else if (tokens[0] == "#import"){

    } else if (tokens[0] == "#define"){

    } else if (tokens[0] == "#undef"){

    } else if (tokens[0] == "#if"){

    } else if (tokens[0] == "#else"){

    } else if (tokens[0] == "#elif"){

    } else if (tokens[0] == "#ifdef"){

    } else if (tokens[0] == "#ifndef"){

    } else if (tokens[0] == "#endif"){

    } else if (tokens[0] == "#line"){
        //lineNum = tokens[1];
    } else if (tokens[0] == "#error"){

    } else {
        Console::Error("Undefined preprocessor directive: " + tokens[0]);
    }
}

std::string PreProcessor::ReplaceDefines(const std::string& line){
    return line;
}

bool PreProcessor::IncludeFile(const std::string& _path){
    if(!LoadHeader(_path)) {
        Console::Error("Failed to include file: " + _path);
        return false;
    }
    for(size_t i = 0; i < _headers.size(); i++){
        if(_headers[i].GetPath() == _path){
            std::list<std::string> src = _headers[i].GetSource();
            for(;src.size() > 0;){
                std::string line = src.back();
                src.pop_back();
                _sourceQueue.push_front(line);
            }
            return true;
        }
    }
    Console::Error("Failed to include file: " + _path);
    return false;
}

bool PreProcessor::LoadHeader(const std::string& _path){
    for(size_t i = 0; i < _headers.size(); i++){
        if(_headers[i].GetPath() == _path){
            return true;
        }
    }
    SourceFile src;
    if(!src.LoadFile(_path)) return false;
    _headers.push_back(src);
    return true;
}