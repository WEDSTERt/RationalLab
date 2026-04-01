#pragma once

#include "Rational.h"
#include <iostream>

struct FracType
{
    int64_t num;
    uint64_t del;
};

class Parser
{
public:
    Parser(const std::string& str);
    void skip();
    Rational parseExpression();
    Rational parseTerm();
    Rational parseFactor();
    const std::string& s;
    static FracType GetExpr();
private:
    size_t i;
};