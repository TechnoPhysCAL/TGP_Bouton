
#ifndef Clavier5B_h
#define Clavier5B_h

#include "Bouton.h"

class Clavier5B
{
  public:
   Clavier5B();
   virtual Bouton gauche()=0;
   virtual Bouton droite()=0;
   virtual Bouton haut()=0;
   virtual Bouton bas()=0;
   virtual Bouton selection()=0;
	
  protected:

  private:

  	
};
#endif