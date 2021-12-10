#include "../headers/source_file.h"

SourceFile::SourceFile() : _path("empty") {}
SourceFile::SourceFile(const std::string& path) : _path("empty") {
    LoadFile(path);
}
SourceFile::SourceFile(const std::string& path, const std::list<std::string>& source) 
    : _path(path), _source(source){}
SourceFile::~SourceFile(){}

bool SourceFile::LoadFile(const std::string& path){
    std::ifstream reader(path, std::ios::in);
    
    if(!reader.is_open()){
        Console::Error("Could not open file: " + path);
        return false;
    }

    std::string line;
    while(std::getline(reader, line)){
        _source.push_back(line);
    }
    reader.close();

    _path = path;
    return true;
}

bool SourceFile::ReloadFile(){
    return LoadFile(_path);
}

bool SourceFile::SaveFile(){
    return SaveFileCopy(_path);
}

bool SourceFile::SaveFileCopy(const std::string& path){
    std::ofstream writer(path, std::ios::out | std::ofstream::trunc);
    if(!writer.is_open()){
        Console::Error("Could not open file: " + path);
        return false;
    }

    std::string source = GetSourceAsString();
    writer.write(source.c_str(), source.length());
    writer.close();

    return true;
}

void SourceFile::SetSource(const std::list<std::string>& source){
    _source = source;
}

void SourceFile::SetPath(const std::string& path){
    _path = path;
}

std::list<std::string> SourceFile::GetSource(){
    return _source;
}

std::string SourceFile::GetSourceAsString(){
    return ToString(_source);
}

std::string SourceFile::GetPath(){
    return _path;
}