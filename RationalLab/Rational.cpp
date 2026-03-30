#include <iostream>
#include <string>
#include "Rational.h"

Rational::Rational() {
    num = 0;
    del = 1;
}
Rational::Rational(float value) {
    num = 0;
    del = 0;
    SetVal(value);
}
Rational(const Rational& c){
    num = c.num;
    del = c.del;
} 

void Rational::Ratgcd(Rational& gcdval) {

    int64_t a = std::abs(gcdval.num);
    uint64_t b = gcdval.del;
    while (b != 0) {
        int64_t tmp = b;
        b = a % b;
        a = tmp;
    }
    gcdval.num = gcdval.num / a;
    gcdval.del = gcdval.del / a;
}

void Rational::SetVal(float value) {
    int64_t bits;
    std::memcpy(&bits, &value, sizeof(float));

    int64_t sign = (bits >> 31) & 1; 
    int64_t exp = (bits >> 23) & 0xFF;
    int64_t mant = bits & 0x7FFFFF;

    if (exp == 0) {
        num = mant;
        del = 1 << 22;
        if (sign) num = -num; 
    }
    else if (exp == 0xFF) {
        num = 0;
        del = 1;
    }
    else {
        num = (1LL << 23) + mant;
        del = 1LL << (23 - (exp - 127));
        if (sign) num = -num; 
    }
    if (sign) {
        num = -num;
    }
    Ratgcd(*this);
}

float Rational::GetVal() const {
    return float(double(num) / double(del));
}
void Rational::PrValue() const {
    std::cout << num << " / " << del << std::endl;
}
Rational Rational::operator +(const Rational& x) {
    Rational res{};
    res.num = num * x.del + x.num * del;
    res.del = del * x.del;
    Ratgcd(res);
    return res;
}

// Arithmetic Operators
Rational Rational::operator -(const Rational& x) {
    Rational res{};
    res.num = num * x.del - x.num * del;
    res.del = del * x.del;
    Ratgcd(res);
    return res;
}
Rational Rational::operator *(const Rational& x) {
    Rational res{};
    res.num = num * x.num;
    res.del = del * x.del;
    Ratgcd(res);
    return res;
}
Rational Rational::operator /(const Rational& x) {
    Rational res{};
    res.num = num * x.del;
    res.del = del * x.num;
    Ratgcd(res);
    return res;
}
// Assignment Operators
Rational& Rational::operator =(const Rational& x) {
    if (this != &x) {
        del = x.del;
        num = x.num;
    }
    return *this;
}
Rational& Rational::operator +=(const Rational& x) {
    num = num * x.del + x.num * del;
    del = del * x.del;
    Ratgcd(*this);
    return *this;
}
Rational& Rational::operator -=(const Rational& x) {
    num = num * x.del - x.num * del;
    del = del * x.del;
    Ratgcd(*this);
    return *this;
}
Rational& Rational::operator *=(const Rational& x) {
    num = num * x.num;
    del = del * x.del;
    Ratgcd(*this);
    return *this;
}
Rational& Rational::operator /=(const Rational& x) {
    num = num * x.del;
    del = del * x.num;
    Ratgcd(*this);
    return *this;
}

// Operators unar
Rational& Rational::operator ++() {
    num = num + del;
    return *this;
}
Rational Rational::operator ++(int) {
    Rational res = *this;
    num = num + del;
    return res;
}
Rational& Rational::operator --() {
    num = num - del;
    return *this;
}
Rational Rational::operator --(int) {
    Rational res = *this;
    num = num - del;
    return res;
}
//Relational Operators
bool Rational::operator==(const Rational& x) {
    if (num == x.num && del == x.del) return 1;
    else return 0;
}
bool Rational::operator!=(const Rational& x) {
    if (num == x.num && del == x.del) return 0;
    else return 1;
}
bool Rational::operator>(const Rational& x) {
    if (num * x.del > x.num * del) return 1;
    else return 0;
}
bool Rational::operator<(const Rational& x) {
    if (num * x.del < x.num * del) return 1;
    else return 0;
}
bool Rational::operator>=(const Rational& x) {
    if (num * x.del >= x.num * del) return 1;
    else return 0;
}
bool Rational::operator<= (const Rational& x) {
    if (num * x.del <= x.num * del) return 1;
    else return 0;
}
//Logical Operators
bool Rational::operator&& (const Rational& x) {
    if (num != 0 && x.num != 0) return 1;
    else return 0;
}
bool Rational::operator|| (const Rational& x) {
    if (num != 0 || x.num != 0) return 1;
    else return 0;
}
bool Rational::operator! () {
    if (num == 0) return 1;
    else return 0;
}

