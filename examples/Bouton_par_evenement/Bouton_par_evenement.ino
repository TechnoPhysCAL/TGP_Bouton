/*
  ## Librairie TPG Bouton - Bouton_par_evenement.ino

  ## Permet de configurer le comportement du bouton avec des fonctions de rappel (communémentent appelé *callback*)

  Note: ###NOTE

*/

#define PIN_BOUTON 34  // Le numéro de la broche sur laquelle est lu le bouton

#include <BoutonPin.h>  //Pour utiliser la librairie Bouton

BoutonPin monBouton(PIN_BOUTON);  // Initialisation du bouton sur le port choisi
// BoutonPin monBouton(PIN_BOUTON,true,true); // Initialisation du bouton sur le port choisi, front montant détecté, utilise le mode INPUT_PULLUP

void setup() {
  Serial.begin(115200);  // Pour l'exemple, le port Série sera utilisé pour observer le comportemement du bouton.

  //On peut fournir une référence à la fonction à apppler selon les trois événements possibles.
  monBouton.setOnPressed(&callbackAppuye);
  monBouton.setOnLongPressed(&callbackAppuyeLonguement);
  monBouton.setOnReleased(&callbackRelache);

}

void loop() {
  monBouton.refresh();  // Permet d'actualiser l'état du bouton. CETTE MÉTHODE EST OBLIGATOIRE EN DÉBUT DE LOOP(), IDÉALEMENT.
}

void callbackAppuye() {
  Serial.println("Le bouton a été appuyé.");
}

void callbackAppuyeLonguement() {
  Serial.println("Le bouton a été appuyé longtemps.");
}

void callbackRelache() {
  Serial.println("Le bouton a été relâché.");
}