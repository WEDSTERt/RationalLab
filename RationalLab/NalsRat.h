#pragma once
#include "Rational.h"
#include <iostream>
class NalsRat :
    public Rational
{
public:
    NalsRat();
    NalsRat(float);
    NalsRat(FracType);
    ~NalsRat();
private:
    float res;
};

