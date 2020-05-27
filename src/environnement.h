/*Ce code à été dévellopé par Emilie ESTIVAL et Laurent DEVEZ
dans le cadre du BE de Programmation Orienté Objet de 4°année AE-SE à l'INSA TOULOUSE

Il permet de simuler grossièrement un poullailer et les poules qui s'y trouvent. 
Le poulailler est constitué d'un abreuvoir(water_level), d'une mangeoire(grain_level), 
d'un environnement extérieur(luminosite_environnement) et de poules.
La luminosité de l'environnement oscille sinuosidallement entre 0 et 2000lux
Le niveau d'eau évolue entre 0 et 10000mL en fonction des poules qui se trouvent dans le poulailler.
Le niveau de grain évolue entre 0 et 50cM en fonction des poules qui se trouvent dans le poulailler.*/

#ifndef ENVIRONNEMENT_H
#define ENVIRONNEMENT_H

#include <pthread.h>
#include <cmath>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

/*cette fonction est appelé dans le main de board.cpp,
elle permet de lancer l'initialisaiton de tout le simulateur*/
void initEnv();

//assesseur luminosite_environnement
int getLumEnv();
/*ce thread va faire évoluer la luminosité de l'environnement
de 0 à 2000 lux en suivant une sinusoide de période 24s représentant les 24h d'une journée*/
void *threadLum(void *_arg);

//assesseur water_level
int getWaterEnv();
//mutateur water_level
void setWaterEnv();
/*ce thread va faire évoluer le niveau d'eau de l'environnement
en appelant toutes les secondes (cad heure pour le simulateur)
la méthode de classe Boivent() (cf commentaire Boivent) */
void *threadWat(void *_arg);

//assesseur grain_level
int getGrainEnv();
//mutateur grain_level
void setGrainEnv();
/*ce thread va faire évoluer le niveau de grain de l'environnement
en appelant toutes les secondes (cad heure pour le simulateur)
la méthode de classe Picorrent() (cf commentaire Picorrent) */
void *threadGrain(void *_arg);



class Poule{
private :
/*les deux attributs suivant représente la consomation en grain et en eau 
d'une instance de la classe, donc d'une poule*/ 
  int faim;
  int soif;

/*les deux variables de classe suivante,
représente la consomation totale en grain et en eau de toutes les poules du poulailler 
(somme de la faim et de la soif de toute les poules créées)*/
  static int consoGrainTot;
  static int consoEauTot;

public :
/*constructeur sans argument classe poule,
à noter ici que les attribut faim et soif de chaque poul créées
sont ajouté aux varible de classe consoGrainTot et consoEauTot */
  Poule();
/*constructeur avec argument classe poule,
à noter ici que les attribut faim et soif de chaque poul créées
sont ajouté aux varible de classe consoGrainTot et consoEauTot */
  Poule(int grain, int eau);

/*cette méthode permet d'initialiser la simulation de la présence de poule dans le poulailler*/
  static void Run();

/*cette méthode de classe est appelé périodiquement par le threadGrain, 
soustrait à grain_level (var global du niveau de grain) la valeur de consoGraintot (variable de classe)
si la quantité de grain ne suffit plus à la consommation des poules, la méthode lance une exception*/
  static void Picorent();

/*cette méthode de classe est appelé périodiquement par le threadWater, 
soustrait à water_level (var global du niveau d'eau) la valeur de consoEautot (variable de classe)
si la quantité de grain ne suffit plus à la consommation des poules, la méthode lance une exception*/
  static void Boivent();

//ascesseur attribut faim
  int getFaim();
//ascesseur attribut eau
  int getSoif();
};

/*surcharge d'opérateur '+',
retourne une poule qui aura comme faim et soif une moyenne de la faim et de la soif de ses "parents".*/
Poule operator+(Poule Pa, Poule Pb);
  




#endif 
