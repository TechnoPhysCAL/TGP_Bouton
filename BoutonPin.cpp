#include "BoutonPin.h"

BoutonPin::BoutonPin(int address, bool rising, bool pullup) : Bouton()
{
	_address = address;
	_front = rising ? LOW : HIGH;
	pinMode(_address, pullup ? INPUT_PULLUP : INPUT);
}

void BoutonPin::rafraichir()
{
	auto booleanGetter = [&]()->bool
	{ return digitalRead(_address) == _front; };

	Bouton::refresh(booleanGetter);
}
