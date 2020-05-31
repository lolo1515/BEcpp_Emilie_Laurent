#include "sensor_water.h"

//classe DigitalSensorWater
DigitalSensorWater::DigitalSensorWater(int d):Device(),temps(d){
    state = HIGH; 
}


/*le capteur est digital donc tout ou rien, 
on met donc en place, dans le thread run, 
un seuil de niveau d'eau pour lequel nous 
considererons le capteur comme n'étant plus immergé
et donc il retournera "LOW"*/
void DigitalSensorWater::run(){
  while(1){

	//optionnel, pour débogage
	cout<<"water: "<<getWaterEnv()<<" mL\n";

	/*si la variable globale water_level retourné par getWaterEnv est 
	inférieur à 1000ml, alors le capteur digital renvoi "LOW"*/
    if (getWaterEnv()<1000){
	state = LOW;
	*ptrmem=state;
    }
	/*si la variable globale water_level retourné par getWaterEnv est 
	supérieur à 1000ml, alors le capteur digital est immergé et il renvoi "HIGH"*/
    else {
    	state = HIGH;
	*ptrmem=state;
    }
    sleep(temps);
  }
}
