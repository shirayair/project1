//
// Created by osnat on 12/26/18.
//

#ifndef EX3_PATHVAL_H
#define EX3_PATHVAL_H


#include <string>
#include "SymVal.h"
#include "SymTbl.h"
#include "FSParamMap.h"
#include <vector>
#include "Client.h"
using namespace std;

class PathSymVal: public SymVal {
    string path;
    FSParamMap* fsParamMap;

public:
    PathSymVal(string path, FSParamMap* fsParamMap1);
    double getVal() override;
    void setVal(double value) override;

};


#endif //EX3_PATHVAL_H
