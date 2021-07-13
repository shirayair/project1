//
// Created by shira on 12/19/18.
//

#ifndef EX3_MULT_H
#define EX3_MULT_H
#include "BinaryExpression.h"

class Mult : public BinaryExpression {
public:
    Mult(Expression *left, Expression *right);

    double calculate();
};

#endif //EX3_MULT_H

