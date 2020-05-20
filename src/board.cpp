#include "core_simulation.h"
//#include "mydevices.h"
#include "sensor_lum.h"
#include "environnement.h"


int main(){
  // creation d'une board
  Board esp8266;
  // achat des senseurs et actionneurs

//==========projet============
  //démarrage simulateur projet
  initEnv();
  AnalogSensorLuminosity luminosity(DELAY);
  //ActuatorPorte porte(DELAY);

  //I2CActuatorScreen screen;


  esp8266.pin(1,luminosity);
 // esp8266.pin(2,porte);
 // esp8266.i2c(1,screen);


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


