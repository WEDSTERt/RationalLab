#include "NalsRat.h"

NalsRat::NalsRat() : Rational(){
	res = 0;
	std::cout << "1" << std::endl;
}
NalsRat::NalsRat(float t) : Rational(t) {
	res = t;
	std::cout << "1" << std::endl;
}
NalsRat::NalsRat(FracType F) : Rational(F) {
	SetValFrac(F);
	res = GetValFloat();
	std::cout << "1" << std::endl;
}
NalsRat::~NalsRat() {
	std::cout << "DecNasledRat" << std::endl;
}