#include "actuator_door.h"

//classe ActuatorPorte
ActuatorDoor::ActuatorDoor(int t):Device(),state(LOW),temps(t){
}

void ActuatorDoor::run(){
  while(1){
    if(ptrmem!=NULL)
      	state=*ptrmem;
    if (state==LOW)
      	cout << "((((porte fermée))))\n"<<endl;
    else {
    	cout << "((((porte ouverte))))\n"<<endl;
    }
	sleep(temps);
  }

}
