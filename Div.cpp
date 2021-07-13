//
// Created by shira on 12/19/18.
//

#include "Div.h"
#include "Expression.h"

Div::Div(Expression* left,Expression* right):BinaryExpression(left,right){

}
double Div::calculate() {
    return this->getLeft()->calculate() / this->getRight()->calculate();
}