#include "BoutonExterne.h"

BoutonExterne::BoutonExterne(unsigned long debounceDelay, uint8_t nbComptes, unsigned long longPressDelay, unsigned long longPressInterval) : Bouton(debounceDelay, nbComptes, longPressDelay, longPressInterval)
{
	_nextValue = false;
}

void BoutonExterne::setNextValue(bool value)
{
	_nextValue = value;
}

bool BoutonExterne::getNextValue()
{
	return _nextValue;
}