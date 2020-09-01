/*
  Librairie TPG Bouton - Un_bouton.ino

  ###DESCRIPTION

  Note: ###NOTE

*/

#include <Bouton.h>  //Pour utiliser la librairie Bouton

const int pin = 34; //Le numéro de la broche sur laquelle est lu le bouton

Bouton monBouton(pin); // Initialisation du bouton sur le port choisi

void setup() {
  Serial.begin(115200); // Pour l'exemple, le port Série sera utilisé pour observer le comportemement du bouton.
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
