//
// Created by osnat on 12/26/18.
//

#ifndef EX3_DOUBLESYMVAL_H
#define EX3_DOUBLESYMVAL_H


#include "SymVal.h"

class DoubleSymVal: public SymVal {
    double value;
public:
    DoubleSymVal(double val);
    double getVal() override;
    void setVal(double value);
};


#endif //EX3_DOUBLESYMVAL_H
