/*
  Librairie TPG Bouton - Un_bouton.ino

  ###DESCRIPTION

  Note: ###NOTE

*/

#define PIN_BOUTON 34  // Le numéro de la broche sur laquelle est lu le bouton

#include <BoutonPin.h>  //Pour utiliser la librairie Bouton

BoutonPin monBouton(PIN_BOUTON);  // Initialisation du bouton sur le port choisi
// BoutonPin monBouton(PIN_BOUTON,true,true); // Initialisation du bouton sur le port choisi, front montant détecté, utilise le mode INPUT_PULLUP

void setup() {
  Serial.begin(115200);  // Pour l'exemple, le port Série sera utilisé pour observer le comportemement du bouton.

  //On peut fournir une référence à la fonction à apppler selon les trois événements possibles.
  monBouton.setOnPressed(&routineQuandAppuye);
  monBouton.setOnLongPressed(&routineQuandAppuyeLonguement);
  monBouton.setOnReleased(&routineQuandRelache);

  //On peut aussi simplifier l'écriture avec une fonction anonyme :
  //monBouton.setOnPressed([](){Serial.println("Le bouton a été appuyé.");});
  //monBouton.setOnLongPressed([](){Serial.println("Le bouton a été appuyé longement.");});
  //monBouton.setOnReleased([](){Serial.println("Le bouton a été relâché.");});
}

void loop() {
  monBouton.refresh();  // Permet d'actualiser l'état du bouton. CETTE MÉTHODE EST OBLIGATOIRE EN DÉBUT DE LOOP(), IDÉALEMENT.
}


void routineQuandAppuye() {
  Serial.println("Le bouton a été appuyé.");
}

void routineQuandAppuyeLonguement() {
  Serial.println("Le bouton a été appuyé longtemps.");
}

void routineQuandRelache() {
  Serial.println("Le bouton a été relâché.");
}