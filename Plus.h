//
// Created by shira on 12/19/18.
//

#ifndef EX3_PLUS_H
#define EX3_PLUS_H

#include "BinaryExpression.h"

class Plus : public BinaryExpression {
public:
    Plus(Expression *left, Expression *right);

    virtual double calculate();
};
#endif //EX3_PLUS_H
