#ifndef Bouton_h
#define Bouton_h

#define RELACHE 0
#define RELACHANT 1
#define ENFONCE 2
#define ENFONCANT 3
#define MAINTENU 6
#define MAINTENANT 7

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