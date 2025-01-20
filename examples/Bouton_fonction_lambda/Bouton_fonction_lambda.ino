/*
  ## Librairie TPG Bouton - Bouton_fonction_lambda.ino

  ###DESCRIPTION

  Permet de configurer le comportement du bouton avec des fonctions lambda.

  IMPORTANT: Certains microcontrôleurs ne supportent pas l'utilisation des fonctions lambda.

*/

#define PIN_BOUTON 34  // Le numéro de la broche sur laquelle est lu le bouton
#include <BoutonPin.h>  //Pour utiliser la librairie Bouton

BoutonPin monBouton(PIN_BOUTON);  // Initialisation du bouton sur le port choisi

void setup() {
  Serial.begin(115200);  // Pour l'exemple, le port Série sera utilisé pour observer le comportemement du bouton.

  //On peut fournir une fonction anonyme à apppler selon les trois événements possibles.
  monBouton.setOnPressed([](){Serial.println("Le bouton a été appuyé.");});
  monBouton.setOnLongPressed([](){Serial.println("Le bouton a été appuyé longement.");});
  monBouton.setOnReleased([](){Serial.println("Le bouton a été relâché.");});

  monBouton.begin(); //Nécessaire pour un bouton branché sur une broche
}

void loop() {
  monBouton.refresh();  // Permet d'actualiser l'état du bouton. CETTE MÉTHODE EST OBLIGATOIRE EN DÉBUT DE LOOP(), IDÉALEMENT.
}
