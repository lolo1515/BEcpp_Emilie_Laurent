#include "actuator_pump.h"

//classe ActuatorPump
ActuatorPump::ActuatorPump(int t):Device(),state(LOW),temps(t){
}

void ActuatorPump::run(){
  while(1){
    if(ptrmem!=NULL)
      state=*ptrmem;
    if (state==LOW)
      cout << "((((pompe à l'arrêt))))"<<endl;
    else{
      cout << "((((pompe en marche))))"<<endl;
      setWaterEnv();
    }
    sleep(temps);
    //cout << "((((coucou))))"<<endl;
    }
}
