#include "Bouton.h"

Bouton::Bouton(unsigned long debounceDelay, uint8_t nbComptes, unsigned long longPressDelay, unsigned long longPressInterval)
{
	_lastEtat = RELACHE;
	_keyRegister = 0;

	Bouton::setDebounceDelay(debounceDelay);
	Bouton::setNbComptes(nbComptes);
	Bouton::setLongPressDelay(longPressDelay);
	Bouton::setLongPressInterval(longPressInterval);
}

void Bouton::refresh(std::function<bool()> f, bool forceNow)
{

	unsigned long _actualSample = millis();

	if (forceNow || (_actualSample - _lastSample > _debounceDelay))
	{ // Si temps d'echantillonnage atteint
		_lastSample = _actualSample;
		forward((f)()); // Decale le registre
	}
	changeEtat(_actualSample);
}

bool Bouton::isPressed()
{
	return (_lastEtat == ENFONCANT);
}
bool Bouton::isReleased()
{
	return (_lastEtat == RELACHANT);
}
bool Bouton::isLongPressed()
{
	return (_lastEtat == MAINTENANT);
}

bool Bouton::isOnPress()
{
	return (_lastEtat == ENFONCE || _lastEtat == ENFONCANT);
}
bool Bouton::isOnRelease()
{
	return (_lastEtat == RELACHE || _lastEtat == RELACHANT);
}
bool Bouton::isOnLongPress()
{
	return (_lastEtat == MAINTENU || _lastEtat == MAINTENANT);
}

int Bouton::changeEtat(unsigned long cur_time)
{

	if (_keyRegister >= _nbComptes)
	{
		if (_lastEtat == ENFONCANT)
		{
			_lastEtat = ENFONCE;
		}
		else if (_lastEtat == ENFONCE)
		{
			if (cur_time - time_started > _longPressDelay)
			{
				_lastEtat = MAINTENANT;
				time_maintenu_started = cur_time;
			}
		}
		else if (_lastEtat == MAINTENANT)
		{
			_lastEtat = MAINTENU;
		}
		else if (_lastEtat == MAINTENU)
		{
			if (cur_time - time_maintenu_started > _longPressInterval)
			{
				_lastEtat = MAINTENANT;
				time_maintenu_started = cur_time;
			}
		}
		else
		{
			_lastEtat = ENFONCANT;
			time_started = cur_time;
		}
	}
	else
	{
		if (_lastEtat >= ENFONCE)
		{
			time_started = cur_time;
			_lastEtat = RELACHANT;
		}
		else
		{
			_lastEtat = RELACHE;
		}
	}
	return _lastEtat;
}

void Bouton::forward(bool newValue)
{

	if (newValue && (_keyRegister < _nbComptes))
	{
		_keyRegister++;
	}
	else if (!newValue && (_keyRegister > 0))
	{
		_keyRegister--;
	}
}
//*********************************************************************
// Routine pour NbComptes
//*********************************************************************
void Bouton::setNbComptes(uint8_t nbComptes)
{
	_nbComptes = nbComptes;
}
uint8_t Bouton::getNbComptes()
{
	return _nbComptes;
}

//*********************************************************************
// Routine pour ajuster l'intervalle de temps pour ajouter les valeurs
// du bouton lu dans le registre à décalage.
//*********************************************************************
void Bouton::setDebounceDelay(unsigned long delay)
{
	_debounceDelay = delay;
}
unsigned long Bouton::getDebounceDelay()
{
	return _debounceDelay;
}

//*********************************************************************
// Routine pour ajuster l'intervalle de temps pour considerer un clic
// comme étant long
//*********************************************************************
void Bouton::setLongPressDelay(unsigned long delay)
{
	_longPressDelay = delay;
}
unsigned long Bouton::getLongPressDelay()
{
	return _longPressDelay;
}

//*********************************************************************
// Routine pour ajuster l'intervalle de temps entre chaque répétition
// dans l'état maintenu
//*********************************************************************
void Bouton::setLongPressInterval(unsigned long interval)
{
	_longPressInterval = interval;
}
unsigned long Bouton::getLongPressInterval()
{
	return _longPressInterval;
}