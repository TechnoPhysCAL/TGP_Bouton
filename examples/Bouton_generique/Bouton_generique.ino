/*
  ##  Librairie TPG Bouton - Bouton_generique.ino

  ###DESCRIPTION
  Ce code présente comment utiliser la classe générique Bouton pour utiliser les fonctionnalités
  de la classe en utilisant une valeur booléenne externe.

*/
#include <Bouton.h>  //Pour utiliser la librairie Bouton
Bouton monBouton(&lireEtat);  // Initialisation du bouton générique avec une fonction pour connaître l'état voulu du bouton

//NOTE : On peut utiliser une fonction lambda pour simplifier l'écriture.

//Bouton monBouton([](){return millis()%3000<2000;});  // Initialisation du bouton générique avec une fonction pour connaître l'état voulu du bouton


void setup() {
  Serial.begin(115200);  // Pour l'exemple, le port Série sera utilisé pour observer le comportemement du bouton.
}

void loop() {
   monBouton.refresh();  // On peut simplifier l'écriture avec une fonction "anonyme", comme ici.

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

//Cette fonction est responsable de fournir une valeur booléenne qui représente l'état du bouton (vrai==appuyé, faux==relâché).
bool lireEtat() {
  return millis()%3000<2000; //Bouton simulé qui est appuyé durant 2.5 secondes et relâché 1 seconde.
  
}
