#include "Bouton.h"

Bouton::Bouton()
{
	_lastEtat = RELACHE;
	_keyRegister = 0;

	_delayDebounce = DEFAULT_DEBOUNCE_DELAY;
	_dureeLongClic = DEFAULT_lONG_PRESS_DELAY;
	_dureeRepetition = DEFAULT_lONG_PRESS_INTERVAL;
}

void Bouton::refresh()
{

	unsigned long _actualSample = millis();

	if (_actualSample - _lastSample > _delayDebounce)
	{ //Si temps d'echantillonnage atteint
		_lastSample = _actualSample;

		forward(); //Decale le registre
		up();
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

	if (_keyRegister >= 255)
	{
		if (_lastEtat == ENFONCANT)
		{
			_lastEtat = ENFONCE;
		}
		else if (_lastEtat == ENFONCE)
		{
			if (cur_time - time_started > _dureeLongClic)
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
			if (cur_time - time_maintenu_started > _dureeRepetition)
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

void Bouton::forward()
{

	_keyRegister = _keyRegister >> 1;
}

void Bouton::up()
{
	if (isDetected())
	{
		_keyRegister += 0x80;
	}
}

//*********************************************************************
//Routine pour ajuster l'intervalle de temps pour ajouter les valeurs
//du bouton lu dans le registre à décalage.
//*********************************************************************
void Bouton::setDebounceDelay(unsigned long delay)
{
	_delayDebounce = delay;
}
unsigned long Bouton::getDebounceDelay()
{
	return _delayDebounce;
}

//*********************************************************************
//Routine pour ajuster l'intervalle de temps pour considerer un clic
//comme étant long
//*********************************************************************
void Bouton::setLongPressDelay(unsigned long delay)
{
	_dureeLongClic = delay;
}
unsigned long Bouton::getLongPressDelay()
{
	return _dureeLongClic;
}

//*********************************************************************
//Routine pour ajuster l'intervalle de temps entre chaque répétition
//dans l'état maintenu
//*********************************************************************
void Bouton::setLongPressInterval(unsigned long interval)
{
	_dureeRepetition = interval;
}
unsigned long Bouton::getLongPressInterval()
{
	return _dureeRepetition;
}