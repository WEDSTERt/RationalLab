#include <string>
#include <iostream>
#include "Rational.h"
#include "Parser.h"

FracType GetExpr();

int main()
{
    FracType t = GetExpr();
    std::cout << t.num << "/" << t.del << std::endl;
    return 0;
}

FracType GetExpr() {
    Rational res;
    std::string expr;
    FracType t;
    std::cout << "Enter an algebraic expression:\n";
    do {
        std::getline(std::cin, expr);
    } while (expr.empty());

    for (char c : expr) {
        if (std::isalpha((unsigned char)c)) {
            std::cerr << "Enter an expression with numbers only." << std::endl;
            exit(0);
        }
    }
    try {
        Parser p(expr);
        Rational res = p.parseExpression();
        p.skip();
        t = res.GetValFrac();
    }
    catch (...) {
        std::cerr << "Error input" << std::endl;
        exit(0);
    }
    return t;
}