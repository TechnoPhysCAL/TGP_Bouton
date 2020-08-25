#include "BoutonPin.h"


BoutonPin::BoutonPin(int address):Bouton()
{
	_address = address;
	_front = LOW;
	pinMode(address, INPUT);
}
BoutonPin::BoutonPin(int address, int front, int pMode)
{
	_address = address;
	_front = front;
	pinMode(_address, pMode);
}
bool BoutonPin::isDetected()
{
	return digitalRead(_address) == _front;
}