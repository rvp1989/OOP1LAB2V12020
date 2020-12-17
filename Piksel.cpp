#include "Piksel.h"

// r = 1, g  = 2, b = 3;

// r = ?, g = ?, b = ?
// nakon tela konstruktora
// r = 1, g  = 2, b = 3;

Piksel::Piksel(unsigned char r, unsigned char g, unsigned char b)
	: _r(r), _g(g), _b(b)
{

}

unsigned char Piksel::R() const
{
	return _r;
}

unsigned char Piksel::G() const
{
	return _g;
}

unsigned char Piksel::B() const
{
	return _b;
}

Piksel operator+(const Piksel& piksel1, const Piksel& piksel2)
{
	return Piksel(
		(piksel1.R() + piksel2.R()) / 2,
		(piksel1.G() + piksel2.G()) / 2,
		(piksel1.B() + piksel2.B()) / 2
	);
}

bool operator==(const Piksel& piksel1, const Piksel& piksel2)
{
	return piksel1.R() == piksel2.R() &&
		piksel1.G() == piksel2.G() &&
		piksel1.B() == piksel2.B();
}

bool operator!=(const Piksel& piksel1, const Piksel& piksel2)
{
	return !(piksel1 == piksel2);
}

std::ostream& operator<<(std::ostream& out, const Piksel& piksel)
{
	
	out << "(" << (int)piksel.R() << "," << (int)piksel.G() << "," << (int)piksel.B() << ")";

	return out;
}
