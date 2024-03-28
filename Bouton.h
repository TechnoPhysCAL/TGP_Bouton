#ifndef Bouton_h
#define Bouton_h

#define DEFAULT_DEBOUNCE_DELAY 5
#define DEFAULT_NOMBRE_COMPTES 4
#define DEFAULT_lONG_PRESS_DELAY 1500
#define DEFAULT_lONG_PRESS_INTERVAL 200

#define RELACHE 0
#define RELACHANT 1
#define ENFONCE 2
#define ENFONCANT 3
#define MAINTENU 6
#define MAINTENANT 7


#include "Arduino.h"


class Bouton
{
public:
	Bouton(unsigned long debounceDelay = DEFAULT_DEBOUNCE_DELAY, uint8_t nbComptes = DEFAULT_NOMBRE_COMPTES, unsigned long longPressDelay = DEFAULT_lONG_PRESS_DELAY, unsigned long longPressInterval = DEFAULT_lONG_PRESS_INTERVAL);

	void refresh(std::function<bool()> f, bool forceNow=false);

	bool isPressed();
	bool isReleased();
	bool isLongPressed();

	bool isOnPress();
	bool isOnRelease();
	bool isOnLongPress();

	void setNbComptes(uint8_t);
	uint8_t getNbComptes();
	void setDebounceDelay(unsigned long);
	unsigned long getDebounceDelay();
	void setLongPressDelay(unsigned long);
	unsigned long getLongPressDelay();
	void setLongPressInterval(unsigned long);
	unsigned long getLongPressInterval();

protected:
	void forward(bool);
	int changeEtat(unsigned long cur_time);

private:
	int _keyRegister;
	uint8_t _register_threshold;
	int _lastEtat;
	unsigned long time_started;
	unsigned long time_maintenu_started;

	unsigned long _lastSample;

	unsigned long _debounceDelay;
	uint8_t _nbComptes;
	unsigned long _longPressDelay;
	unsigned long _longPressInterval;
};

#endif