//
// Created by shira on 12/19/18.
//

#ifndef EX3_DIV_H
#define EX3_DIV_H
#include "BinaryExpression.h"
#include "Expression.h"

class Div : public BinaryExpression
{
public:
    Div(Expression *expLeft, Expression *expRight);
    double calculate();
};

#endif // EX3_DIV_H
