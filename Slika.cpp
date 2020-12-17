#include "Slika.h"

const int NUM_BITS_IN_PIXEL = 24;

Slika::Slika(int w, int h)
	: _w(w), _h(h), _matrica(nullptr)
{
	_matrica = new Piksel * [_h];

	// za svaki kreirani piksel se poziva podrazumevani konstruktor
	// Piksel()
	for (int i = 0; i < _h; ++i)
		_matrica[i] = new Piksel[_w];
}

Slika::~Slika()
{
	if (_matrica == nullptr)
		return;

	// uz delete se stavljaju [] jer se u pitanju brisanje
	// *niza* objekata, time ce se pozvati destruktor za svaki
	// objekat unutar tog niza.
	for (int i = 0; i < _h; ++i)
		delete[] _matrica[i];

	delete[] _matrica;
}

Slika::Slika(const Slika& slika)
{
	_h = slika._h;
	_w = slika._w;

	_matrica = new Piksel * [_h];
	for (int i = 0; i < _h; ++i)
		_matrica[i] = new Piksel[_w];

	for (int i = 0; i < _h; ++i)
		for (int j = 0; j < _w; ++j)
			_matrica[i][j] = slika._matrica[i][j];
}

Slika::Slika(Slika&& slika)
{
	_h = slika._h;
	_w = slika._w;

	// Posto se prosledjeni objekat slika neposredno nakon
	// zavrsetka premestajuceg konstruktora brise, mi mozemo
	// samo da uzmemo njegove pokazivace, a u prosledjenoj slici
	// da upisemo nullptr. Razlog tome je sto se ta slika brise, i nema
	// potrebe za dubokom kopijom
	_matrica = slika._matrica;
	slika._matrica = nullptr;
}

int Slika::H() const
{
	return _h;
}

int Slika::W() const
{
	return _w;
}

Slika& Slika::operator=(Slika slika)

{
	std::swap(_h, slika._h);
	std::swap(_w, slika._w);
	std::swap(_matrica, slika._matrica);

	return *this;
}

const Piksel& Slika::operator[](const Pozicija& pos) const
{
	return _matrica[pos.Row()][pos.Col()];
}

void Slika::Set(const Piksel& piksel, const Pozicija& pos)
{
	_matrica[pos.Row()][pos.Col()] = piksel;
}

// Uglavnom kada se koriste konstante, treba ih definisati unutar nekog const simbola
// jer se time obezbedjujemo da samo na jednom mestu menjamo vrednost, ukoliko za to bude potrebe.
int Slika::Size() const
{
	return NUM_BITS_IN_PIXEL * _w * _h;
}

std::ostream& operator<<(std::ostream& out, const Slika& slika)
{
	out << slika.Size() << std::endl;
	for (int i = 0; i < slika.H(); ++i)
	{
		for (int j = 0; j < slika.W(); ++j)
		{
			out << slika[Pozicija(i, j)] << " ";
		}
		out << std::endl;
	}

	return out;
}
