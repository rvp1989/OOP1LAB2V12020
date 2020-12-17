#ifndef _CRNO_BELA_SLIKA_H_
#define _CRNO_BELA_SLIKA_H_

#include "Slika.h"

class CrnoBelaSlika : public Slika
{
public:
	using Slika::Slika;
	void Set(const Piksel& piksel, const Pozicija& pos) override;
};

#endif // !_CRNO_BELA_SLIKA_H_