#include "FSParamMap.h"
#include "Lexer.h"
#include "Parser.h"

#include <iostream>
#include <memory>

int main(int argc, char *argv[])
{
    if (argc != 2) {
        std::cerr << "No script" << std::endl;
        return 1;
    }

    try {
        auto fsParamMap = std::make_unique<FSParamMap>();
        auto symTbl = std::make_unique<SymTbl>();
        auto lexer = std::make_unique<Lexer>(argv[1]);
        auto parser = std::make_unique<Parser>(symTbl.get(), lexer->readFromScript(), fsParamMap.get());
        parser->fromStringToExcute();
    } catch (std::exception &e) {
        std::cerr << "std::exception occurred - reason=" << e.what() << std::endl;
        return 2;
    } catch (...) {
        std::cerr << "Unexpected exception was thrown." << std::endl;
        return 2;
    }

    return 0;
}