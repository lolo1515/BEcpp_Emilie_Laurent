#ifndef SENSOR_WATER_H
#define SENSOR_WATER_H

#include <iostream>
#include <unistd.h>
#include <string.h>
#include <fstream>
#include "core_simulation.h"
#include "environnement.h"


// exemple de capteur digital de niveau d'eau, ne pas oublier d'heriter de Device
class  DigitalSensorWater: public Device {
private:
  //etat du bouton
  int state;
  // temps entre 2 prises de valeurs
  int temps;

public:
  //constructeur ne pas oublier d'initialiser la classe mere
  DigitalSensorWater(int d);
  // thread representant le capteur et permettant de fonctionner independamment de la board
  virtual void run();
};


#endif 
