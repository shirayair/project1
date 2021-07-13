//
// Created by shira on 12/19/18.
//

#ifndef EX3_BINAREYEXPRESSION_H
#define EX3_BINAREYEXPRESSION_H

#include "Expression.h"

class BinaryExpression : public Expression {
protected:
    Expression *left;
    Expression *right;
public:
    BinaryExpression(Expression *left, Expression *right);

    virtual Expression *getLeft();

    virtual Expression *getRight();
    virtual ~BinaryExpression();
};


#endif //EX3_BINAREYEXPRESSION_H
