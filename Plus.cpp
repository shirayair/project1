//
// Created by shira on 12/19/18.
//

#include "Plus.h"

Plus::Plus(Expression *left, Expression *right) : BinaryExpression(left, right){}

double Plus::calculate() {
    return this->getLeft()->calculate() + this->getRight()->calculate();
}