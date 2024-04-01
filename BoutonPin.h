#ifndef BoutonPin_h
#define BoutonPin_h

#include "Bouton.h"

class BoutonPin : public Bouton
{
public:
  BoutonPin(int address, bool rising = true, bool pullup = false);
  void begin();

private:
#ifdef __AVR__
  bool getNextValue() override;
#endif
  int _address;
  int _front;
  bool _pullup;
};
#endif