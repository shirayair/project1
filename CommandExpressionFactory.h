//
// Created by shira on 12/20/18.
//

#ifndef EX3_COMMANDEXPRESSIONFACTORY_H
#define EX3_COMMANDEXPRESSIONFACTORY_H


#include "Expression.h"
#include "Command.h"
#include "ShuntingYard.h"
#include "SymTbl.h"
#include "FSParamMap.h"

class CommandExpressionFactory{
    ShuntingYard* shuntingYard;
    SymTbl* symTbl;
    FSParamMap* fsParamMap1;
    vector<string> extractBlockStrings(vector<string>  ::iterator &it);
public:
    explicit CommandExpressionFactory(SymTbl* symTbl1, FSParamMap* fsParamMap);
    Expression*  createCommandExpression(vector<string>  ::iterator &it);
    Expression* getOpenDateServer(vector<string> ::iterator &it);
    Expression* getAssignCommand(vector<string> ::iterator &it);
    Expression* getDefineVarCommand(vector<string> ::iterator &it);
    Expression* getWhileCommand(vector<string> ::iterator &it);
    Expression* getIfCommand(vector<string> ::iterator &it);
    Expression* getSleepCommand(vector<string> ::iterator &it);
    Expression* getConnectCommand(vector<string> ::iterator &it);
    Expression* getPrintCommand(vector<string> ::iterator &it);
    Expression* getExitCommand();
    ~CommandExpressionFactory();

};


#endif //EX3_COMMANDEXPRESSIONFACTORY_H
