#pragma once
#include <iostream>
#include <string>
#include "Rational.h"

class Parser
{
public:
    Parser(const std::string& str);
    void skip();
    Rational parseExpression();
    Rational parseTerm();
    Rational parseFactor();
    const std::string& s;
    size_t i;
};
Rational LinExpr(const std::string& expr);