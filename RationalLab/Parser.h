#pragma once

#include "Rational.h"
#include <iostream>

class Parser
{
public:
    static void PrExpr();
private:
    size_t i;
    Parser(const std::string& str);
    void skip();
    Rational parseExpression();
    Rational parseTerm();
    Rational parseFactor();
    const std::string& s;
    static FracType GetExpr();
};