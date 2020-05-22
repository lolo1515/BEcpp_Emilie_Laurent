#include "door.h"

//classe ActuatorPorte
ActuatorPorte::ActuatorPorte(int t):Device(),state(LOW),temps(t){
}

void ActuatorPorte::run(){
  while(1){
    if(ptrmem!=NULL)
      state=*ptrmem;
    if (state==LOW)
      cout << "((((fermé))))"<<endl;
    else
    cout << "((((ouverte))))"<<endl;
    sleep(temps);
    //cout << "((((coucou))))"<<endl;
    }
}
