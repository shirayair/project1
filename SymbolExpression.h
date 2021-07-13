//
// Created by shira on 12/26/18.
//

#ifndef EX3_SYMBOLVAR_H
#define EX3_SYMBOLVAR_H
#include "Expression.h"
#include "SymTbl.h"
class SymbolExpression : public Expression {
  SymTbl* var;
  string nameVar;
public:
    SymbolExpression(SymTbl* froMap,string nameVar);
    double calculate();
};


#endif //EX3_SYMBOLVAR_H
