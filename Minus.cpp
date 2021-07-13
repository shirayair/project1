//
// Created by shira on 12/19/18.
//

#include "Minus.h"


Minus::Minus(Expression* left,Expression* right):BinaryExpression(left,right){}
double Minus::calculate() {
    return this->getLeft()->calculate() - this->getRight()->calculate();
}