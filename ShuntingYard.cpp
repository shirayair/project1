//
// Created by shira on 12/19/18.
//

#include "ShuntingYard.h"
#include "Number.h"
#include "Mult.h"
#include "Div.h"
#include "Minus.h"
#include "Plus.h"
#include "SymbolExpression.h"


ShuntingYard::ShuntingYard(SymTbl* expVar) {
    this->expVar = expVar;
    initializeMap();
}

void ShuntingYard::initializeMap() {
    this->prcedence.insert(pair<char, int>('/', 2));
    this->prcedence.insert(pair<char, int>('*', 2));
    this->prcedence.insert(pair<char, int>('+', 1));
    this->prcedence.insert(pair<char, int>('-', 1));
    this->prcedence.insert(pair<char, int>(')', 0));
    this->prcedence.insert(pair<char, int>('(', 0));
}

int ShuntingYard::precedence(char operation) {
    if (this->prcedence.count(operation)) {
        return this->prcedence.at(operation);
    }
    throw "invalid operation!";
}

Expression *ShuntingYard::applyOp(Expression *val1, Expression *val2, char operation) {
    switch (operation) {
        case '*':
            return new Mult(val1, val2);
        case '/':
            return new Div(val1, val2);
        case '+':
            return new Plus(val1, val2);
        case '-':
            return new Minus(val1, val2);
    }
}

// Function that returns value of
// expression after evaluation.
Expression *ShuntingYard::createExpression(string tokens) {
    int i;

    // stack to store integer values.
    stack<Expression *> values;

    // stack to store operators.
    stack<char> ops;

    for (i = 0; i < tokens.length(); i++) {
        if(tokens[i]== '-'&& (!isdigit(tokens[i-1]) && !isalpha(tokens[i-1]))  &&isdigit(tokens[i+1])){
            Expression* val = new Minus(new Number(0),new Number((tokens[i+1]-'0')));
            values.push(val);
            i+=2;
            continue;
        }
        if(tokens[i] == '-' && !(isalpha(tokens[i-1]) || isdigit(tokens[i-1])) && isalpha(tokens[i+1])) {
            string varName = "";
            i++;
            while(this->prcedence.find(tokens[i]) == this->prcedence.end()) {
                varName+=tokens[i];
                i++;
            }
            Expression* val = new Minus(new Number(0),new SymbolExpression(this->expVar,varName));
            values.push(val);
            i--;
            continue;
        }
        // Current token is a whitespace,
        // skip it.
        if (tokens[i] == ' ')
            continue;

            // Current token is an opening
            // brace, push it to 'ops'
        else if (tokens[i] == '(') {
            ops.push(tokens[i]);
        }

            // Current token is a number, push
            // it to stack for numbers.
        else if (isdigit(tokens[i])) {
            int val = 0;

            // There may be more than one
            // digits in number.
            while (i < tokens.length() &&
                    (isdigit(tokens[i]) || tokens[i] == '.')) {
                val = (val * 10) + (tokens[i] - '0');
                i++;
            }
            i--;
            Expression *num = new Number(val);
            values.push(num);
        }else if(isalpha((tokens[i]))){
            string var = "";
            while(i < tokens.length() &&(
            isalpha(tokens[i])||isdigit(tokens[i])||tokens[i] == '_')){
                var += tokens[i];
                i++;
            }
            i--;
            Expression* varExp = new SymbolExpression(this->expVar,var);
            values.push(varExp);
        }

            // Closing brace encountered, solve
            // entire brace.
        else if (tokens[i] == ')') {
            while (!ops.empty() && ops.top() != '(') {
                Expression *val2 = values.top();
                values.pop();

                Expression *val1 = values.top();
                values.pop();

                char op = ops.top();
                ops.pop();

                values.push(applyOp(val1, val2, op));
            }

            // pop opening brace.
            ops.pop();
        }

            // Current token is an operator.
        else {
            // While top of 'ops' has same or greater
            // precedence to current token, which
            // is an operator. Apply operator on top
            // of 'ops' to top two elements in values stack.
            while (!ops.empty() && precedence(ops.top())
                                   >= precedence(tokens[i])) {
                Expression *val2 = values.top();
                values.pop();

                Expression *val1 = values.top();
                values.pop();

                char op = ops.top();
                ops.pop();

                values.push(applyOp(val1, val2, op));
            }

            // Push current token to 'ops'.
            ops.push(tokens[i]);
        }
    }

    // Entire expression has been parsed at this
    // point, apply remaining ops to remaining
    // values.
    while (!ops.empty()) {
        Expression *val2 = values.top();
        values.pop();

        Expression *val1 = values.top();
        values.pop();

        char op = ops.top();
        ops.pop();

        values.push(applyOp(val1, val2, op));
    }

    // Top of 'values' contains result, return it.
    return values.top();
}
