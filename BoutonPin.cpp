#include "BoutonPin.h"

BoutonPin::BoutonPin(int address, bool rising, bool pullup) : Bouton()
{
	_address = address;
	_front = rising ? LOW : HIGH;
	_pullup = pullup;

#ifndef __AVR__
	auto booleanGetter = [&]() -> bool
	{ return digitalRead(_address) == _front; };

	Bouton::setValueGetter(booleanGetter);
#endif
}

void BoutonPin::begin()
{
	pinMode(_address, _pullup ? INPUT_PULLUP : INPUT);
}

#ifdef __AVR__
bool BoutonPin::getNextValue()
{
	return digitalRead(_address) == _front;
}
#endif