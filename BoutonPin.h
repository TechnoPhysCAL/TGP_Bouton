#ifndef BoutonPin_h
#define BoutonPin_h

#include "Bouton.h"
#define DEBOUNCE_DELAY_PIN 5
#define NOMBRE_COMPTES_PIN 4

class BoutonPin : public Bouton
{
public:
  BoutonPin(int address, bool rising = true, bool pullup = false);
  void begin();

protected:

bool getNextValue() override;

private:
  int _address;
  int _front;
  bool _pullup;
  bool _state;
};
#endif