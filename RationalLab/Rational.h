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
    Rational(int);
    Rational(short);
    Rational(float);
    Rational(double);
    Rational(FracType);
    Rational(int64_t, uint64_t);
    Rational(const Rational&);
    Rational(Rational&&) noexcept;
    ~Rational();
    void Ratgcd(Rational& gcdval);

    void SetValFloat(float);
    void SetValFrac(FracType);
    float GetValFloat() const;
    FracType GetValFrac() const;
    int64_t GetOcrlVal(char) const;

    static int GetCount();

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
    operator FracType() const;

private:
    FracType Frac;
    static int count;
    void CountAdd();
};


