#include "sensor_water.h"

//classe DigitalSensorWater
DigitalSensorWater::DigitalSensorWater(int d):Device(),temps(d){
    state = HIGH; 
}

void DigitalSensorWater::run(){
  while(1){
    /*if(ptrmem!=NULL)
      *ptrmem=getWaterEnv()+alea;*/
    if (getWaterEnv()<1000){
	state = LOW;
	*ptrmem=state;
    }
    else {
    	state = HIGH;
	*ptrmem=state;
    }
    sleep(temps);
  }
}
