#include "Bouton.h"

Bouton::Bouton()
{
	_lastEtat = RELACHE;
	_keyRegister = 0;
	_register_threshold = 255;

	_delayDebounce = DEFAULT_DEBOUNCE_DELAY;
	_dureeLongClic = DEFAULT_lONG_PRESS_DELAY;
	_dureeRepetition = DEFAULT_lONG_PRESS_INTERVAL;
}

void Bouton::setNbBits(uint8_t number_steps)
{
	switch (number_steps)
	{
	case 1:
		_register_threshold = 0b1;
		break;
	case 2:
		_register_threshold = 0b11;
		break;
	case 3:
		_register_threshold = 0b111;
		break;
	case 4:
		_register_threshold = 0b1111;
		break;
	case 5:
		_register_threshold = 0b11111;
		break;
	case 6:
		_register_threshold = 0b111111;
		break;
	case 7:
		_register_threshold = 0b1111111;
		break;
	default:

		_register_threshold = 0b11111111;
		break;
	}
}

void Bouton::refresh(bool newValue)
{

	unsigned long _actualSample = millis();

	if (_actualSample - _lastSample > _delayDebounce)
	{ // Si temps d'echantillonnage atteint
		_lastSample = _actualSample;

		forward(newValue); // Decale le registre
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

	if (_keyRegister >= _register_threshold)
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

void Bouton::forward(bool newValue)
{

	_keyRegister = _keyRegister >> 1;
	
	if (newValue)
	{
		_keyRegister += 0x80;
	}
}

//*********************************************************************
// Routine pour ajuster l'intervalle de temps pour ajouter les valeurs
// du bouton lu dans le registre à décalage.
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
// Routine pour ajuster l'intervalle de temps pour considerer un clic
// comme étant long
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
// Routine pour ajuster l'intervalle de temps entre chaque répétition
// dans l'état maintenu
//*********************************************************************
void Bouton::setLongPressInterval(unsigned long interval)
{
	_dureeRepetition = interval;
}
unsigned long Bouton::getLongPressInterval()
{
	return _dureeRepetition;
}