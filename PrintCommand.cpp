//
// Created by osnat on 12/29/18.
//

#include <iostream>
#include "PrintCommand.h"
PrintCommand :: PrintCommand(string str, SymTbl* symTbl1){
    this->str = str;
    this->symTbl = symTbl1;
}
void PrintCommand::execute() {
    if(symTbl->isSymExist(str)) {
        auto val = symTbl->getSymbol(str)->getVal();
        cout << val << endl;
    } else {
        cout<<this->str<<endl;
    }
}