//
// Created by osnat on 12/26/18.
//

#include "DefineVarCommand.h"
#include "DoubleSymVal.h"
#include "Expression.h"
#include "PathSymVal.h"
#include "VarSymVal.h"

DefineVarCommand::DefineVarCommand(SymTbl *symTbl, string varName, Expression* varVal) {
    this->symTbl = symTbl;
    this->varName = varName;
    this->varVal = varVal;
}
DefineVarCommand::DefineVarCommand(SymTbl *symTbl, string varName, string path,FSParamMap* fsParamMap1) {
    this->path = path;
    this->varName = varName;
    this->symTbl = symTbl;
    this->fsParamMap1 = fsParamMap1;
}
DefineVarCommand::DefineVarCommand(SymTbl *symTbl, string varName, string PointerName){
    this->symTbl = symTbl;
    this->varName = varName;
    this->PointerName = PointerName;
}
void DefineVarCommand::execute() {
    if(this->PointerName !=""){
        symTbl->addSymbol(varName,new VarSymVal(symTbl,PointerName));
    }else if(this->path != ""){
        symTbl->addSymbol(varName,new PathSymVal(path,fsParamMap1));
    }else if(this->varVal == NULL){
        symTbl->addSymbol(this->varName, new DoubleSymVal(0));
    }else {
        double enterVal = this->varVal->calculate();
        //for now only add double vars
        symTbl->addSymbol(this->varName, new DoubleSymVal(enterVal));
    }
}
DefineVarCommand::~DefineVarCommand(){
    if(varVal != nullptr) {
        delete this->varVal;
    }
}