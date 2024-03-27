#ifndef BoutonPin_h
#define BoutonPin_h

#include "Bouton.h"

class BoutonPin : public Bouton
{
public:
  BoutonPin(int address, bool rising=LOW, bool pullup=false);
  void refresh();

private:
  void refresh(bool);
  int _address;
  int _front;
};
#endif