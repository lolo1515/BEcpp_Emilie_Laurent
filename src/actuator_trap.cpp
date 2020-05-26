#include "actuator_trap.h"

//classe ActuatorPump
ActuatorTrap::ActuatorTrap(int t):Device(),state(LOW),temps(t){
}

void ActuatorTrap::run(){
  while(1){
    if(ptrmem!=NULL)
      state=*ptrmem;
    if (state==LOW)
      cout << "((((trappe fermée))))\n"<<endl;
    else{
      cout << "((((trappe ouverte))))\n"<<endl;
      setGrainEnv();
    }
    sleep(temps);
    //cout << "((((coucou))))"<<endl;
    }
}
