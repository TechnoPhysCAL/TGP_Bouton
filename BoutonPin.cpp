#include "BoutonPin.h"

BoutonPin::BoutonPin(int address, bool rising, bool pullup) : Bouton()
{
	_address = address;
	_front = rising ? LOW : HIGH;
	_pullup = pullup;
	setDebounceDelay(DEBOUNCE_DELAY_PIN);
	setNbComptes(NOMBRE_COMPTES_PIN);

}

void BoutonPin::begin()
{
	pinMode(_address, _pullup ? INPUT_PULLUP : INPUT);
}

bool BoutonPin::getNextValue()
{
	return digitalRead(_address) == _front;
}
