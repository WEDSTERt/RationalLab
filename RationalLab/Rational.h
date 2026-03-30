#pragma once

#include <string>
#include <iostream>
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
    float GetVal() const;
    void PrValue() const;

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
private:
    int64_t num;
    uint64_t del;
};


