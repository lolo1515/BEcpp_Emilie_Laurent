#include <unistd.h>
#include "core_simulation.h"

// la fonction d'initialisation d'arduino
void Board::setup(){
  // on configure la vitesse de la liaison
  Serial.begin(9600);
// on fixe les pin en entree et en sorite en fonction des capteurs/actionneurs mis sur la carte
  pinMode(1,INPUT);
  pinMode(2,INPUT);
  pinMode(4,INPUT);

  pinMode(0,OUTPUT);
  pinMode(3,OUTPUT);

}

// la boucle de controle arduino
void Board::loop(){
  char buf[100];
  int temp = 0;
  int lum = 0;
  int bout = 0;
  static int cpt=0;
  static int bascule=0;
  int i=0;


  for(i=0;i<10;i++){
    // lecture sur la pin 1 : capteur de temperature
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
  bascule=1-bascule;
  
}


