#include <string>
#include <iostream>
#include "Parser.h"
#include "NalsRat.h"


int main()
{
    //NalsRat T(1.2f);
    Rational* t = new Rational[10];
    //Parser::PrExpr();
    t[1] = Rational(2);
    std::cout << t[1].GetOcrlVal('d');
    return 0;
}