#ifndef _SLIKA_H_
#define _SLIKA_H_

#include "Piksel.h"
#include "Pozicija.h"


// Slika sadrzi pokazivac, te zahteva definiciju konstruktora
// premestanja i kopiranja i destruktor. Prema pravilu petorke,
// ukoliko je potreban jedan od destruktora, kopirajuceg ili premestajuceg
// konstruktora, treba ih definisati sve kao i operator dodele.
// Operator dodele se najcesce realizuje preko Copy-And-Swap idioma,
// gde je argument objekat po vrednosti, a unutar operatora se samo vrsi
// zamena vrednosti polja preko std::swap metode.
class Slika
{
public:
	Slika(int w, int h);
	// Destruktor se definise kao virtuelan.
	// Ukoliko imamo primer Slika *s = new DerivedSlika();
	// gde je DerivedSlika izvedena klasa iz slike. Pri pozivu:
	// delete s;
	// Pozvace se destruktor Slike, a ne DerivedSlike
	virtual ~Slika();
	Slika(const Slika&); // kopirajuci konstruktor
	Slika(Slika&&);      // premestajuci

	int H() const;
	int W() const;
	int Size() const;

	// Copy-And-Swap Idiom
	Slika& operator=(Slika slika);

	const Piksel& operator[](const Pozicija& pos) const;

	// Funkcija se definise virtuelno, jer se nadjacava u izvedenim klasama
	virtual void Set(const Piksel& piksel, const Pozicija& pos);

	friend std::ostream& operator<<(std::ostream& out, const Slika& slika);

// Stavlja se protected, jer cemo imati izvedene klase koje ce pristupati
// ovim poljima.
protected:
	int _h;
	int _w;

	Piksel** _matrica;
};

// Slika(const Slika& s1)
//{
// _h = s1._h;
// _w = s1._w;
// _matrica = s1._matrica;
//}

// Slika slika1;
// Slika slika2;

// ... slika1 = slika2;

#endif
