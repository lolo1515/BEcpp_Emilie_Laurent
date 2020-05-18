
#include "mydevices.h"

using namespace std;

// valeur de luminosité mesurée
static volatile int luminosite_environnement=200;

void journee(){
	if (luminosite_environnement==200){
		luminosite_environnement=5000;
	}
	if (luminosite_environnement==5000){
		luminosite_environnement=200;
	}
}
//classe AnalogSensorTemperature
AnalogSensorTemperature::AnalogSensorTemperature(int d,int  t):Device(),val(t),temps(d){
  alea=1;
}

void AnalogSensorTemperature::run(){
  while(1){
    alea=1-alea;
    if(ptrmem!=NULL)
      *ptrmem=val+alea;
    sleep(temps);
  }
}

//classe AnalogSensorLuminosity
AnalogSensorLuminosity::AnalogSensorLuminosity(int d):Device(),temps(d) {
	alea=10;
}

void AnalogSensorLuminosity::run(){
  while(1){
    alea=10-alea;
    if(ptrmem!=NULL)
      *ptrmem=alea;
    sleep(temps);
  }
}

//classe DigitalActuatorLED
DigitalActuatorLED::DigitalActuatorLED(int t):Device(),state(LOW),temps(t){
}

void DigitalActuatorLED::run(){
  while(1){
    if(ptrmem!=NULL)
      state=*ptrmem;
    if (state==LOW)
      cout << "((((eteint))))\n";
    else
    cout << "((((allume))))\n";
    sleep(temps);
    }
}





//classe intelligentDigitalActuatorLED
IntelligentDigitalActuatorLED::IntelligentDigitalActuatorLED(int t):Device(),state(LOW),temps(t), init(false){
}

void IntelligentDigitalActuatorLED::run(){
  //vrai si une modif de lum a déjà été faite
  int oldState = HIGH; //high car la led est initialisé à low 
  while(1){
    if(ptrmem!=NULL)
      state=*ptrmem;
    if (state==LOW){
	  cout << "((((pas de soleil))))\n";
	  if (state!=oldState){
	  	oldState = LOW;
	  	if (init){
	  		luminosite_environnement = luminosite_environnement-50; 
	  	}
	  }
	}
    else {
      cout << "((((soleil !))))\n";
      init = true; 
	  if (state!=oldState){
        oldState = HIGH;
        luminosite_environnement = luminosite_environnement+50;
	  }
	}
    sleep(temps);
  }
	
}




// classe  ExternalDigitalSensorButton 
ExternalDigitalSensorButton::ExternalDigitalSensorButton(int t): Device(), state(LOW),temps(t){
}

void ExternalDigitalSensorButton::run(){
	while(1){
		if (ifstream("on.txt")){
			//le fichier on.txt est présent dans le repertoire
			cout<<"bouton appuyé"<<endl;
			state=HIGH;
			*ptrmem=state;
		}
		else {
			//le fichier on.txt n'est pas présent dans le repertoire
			cout<<"bouton relaché"<<endl;
			state=LOW;
			*ptrmem=state;
		}
		sleep(temps);
	}
}



//classe ActuatorPorte
ActuatorPorte::ActuatorPorte(int t):Device(),state(LOW),temps(t){
}

void ActuatorPorte::run(){
  while(1){
    if(ptrmem!=NULL)
      state=*ptrmem;
    if (state==LOW)
      cout << "((((fermé))))\n";
    else
    cout << "((((ouverte))))\n";
    sleep(temps);
    }
}



// classe I2CActuatorScreen
I2CActuatorScreen::I2CActuatorScreen ():Device(){
  }

void I2CActuatorScreen::run(){
  while(1){
    if ( (i2cbus!=NULL)&&!(i2cbus->isEmptyRegister(i2caddr))){
      Device::i2cbus->requestFrom(i2caddr, buf, I2C_BUFFER_SIZE);
      cout << "---screen :"<< buf << endl;
    }
    sleep(1);
    }
}





