#ifndef _POZICIJA_H_
#define _POZICIJA_H_

class Pozicija
{
public:
	Pozicija(int row, int col);

	int Row() const;
	int Col() const;

	friend int operator-(const Pozicija& pozicija1, const Pozicija& pozicija2);

private:
	int _row;
	int _col;
};
#endif // !_POZICIJA_H_
