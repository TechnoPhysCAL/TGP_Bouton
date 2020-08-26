#include "BoutonBase.h"

BoutonBase::BoutonBase()
{
	_lastEtat = RELACHE;
	_keyRegister = 0;

	_delayDebounce = DEFAULT_DEBOUNCE_DELAY;
	_dureeLongClic = DEFAULT_lONG_PRESS_DELAY;
	_dureeRepetition = DEFAULT_lONG_PRESS_INTERVAL;
}

void BoutonBase::refresh()
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

bool BoutonBase::isPressed()
{
	return (_lastEtat == ENFONCANT);
}
bool BoutonBase::isReleased()
{
	return (_lastEtat == RELACHANT);
}
bool BoutonBase::isLongPressed()
{
	return (_lastEtat == MAINTENANT);
}

bool BoutonBase::isOnPress()
{
	return (_lastEtat == ENFONCE || _lastEtat == ENFONCANT);
}
bool BoutonBase::isOnRelease()
{
	return (_lastEtat == RELACHE || _lastEtat == RELACHANT);
}
bool BoutonBase::isOnLongPress()
{
	return (_lastEtat == MAINTENU || _lastEtat == MAINTENANT);
}

int BoutonBase::changeEtat(unsigned long cur_time)
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

void BoutonBase::forward()
{

	_keyRegister = _keyRegister >> 1;
}

void BoutonBase::up()
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
void BoutonBase::setDebounceDelay(unsigned long delay)
{
	_delayDebounce = delay;
}
unsigned long BoutonBase::getDebounceDelay()
{
	return _delayDebounce;
}

//*********************************************************************
//Routine pour ajuster l'intervalle de temps pour considerer un clic
//comme étant long
//*********************************************************************
void BoutonBase::setLongPressDelay(unsigned long delay)
{
	_dureeLongClic = delay;
}
unsigned long BoutonBase::getLongPressDelay()
{
	return _dureeLongClic;
}

//*********************************************************************
//Routine pour ajuster l'intervalle de temps entre chaque répétition
//dans l'état maintenu
//*********************************************************************
void BoutonBase::setLongPressInterval(unsigned long interval)
{
	_dureeRepetition = interval;
}
unsigned long BoutonBase::getLongPressInterval()
{
	return _dureeRepetition;
}