#include "../headers/compiler.h"

Compiler::Compiler(int argc, char** argv) : _preProc(_sources){
    for(s32 i = 1; i < argc; i++){
        //Console::Log(std::string(argv[i]));
        _sources.push_back(SourceFile(std::string(argv[i])));
    }
}

Compiler::~Compiler(){

}

void Compiler::Start(){
    Preprocess();
}

void Compiler::Preprocess(){
    _preProc.Process();
}