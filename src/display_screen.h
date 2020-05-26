#ifndef DISPLAY_SCREEN_H
#define DISPLAY_SCREEN_H

#include <iostream>
#include <unistd.h>
#include <string.h>
#include <fstream>
#include "core_simulation.h"




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


#endif 
