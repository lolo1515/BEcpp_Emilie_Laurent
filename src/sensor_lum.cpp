#include "sensor_lum.h"


//classe AnalogSensorLuminosity
AnalogSensorLuminosity::AnalogSensorLuminosity(int d):Device(),temps(d) {
	alea=10;
}

void AnalogSensorLuminosity::run(){
  while(1){
    alea=10-alea;
    if(ptrmem!=NULL)
      *ptrmem=getLumEnv()+alea;
    sleep(temps);
  }
}
