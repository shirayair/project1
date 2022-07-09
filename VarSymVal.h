//
// Created by shira on 12/26/18.
//

#ifndef EX3_VARSYMVAL_H
#define EX3_VARSYMVAL_H

#include "SymTbl.h"
#include "SymVal.h"

#include <string>

using namespace std;
class VarSymVal : public SymVal
{
    string name;
    SymTbl *symTbl;

   public:
    VarSymVal (SymTbl *symTbl, string PointerName);
    double getVal () override;
    void setVal (double value) override;
};

#endif // EX3_VARSYMVAL_H
