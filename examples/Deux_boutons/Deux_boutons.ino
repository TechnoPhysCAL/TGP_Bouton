/*
  Librairie TPG Bouton - Deux_boutons.ino

  ###DESCRIPTION

  Note: ###NOTE

*/



#define PIN_BOUTON_A 34 //Le numéro de la broche sur laquelle est lu le bouton
#define PIN_BOUTON_B 35 //Le numéro de la broche sur laquelle est lu le bouton

#include <BoutonPin.h>  //Pour utiliser la librairie Bouton

BoutonPin boutonA(PIN_BOUTON_A); // Initialisation du bouton A sur le port choisi
BoutonPin boutonB(PIN_BOUTON_B); // Initialisation du bouton B sur le port choisi

void setup() {
  Serial.begin(115200); // Pour l'exemple, le port Série sera utilisé pour observer le comportemement du bouton.
}

void loop() {
  boutonA.refresh(); //Permet d'actualiser l'état du bouton. CETTE MÉTHODE EST OBLIGATOIRE EN DÉBUT DE LOOP(), IDÉALEMENT.
  boutonB.refresh(); //Permet d'actualiser l'état du bouton. CETTE MÉTHODE EST OBLIGATOIRE EN DÉBUT DE LOOP(), IDÉALEMENT.

  if (boutonA.isPressed()) { //condition VRAIE lorsque le bouton A vient d'être appuyé.
    Serial.println("Le bouton A a été appuyé.");
  }
  if (boutonA.isLongPressed()) { //condition VRAIE lorsque le bouton A a été maintenu assez longtemps. La condition VRAIE reviendra périodiquement.
    Serial.println("Le bouton A a été appuyé longtemps.");
  }
  if (boutonA.isReleased())//condition VRAIE lorsque le bouton A vient d'être relâché.
  {
    Serial.println("Le bouton A a été relâché.");
  }

  if (boutonB.isPressed()) { //condition VRAIE lorsque le bouton B vient d'être appuyé.
    Serial.println("Le bouton B a été appuyé.");
  }
  if (boutonB.isLongPressed()) { //condition VRAIE lorsque le bouton B a été maintenu assez longtemps. La condition VRAIE reviendra périodiquement.
    Serial.println("Le bouton B a été appuyé longtemps.");
  }
  if (boutonB.isReleased())//condition VRAIE lorsque le bouton B vient d'être relâché.
  {
    Serial.println("Le bouton B a été relâché.");
  }
}
