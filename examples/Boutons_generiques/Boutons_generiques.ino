/*
  ##  Librairie TPG Bouton - Boutons_generiques.ino

  ###DESCRIPTION
  Ce code présente comment utiliser la classe générique Bouton pour utiliser les fonctionnalités
  de la classe en utilisant des valeurs booléennes externes.

  Par défaut, le bouton générique a un temps de debounce de 0ms et une valeur de compte de 1

*/
#include <Bouton.h>  //Pour utiliser la librairie Bouton

// Initialisation du bouton générique avec une fonction en référence pour connaître l'état voulu du bouton
Bouton boutonA(&lireEtatBoutonA);  

bool etatB = false;
// Initialisation du bouton générique avec une variable booléenne en référence (non disponible pour certains microcontrôleurs)
Bouton boutonB(etatB);  

 // Initialisation du bouton générique avec une fonction lambda qui simule le bouton C (non disponible pour certains microcontrôleurs)
Bouton boutonC([](){return millis()%4000<2000;}); 

void setup() {
  Serial.begin(115200);  // Pour l'exemple, le port Série sera utilisé pour observer le comportemement du bouton.
}

void loop() {

  etatB = millis()%5000<2500; //Simulation du bouton B avec la variable etatB

  boutonA.refresh();
  
  if (boutonA.isPressed()) {  // condition VRAIE lorsque le bouton vient d'être appuyé.
    Serial.println("Le bouton A a été appuyé.");
  }
  if (boutonA.isLongPressed()) {  // condition VRAIE lorsque le bouton a été maintenu assez longtemps. La condition VRAIE reviendra périodiquement.
    Serial.println("Le bouton A a été appuyé longtemps.");
  }
  if (boutonA.isReleased())  // condition VRAIE lorsque le bouton vient d'être relâché.
  {
    Serial.println("Le bouton A a été relâché.");
  }

  boutonB.refresh();

  if (boutonB.isPressed()) {  // condition VRAIE lorsque le bouton vient d'être appuyé.
    Serial.println("Le bouton B a été appuyé.");
  }
  if (boutonB.isLongPressed()) {  // condition VRAIE lorsque le bouton a été maintenu assez longtemps. La condition VRAIE reviendra périodiquement.
    Serial.println("Le bouton B a été appuyé longtemps.");
  }
  if (boutonB.isReleased())  // condition VRAIE lorsque le bouton vient d'être relâché.
  {
    Serial.println("Le bouton B a été relâché.");
  }

  boutonC.refresh();

  if (boutonC.isPressed()) {  // condition VRAIE lorsque le bouton vient d'être appuyé.
    Serial.println("Le bouton C a été appuyé.");
  }
  if (boutonC.isLongPressed()) {  // condition VRAIE lorsque le bouton a été maintenu assez longtemps. La condition VRAIE reviendra périodiquement.
    Serial.println("Le bouton C a été appuyé longtemps.");
  }
  if (boutonC.isReleased())  // condition VRAIE lorsque le bouton vient d'être relâché.
  {
    Serial.println("Le bouton C a été relâché.");
  }
}

//fonction qui simule l'état du bouton A (vrai==appuyé, faux==relâché).
bool lireEtatBoutonA() {
  return millis()%3000<1500; //Bouton simulé qui est appuyé durant 2.5 secondes et relâché 1 seconde.
  
}
