#include "BoutonPin.h"

BoutonPin::BoutonPin(int address, bool rising, bool pullup) : Bouton()
{
	_address = address;
	_front = rising ? LOW : HIGH;
	_pullup = pullup;

	auto booleanGetter = [&]() -> bool
	{ return digitalRead(_address) == _front; };

	Bouton::setValueGetter(booleanGetter);
}

void BoutonPin::begin()
{
	pinMode(_address, _pullup ? INPUT_PULLUP : INPUT);
}
