/*
  Librairie TPG Bouton - Bouton_parametree.ino

  ###DESCRIPTION

  Note: ###NOTE

*/

#include <Bouton.h>  //Pour utiliser la librairie Bouton

const int pin = 34; //Le numéro de la broche sur laquelle est lu le bouton

Bouton monBouton(pin); // Initialisation du bouton sur le port choisi

void setup() {
  Serial.begin(115200); // Pour l'exemple, le port Série sera utilisé pour observer le comportemement du bouton.

  monBouton.setDebounceDelay(6); //Ajuste de 'Debounce' pour la détection du bouton à 6 millisecondes. (Par défaut : 5 millisecondes);
  
  monBouton.setLongPressDelay(500); //Le bouton sera considéré en 'longPress' s'il est appuyé plus de 500 millisecondes.  (Par défaut : 2000 millisecondes);
  
  monBouton.setLongPressInterval(100); //La condition 'isLongPressed' reviendra vraie périodiquement, à chaque 100 millisecondes. (Par défaut : 200 millisecondes);
}

void loop() {
  monBouton.refresh(); //Permet d'actualiser l'état du bouton. CETTE MÉTHODE EST OBLIGATOIRE EN DÉBUT DE LOOP(), IDÉALEMENT.

  if (monBouton.isPressed()) { //condition VRAIE lorsque le bouton vient d'être appuyé.
    Serial.println("Le bouton a été appuyé.");
  }
  if (monBouton.isLongPressed()) { //condition VRAIE lorsque le bouton a été maintenu assez longtemps. La condition VRAIE reviendra périodiquement.
    Serial.println("Le bouton a été appuyé longtemps.");
  }
  if (monBouton.isReleased())//condition VRAIE lorsque le bouton vient d'être relâché.
  {
    Serial.println("Le bouton a été relâché.");
  }
}
