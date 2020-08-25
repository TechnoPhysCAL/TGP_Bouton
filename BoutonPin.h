#ifndef BoutonPin_h
#define BoutonPin_h

#define RELACHE 0
#define RELACHANT 1
#define ENFONCE 2
#define ENFONCANT 3
#define MAINTENU 6
#define MAINTENANT 7

#include "Bouton.h"

class BoutonPin : public Bouton
{
  public:
   BoutonPin(int address);
   BoutonPin(int address,int front,int pinMode);
	
  protected:
   bool isDetected();
	
  private:
    int _address;
  	int _front;
  

  	
};
#endif