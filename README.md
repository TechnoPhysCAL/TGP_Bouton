# Librairie TGP Bouton

Permet la création de boutons. Permet de détecter si le bouton a été appuyé, maintenu appuyé ou relâché.

## Notes de version

### 2.0.2 : 

 - Uniformisation des typedef pour BooleanGetter et Callback.
### 2.0.0 : 
 - Refonte pour que Bouton.h gère les comportements virtuels et que BoutonPin gère un bouton matériel simple.
 - Constructeurs simplifiés, les paramètres temporels sont relégués dans les méthodes correspondantes;
 - Permet l'utilisation d'un bouton générique via une fonction de référence ou une variable booléenne en référence;
 - Permet l'utilisation des fonctions lambdas;
 - Permet l'utilisation de fonctions callbacks pour attacher les comportements liés aux événements du bouton;
 


## Détails

Le graphique illustre l'évolution temporelle de l'état du bouton et de ses différentes méthodes, lorsqu'on appuie dessus. Les valeurs retournées sont booléennes (True ou False).

![Timing](timing.svg)

## Utilisation

La version la plus courante est celui d'un bouton branché sur une broche digitale.

```cpp
#include <BoutonPin.h> 
#define PIN 34

BoutonPin monBouton(PIN); 

void setup() {
  monBouton.begin();
}

void loop() {
  monBouton.refresh(); 

  if (monBouton.isPressed()) { 
    //condition VRAIE lorsque le bouton vient d'être appuyé.
  }
  if (monBouton.isLongPressed()) { 
    //condition VRAIE lorsque le bouton a été maintenu assez 
    // longtemps. La condition VRAIE reviendra périodiquement.

  }
  if (monBouton.isReleased())
  {
    //condition VRAIE lorsque le bouton vient d'être relâché.
  }
}
```

## Constructeurs

### Bouton
```cpp
Bouton(bool& variable)
Bouton(bool (*booleanGetter)())
Bouton([]()->bool{return false;})
```
Le constructeur de la classe `Bouton` permet de créer un bouton avec une fonction personnalisée (fonction sans argument qui retourne un booléen) afin d'obtenir l'état du bouton. La fonction peut être donnée en référence, ou être une fonction lambda.
On peut aussi fournir simplement une variable booléenne par référence.

### BoutonPin
```cpp
BoutonPin(int pin)
BoutonPin(int pin, bool useRising, bool usePullup); 
```
On spécifie le numéro de la broche sur lequel est branché le bouton. On peut spécifier également si c'est le front montant (true) ou descendant (false) qui est considéré comme appuyé, et l'utilisation ou non de la résistance pullup interne.

## Méthodes disponibles


### Bouton
```cpp
void refresh()
```
Cette méthode doit être placée en début de boucle loop(): elle permet de mettre à jour l'état du bouton sans bloquer l'exécution du reste de la boucle.

```cpp
bool isPressed()
```
Permet savoir si le bouton vient d'être appuyé.

```cpp
bool isReleased()
```
Permet savoir si le bouton vient d'être relâché.

```cpp
bool isLongPressed()
```
Permet savoir si le bouton vient est maintenu appuyé. La condition devient vrai après le délai prévu, et reviendra vrai à intervalles réguliers.

```cpp
bool isOnPress();
bool isOnRelease();
bool isOnLongPress();
```
Permet de connaître l'état du bouton; contrairement aux méthodes précédentes, la valeur peut rester vrai en continu, et non seulement lorsque du changement d'état.

```cpp
void setDebounceDelay(unsigned long)
unsigned long getDebounceDelay()
```
Permet de lire et modifier le temps de "debouncing" en millisecondes pour s'assurer de l'effet de rebond d'un bouton mécanique et éviter les faux positifs (voir la méthode setNbComptes).
Valeur par défaut dans Bouton : 0 ms.
Valeur par défaut dans BoutonPin : 5 ms.

```cpp
void setLongPressDelay(unsigned long);
unsigned long getLongPressDelay();
```
Permet de lire et modifier le temps en millisecondes nécessaire pour que le bouton soit considéré comme 'maintenu longtemps'. Valeur par défaut : 1200 ms.

```cpp
void setLongPressInterval(unsigned long);
unsigned long getLongPressInterval();
```
Permet de lire et modifier le temps en millisecondes entre chaque valeur vraie de la méthode  'isLongPressed()'. Valeur par défaut : 200 ms.

```cpp
void setStateGetter(bool (*stateGetter)());
```
Permet de définir une fonction personnalisée pour obtenir l'état du bouton. La fonction ne prend pas d'argument et doit retourner un booléen.

```cpp
void setNbComptes(int nbComptes);
int getNbComptes();
```
Permet de définir et obtenir le nombre de comptes pour le bouton, dans le but d'éviter de faux positifs. Par exemple, si le compte vaut 3, le bouton devra avoir lu trois fois la valeurs VRAI (espacé par la durée du debouncing) avant émettre l'évènement IsPressed. 
Valeur par défaut dans Bouton : 1
Valeur par défaut dans BoutonPin : 4

### BoutonPin
```cpp
void begin()
```
Initialise le bouton matériel.
