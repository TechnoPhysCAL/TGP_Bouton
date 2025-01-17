/*
  ## Librairie TPG Bouton - Bouton_simple.ino

  ###DESCRIPTION
    Permet de lire un bouton branché sur une broche digitale.

*/

#define PIN_BOUTON 34 // Le numéro de la broche sur laquelle est lu le bouton
#include <BoutonPin.h> //Pour utiliser la librairie Bouton

BoutonPin monBouton(PIN_BOUTON); // Initialisation du bouton sur la broche choisi
// BoutonPin monBouton(PIN_BOUTON,true,true); // ALTERNATIVE : Initialisation du bouton sur la broche choisi, front montant détecté, utilise le mode INPUT_PULLUP

void setup()
{
  Serial.begin(115200); // Pour l'exemple, le port Série sera utilisé pour observer le comportemement du bouton.
  monBouton.begin();  //Nécessaire pour configurer adéquatement la broche
}

void loop()
{
  monBouton.refresh(); // Permet d'actualiser l'état du bouton. CETTE MÉTHODE EST OBLIGATOIRE EN DÉBUT DE LOOP(), IDÉALEMENT.

  if (monBouton.isPressed())
  { // condition VRAIE lorsque le bouton vient d'être appuyé.
    Serial.println("Le bouton a été appuyé.");
  }
  if (monBouton.isLongPressed())
  { // condition VRAIE lorsque le bouton a été maintenu assez longtemps. La condition VRAIE reviendra périodiquement.
    Serial.println("Le bouton a été appuyé longtemps.");
  }
  if (monBouton.isReleased()) // condition VRAIE lorsque le bouton vient d'être relâché.
  {
    Serial.println("Le bouton a été relâché.");
  }
 
}
