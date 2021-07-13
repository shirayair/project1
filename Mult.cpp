//
// Created by shira on 12/19/18.
//

#include "Mult.h"

Mult::Mult(Expression *left, Expression *right):BinaryExpression(left,right){}

double Mult::calculate() {
    auto rightI = this->getRight()->calculate();
    auto leftI = this->getLeft()->calculate();

    return  leftI*rightI ;
}