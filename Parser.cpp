//
// Created by shira on 12/19/18.
//

#include "Parser.h"
#include "CommandExpressionFactory.h"

Parser::Parser(SymTbl *symTbl, vector<string> strings, FSParamMap* fsParamMap) {
    this->strings = strings;
    this->symTbl = symTbl;
    this->fsParamMap = fsParamMap;
}
void Parser:: fromStringToExcute(){
    auto itr = this->strings.begin();
    auto factory =  new CommandExpressionFactory(symTbl, fsParamMap);
    for(;itr != this->strings.end();(++itr)){
        Expression* temp = factory->createCommandExpression((itr));
        temp->calculate();
        delete temp;
    }
    auto x = factory->getExitCommand();
    x->calculate();
    delete x;
    delete factory;
}

list<Expression*> Parser::fromStringToList() {
    list<Expression*> commands;
    auto itr = this->strings.begin();
    auto factory =  new CommandExpressionFactory(symTbl, fsParamMap);
    for(;itr != this->strings.end();(++itr)){
        Expression* temp = factory->createCommandExpression((itr));
        commands.push_back(temp);
    }
    delete factory;
    return commands;
}
