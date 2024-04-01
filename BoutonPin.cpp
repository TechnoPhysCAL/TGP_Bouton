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
#else
	//Bouton::setValueGetter(&BoutonPin::readValue);
#endif
}

void BoutonPin::begin()
{
	pinMode(_address, _pullup ? INPUT_PULLUP : INPUT);
}

bool BoutonPin::readValue(){
	 return digitalRead(_address) == _front; 
}