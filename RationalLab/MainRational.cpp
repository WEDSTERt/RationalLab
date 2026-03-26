#include <iostream>
#include <cstdlib>
#include "Rational.h"
#include <string>
int main()
{
    Rational x, y, z;
    float a, b;
    std::string t, ch1, ch2;
    char zn = ' ';
    while (true) {
        std::cin >> a >> b;
        x.SetVal(a);
        y.SetVal(b);
        /*for (int i = 0; i < std::size(t); ++i) {
            if (!isdigit(t[i]) && (t[i] != '.') && (t[i] != ',')) {
                zn = t[i];
                t[i] = ' ';
                ch1 = t.substr(0, i);
                ch2 = t.substr(i + 1, std::size(t));
                x.SetVal(stof(ch1));
                y.SetVal(stof(ch2));
                break;
            }
        }*/
        z = x + y;
        x.PrValue();

        break;

    }

}
