#include <unistd.h>
#include "core_simulation.h"

// la fonction d'initialisation d'arduino
void Board::setup(){
  // on configure la vitesse de la liaison
  Serial.begin(9600);
  //=========projet===========
  //pinMode(2, OUTPUT);
  pinMode(1, INPUT);
  pinMode(3, INPUT);
  pinMode(5, INPUT);
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(6, OUTPUT);
    //cout << "((((tututsetup))))"<<endl;





/*=========question===========
// on fixe les pin en entree et en sorite en fonction des capteurs/actionneurs mis sur la carte
  pinMode(1,INPUT);
  pinMode(2,INPUT);
  pinMode(4,INPUT);

  pinMode(0,OUTPUT);
  pinMode(3,OUTPUT);*/



}

// la boucle de controle arduino
void Board::loop(){
 //==================projet=============
	int lum =0;
	int water = HIGH;
	int grain = 50;
    int i=0;

	//for(i=0;i<12;i++){

		lum = analogRead(1);
		water = digitalRead(3);
		grain = digitalRead(5);

		if (lum<400){
			digitalWrite(2,LOW);		
		}
		else if (lum>450){
			digitalWrite(2,HIGH);
		}
	
		if(water==HIGH){
			cout<<"il y'a de l'eau"<<endl;
			digitalWrite(4, LOW);
		}
		else{
			cout<<"il y'a pas d'eau, elles ont tout bu"<<endl;
			digitalWrite(4, HIGH);
		}

        if (grain>11){
			cout<<"il y'a du grain"<<endl;
			digitalWrite(6,LOW);		
		}
		else if (grain<10){
			cout<<"il n y'a plus de grain, tout a été mangé"<<endl;
			digitalWrite(6,HIGH);
		}
			
		cout<<"lum: "<<lum<<endl;
		cout<<"grain: "<<grain<<endl;
		sleep(1);
	//}

	//cout<<getLum()<<endl;











//==============question===============
  /*char buf[100];
  int temp = 0;
  int lum = 0;
  int bout = 0;
  static int cpt=0;
  static int bascule=0;
  int i=0;


  for(i=0;i<10;i++){
    //lecture sur la pin 1 : capteur de temperature
    temp=analogRead(1);
    lum=analogRead(2);
    sprintf(buf,"temperature: %d; luminosity: %d",temp, lum);
    Serial.println(buf);
    if(cpt%5==0){
      // toutes les 5 fois on affiche sur l ecran la temperature
      sprintf(buf,"t: %d; l=%d",temp,lum);
      bus.write(1,buf,100);
    }
    cpt++;
    sleep(1);
  }
 
  bout=digitalRead(4);
  // on eteint ou on allume la LED selon l'état du bouton
  if(bout){
    digitalWrite(3,HIGH);
  }
  else{
	digitalWrite(3,LOW);
  }


// on eteint et on allume la LED
  if(bascule){
    digitalWrite(0,HIGH);
    //digitalWrite(3,HIGH);
  }
  else{
    digitalWrite(0,LOW);
	//digitalWrite(3,LOW);
  }
  bascule=1-bascule;*/
  
}


