#include "Bouton.h"

Bouton::Bouton(int address) : BoutonBase()
{
	_address = address;
	_front = LOW;
	pinMode(address, INPUT);
}
Bouton::Bouton(int address, bool rising, bool pullup)
{
	_address = address;
	_front = rising ? LOW : HIGH;
	pinMode(_address, pullup ? INPUT_PULLUP : INPUT);
}
bool Bouton::isDetected()
{
	return digitalRead(_address) == _front;
}