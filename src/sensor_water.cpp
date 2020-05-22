#include "sensor_water.h"

//classe AnalogSensorWater
AnalogSensorWater::AnalogSensorWater(int d):Device(),temps(d){
    state = HIGH; 
}

void AnalogSensorWater::run(){
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
