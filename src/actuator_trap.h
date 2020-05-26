#ifndef ACTUATOR_TRAP_H
#define ACTUATOR_TRAP_H

#include <iostream>
#include <unistd.h>
#include <string.h>
#include <fstream>
#include "core_simulation.h"
#include "environnement.h"


//classe pour agir sur la porte du poulailler 
class ActuatorTrap: public Device {
private:
  //etat de la trappe à grain
  int state;
  // temps entre 2 affichage de l etat de la porte
  int temps;
public:
  // initialisation du temps de rafraichissement
  ActuatorTrap(int t);
  // thread representant l'actionneur et permettant de fonctionner independamment de la board
  virtual void run();
};

#endif
