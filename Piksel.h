#ifndef _PIKSEL_H_
#define _PIKSEL_H_

#include <iostream>


// Voditi racuna:
// 1. funkcije koje ne menjaju unutrasnje stanje objekta treba da imaju const u definiciji
// 2. argumenti koji su objekti klasa ili struktura, ukoliko se ne menjaju, treba da budu reference na const objekat
// 3. aritmeticki operatori i operatori poredjenja treba da budu prijateljske funckije
// 4. ukoliko se definise ==, nije lose definisati i njegov parnjak != (i obrnuto)
class Piksel
{
public:
	Piksel(unsigned char r = 0, unsigned char g = 0, unsigned char b = 0);


	unsigned char R() const;
	unsigned char G() const;
	unsigned char B() const;


	friend Piksel operator+(const Piksel&, const Piksel&);
	friend bool operator==(const Piksel&, const Piksel&);
	friend bool operator!=(const Piksel& pikse1, const Piksel& piksel2);

	friend std::ostream& operator<<(std::ostream&, const Piksel&);
private:
	unsigned char _r;
	unsigned char _g;
	unsigned char _b;
};

#endif // !_PIKSEL_H_
