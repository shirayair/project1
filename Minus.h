//
// Created by shira on 12/19/18.
//

#ifndef EX3_MINUS_H
#define EX3_MINUS_H

#include "BinaryExpression.h"


class Minus : public BinaryExpression {
public:
    Minus(Expression *left, Expression *right);

    double calculate();
};

#endif //EX3_MINUS_H
