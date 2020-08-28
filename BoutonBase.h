#ifndef BoutonBase_h
#define BoutonBase_h

#define DEFAULT_DEBOUNCE_DELAY 5

#define DEFAULT_lONG_PRESS_DELAY 1500
#define DEFAULT_lONG_PRESS_INTERVAL 200

#define RELACHE 0
#define RELACHANT 1
#define ENFONCE 2
#define ENFONCANT 3
#define MAINTENU 6
#define MAINTENANT 7

#include "Arduino.h"

class BoutonBase
{
  public:
	BoutonBase();

	void refresh();

	bool isPressed();
	bool isReleased();
	bool isLongPressed();

	bool isOnPress();
	bool isOnRelease();
	bool isOnLongPress();

	void setDebounceDelay(unsigned long);
	unsigned long getDebounceDelay();
	void setLongPressDelay(unsigned long);
	unsigned long getLongPressDelay();
	void setLongPressInterval(unsigned long);
	unsigned long getLongPressInterval();


  protected:
	void forward();
	virtual bool isDetected(){return false;}
	void up();
	int changeEtat(unsigned long cur_time);
	
 private:
  	int _keyRegister;
	int _lastEtat;
	unsigned long time_started;
	unsigned long time_maintenu_started;

	unsigned long _lastSample;

	unsigned long _delayDebounce;
	unsigned long _dureeLongClic;
	unsigned long _dureeRepetition;

};
#endif