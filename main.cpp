#include <iostream>

#include "Piksel.h"
#include "CrnoBelaSlika.h"


int main(void)
{
	Slika slika(5, 5);
	CrnoBelaSlika cbslika(5,5);
	Slika& sr = cbslika;

	std::cout << slika;
	slika.Set(Piksel(100, 200, 100), Pozicija(0, 0));
	std::cout << slika << std::endl;

	cbslika.Set(Piksel(100, 200, 200), Pozicija(0, 1));
	std::cout << cbslika << std::endl;

	sr.Set(Piksel(100, 200, 200), Pozicija(0, 0));
	std::cout << sr << std::endl;

	return 0;
}