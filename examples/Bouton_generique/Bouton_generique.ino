/*
  Librairie TPG Bouton - Bouton_generique.ino

  ### Ce code présente comment utiliser la classe générique Bouton pour utiliser les fonctionnalités
  de la classe en utilisant une valeur booléenne externe.

  Note: ###NOTE

*/

#define PIN_BOUTON 34  // Le numéro de la broche sur laquelle est lu le bouton

#include <Bouton.h>  //Pour utiliser la librairie Bouton

Bouton monBouton;  // Initialisation du bouton générique sur le port choisi

void setup() {
  pinMode(PIN_BOUTON, INPUT);
  Serial.begin(115200);  // Pour l'exemple, le port Série sera utilisé pour observer le comportemement du bouton.
}

void loop() {
  //monBouton.refresh(&readNewValue);  // Permet d'actualiser l'état du bouton, en fournissant une fonction qui permet de lire l'état booleen du bouton souhaité.

   monBouton.refresh([=](){return digitalRead(PIN_BOUTON) == LOW;});  // On peut simplifier l'écriture avec une fonction "anonyme", comme ici.

  if (monBouton.isPressed()) {  // condition VRAIE lorsque le bouton vient d'être appuyé.
    Serial.println("Le bouton a été appuyé.");
  }
  if (monBouton.isLongPressed()) {  // condition VRAIE lorsque le bouton a été maintenu assez longtemps. La condition VRAIE reviendra périodiquement.
    Serial.println("Le bouton a été appuyé longtemps.");
  }
  if (monBouton.isReleased())  // condition VRAIE lorsque le bouton vient d'être relâché.
  {
    Serial.println("Le bouton a été relâché.");
  }
}

bool readNewValue() {
  return digitalRead(PIN_BOUTON) == LOW;
}
