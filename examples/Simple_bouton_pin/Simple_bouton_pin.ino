/*
  Librairie TPG Bouton - Simple_bouton_pin.ino

  ###DESCRIPTION
    Permet de lire simplement un bouton branché sur une broche digitale.

  Note: ###NOTE

*/

#define PIN_BOUTON 34 // Le numéro de la broche sur laquelle est lu le bouton
#include <BoutonPin.h> //Pour utiliser la librairie Bouton

BoutonPin monBouton(PIN_BOUTON); // Initialisation du bouton sur la broche choisi
// BoutonPin monBouton(PIN_BOUTON,true,true); // ALTERNATIVE : Initialisation du bouton sur la broche choisi, front montant détecté, utilise le mode INPUT_PULLUP

void setup()
{
  Serial.begin(115200); // Pour l'exemple, le port Série sera utilisé pour observer le comportemement du bouton.
  monBouton.begin();  //Nécessaire pour configurer adéquatement la broche

  monBouton.setDebounceDelay(5);       // Ajuste de 'Debounce' pour la détection du bouton à 5 millisecondes. (Par défaut : 5 millisecondes);
  monBouton.setLongPressDelay(1500);    // Le bouton sera considéré en 'longPress' s'il est appuyé plus de 500 millisecondes.  (Par défaut : 1500 millisecondes);
  monBouton.setLongPressInterval(200); // La condition 'isLongPressed' reviendra vraie périodiquement, à chaque 100 millisecondes. (Par défaut : 200 millisecondes);
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
