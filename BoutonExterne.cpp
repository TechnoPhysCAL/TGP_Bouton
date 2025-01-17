#include "BoutonExterne.h"

BoutonExterne::BoutonExterne(unsigned long debounceDelay, uint8_t nbComptes, unsigned long longPressDelay, unsigned long longPressInterval) : Bouton(debounceDelay, nbComptes, longPressDelay, longPressInterval)
{
	_nextValue = false;
#ifndef __AVR__
	Bouton::setValueGetter([&]() -> bool
	{
		return BoutonExterne::_nextValue;
	});
#endif
}

void BoutonExterne::setNextValue(bool value)
{
	_nextValue = value;
}
#ifdef __AVR__
bool BoutonExterne::getNextValue()
{
	return _nextValue;
}
#endif