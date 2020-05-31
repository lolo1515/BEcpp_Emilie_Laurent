#include "core_simulation.h"
//#include "mydevices.h"
#include "sensor_lum.h"
#include "sensor_water.h"
#include "sensor_grain.h"
#include "actuator_door.h"
#include "actuator_pump.h"
#include "actuator_trap.h"
#include "display_screen.h"
#include "environnement.h"




int main(){

//==========projet============
 
 //démarrage simulateur projet
  initEnv();

  // creation d'une board
  Board esp8266;
  //création des instances de capteurs et d'actionneurs
  AnalogSensorLuminosity luminosity(1);
  ActuatorDoor porte(DELAY);
  DigitalSensorWater water(1);
  ActuatorPump pompe(DELAY);
  AnalogSensorGrain grain(1);
  ActuatorTrap trappe(DELAY);
  //création de l'écran
  I2CActuatorScreen screen;

  //link entre les instances précedement créées et la carte
  esp8266.pin(1,luminosity);
  esp8266.pin(2,porte);
  esp8266.pin(3,water);
  esp8266.pin(4,pompe);
  esp8266.pin(5,grain);
  esp8266.pin(6,trappe);

  esp8266.i2c(1,screen);
  // cout << "((((tututboard))))"<<endl;

//==========question==========
  /*AnalogSensorTemperature temperature(DELAY,TEMP);
  AnalogSensorLuminosity luminosity(DELAY);
  ExternalDigitalSensorButton bouton(DELAY);

  DigitalActuatorLED led1(DELAY);
  IntelligentDigitalActuatorLED ledSoleil(DELAY);

  I2CActuatorScreen screen;
  
  
  // branchement des capteurs actionneurs
  esp8266.pin(1,temperature);
  esp8266.pin(2,luminosity);
  esp8266.pin(4,bouton);

  esp8266.pin(3,ledSoleil);
  esp8266.pin(0,led1);

  esp8266.i2c(1,screen);*/
  
  // allumage de la carte
  esp8266.run();
  return 0;
}


