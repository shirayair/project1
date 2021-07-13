//
// Created by osnat on 12/26/18.
//

#include <iostream>
#include "SymTbl.h"

SymVal* SymTbl::getSymbol(string sym) {
    if (this->table.find(sym) == table.end()) {
        throw "Symbol name doesn't exist";
    }
    return (this->table[sym]);
}

void SymTbl::addSymbol(string symName, SymVal *val) {
    this->table[symName] = val;
    //cout<< "symbol " << symName<< "added. his val is" << val->getVal()<<endl;
}

bool SymTbl::isSymExist(string sym) {
    if (this->table.find(sym) != table.end()) {
        return true;
    }
    return false;
}

SymTbl::~SymTbl() {
    for(auto symVal: this->table) {
        delete symVal.second;
    }
}