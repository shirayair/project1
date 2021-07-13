//
// Created by osnat on 12/26/18.
//

#ifndef EX3_SYMTBL_H
#define EX3_SYMTBL_H

#include <string>
#include <map>
#include "SymVal.h"

using namespace std;

class SymTbl {
    map<string, SymVal*> table;
public:
    SymVal* getSymbol(string sym);
    void addSymbol(string symName, SymVal* val);
    bool isSymExist(string sym);
    ~SymTbl();

};


#endif //EX3_SYMTBL_H
