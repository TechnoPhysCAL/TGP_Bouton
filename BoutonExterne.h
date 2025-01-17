#ifndef BoutonExterne_h
#define BoutonExterne_h

#include "Bouton.h"

class BoutonExterne : public Bouton
{
public:
	BoutonExterne(unsigned long debounceDelay = DEFAULT_DEBOUNCE_DELAY, uint8_t nbComptes = DEFAULT_NOMBRE_COMPTES, unsigned long longPressDelay = DEFAULT_lONG_PRESS_DELAY, unsigned long longPressInterval = DEFAULT_lONG_PRESS_INTERVAL);
	void setNextValue(bool);

protected:
#ifdef __AVR__
	bool getNextValue() override;
#endif
private:
	bool _nextValue;
};

#endif