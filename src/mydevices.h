#ifndef MYDEVICES_H
#define MYDEVICES_H

#include <iostream>
#include <thread>
#include <unistd.h>
#include <string.h>
#include <fstream>
#include "core_simulation.h"


/*

// exemple de capteur analogique de temperature, ne pas oublier d'heriter de Device
class AnalogSensorTemperature: public Device {
private:
  // fait osciller la valeur du capteur de 1
  int alea;
  // valeur de temperature mesuree
  int val;
  // temps entre 2 prises de valeurs
  int temps;
  
public:
  //constructeur ne pas oublier d'initialiser la classe mere
  AnalogSensorTemperature(int d,int  t);
  // thread representant le capteur et permettant de fonctionner independamment de la board
  virtual void run();
};





// exemple de capteur analogique de luminosité, ne pas oublier d'heriter de Device
class  AnalogSensorLuminosity: public Device {
private:
  // fait osciller la valeur du capteur de 10 lux
  int alea;
  // temps entre 2 prises de valeurs
  int temps;

public:
  //constructeur ne pas oublier d'initialiser la classe mere
  AnalogSensorLuminosity(int d);
  // thread representant le capteur et permettant de fonctionner independamment de la board
  virtual void run();
};





// exemple d'actionneur digital : une led, ne pas oublier d'heriter de Device
class DigitalActuatorLED: public Device {
private:
  // etat de la LED
  int state;
  // temps entre 2 affichage de l etat de la led
  int temps;
  
public:
    // initialisation du temps de rafraichiisement
  DigitalActuatorLED(int t);
  // thread representant l'actionneur et permettant de fonctionner independamment de la board
  virtual void run();
};





// exemple d'actionneur digital : une led, ne pas oublier d'heriter de Device
class IntelligentDigitalActuatorLED: public Device {
private:
  // etat de la LED
  int state;
  // temps entre 2 affichage de l etat de la led
  int temps;
  //permet de savoir si la led à déjà été allumé au moins une fois (faux sinon)
  bool init;
public:
    // initialisation du temps de rafraichiisement
  IntelligentDigitalActuatorLED(int t);
  // thread representant l'actionneur et permettant de fonctionner independamment de la board
  virtual void run();
};




//exemple d'interaction exterieure avec le simulateur
class  ExternalDigitalSensorButton: public Device {
private:
  //etat du bouton
  int state;
  //temps entre 2 prises de valeur
  int temps;
public:
   ExternalDigitalSensorButton(int t);
   virtual void run();
};
   


//classe pour agir sur la porte du poulailler 
class ActuatorPorte: public Device {
private:
  //etat de la porte 
  int state;
  // temps entre 2 affichage de l etat de la porte
  int temps;
public:
  // initialisation du temps de rafraichissement
  ActuatorPorte(int t);
  // thread representant l'actionneur et permettant de fonctionner independamment de la board
  virtual void run();
};



// exemple d'actionneur sur le bus I2C permettant d'echanger des tableaux de caracteres : un ecran, ne pas oublier d'heriter de Device
class I2CActuatorScreen : public Device{
protected:
    // memorise l'affichage de l'ecran
  char buf[I2C_BUFFER_SIZE];
  
public:
  // constructeur
  I2CActuatorScreen ();
  // thread representant le capteur et permettant de fonctionner independamment de la board
  virtual void run();
};



//classe pour gérer les variables d'environnement
class Environnement{
public:
  //Constructeur
  Environnement(int lum);
  //Méthodes pour récupérer et set la luminosité ambiante
  int getLum();
  int setLum();
}
*/

#endif
