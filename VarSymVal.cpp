//
// Created by shira on 12/26/18.
//

#include "VarSymVal.h"
#include "SymTbl.h"

VarSymVal:: VarSymVal(SymTbl* symTbl,string PointerName){
    this->name = PointerName;
    this->symTbl = symTbl;
}
double VarSymVal:: getVal(){
   return this->symTbl->getSymbol(this->name)->getVal();
}
void VarSymVal::setVal(double value){
   SymVal* symVal= this->symTbl->getSymbol(name);
   symVal->setVal(value);
}