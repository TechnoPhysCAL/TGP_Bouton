#include "Bouton.h"

Bouton::Bouton()
{
	_address = -1;
	_front = -1;
	_nextValue = false;
}
Bouton::Bouton(int address) : BoutonBase()
{
	_address = address;
	_front = LOW;
	_nextValue = false;
	pinMode(address, INPUT);
}
Bouton::Bouton(int address, bool rising, bool pullup)
{
	_address = address;
	_front = rising ? LOW : HIGH;
	_nextValue = false pinMode(_address, pullup ? INPUT_PULLUP : INPUT);
}
bool Bouton::isDetected()
{
	if (_address != -1)
	{
		return digitalRead(_address) == _front;
	}
	else
	{
		return _nextValue;
	}
}