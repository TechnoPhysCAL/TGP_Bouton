#include "Bouton.h"


Bouton::Bouton(int address):BoutonBase()
{
	_address = address;
	_front = LOW;
	pinMode(address, INPUT);
}
Bouton::Bouton(int address, int front, int pMode)
{
	_address = address;
	_front = front;
	pinMode(_address, pMode);
}
bool Bouton::isDetected()
{
	return digitalRead(_address) == _front;
}