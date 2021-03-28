#ifndef Bouton_h
#define Bouton_h

#include "BoutonBase.h"

class Bouton : public BoutonBase
{
  public:
   Bouton(int address);
   Bouton(int address,bool rising,bool pullup);
	
  protected:
   bool isDetected();
	
  private:
    int _address;
  	int _front;
  

  	
};
#endif