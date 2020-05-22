#ifndef ACTUATOR_PUMP_H
#define ACTUATOR_PUMP_H

#include <iostream>
#include <unistd.h>
#include <string.h>
#include <fstream>
#include "core_simulation.h"
#include "environnement.h"


//classe pour agir sur la porte du poulailler 
class ActuatorPump: public Device {
private:
  //etat de la porte 
  int state;
  // temps entre 2 affichage de l etat de la porte
  int temps;
public:
  // initialisation du temps de rafraichissement
  ActuatorPump(int t);
  // thread representant l'actionneur et permettant de fonctionner independamment de la board
  virtual void run();
};

#endif
