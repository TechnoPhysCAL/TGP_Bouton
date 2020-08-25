#ifndef Bouton_h
#define Bouton_h

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
	Bouton();

	void refresh();

	bool isPressed();
	bool isReleased();
	bool isLongPressed();

	bool isOnPress();
	bool isOnRelease();
	bool iSOnLongPress();

	void setReboundDelay(unsigned long);
	void setLongPressDelay(unsigned long);
	void setLongPressInterval(unsigned long);

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

	unsigned long _delayRebound;
	unsigned long _dureeLongClic;
	unsigned long _dureeRepetition;

};
#endif