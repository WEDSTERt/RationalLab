#include "Rational.h"
#include <iostream>
Rational::Rational() {
    Frac.num = 0;
    Frac.del = 1;
}
Rational::Rational(float value) {
    SetVal(value);
}
Rational::Rational(int64_t t_num, uint64_t t_del) {
    Frac.num = t_num;
    Frac.del = t_del;
}
Rational::Rational(const Rational& c){
    Frac.num = c.Frac.num;
    Frac.del = c.Frac.del;
} 
Rational::Rational(Rational&& t) noexcept {
    std::swap(Frac.del, t.Frac.del);
    std::swap(Frac.num, t.Frac.num);
}

Rational::~Rational() {
 //   std::cout << "Delete Var "<< std::endl;
}

void Rational::Ratgcd(Rational& gcdval) {
    int64_t num = gcdval.Frac.num;
    uint64_t a = (num < 0) ? uint64_t(-num) : uint64_t(num);
    uint64_t b = gcdval.Frac.del;

    if (a == 0) {
        // 0 / d -> normalize to 0/1
        gcdval.Frac.num = 0;
        gcdval.Frac.del = 1;
        return;
    }

    while (b != 0) {
        uint64_t tmp = b;
        b = a % b;
        a = tmp;
    }

    gcdval.Frac.num = gcdval.Frac.num / static_cast<int64_t>(a);
    gcdval.Frac.del = gcdval.Frac.del / a;
}

void Rational::SetVal(float value) {
    int64_t bits;
    std::memcpy(&bits, &value, sizeof(float));

    int64_t sign = (bits >> 31) & 1; 
    int64_t exp = (bits >> 23) & 0xFF;
    int64_t mant = bits & 0x7FFFFF;

    if (exp == 0) {
        Frac.num = mant;
        Frac.del = 1 << 22;
    }
    else if (exp == 0xFF) {
        Frac.num = 0;
        Frac.del = 1;
    }
    else {
        Frac.num = (1LL << 23) + mant;
        Frac.del = 1LL << (23 - (exp - 127));
    }
    if (sign) {
        Frac.num = -Frac.num;
    }
    Ratgcd(*this);
}

float Rational::GetValFloat() const {
    return float(double(Frac.num) / double(Frac.del));
}
FracType Rational::GetValFrac() const {
    return Frac;
}
Rational Rational::operator +(const Rational& x) {
    Rational res{};
    res.Frac.num = Frac.num * x.Frac.del + x.Frac.num * Frac.del;
    res.Frac.del = Frac.del * x.Frac.del;
    Ratgcd(res);
    return res;
}

// Arithmetic Operators
Rational Rational::operator -(const Rational& x) {
    Rational res{};
    res.Frac.num = Frac.num * x.Frac.del - x.Frac.num * Frac.del;
    res.Frac.del = Frac.del * x.Frac.del;
    Ratgcd(res);
    return res;
}
Rational Rational::operator *(const Rational& x) {
    Rational res{};
    res.Frac.num = Frac.num * x.Frac.num;
    res.Frac.del = Frac.del * x.Frac.del;
    Ratgcd(res);
    return res;
}
Rational Rational::operator /(const Rational& x) {
    Rational res{}
    ;
    if (x.Frac.num == 0) {
        res.Frac.num = 0;
        res.Frac.del = 1;
        return res;
    }
    uint64_t abs_xnum = (x.Frac.num < 0) ? uint64_t(-x.Frac.num) : uint64_t(x.Frac.num);

    res.Frac.num = Frac.num * static_cast<int64_t>(x.Frac.del);
    res.Frac.del = Frac.del * abs_xnum;
    if (x.Frac.num < 0) res.Frac.num = -res.Frac.num;

    Ratgcd(res);
    return res;
}
// Assignment Operators
Rational& Rational::operator =(const Rational& x) {
    if (this != &x) {
        Frac.del = x.Frac.del;
        Frac.num = x.Frac.num;
    }
    return *this;
}
Rational& Rational::operator +=(const Rational& x) {
    Frac.num = Frac.num * x.Frac.del + x.Frac.num * Frac.del;
    Frac.del = Frac.del * x.Frac.del;
    Ratgcd(*this);
    return *this;
}
Rational& Rational::operator -=(const Rational& x) {
    Frac.num = Frac.num * x.Frac.del - x.Frac.num * Frac.del;
    Frac.del = Frac.del * x.Frac.del;
    Ratgcd(*this);
    return *this;
}
Rational& Rational::operator *=(const Rational& x) {
    Frac.num = Frac.num * x.Frac.num;
    Frac.del = Frac.del * x.Frac.del;
    Ratgcd(*this);
    return *this;
}
Rational& Rational::operator /=(const Rational& x) {
    Frac.num = Frac.num * x.Frac.del;
    Frac.del = Frac.del * x.Frac.num;
    Ratgcd(*this);
    return *this;
}

