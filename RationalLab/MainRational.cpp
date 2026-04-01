#include <string>
#include <iostream>
#include "Rational.h"
#include "Parser.h"



int main()
{

    Rational t2;
    FracType t = Parser::GetExpr();
    int s = Rational::GetCount();
    std::cout << t.num << "/" << t.del << std::endl << s;
    return 0;
}

