#include "sensor_grain.h"


//classe AnalogSensorGrain
AnalogSensorGrain::AnalogSensorGrain(int d):Device(),temps(d) {
	alea=1;
}

void AnalogSensorGrain::run(){
  while(1){
    alea=1-alea;
    if(ptrmem!=NULL)
      *ptrmem=getGrainEnv()+alea;
    sleep(temps);
  }
}
