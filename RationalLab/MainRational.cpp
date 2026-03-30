#include <iostream>
#include <string>
#include "Rational.h"
#include "Parser.h"

int main()
{
    Rational res;
    std::string expr;
    std::cout << "Enter an algebraic expression:\n";
    std::getline(std::cin, expr);
    if (expr.empty()) return 0;

    for (char c : expr) {
        if (std::isalpha((unsigned char)c)) {
            std::cerr << "Variables are not supported. Enter an expression with numbers only." << std::endl;
            return 1;
        }
    }
    try {
        res = LinExpr(expr);
        std::cout << "Result: "; res.PrValue();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}