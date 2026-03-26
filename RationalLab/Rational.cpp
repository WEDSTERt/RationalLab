#include <iostream>
#include "Rational.h"

Rational::Rational() {
    num = 1;
    del = 0;
}
Rational::Rational(float value) {
    num = 0;
    del = 0;
    void SetVal(float value);
}
Rational::Rational(double value) {
    num = 0;
    del = 0;
    void SetVal(double value);
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

void Rational::SetVal(double value) {
    int64_t bits;
    std::memcpy(&bits, &value, sizeof(double));

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
