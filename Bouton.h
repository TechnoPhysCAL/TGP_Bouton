#ifndef Bouton_h
#define Bouton_h

#define DEFAULT_DEBOUNCE_DELAY 0
#define DEFAULT_NOMBRE_COMPTES 1
#define DEFAULT_lONG_PRESS_DELAY 1200
#define DEFAULT_lONG_PRESS_INTERVAL 200

#define RELACHE 0
#define RELACHANT 1
#define ENFONCE 2
#define ENFONCANT 3
#define MAINTENU 6
#define MAINTENANT 7

#include "Arduino.h"

//#ifdef __ESP__
//typedef std::function<void(void)> Callback;
//typedef std::function<bool(void)> BooleanGetter;
//#else
typedef void (*Callback)();
typedef bool (*BooleanGetter)();
//#endif

class Bouton
{
public:
	Bouton(BooleanGetter booleanGetter);
	Bouton(bool &variable);
	Bouton();

	void refresh(bool forceNow = false);

	void setStateGetter(BooleanGetter func);
	
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

	void setOnPressed(Callback func);
	void setOnLongPressed(Callback func);
	void setOnReleased(Callback func);

protected:
	void forward(bool);
	int changeEtat(unsigned long cur_time);
	virtual bool getNextValue();


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

	BooleanGetter _valueGetter;
	Callback _whenPressed;
	Callback _whenLongPressed;
	Callback _whenReleased;

	void doWhenPressed();
	void doWhenLongPressed();
	void doWhenReleased();

	bool* _boolRef = nullptr;

};

#endif