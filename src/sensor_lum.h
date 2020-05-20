#ifndef SENSOR_LUM_H
#define SENSOR_LUM_H

#include <iostream>
#include <thread>
#include <unistd.h>
#include <string.h>
#include <fstream>
#include "core_simulation.h"
#include "environnement.h"

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


#endif
