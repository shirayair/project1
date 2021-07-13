//
// Created by shira on 12/19/18.
//

#include "BinaryExpression.h"

BinaryExpression::BinaryExpression(Expression *left, Expression *right) {
    this->left = left;
    this->right = right;
}

BinaryExpression::~BinaryExpression() {
    delete this->right;
    delete this->left;
}

Expression *BinaryExpression::getLeft() {
    return this->left;
}

Expression *BinaryExpression::getRight() {
    return this->right;
}