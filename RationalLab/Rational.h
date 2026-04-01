#pragma once

#include <string>

struct FracType
{
    int64_t num;
    uint64_t del;
};

class Rational
{
public:

    Rational();
    Rational(float);
    Rational(int64_t, uint64_t);
    Rational(const Rational&);
    Rational(Rational&&) noexcept;
    ~Rational();
    void Ratgcd(Rational& gcdval);
    void SetVal(float);
    float GetValFloat() const;
    FracType GetValFrac() const;

    // Arithmetic Operators
    Rational operator +(const Rational&);
    Rational operator -(const Rational&);
    Rational operator *(const Rational&);
    Rational operator /(const Rational&);

    // Assignment Operators
    Rational& operator =(const Rational&);
    Rational& operator +=(const Rational&);
    Rational& operator -=(const Rational&);
    Rational& operator *=(const Rational&);
    Rational& operator /=(const Rational&);

    // Operators unar
    Rational& operator ++();
    Rational operator ++(int);
    Rational& operator --();
    Rational operator --(int);
    Rational operator -() const;

    //Relational Operators
    bool operator==(const Rational&);
    bool operator!=(const Rational&);
    bool operator>(const Rational&);
    bool operator<(const Rational&);
    bool operator>=(const Rational&);
    bool operator<= (const Rational&);

    //Logical Operators
    bool operator&& (const Rational&);
    bool operator|| (const Rational&);
    bool operator! ();

    //Bitwise Operators
    Rational operator& (const Rational&);
    Rational operator| (const Rational&);
    Rational operator^ (const Rational&);
    Rational operator<< (const int);
    Rational operator>> (const int);
    Rational operator~ ();

    //Casting Operators
    operator double() const;
    operator float() const;
    operator int() const;
    operator int64_t() const;

private:
    FracType Frac;
};


