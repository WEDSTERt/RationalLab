#pragma once

class Rational
{
public:

    Rational();
    Rational(float value);
    Rational(double value);

    void Ratgcd(Rational& gcdval);
    void SetVal(float value);
    void SetVal(double value);
    float GetVal() const;
    void PrValue() const;

    // Arithmetic Operators
    Rational operator +(const Rational& x);
    Rational operator -(const Rational& x);
    Rational operator *(const Rational& x);
    Rational operator /(const Rational& x);

    // Assignment Operators
    Rational& operator =(const Rational& x);
    Rational& operator +=(const Rational& x);
    Rational& operator -=(const Rational& x);
    Rational& operator *=(const Rational& x);
    Rational& operator /=(const Rational& x);

    // Operators unar
    Rational& operator ++();
    Rational operator ++(int);
    Rational& operator --();
    Rational operator --(int);


    //Relational Operators
    bool operator==(const Rational& x);
    bool operator!=(const Rational& x);
    bool operator>(const Rational& x);
    bool operator<(const Rational& x);
    bool operator>=(const Rational& x);
    bool operator<= (const Rational& x);

    //Logical Operators
    bool operator&& (const Rational& x);
    bool operator|| (const Rational& x);
    bool operator! ();

    //Bitwise Operators
    Rational operator& (const Rational& x);
    Rational operator| (const Rational& x);
    Rational operator^ (const Rational& x);
    Rational operator<< (const int x);
    Rational operator>> (const int x);
    Rational operator~ ();

    //Casting Operators
    operator double() const;
    operator float() const;
    operator int() const;
private:
    int64_t num;
    uint64_t del;
};
