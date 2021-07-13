//
// Created by shira on 12/19/18.
//

#ifndef EX3_PARSER_H
#define EX3_PARSER_H

#include <vector>
#include <string>
#include <list>
#include "SymTbl.h"
#include "CommandExpression.h"
#include "FSParamMap.h"

using namespace std;
class Parser {
    vector<string> strings;
    SymTbl* symTbl;
    FSParamMap* fsParamMap;
public:
    Parser(SymTbl* symTbl,vector<string> strings, FSParamMap* fsParamsMap);
    void fromStringToExcute();
    list<Expression*> fromStringToList();

};
#endif //EX3_PARSER_H
