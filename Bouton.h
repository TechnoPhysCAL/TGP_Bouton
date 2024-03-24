#ifndef Bouton_h
#define Bouton_h

#include "BoutonBase.h"

class Bouton : public BoutonBase
{
public:
  Bouton();
  Bouton(int address);
  Bouton(int address, bool rising, bool pullup);
 bool _nextValue;
protected:
  bool isDetected();

private:
  int _address;
  int _front;
 
};
#endif