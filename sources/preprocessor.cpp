#include "../headers/preprocessor.h"

PreProcessor::PreProcessor(std::vector<SourceFile>& sources)
    : _sources(sources), _ignoreCode(false) {}

PreProcessor::~PreProcessor(){}
    
std::vector<SourceFile> PreProcessor::Process(){
    for(s32 i = 0; i < _sources.size(); i++){
        //Console::Log(std::to_string(i) + "/" + std::to_string(_sources.size()));
        _sourceQueue = _sources[i].GetSource();
        _preprocessedSource = std::list<std::string>();
        for(; _sourceQueue.size() > 0; ){
            std::string line = _sourceQueue.front();
            _sourceQueue.pop_front();
            if(IsEmptyString(line)) continue;
            line = ProcessLine(line);
            if(IsEmptyString(line)) continue;
            _preprocessedSource.push_back(line);
        }
        Console::Log(ToString(_preprocessedSource));
    }
}

std::string PreProcessor::ProcessLine(const std::string& line){
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