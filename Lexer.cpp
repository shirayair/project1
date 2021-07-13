//
// Created by shira on 12/19/18.
//

#include "Lexer.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <ctype.h>
#include "Lexer.h"

typedef string::iterator stritr;

Lexer::Lexer(string fileName) {
    this->fileName = fileName;
}

vector<string> Lexer::readFromScript() {
    vector<string> orders;
    ifstream readFile;
    readFile.open(fileName);
    if (readFile.is_open()) {
        string line;
        while (getline(readFile, line)) {
            auto x = this->toEnterAccording(line);
            orders.insert(orders.end(), x.begin(), x.end());
        }
        readFile.close();
    }
    return orders;
}

bool Lexer::isOperator(char c) {
    return c == '*' || c == '+' || c == '/' || c == '-' || c == '(' || c == ')';
}

vector<string> Lexer::toEnterAccording(string line) {
    vector<string> orders;
    stritr b = line.begin();
    stritr e = line.end();
    while (b != e) {
        if (*b == ' ') {
            b++;
            continue;
        }
        if(isSign(*b)){
            string s ="";
            s+=*b;
            if((*(b + 1)) == '=') {
                s+= *(++b);
            }
            orders.push_back(s);
        }
        if (*b == ',') {
            string p = "";
            p += *b;
            orders.push_back(p);
        }
        if (isDigit(*b)) {
            string val = "";
            while (isDigit(*b) || *b == '.') {
                val += *b;
                b++;
            }
            b--;
            orders.push_back(val);
        } else if (isOperator(*b)) {
            string s = "";
            s += *b;
            orders.push_back(s);
        } else if (isalpha(*b)) {
            string val = "";
            while (isalpha(*b) || isdigit(*b) || (*b) == '_') {
                val += *b;
                b++;
            }
            b--;
            orders.push_back(val);
        }

        if (*b == '\"') {
            b++;
            string val = "";
            while (*b != '\"') {
                val += *b;
                b++;
            }
            orders.push_back(val);
        }
        if (*b == '=') {
            string a = "";
            a += *b;
            if(*(b+1) == '=') {
                a+= *(++b);
            }
            orders.push_back(a);
        }
        if (*b == '{') {
            string w = "";
            w += *b;
            orders.push_back(w);
        }
        if (*b == '}') {
            string w = "";
            w += *b;
            orders.push_back(w);
        }
        b++;
    }


    return this->seperateVector(orders);
}


bool Lexer::ifToSeperate(char c, char s) {
    if (isOperator(c) && isDigit(s)) {
        return true;
    }

    if (isDigit(c) && (isOperator(s))) {
        return true;
    }
    return false;
}

bool Lexer::isSign(char c) {
    return c == '>' || c == '<' ||  c == '!';
}

vector<string> Lexer::seperateVector(vector<string> scriptSpleet) {
    vector<string> newSplit;
    string val = "";
    int index = 0;
    std::vector<string>::iterator itr;
    for (itr = scriptSpleet.begin(); itr != scriptSpleet.end(); itr++) {
        stritr b = itr->begin();
        if (isalpha(*b)) {
            if((itr+1)!= scriptSpleet.end() && isOperator((*(itr+1)).front())){
                val+= *(itr);
            }else {
                newSplit.push_back(*itr);
            }
        } else if (isDigit(*b)) {
            if (index != 0) {
                if (isDigit(*(itr - 1)->begin())) {
                    newSplit.push_back(val);
                    newSplit.push_back(*itr);
                    val = "";
                    continue;
                }
            }
            val += *itr;
        } else if (isOperator(*b)) {
            if(*b == '/' && isalpha(*(b+1))){
                newSplit.push_back(val);
                newSplit.push_back(*itr);
                val = "";
                continue;
            }
            val += *itr;
            if (isalpha((*(itr + 1)).front())) {
                val += *(++itr);
            }
        }
        if (*b == ',') {
            newSplit.push_back(val);
            val = "";
            continue;
        }
        if (*b == '\"') {
            if(val != "") {
                string s = (*itr).erase(0,1);
                newSplit.push_back(val);
                newSplit.push_back(s);
                val = "";
            }
            newSplit.push_back(*itr);
        }
        if (*b == '=') {
            if(val != "") {
                newSplit.push_back(val);
                val = "";
            }
            newSplit.push_back(*itr);
        }
        if (*b == '{') {
            if(val != "") {
                newSplit.push_back(val);
                val = "";
            }
            newSplit.push_back(*itr);
        }
        if (*b == '}') {
            if(val != "") {
                newSplit.push_back(val);
                val = "";
            }
            newSplit.push_back(*itr);
        }
        if(isSign(*b)){
            if(val != "") {
                newSplit.push_back(val);
                val = "";
            }
            newSplit.push_back(*itr);
        }
        index++;
    }
    if(val != "") {
        newSplit.push_back(val);
    }
    return newSplit;
}


bool Lexer::isDigit(char c) {
    return c <= '9' && c >= '0';
}