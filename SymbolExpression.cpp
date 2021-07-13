//
// Created by shira on 12/26/18.
//

#include "SymbolExpression.h"

SymbolExpression::SymbolExpression(SymTbl *froMap, string nameVar){
    this->var = froMap;
   this->nameVar = nameVar;
}
double SymbolExpression:: calculate(){
  return this->var->getSymbol(nameVar)->getVal();
}
