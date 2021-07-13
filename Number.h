//
// Created by shira on 12/19/18.
//

#ifndef EX3_NUMBER_H
#define EX3_NUMBER_H

#include "Expression.h"

class Number :public Expression {
    double value;
public:
    Number(double val);

    virtual double calculate();

    double getValue();

};

#endif //EX3_NUMBER_H
