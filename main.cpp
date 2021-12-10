#include "headers/headers.h"
#include "headers/compiler.h"

int main(int argc, char** argv){
    std::cout << "Azuart Compiler Start" << std::endl;
    Compiler compiler(argc, argv);
    compiler.Preprocess();
    return 0;
}