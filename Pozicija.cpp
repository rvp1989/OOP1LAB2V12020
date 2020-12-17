#include <cmath>

#include "Pozicija.h"

Pozicija::Pozicija(int row, int col)
	: _row(row), _col(col)
{
}

int Pozicija::Row() const
{
	return _row;
}

int Pozicija::Col() const
{
	return _col;
}

int operator-(const Pozicija& pozicija1, const Pozicija& pozicija2)
{
	return std::abs(pozicija1.Row() - pozicija2.Row()) + std::abs(pozicija1.Col() - pozicija2.Col());
}
