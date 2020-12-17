#include "CrnoBelaSlika.h"


const Piksel WHITE_PIXEL = Piksel(255, 255, 255);
const Piksel BLACK_PIXEL = Piksel();

void CrnoBelaSlika::Set(const Piksel& piksel, const Pozicija& pos)
{
	if ((piksel.R() + piksel.G() + piksel.B()) / 3 > 127)
		_matrica[pos.Row()][pos.Col()] = WHITE_PIXEL;
	else
		_matrica[pos.Row()][pos.Col()] = BLACK_PIXEL;
}
