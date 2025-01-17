#include "BoutonPin.h"

BoutonPin::BoutonPin(int address, bool rising, bool pullup) : Bouton()
{
	_address = address;
	_front = rising ? LOW : HIGH;
	_pullup = pullup;

}

void BoutonPin::begin()
{
	pinMode(_address, _pullup ? INPUT_PULLUP : INPUT);
}

bool BoutonPin::getNextValue()
{
	return digitalRead(_address) == _front;
}