// Operators unar
Rational& Rational::operator ++() {
    Frac.num = Frac.num + Frac.del;
    return *this;
}
Rational Rational::operator ++(int) {
    Rational res = *this;
    Frac.num = Frac.num + Frac.del;
    return res;
}
Rational& Rational::operator --() {
    Frac.num = Frac.num - Frac.del;
    return *this;
}
Rational Rational::operator --(int) {
    Rational res = *this;
    Frac.num = Frac.num - Frac.del;
    return res;
}
Rational Rational::operator-() const {
    Rational x;
    x.Frac.num = -Frac.num;
    x.Frac.del = Frac.del;
    return x;
}

//Relational Operators
bool Rational::operator==(const Rational& x) {
    if (Frac.num == x.Frac.num && Frac.del == x.Frac.del) return 1;
    else return 0;
}
bool Rational::operator!=(const Rational& x) {
    if (Frac.num == x.Frac.num && Frac.del == x.Frac.del) return 0;
    else return 1;
}
bool Rational::operator>(const Rational& x) {
    if (Frac.num * x.Frac.del > x.Frac.num * Frac.del) return 1;
    else return 0;
}
bool Rational::operator<(const Rational& x) {
    if (Frac.num * x.Frac.del < x.Frac.num * Frac.del) return 1;
    else return 0;
}
bool Rational::operator>=(const Rational& x) {
    if (Frac.num * x.Frac.del >= x.Frac.num * Frac.del) return 1;
    else return 0;
}
bool Rational::operator<= (const Rational& x) {
    if (Frac.num * x.Frac.del <= x.Frac.num * Frac.del) return 1;
    else return 0;
}
//Logical Operators
bool Rational::operator&& (const Rational& x) {
    if (Frac.num != 0 && x.Frac.num != 0) return 1;
    else return 0;
}
bool Rational::operator|| (const Rational& x) {
    if (Frac.num != 0 || x.Frac.num != 0) return 1;
    else return 0;
}
bool Rational::operator! () {
    if (Frac.num == 0) return 1;
    else return 0;
}

//Bitwise Operators
Rational Rational::operator& (const Rational& x) {
    Rational res{};
    res.Frac.num = Frac.num & x.Frac.num;
    res.Frac.del = Frac.del & x.Frac.del;
    Ratgcd(res);
    return res;
}
Rational Rational::operator| (const Rational& x) {
    Rational res{};
    res.Frac.num = Frac.num | x.Frac.num;
    res.Frac.del = Frac.del | x.Frac.del;
    Ratgcd(res);
    return res;
}
Rational Rational::operator^ (const Rational& x) {
    Rational res{};
    res.Frac.num = Frac.num ^ x.Frac.num;
    res.Frac.del = Frac.del ^ x.Frac.del;
    Ratgcd(res);
    return res;
}
Rational Rational::operator<< (const int x) {
    Rational res{};
    res.Frac.num = Frac.num << x;
    res.Frac.del = Frac.del << x;
    Ratgcd(res);
    return res;
}
Rational Rational::operator>> (const int x) {
    Rational res{};
    res.Frac.num = Frac.num >> x;
    res.Frac.del = Frac.del >> x;
    Ratgcd(res);
    return res;
}


Rational Rational::operator~ () {
    Rational res{};
    res.Frac.num = ~Frac.num;
    res.Frac.del = ~Frac.del;
    Ratgcd(res);
    return res;
}

//Casting Operators
Rational::operator double() const
{
    return double(Frac.num) / double(Frac.del);
}
Rational::operator float() const
{
    return float(Frac.num) / float(Frac.del);
}
Rational::operator int() const
{
    return int(float(Frac.num) / float(Frac.del));
}