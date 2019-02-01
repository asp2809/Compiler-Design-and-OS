// Name - Anshu S Panda
// Roll No. - 39/CSE/16010/167


#include<iostream>
#include<regex>
#include<string>

using namespace std;

#ifndef HEADER
#define HEADER

struct token {
    int pos, lineNo=1, prevLen = 0;
    string type, value, strline;
};

token nextToken(token);

const regex id("^[a-zA-Z][a-zA-Z0-9]*");
const regex intConst("^[0-9]+");
const regex binOp("^[+\\-*/%=]");
const regex seperator("^[;,(){}]");
const regex comment("^//[ a-zA-Z0-9]*");
const regex space("^ ");
const regex noToken("^[^a-zA-Z0-9+*\\-%=;,(){} ]");

#endif