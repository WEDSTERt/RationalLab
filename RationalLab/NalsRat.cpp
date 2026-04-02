#include "NalsRat.h"

NalsRat::NalsRat() {
	res = 0;
	std::cout << "1" << std::endl;
}
NalsRat::NalsRat(float t) {
	res = t;
	std::cout << "1" << std::endl;
}
NalsRat::NalsRat(FracType F) {
	SetValFrac(F);
	res = GetValFloat();
	std::cout << "1" << std::endl;
}