#include "Parser.h"
Parser::Parser(const std::string& str) : s(str), i(0) {}

void Parser::skip(){
    while (i < s.size() && std::isspace((unsigned char)s[i])) ++i;
}

Rational Parser::parseExpression() {
    Rational res = parseTerm();
    skip();
    while (i < s.size()) {
        if (s[i] == '+') {
            ++i; skip();
            res = res + parseTerm();
        }
        else if (s[i] == '-') {
            ++i; skip();
            res = res - parseTerm();
        }
        else break;
        skip();
    }
    return res;
}
Rational Parser::parseTerm() {
    Rational res = parseFactor();
    skip();
    while (i < s.size()) {
        if (s[i] == '*') {
            ++i; skip();
            res = res * parseFactor();
        }
        else if (s[i] == '/') {
            ++i; skip();
            res = res / parseFactor();
        }
        else break;
        skip();
    }
    return res;
}
Rational Parser::parseFactor() {
    skip();
    if (s[i] == '+') { ++i; return parseFactor(); }
    if (s[i] == '-') { ++i; 
    Rational v = parseFactor(); 
    return -v; 
    }
    if (s[i] == '(') {
        ++i;
        Rational v = parseExpression();
        skip();
        if (i >= s.size() || s[i] != ')') throw std::runtime_error("Missing closing parenthesis");
        ++i;
        return v;
    }
    if (std::isdigit((unsigned char)s[i]) || s[i] == '.') {
        size_t start = i;
        bool hasDot = false;
        while (i < s.size() && (std::isdigit((unsigned char)s[i]) || s[i] == '.')) {
            if (s[i] == '.') {
                if (hasDot) break;
                hasDot = true;
            }
            ++i;
        }
        std::string numstr = s.substr(start, i - start);
        double val = std::stod(numstr);
        Rational r(val);
        return r;
    }
    throw std::runtime_error(std::string("Unexpected character: ") + s[i]);
}

FracType Parser::GetExpr() {
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