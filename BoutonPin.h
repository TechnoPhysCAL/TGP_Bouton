#ifndef BoutonPin_h
#define BoutonPin_h

#include "Bouton.h"

class BoutonPin : public Bouton
{
public:
  BoutonPin(int address, bool rising=true, bool pullup=false);
  void rafraichir();
  bool operator()() const;
private:
  int _address;
  int _front;
};
#endif