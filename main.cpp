#include <iostream>
#include "Lexer.h"
#include "Parser.h"
#include "FSParamMap.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        throw "No script.\n";
    }

    FSParamMap* fsParamMap = new FSParamMap();
    SymTbl* symTbl = new SymTbl();
    Lexer* lexer = new Lexer(argv[1]);
    auto x = lexer->readFromScript();
    Parser* parser = new Parser(symTbl, x, fsParamMap);
    parser->fromStringToExcute();
    delete symTbl;
    delete lexer;
    delete parser;
    delete fsParamMap;

}