//Bitwise Operators
Rational Rational::operator& (const Rational& x) {
    Rational res{};
    res.num = num & x.num;
    res.del = del & x.del;
    Ratgcd(res);
    return res;
}
Rational Rational::operator| (const Rational& x) {
    Rational res{};
    res.num = num | x.num;
    res.del = del | x.del;
    Ratgcd(res);
    return res;
}
Rational Rational::operator^ (const Rational& x) {
    Rational res{};
    res.num = num ^ x.num;
    res.del = del ^ x.del;
    Ratgcd(res);
    return res;
}
Rational Rational::operator<< (const int x) {
    Rational res{};
    res.num = num << x;
    res.del = del << x;
    Ratgcd(res);
    return res;
}
Rational Rational::operator>> (const int x) {
    Rational res{};
    res.num = num >> x;
    res.del = del >> x;
    Ratgcd(res);
    return res;
}


Rational Rational::operator~ () {
    Rational res{};
    res.num = ~num;
    res.del = ~del;
    Ratgcd(res);
    return res;
}

//Casting Operators
Rational::operator double() const
{
    return double(num) / double(del);
}
Rational::operator float() const
{
    return float(num) / float(del);
}
Rational::operator int() const
{
    return int(float(num) / float(del));
}

// Parser implementation for EvalLinearExpr
namespace {
    struct Parser {
        const std::string& s;
        size_t i;
        Parser(const std::string& str) : s(str), i(0) {}

        void skip() {
            while (i < s.size() && std::isspace((unsigned char)s[i])) ++i;
        }

        Rational parseExpression() {
            Rational res = parseTerm();
            skip();
            while (i < s.size()) {
                if (s[i] == '+') {
                    ++i; skip();
                    res = res + parseTerm();
                } else if (s[i] == '-') {
                    ++i; skip();
                    res = res - parseTerm();
                } else break;
                skip();
            }
            return res;
        }

        Rational parseTerm() {
            Rational res = parseFactor();
            skip();
            while (i < s.size()) {
                if (s[i] == '*') {
                    ++i; skip();
                    res = res * parseFactor();
                } else if (s[i] == '/') {
                    ++i; skip();
                    res = res / parseFactor();
                } else break;
                skip();
            }
            return res;
        }

        Rational parseFactor() {
            skip();
            if (i >= s.size()) throw std::runtime_error("Unexpected end of expression");
            if (s[i] == '+') { ++i; return parseFactor(); }
            if (s[i] == '-') { ++i; Rational v = parseFactor(); Rational zero; zero.SetVal(0.0); return zero - v; }
            if (s[i] == '(') {
                ++i;
                Rational v = parseExpression();
                skip();
                if (i >= s.size() || s[i] != ')') throw std::runtime_error("Missing closing parenthesis");
                ++i;
                return v;
            }
            if (std::isalpha((unsigned char)s[i])) {
                throw std::runtime_error(std::string("Variables are not supported: ") + s[i]);
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
                Rational r; r.SetVal(val);
                return r;
            }
            throw std::runtime_error(std::string("Unexpected character: ") + s[i]);
        }
    };
}

Rational EvalLinearExpr(const std::string& expr) {
    Parser p(expr);
    Rational res = p.parseExpression();
    p.skip();
    if (p.i != expr.size()) throw std::runtime_error("Trailing characters in expression");
    return res;
}
