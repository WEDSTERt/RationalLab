#include <string>
#include <iostream>
#include "Parser.h"


int main()
{
    FracType t = Parser::GetExpr();
    std::cout << t.num << "/" << t.del << std::endl;
    return 0;
}

