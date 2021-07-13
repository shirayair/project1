//
// Created by shira on 12/20/18.
//

#include "CommandExpressionFactory.h"
#include "CommandExpression.h"
#include "OpenDataServerCommand.h"
#include "AssignCommand.h"
#include "DefineVarCommand.h"
#include "Parser.h"
#include "WhileCommand.h"
#include "IfCommand.h"
#include "ExitCommand.h"
#include "CommandSleep.h"
#include "ConnectCommand.h"
#include "PrintCommand.h"


CommandExpressionFactory:: CommandExpressionFactory(SymTbl* symTbl1, FSParamMap* fsParamMap){
    this->symTbl = symTbl1;
    this->fsParamMap1 = fsParamMap;
    this->shuntingYard = new ShuntingYard(this->symTbl);
}

CommandExpressionFactory::~CommandExpressionFactory() {
    delete this->shuntingYard;
}


Expression* CommandExpressionFactory:: createCommandExpression(vector<string> ::iterator &it){
    if(symTbl->isSymExist(*it)) {
        ++it;
    }

    if((*it) == "openDataServer"){
        return this->getOpenDateServer(it);
    }
    if((*it) == "=") {
        return getAssignCommand(it);
    }
    if((*it) == "var") {
        return getDefineVarCommand(it);
    }
    if((*it) == "while") {
        return getWhileCommand(it);
    }
    if((*it) == "if") {
        return getIfCommand(it);
    }
    if((*it) == "sleep") {
        return getSleepCommand(it);
    }
    if((*it) == "connect") {
        return getConnectCommand(it);
    }
    if((*it) == "print") {
        return getPrintCommand(it);
    }

}

Expression* CommandExpressionFactory:: getOpenDateServer(vector<string> ::iterator &it){
    Expression* port  = this->shuntingYard->createExpression(*(++it));
    Expression* hertz  = this->shuntingYard->createExpression(*(++it));
    return new CommandExpression(new OpenDataServerCommand(port, hertz, fsParamMap1));
}

Expression* CommandExpressionFactory::getAssignCommand(vector<string>::iterator &it) {
    string symbolName = *(it-1);
    Expression* exp = this->shuntingYard->createExpression(*(++it));
    return new CommandExpression(new AssignCommand(this-> symTbl,symbolName,exp));
}

Expression* CommandExpressionFactory::getDefineVarCommand(vector<string>::iterator &it) {
    string varName = *(++it);
    if(*(++it) == "="){
        if(*(it+1) == "bind") {
            ++it;
            if((*(++it)).front() == '/') {
                return new CommandExpression(new DefineVarCommand(this->symTbl, varName, *it, fsParamMap1));
            } else {
                return new CommandExpression(new DefineVarCommand(symTbl, varName,*it));
            }
        }

        Expression *exp = this->shuntingYard->createExpression(*(++it));
        return new CommandExpression(new DefineVarCommand(this->symTbl, varName, exp));
    }
    return new CommandExpression(new DefineVarCommand(this->symTbl,varName, nullptr));
}

Expression* CommandExpressionFactory::getWhileCommand(vector<string> ::iterator &it) {
    //extract condition params
    Expression* exp1 =this->shuntingYard->createExpression(*(++it));
    string sign = *(++it);
    Expression* exp2 =this->shuntingYard->createExpression(*(++it));
    if(*(++it) != "{") {
        throw "Invalid while condition.";
    }
    //build WhileCommand
    auto whileCommand = new WhileCommand(exp1, exp2, sign);
    //extract and update his list of commands
    auto blockStrings = extractBlockStrings(it);
    Parser* parser = new Parser(this->symTbl, blockStrings, this->fsParamMap1);
    auto commands = parser->fromStringToList();
    whileCommand->addCommand(commands);
    delete parser;
    return new CommandExpression(whileCommand);
}

Expression* CommandExpressionFactory:: getIfCommand(vector<string> ::iterator &it){
    //extract condition params
    Expression* exp1 =this->shuntingYard->createExpression(*(++it));
    string sign = *(++it);
    Expression* exp2 =this->shuntingYard->createExpression(*(++it));
    if(*(++it) != "{") {
        throw "Invalid while condition.";
    }
    //build IfCommand
    auto ifCommand = new IfCommand(exp1, exp2, sign);
    //extract and update his list of commands
    auto blockStrings = extractBlockStrings(it);
    Parser* parser = new Parser(this->symTbl, blockStrings, this->fsParamMap1);
    auto commands = parser->fromStringToList();
    ifCommand->addCommand(commands);
    delete parser;
    return new CommandExpression(ifCommand);
}


vector<string> CommandExpressionFactory::extractBlockStrings(vector<string>  ::iterator &it){
    vector<string> blockStrings;
    while (*(++it) != "}") {
        blockStrings.push_back(*it);
    }
    return blockStrings;
}

Expression* CommandExpressionFactory:: getSleepCommand(vector<string> ::iterator &it) {
    Expression* sleep = this->shuntingYard->createExpression(*(++it));
    return new CommandExpression(new CommandSleep(sleep));
}

Expression* CommandExpressionFactory::getConnectCommand(vector<string> ::iterator &it) {
    string ip = (*(++it));
    Expression* port = this->shuntingYard->createExpression(*(++it));
    return new CommandExpression( new ConnectCommand(ip, port));
}

Expression* CommandExpressionFactory:: getPrintCommand(vector<string> ::iterator &it) {
    string toPrint = *(++it);
    return new CommandExpression(new PrintCommand(toPrint, this->symTbl));
}

Expression* CommandExpressionFactory::getExitCommand() {
    return new CommandExpression(new ExitCommand());
}



